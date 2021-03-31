/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
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
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "adc.h"
#include "dac.h"
#include "dma.h"
#include "fatfs.h"
#include "i2c.h"
#include "lwip.h"
#include "quadspi.h"
#include "sdmmc.h"
#include "spi.h"
#include "usart.h"
#include "gpio.h"
#include "fmc.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "string.h"
#include "udp_echoclient.h"
#include "app_ethernet.h"
#include "lcd.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

FMC_SDRAM_CommandTypeDef command;

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
// Peripheral enable
//#define LAN_ENABLE
//#define SPI_ENABLE
//#define I2C_ENABLE
//#define UART_ENABLE
//#define SDMMC_ENABLE
//#define QSPI_ENABLE
#define SDRAM_ENABLE

#ifdef SDRAM_ENABLE
#define BUFFER_SIZE         ((uint32_t)0x1000)
#define WRITE_READ_ADDR     ((uint32_t)0x0800)
#endif
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
#ifdef SDRAM_ENABLE
/* Read/Write Buffers */
uint32_t aTxBuffer[BUFFER_SIZE];
uint32_t aRxBuffer[BUFFER_SIZE];
/* Status variables */
__IO uint32_t uwWriteReadStatus = 0;

/* Counter index */
uint32_t uwIndex = 0;
#endif
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */
#ifdef SDRAM_ENABLE
static void BSP_SDRAM_Initialization_Sequence(SDRAM_HandleTypeDef *hsdram, FMC_SDRAM_CommandTypeDef *Command);
static void Fill_Buffer(uint32_t *pBuffer, uint32_t uwBufferLenght, uint32_t uwOffset);
#endif

#ifdef I2C_ENABLE
#endif

#ifdef	ADC_ENABLE
#endif

#ifdef UART_ENABLE
	#ifdef __GNUC__
	/* With GCC, small printf (option LD Linker->Libraries->Small printf
	   set to 'Yes') calls __io_putchar() */
	#define PUTCHAR_PROTOTYPE int __io_putchar(int ch)
	#else
	#define PUTCHAR_PROTOTYPE int fputc(int ch, FILE *f)
	#endif /* __GNUC__ */
#endif

#ifdef LAN_ENABLE
	extern struct netif gnetif;
#endif

#ifdef SPI_ENABLE
#endif

#ifdef SDMMC_ENABLE
void uSD_Test(void);
#endif

#ifdef QSPI_ENABLE
__IO uint8_t CmdCplt, RxCplt, TxCplt, StatusMatch, TimeOut;

/* Buffer used for transmission */
uint8_t aTxBuffer[] = " ****QSPI communication based on IT****  ****QSPI communication based on IT****  ****QSPI communication based on IT****  ****QSPI communication based on IT****  ****QSPI communication based on IT****  ****QSPI communication based on IT**** ";

/* Buffer used for reception */

#endif

#ifdef DAC_ENABLE
#endif
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
#ifdef I2C_ENABLE
#endif

#ifdef	ADC_ENABLE
	__IO uint16_t uhADCxConvertedValue1 = 0;
	__IO uint16_t uhADCxConvertedValue2 = 0;
#endif

#ifdef UART_ENABLE
#endif

#ifdef LAN_ENABLE
#endif

#ifdef SPI_ENABLE
#endif

#ifdef SDMMC_ENABLE
FRESULT res;
uint32_t bytesWritten, bytesRead;
uint8_t wText[] = "STM32 Bel Demo Working... !";
uint8_t rText[_MAX_SS];
#endif

#ifdef QSPI_ENABLE
#endif

#ifdef SDRAM_ENABLE
#endif

#ifdef DAC_ENABLE
	const uint8_t aEscalator8bit[6] = {0x0, 0x33, 0x66, 0x99, 0xCC, 0xFF};
	__IO uint8_t ubSelectedWavesForm = 1;
#endif
/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */
#ifdef I2C_ENABLE
#endif

#ifdef	ADC_ENABLE
#endif

#ifdef UART_ENABLE
#endif

#ifdef LAN_ENABLE

#endif

#ifdef SPI_ENABLE
#endif

#ifdef SDMMC_ENABLE
#endif

#ifdef QSPI_ENABLE
	QSPI_CommandTypeDef sCommand;
	uint32_t address = 0;
	uint16_t index;
	__IO uint8_t step = 0;
#endif

