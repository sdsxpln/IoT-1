#ifndef INCLUDED_CYFITTER_H
#define INCLUDED_CYFITTER_H
#include "cydevice.h"
#include "cydevice_trm.h"

/* SCL_1 */
#define SCL_1__0__INTTYPE CYREG_PICU1_INTTYPE2
#define SCL_1__0__MASK 0x04u
#define SCL_1__0__PC CYREG_PRT1_PC2
#define SCL_1__0__PORT 1u
#define SCL_1__0__SHIFT 2
#define SCL_1__AG CYREG_PRT1_AG
#define SCL_1__AMUX CYREG_PRT1_AMUX
#define SCL_1__BIE CYREG_PRT1_BIE
#define SCL_1__BIT_MASK CYREG_PRT1_BIT_MASK
#define SCL_1__BYP CYREG_PRT1_BYP
#define SCL_1__CTL CYREG_PRT1_CTL
#define SCL_1__DM0 CYREG_PRT1_DM0
#define SCL_1__DM1 CYREG_PRT1_DM1
#define SCL_1__DM2 CYREG_PRT1_DM2
#define SCL_1__DR CYREG_PRT1_DR
#define SCL_1__INP_DIS CYREG_PRT1_INP_DIS
#define SCL_1__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU1_BASE
#define SCL_1__LCD_COM_SEG CYREG_PRT1_LCD_COM_SEG
#define SCL_1__LCD_EN CYREG_PRT1_LCD_EN
#define SCL_1__MASK 0x04u
#define SCL_1__PORT 1u
#define SCL_1__PRT CYREG_PRT1_PRT
#define SCL_1__PRTDSI__CAPS_SEL CYREG_PRT1_CAPS_SEL
#define SCL_1__PRTDSI__DBL_SYNC_IN CYREG_PRT1_DBL_SYNC_IN
#define SCL_1__PRTDSI__OE_SEL0 CYREG_PRT1_OE_SEL0
#define SCL_1__PRTDSI__OE_SEL1 CYREG_PRT1_OE_SEL1
#define SCL_1__PRTDSI__OUT_SEL0 CYREG_PRT1_OUT_SEL0
#define SCL_1__PRTDSI__OUT_SEL1 CYREG_PRT1_OUT_SEL1
#define SCL_1__PRTDSI__SYNC_OUT CYREG_PRT1_SYNC_OUT
#define SCL_1__PS CYREG_PRT1_PS
#define SCL_1__SHIFT 2
#define SCL_1__SLW CYREG_PRT1_SLW

/* SDA_1 */
#define SDA_1__0__INTTYPE CYREG_PICU5_INTTYPE3
#define SDA_1__0__MASK 0x08u
#define SDA_1__0__PC CYREG_PRT5_PC3
#define SDA_1__0__PORT 5u
#define SDA_1__0__SHIFT 3
#define SDA_1__AG CYREG_PRT5_AG
#define SDA_1__AMUX CYREG_PRT5_AMUX
#define SDA_1__BIE CYREG_PRT5_BIE
#define SDA_1__BIT_MASK CYREG_PRT5_BIT_MASK
#define SDA_1__BYP CYREG_PRT5_BYP
#define SDA_1__CTL CYREG_PRT5_CTL
#define SDA_1__DM0 CYREG_PRT5_DM0
#define SDA_1__DM1 CYREG_PRT5_DM1
#define SDA_1__DM2 CYREG_PRT5_DM2
#define SDA_1__DR CYREG_PRT5_DR
#define SDA_1__INP_DIS CYREG_PRT5_INP_DIS
#define SDA_1__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU5_BASE
#define SDA_1__LCD_COM_SEG CYREG_PRT5_LCD_COM_SEG
#define SDA_1__LCD_EN CYREG_PRT5_LCD_EN
#define SDA_1__MASK 0x08u
#define SDA_1__PORT 5u
#define SDA_1__PRT CYREG_PRT5_PRT
#define SDA_1__PRTDSI__CAPS_SEL CYREG_PRT5_CAPS_SEL
#define SDA_1__PRTDSI__DBL_SYNC_IN CYREG_PRT5_DBL_SYNC_IN
#define SDA_1__PRTDSI__OE_SEL0 CYREG_PRT5_OE_SEL0
#define SDA_1__PRTDSI__OE_SEL1 CYREG_PRT5_OE_SEL1
#define SDA_1__PRTDSI__OUT_SEL0 CYREG_PRT5_OUT_SEL0
#define SDA_1__PRTDSI__OUT_SEL1 CYREG_PRT5_OUT_SEL1
#define SDA_1__PRTDSI__SYNC_OUT CYREG_PRT5_SYNC_OUT
#define SDA_1__PS CYREG_PRT5_PS
#define SDA_1__SHIFT 3
#define SDA_1__SLW CYREG_PRT5_SLW

