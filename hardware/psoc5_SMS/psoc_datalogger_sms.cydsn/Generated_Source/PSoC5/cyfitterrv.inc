    IF :LNOT::DEF:INCLUDED_CYFITTERRV_INC
INCLUDED_CYFITTERRV_INC EQU 1
    GET cydevicerv.inc
    GET cydevicerv_trm.inc

; ultrasonic_uart_IntClock
ultrasonic_uart_IntClock__CFG0 EQU CYREG_CLKDIST_DCFG1_CFG0
ultrasonic_uart_IntClock__CFG1 EQU CYREG_CLKDIST_DCFG1_CFG1
ultrasonic_uart_IntClock__CFG2 EQU CYREG_CLKDIST_DCFG1_CFG2
ultrasonic_uart_IntClock__CFG2_SRC_SEL_MASK EQU 0x07
ultrasonic_uart_IntClock__INDEX EQU 0x01
ultrasonic_uart_IntClock__PM_ACT_CFG EQU CYREG_PM_ACT_CFG2
ultrasonic_uart_IntClock__PM_ACT_MSK EQU 0x02
ultrasonic_uart_IntClock__PM_STBY_CFG EQU CYREG_PM_STBY_CFG2
ultrasonic_uart_IntClock__PM_STBY_MSK EQU 0x02

; ultrasonic_voltage_pin_2
ultrasonic_voltage_pin_2__0__MASK EQU 0x08
ultrasonic_voltage_pin_2__0__PC EQU CYREG_PRT0_PC3
ultrasonic_voltage_pin_2__0__PORT EQU 0
ultrasonic_voltage_pin_2__0__SHIFT EQU 3
ultrasonic_voltage_pin_2__AG EQU CYREG_PRT0_AG
ultrasonic_voltage_pin_2__AMUX EQU CYREG_PRT0_AMUX
ultrasonic_voltage_pin_2__BIE EQU CYREG_PRT0_BIE
ultrasonic_voltage_pin_2__BIT_MASK EQU CYREG_PRT0_BIT_MASK
ultrasonic_voltage_pin_2__BYP EQU CYREG_PRT0_BYP
ultrasonic_voltage_pin_2__CTL EQU CYREG_PRT0_CTL
ultrasonic_voltage_pin_2__DM0 EQU CYREG_PRT0_DM0
ultrasonic_voltage_pin_2__DM1 EQU CYREG_PRT0_DM1
ultrasonic_voltage_pin_2__DM2 EQU CYREG_PRT0_DM2
ultrasonic_voltage_pin_2__DR EQU CYREG_PRT0_DR
ultrasonic_voltage_pin_2__INP_DIS EQU CYREG_PRT0_INP_DIS
ultrasonic_voltage_pin_2__LCD_COM_SEG EQU CYREG_PRT0_LCD_COM_SEG
ultrasonic_voltage_pin_2__LCD_EN EQU CYREG_PRT0_LCD_EN
ultrasonic_voltage_pin_2__MASK EQU 0x08
ultrasonic_voltage_pin_2__PORT EQU 0
ultrasonic_voltage_pin_2__PRT EQU CYREG_PRT0_PRT
ultrasonic_voltage_pin_2__PRTDSI__CAPS_SEL EQU CYREG_PRT0_CAPS_SEL
ultrasonic_voltage_pin_2__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT0_DBL_SYNC_IN
ultrasonic_voltage_pin_2__PRTDSI__OE_SEL0 EQU CYREG_PRT0_OE_SEL0
ultrasonic_voltage_pin_2__PRTDSI__OE_SEL1 EQU CYREG_PRT0_OE_SEL1
ultrasonic_voltage_pin_2__PRTDSI__OUT_SEL0 EQU CYREG_PRT0_OUT_SEL0
ultrasonic_voltage_pin_2__PRTDSI__OUT_SEL1 EQU CYREG_PRT0_OUT_SEL1
ultrasonic_voltage_pin_2__PRTDSI__SYNC_OUT EQU CYREG_PRT0_SYNC_OUT
ultrasonic_voltage_pin_2__PS EQU CYREG_PRT0_PS
ultrasonic_voltage_pin_2__SHIFT EQU 3
ultrasonic_voltage_pin_2__SLW EQU CYREG_PRT0_SLW

; isr_byte_ultrasonic_rx
isr_byte_ultrasonic_rx__INTC_CLR_EN_REG EQU CYREG_NVIC_CLRENA0
isr_byte_ultrasonic_rx__INTC_CLR_PD_REG EQU CYREG_NVIC_CLRPEND0
isr_byte_ultrasonic_rx__INTC_MASK EQU 0x04
isr_byte_ultrasonic_rx__INTC_NUMBER EQU 2
isr_byte_ultrasonic_rx__INTC_PRIOR_NUM EQU 7
isr_byte_ultrasonic_rx__INTC_PRIOR_REG EQU CYREG_NVIC_PRI_2
isr_byte_ultrasonic_rx__INTC_SET_EN_REG EQU CYREG_NVIC_SETENA0
isr_byte_ultrasonic_rx__INTC_SET_PD_REG EQU CYREG_NVIC_SETPEND0

; ultrasonic_reading_pin
ultrasonic_reading_pin__0__MASK EQU 0x04
ultrasonic_reading_pin__0__PC EQU CYREG_PRT0_PC2
ultrasonic_reading_pin__0__PORT EQU 0
ultrasonic_reading_pin__0__SHIFT EQU 2
ultrasonic_reading_pin__AG EQU CYREG_PRT0_AG
ultrasonic_reading_pin__AMUX EQU CYREG_PRT0_AMUX
ultrasonic_reading_pin__BIE EQU CYREG_PRT0_BIE
ultrasonic_reading_pin__BIT_MASK EQU CYREG_PRT0_BIT_MASK
ultrasonic_reading_pin__BYP EQU CYREG_PRT0_BYP
ultrasonic_reading_pin__CTL EQU CYREG_PRT0_CTL
ultrasonic_reading_pin__DM0 EQU CYREG_PRT0_DM0
ultrasonic_reading_pin__DM1 EQU CYREG_PRT0_DM1
ultrasonic_reading_pin__DM2 EQU CYREG_PRT0_DM2
ultrasonic_reading_pin__DR EQU CYREG_PRT0_DR
ultrasonic_reading_pin__INP_DIS EQU CYREG_PRT0_INP_DIS
ultrasonic_reading_pin__LCD_COM_SEG EQU CYREG_PRT0_LCD_COM_SEG
ultrasonic_reading_pin__LCD_EN EQU CYREG_PRT0_LCD_EN
ultrasonic_reading_pin__MASK EQU 0x04
ultrasonic_reading_pin__PORT EQU 0
ultrasonic_reading_pin__PRT EQU CYREG_PRT0_PRT
ultrasonic_reading_pin__PRTDSI__CAPS_SEL EQU CYREG_PRT0_CAPS_SEL
ultrasonic_reading_pin__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT0_DBL_SYNC_IN
ultrasonic_reading_pin__PRTDSI__OE_SEL0 EQU CYREG_PRT0_OE_SEL0
ultrasonic_reading_pin__PRTDSI__OE_SEL1 EQU CYREG_PRT0_OE_SEL1
ultrasonic_reading_pin__PRTDSI__OUT_SEL0 EQU CYREG_PRT0_OUT_SEL0
ultrasonic_reading_pin__PRTDSI__OUT_SEL1 EQU CYREG_PRT0_OUT_SEL1
ultrasonic_reading_pin__PRTDSI__SYNC_OUT EQU CYREG_PRT0_SYNC_OUT
ultrasonic_reading_pin__PS EQU CYREG_PRT0_PS
ultrasonic_reading_pin__SHIFT EQU 2
ultrasonic_reading_pin__SLW EQU CYREG_PRT0_SLW

