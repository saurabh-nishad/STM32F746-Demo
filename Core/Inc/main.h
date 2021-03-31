/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f7xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define T_R_COMB_UC_Pin GPIO_PIN_3
#define T_R_COMB_UC_GPIO_Port GPIOE
#define QSPI_D2_Pin GPIO_PIN_2
#define QSPI_D2_GPIO_Port GPIOE
#define FMC_NBL1_Pin GPIO_PIN_1
#define FMC_NBL1_GPIO_Port GPIOE
#define FMC_NBL0_Pin GPIO_PIN_0
#define FMC_NBL0_GPIO_Port GPIOE
#define ADC_I2C_SCL_Pin GPIO_PIN_8
#define ADC_I2C_SCL_GPIO_Port GPIOB
#define S_2_UC_Pin GPIO_PIN_5
#define S_2_UC_GPIO_Port GPIOB
#define TRST_Pin GPIO_PIN_4
#define TRST_GPIO_Port GPIOB
#define SWO_Pin GPIO_PIN_3
#define SWO_GPIO_Port GPIOB
#define GPIO_3_Pin GPIO_PIN_7
#define GPIO_3_GPIO_Port GPIOD
#define uSD_CLK_Pin GPIO_PIN_12
#define uSD_CLK_GPIO_Port GPIOC
#define TDI_Pin GPIO_PIN_15
#define TDI_GPIO_Port GPIOA
#define SWCLK_Pin GPIO_PIN_14
#define SWCLK_GPIO_Port GPIOA
#define SWDIO_Pin GPIO_PIN_13
#define SWDIO_GPIO_Port GPIOA
#define ADC_I2C_SDA_Pin GPIO_PIN_9
#define ADC_I2C_SDA_GPIO_Port GPIOB
#define VCP_RX_Pin GPIO_PIN_7
#define VCP_RX_GPIO_Port GPIOB
#define QSPI_NCS_Pin GPIO_PIN_6
#define QSPI_NCS_GPIO_Port GPIOB
#define BIAS__UC_3_Pin GPIO_PIN_13
#define BIAS__UC_3_GPIO_Port GPIOJ
#define BIAS__UC_2_Pin GPIO_PIN_12
#define BIAS__UC_2_GPIO_Port GPIOJ
#define UART_RS232_EX_RX_Pin GPIO_PIN_6
#define UART_RS232_EX_RX_GPIO_Port GPIOD
#define FMC_D2_Pin GPIO_PIN_0
#define FMC_D2_GPIO_Port GPIOD
#define uSD_D3_Pin GPIO_PIN_11
#define uSD_D3_GPIO_Port GPIOC
#define uSD_D2_Pin GPIO_PIN_10
#define uSD_D2_GPIO_Port GPIOC
#define EOC_ADC_Pin GPIO_PIN_12
#define EOC_ADC_GPIO_Port GPIOA
#define ATTN_UC_D5_Pin GPIO_PIN_7
#define ATTN_UC_D5_GPIO_Port GPIOK
#define ATTN_UC_D4_Pin GPIO_PIN_6
#define ATTN_UC_D4_GPIO_Port GPIOK
#define ATTN_UC_D3_Pin GPIO_PIN_5
#define ATTN_UC_D3_GPIO_Port GPIOK
#define BIAS__UC_4_Pin GPIO_PIN_14
#define BIAS__UC_4_GPIO_Port GPIOJ
#define UART_RS232_EX_TX_Pin GPIO_PIN_5
#define UART_RS232_EX_TX_GPIO_Port GPIOD
#define TH_SW_UC_4_Pin GPIO_PIN_3
#define TH_SW_UC_4_GPIO_Port GPIOD
#define FMC_D3_Pin GPIO_PIN_1
#define FMC_D3_GPIO_Port GPIOD
#define VSWR_FLT_Pin GPIO_PIN_11
#define VSWR_FLT_GPIO_Port GPIOA
#define uSD_Detect_Pin GPIO_PIN_13
#define uSD_Detect_GPIO_Port GPIOC
#define ATTN_UC_D2_Pin GPIO_PIN_4
#define ATTN_UC_D2_GPIO_Port GPIOK
#define ATTN_UC_D1_Pin GPIO_PIN_3
#define ATTN_UC_D1_GPIO_Port GPIOK
#define BIAS__UC_5_Pin GPIO_PIN_15
#define BIAS__UC_5_GPIO_Port GPIOJ
#define LED2_C_UC_Pin GPIO_PIN_4
#define LED2_C_UC_GPIO_Port GPIOD
#define uSD_CMD_Pin GPIO_PIN_2
#define uSD_CMD_GPIO_Port GPIOD
#define ALC_C4_Pin GPIO_PIN_10
#define ALC_C4_GPIO_Port GPIOA
#define VCP_TX_Pin GPIO_PIN_9
#define VCP_TX_GPIO_Port GPIOA
#define RF_SW_ON_UC_Pin GPIO_PIN_1
#define RF_SW_ON_UC_GPIO_Port GPIOK
#define ATTN_UC_D0_Pin GPIO_PIN_2
#define ATTN_UC_D0_GPIO_Port GPIOK
#define uSD_D1_Pin GPIO_PIN_9
#define uSD_D1_GPIO_Port GPIOC
#define ALC_C3_Pin GPIO_PIN_8
#define ALC_C3_GPIO_Port GPIOA
#define OSC_25M_Pin GPIO_PIN_0
#define OSC_25M_GPIO_Port GPIOH
#define BIAS__UC_1_Pin GPIO_PIN_11
#define BIAS__UC_1_GPIO_Port GPIOJ
#define TX_RELAY_ON_UC_Pin GPIO_PIN_0
#define TX_RELAY_ON_UC_GPIO_Port GPIOK
#define uSD_D0_Pin GPIO_PIN_8
#define uSD_D0_GPIO_Port GPIOC
#define UART_RS485_LRU_RX_Pin GPIO_PIN_7
#define UART_RS485_LRU_RX_GPIO_Port GPIOC
#define FIL_SEL_UC_3_Pin GPIO_PIN_8
#define FIL_SEL_UC_3_GPIO_Port GPIOJ
#define FIL_SEL_UC_1_Pin GPIO_PIN_10
#define FIL_SEL_UC_1_GPIO_Port GPIOJ
#define UART_RS485_LRU_TX_Pin GPIO_PIN_6
#define UART_RS485_LRU_TX_GPIO_Port GPIOC
#define FIL_SEL_UC_4_Pin GPIO_PIN_7
#define FIL_SEL_UC_4_GPIO_Port GPIOJ
#define FIL_SEL_UC_2_Pin GPIO_PIN_9
#define FIL_SEL_UC_2_GPIO_Port GPIOJ
#define FIL_SEL_UC_5_Pin GPIO_PIN_6
#define FIL_SEL_UC_5_GPIO_Port GPIOJ
#define FMC_D1_Pin GPIO_PIN_15
#define FMC_D1_GPIO_Port GPIOD
#define EX_CTL_Pin GPIO_PIN_13
#define EX_CTL_GPIO_Port GPIOB
#define FMC_D15_Pin GPIO_PIN_10
#define FMC_D15_GPIO_Port GPIOD
#define FMC_SDCKE0_Pin GPIO_PIN_3
#define FMC_SDCKE0_GPIO_Port GPIOC
#define FMC_D0_Pin GPIO_PIN_14
#define FMC_D0_GPIO_Port GPIOD
#define LRU_CTL_Pin GPIO_PIN_12
#define LRU_CTL_GPIO_Port GPIOB
#define FMC_D14_Pin GPIO_PIN_9
#define FMC_D14_GPIO_Port GPIOD
#define FMC_D13_Pin GPIO_PIN_8
#define FMC_D13_GPIO_Port GPIOD
#define CS_BPA1_2_AN_Pin GPIO_PIN_0
#define CS_BPA1_2_AN_GPIO_Port GPIOC
#define RMII_MDC_Pin GPIO_PIN_1
#define RMII_MDC_GPIO_Port GPIOC
#define CS_BPA2_1_AN_Pin GPIO_PIN_2
#define CS_BPA2_1_AN_GPIO_Port GPIOC
#define QSPI_CLK_Pin GPIO_PIN_2
#define QSPI_CLK_GPIO_Port GPIOB
#define FIL_SEL_UC_7_Pin GPIO_PIN_4
#define FIL_SEL_UC_7_GPIO_Port GPIOJ
#define QSPI_D1_Pin GPIO_PIN_12
#define QSPI_D1_GPIO_Port GPIOD
#define QSPI_D3_Pin GPIO_PIN_13
#define QSPI_D3_GPIO_Port GPIOD
#define FIL_SEL_UC_6_Pin GPIO_PIN_5
#define FIL_SEL_UC_6_GPIO_Port GPIOJ
#define RMII_REF_CLK_Pin GPIO_PIN_1
#define RMII_REF_CLK_GPIO_Port GPIOA
#define CS_BPA2_2_AN_Pin GPIO_PIN_0
#define CS_BPA2_2_AN_GPIO_Port GPIOA
#define DAC1_FWD_REF_Pin GPIO_PIN_4
#define DAC1_FWD_REF_GPIO_Port GPIOA
#define RMII_RXD0_Pin GPIO_PIN_4
#define RMII_RXD0_GPIO_Port GPIOC
#define FIL_SEL_UC_8_Pin GPIO_PIN_3
#define FIL_SEL_UC_8_GPIO_Port GPIOJ
#define QSPI_D0_Pin GPIO_PIN_11
#define QSPI_D0_GPIO_Port GPIOD
#define LED_D1_Pin GPIO_PIN_9
#define LED_D1_GPIO_Port GPIOH
#define RMII_MDIO_Pin GPIO_PIN_2
#define RMII_MDIO_GPIO_Port GPIOA
#define CS_BPA3_2_AN_Pin GPIO_PIN_6
#define CS_BPA3_2_AN_GPIO_Port GPIOA
#define DAC2_REV_REF_Pin GPIO_PIN_5
#define DAC2_REV_REF_GPIO_Port GPIOA
#define RMII_RXD1_Pin GPIO_PIN_5
#define RMII_RXD1_GPIO_Port GPIOC
#define TX_SEL_UC_Pin GPIO_PIN_2
#define TX_SEL_UC_GPIO_Port GPIOJ
#define UART_RS232_LCD_TX_Pin GPIO_PIN_10
#define UART_RS232_LCD_TX_GPIO_Port GPIOB
#define LED_D2_Pin GPIO_PIN_10
#define LED_D2_GPIO_Port GPIOH
#define RMII_CRS_DV_Pin GPIO_PIN_7
#define RMII_CRS_DV_GPIO_Port GPIOA
#define CS_BPA4_2_AN_Pin GPIO_PIN_1
#define CS_BPA4_2_AN_GPIO_Port GPIOB
#define CS_BPA4_1_AN_Pin GPIO_PIN_0
#define CS_BPA4_1_AN_GPIO_Port GPIOB
#define GPIO_1_Pin GPIO_PIN_0
#define GPIO_1_GPIO_Port GPIOJ
#define RX_SEL_UC_Pin GPIO_PIN_1
#define RX_SEL_UC_GPIO_Port GPIOJ
#define UART_RS232_LCD_RX_Pin GPIO_PIN_11
#define UART_RS232_LCD_RX_GPIO_Port GPIOB
#define FAN_FLT2_UC_Pin GPIO_PIN_14
#define FAN_FLT2_UC_GPIO_Port GPIOB
#define ALC_C2_Pin GPIO_PIN_15
#define ALC_C2_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */
#define USE_DHCP       /* enable DHCP, if disabled static address is used */