/* Sensirion_I2C_bI2C_UDB */
#define Sensirion_I2C_bI2C_UDB_Master_ClkGen_u0__16BIT_A0_REG CYREG_B1_UDB08_09_A0
#define Sensirion_I2C_bI2C_UDB_Master_ClkGen_u0__16BIT_A1_REG CYREG_B1_UDB08_09_A1
#define Sensirion_I2C_bI2C_UDB_Master_ClkGen_u0__16BIT_D0_REG CYREG_B1_UDB08_09_D0
#define Sensirion_I2C_bI2C_UDB_Master_ClkGen_u0__16BIT_D1_REG CYREG_B1_UDB08_09_D1
#define Sensirion_I2C_bI2C_UDB_Master_ClkGen_u0__16BIT_DP_AUX_CTL_REG CYREG_B1_UDB08_09_ACTL
#define Sensirion_I2C_bI2C_UDB_Master_ClkGen_u0__16BIT_F0_REG CYREG_B1_UDB08_09_F0
#define Sensirion_I2C_bI2C_UDB_Master_ClkGen_u0__16BIT_F1_REG CYREG_B1_UDB08_09_F1
#define Sensirion_I2C_bI2C_UDB_Master_ClkGen_u0__A0_A1_REG CYREG_B1_UDB08_A0_A1
#define Sensirion_I2C_bI2C_UDB_Master_ClkGen_u0__A0_REG CYREG_B1_UDB08_A0
#define Sensirion_I2C_bI2C_UDB_Master_ClkGen_u0__A1_REG CYREG_B1_UDB08_A1
#define Sensirion_I2C_bI2C_UDB_Master_ClkGen_u0__D0_D1_REG CYREG_B1_UDB08_D0_D1
#define Sensirion_I2C_bI2C_UDB_Master_ClkGen_u0__D0_REG CYREG_B1_UDB08_D0
#define Sensirion_I2C_bI2C_UDB_Master_ClkGen_u0__D1_REG CYREG_B1_UDB08_D1
#define Sensirion_I2C_bI2C_UDB_Master_ClkGen_u0__DP_AUX_CTL_REG CYREG_B1_UDB08_ACTL
#define Sensirion_I2C_bI2C_UDB_Master_ClkGen_u0__F0_F1_REG CYREG_B1_UDB08_F0_F1
#define Sensirion_I2C_bI2C_UDB_Master_ClkGen_u0__F0_REG CYREG_B1_UDB08_F0
#define Sensirion_I2C_bI2C_UDB_Master_ClkGen_u0__F1_REG CYREG_B1_UDB08_F1
#define Sensirion_I2C_bI2C_UDB_Shifter_u0__16BIT_A0_REG CYREG_B0_UDB09_10_A0
#define Sensirion_I2C_bI2C_UDB_Shifter_u0__16BIT_A1_REG CYREG_B0_UDB09_10_A1
#define Sensirion_I2C_bI2C_UDB_Shifter_u0__16BIT_D0_REG CYREG_B0_UDB09_10_D0
#define Sensirion_I2C_bI2C_UDB_Shifter_u0__16BIT_D1_REG CYREG_B0_UDB09_10_D1
#define Sensirion_I2C_bI2C_UDB_Shifter_u0__16BIT_DP_AUX_CTL_REG CYREG_B0_UDB09_10_ACTL
#define Sensirion_I2C_bI2C_UDB_Shifter_u0__16BIT_F0_REG CYREG_B0_UDB09_10_F0
#define Sensirion_I2C_bI2C_UDB_Shifter_u0__16BIT_F1_REG CYREG_B0_UDB09_10_F1
#define Sensirion_I2C_bI2C_UDB_Shifter_u0__A0_A1_REG CYREG_B0_UDB09_A0_A1
#define Sensirion_I2C_bI2C_UDB_Shifter_u0__A0_REG CYREG_B0_UDB09_A0
#define Sensirion_I2C_bI2C_UDB_Shifter_u0__A1_REG CYREG_B0_UDB09_A1
#define Sensirion_I2C_bI2C_UDB_Shifter_u0__D0_D1_REG CYREG_B0_UDB09_D0_D1
#define Sensirion_I2C_bI2C_UDB_Shifter_u0__D0_REG CYREG_B0_UDB09_D0
#define Sensirion_I2C_bI2C_UDB_Shifter_u0__D1_REG CYREG_B0_UDB09_D1
#define Sensirion_I2C_bI2C_UDB_Shifter_u0__DP_AUX_CTL_REG CYREG_B0_UDB09_ACTL
#define Sensirion_I2C_bI2C_UDB_Shifter_u0__F0_F1_REG CYREG_B0_UDB09_F0_F1
#define Sensirion_I2C_bI2C_UDB_Shifter_u0__F0_REG CYREG_B0_UDB09_F0
#define Sensirion_I2C_bI2C_UDB_Shifter_u0__F1_REG CYREG_B0_UDB09_F1
#define Sensirion_I2C_bI2C_UDB_Shifter_u0__MSK_DP_AUX_CTL_REG CYREG_B0_UDB09_MSK_ACTL
#define Sensirion_I2C_bI2C_UDB_Shifter_u0__PER_DP_AUX_CTL_REG CYREG_B0_UDB09_MSK_ACTL
#define Sensirion_I2C_bI2C_UDB_StsReg__0__MASK 0x01u
#define Sensirion_I2C_bI2C_UDB_StsReg__0__POS 0
#define Sensirion_I2C_bI2C_UDB_StsReg__1__MASK 0x02u
#define Sensirion_I2C_bI2C_UDB_StsReg__1__POS 1
#define Sensirion_I2C_bI2C_UDB_StsReg__16BIT_STATUS_AUX_CTL_REG CYREG_B0_UDB11_12_ACTL
#define Sensirion_I2C_bI2C_UDB_StsReg__16BIT_STATUS_REG CYREG_B0_UDB11_12_ST
#define Sensirion_I2C_bI2C_UDB_StsReg__2__MASK 0x04u
#define Sensirion_I2C_bI2C_UDB_StsReg__2__POS 2
#define Sensirion_I2C_bI2C_UDB_StsReg__3__MASK 0x08u
#define Sensirion_I2C_bI2C_UDB_StsReg__3__POS 3
#define Sensirion_I2C_bI2C_UDB_StsReg__4__MASK 0x10u
#define Sensirion_I2C_bI2C_UDB_StsReg__4__POS 4
#define Sensirion_I2C_bI2C_UDB_StsReg__5__MASK 0x20u
#define Sensirion_I2C_bI2C_UDB_StsReg__5__POS 5
#define Sensirion_I2C_bI2C_UDB_StsReg__MASK 0x3Fu
#define Sensirion_I2C_bI2C_UDB_StsReg__MASK_REG CYREG_B0_UDB11_MSK
#define Sensirion_I2C_bI2C_UDB_StsReg__STATUS_AUX_CTL_REG CYREG_B0_UDB11_ACTL
#define Sensirion_I2C_bI2C_UDB_StsReg__STATUS_REG CYREG_B0_UDB11_ST
#define Sensirion_I2C_bI2C_UDB_SyncCtl_CtrlReg__1__MASK 0x02u
#define Sensirion_I2C_bI2C_UDB_SyncCtl_CtrlReg__1__POS 1
#define Sensirion_I2C_bI2C_UDB_SyncCtl_CtrlReg__16BIT_CONTROL_AUX_CTL_REG CYREG_B0_UDB09_10_ACTL
#define Sensirion_I2C_bI2C_UDB_SyncCtl_CtrlReg__16BIT_CONTROL_CONTROL_REG CYREG_B0_UDB09_10_CTL
#define Sensirion_I2C_bI2C_UDB_SyncCtl_CtrlReg__16BIT_CONTROL_COUNT_REG CYREG_B0_UDB09_10_CTL
#define Sensirion_I2C_bI2C_UDB_SyncCtl_CtrlReg__16BIT_COUNT_CONTROL_REG CYREG_B0_UDB09_10_CTL
#define Sensirion_I2C_bI2C_UDB_SyncCtl_CtrlReg__16BIT_COUNT_COUNT_REG CYREG_B0_UDB09_10_CTL
#define Sensirion_I2C_bI2C_UDB_SyncCtl_CtrlReg__16BIT_MASK_MASK_REG CYREG_B0_UDB09_10_MSK
#define Sensirion_I2C_bI2C_UDB_SyncCtl_CtrlReg__16BIT_MASK_PERIOD_REG CYREG_B0_UDB09_10_MSK
#define Sensirion_I2C_bI2C_UDB_SyncCtl_CtrlReg__16BIT_PERIOD_MASK_REG CYREG_B0_UDB09_10_MSK
#define Sensirion_I2C_bI2C_UDB_SyncCtl_CtrlReg__16BIT_PERIOD_PERIOD_REG CYREG_B0_UDB09_10_MSK
#define Sensirion_I2C_bI2C_UDB_SyncCtl_CtrlReg__2__MASK 0x04u
#define Sensirion_I2C_bI2C_UDB_SyncCtl_CtrlReg__2__POS 2
#define Sensirion_I2C_bI2C_UDB_SyncCtl_CtrlReg__4__MASK 0x10u
#define Sensirion_I2C_bI2C_UDB_SyncCtl_CtrlReg__4__POS 4
#define Sensirion_I2C_bI2C_UDB_SyncCtl_CtrlReg__5__MASK 0x20u
#define Sensirion_I2C_bI2C_UDB_SyncCtl_CtrlReg__5__POS 5
#define Sensirion_I2C_bI2C_UDB_SyncCtl_CtrlReg__6__MASK 0x40u
#define Sensirion_I2C_bI2C_UDB_SyncCtl_CtrlReg__6__POS 6
#define Sensirion_I2C_bI2C_UDB_SyncCtl_CtrlReg__7__MASK 0x80u
#define Sensirion_I2C_bI2C_UDB_SyncCtl_CtrlReg__7__POS 7
#define Sensirion_I2C_bI2C_UDB_SyncCtl_CtrlReg__CONTROL_AUX_CTL_REG CYREG_B0_UDB09_ACTL
#define Sensirion_I2C_bI2C_UDB_SyncCtl_CtrlReg__CONTROL_REG CYREG_B0_UDB09_CTL
#define Sensirion_I2C_bI2C_UDB_SyncCtl_CtrlReg__CONTROL_ST_REG CYREG_B0_UDB09_ST_CTL
#define Sensirion_I2C_bI2C_UDB_SyncCtl_CtrlReg__COUNT_REG CYREG_B0_UDB09_CTL
#define Sensirion_I2C_bI2C_UDB_SyncCtl_CtrlReg__COUNT_ST_REG CYREG_B0_UDB09_ST_CTL
#define Sensirion_I2C_bI2C_UDB_SyncCtl_CtrlReg__MASK 0xF6u
#define Sensirion_I2C_bI2C_UDB_SyncCtl_CtrlReg__MASK_CTL_AUX_CTL_REG CYREG_B0_UDB09_MSK_ACTL
#define Sensirion_I2C_bI2C_UDB_SyncCtl_CtrlReg__PER_CTL_AUX_CTL_REG CYREG_B0_UDB09_MSK_ACTL
#define Sensirion_I2C_bI2C_UDB_SyncCtl_CtrlReg__PERIOD_REG CYREG_B0_UDB09_MSK