; ultrasonic_voltage_pin
ultrasonic_voltage_pin__0__MASK EQU 0x20
ultrasonic_voltage_pin__0__PC EQU CYREG_PRT6_PC5
ultrasonic_voltage_pin__0__PORT EQU 6
ultrasonic_voltage_pin__0__SHIFT EQU 5
ultrasonic_voltage_pin__AG EQU CYREG_PRT6_AG
ultrasonic_voltage_pin__AMUX EQU CYREG_PRT6_AMUX
ultrasonic_voltage_pin__BIE EQU CYREG_PRT6_BIE
ultrasonic_voltage_pin__BIT_MASK EQU CYREG_PRT6_BIT_MASK
ultrasonic_voltage_pin__BYP EQU CYREG_PRT6_BYP
ultrasonic_voltage_pin__CTL EQU CYREG_PRT6_CTL
ultrasonic_voltage_pin__DM0 EQU CYREG_PRT6_DM0
ultrasonic_voltage_pin__DM1 EQU CYREG_PRT6_DM1
ultrasonic_voltage_pin__DM2 EQU CYREG_PRT6_DM2
ultrasonic_voltage_pin__DR EQU CYREG_PRT6_DR
ultrasonic_voltage_pin__INP_DIS EQU CYREG_PRT6_INP_DIS
ultrasonic_voltage_pin__LCD_COM_SEG EQU CYREG_PRT6_LCD_COM_SEG
ultrasonic_voltage_pin__LCD_EN EQU CYREG_PRT6_LCD_EN
ultrasonic_voltage_pin__MASK EQU 0x20
ultrasonic_voltage_pin__PORT EQU 6
ultrasonic_voltage_pin__PRT EQU CYREG_PRT6_PRT
ultrasonic_voltage_pin__PRTDSI__CAPS_SEL EQU CYREG_PRT6_CAPS_SEL
ultrasonic_voltage_pin__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT6_DBL_SYNC_IN
ultrasonic_voltage_pin__PRTDSI__OE_SEL0 EQU CYREG_PRT6_OE_SEL0
ultrasonic_voltage_pin__PRTDSI__OE_SEL1 EQU CYREG_PRT6_OE_SEL1
ultrasonic_voltage_pin__PRTDSI__OUT_SEL0 EQU CYREG_PRT6_OUT_SEL0
ultrasonic_voltage_pin__PRTDSI__OUT_SEL1 EQU CYREG_PRT6_OUT_SEL1
ultrasonic_voltage_pin__PRTDSI__SYNC_OUT EQU CYREG_PRT6_SYNC_OUT
ultrasonic_voltage_pin__PS EQU CYREG_PRT6_PS
ultrasonic_voltage_pin__SHIFT EQU 5
ultrasonic_voltage_pin__SLW EQU CYREG_PRT6_SLW