#ifdef DAC_ENABLE
#endif
  /* USER CODE END 1 */

  /* Enable I-Cache---------------------------------------------------------*/
  SCB_EnableICache();

  /* Enable D-Cache---------------------------------------------------------*/
  SCB_EnableDCache();

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_SDMMC1_SD_Init();
  MX_FATFS_Init();
  MX_LWIP_Init();
  MX_QUADSPI_Init();
  MX_I2C1_Init();
  MX_I2C3_Init();
  MX_I2C4_Init();
  MX_SPI2_Init();
  MX_USART1_UART_Init();
  MX_USART2_UART_Init();
  MX_ADC1_Init();
  MX_ADC3_Init();
  MX_DAC_Init();
  MX_SPI5_Init();
  MX_UART7_Init();
  MX_USART3_UART_Init();
  MX_USART6_UART_Init();
  MX_FMC_Init();
  /* USER CODE BEGIN 2 */
#ifdef I2C_ENABLE
  lcd_test();
  HAL_Delay(500);
  HAL_I2C_Master_Transmit (&hi2c2, 0x50,(uint8_t *) "Hello I2C_2", 11, 100);
  HAL_Delay(500);
  HAL_I2C_Master_Transmit (&hi2c3, 0x50,(uint8_t *) "Hello I2C_3", 11, 100);
  HAL_Delay(500);
  HAL_I2C_Master_Transmit (&hi2c4, 0x50,(uint8_t *) "Hello I2C_4", 11, 100);
  HAL_Delay(500);
#endif

#ifdef	ADC_ENABLE
	HAL_ADC_PollForConversion(&hadc1, 10);
	HAL_ADC_PollForConversion(&hadc3, 10);

	/* Check if the continous conversion of regular channel is finished */
	if(HAL_IS_BIT_SET(HAL_ADC_GetState(&hadc1), HAL_ADC_STATE_REG_EOC))
	{
		/*##-5- Get the converted value of regular channel  ########################*/
		uhADCxConvertedValue1 = HAL_ADC_GetValue(&hadc1);
	}
	/* Check if the continous conversion of regular channel is finished */
	if(HAL_IS_BIT_SET(HAL_ADC_GetState(&hadc3), HAL_ADC_STATE_REG_EOC))
	{
		/*##-5- Get the converted value of regular channel  ########################*/
		uhADCxConvertedValue2 = HAL_ADC_GetValue(&hadc3);
	}
#endif

#ifdef UART_ENABLE
  lcd_test();
  HAL_Delay(500);
  HAL_UART_Transmit(&huart1, (uint8_t *) "Hello UART_1", 12, 100);
  HAL_Delay(500);
  HAL_UART_Transmit(&huart2, (uint8_t *) "Hello UART_2", 12, 100);
  HAL_Delay(500);
  HAL_UART_Transmit(&huart3, (uint8_t *) "Hello UART_3", 12, 100);
  HAL_Delay(500);
  HAL_UART_Transmit(&huart6, (uint8_t *) "Hello UART_6", 12, 100);
  HAL_Delay(500);
  HAL_UART_Transmit(&huart7, (uint8_t *) "Hello UART_7", 12, 100);
#endif

#ifdef LAN_ENABLE
  udp_echoclient_connect();

  /* Notify user about the network interface config */
  User_notification(&gnetif);
#endif

#ifdef SPI_ENABLE
  lcd_test();
  HAL_SPI_Transmit(&hspi2, (uint8_t *) "Hello SPI_2", 11, 100);
  HAL_SPI_Transmit(&hspi5, (uint8_t *) "Hello SPI_5", 11, 100);
#endif

#ifdef SDMMC_ENABLE
  uSD_Test();
#endif

#ifdef QSPI_ENABLE
#endif

#ifdef DAC_ENABLE
  /*##-1- Set DAC Channel1 DHR register ######################################*/
  if (HAL_DAC_SetValue(&hdac, DAC_CHANNEL_1 | DAC_CHANNEL_2, DAC_ALIGN_8B_R, 0xFF) != HAL_OK)
  {
    /* Setting value Error */
    Error_Handler();
  }

  /*##-2- Enable DAC Channel1 ################################################*/
  if (HAL_DAC_Start(&hdac, DAC_CHANNEL_1 | DAC_CHANNEL_2) != HAL_OK)
  {
    /* Start Error */
    Error_Handler();
  }
#endif