#define DEST_IP_ADDR0   (uint8_t)192
#define DEST_IP_ADDR1   (uint8_t)168
#define DEST_IP_ADDR2   (uint8_t)0
#define DEST_IP_ADDR3   (uint8_t)11

#define UDP_SERVER_PORT    7   /* define the UDP local connection port */
#define UDP_CLIENT_PORT    7   /* define the UDP remote connection port */

/*Static IP ADDRESS: IP_ADDR0.IP_ADDR1.IP_ADDR2.IP_ADDR3 */
#define IP_ADDR0   (uint8_t) 192
#define IP_ADDR1   (uint8_t) 168
#define IP_ADDR2   (uint8_t) 0
#define IP_ADDR3   (uint8_t) 10

/*NETMASK*/
#define NETMASK_ADDR0   (uint8_t) 255
#define NETMASK_ADDR1   (uint8_t) 255
#define NETMASK_ADDR2   (uint8_t) 255
#define NETMASK_ADDR3   (uint8_t) 0

/*Gateway Address*/
#define GW_ADDR0   (uint8_t) 192
#define GW_ADDR1   (uint8_t) 168
#define GW_ADDR2   (uint8_t) 0
#define GW_ADDR3   (uint8_t) 1


typedef enum {PASSED = 0, FAILED = !PASSED} TestStatus_t;
#define SDRAM_BANK_ADDR                 ((uint32_t)0xC0000000)