/* Sensirion_I2C_I2C_IRQ */
#define Sensirion_I2C_I2C_IRQ__INTC_CLR_EN_REG CYREG_NVIC_CLRENA0
#define Sensirion_I2C_I2C_IRQ__INTC_CLR_PD_REG CYREG_NVIC_CLRPEND0
#define Sensirion_I2C_I2C_IRQ__INTC_MASK 0x01u
#define Sensirion_I2C_I2C_IRQ__INTC_NUMBER 0u
#define Sensirion_I2C_I2C_IRQ__INTC_PRIOR_NUM 7u
#define Sensirion_I2C_I2C_IRQ__INTC_PRIOR_REG CYREG_NVIC_PRI_0
#define Sensirion_I2C_I2C_IRQ__INTC_SET_EN_REG CYREG_NVIC_SETENA0
#define Sensirion_I2C_I2C_IRQ__INTC_SET_PD_REG CYREG_NVIC_SETPEND0

/* Sensirion_I2C_IntClock */
#define Sensirion_I2C_IntClock__CFG0 CYREG_CLKDIST_DCFG0_CFG0
#define Sensirion_I2C_IntClock__CFG1 CYREG_CLKDIST_DCFG0_CFG1
#define Sensirion_I2C_IntClock__CFG2 CYREG_CLKDIST_DCFG0_CFG2
#define Sensirion_I2C_IntClock__CFG2_SRC_SEL_MASK 0x07u
#define Sensirion_I2C_IntClock__INDEX 0x00u
#define Sensirion_I2C_IntClock__PM_ACT_CFG CYREG_PM_ACT_CFG2
#define Sensirion_I2C_IntClock__PM_ACT_MSK 0x01u
#define Sensirion_I2C_IntClock__PM_STBY_CFG CYREG_PM_STBY_CFG2
#define Sensirion_I2C_IntClock__PM_STBY_MSK 0x01u