; ultrasonic_uart_BUART
ultrasonic_uart_BUART_sRX_RxBitCounter_ST__16BIT_STATUS_AUX_CTL_REG EQU CYREG_B1_UDB09_10_ACTL
ultrasonic_uart_BUART_sRX_RxBitCounter_ST__16BIT_STATUS_REG EQU CYREG_B1_UDB09_10_ST
ultrasonic_uart_BUART_sRX_RxBitCounter_ST__MASK_REG EQU CYREG_B1_UDB09_MSK
ultrasonic_uart_BUART_sRX_RxBitCounter_ST__MASK_ST_AUX_CTL_REG EQU CYREG_B1_UDB09_MSK_ACTL
ultrasonic_uart_BUART_sRX_RxBitCounter_ST__PER_ST_AUX_CTL_REG EQU CYREG_B1_UDB09_MSK_ACTL
ultrasonic_uart_BUART_sRX_RxBitCounter_ST__STATUS_AUX_CTL_REG EQU CYREG_B1_UDB09_ACTL
ultrasonic_uart_BUART_sRX_RxBitCounter_ST__STATUS_CNT_REG EQU CYREG_B1_UDB09_ST_CTL
ultrasonic_uart_BUART_sRX_RxBitCounter_ST__STATUS_CONTROL_REG EQU CYREG_B1_UDB09_ST_CTL
ultrasonic_uart_BUART_sRX_RxBitCounter_ST__STATUS_REG EQU CYREG_B1_UDB09_ST
ultrasonic_uart_BUART_sRX_RxBitCounter__16BIT_CONTROL_AUX_CTL_REG EQU CYREG_B1_UDB09_10_ACTL
ultrasonic_uart_BUART_sRX_RxBitCounter__16BIT_CONTROL_CONTROL_REG EQU CYREG_B1_UDB09_10_CTL
ultrasonic_uart_BUART_sRX_RxBitCounter__16BIT_CONTROL_COUNT_REG EQU CYREG_B1_UDB09_10_CTL
ultrasonic_uart_BUART_sRX_RxBitCounter__16BIT_COUNT_CONTROL_REG EQU CYREG_B1_UDB09_10_CTL
ultrasonic_uart_BUART_sRX_RxBitCounter__16BIT_COUNT_COUNT_REG EQU CYREG_B1_UDB09_10_CTL
ultrasonic_uart_BUART_sRX_RxBitCounter__16BIT_MASK_MASK_REG EQU CYREG_B1_UDB09_10_MSK
ultrasonic_uart_BUART_sRX_RxBitCounter__16BIT_MASK_PERIOD_REG EQU CYREG_B1_UDB09_10_MSK
ultrasonic_uart_BUART_sRX_RxBitCounter__16BIT_PERIOD_MASK_REG EQU CYREG_B1_UDB09_10_MSK
ultrasonic_uart_BUART_sRX_RxBitCounter__16BIT_PERIOD_PERIOD_REG EQU CYREG_B1_UDB09_10_MSK
ultrasonic_uart_BUART_sRX_RxBitCounter__CONTROL_AUX_CTL_REG EQU CYREG_B1_UDB09_ACTL
ultrasonic_uart_BUART_sRX_RxBitCounter__CONTROL_REG EQU CYREG_B1_UDB09_CTL
ultrasonic_uart_BUART_sRX_RxBitCounter__CONTROL_ST_REG EQU CYREG_B1_UDB09_ST_CTL
ultrasonic_uart_BUART_sRX_RxBitCounter__COUNT_REG EQU CYREG_B1_UDB09_CTL
ultrasonic_uart_BUART_sRX_RxBitCounter__COUNT_ST_REG EQU CYREG_B1_UDB09_ST_CTL
ultrasonic_uart_BUART_sRX_RxBitCounter__MASK_CTL_AUX_CTL_REG EQU CYREG_B1_UDB09_MSK_ACTL
ultrasonic_uart_BUART_sRX_RxBitCounter__PERIOD_REG EQU CYREG_B1_UDB09_MSK
ultrasonic_uart_BUART_sRX_RxBitCounter__PER_CTL_AUX_CTL_REG EQU CYREG_B1_UDB09_MSK_ACTL
ultrasonic_uart_BUART_sRX_RxShifter_u0__16BIT_A0_REG EQU CYREG_B0_UDB09_10_A0
ultrasonic_uart_BUART_sRX_RxShifter_u0__16BIT_A1_REG EQU CYREG_B0_UDB09_10_A1
ultrasonic_uart_BUART_sRX_RxShifter_u0__16BIT_D0_REG EQU CYREG_B0_UDB09_10_D0
ultrasonic_uart_BUART_sRX_RxShifter_u0__16BIT_D1_REG EQU CYREG_B0_UDB09_10_D1
ultrasonic_uart_BUART_sRX_RxShifter_u0__16BIT_DP_AUX_CTL_REG EQU CYREG_B0_UDB09_10_ACTL
ultrasonic_uart_BUART_sRX_RxShifter_u0__16BIT_F0_REG EQU CYREG_B0_UDB09_10_F0
ultrasonic_uart_BUART_sRX_RxShifter_u0__16BIT_F1_REG EQU CYREG_B0_UDB09_10_F1
ultrasonic_uart_BUART_sRX_RxShifter_u0__A0_A1_REG EQU CYREG_B0_UDB09_A0_A1
ultrasonic_uart_BUART_sRX_RxShifter_u0__A0_REG EQU CYREG_B0_UDB09_A0
ultrasonic_uart_BUART_sRX_RxShifter_u0__A1_REG EQU CYREG_B0_UDB09_A1
ultrasonic_uart_BUART_sRX_RxShifter_u0__D0_D1_REG EQU CYREG_B0_UDB09_D0_D1
ultrasonic_uart_BUART_sRX_RxShifter_u0__D0_REG EQU CYREG_B0_UDB09_D0
ultrasonic_uart_BUART_sRX_RxShifter_u0__D1_REG EQU CYREG_B0_UDB09_D1
ultrasonic_uart_BUART_sRX_RxShifter_u0__DP_AUX_CTL_REG EQU CYREG_B0_UDB09_ACTL
ultrasonic_uart_BUART_sRX_RxShifter_u0__F0_F1_REG EQU CYREG_B0_UDB09_F0_F1
ultrasonic_uart_BUART_sRX_RxShifter_u0__F0_REG EQU CYREG_B0_UDB09_F0
ultrasonic_uart_BUART_sRX_RxShifter_u0__F1_REG EQU CYREG_B0_UDB09_F1
ultrasonic_uart_BUART_sRX_RxSts__16BIT_STATUS_AUX_CTL_REG EQU CYREG_B0_UDB08_09_ACTL
ultrasonic_uart_BUART_sRX_RxSts__16BIT_STATUS_REG EQU CYREG_B0_UDB08_09_ST
ultrasonic_uart_BUART_sRX_RxSts__3__MASK EQU 0x08
ultrasonic_uart_BUART_sRX_RxSts__3__POS EQU 3
ultrasonic_uart_BUART_sRX_RxSts__4__MASK EQU 0x10
ultrasonic_uart_BUART_sRX_RxSts__4__POS EQU 4
ultrasonic_uart_BUART_sRX_RxSts__5__MASK EQU 0x20
ultrasonic_uart_BUART_sRX_RxSts__5__POS EQU 5
ultrasonic_uart_BUART_sRX_RxSts__MASK EQU 0x38
ultrasonic_uart_BUART_sRX_RxSts__MASK_REG EQU CYREG_B0_UDB08_MSK
ultrasonic_uart_BUART_sRX_RxSts__STATUS_AUX_CTL_REG EQU CYREG_B0_UDB08_ACTL
ultrasonic_uart_BUART_sRX_RxSts__STATUS_REG EQU CYREG_B0_UDB08_ST
ultrasonic_uart_BUART_sTX_TxShifter_u0__16BIT_A0_REG EQU CYREG_B0_UDB11_12_A0
ultrasonic_uart_BUART_sTX_TxShifter_u0__16BIT_A1_REG EQU CYREG_B0_UDB11_12_A1
ultrasonic_uart_BUART_sTX_TxShifter_u0__16BIT_D0_REG EQU CYREG_B0_UDB11_12_D0
ultrasonic_uart_BUART_sTX_TxShifter_u0__16BIT_D1_REG EQU CYREG_B0_UDB11_12_D1
ultrasonic_uart_BUART_sTX_TxShifter_u0__16BIT_DP_AUX_CTL_REG EQU CYREG_B0_UDB11_12_ACTL
ultrasonic_uart_BUART_sTX_TxShifter_u0__16BIT_F0_REG EQU CYREG_B0_UDB11_12_F0
ultrasonic_uart_BUART_sTX_TxShifter_u0__16BIT_F1_REG EQU CYREG_B0_UDB11_12_F1
ultrasonic_uart_BUART_sTX_TxShifter_u0__A0_A1_REG EQU CYREG_B0_UDB11_A0_A1
ultrasonic_uart_BUART_sTX_TxShifter_u0__A0_REG EQU CYREG_B0_UDB11_A0
ultrasonic_uart_BUART_sTX_TxShifter_u0__A1_REG EQU CYREG_B0_UDB11_A1
ultrasonic_uart_BUART_sTX_TxShifter_u0__D0_D1_REG EQU CYREG_B0_UDB11_D0_D1
ultrasonic_uart_BUART_sTX_TxShifter_u0__D0_REG EQU CYREG_B0_UDB11_D0
ultrasonic_uart_BUART_sTX_TxShifter_u0__D1_REG EQU CYREG_B0_UDB11_D1
ultrasonic_uart_BUART_sTX_TxShifter_u0__DP_AUX_CTL_REG EQU CYREG_B0_UDB11_ACTL
ultrasonic_uart_BUART_sTX_TxShifter_u0__F0_F1_REG EQU CYREG_B0_UDB11_F0_F1
ultrasonic_uart_BUART_sTX_TxShifter_u0__F0_REG EQU CYREG_B0_UDB11_F0
ultrasonic_uart_BUART_sTX_TxShifter_u0__F1_REG EQU CYREG_B0_UDB11_F1
ultrasonic_uart_BUART_sTX_TxSts__0__MASK EQU 0x01
ultrasonic_uart_BUART_sTX_TxSts__0__POS EQU 0
ultrasonic_uart_BUART_sTX_TxSts__16BIT_STATUS_AUX_CTL_REG EQU CYREG_B0_UDB11_12_ACTL
ultrasonic_uart_BUART_sTX_TxSts__16BIT_STATUS_REG EQU CYREG_B0_UDB11_12_ST
ultrasonic_uart_BUART_sTX_TxSts__1__MASK EQU 0x02
ultrasonic_uart_BUART_sTX_TxSts__1__POS EQU 1
ultrasonic_uart_BUART_sTX_TxSts__2__MASK EQU 0x04
ultrasonic_uart_BUART_sTX_TxSts__2__POS EQU 2
ultrasonic_uart_BUART_sTX_TxSts__3__MASK EQU 0x08
ultrasonic_uart_BUART_sTX_TxSts__3__POS EQU 3
ultrasonic_uart_BUART_sTX_TxSts__MASK EQU 0x0F
ultrasonic_uart_BUART_sTX_TxSts__MASK_REG EQU CYREG_B0_UDB11_MSK
ultrasonic_uart_BUART_sTX_TxSts__STATUS_AUX_CTL_REG EQU CYREG_B0_UDB11_ACTL
ultrasonic_uart_BUART_sTX_TxSts__STATUS_REG EQU CYREG_B0_UDB11_ST
ultrasonic_uart_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_A0_REG EQU CYREG_B0_UDB08_09_A0
ultrasonic_uart_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_A1_REG EQU CYREG_B0_UDB08_09_A1
ultrasonic_uart_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_D0_REG EQU CYREG_B0_UDB08_09_D0
ultrasonic_uart_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_D1_REG EQU CYREG_B0_UDB08_09_D1
ultrasonic_uart_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_DP_AUX_CTL_REG EQU CYREG_B0_UDB08_09_ACTL
ultrasonic_uart_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_F0_REG EQU CYREG_B0_UDB08_09_F0
ultrasonic_uart_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_F1_REG EQU CYREG_B0_UDB08_09_F1
ultrasonic_uart_BUART_sTX_sCLOCK_TxBitClkGen__A0_A1_REG EQU CYREG_B0_UDB08_A0_A1
ultrasonic_uart_BUART_sTX_sCLOCK_TxBitClkGen__A0_REG EQU CYREG_B0_UDB08_A0
ultrasonic_uart_BUART_sTX_sCLOCK_TxBitClkGen__A1_REG EQU CYREG_B0_UDB08_A1
ultrasonic_uart_BUART_sTX_sCLOCK_TxBitClkGen__D0_D1_REG EQU CYREG_B0_UDB08_D0_D1
ultrasonic_uart_BUART_sTX_sCLOCK_TxBitClkGen__D0_REG EQU CYREG_B0_UDB08_D0
ultrasonic_uart_BUART_sTX_sCLOCK_TxBitClkGen__D1_REG EQU CYREG_B0_UDB08_D1
ultrasonic_uart_BUART_sTX_sCLOCK_TxBitClkGen__DP_AUX_CTL_REG EQU CYREG_B0_UDB08_ACTL
ultrasonic_uart_BUART_sTX_sCLOCK_TxBitClkGen__F0_F1_REG EQU CYREG_B0_UDB08_F0_F1
ultrasonic_uart_BUART_sTX_sCLOCK_TxBitClkGen__F0_REG EQU CYREG_B0_UDB08_F0
ultrasonic_uart_BUART_sTX_sCLOCK_TxBitClkGen__F1_REG EQU CYREG_B0_UDB08_F1

; ultrasonic_uart_rx
ultrasonic_uart_rx__0__MASK EQU 0x08
ultrasonic_uart_rx__0__PC EQU CYREG_PRT6_PC3
ultrasonic_uart_rx__0__PORT EQU 6
ultrasonic_uart_rx__0__SHIFT EQU 3
ultrasonic_uart_rx__AG EQU CYREG_PRT6_AG
ultrasonic_uart_rx__AMUX EQU CYREG_PRT6_AMUX
ultrasonic_uart_rx__BIE EQU CYREG_PRT6_BIE
ultrasonic_uart_rx__BIT_MASK EQU CYREG_PRT6_BIT_MASK
ultrasonic_uart_rx__BYP EQU CYREG_PRT6_BYP
ultrasonic_uart_rx__CTL EQU CYREG_PRT6_CTL
ultrasonic_uart_rx__DM0 EQU CYREG_PRT6_DM0
ultrasonic_uart_rx__DM1 EQU CYREG_PRT6_DM1
ultrasonic_uart_rx__DM2 EQU CYREG_PRT6_DM2
ultrasonic_uart_rx__DR EQU CYREG_PRT6_DR
ultrasonic_uart_rx__INP_DIS EQU CYREG_PRT6_INP_DIS
ultrasonic_uart_rx__LCD_COM_SEG EQU CYREG_PRT6_LCD_COM_SEG
ultrasonic_uart_rx__LCD_EN EQU CYREG_PRT6_LCD_EN
ultrasonic_uart_rx__MASK EQU 0x08
ultrasonic_uart_rx__PORT EQU 6
ultrasonic_uart_rx__PRT EQU CYREG_PRT6_PRT
ultrasonic_uart_rx__PRTDSI__CAPS_SEL EQU CYREG_PRT6_CAPS_SEL
ultrasonic_uart_rx__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT6_DBL_SYNC_IN
ultrasonic_uart_rx__PRTDSI__OE_SEL0 EQU CYREG_PRT6_OE_SEL0
ultrasonic_uart_rx__PRTDSI__OE_SEL1 EQU CYREG_PRT6_OE_SEL1
ultrasonic_uart_rx__PRTDSI__OUT_SEL0 EQU CYREG_PRT6_OUT_SEL0
ultrasonic_uart_rx__PRTDSI__OUT_SEL1 EQU CYREG_PRT6_OUT_SEL1
ultrasonic_uart_rx__PRTDSI__SYNC_OUT EQU CYREG_PRT6_SYNC_OUT
ultrasonic_uart_rx__PS EQU CYREG_PRT6_PS
ultrasonic_uart_rx__SHIFT EQU 3
ultrasonic_uart_rx__SLW EQU CYREG_PRT6_SLW