#ifdef SDRAM_ENABLE
  /* Program the SDRAM external device */
    BSP_SDRAM_Initialization_Sequence(&hsdram1, &command);

    /*##-2- SDRAM memory read/write access #####################################*/

    /* Fill the buffer to write */
    Fill_Buffer(aTxBuffer, BUFFER_SIZE, 0xA244250F);

    /* Write data to the SDRAM memory */
    for (uwIndex = 0; uwIndex < BUFFER_SIZE; uwIndex++)
    {
      *(__IO uint32_t*) (SDRAM_BANK_ADDR + WRITE_READ_ADDR + 4*uwIndex) = aTxBuffer[uwIndex];
    }

    /* Read back data from the SDRAM memory */
    for (uwIndex = 0; uwIndex < BUFFER_SIZE; uwIndex++)
    {
      aRxBuffer[uwIndex] = *(__IO uint32_t*) (SDRAM_BANK_ADDR + WRITE_READ_ADDR + 4*uwIndex);
    }

    /*##-3- Checking data integrity ############################################*/

    for (uwIndex = 0; (uwIndex < BUFFER_SIZE) && (uwWriteReadStatus == 0); uwIndex++)
    {
      if (aRxBuffer[uwIndex] != aTxBuffer[uwIndex])
      {
        uwWriteReadStatus++;
      }
    }

    if (uwWriteReadStatus != PASSED)
    {
      while(1)
      {
        /* KO, Toggle LED1 with a period of 200 ms */
        //BSP_LED_Toggle(LED1);
        HAL_Delay(200);
      }
    }
    else
    {
      /* OK, turn on LED1 */
      //BSP_LED_On(LED1);
    }
#endif
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
#ifdef I2C_ENABLE
#endif

#ifdef	ADC_ENABLE

#endif

#ifdef UART_ENABLE
#endif

#ifdef LAN_ENABLE
	/* Read a received packet from the Ethernet buffers and send it
	   to the lwIP for handling */
	ethernetif_input(&gnetif);

	/* Handle timeouts */
	sys_check_timeouts();

	#ifdef USE_DHCP
	    /* handle periodic timers for DHCP */
	    DHCP_Periodic_Handle(&gnetif);
	#endif
#endif

#ifdef SPI_ENABLE
#endif

#ifdef SDMMC_ENABLE
#endif

#ifdef QSPI_ENABLE
#endif

#ifdef DAC_ENABLE

#endif
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);
  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 200;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 8;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Activate the Over-Drive mode
  */
  if (HAL_PWREx_EnableOverDrive() != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_6) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInitStruct.PeriphClockSelection = RCC_PERIPHCLK_USART1|RCC_PERIPHCLK_USART2
                              |RCC_PERIPHCLK_USART3|RCC_PERIPHCLK_USART6
                              |RCC_PERIPHCLK_UART7|RCC_PERIPHCLK_I2C1
                              |RCC_PERIPHCLK_I2C3|RCC_PERIPHCLK_I2C4
                              |RCC_PERIPHCLK_SDMMC1|RCC_PERIPHCLK_CLK48;
  PeriphClkInitStruct.Usart1ClockSelection = RCC_USART1CLKSOURCE_PCLK2;
  PeriphClkInitStruct.Usart2ClockSelection = RCC_USART2CLKSOURCE_PCLK1;
  PeriphClkInitStruct.Usart3ClockSelection = RCC_USART3CLKSOURCE_PCLK1;
  PeriphClkInitStruct.Usart6ClockSelection = RCC_USART6CLKSOURCE_PCLK2;
  PeriphClkInitStruct.Uart7ClockSelection = RCC_UART7CLKSOURCE_PCLK1;
  PeriphClkInitStruct.I2c1ClockSelection = RCC_I2C1CLKSOURCE_PCLK1;
  PeriphClkInitStruct.I2c3ClockSelection = RCC_I2C3CLKSOURCE_PCLK1;
  PeriphClkInitStruct.I2c4ClockSelection = RCC_I2C4CLKSOURCE_PCLK1;
  PeriphClkInitStruct.Clk48ClockSelection = RCC_CLK48SOURCE_PLL;
  PeriphClkInitStruct.Sdmmc1ClockSelection = RCC_SDMMC1CLKSOURCE_CLK48;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */
#ifdef UART_ENABLE
/**
  * @brief  Retargets the C library printf function to the USART.
  * @param  None
  * @retval None
  */
PUTCHAR_PROTOTYPE
{
  /* Place your implementation of fputc here */
  /* e.g. write a character to the USART1 and Loop until the end of transmission */
  HAL_UART_Transmit(&huart2, (uint8_t *)&ch, 1, 0xFFFF);

  return ch;
}
#endif