/* Sensirion_Power */
#define Sensirion_Power__0__INTTYPE CYREG_PICU5_INTTYPE2
#define Sensirion_Power__0__MASK 0x04u
#define Sensirion_Power__0__PC CYREG_PRT5_PC2
#define Sensirion_Power__0__PORT 5u
#define Sensirion_Power__0__SHIFT 2
#define Sensirion_Power__AG CYREG_PRT5_AG
#define Sensirion_Power__AMUX CYREG_PRT5_AMUX
#define Sensirion_Power__BIE CYREG_PRT5_BIE
#define Sensirion_Power__BIT_MASK CYREG_PRT5_BIT_MASK
#define Sensirion_Power__BYP CYREG_PRT5_BYP
#define Sensirion_Power__CTL CYREG_PRT5_CTL
#define Sensirion_Power__DM0 CYREG_PRT5_DM0
#define Sensirion_Power__DM1 CYREG_PRT5_DM1
#define Sensirion_Power__DM2 CYREG_PRT5_DM2
#define Sensirion_Power__DR CYREG_PRT5_DR
#define Sensirion_Power__INP_DIS CYREG_PRT5_INP_DIS
#define Sensirion_Power__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU5_BASE
#define Sensirion_Power__LCD_COM_SEG CYREG_PRT5_LCD_COM_SEG
#define Sensirion_Power__LCD_EN CYREG_PRT5_LCD_EN
#define Sensirion_Power__MASK 0x04u
#define Sensirion_Power__PORT 5u
#define Sensirion_Power__PRT CYREG_PRT5_PRT
#define Sensirion_Power__PRTDSI__CAPS_SEL CYREG_PRT5_CAPS_SEL
#define Sensirion_Power__PRTDSI__DBL_SYNC_IN CYREG_PRT5_DBL_SYNC_IN
#define Sensirion_Power__PRTDSI__OE_SEL0 CYREG_PRT5_OE_SEL0
#define Sensirion_Power__PRTDSI__OE_SEL1 CYREG_PRT5_OE_SEL1
#define Sensirion_Power__PRTDSI__OUT_SEL0 CYREG_PRT5_OUT_SEL0
#define Sensirion_Power__PRTDSI__OUT_SEL1 CYREG_PRT5_OUT_SEL1
#define Sensirion_Power__PRTDSI__SYNC_OUT CYREG_PRT5_SYNC_OUT
#define Sensirion_Power__PS CYREG_PRT5_PS
#define Sensirion_Power__SHIFT 2
#define Sensirion_Power__SLW CYREG_PRT5_SLW