; modem_voltage_pin
modem_voltage_pin__0__MASK EQU 0x08
modem_voltage_pin__0__PC EQU CYREG_PRT12_PC3
modem_voltage_pin__0__PORT EQU 12
modem_voltage_pin__0__SHIFT EQU 3
modem_voltage_pin__AG EQU CYREG_PRT12_AG
modem_voltage_pin__BIE EQU CYREG_PRT12_BIE
modem_voltage_pin__BIT_MASK EQU CYREG_PRT12_BIT_MASK
modem_voltage_pin__BYP EQU CYREG_PRT12_BYP
modem_voltage_pin__DM0 EQU CYREG_PRT12_DM0
modem_voltage_pin__DM1 EQU CYREG_PRT12_DM1
modem_voltage_pin__DM2 EQU CYREG_PRT12_DM2
modem_voltage_pin__DR EQU CYREG_PRT12_DR
modem_voltage_pin__INP_DIS EQU CYREG_PRT12_INP_DIS
modem_voltage_pin__MASK EQU 0x08
modem_voltage_pin__PORT EQU 12
modem_voltage_pin__PRT EQU CYREG_PRT12_PRT
modem_voltage_pin__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT12_DBL_SYNC_IN
modem_voltage_pin__PRTDSI__OE_SEL0 EQU CYREG_PRT12_OE_SEL0
modem_voltage_pin__PRTDSI__OE_SEL1 EQU CYREG_PRT12_OE_SEL1
modem_voltage_pin__PRTDSI__OUT_SEL0 EQU CYREG_PRT12_OUT_SEL0
modem_voltage_pin__PRTDSI__OUT_SEL1 EQU CYREG_PRT12_OUT_SEL1
modem_voltage_pin__PRTDSI__SYNC_OUT EQU CYREG_PRT12_SYNC_OUT
modem_voltage_pin__PS EQU CYREG_PRT12_PS
modem_voltage_pin__SHIFT EQU 3
modem_voltage_pin__SIO_CFG EQU CYREG_PRT12_SIO_CFG
modem_voltage_pin__SIO_DIFF EQU CYREG_PRT12_SIO_DIFF
modem_voltage_pin__SIO_HYST_EN EQU CYREG_PRT12_SIO_HYST_EN
modem_voltage_pin__SIO_REG_HIFREQ EQU CYREG_PRT12_SIO_REG_HIFREQ
modem_voltage_pin__SLW EQU CYREG_PRT12_SLW

; modem_power_pin
modem_power_pin__0__MASK EQU 0x01
modem_power_pin__0__PC EQU CYREG_PRT4_PC0
modem_power_pin__0__PORT EQU 4
modem_power_pin__0__SHIFT EQU 0
modem_power_pin__AG EQU CYREG_PRT4_AG
modem_power_pin__AMUX EQU CYREG_PRT4_AMUX
modem_power_pin__BIE EQU CYREG_PRT4_BIE
modem_power_pin__BIT_MASK EQU CYREG_PRT4_BIT_MASK
modem_power_pin__BYP EQU CYREG_PRT4_BYP
modem_power_pin__CTL EQU CYREG_PRT4_CTL
modem_power_pin__DM0 EQU CYREG_PRT4_DM0
modem_power_pin__DM1 EQU CYREG_PRT4_DM1
modem_power_pin__DM2 EQU CYREG_PRT4_DM2
modem_power_pin__DR EQU CYREG_PRT4_DR
modem_power_pin__INP_DIS EQU CYREG_PRT4_INP_DIS
modem_power_pin__LCD_COM_SEG EQU CYREG_PRT4_LCD_COM_SEG
modem_power_pin__LCD_EN EQU CYREG_PRT4_LCD_EN
modem_power_pin__MASK EQU 0x01
modem_power_pin__PORT EQU 4
modem_power_pin__PRT EQU CYREG_PRT4_PRT
modem_power_pin__PRTDSI__CAPS_SEL EQU CYREG_PRT4_CAPS_SEL
modem_power_pin__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT4_DBL_SYNC_IN
modem_power_pin__PRTDSI__OE_SEL0 EQU CYREG_PRT4_OE_SEL0
modem_power_pin__PRTDSI__OE_SEL1 EQU CYREG_PRT4_OE_SEL1
modem_power_pin__PRTDSI__OUT_SEL0 EQU CYREG_PRT4_OUT_SEL0
modem_power_pin__PRTDSI__OUT_SEL1 EQU CYREG_PRT4_OUT_SEL1
modem_power_pin__PRTDSI__SYNC_OUT EQU CYREG_PRT4_SYNC_OUT
modem_power_pin__PS EQU CYREG_PRT4_PS
modem_power_pin__SHIFT EQU 0
modem_power_pin__SLW EQU CYREG_PRT4_SLW