#ifdef SDMMC_ENABLE
void uSD_Test(void)
{
	if (f_mount(&SDFatFS, (TCHAR const*)SDPath, 0) != FR_OK) {
		Error_Handler();
	} else {
		if (f_mkfs((TCHAR const*)SDPath, FM_ANY, 0, rText, sizeof(rText))) {
			Error_Handler();
		} else {
			// Open File for Writing
			if (f_open(&SDFile, "BEL.txt", FA_CREATE_ALWAYS | FA_WRITE) != FR_OK) {
				Error_Handler();
			} else {
				// Write to text file
				res = f_write(&SDFile, wText, strlen((char *)wText), (void *)bytesWritten);
				if ((bytesWritten == 0) || (res != FR_OK)) {
					Error_Handler();
				} else {
					f_close(&SDFile);

					// Test Read file
					f_open(&SDFile, "STM32.txt", FA_READ);
					memset(rText, 0, sizeof(rText));
					res = f_read(&SDFile, rText, sizeof(rText), (UINT*)&bytesRead);
					if ((bytesRead == 0) || (res != FR_OK)) {
						Error_Handler();
					} else {
						Error_Handler();
					}
					f_close(&SDFile);
				}
			}
		}
	}
	f_mount(&SDFatFS, (TCHAR const*)NULL, 0);
}
#endif

#ifdef SDRAM_ENABLE
/**
  * @brief  Perform the SDRAM external memory initialization sequence
  * @param  hsdram: SDRAM handle
  * @param  Command: Pointer to SDRAM command structure
  * @retval None
  */
static void BSP_SDRAM_Initialization_Sequence(SDRAM_HandleTypeDef *hsdram, FMC_SDRAM_CommandTypeDef *Command)
{
  __IO uint32_t tmpmrd =0;
  /* Step 3:  Configure a clock configuration enable command */
  Command->CommandMode = FMC_SDRAM_CMD_CLK_ENABLE;
  Command->CommandTarget = FMC_SDRAM_CMD_TARGET_BANK1;
  Command->AutoRefreshNumber = 1;
  Command->ModeRegisterDefinition = 0;

  /* Send the command */
  HAL_SDRAM_SendCommand(hsdram, Command, SDRAM_TIMEOUT);

  /* Step 4: Insert 100 us minimum delay */
  /* Inserted delay is equal to 1 ms due to systick time base unit (ms) */
  HAL_Delay(1);

  /* Step 5: Configure a PALL (precharge all) command */
  Command->CommandMode = FMC_SDRAM_CMD_PALL;
  Command->CommandTarget = FMC_SDRAM_CMD_TARGET_BANK1;
  Command->AutoRefreshNumber = 1;
  Command->ModeRegisterDefinition = 0;

  /* Send the command */
  HAL_SDRAM_SendCommand(hsdram, Command, SDRAM_TIMEOUT);

  /* Step 6 : Configure a Auto-Refresh command */
  Command->CommandMode = FMC_SDRAM_CMD_AUTOREFRESH_MODE;
  Command->CommandTarget = FMC_SDRAM_CMD_TARGET_BANK1;
  Command->AutoRefreshNumber = 8;
  Command->ModeRegisterDefinition = 0;

  /* Send the command */
  HAL_SDRAM_SendCommand(hsdram, Command, SDRAM_TIMEOUT);

  /* Step 7: Program the external memory mode register */
  tmpmrd = (uint32_t)SDRAM_MODEREG_BURST_LENGTH_1          |
                     SDRAM_MODEREG_BURST_TYPE_SEQUENTIAL   |
                     SDRAM_MODEREG_CAS_LATENCY_2           |
                     SDRAM_MODEREG_OPERATING_MODE_STANDARD |
                     SDRAM_MODEREG_WRITEBURST_MODE_SINGLE;

  Command->CommandMode = FMC_SDRAM_CMD_LOAD_MODE;
  Command->CommandTarget = FMC_SDRAM_CMD_TARGET_BANK1;
  Command->AutoRefreshNumber = 1;
  Command->ModeRegisterDefinition = tmpmrd;

  /* Send the command */
  HAL_SDRAM_SendCommand(hsdram, Command, SDRAM_TIMEOUT);

  /* Step 8: Set the refresh rate counter */
  /* (15.62 us x Freq) - 20 */
  /* Set the device refresh counter */
  hsdram->Instance->SDRTR |= ((uint32_t)((1292)<< 1));

}

/**
  * @brief  Fills buffer with user predefined data.
  * @param  pBuffer: pointer on the buffer to fill
  * @param  uwBufferLenght: size of the buffer to fill
  * @param  uwOffset: first value to fill on the buffer
  * @retval None
  */
static void Fill_Buffer(uint32_t *pBuffer, uint32_t uwBufferLenght, uint32_t uwOffset)
{
  uint32_t tmpIndex = 0;

  /* Put in global buffer different values */
  for (tmpIndex = 0; tmpIndex < uwBufferLenght; tmpIndex++ )
  {
    pBuffer[tmpIndex] = tmpIndex + uwOffset;
  }
}
#endif

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
