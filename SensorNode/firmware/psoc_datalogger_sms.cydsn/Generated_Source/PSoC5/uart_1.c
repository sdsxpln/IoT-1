/*******************************************************************************
* File Name: uart_1.c
* Version 2.30
*
* Description:
*  This file provides all API functionality of the UART component
*
* Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions,
* disclaimers, and limitations in the end user license agreement accompanying
* the software package with which this file was provided.
*******************************************************************************/

#include "uart_1.h"
#include "CyLib.h"
#if(uart_1_INTERNAL_CLOCK_USED)
    #include "uart_1_IntClock.h"
#endif /* End uart_1_INTERNAL_CLOCK_USED */


/***************************************
* Global data allocation
***************************************/

uint8 uart_1_initVar = 0u;
#if( uart_1_TX_ENABLED && (uart_1_TXBUFFERSIZE > uart_1_FIFO_LENGTH))
    volatile uint8 uart_1_txBuffer[uart_1_TXBUFFERSIZE];
    volatile uint8 uart_1_txBufferRead = 0u;
    uint8 uart_1_txBufferWrite = 0u;
#endif /* End uart_1_TX_ENABLED */
#if( ( uart_1_RX_ENABLED || uart_1_HD_ENABLED ) && \
     (uart_1_RXBUFFERSIZE > uart_1_FIFO_LENGTH) )
    volatile uint8 uart_1_rxBuffer[uart_1_RXBUFFERSIZE];
    volatile uint8 uart_1_rxBufferRead = 0u;
    volatile uint8 uart_1_rxBufferWrite = 0u;
    volatile uint8 uart_1_rxBufferLoopDetect = 0u;
    volatile uint8 uart_1_rxBufferOverflow = 0u;
    #if (uart_1_RXHW_ADDRESS_ENABLED)
        volatile uint8 uart_1_rxAddressMode = uart_1_RXADDRESSMODE;
        volatile uint8 uart_1_rxAddressDetected = 0u;
    #endif /* End EnableHWAddress */
#endif /* End uart_1_RX_ENABLED */


/*******************************************************************************
* Function Name: uart_1_Start
********************************************************************************
*
* Summary:
*  Initialize and Enable the UART component.
*  Enable the clock input to enable operation.
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global variables:
*  The uart_1_intiVar variable is used to indicate initial
*  configuration of this component. The variable is initialized to zero (0u)
*  and set to one (1u) the first time UART_Start() is called. This allows for
*  component initialization without re-initialization in all subsequent calls
*  to the uart_1_Start() routine.
*
* Reentrant:
*  No.
*
*******************************************************************************/
void uart_1_Start(void) 
{
    /* If not Initialized then initialize all required hardware and software */
    if(uart_1_initVar == 0u)
    {
        uart_1_Init();
        uart_1_initVar = 1u;
    }
    uart_1_Enable();
}


/*******************************************************************************
* Function Name: uart_1_Init
********************************************************************************
*
* Summary:
*  Initialize component's parameters to the parameters set by user in the
*  customizer of the component placed onto schematic. Usually called in
*  uart_1_Start().
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void uart_1_Init(void) 
{
    #if(uart_1_RX_ENABLED || uart_1_HD_ENABLED)

        #if(uart_1_RX_INTERRUPT_ENABLED && (uart_1_RXBUFFERSIZE > uart_1_FIFO_LENGTH))
            /* Set the RX Interrupt. */
            (void)CyIntSetVector(uart_1_RX_VECT_NUM, &uart_1_RXISR);
            CyIntSetPriority(uart_1_RX_VECT_NUM, uart_1_RX_PRIOR_NUM);
        #endif /* End uart_1_RX_INTERRUPT_ENABLED */

        #if (uart_1_RXHW_ADDRESS_ENABLED)
            uart_1_SetRxAddressMode(uart_1_RXAddressMode);
            uart_1_SetRxAddress1(uart_1_RXHWADDRESS1);
            uart_1_SetRxAddress2(uart_1_RXHWADDRESS2);
        #endif /* End uart_1_RXHW_ADDRESS_ENABLED */

        /* Init Count7 period */
        uart_1_RXBITCTR_PERIOD_REG = uart_1_RXBITCTR_INIT;
        /* Configure the Initial RX interrupt mask */
        uart_1_RXSTATUS_MASK_REG  = uart_1_INIT_RX_INTERRUPTS_MASK;
    #endif /* End uart_1_RX_ENABLED || uart_1_HD_ENABLED*/

    #if(uart_1_TX_ENABLED)
        #if(uart_1_TX_INTERRUPT_ENABLED && (uart_1_TXBUFFERSIZE > uart_1_FIFO_LENGTH))
            /* Set the TX Interrupt. */
            (void)CyIntSetVector(uart_1_TX_VECT_NUM, &uart_1_TXISR);
            CyIntSetPriority(uart_1_TX_VECT_NUM, uart_1_TX_PRIOR_NUM);
        #endif /* End uart_1_TX_INTERRUPT_ENABLED */

        /* Write Counter Value for TX Bit Clk Generator*/
        #if(uart_1_TXCLKGEN_DP)
            uart_1_TXBITCLKGEN_CTR_REG = uart_1_BIT_CENTER;
            uart_1_TXBITCLKTX_COMPLETE_REG = (uart_1_NUMBER_OF_DATA_BITS +
                        uart_1_NUMBER_OF_START_BIT) * uart_1_OVER_SAMPLE_COUNT;
        #else
            uart_1_TXBITCTR_PERIOD_REG = ((uart_1_NUMBER_OF_DATA_BITS +
                        uart_1_NUMBER_OF_START_BIT) * uart_1_OVER_SAMPLE_8) - 1u;
        #endif /* End uart_1_TXCLKGEN_DP */

        /* Configure the Initial TX interrupt mask */
        #if(uart_1_TX_INTERRUPT_ENABLED && (uart_1_TXBUFFERSIZE > uart_1_FIFO_LENGTH))
            uart_1_TXSTATUS_MASK_REG = uart_1_TX_STS_FIFO_EMPTY;
        #else
            uart_1_TXSTATUS_MASK_REG = uart_1_INIT_TX_INTERRUPTS_MASK;
        #endif /*End uart_1_TX_INTERRUPT_ENABLED*/

    #endif /* End uart_1_TX_ENABLED */

    #if(uart_1_PARITY_TYPE_SW)  /* Write Parity to Control Register */
        uart_1_WriteControlRegister( \
            (uart_1_ReadControlRegister() & (uint8)~uart_1_CTRL_PARITY_TYPE_MASK) | \
            (uint8)(uart_1_PARITY_TYPE << uart_1_CTRL_PARITY_TYPE0_SHIFT) );
    #endif /* End uart_1_PARITY_TYPE_SW */
}