; timer_TimerUDB
timer_TimerUDB_nrstSts_stsreg__0__MASK EQU 0x01
timer_TimerUDB_nrstSts_stsreg__0__POS EQU 0
timer_TimerUDB_nrstSts_stsreg__16BIT_STATUS_AUX_CTL_REG EQU CYREG_B1_UDB07_08_ACTL
timer_TimerUDB_nrstSts_stsreg__16BIT_STATUS_REG EQU CYREG_B1_UDB07_08_ST
timer_TimerUDB_nrstSts_stsreg__2__MASK EQU 0x04
timer_TimerUDB_nrstSts_stsreg__2__POS EQU 2
timer_TimerUDB_nrstSts_stsreg__3__MASK EQU 0x08
timer_TimerUDB_nrstSts_stsreg__3__POS EQU 3
timer_TimerUDB_nrstSts_stsreg__MASK EQU 0x0D
timer_TimerUDB_nrstSts_stsreg__MASK_REG EQU CYREG_B1_UDB07_MSK
timer_TimerUDB_nrstSts_stsreg__STATUS_AUX_CTL_REG EQU CYREG_B1_UDB07_ACTL
timer_TimerUDB_nrstSts_stsreg__STATUS_REG EQU CYREG_B1_UDB07_ST
timer_TimerUDB_sCTRLReg_AsyncCtl_ctrlreg__16BIT_CONTROL_AUX_CTL_REG EQU CYREG_B1_UDB04_05_ACTL
timer_TimerUDB_sCTRLReg_AsyncCtl_ctrlreg__16BIT_CONTROL_CONTROL_REG EQU CYREG_B1_UDB04_05_CTL
timer_TimerUDB_sCTRLReg_AsyncCtl_ctrlreg__16BIT_CONTROL_COUNT_REG EQU CYREG_B1_UDB04_05_CTL
timer_TimerUDB_sCTRLReg_AsyncCtl_ctrlreg__16BIT_COUNT_CONTROL_REG EQU CYREG_B1_UDB04_05_CTL
timer_TimerUDB_sCTRLReg_AsyncCtl_ctrlreg__16BIT_COUNT_COUNT_REG EQU CYREG_B1_UDB04_05_CTL
timer_TimerUDB_sCTRLReg_AsyncCtl_ctrlreg__16BIT_MASK_MASK_REG EQU CYREG_B1_UDB04_05_MSK
timer_TimerUDB_sCTRLReg_AsyncCtl_ctrlreg__16BIT_MASK_PERIOD_REG EQU CYREG_B1_UDB04_05_MSK
timer_TimerUDB_sCTRLReg_AsyncCtl_ctrlreg__16BIT_PERIOD_MASK_REG EQU CYREG_B1_UDB04_05_MSK
timer_TimerUDB_sCTRLReg_AsyncCtl_ctrlreg__16BIT_PERIOD_PERIOD_REG EQU CYREG_B1_UDB04_05_MSK
timer_TimerUDB_sCTRLReg_AsyncCtl_ctrlreg__7__MASK EQU 0x80
timer_TimerUDB_sCTRLReg_AsyncCtl_ctrlreg__7__POS EQU 7
timer_TimerUDB_sCTRLReg_AsyncCtl_ctrlreg__CONTROL_AUX_CTL_REG EQU CYREG_B1_UDB04_ACTL
timer_TimerUDB_sCTRLReg_AsyncCtl_ctrlreg__CONTROL_REG EQU CYREG_B1_UDB04_CTL
timer_TimerUDB_sCTRLReg_AsyncCtl_ctrlreg__CONTROL_ST_REG EQU CYREG_B1_UDB04_ST_CTL
timer_TimerUDB_sCTRLReg_AsyncCtl_ctrlreg__COUNT_REG EQU CYREG_B1_UDB04_CTL
timer_TimerUDB_sCTRLReg_AsyncCtl_ctrlreg__COUNT_ST_REG EQU CYREG_B1_UDB04_ST_CTL
timer_TimerUDB_sCTRLReg_AsyncCtl_ctrlreg__MASK EQU 0x80
timer_TimerUDB_sCTRLReg_AsyncCtl_ctrlreg__MASK_CTL_AUX_CTL_REG EQU CYREG_B1_UDB04_MSK_ACTL
timer_TimerUDB_sCTRLReg_AsyncCtl_ctrlreg__PERIOD_REG EQU CYREG_B1_UDB04_MSK
timer_TimerUDB_sCTRLReg_AsyncCtl_ctrlreg__PER_CTL_AUX_CTL_REG EQU CYREG_B1_UDB04_MSK_ACTL
timer_TimerUDB_sT32_timerdp_u0__16BIT_A0_REG EQU CYREG_B1_UDB04_05_A0
timer_TimerUDB_sT32_timerdp_u0__16BIT_A1_REG EQU CYREG_B1_UDB04_05_A1
timer_TimerUDB_sT32_timerdp_u0__16BIT_D0_REG EQU CYREG_B1_UDB04_05_D0
timer_TimerUDB_sT32_timerdp_u0__16BIT_D1_REG EQU CYREG_B1_UDB04_05_D1
timer_TimerUDB_sT32_timerdp_u0__16BIT_DP_AUX_CTL_REG EQU CYREG_B1_UDB04_05_ACTL
timer_TimerUDB_sT32_timerdp_u0__16BIT_F0_REG EQU CYREG_B1_UDB04_05_F0
timer_TimerUDB_sT32_timerdp_u0__16BIT_F1_REG EQU CYREG_B1_UDB04_05_F1
timer_TimerUDB_sT32_timerdp_u0__A0_A1_REG EQU CYREG_B1_UDB04_A0_A1
timer_TimerUDB_sT32_timerdp_u0__A0_REG EQU CYREG_B1_UDB04_A0
timer_TimerUDB_sT32_timerdp_u0__A1_REG EQU CYREG_B1_UDB04_A1
timer_TimerUDB_sT32_timerdp_u0__D0_D1_REG EQU CYREG_B1_UDB04_D0_D1
timer_TimerUDB_sT32_timerdp_u0__D0_REG EQU CYREG_B1_UDB04_D0
timer_TimerUDB_sT32_timerdp_u0__D1_REG EQU CYREG_B1_UDB04_D1
timer_TimerUDB_sT32_timerdp_u0__DP_AUX_CTL_REG EQU CYREG_B1_UDB04_ACTL
timer_TimerUDB_sT32_timerdp_u0__F0_F1_REG EQU CYREG_B1_UDB04_F0_F1
timer_TimerUDB_sT32_timerdp_u0__F0_REG EQU CYREG_B1_UDB04_F0
timer_TimerUDB_sT32_timerdp_u0__F1_REG EQU CYREG_B1_UDB04_F1
timer_TimerUDB_sT32_timerdp_u0__MSK_DP_AUX_CTL_REG EQU CYREG_B1_UDB04_MSK_ACTL
timer_TimerUDB_sT32_timerdp_u0__PER_DP_AUX_CTL_REG EQU CYREG_B1_UDB04_MSK_ACTL
timer_TimerUDB_sT32_timerdp_u1__16BIT_A0_REG EQU CYREG_B1_UDB05_06_A0
timer_TimerUDB_sT32_timerdp_u1__16BIT_A1_REG EQU CYREG_B1_UDB05_06_A1
timer_TimerUDB_sT32_timerdp_u1__16BIT_D0_REG EQU CYREG_B1_UDB05_06_D0
timer_TimerUDB_sT32_timerdp_u1__16BIT_D1_REG EQU CYREG_B1_UDB05_06_D1
timer_TimerUDB_sT32_timerdp_u1__16BIT_DP_AUX_CTL_REG EQU CYREG_B1_UDB05_06_ACTL
timer_TimerUDB_sT32_timerdp_u1__16BIT_F0_REG EQU CYREG_B1_UDB05_06_F0
timer_TimerUDB_sT32_timerdp_u1__16BIT_F1_REG EQU CYREG_B1_UDB05_06_F1
timer_TimerUDB_sT32_timerdp_u1__A0_A1_REG EQU CYREG_B1_UDB05_A0_A1
timer_TimerUDB_sT32_timerdp_u1__A0_REG EQU CYREG_B1_UDB05_A0
timer_TimerUDB_sT32_timerdp_u1__A1_REG EQU CYREG_B1_UDB05_A1
timer_TimerUDB_sT32_timerdp_u1__D0_D1_REG EQU CYREG_B1_UDB05_D0_D1
timer_TimerUDB_sT32_timerdp_u1__D0_REG EQU CYREG_B1_UDB05_D0
timer_TimerUDB_sT32_timerdp_u1__D1_REG EQU CYREG_B1_UDB05_D1
timer_TimerUDB_sT32_timerdp_u1__DP_AUX_CTL_REG EQU CYREG_B1_UDB05_ACTL
timer_TimerUDB_sT32_timerdp_u1__F0_F1_REG EQU CYREG_B1_UDB05_F0_F1
timer_TimerUDB_sT32_timerdp_u1__F0_REG EQU CYREG_B1_UDB05_F0
timer_TimerUDB_sT32_timerdp_u1__F1_REG EQU CYREG_B1_UDB05_F1
timer_TimerUDB_sT32_timerdp_u2__16BIT_A0_REG EQU CYREG_B1_UDB06_07_A0
timer_TimerUDB_sT32_timerdp_u2__16BIT_A1_REG EQU CYREG_B1_UDB06_07_A1
timer_TimerUDB_sT32_timerdp_u2__16BIT_D0_REG EQU CYREG_B1_UDB06_07_D0
timer_TimerUDB_sT32_timerdp_u2__16BIT_D1_REG EQU CYREG_B1_UDB06_07_D1
timer_TimerUDB_sT32_timerdp_u2__16BIT_DP_AUX_CTL_REG EQU CYREG_B1_UDB06_07_ACTL
timer_TimerUDB_sT32_timerdp_u2__16BIT_F0_REG EQU CYREG_B1_UDB06_07_F0
timer_TimerUDB_sT32_timerdp_u2__16BIT_F1_REG EQU CYREG_B1_UDB06_07_F1
timer_TimerUDB_sT32_timerdp_u2__A0_A1_REG EQU CYREG_B1_UDB06_A0_A1
timer_TimerUDB_sT32_timerdp_u2__A0_REG EQU CYREG_B1_UDB06_A0
timer_TimerUDB_sT32_timerdp_u2__A1_REG EQU CYREG_B1_UDB06_A1
timer_TimerUDB_sT32_timerdp_u2__D0_D1_REG EQU CYREG_B1_UDB06_D0_D1
timer_TimerUDB_sT32_timerdp_u2__D0_REG EQU CYREG_B1_UDB06_D0
timer_TimerUDB_sT32_timerdp_u2__D1_REG EQU CYREG_B1_UDB06_D1
timer_TimerUDB_sT32_timerdp_u2__DP_AUX_CTL_REG EQU CYREG_B1_UDB06_ACTL
timer_TimerUDB_sT32_timerdp_u2__F0_F1_REG EQU CYREG_B1_UDB06_F0_F1
timer_TimerUDB_sT32_timerdp_u2__F0_REG EQU CYREG_B1_UDB06_F0
timer_TimerUDB_sT32_timerdp_u2__F1_REG EQU CYREG_B1_UDB06_F1
timer_TimerUDB_sT32_timerdp_u3__16BIT_A0_REG EQU CYREG_B1_UDB07_08_A0
timer_TimerUDB_sT32_timerdp_u3__16BIT_A1_REG EQU CYREG_B1_UDB07_08_A1
timer_TimerUDB_sT32_timerdp_u3__16BIT_D0_REG EQU CYREG_B1_UDB07_08_D0
timer_TimerUDB_sT32_timerdp_u3__16BIT_D1_REG EQU CYREG_B1_UDB07_08_D1
timer_TimerUDB_sT32_timerdp_u3__16BIT_DP_AUX_CTL_REG EQU CYREG_B1_UDB07_08_ACTL
timer_TimerUDB_sT32_timerdp_u3__16BIT_F0_REG EQU CYREG_B1_UDB07_08_F0
timer_TimerUDB_sT32_timerdp_u3__16BIT_F1_REG EQU CYREG_B1_UDB07_08_F1
timer_TimerUDB_sT32_timerdp_u3__A0_A1_REG EQU CYREG_B1_UDB07_A0_A1
timer_TimerUDB_sT32_timerdp_u3__A0_REG EQU CYREG_B1_UDB07_A0
timer_TimerUDB_sT32_timerdp_u3__A1_REG EQU CYREG_B1_UDB07_A1
timer_TimerUDB_sT32_timerdp_u3__D0_D1_REG EQU CYREG_B1_UDB07_D0_D1
timer_TimerUDB_sT32_timerdp_u3__D0_REG EQU CYREG_B1_UDB07_D0
timer_TimerUDB_sT32_timerdp_u3__D1_REG EQU CYREG_B1_UDB07_D1
timer_TimerUDB_sT32_timerdp_u3__DP_AUX_CTL_REG EQU CYREG_B1_UDB07_ACTL
timer_TimerUDB_sT32_timerdp_u3__F0_F1_REG EQU CYREG_B1_UDB07_F0_F1
timer_TimerUDB_sT32_timerdp_u3__F0_REG EQU CYREG_B1_UDB07_F0
timer_TimerUDB_sT32_timerdp_u3__F1_REG EQU CYREG_B1_UDB07_F1