/* #define SDRAM_MEMORY_WIDTH            FMC_SDRAM_MEM_BUS_WIDTH_8  */
#define SDRAM_MEMORY_WIDTH               FMC_SDRAM_MEM_BUS_WIDTH_16

#define SDCLOCK_PERIOD                   FMC_SDRAM_CLOCK_PERIOD_2
/* #define SDCLOCK_PERIOD                FMC_SDRAM_CLOCK_PERIOD_3 */

#define SDRAM_TIMEOUT     ((uint32_t)0xFFFF)

#define SDRAM_MODEREG_BURST_LENGTH_1             ((uint16_t)0x0000)
#define SDRAM_MODEREG_BURST_LENGTH_2             ((uint16_t)0x0001)
#define SDRAM_MODEREG_BURST_LENGTH_4             ((uint16_t)0x0002)
#define SDRAM_MODEREG_BURST_LENGTH_8             ((uint16_t)0x0004)
#define SDRAM_MODEREG_BURST_TYPE_SEQUENTIAL      ((uint16_t)0x0000)
#define SDRAM_MODEREG_BURST_TYPE_INTERLEAVED     ((uint16_t)0x0008)
#define SDRAM_MODEREG_CAS_LATENCY_2              ((uint16_t)0x0020)
#define SDRAM_MODEREG_CAS_LATENCY_3              ((uint16_t)0x0030)
#define SDRAM_MODEREG_OPERATING_MODE_STANDARD    ((uint16_t)0x0000)
#define SDRAM_MODEREG_WRITEBURST_MODE_PROGRAMMED ((uint16_t)0x0000)
#define SDRAM_MODEREG_WRITEBURST_MODE_SINGLE     ((uint16_t)0x0200)

#define REFRESH_COUNT                    ((uint32_t)0x0603)   /* SDRAM refresh counter (100Mhz SD clock) */

#define SDRAM_TIMEOUT                    ((uint32_t)0xFFFF)
/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