/*******************************************************************************
* Function Name: uart_1_Enable
********************************************************************************
*
* Summary:
*  Enables the UART block operation
*
* Parameters:
*  None.
*
* Return:
*  None.
*
* Global Variables:
*  uart_1_rxAddressDetected - set to initial state (0).
*
*******************************************************************************/
void uart_1_Enable(void) 
{
    uint8 enableInterrupts;
    enableInterrupts = CyEnterCriticalSection();

    #if(uart_1_RX_ENABLED || uart_1_HD_ENABLED)
        /*RX Counter (Count7) Enable */
        uart_1_RXBITCTR_CONTROL_REG |= uart_1_CNTR_ENABLE;
        /* Enable the RX Interrupt. */
        uart_1_RXSTATUS_ACTL_REG  |= uart_1_INT_ENABLE;
        #if(uart_1_RX_INTERRUPT_ENABLED && (uart_1_RXBUFFERSIZE > uart_1_FIFO_LENGTH))
            CyIntEnable(uart_1_RX_VECT_NUM);
            #if (uart_1_RXHW_ADDRESS_ENABLED)
                uart_1_rxAddressDetected = 0u;
            #endif /* End uart_1_RXHW_ADDRESS_ENABLED */
        #endif /* End uart_1_RX_INTERRUPT_ENABLED */
    #endif /* End uart_1_RX_ENABLED || uart_1_HD_ENABLED*/

    #if(uart_1_TX_ENABLED)
        /*TX Counter (DP/Count7) Enable */
        #if(!uart_1_TXCLKGEN_DP)
            uart_1_TXBITCTR_CONTROL_REG |= uart_1_CNTR_ENABLE;
        #endif /* End uart_1_TXCLKGEN_DP */
        /* Enable the TX Interrupt. */
        uart_1_TXSTATUS_ACTL_REG |= uart_1_INT_ENABLE;
        #if(uart_1_TX_INTERRUPT_ENABLED && (uart_1_TXBUFFERSIZE > uart_1_FIFO_LENGTH))
            CyIntEnable(uart_1_TX_VECT_NUM);
        #endif /* End uart_1_TX_INTERRUPT_ENABLED*/
     #endif /* End uart_1_TX_ENABLED */

    #if(uart_1_INTERNAL_CLOCK_USED)
        /* Enable the clock. */
        uart_1_IntClock_Start();
    #endif /* End uart_1_INTERNAL_CLOCK_USED */

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: uart_1_Stop
********************************************************************************
*
* Summary:
*  Disable the UART component
*
* Parameters:
*  None.
*
* Return:
*  None.
*
*******************************************************************************/
void uart_1_Stop(void) 
{
    uint8 enableInterrupts;
    enableInterrupts = CyEnterCriticalSection();

    /* Write Bit Counter Disable */
    #if(uart_1_RX_ENABLED || uart_1_HD_ENABLED)
        uart_1_RXBITCTR_CONTROL_REG &= (uint8)~uart_1_CNTR_ENABLE;
    #endif /* End uart_1_RX_ENABLED */

    #if(uart_1_TX_ENABLED)
        #if(!uart_1_TXCLKGEN_DP)
            uart_1_TXBITCTR_CONTROL_REG &= (uint8)~uart_1_CNTR_ENABLE;
        #endif /* End uart_1_TXCLKGEN_DP */
    #endif /* uart_1_TX_ENABLED */

    #if(uart_1_INTERNAL_CLOCK_USED)
        /* Disable the clock. */
        uart_1_IntClock_Stop();
    #endif /* End uart_1_INTERNAL_CLOCK_USED */

    /* Disable internal interrupt component */
    #if(uart_1_RX_ENABLED || uart_1_HD_ENABLED)
        uart_1_RXSTATUS_ACTL_REG  &= (uint8)~uart_1_INT_ENABLE;
        #if(uart_1_RX_INTERRUPT_ENABLED && (uart_1_RXBUFFERSIZE > uart_1_FIFO_LENGTH))
            uart_1_DisableRxInt();
        #endif /* End uart_1_RX_INTERRUPT_ENABLED */
    #endif /* End uart_1_RX_ENABLED */

    #if(uart_1_TX_ENABLED)
        uart_1_TXSTATUS_ACTL_REG &= (uint8)~uart_1_INT_ENABLE;
        #if(uart_1_TX_INTERRUPT_ENABLED && (uart_1_TXBUFFERSIZE > uart_1_FIFO_LENGTH))
            uart_1_DisableTxInt();
        #endif /* End uart_1_TX_INTERRUPT_ENABLED */
    #endif /* End uart_1_TX_ENABLED */

    CyExitCriticalSection(enableInterrupts);
}


/*******************************************************************************
* Function Name: uart_1_ReadControlRegister
********************************************************************************
*
* Summary:
*  Read the current state of the control register
*
* Parameters:
*  None.
*
* Return:
*  Current state of the control register.
*
*******************************************************************************/
uint8 uart_1_ReadControlRegister(void) 
{
    #if( uart_1_CONTROL_REG_REMOVED )
        return(0u);
    #else
        return(uart_1_CONTROL_REG);
    #endif /* End uart_1_CONTROL_REG_REMOVED */
}


/*******************************************************************************
* Function Name: uart_1_WriteControlRegister
********************************************************************************
*
* Summary:
*  Writes an 8-bit value into the control register
*
* Parameters:
*  control:  control register value
*
* Return:
*  None.
*
*******************************************************************************/
void  uart_1_WriteControlRegister(uint8 control) 
{
    #if( uart_1_CONTROL_REG_REMOVED )
        if(control != 0u) { }      /* release compiler warning */
    #else
       uart_1_CONTROL_REG = control;
    #endif /* End uart_1_CONTROL_REG_REMOVED */
}


#if(uart_1_RX_ENABLED || uart_1_HD_ENABLED)

    #if(uart_1_RX_INTERRUPT_ENABLED)

        /*******************************************************************************
        * Function Name: uart_1_EnableRxInt
        ********************************************************************************
        *
        * Summary:
        *  Enable RX interrupt generation
        *
        * Parameters:
        *  None.
        *
        * Return:
        *  None.
        *
        * Theory:
        *  Enable the interrupt output -or- the interrupt component itself
        *
        *******************************************************************************/
        void uart_1_EnableRxInt(void) 
        {
            CyIntEnable(uart_1_RX_VECT_NUM);
        }


        /*******************************************************************************
        * Function Name: uart_1_DisableRxInt
        ********************************************************************************
        *
        * Summary:
        *  Disable RX interrupt generation
        *
        * Parameters:
        *  None.
        *
        * Return:
        *  None.
        *
        * Theory:
        *  Disable the interrupt output -or- the interrupt component itself
        *
        *******************************************************************************/
        void uart_1_DisableRxInt(void) 
        {
            CyIntDisable(uart_1_RX_VECT_NUM);
        }

    #endif /* uart_1_RX_INTERRUPT_ENABLED */


    /*******************************************************************************
    * Function Name: uart_1_SetRxInterruptMode
    ********************************************************************************
    *
    * Summary:
    *  Configure which status bits trigger an interrupt event
    *
    * Parameters:
    *  IntSrc:  An or'd combination of the desired status bit masks (defined in
    *           the header file)
    *
    * Return:
    *  None.
    *
    * Theory:
    *  Enables the output of specific status bits to the interrupt controller
    *
    *******************************************************************************/
    void uart_1_SetRxInterruptMode(uint8 intSrc) 
    {
        uart_1_RXSTATUS_MASK_REG  = intSrc;
    }


    /*******************************************************************************
    * Function Name: uart_1_ReadRxData
    ********************************************************************************
    *
    * Summary:
    *  Returns data in RX Data register without checking status register to
    *  determine if data is valid
    *
    * Parameters:
    *  None.
    *
    * Return:
    *  Received data from RX register
    *
    * Global Variables:
    *  uart_1_rxBuffer - RAM buffer pointer for save received data.
    *  uart_1_rxBufferWrite - cyclic index for write to rxBuffer,
    *     checked to identify new data.
    *  uart_1_rxBufferRead - cyclic index for read from rxBuffer,
    *     incremented after each byte has been read from buffer.
    *  uart_1_rxBufferLoopDetect - creared if loop condition was detected
    *     in RX ISR.
    *
    * Reentrant:
    *  No.
    *
    *******************************************************************************/
    uint8 uart_1_ReadRxData(void) 
    {
        uint8 rxData;

        #if(uart_1_RXBUFFERSIZE > uart_1_FIFO_LENGTH)
            uint8 loc_rxBufferRead;
            uint8 loc_rxBufferWrite;
            /* Protect variables that could change on interrupt. */
            /* Disable Rx interrupt. */
            #if(uart_1_RX_INTERRUPT_ENABLED)
                uart_1_DisableRxInt();
            #endif /* uart_1_RX_INTERRUPT_ENABLED */
            loc_rxBufferRead = uart_1_rxBufferRead;
            loc_rxBufferWrite = uart_1_rxBufferWrite;

            if( (uart_1_rxBufferLoopDetect != 0u) || (loc_rxBufferRead != loc_rxBufferWrite) )
            {
                rxData = uart_1_rxBuffer[loc_rxBufferRead];
                loc_rxBufferRead++;

                if(loc_rxBufferRead >= uart_1_RXBUFFERSIZE)
                {
                    loc_rxBufferRead = 0u;
                }
                /* Update the real pointer */
                uart_1_rxBufferRead = loc_rxBufferRead;

                if(uart_1_rxBufferLoopDetect != 0u )
                {
                    uart_1_rxBufferLoopDetect = 0u;
                    #if( (uart_1_RX_INTERRUPT_ENABLED) && (uart_1_FLOW_CONTROL != 0u) && \
                         (uart_1_RXBUFFERSIZE > uart_1_FIFO_LENGTH) )
                        /* When Hardware Flow Control selected - return RX mask */
                        #if( uart_1_HD_ENABLED )
                            if((uart_1_CONTROL_REG & uart_1_CTRL_HD_SEND) == 0u)
                            {   /* In Half duplex mode return RX mask only in RX
                                *  configuration set, otherwise
                                *  mask will be returned in LoadRxConfig() API.
                                */
                                uart_1_RXSTATUS_MASK_REG  |= uart_1_RX_STS_FIFO_NOTEMPTY;
                            }
                        #else
                            uart_1_RXSTATUS_MASK_REG  |= uart_1_RX_STS_FIFO_NOTEMPTY;
                        #endif /* end uart_1_HD_ENABLED */
                    #endif /* uart_1_RX_INTERRUPT_ENABLED and Hardware flow control*/
                }
            }
            else
            {   /* Needs to check status for RX_STS_FIFO_NOTEMPTY bit*/
                rxData = uart_1_RXDATA_REG;
            }

            /* Enable Rx interrupt. */
            #if(uart_1_RX_INTERRUPT_ENABLED)
                uart_1_EnableRxInt();
            #endif /* End uart_1_RX_INTERRUPT_ENABLED */

        #else /* uart_1_RXBUFFERSIZE > uart_1_FIFO_LENGTH */

            /* Needs to check status for RX_STS_FIFO_NOTEMPTY bit*/
            rxData = uart_1_RXDATA_REG;

        #endif /* uart_1_RXBUFFERSIZE > uart_1_FIFO_LENGTH */

        return(rxData);
    }


    /*******************************************************************************
    * Function Name: uart_1_ReadRxStatus
    ********************************************************************************
    *
    * Summary:
    *  Read the current state of the status register
    *  And detect software buffer overflow.
    *
    * Parameters:
    *  None.
    *
    * Return:
    *  Current state of the status register.
    *
    * Global Variables:
    *  uart_1_rxBufferOverflow - used to indicate overload condition.
    *   It set to one in RX interrupt when there isn?t free space in
    *   uart_1_rxBufferRead to write new data. This condition returned
    *   and cleared to zero by this API as an
    *   uart_1_RX_STS_SOFT_BUFF_OVER bit along with RX Status register
    *   bits.
    *
    *******************************************************************************/
    uint8 uart_1_ReadRxStatus(void) 
    {
        uint8 status;

        status = uart_1_RXSTATUS_REG & uart_1_RX_HW_MASK;

        #if(uart_1_RXBUFFERSIZE > uart_1_FIFO_LENGTH)
            if( uart_1_rxBufferOverflow != 0u )
            {
                status |= uart_1_RX_STS_SOFT_BUFF_OVER;
                uart_1_rxBufferOverflow = 0u;
            }
        #endif /* uart_1_RXBUFFERSIZE */

        return(status);
    }


    /*******************************************************************************
    * Function Name: uart_1_GetChar
    ********************************************************************************
    *
    * Summary:
    *  Reads UART RX buffer immediately, if data is not available or an error
    *  condition exists, zero is returned; otherwise, character is read and
    *  returned.
    *
    * Parameters:
    *  None.
    *
    * Return:
    *  Character read from UART RX buffer. ASCII characters from 1 to 255 are valid.
    *  A returned zero signifies an error condition or no data available.
    *
    * Global Variables:
    *  uart_1_rxBuffer - RAM buffer pointer for save received data.
    *  uart_1_rxBufferWrite - cyclic index for write to rxBuffer,
    *     checked to identify new data.
    *  uart_1_rxBufferRead - cyclic index for read from rxBuffer,
    *     incremented after each byte has been read from buffer.
    *  uart_1_rxBufferLoopDetect - creared if loop condition was detected
    *     in RX ISR.
    *
    * Reentrant:
    *  No.
    *
    *******************************************************************************/
    uint8 uart_1_GetChar(void) 
    {
        uint8 rxData = 0u;
        uint8 rxStatus;

        #if(uart_1_RXBUFFERSIZE > uart_1_FIFO_LENGTH)
            uint8 loc_rxBufferRead;
            uint8 loc_rxBufferWrite;
            /* Protect variables that could change on interrupt. */
            /* Disable Rx interrupt. */
            #if(uart_1_RX_INTERRUPT_ENABLED)
                uart_1_DisableRxInt();
            #endif /* uart_1_RX_INTERRUPT_ENABLED */
            loc_rxBufferRead = uart_1_rxBufferRead;
            loc_rxBufferWrite = uart_1_rxBufferWrite;

            if( (uart_1_rxBufferLoopDetect != 0u) || (loc_rxBufferRead != loc_rxBufferWrite) )
            {
                rxData = uart_1_rxBuffer[loc_rxBufferRead];
                loc_rxBufferRead++;
                if(loc_rxBufferRead >= uart_1_RXBUFFERSIZE)
                {
                    loc_rxBufferRead = 0u;
                }
                /* Update the real pointer */
                uart_1_rxBufferRead = loc_rxBufferRead;

                if(uart_1_rxBufferLoopDetect > 0u )
                {
                    uart_1_rxBufferLoopDetect = 0u;
                    #if( (uart_1_RX_INTERRUPT_ENABLED) && (uart_1_FLOW_CONTROL != 0u) )
                        /* When Hardware Flow Control selected - return RX mask */
                        #if( uart_1_HD_ENABLED )
                            if((uart_1_CONTROL_REG & uart_1_CTRL_HD_SEND) == 0u)
                            {   /* In Half duplex mode return RX mask only if
                                *  RX configuration set, otherwise
                                *  mask will be returned in LoadRxConfig() API.
                                */
                                uart_1_RXSTATUS_MASK_REG  |= uart_1_RX_STS_FIFO_NOTEMPTY;
                            }
                        #else
                            uart_1_RXSTATUS_MASK_REG  |= uart_1_RX_STS_FIFO_NOTEMPTY;
                        #endif /* end uart_1_HD_ENABLED */
                    #endif /* uart_1_RX_INTERRUPT_ENABLED and Hardware flow control*/
                }

            }
            else
            {   rxStatus = uart_1_RXSTATUS_REG;
                if((rxStatus & uart_1_RX_STS_FIFO_NOTEMPTY) != 0u)
                {   /* Read received data from FIFO*/
                    rxData = uart_1_RXDATA_REG;
                    /*Check status on error*/
                    if((rxStatus & (uart_1_RX_STS_BREAK | uart_1_RX_STS_PAR_ERROR |
                                   uart_1_RX_STS_STOP_ERROR | uart_1_RX_STS_OVERRUN)) != 0u)
                    {
                        rxData = 0u;
                    }
                }
            }

            /* Enable Rx interrupt. */
            #if(uart_1_RX_INTERRUPT_ENABLED)
                uart_1_EnableRxInt();
            #endif /* uart_1_RX_INTERRUPT_ENABLED */

        #else /* uart_1_RXBUFFERSIZE > uart_1_FIFO_LENGTH */

            rxStatus =uart_1_RXSTATUS_REG;
            if((rxStatus & uart_1_RX_STS_FIFO_NOTEMPTY) != 0u)
            {   /* Read received data from FIFO*/
                rxData = uart_1_RXDATA_REG;
                /*Check status on error*/
                if((rxStatus & (uart_1_RX_STS_BREAK | uart_1_RX_STS_PAR_ERROR |
                               uart_1_RX_STS_STOP_ERROR | uart_1_RX_STS_OVERRUN)) != 0u)
                {
                    rxData = 0u;
                }
            }
        #endif /* uart_1_RXBUFFERSIZE > uart_1_FIFO_LENGTH */

        return(rxData);
    }


    /*******************************************************************************
    * Function Name: uart_1_GetByte
    ********************************************************************************
    *
    * Summary:
    *  Grab the next available byte of data from the recieve FIFO
    *
    * Parameters:
    *  None.
    *
    * Return:
    *  MSB contains Status Register and LSB contains UART RX data
    *
    * Reentrant:
    *  No.
    *
    *******************************************************************************/
    uint16 uart_1_GetByte(void) 
    {
        return ( ((uint16)uart_1_ReadRxStatus() << 8u) | uart_1_ReadRxData() );
    }


    /*******************************************************************************
    * Function Name: uart_1_GetRxBufferSize
    ********************************************************************************
    *
    * Summary:
    *  Determine the amount of bytes left in the RX buffer and return the count in
    *  bytes
    *
    * Parameters:
    *  None.
    *
    * Return:
    *  uint8: Integer count of the number of bytes left
    *  in the RX buffer
    *
    * Global Variables:
    *  uart_1_rxBufferWrite - used to calculate left bytes.
    *  uart_1_rxBufferRead - used to calculate left bytes.
    *  uart_1_rxBufferLoopDetect - checked to decide left bytes amount.
    *
    * Reentrant:
    *  No.
    *
    * Theory:
    *  Allows the user to find out how full the RX Buffer is.
    *
    *******************************************************************************/
    uint8 uart_1_GetRxBufferSize(void)
                                                            
    {
        uint8 size;

        #if(uart_1_RXBUFFERSIZE > uart_1_FIFO_LENGTH)

            /* Disable Rx interrupt. */
            /* Protect variables that could change on interrupt. */
            #if(uart_1_RX_INTERRUPT_ENABLED)
                uart_1_DisableRxInt();
            #endif /* uart_1_RX_INTERRUPT_ENABLED */

            if(uart_1_rxBufferRead == uart_1_rxBufferWrite)
            {
                if(uart_1_rxBufferLoopDetect > 0u)
                {
                    size = uart_1_RXBUFFERSIZE;
                }
                else
                {
                    size = 0u;
                }
            }
            else if(uart_1_rxBufferRead < uart_1_rxBufferWrite)
            {
                size = (uart_1_rxBufferWrite - uart_1_rxBufferRead);
            }
            else
            {
                size = (uart_1_RXBUFFERSIZE - uart_1_rxBufferRead) + uart_1_rxBufferWrite;
            }

            /* Enable Rx interrupt. */
            #if(uart_1_RX_INTERRUPT_ENABLED)
                uart_1_EnableRxInt();
            #endif /* End uart_1_RX_INTERRUPT_ENABLED */

        #else /* uart_1_RXBUFFERSIZE > uart_1_FIFO_LENGTH */

            /* We can only know if there is data in the fifo. */
            size = ((uart_1_RXSTATUS_REG & uart_1_RX_STS_FIFO_NOTEMPTY) != 0u) ? 1u : 0u;

        #endif /* End uart_1_RXBUFFERSIZE > uart_1_FIFO_LENGTH */

        return(size);
    }


    /*******************************************************************************
    * Function Name: uart_1_ClearRxBuffer
    ********************************************************************************
    *
    * Summary:
    *  Clears the RX RAM buffer by setting the read and write pointers both to zero.
    *  Clears hardware RX FIFO.
    *
    * Parameters:
    *  None.
    *
    * Return:
    *  None.
    *
    * Global Variables:
    *  uart_1_rxBufferWrite - cleared to zero.
    *  uart_1_rxBufferRead - cleared to zero.
    *  uart_1_rxBufferLoopDetect - cleared to zero.
    *  uart_1_rxBufferOverflow - cleared to zero.
    *
    * Reentrant:
    *  No.
    *
    * Theory:
    *  Setting the pointers to zero makes the system believe there is no data to
    *  read and writing will resume at address 0 overwriting any data that may
    *  have remained in the RAM.
    *
    * Side Effects:
    *  Any received data not read from the RAM or FIFO buffer will be lost.
    *******************************************************************************/
    void uart_1_ClearRxBuffer(void) 
    {
        uint8 enableInterrupts;

        /* clear the HW FIFO */
        /* Enter critical section */
        enableInterrupts = CyEnterCriticalSection();
        uart_1_RXDATA_AUX_CTL_REG |=  uart_1_RX_FIFO_CLR;
        uart_1_RXDATA_AUX_CTL_REG &= (uint8)~uart_1_RX_FIFO_CLR;
        /* Exit critical section */
        CyExitCriticalSection(enableInterrupts);

        #if(uart_1_RXBUFFERSIZE > uart_1_FIFO_LENGTH)
            /* Disable Rx interrupt. */
            /* Protect variables that could change on interrupt. */
            #if(uart_1_RX_INTERRUPT_ENABLED)
                uart_1_DisableRxInt();
            #endif /* End uart_1_RX_INTERRUPT_ENABLED */

            uart_1_rxBufferRead = 0u;
            uart_1_rxBufferWrite = 0u;
            uart_1_rxBufferLoopDetect = 0u;
            uart_1_rxBufferOverflow = 0u;

            /* Enable Rx interrupt. */
            #if(uart_1_RX_INTERRUPT_ENABLED)
                uart_1_EnableRxInt();
            #endif /* End uart_1_RX_INTERRUPT_ENABLED */
        #endif /* End uart_1_RXBUFFERSIZE > uart_1_FIFO_LENGTH */

    }


    /*******************************************************************************
    * Function Name: uart_1_SetRxAddressMode
    ********************************************************************************
    *
    * Summary:
    *  Set the receive addressing mode
    *
    * Parameters:
    *  addressMode: Enumerated value indicating the mode of RX addressing
    *  uart_1__B_UART__AM_SW_BYTE_BYTE -  Software Byte-by-Byte address
    *                                               detection
    *  uart_1__B_UART__AM_SW_DETECT_TO_BUFFER - Software Detect to Buffer
    *                                               address detection
    *  uart_1__B_UART__AM_HW_BYTE_BY_BYTE - Hardware Byte-by-Byte address
    *                                               detection
    *  uart_1__B_UART__AM_HW_DETECT_TO_BUFFER - Hardware Detect to Buffer
    *                                               address detection
    *  uart_1__B_UART__AM_NONE - No address detection
    *
    * Return:
    *  None.
    *
    * Global Variables:
    *  uart_1_rxAddressMode - the parameter stored in this variable for
    *   the farther usage in RX ISR.
    *  uart_1_rxAddressDetected - set to initial state (0).
    *
    *******************************************************************************/
    void uart_1_SetRxAddressMode(uint8 addressMode)
                                                        
    {
        #if(uart_1_RXHW_ADDRESS_ENABLED)
            #if(uart_1_CONTROL_REG_REMOVED)
                if(addressMode != 0u) { }     /* release compiler warning */
            #else /* uart_1_CONTROL_REG_REMOVED */
                uint8 tmpCtrl;
                tmpCtrl = uart_1_CONTROL_REG & (uint8)~uart_1_CTRL_RXADDR_MODE_MASK;
                tmpCtrl |= (uint8)(addressMode << uart_1_CTRL_RXADDR_MODE0_SHIFT);
                uart_1_CONTROL_REG = tmpCtrl;
                #if(uart_1_RX_INTERRUPT_ENABLED && \
                   (uart_1_RXBUFFERSIZE > uart_1_FIFO_LENGTH) )
                    uart_1_rxAddressMode = addressMode;
                    uart_1_rxAddressDetected = 0u;
                #endif /* End uart_1_RXBUFFERSIZE > uart_1_FIFO_LENGTH*/
            #endif /* End uart_1_CONTROL_REG_REMOVED */
        #else /* uart_1_RXHW_ADDRESS_ENABLED */
            if(addressMode != 0u) { }     /* release compiler warning */
        #endif /* End uart_1_RXHW_ADDRESS_ENABLED */
    }


    /*******************************************************************************
    * Function Name: uart_1_SetRxAddress1
    ********************************************************************************
    *
    * Summary:
    *  Set the first hardware address compare value
    *
    * Parameters:
    *  address
    *
    * Return:
    *  None.
    *
    *******************************************************************************/
    void uart_1_SetRxAddress1(uint8 address) 

    {
        uart_1_RXADDRESS1_REG = address;
    }


    /*******************************************************************************
    * Function Name: uart_1_SetRxAddress2
    ********************************************************************************
    *
    * Summary:
    *  Set the second hardware address compare value
    *
    * Parameters:
    *  address
    *
    * Return:
    *  None.
    *
    *******************************************************************************/
    void uart_1_SetRxAddress2(uint8 address) 
    {
        uart_1_RXADDRESS2_REG = address;
    }