; uart_IntClock
uart_IntClock__CFG0 EQU CYREG_CLKDIST_DCFG0_CFG0
uart_IntClock__CFG1 EQU CYREG_CLKDIST_DCFG0_CFG1
uart_IntClock__CFG2 EQU CYREG_CLKDIST_DCFG0_CFG2
uart_IntClock__CFG2_SRC_SEL_MASK EQU 0x07
uart_IntClock__INDEX EQU 0x00
uart_IntClock__PM_ACT_CFG EQU CYREG_PM_ACT_CFG2
uart_IntClock__PM_ACT_MSK EQU 0x01
uart_IntClock__PM_STBY_CFG EQU CYREG_PM_STBY_CFG2
uart_IntClock__PM_STBY_MSK EQU 0x01

; isr_byte_rx
isr_byte_rx__INTC_CLR_EN_REG EQU CYREG_NVIC_CLRENA0
isr_byte_rx__INTC_CLR_PD_REG EQU CYREG_NVIC_CLRPEND0
isr_byte_rx__INTC_MASK EQU 0x02
isr_byte_rx__INTC_NUMBER EQU 1
isr_byte_rx__INTC_PRIOR_NUM EQU 7
isr_byte_rx__INTC_PRIOR_REG EQU CYREG_NVIC_PRI_1
isr_byte_rx__INTC_SET_EN_REG EQU CYREG_NVIC_SETENA0
isr_byte_rx__INTC_SET_PD_REG EQU CYREG_NVIC_SETPEND0