/* Miscellaneous */
#define BCLK__BUS_CLK__HZ 24000000U
#define BCLK__BUS_CLK__KHZ 24000U
#define BCLK__BUS_CLK__MHZ 24U
#define CY_PROJECT_NAME "Sensirion_TempRH"
#define CY_VERSION "PSoC Creator  3.3 SP1"
#define CYDEV_CHIP_DIE_LEOPARD 1u
#define CYDEV_CHIP_DIE_PANTHER 18u
#define CYDEV_CHIP_DIE_PSOC4A 10u
#define CYDEV_CHIP_DIE_PSOC5LP 17u
#define CYDEV_CHIP_DIE_TMA4 2u
#define CYDEV_CHIP_DIE_UNKNOWN 0u
#define CYDEV_CHIP_FAMILY_PSOC3 1u
#define CYDEV_CHIP_FAMILY_PSOC4 2u
#define CYDEV_CHIP_FAMILY_PSOC5 3u
#define CYDEV_CHIP_FAMILY_UNKNOWN 0u
#define CYDEV_CHIP_FAMILY_USED CYDEV_CHIP_FAMILY_PSOC5
#define CYDEV_CHIP_JTAG_ID 0x2E123069u
#define CYDEV_CHIP_MEMBER_3A 1u
#define CYDEV_CHIP_MEMBER_4A 10u
#define CYDEV_CHIP_MEMBER_4C 15u
#define CYDEV_CHIP_MEMBER_4D 6u
#define CYDEV_CHIP_MEMBER_4E 4u
#define CYDEV_CHIP_MEMBER_4F 11u
#define CYDEV_CHIP_MEMBER_4G 2u
#define CYDEV_CHIP_MEMBER_4H 9u
#define CYDEV_CHIP_MEMBER_4I 14u
#define CYDEV_CHIP_MEMBER_4J 7u
#define CYDEV_CHIP_MEMBER_4K 8u
#define CYDEV_CHIP_MEMBER_4L 13u
#define CYDEV_CHIP_MEMBER_4M 12u
#define CYDEV_CHIP_MEMBER_4N 5u
#define CYDEV_CHIP_MEMBER_4U 3u
#define CYDEV_CHIP_MEMBER_5A 17u
#define CYDEV_CHIP_MEMBER_5B 16u
#define CYDEV_CHIP_MEMBER_UNKNOWN 0u
#define CYDEV_CHIP_MEMBER_USED CYDEV_CHIP_MEMBER_5B
#define CYDEV_CHIP_DIE_EXPECT CYDEV_CHIP_MEMBER_USED
#define CYDEV_CHIP_DIE_ACTUAL CYDEV_CHIP_DIE_EXPECT
#define CYDEV_CHIP_REV_LEOPARD_ES1 0u
#define CYDEV_CHIP_REV_LEOPARD_ES2 1u
#define CYDEV_CHIP_REV_LEOPARD_ES3 3u
#define CYDEV_CHIP_REV_LEOPARD_PRODUCTION 3u
#define CYDEV_CHIP_REV_PANTHER_ES0 0u
#define CYDEV_CHIP_REV_PANTHER_ES1 1u
#define CYDEV_CHIP_REV_PANTHER_PRODUCTION 1u
#define CYDEV_CHIP_REV_PSOC4A_ES0 17u
#define CYDEV_CHIP_REV_PSOC4A_PRODUCTION 17u
#define CYDEV_CHIP_REV_PSOC5LP_ES0 0u
#define CYDEV_CHIP_REV_PSOC5LP_PRODUCTION 0u
#define CYDEV_CHIP_REV_TMA4_ES 17u
#define CYDEV_CHIP_REV_TMA4_ES2 33u
#define CYDEV_CHIP_REV_TMA4_PRODUCTION 17u
#define CYDEV_CHIP_REVISION_3A_ES1 0u
#define CYDEV_CHIP_REVISION_3A_ES2 1u
#define CYDEV_CHIP_REVISION_3A_ES3 3u
#define CYDEV_CHIP_REVISION_3A_PRODUCTION 3u
#define CYDEV_CHIP_REVISION_4A_ES0 17u
#define CYDEV_CHIP_REVISION_4A_PRODUCTION 17u
#define CYDEV_CHIP_REVISION_4C_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4D_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4E_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4F_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4F_PRODUCTION_256DMA 0u
#define CYDEV_CHIP_REVISION_4F_PRODUCTION_256K 0u
#define CYDEV_CHIP_REVISION_4G_ES 17u
#define CYDEV_CHIP_REVISION_4G_ES2 33u
#define CYDEV_CHIP_REVISION_4G_PRODUCTION 17u
#define CYDEV_CHIP_REVISION_4H_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4I_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4J_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4K_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4L_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4M_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4N_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4U_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_5A_ES0 0u
#define CYDEV_CHIP_REVISION_5A_ES1 1u
#define CYDEV_CHIP_REVISION_5A_PRODUCTION 1u
#define CYDEV_CHIP_REVISION_5B_ES0 0u
#define CYDEV_CHIP_REVISION_5B_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_USED CYDEV_CHIP_REVISION_5B_PRODUCTION
#define CYDEV_CHIP_REV_EXPECT CYDEV_CHIP_REVISION_USED
#define CYDEV_CONFIG_FASTBOOT_ENABLED 1
#define CYDEV_CONFIG_UNUSED_IO_AllowButWarn 0
#define CYDEV_CONFIG_UNUSED_IO CYDEV_CONFIG_UNUSED_IO_AllowButWarn
#define CYDEV_CONFIG_UNUSED_IO_AllowWithInfo 1
#define CYDEV_CONFIG_UNUSED_IO_Disallowed 2
#define CYDEV_CONFIGURATION_COMPRESSED 1
#define CYDEV_CONFIGURATION_DMA 0
#define CYDEV_CONFIGURATION_ECC 1
#define CYDEV_CONFIGURATION_IMOENABLED CYDEV_CONFIG_FASTBOOT_ENABLED
#define CYDEV_CONFIGURATION_MODE_COMPRESSED 0
#define CYDEV_CONFIGURATION_MODE CYDEV_CONFIGURATION_MODE_COMPRESSED
#define CYDEV_CONFIGURATION_MODE_DMA 2
#define CYDEV_CONFIGURATION_MODE_UNCOMPRESSED 1
#define CYDEV_DEBUG_ENABLE_MASK 0x20u
#define CYDEV_DEBUG_ENABLE_REGISTER CYREG_MLOGIC_DEBUG
#define CYDEV_DEBUGGING_DPS_Disable 3
#define CYDEV_DEBUGGING_DPS_JTAG_4 1
#define CYDEV_DEBUGGING_DPS_JTAG_5 0
#define CYDEV_DEBUGGING_DPS_SWD 2
#define CYDEV_DEBUGGING_DPS_SWD_SWV 6
#define CYDEV_DEBUGGING_DPS CYDEV_DEBUGGING_DPS_SWD_SWV
#define CYDEV_DEBUGGING_ENABLE 1
#define CYDEV_DEBUGGING_XRES 0
#define CYDEV_DMA_CHANNELS_AVAILABLE 24u
#define CYDEV_ECC_ENABLE 0
#define CYDEV_HEAP_SIZE 0x80
#define CYDEV_INSTRUCT_CACHE_ENABLED 1
#define CYDEV_INTR_RISING 0x00000001u
#define CYDEV_IS_EXPORTING_CODE 0
#define CYDEV_IS_IMPORTING_CODE 0
#define CYDEV_PROJ_TYPE 0
#define CYDEV_PROJ_TYPE_BOOTLOADER 1
#define CYDEV_PROJ_TYPE_LAUNCHER 5
#define CYDEV_PROJ_TYPE_LOADABLE 2
#define CYDEV_PROJ_TYPE_LOADABLEANDBOOTLOADER 4
#define CYDEV_PROJ_TYPE_MULTIAPPBOOTLOADER 3
#define CYDEV_PROJ_TYPE_STANDARD 0
#define CYDEV_PROTECTION_ENABLE 0
#define CYDEV_STACK_SIZE 0x0800
#define CYDEV_USE_BUNDLED_CMSIS 1
#define CYDEV_VARIABLE_VDDA 0
#define CYDEV_VDDA 5.0
#define CYDEV_VDDA_MV 5000
#define CYDEV_VDDD 5.0
#define CYDEV_VDDD_MV 5000
#define CYDEV_VDDIO0 5.0
#define CYDEV_VDDIO0_MV 5000
#define CYDEV_VDDIO1 5.0
#define CYDEV_VDDIO1_MV 5000
#define CYDEV_VDDIO2 5.0
#define CYDEV_VDDIO2_MV 5000
#define CYDEV_VDDIO3 5.0
#define CYDEV_VDDIO3_MV 5000
#define CYDEV_VIO0 5.0
#define CYDEV_VIO0_MV 5000
#define CYDEV_VIO1 5.0
#define CYDEV_VIO1_MV 5000
#define CYDEV_VIO2 5.0
#define CYDEV_VIO2_MV 5000
#define CYDEV_VIO3 5.0
#define CYDEV_VIO3_MV 5000
#define CYIPBLOCK_ARM_CM3_VERSION 0
#define CYIPBLOCK_P3_ANAIF_VERSION 0
#define CYIPBLOCK_P3_CAN_VERSION 0
#define CYIPBLOCK_P3_CAPSENSE_VERSION 0
#define CYIPBLOCK_P3_COMP_VERSION 0
#define CYIPBLOCK_P3_DECIMATOR_VERSION 0
#define CYIPBLOCK_P3_DFB_VERSION 0
#define CYIPBLOCK_P3_DMA_VERSION 0
#define CYIPBLOCK_P3_DRQ_VERSION 0
#define CYIPBLOCK_P3_DSM_VERSION 0
#define CYIPBLOCK_P3_EMIF_VERSION 0
#define CYIPBLOCK_P3_I2C_VERSION 0
#define CYIPBLOCK_P3_LCD_VERSION 0
#define CYIPBLOCK_P3_LPF_VERSION 0
#define CYIPBLOCK_P3_OPAMP_VERSION 0
#define CYIPBLOCK_P3_PM_VERSION 0
#define CYIPBLOCK_P3_SCCT_VERSION 0
#define CYIPBLOCK_P3_TIMER_VERSION 0
#define CYIPBLOCK_P3_USB_VERSION 0
#define CYIPBLOCK_P3_VIDAC_VERSION 0
#define CYIPBLOCK_P3_VREF_VERSION 0
#define CYIPBLOCK_S8_GPIO_VERSION 0
#define CYIPBLOCK_S8_IRQ_VERSION 0
#define CYIPBLOCK_S8_SAR_VERSION 0
#define CYIPBLOCK_S8_SIO_VERSION 0
#define CYIPBLOCK_S8_UDB_VERSION 0
#define DMA_CHANNELS_USED__MASK0 0x00000000u
#define CYDEV_BOOTLOADER_ENABLE 0

#endif /* INCLUDED_CYFITTER_H */