#endif  /* uart_1_RX_ENABLED || uart_1_HD_ENABLED*/


#if( (uart_1_TX_ENABLED) || (uart_1_HD_ENABLED) )

    #if(uart_1_TX_INTERRUPT_ENABLED)

        /*******************************************************************************
        * Function Name: uart_1_EnableTxInt
        ********************************************************************************
        *
        * Summary:
        *  Enable TX interrupt generation
        *
        * Parameters:
        *  None.
        *
        * Return:
        *  None.
        *
        * Theory:
        *  Enable the interrupt output -or- the interrupt component itself
        *
        *******************************************************************************/
        void uart_1_EnableTxInt(void) 
        {
            CyIntEnable(uart_1_TX_VECT_NUM);
        }


        /*******************************************************************************
        * Function Name: uart_1_DisableTxInt
        ********************************************************************************
        *
        * Summary:
        *  Disable TX interrupt generation
        *
        * Parameters:
        *  None.
        *
        * Return:
        *  None.
        *
        * Theory:
        *  Disable the interrupt output -or- the interrupt component itself
        *
        *******************************************************************************/
        void uart_1_DisableTxInt(void) 
        {
            CyIntDisable(uart_1_TX_VECT_NUM);
        }

    #endif /* uart_1_TX_INTERRUPT_ENABLED */


    /*******************************************************************************
    * Function Name: uart_1_SetTxInterruptMode
    ********************************************************************************
    *
    * Summary:
    *  Configure which status bits trigger an interrupt event
    *
    * Parameters:
    *  intSrc: An or'd combination of the desired status bit masks (defined in
    *          the header file)
    *
    * Return:
    *  None.
    *
    * Theory:
    *  Enables the output of specific status bits to the interrupt controller
    *
    *******************************************************************************/
    void uart_1_SetTxInterruptMode(uint8 intSrc) 
    {
        uart_1_TXSTATUS_MASK_REG = intSrc;
    }


    /*******************************************************************************
    * Function Name: uart_1_WriteTxData
    ********************************************************************************
    *
    * Summary:
    *  Write a byte of data to the Transmit FIFO or TX buffer to be sent when the
    *  bus is available. WriteTxData sends a byte without checking for buffer room
    *  or status. It is up to the user to separately check status.
    *
    * Parameters:
    *  TXDataByte: byte of data to place in the transmit FIFO
    *
    * Return:
    * void
    *
    * Global Variables:
    *  uart_1_txBuffer - RAM buffer pointer for save data for transmission
    *  uart_1_txBufferWrite - cyclic index for write to txBuffer,
    *    incremented after each byte saved to buffer.
    *  uart_1_txBufferRead - cyclic index for read from txBuffer,
    *    checked to identify the condition to write to FIFO directly or to TX buffer
    *  uart_1_initVar - checked to identify that the component has been
    *    initialized.
    *
    * Reentrant:
    *  No.
    *
    *******************************************************************************/
    void uart_1_WriteTxData(uint8 txDataByte) 
    {
        /* If not Initialized then skip this function*/
        if(uart_1_initVar != 0u)
        {
            #if(uart_1_TXBUFFERSIZE > uart_1_FIFO_LENGTH)

                /* Disable Tx interrupt. */
                /* Protect variables that could change on interrupt. */
                #if(uart_1_TX_INTERRUPT_ENABLED)
                    uart_1_DisableTxInt();
                #endif /* End uart_1_TX_INTERRUPT_ENABLED */

                if( (uart_1_txBufferRead == uart_1_txBufferWrite) &&
                    ((uart_1_TXSTATUS_REG & uart_1_TX_STS_FIFO_FULL) == 0u) )
                {
                    /* Add directly to the FIFO. */
                    uart_1_TXDATA_REG = txDataByte;
                }
                else
                {
                    if(uart_1_txBufferWrite >= uart_1_TXBUFFERSIZE)
                    {
                        uart_1_txBufferWrite = 0u;
                    }

                    uart_1_txBuffer[uart_1_txBufferWrite] = txDataByte;

                    /* Add to the software buffer. */
                    uart_1_txBufferWrite++;

                }

                /* Enable Tx interrupt. */
                #if(uart_1_TX_INTERRUPT_ENABLED)
                    uart_1_EnableTxInt();
                #endif /* End uart_1_TX_INTERRUPT_ENABLED */

            #else /* uart_1_TXBUFFERSIZE > uart_1_FIFO_LENGTH */

                /* Add directly to the FIFO. */
                uart_1_TXDATA_REG = txDataByte;

            #endif /* End uart_1_TXBUFFERSIZE > uart_1_FIFO_LENGTH */
        }
    }


    /*******************************************************************************
    * Function Name: uart_1_ReadTxStatus
    ********************************************************************************
    *
    * Summary:
    *  Read the status register for the component
    *
    * Parameters:
    *  None.
    *
    * Return:
    *  Contents of the status register
    *
    * Theory:
    *  This function reads the status register which is clear on read. It is up to
    *  the user to handle all bits in this return value accordingly, even if the bit
    *  was not enabled as an interrupt source the event happened and must be handled
    *  accordingly.
    *
    *******************************************************************************/
    uint8 uart_1_ReadTxStatus(void) 
    {
        return(uart_1_TXSTATUS_REG);
    }


    /*******************************************************************************
    * Function Name: uart_1_PutChar
    ********************************************************************************
    *
    * Summary:
    *  Wait to send byte until TX register or buffer has room.
    *
    * Parameters:
    *  txDataByte: The 8-bit data value to send across the UART.
    *
    * Return:
    *  None.
    *
    * Global Variables:
    *  uart_1_txBuffer - RAM buffer pointer for save data for transmission
    *  uart_1_txBufferWrite - cyclic index for write to txBuffer,
    *     checked to identify free space in txBuffer and incremented after each byte
    *     saved to buffer.
    *  uart_1_txBufferRead - cyclic index for read from txBuffer,
    *     checked to identify free space in txBuffer.
    *  uart_1_initVar - checked to identify that the component has been
    *     initialized.
    *
    * Reentrant:
    *  No.
    *
    * Theory:
    *  Allows the user to transmit any byte of data in a single transfer
    *
    *******************************************************************************/
    void uart_1_PutChar(uint8 txDataByte) 
    {
            #if(uart_1_TXBUFFERSIZE > uart_1_FIFO_LENGTH)
                /* The temporary output pointer is used since it takes two instructions
                *  to increment with a wrap, and we can't risk doing that with the real
                *  pointer and getting an interrupt in between instructions.
                */
                uint8 loc_txBufferWrite;
                uint8 loc_txBufferRead;

                do{
                    /* Block if software buffer is full, so we don't overwrite. */
                    #if ((uart_1_TXBUFFERSIZE > uart_1_MAX_BYTE_VALUE) && (CY_PSOC3))
                        /* Disable TX interrupt to protect variables that could change on interrupt */
                        CyIntDisable(uart_1_TX_VECT_NUM);
                    #endif /* End TXBUFFERSIZE > 255 */
                    loc_txBufferWrite = uart_1_txBufferWrite;
                    loc_txBufferRead = uart_1_txBufferRead;
                    #if ((uart_1_TXBUFFERSIZE > uart_1_MAX_BYTE_VALUE) && (CY_PSOC3))
                        /* Enable interrupt to continue transmission */
                        CyIntEnable(uart_1_TX_VECT_NUM);
                    #endif /* End TXBUFFERSIZE > 255 */
                }while( (loc_txBufferWrite < loc_txBufferRead) ? (loc_txBufferWrite == (loc_txBufferRead - 1u)) :
                                        ((loc_txBufferWrite - loc_txBufferRead) ==
                                        (uint8)(uart_1_TXBUFFERSIZE - 1u)) );

                if( (loc_txBufferRead == loc_txBufferWrite) &&
                    ((uart_1_TXSTATUS_REG & uart_1_TX_STS_FIFO_FULL) == 0u) )
                {
                    /* Add directly to the FIFO. */
                    uart_1_TXDATA_REG = txDataByte;
                }
                else
                {
                    if(loc_txBufferWrite >= uart_1_TXBUFFERSIZE)
                    {
                        loc_txBufferWrite = 0u;
                    }
                    /* Add to the software buffer. */
                    uart_1_txBuffer[loc_txBufferWrite] = txDataByte;
                    loc_txBufferWrite++;

                    /* Finally, update the real output pointer */
                    #if ((uart_1_TXBUFFERSIZE > uart_1_MAX_BYTE_VALUE) && (CY_PSOC3))
                        CyIntDisable(uart_1_TX_VECT_NUM);
                    #endif /* End TXBUFFERSIZE > 255 */
                    uart_1_txBufferWrite = loc_txBufferWrite;
                    #if ((uart_1_TXBUFFERSIZE > uart_1_MAX_BYTE_VALUE) && (CY_PSOC3))
                        CyIntEnable(uart_1_TX_VECT_NUM);
                    #endif /* End TXBUFFERSIZE > 255 */
                }

            #else /* uart_1_TXBUFFERSIZE > uart_1_FIFO_LENGTH */

                while((uart_1_TXSTATUS_REG & uart_1_TX_STS_FIFO_FULL) != 0u)
                {
                    ; /* Wait for room in the FIFO. */
                }

                /* Add directly to the FIFO. */
                uart_1_TXDATA_REG = txDataByte;

            #endif /* End uart_1_TXBUFFERSIZE > uart_1_FIFO_LENGTH */
    }


    /*******************************************************************************
    * Function Name: uart_1_PutString
    ********************************************************************************
    *
    * Summary:
    *  Write a Sequence of bytes on the Transmit line. Data comes from RAM or ROM.
    *
    * Parameters:
    *  string: char pointer to character string of Data to Send.
    *
    * Return:
    *  None.
    *
    * Global Variables:
    *  uart_1_initVar - checked to identify that the component has been
    *     initialized.
    *
    * Reentrant:
    *  No.
    *
    * Theory:
    *  This function will block if there is not enough memory to place the whole
    *  string, it will block until the entire string has been written to the
    *  transmit buffer.
    *
    *******************************************************************************/
    void uart_1_PutString(const char8 string[]) 
    {
        uint16 buf_index = 0u;
        /* If not Initialized then skip this function*/
        if(uart_1_initVar != 0u)
        {
            /* This is a blocking function, it will not exit until all data is sent*/
            while(string[buf_index] != (char8)0)
            {
                uart_1_PutChar((uint8)string[buf_index]);
                buf_index++;
            }
        }
    }


    /*******************************************************************************
    * Function Name: uart_1_PutArray
    ********************************************************************************
    *
    * Summary:
    *  Write a Sequence of bytes on the Transmit line. Data comes from RAM or ROM.
    *
    * Parameters:
    *  string: Address of the memory array residing in RAM or ROM.
    *  byteCount: Number of Bytes to be transmitted.
    *
    * Return:
    *  None.
    *
    * Global Variables:
    *  uart_1_initVar - checked to identify that the component has been
    *     initialized.
    *
    * Reentrant:
    *  No.
    *
    *******************************************************************************/
    void uart_1_PutArray(const uint8 string[], uint8 byteCount)
                                                                    
    {
        uint8 buf_index = 0u;
        /* If not Initialized then skip this function*/
        if(uart_1_initVar != 0u)
        {
            do
            {
                uart_1_PutChar(string[buf_index]);
                buf_index++;
            }while(buf_index < byteCount);
        }
    }


    /*******************************************************************************
    * Function Name: uart_1_PutCRLF
    ********************************************************************************
    *
    * Summary:
    *  Write a character and then carriage return and line feed.
    *
    * Parameters:
    *  txDataByte: uint8 Character to send.
    *
    * Return:
    *  None.
    *
    * Global Variables:
    *  uart_1_initVar - checked to identify that the component has been
    *     initialized.
    *
    * Reentrant:
    *  No.
    *
    *******************************************************************************/
    void uart_1_PutCRLF(uint8 txDataByte) 
    {
        /* If not Initialized then skip this function*/
        if(uart_1_initVar != 0u)
        {
            uart_1_PutChar(txDataByte);
            uart_1_PutChar(0x0Du);
            uart_1_PutChar(0x0Au);
        }
    }


    /*******************************************************************************
    * Function Name: uart_1_GetTxBufferSize
    ********************************************************************************
    *
    * Summary:
    *  Determine the amount of space left in the TX buffer and return the count in
    *  bytes
    *
    * Parameters:
    *  None.
    *
    * Return:
    *  Integer count of the number of bytes left in the TX buffer
    *
    * Global Variables:
    *  uart_1_txBufferWrite - used to calculate left space.
    *  uart_1_txBufferRead - used to calculate left space.
    *
    * Reentrant:
    *  No.
    *
    * Theory:
    *  Allows the user to find out how full the TX Buffer is.
    *
    *******************************************************************************/
    uint8 uart_1_GetTxBufferSize(void)
                                                            
    {
        uint8 size;

        #if(uart_1_TXBUFFERSIZE > uart_1_FIFO_LENGTH)

            /* Disable Tx interrupt. */
            /* Protect variables that could change on interrupt. */
            #if(uart_1_TX_INTERRUPT_ENABLED)
                uart_1_DisableTxInt();
            #endif /* End uart_1_TX_INTERRUPT_ENABLED */

            if(uart_1_txBufferRead == uart_1_txBufferWrite)
            {
                size = 0u;
            }
            else if(uart_1_txBufferRead < uart_1_txBufferWrite)
            {
                size = (uart_1_txBufferWrite - uart_1_txBufferRead);
            }
            else
            {
                size = (uart_1_TXBUFFERSIZE - uart_1_txBufferRead) + uart_1_txBufferWrite;
            }

            /* Enable Tx interrupt. */
            #if(uart_1_TX_INTERRUPT_ENABLED)
                uart_1_EnableTxInt();
            #endif /* End uart_1_TX_INTERRUPT_ENABLED */

        #else /* uart_1_TXBUFFERSIZE > uart_1_FIFO_LENGTH */

            size = uart_1_TXSTATUS_REG;

            /* Is the fifo is full. */
            if((size & uart_1_TX_STS_FIFO_FULL) != 0u)
            {
                size = uart_1_FIFO_LENGTH;
            }
            else if((size & uart_1_TX_STS_FIFO_EMPTY) != 0u)
            {
                size = 0u;
            }
            else
            {
                /* We only know there is data in the fifo. */
                size = 1u;
            }

        #endif /* End uart_1_TXBUFFERSIZE > uart_1_FIFO_LENGTH */

        return(size);
    }


    /*******************************************************************************
    * Function Name: uart_1_ClearTxBuffer
    ********************************************************************************
    *
    * Summary:
    *  Clears the TX RAM buffer by setting the read and write pointers both to zero.
    *  Clears the hardware TX FIFO.  Any data present in the FIFO will not be sent.
    *
    * Parameters:
    *  None.
    *
    * Return:
    *  None.
    *
    * Global Variables:
    *  uart_1_txBufferWrite - cleared to zero.
    *  uart_1_txBufferRead - cleared to zero.
    *
    * Reentrant:
    *  No.
    *
    * Theory:
    *  Setting the pointers to zero makes the system believe there is no data to
    *  read and writing will resume at address 0 overwriting any data that may have
    *  remained in the RAM.
    *
    * Side Effects:
    *  Any received data not read from the RAM buffer will be lost when overwritten.
    *
    *******************************************************************************/
    void uart_1_ClearTxBuffer(void) 
    {
        uint8 enableInterrupts;

        /* Enter critical section */
        enableInterrupts = CyEnterCriticalSection();
        /* clear the HW FIFO */
        uart_1_TXDATA_AUX_CTL_REG |=  uart_1_TX_FIFO_CLR;
        uart_1_TXDATA_AUX_CTL_REG &= (uint8)~uart_1_TX_FIFO_CLR;
        /* Exit critical section */
        CyExitCriticalSection(enableInterrupts);

        #if(uart_1_TXBUFFERSIZE > uart_1_FIFO_LENGTH)

            /* Disable Tx interrupt. */
            /* Protect variables that could change on interrupt. */
            #if(uart_1_TX_INTERRUPT_ENABLED)
                uart_1_DisableTxInt();
            #endif /* End uart_1_TX_INTERRUPT_ENABLED */

            uart_1_txBufferRead = 0u;
            uart_1_txBufferWrite = 0u;

            /* Enable Tx interrupt. */
            #if(uart_1_TX_INTERRUPT_ENABLED)
                uart_1_EnableTxInt();
            #endif /* End uart_1_TX_INTERRUPT_ENABLED */

        #endif /* End uart_1_TXBUFFERSIZE > uart_1_FIFO_LENGTH */
    }


    /*******************************************************************************
    * Function Name: uart_1_SendBreak
    ********************************************************************************
    *
    * Summary:
    *  Write a Break command to the UART
    *
    * Parameters:
    *  uint8 retMode:  Wait mode,
    *   0 - Initialize registers for Break, sends the Break signal and return
    *       imediately.
    *   1 - Wait until Break sending is complete, reinitialize registers to normal
    *       transmission mode then return.
    *   2 - Reinitialize registers to normal transmission mode then return.
    *   3 - both steps: 0 and 1
    *       init registers for Break, send Break signal
    *       wait until Break sending is complete, reinit registers to normal
    *       transmission mode then return.
    *
    * Return:
    *  None.
    *
    * Global Variables:
    *  uart_1_initVar - checked to identify that the component has been
    *     initialized.
    *  tx_period - static variable, used for keeping TX period configuration.
    *
    * Reentrant:
    *  No.
    *
    * Theory:
    *  SendBreak function initializes registers to send 13-bit break signal. It is
    *  important to return the registers configuration to normal for continue 8-bit
    *  operation.
    *  Trere are 3 variants for this API usage:
    *  1) SendBreak(3) - function will send the Break signal and take care on the
    *     configuration returning. Funcition will block CPU untill transmition
    *     complete.
    *  2) User may want to use bloking time if UART configured to the low speed
    *     operation
    *     Emample for this case:
    *     SendBreak(0);     - init Break signal transmition
    *         Add your code here to use CPU time
    *     SendBreak(1);     - complete Break operation
    *  3) Same to 2) but user may want to init and use the interrupt for complete
    *     break operation.
    *     Example for this case:
    *     Init TX interrupt whith "TX - On TX Complete" parameter
    *     SendBreak(0);     - init Break signal transmition
    *         Add your code here to use CPU time
    *     When interrupt appear with UART_TX_STS_COMPLETE status:
    *     SendBreak(2);     - complete Break operation
    *
    * Side Effects:
    *   Uses static variable to keep registers configuration.
    *
    *******************************************************************************/
    void uart_1_SendBreak(uint8 retMode) 
    {

        /* If not Initialized then skip this function*/
        if(uart_1_initVar != 0u)
        {
            /*Set the Counter to 13-bits and transmit a 00 byte*/
            /*When that is done then reset the counter value back*/
            uint8 tmpStat;

            #if(uart_1_HD_ENABLED) /* Half Duplex mode*/

                if( (retMode == uart_1_SEND_BREAK) ||
                    (retMode == uart_1_SEND_WAIT_REINIT ) )
                {
                    /* CTRL_HD_SEND_BREAK - sends break bits in HD mode*/
                    uart_1_WriteControlRegister(uart_1_ReadControlRegister() |
                                                          uart_1_CTRL_HD_SEND_BREAK);
                    /* Send zeros*/
                    uart_1_TXDATA_REG = 0u;

                    do /*wait until transmit starts*/
                    {
                        tmpStat = uart_1_TXSTATUS_REG;
                    }while((tmpStat & uart_1_TX_STS_FIFO_EMPTY) != 0u);
                }

                if( (retMode == uart_1_WAIT_FOR_COMPLETE_REINIT) ||
                    (retMode == uart_1_SEND_WAIT_REINIT) )
                {
                    do /*wait until transmit complete*/
                    {
                        tmpStat = uart_1_TXSTATUS_REG;
                    }while(((uint8)~tmpStat & uart_1_TX_STS_COMPLETE) != 0u);
                }

                if( (retMode == uart_1_WAIT_FOR_COMPLETE_REINIT) ||
                    (retMode == uart_1_REINIT) ||
                    (retMode == uart_1_SEND_WAIT_REINIT) )
                {
                    uart_1_WriteControlRegister(uart_1_ReadControlRegister() &
                                                  (uint8)~uart_1_CTRL_HD_SEND_BREAK);
                }

            #else /* uart_1_HD_ENABLED Full Duplex mode */

                static uint8 tx_period;

                if( (retMode == uart_1_SEND_BREAK) ||
                    (retMode == uart_1_SEND_WAIT_REINIT) )
                {
                    /* CTRL_HD_SEND_BREAK - skip to send parity bit at Break signal in Full Duplex mode*/
                    #if( (uart_1_PARITY_TYPE != uart_1__B_UART__NONE_REVB) || \
                                        (uart_1_PARITY_TYPE_SW != 0u) )
                        uart_1_WriteControlRegister(uart_1_ReadControlRegister() |
                                                              uart_1_CTRL_HD_SEND_BREAK);
                    #endif /* End uart_1_PARITY_TYPE != uart_1__B_UART__NONE_REVB  */

                    #if(uart_1_TXCLKGEN_DP)
                        tx_period = uart_1_TXBITCLKTX_COMPLETE_REG;
                        uart_1_TXBITCLKTX_COMPLETE_REG = uart_1_TXBITCTR_BREAKBITS;
                    #else
                        tx_period = uart_1_TXBITCTR_PERIOD_REG;
                        uart_1_TXBITCTR_PERIOD_REG = uart_1_TXBITCTR_BREAKBITS8X;
                    #endif /* End uart_1_TXCLKGEN_DP */

                    /* Send zeros*/
                    uart_1_TXDATA_REG = 0u;

                    do /* wait until transmit starts */
                    {
                        tmpStat = uart_1_TXSTATUS_REG;
                    }while((tmpStat & uart_1_TX_STS_FIFO_EMPTY) != 0u);
                }

                if( (retMode == uart_1_WAIT_FOR_COMPLETE_REINIT) ||
                    (retMode == uart_1_SEND_WAIT_REINIT) )
                {
                    do /*wait until transmit complete*/
                    {
                        tmpStat = uart_1_TXSTATUS_REG;
                    }while(((uint8)~tmpStat & uart_1_TX_STS_COMPLETE) != 0u);
                }

                if( (retMode == uart_1_WAIT_FOR_COMPLETE_REINIT) ||
                    (retMode == uart_1_REINIT) ||
                    (retMode == uart_1_SEND_WAIT_REINIT) )
                {

                    #if(uart_1_TXCLKGEN_DP)
                        uart_1_TXBITCLKTX_COMPLETE_REG = tx_period;
                    #else
                        uart_1_TXBITCTR_PERIOD_REG = tx_period;
                    #endif /* End uart_1_TXCLKGEN_DP */

                    #if( (uart_1_PARITY_TYPE != uart_1__B_UART__NONE_REVB) || \
                         (uart_1_PARITY_TYPE_SW != 0u) )
                        uart_1_WriteControlRegister(uart_1_ReadControlRegister() &
                                                      (uint8)~uart_1_CTRL_HD_SEND_BREAK);
                    #endif /* End uart_1_PARITY_TYPE != NONE */
                }
            #endif    /* End uart_1_HD_ENABLED */
        }
    }


    /*******************************************************************************
    * Function Name: uart_1_SetTxAddressMode
    ********************************************************************************
    *
    * Summary:
    *  Set the transmit addressing mode
    *
    * Parameters:
    *  addressMode: 0 -> Space
    *               1 -> Mark
    *
    * Return:
    *  None.
    *
    *******************************************************************************/
    void uart_1_SetTxAddressMode(uint8 addressMode) 
    {
        /* Mark/Space sending enable*/
        if(addressMode != 0u)
        {
            #if( uart_1_CONTROL_REG_REMOVED == 0u )
                uart_1_WriteControlRegister(uart_1_ReadControlRegister() |
                                                      uart_1_CTRL_MARK);
            #endif /* End uart_1_CONTROL_REG_REMOVED == 0u */
        }
        else
        {
            #if( uart_1_CONTROL_REG_REMOVED == 0u )
                uart_1_WriteControlRegister(uart_1_ReadControlRegister() &
                                                    (uint8)~uart_1_CTRL_MARK);
            #endif /* End uart_1_CONTROL_REG_REMOVED == 0u */
        }
    }