; uart_BUART
uart_BUART_sRX_RxBitCounter_ST__16BIT_STATUS_AUX_CTL_REG EQU CYREG_B0_UDB14_15_ACTL
uart_BUART_sRX_RxBitCounter_ST__16BIT_STATUS_REG EQU CYREG_B0_UDB14_15_ST
uart_BUART_sRX_RxBitCounter_ST__MASK_REG EQU CYREG_B0_UDB14_MSK
uart_BUART_sRX_RxBitCounter_ST__MASK_ST_AUX_CTL_REG EQU CYREG_B0_UDB14_MSK_ACTL
uart_BUART_sRX_RxBitCounter_ST__PER_ST_AUX_CTL_REG EQU CYREG_B0_UDB14_MSK_ACTL
uart_BUART_sRX_RxBitCounter_ST__STATUS_AUX_CTL_REG EQU CYREG_B0_UDB14_ACTL
uart_BUART_sRX_RxBitCounter_ST__STATUS_CNT_REG EQU CYREG_B0_UDB14_ST_CTL
uart_BUART_sRX_RxBitCounter_ST__STATUS_CONTROL_REG EQU CYREG_B0_UDB14_ST_CTL
uart_BUART_sRX_RxBitCounter_ST__STATUS_REG EQU CYREG_B0_UDB14_ST
uart_BUART_sRX_RxBitCounter__16BIT_CONTROL_AUX_CTL_REG EQU CYREG_B0_UDB14_15_ACTL
uart_BUART_sRX_RxBitCounter__16BIT_CONTROL_CONTROL_REG EQU CYREG_B0_UDB14_15_CTL
uart_BUART_sRX_RxBitCounter__16BIT_CONTROL_COUNT_REG EQU CYREG_B0_UDB14_15_CTL
uart_BUART_sRX_RxBitCounter__16BIT_COUNT_CONTROL_REG EQU CYREG_B0_UDB14_15_CTL
uart_BUART_sRX_RxBitCounter__16BIT_COUNT_COUNT_REG EQU CYREG_B0_UDB14_15_CTL
uart_BUART_sRX_RxBitCounter__16BIT_MASK_MASK_REG EQU CYREG_B0_UDB14_15_MSK
uart_BUART_sRX_RxBitCounter__16BIT_MASK_PERIOD_REG EQU CYREG_B0_UDB14_15_MSK
uart_BUART_sRX_RxBitCounter__16BIT_PERIOD_MASK_REG EQU CYREG_B0_UDB14_15_MSK
uart_BUART_sRX_RxBitCounter__16BIT_PERIOD_PERIOD_REG EQU CYREG_B0_UDB14_15_MSK
uart_BUART_sRX_RxBitCounter__CONTROL_AUX_CTL_REG EQU CYREG_B0_UDB14_ACTL
uart_BUART_sRX_RxBitCounter__CONTROL_REG EQU CYREG_B0_UDB14_CTL
uart_BUART_sRX_RxBitCounter__CONTROL_ST_REG EQU CYREG_B0_UDB14_ST_CTL
uart_BUART_sRX_RxBitCounter__COUNT_REG EQU CYREG_B0_UDB14_CTL
uart_BUART_sRX_RxBitCounter__COUNT_ST_REG EQU CYREG_B0_UDB14_ST_CTL
uart_BUART_sRX_RxBitCounter__MASK_CTL_AUX_CTL_REG EQU CYREG_B0_UDB14_MSK_ACTL
uart_BUART_sRX_RxBitCounter__PERIOD_REG EQU CYREG_B0_UDB14_MSK
uart_BUART_sRX_RxBitCounter__PER_CTL_AUX_CTL_REG EQU CYREG_B0_UDB14_MSK_ACTL
uart_BUART_sRX_RxShifter_u0__16BIT_A0_REG EQU CYREG_B0_UDB13_14_A0
uart_BUART_sRX_RxShifter_u0__16BIT_A1_REG EQU CYREG_B0_UDB13_14_A1
uart_BUART_sRX_RxShifter_u0__16BIT_D0_REG EQU CYREG_B0_UDB13_14_D0
uart_BUART_sRX_RxShifter_u0__16BIT_D1_REG EQU CYREG_B0_UDB13_14_D1
uart_BUART_sRX_RxShifter_u0__16BIT_DP_AUX_CTL_REG EQU CYREG_B0_UDB13_14_ACTL
uart_BUART_sRX_RxShifter_u0__16BIT_F0_REG EQU CYREG_B0_UDB13_14_F0
uart_BUART_sRX_RxShifter_u0__16BIT_F1_REG EQU CYREG_B0_UDB13_14_F1
uart_BUART_sRX_RxShifter_u0__A0_A1_REG EQU CYREG_B0_UDB13_A0_A1
uart_BUART_sRX_RxShifter_u0__A0_REG EQU CYREG_B0_UDB13_A0
uart_BUART_sRX_RxShifter_u0__A1_REG EQU CYREG_B0_UDB13_A1
uart_BUART_sRX_RxShifter_u0__D0_D1_REG EQU CYREG_B0_UDB13_D0_D1
uart_BUART_sRX_RxShifter_u0__D0_REG EQU CYREG_B0_UDB13_D0
uart_BUART_sRX_RxShifter_u0__D1_REG EQU CYREG_B0_UDB13_D1
uart_BUART_sRX_RxShifter_u0__DP_AUX_CTL_REG EQU CYREG_B0_UDB13_ACTL
uart_BUART_sRX_RxShifter_u0__F0_F1_REG EQU CYREG_B0_UDB13_F0_F1
uart_BUART_sRX_RxShifter_u0__F0_REG EQU CYREG_B0_UDB13_F0
uart_BUART_sRX_RxShifter_u0__F1_REG EQU CYREG_B0_UDB13_F1
uart_BUART_sRX_RxSts__16BIT_STATUS_AUX_CTL_REG EQU CYREG_B0_UDB13_14_ACTL
uart_BUART_sRX_RxSts__16BIT_STATUS_REG EQU CYREG_B0_UDB13_14_ST
uart_BUART_sRX_RxSts__3__MASK EQU 0x08
uart_BUART_sRX_RxSts__3__POS EQU 3
uart_BUART_sRX_RxSts__4__MASK EQU 0x10
uart_BUART_sRX_RxSts__4__POS EQU 4
uart_BUART_sRX_RxSts__5__MASK EQU 0x20
uart_BUART_sRX_RxSts__5__POS EQU 5
uart_BUART_sRX_RxSts__MASK EQU 0x38
uart_BUART_sRX_RxSts__MASK_REG EQU CYREG_B0_UDB13_MSK
uart_BUART_sRX_RxSts__STATUS_AUX_CTL_REG EQU CYREG_B0_UDB13_ACTL
uart_BUART_sRX_RxSts__STATUS_REG EQU CYREG_B0_UDB13_ST
uart_BUART_sTX_TxShifter_u0__16BIT_A0_REG EQU CYREG_B0_UDB12_13_A0
uart_BUART_sTX_TxShifter_u0__16BIT_A1_REG EQU CYREG_B0_UDB12_13_A1
uart_BUART_sTX_TxShifter_u0__16BIT_D0_REG EQU CYREG_B0_UDB12_13_D0
uart_BUART_sTX_TxShifter_u0__16BIT_D1_REG EQU CYREG_B0_UDB12_13_D1
uart_BUART_sTX_TxShifter_u0__16BIT_DP_AUX_CTL_REG EQU CYREG_B0_UDB12_13_ACTL
uart_BUART_sTX_TxShifter_u0__16BIT_F0_REG EQU CYREG_B0_UDB12_13_F0
uart_BUART_sTX_TxShifter_u0__16BIT_F1_REG EQU CYREG_B0_UDB12_13_F1
uart_BUART_sTX_TxShifter_u0__A0_A1_REG EQU CYREG_B0_UDB12_A0_A1
uart_BUART_sTX_TxShifter_u0__A0_REG EQU CYREG_B0_UDB12_A0
uart_BUART_sTX_TxShifter_u0__A1_REG EQU CYREG_B0_UDB12_A1
uart_BUART_sTX_TxShifter_u0__D0_D1_REG EQU CYREG_B0_UDB12_D0_D1
uart_BUART_sTX_TxShifter_u0__D0_REG EQU CYREG_B0_UDB12_D0
uart_BUART_sTX_TxShifter_u0__D1_REG EQU CYREG_B0_UDB12_D1
uart_BUART_sTX_TxShifter_u0__DP_AUX_CTL_REG EQU CYREG_B0_UDB12_ACTL
uart_BUART_sTX_TxShifter_u0__F0_F1_REG EQU CYREG_B0_UDB12_F0_F1
uart_BUART_sTX_TxShifter_u0__F0_REG EQU CYREG_B0_UDB12_F0
uart_BUART_sTX_TxShifter_u0__F1_REG EQU CYREG_B0_UDB12_F1
uart_BUART_sTX_TxSts__0__MASK EQU 0x01
uart_BUART_sTX_TxSts__0__POS EQU 0
uart_BUART_sTX_TxSts__16BIT_STATUS_AUX_CTL_REG EQU CYREG_B0_UDB12_13_ACTL
uart_BUART_sTX_TxSts__16BIT_STATUS_REG EQU CYREG_B0_UDB12_13_ST
uart_BUART_sTX_TxSts__1__MASK EQU 0x02
uart_BUART_sTX_TxSts__1__POS EQU 1
uart_BUART_sTX_TxSts__2__MASK EQU 0x04
uart_BUART_sTX_TxSts__2__POS EQU 2
uart_BUART_sTX_TxSts__3__MASK EQU 0x08
uart_BUART_sTX_TxSts__3__POS EQU 3
uart_BUART_sTX_TxSts__MASK EQU 0x0F
uart_BUART_sTX_TxSts__MASK_REG EQU CYREG_B0_UDB12_MSK
uart_BUART_sTX_TxSts__STATUS_AUX_CTL_REG EQU CYREG_B0_UDB12_ACTL
uart_BUART_sTX_TxSts__STATUS_REG EQU CYREG_B0_UDB12_ST
uart_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_A0_REG EQU CYREG_B0_UDB10_11_A0
uart_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_A1_REG EQU CYREG_B0_UDB10_11_A1
uart_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_D0_REG EQU CYREG_B0_UDB10_11_D0
uart_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_D1_REG EQU CYREG_B0_UDB10_11_D1
uart_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_DP_AUX_CTL_REG EQU CYREG_B0_UDB10_11_ACTL
uart_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_F0_REG EQU CYREG_B0_UDB10_11_F0
uart_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_F1_REG EQU CYREG_B0_UDB10_11_F1
uart_BUART_sTX_sCLOCK_TxBitClkGen__A0_A1_REG EQU CYREG_B0_UDB10_A0_A1
uart_BUART_sTX_sCLOCK_TxBitClkGen__A0_REG EQU CYREG_B0_UDB10_A0
uart_BUART_sTX_sCLOCK_TxBitClkGen__A1_REG EQU CYREG_B0_UDB10_A1
uart_BUART_sTX_sCLOCK_TxBitClkGen__D0_D1_REG EQU CYREG_B0_UDB10_D0_D1
uart_BUART_sTX_sCLOCK_TxBitClkGen__D0_REG EQU CYREG_B0_UDB10_D0
uart_BUART_sTX_sCLOCK_TxBitClkGen__D1_REG EQU CYREG_B0_UDB10_D1
uart_BUART_sTX_sCLOCK_TxBitClkGen__DP_AUX_CTL_REG EQU CYREG_B0_UDB10_ACTL
uart_BUART_sTX_sCLOCK_TxBitClkGen__F0_F1_REG EQU CYREG_B0_UDB10_F0_F1
uart_BUART_sTX_sCLOCK_TxBitClkGen__F0_REG EQU CYREG_B0_UDB10_F0
uart_BUART_sTX_sCLOCK_TxBitClkGen__F1_REG EQU CYREG_B0_UDB10_F1

; isr_timer
isr_timer__INTC_CLR_EN_REG EQU CYREG_NVIC_CLRENA0
isr_timer__INTC_CLR_PD_REG EQU CYREG_NVIC_CLRPEND0
isr_timer__INTC_MASK EQU 0x08
isr_timer__INTC_NUMBER EQU 3
isr_timer__INTC_PRIOR_NUM EQU 7
isr_timer__INTC_PRIOR_REG EQU CYREG_NVIC_PRI_3
isr_timer__INTC_SET_EN_REG EQU CYREG_NVIC_SETENA0
isr_timer__INTC_SET_PD_REG EQU CYREG_NVIC_SETPEND0

; uart_rx
uart_rx__0__MASK EQU 0x02
uart_rx__0__PC EQU CYREG_PRT0_PC1
uart_rx__0__PORT EQU 0
uart_rx__0__SHIFT EQU 1
uart_rx__AG EQU CYREG_PRT0_AG
uart_rx__AMUX EQU CYREG_PRT0_AMUX
uart_rx__BIE EQU CYREG_PRT0_BIE
uart_rx__BIT_MASK EQU CYREG_PRT0_BIT_MASK
uart_rx__BYP EQU CYREG_PRT0_BYP
uart_rx__CTL EQU CYREG_PRT0_CTL
uart_rx__DM0 EQU CYREG_PRT0_DM0
uart_rx__DM1 EQU CYREG_PRT0_DM1
uart_rx__DM2 EQU CYREG_PRT0_DM2
uart_rx__DR EQU CYREG_PRT0_DR
uart_rx__INP_DIS EQU CYREG_PRT0_INP_DIS
uart_rx__LCD_COM_SEG EQU CYREG_PRT0_LCD_COM_SEG
uart_rx__LCD_EN EQU CYREG_PRT0_LCD_EN
uart_rx__MASK EQU 0x02
uart_rx__PORT EQU 0
uart_rx__PRT EQU CYREG_PRT0_PRT
uart_rx__PRTDSI__CAPS_SEL EQU CYREG_PRT0_CAPS_SEL
uart_rx__PRTDSI__DBL_SYNC_IN EQU CYREG_PRT0_DBL_SYNC_IN
uart_rx__PRTDSI__OE_SEL0 EQU CYREG_PRT0_OE_SEL0
uart_rx__PRTDSI__OE_SEL1 EQU CYREG_PRT0_OE_SEL1
uart_rx__PRTDSI__OUT_SEL0 EQU CYREG_PRT0_OUT_SEL0
uart_rx__PRTDSI__OUT_SEL1 EQU CYREG_PRT0_OUT_SEL1
uart_rx__PRTDSI__SYNC_OUT EQU CYREG_PRT0_SYNC_OUT
uart_rx__PS EQU CYREG_PRT0_PS
uart_rx__SHIFT EQU 1
uart_rx__SLW EQU CYREG_PRT0_SLW