#endif  /* Enduart_1_TX_ENABLED */

#if(uart_1_HD_ENABLED)


    /*******************************************************************************
    * Function Name: uart_1_LoadTxConfig
    ********************************************************************************
    *
    * Summary:
    *  Unloads the Rx configuration if required and loads the
    *  Tx configuration. It is the users responsibility to ensure that any
    *  transaction is complete and it is safe to unload the Tx
    *  configuration.
    *
    * Parameters:
    *  None.
    *
    * Return:
    *  None.
    *
    * Theory:
    *  Valid only for half duplex UART.
    *
    * Side Effects:
    *  Disable RX interrupt mask, when software buffer has been used.
    *
    *******************************************************************************/
    void uart_1_LoadTxConfig(void) 
    {
        #if((uart_1_RX_INTERRUPT_ENABLED) && (uart_1_RXBUFFERSIZE > uart_1_FIFO_LENGTH))
            /* Disable RX interrupts before set TX configuration */
            uart_1_SetRxInterruptMode(0u);
        #endif /* uart_1_RX_INTERRUPT_ENABLED */

        uart_1_WriteControlRegister(uart_1_ReadControlRegister() | uart_1_CTRL_HD_SEND);
        uart_1_RXBITCTR_PERIOD_REG = uart_1_HD_TXBITCTR_INIT;
        #if(CY_UDB_V0) /* Manually clear status register when mode has been changed */
            /* Clear status register */
            CY_GET_REG8(uart_1_RXSTATUS_PTR);
        #endif /* CY_UDB_V0 */
    }


    /*******************************************************************************
    * Function Name: uart_1_LoadRxConfig
    ********************************************************************************
    *
    * Summary:
    *  Unloads the Tx configuration if required and loads the
    *  Rx configuration. It is the users responsibility to ensure that any
    *  transaction is complete and it is safe to unload the Rx
    *  configuration.
    *
    * Parameters:
    *  None.
    *
    * Return:
    *  None.
    *
    * Theory:
    *  Valid only for half duplex UART
    *
    * Side Effects:
    *  Set RX interrupt mask based on customizer settings, when software buffer
    *  has been used.
    *
    *******************************************************************************/
    void uart_1_LoadRxConfig(void) 
    {
        uart_1_WriteControlRegister(uart_1_ReadControlRegister() &
                                                (uint8)~uart_1_CTRL_HD_SEND);
        uart_1_RXBITCTR_PERIOD_REG = uart_1_HD_RXBITCTR_INIT;
        #if(CY_UDB_V0) /* Manually clear status register when mode has been changed */
            /* Clear status register */
            CY_GET_REG8(uart_1_RXSTATUS_PTR);
        #endif /* CY_UDB_V0 */

        #if((uart_1_RX_INTERRUPT_ENABLED) && (uart_1_RXBUFFERSIZE > uart_1_FIFO_LENGTH))
            /* Enable RX interrupt after set RX configuration */
            uart_1_SetRxInterruptMode(uart_1_INIT_RX_INTERRUPTS_MASK);
        #endif /* uart_1_RX_INTERRUPT_ENABLED */
    }

#endif  /* uart_1_HD_ENABLED */


/* [] END OF FILE */