; isr_1
isr_1__INTC_CLR_EN_REG EQU CYREG_NVIC_CLRENA0
isr_1__INTC_CLR_PD_REG EQU CYREG_NVIC_CLRPEND0
isr_1__INTC_MASK EQU 0x01
isr_1__INTC_NUMBER EQU 0
isr_1__INTC_PRIOR_NUM EQU 7
isr_1__INTC_PRIOR_REG EQU CYREG_NVIC_PRI_0
isr_1__INTC_SET_EN_REG EQU CYREG_NVIC_SETENA0
isr_1__INTC_SET_PD_REG EQU CYREG_NVIC_SETPEND0

; Miscellaneous
; -- WARNING: define names containing LEOPARD or PANTHER are deprecated and will be removed in a future release
CYDEV_DEBUGGING_DPS_SWD_SWV EQU 6
CYDEV_CONFIG_UNUSED_IO_AllowButWarn EQU 0
CYDEV_CONFIGURATION_MODE_COMPRESSED EQU 0
CYDEV_CONFIG_FASTBOOT_ENABLED EQU 0
CYDEV_CHIP_REV_PANTHER_PRODUCTION EQU 1
CYDEV_CHIP_REVISION_5A_PRODUCTION EQU 1
CYDEV_CHIP_MEMBER_5A EQU 3
CYDEV_CHIP_FAMILY_PSOC5 EQU 3
CYDEV_CHIP_DIE_PANTHER EQU 3
CYDEV_CHIP_DIE_EXPECT EQU CYDEV_CHIP_DIE_PANTHER
BCLK__BUS_CLK__HZ EQU 24000000
BCLK__BUS_CLK__KHZ EQU 24000
BCLK__BUS_CLK__MHZ EQU 24
CYDEV_CHIP_DIE_ACTUAL EQU CYDEV_CHIP_DIE_EXPECT
CYDEV_CHIP_DIE_LEOPARD EQU 1
CYDEV_CHIP_DIE_PSOC4A EQU 2
CYDEV_CHIP_DIE_PSOC5LP EQU 4
CYDEV_CHIP_DIE_UNKNOWN EQU 0
CYDEV_CHIP_FAMILY_PSOC3 EQU 1
CYDEV_CHIP_FAMILY_PSOC4 EQU 2
CYDEV_CHIP_FAMILY_UNKNOWN EQU 0
CYDEV_CHIP_FAMILY_USED EQU CYDEV_CHIP_FAMILY_PSOC5
CYDEV_CHIP_JTAG_ID EQU 0x0E13C069
CYDEV_CHIP_MEMBER_3A EQU 1
CYDEV_CHIP_MEMBER_4A EQU 2
CYDEV_CHIP_MEMBER_5B EQU 4
CYDEV_CHIP_MEMBER_UNKNOWN EQU 0
CYDEV_CHIP_MEMBER_USED EQU CYDEV_CHIP_MEMBER_5A
CYDEV_CHIP_REVISION_3A_ES1 EQU 0
CYDEV_CHIP_REVISION_3A_ES2 EQU 1
CYDEV_CHIP_REVISION_3A_ES3 EQU 3
CYDEV_CHIP_REVISION_3A_PRODUCTION EQU 3
CYDEV_CHIP_REVISION_4A_ES0 EQU 17
CYDEV_CHIP_REVISION_4A_PRODUCTION EQU 17
CYDEV_CHIP_REVISION_5A_ES0 EQU 0
CYDEV_CHIP_REVISION_5A_ES1 EQU 1
CYDEV_CHIP_REVISION_5B_ES0 EQU 0
CYDEV_CHIP_REVISION_5B_PRODUCTION EQU 0
CYDEV_CHIP_REVISION_USED EQU CYDEV_CHIP_REVISION_5A_PRODUCTION
CYDEV_CHIP_REV_EXPECT EQU CYDEV_CHIP_REV_PANTHER_PRODUCTION
CYDEV_CHIP_REV_LEOPARD_ES1 EQU 0
CYDEV_CHIP_REV_LEOPARD_ES2 EQU 1
CYDEV_CHIP_REV_LEOPARD_ES3 EQU 3
CYDEV_CHIP_REV_LEOPARD_PRODUCTION EQU 3
CYDEV_CHIP_REV_PANTHER_ES0 EQU 0
CYDEV_CHIP_REV_PANTHER_ES1 EQU 1
CYDEV_CHIP_REV_PSOC4A_ES0 EQU 17
CYDEV_CHIP_REV_PSOC4A_PRODUCTION EQU 17
CYDEV_CHIP_REV_PSOC5LP_ES0 EQU 0
CYDEV_CHIP_REV_PSOC5LP_PRODUCTION EQU 0
CYDEV_CONFIGURATION_COMPRESSED EQU 1
CYDEV_CONFIGURATION_DMA EQU 0
CYDEV_CONFIGURATION_ECC EQU 1
CYDEV_CONFIGURATION_IMOENABLED EQU CYDEV_CONFIG_FASTBOOT_ENABLED
CYDEV_CONFIGURATION_MODE EQU CYDEV_CONFIGURATION_MODE_COMPRESSED
CYDEV_CONFIGURATION_MODE_DMA EQU 2
CYDEV_CONFIGURATION_MODE_UNCOMPRESSED EQU 1
CYDEV_CONFIG_UNUSED_IO EQU CYDEV_CONFIG_UNUSED_IO_AllowButWarn
CYDEV_CONFIG_UNUSED_IO_AllowWithInfo EQU 1
CYDEV_CONFIG_UNUSED_IO_Disallowed EQU 2
CYDEV_DATA_CACHE_ENABLED EQU 0
CYDEV_DEBUGGING_DPS EQU CYDEV_DEBUGGING_DPS_SWD_SWV
CYDEV_DEBUGGING_DPS_Disable EQU 3
CYDEV_DEBUGGING_ENABLE EQU 1
CYDEV_DEBUGGING_REQXRES EQU 1
CYDEV_DEBUGGING_XRES EQU 0
CYDEV_DEBUG_ENABLE_MASK EQU 0x01
CYDEV_DEBUG_ENABLE_REGISTER EQU CYREG_MLOGIC_DBG_DBE
CYDEV_DMA_CHANNELS_AVAILABLE EQU 24
CYDEV_ECC_ENABLE EQU 0
CYDEV_HEAP_SIZE EQU 0x1000
CYDEV_INSTRUCT_CACHE_ENABLED EQU 1
CYDEV_INTR_RISING EQU 0x0000000E
CYDEV_PROJ_TYPE EQU 0
CYDEV_PROJ_TYPE_BOOTLOADER EQU 1
CYDEV_PROJ_TYPE_LOADABLE EQU 2
CYDEV_PROJ_TYPE_MULTIAPPBOOTLOADER EQU 3
CYDEV_PROJ_TYPE_STANDARD EQU 0
CYDEV_PROTECTION_ENABLE EQU 0
CYDEV_STACK_SIZE EQU 0x4000
CYDEV_USE_BUNDLED_CMSIS EQU 1
CYDEV_VDDA_MV EQU 5000
CYDEV_VDDD_MV EQU 5000
CYDEV_VDDIO0_MV EQU 5000
CYDEV_VDDIO1_MV EQU 5000
CYDEV_VDDIO2_MV EQU 5000
CYDEV_VDDIO3_MV EQU 5000
CYDEV_VIO0 EQU 5
CYDEV_VIO0_MV EQU 5000
CYDEV_VIO1 EQU 5
CYDEV_VIO1_MV EQU 5000
CYDEV_VIO2 EQU 5
CYDEV_VIO2_MV EQU 5000
CYDEV_VIO3 EQU 5
CYDEV_VIO3_MV EQU 5000
DMA_CHANNELS_USED__MASK0 EQU 0x00000000
CYDEV_BOOTLOADER_ENABLE EQU 0
    ENDIF
    END