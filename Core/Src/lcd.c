/**	Driver for Newheaven Serial Display **/
/**	4 Lines x 20 Characters	**/

/**
 * 	I2C Max clock frequency 50kHz
 */
/** Put this in the src folder **/


#include "lcd.h"

extern UART_HandleTypeDef huart6;  	// change your handler here accordingly
extern SPI_HandleTypeDef hspi2;		// change your handler here accordingly
extern I2C_HandleTypeDef hi2c1;		// change your handler here accordingly

//#define USE_UART
#define USE_I2C
//#define USE_SPI

/*
 * Use this function to turn on the LCD
 */
void lcd_on (void)
{
	unsigned char buff[2];
	unsigned char buff2[3];
	buff[0]=0xFE;
	buff[1]=DISPLAY_ON;

	buff2[0]=0xFE;
	buff2[1]=BRIGHTNESS;
	buff2[2]=0x08;

#ifdef USE_I2C
	HAL_I2C_Master_Transmit (&hi2c1, SLAVE_ADDRESS_LCD,(uint8_t *) buff, 2, LCD_TIMEOUT);
	HAL_Delay(1);
	HAL_I2C_Master_Transmit (&hi2c1, SLAVE_ADDRESS_LCD,(uint8_t *) buff2, 3, LCD_TIMEOUT);
	HAL_Delay(1);
#endif

#ifdef USE_UART
	HAL_UART_Transmit(&huart6, (uint8_t *) buff, 2, LCD_TIMEOUT);
	HAL_Delay(1);
	HAL_UART_Transmit(&huart6, (uint8_t *) buff2, 3, LCD_TIMEOUT);
	HAL_Delay(1);
#endif

#ifdef USE_SPI
	HAL_SPI_Transmit(&hspi2, (uint8_t *) buff, 2, LCD_TIMEOUT);
	HAL_Delay(1);
	HAL_SPI_Transmit(&hspi2, (uint8_t *) buff2, 3, LCD_TIMEOUT);
	HAL_Delay(1);
#endif

}

/*
 * Use this function to turn off the LCD
 */
void lcd_off (void)
{
	unsigned char buff[2];
	buff[0]=0xFE;
	buff[1]=DISPLAY_OFF;

#ifdef USE_I2C
	HAL_I2C_Master_Transmit (&hi2c1, SLAVE_ADDRESS_LCD,(uint8_t *) buff, 2, LCD_TIMEOUT);
#endif

#ifdef USE_UART
	HAL_UART_Transmit(&huart6, (uint8_t *) buff, 2, LCD_TIMEOUT);
#endif

#ifdef USE_SPI
	HAL_SPI_Transmit(&hspi2, (uint8_t *) buff, 2, LCD_TIMEOUT);
#endif
	HAL_Delay(1);
}

/*
 * Use this function to clear the screen
 */
void lcd_clear (void)
{
	unsigned char buff[2];
	buff[0]=0xFE;
	buff[1]=CLEARSCREEN;

#ifdef USE_I2C
	HAL_I2C_Master_Transmit (&hi2c1, SLAVE_ADDRESS_LCD,(uint8_t *) buff, 2, LCD_TIMEOUT);
#endif

#ifdef USE_UART
	HAL_UART_Transmit(&huart6, (uint8_t *) buff, 2, LCD_TIMEOUT);
#endif

#ifdef USE_SPI
	HAL_SPI_Transmit(&hspi2, (uint8_t *) buff, 2, LCD_TIMEOUT);
#endif
	HAL_Delay(2);
}

/*
 * Use this function to set curson at desired line
 * Parameter:
 * 1 = For line 1
 * 2 = For line 2
 * 3 = For line 3
 * 4 = For line 4
 */
void lcd_set_cursor (uint8_t line)
{
	unsigned char buff[3];
	buff[0]=0xFE;
	buff[1]=SET_CURSOR;

	switch (line) {
		case 1:
			buff[2]=LINE_1;
			break;
		case 2:
			buff[2]=LINE_2;
			break;
		case 3:
			buff[2]=LINE_3;
			break;
		case 4:
			buff[2]=LINE_4;
			break;
		default:
			break;
	}

#ifdef USE_I2C
	HAL_I2C_Master_Transmit (&hi2c1, SLAVE_ADDRESS_LCD,(uint8_t *) buff, 3, LCD_TIMEOUT);
#endif

#ifdef USE_UART
	HAL_UART_Transmit(&huart6, (uint8_t *) buff, 3, LCD_TIMEOUT);
#endif

#ifdef USE_SPI
	HAL_SPI_Transmit(&hspi2, (uint8_t *) buff, 3, LCD_TIMEOUT);
#endif
	HAL_Delay(2);
}

/*
 * Use this function for backspace
 */
void lcd_backspace (void)
{
	unsigned char buff[2];
	buff[0]=0xFE;
	buff[1]=BACKSPACE;

#ifdef USE_I2C
	HAL_I2C_Master_Transmit (&hi2c1, SLAVE_ADDRESS_LCD,(uint8_t *) buff, 2, LCD_TIMEOUT);
#endif

#ifdef USE_UART
	HAL_UART_Transmit(&huart6, (uint8_t *) buff, 2, LCD_TIMEOUT);
#endif

#ifdef USE_SPI
	HAL_SPI_Transmit(&hspi2, (uint8_t *) buff, 2, LCD_TIMEOUT);
#endif
	HAL_Delay(1);
}

/*
 * Use this funtion to print Firmware Version
 */
void lcd_fw (void)
{
	unsigned char buff[2];
	buff[0]=0xFE;
	buff[1]=FW_VERSION;

#ifdef USE_I2C
	HAL_I2C_Master_Transmit (&hi2c1, SLAVE_ADDRESS_LCD,(uint8_t *) buff, 2, LCD_TIMEOUT);
#endif

#ifdef USE_UART
	HAL_UART_Transmit(&huart6, (uint8_t *) buff, 2, LCD_TIMEOUT);
#endif

#ifdef USE_SPI
	HAL_SPI_Transmit(&hspi2, (uint8_t *) buff, 2, LCD_TIMEOUT);
#endif
	HAL_Delay(4);
}

/*
 * Use this funtion to print Baud-Rate
 */
void lcd_baud_rate (void)
{
	unsigned char buff[2];
	buff[0]=0xFE;
	buff[1]=BAUD_RATE;

#ifdef USE_I2C
	HAL_I2C_Master_Transmit (&hi2c1, SLAVE_ADDRESS_LCD,(uint8_t *) buff, 2, LCD_TIMEOUT);
#endif

#ifdef USE_UART
	HAL_UART_Transmit(&huart6, (uint8_t *) buff, 2, LCD_TIMEOUT);
#endif

#ifdef USE_SPI
	HAL_SPI_Transmit(&hspi2, (uint8_t *) buff, 2, LCD_TIMEOUT);
#endif
	HAL_Delay(10);
}

/*
 * Use this funtion to print I2C Address
 */
void lcd_i2c_addr (void)
{
	unsigned char buff[2];
	buff[0]=0xFE;
	buff[1]=I2C_ADDR;

#ifdef USE_I2C
	HAL_I2C_Master_Transmit (&hi2c1, SLAVE_ADDRESS_LCD,(uint8_t *) buff, 2, LCD_TIMEOUT);
#endif

#ifdef USE_UART
	HAL_UART_Transmit(&huart6, (uint8_t *) buff, 2, LCD_TIMEOUT);
#endif

#ifdef USE_SPI
	HAL_SPI_Transmit(&hspi2, (uint8_t *) buff, 2, LCD_TIMEOUT);
#endif
	HAL_Delay(4);
}

/*
 * Send String on LCD
 */
void lcd_send_string (char *str)
{
}

/*
 * LCD Test function to print
 */
void lcd_test(void)
{
	lcd_off();
	lcd_clear();
	lcd_on();

	lcd_fw();
	HAL_Delay(2000);

	lcd_baud_rate();
	HAL_Delay(2000);

	lcd_i2c_addr();
	HAL_Delay(2000);

#ifdef USE_I2C
	lcd_set_cursor(2);
	HAL_I2C_Master_Transmit (&hi2c1, SLAVE_ADDRESS_LCD,(uint8_t *) "Tested By ST...", 15, LCD_TIMEOUT);
	lcd_set_cursor(3);
	HAL_I2C_Master_Transmit (&hi2c1, SLAVE_ADDRESS_LCD,(uint8_t *) "I2C Working", 11, LCD_TIMEOUT);
#endif

#ifdef USE_UART
	lcd_set_cursor(2);
	HAL_UART_Transmit(&huart6, (uint8_t *) "Tested By ST...", 15, LCD_TIMEOUT);
	lcd_set_cursor(3);
	HAL_UART_Transmit(&huart6, (uint8_t *) "UART Working", 12, LCD_TIMEOUT);
#endif

#ifdef USE_SPI
	lcd_set_cursor(2);
	HAL_SPI_Transmit(&hspi2, (uint8_t *) "Tested By ST...", 15, LCD_TIMEOUT);
	lcd_set_cursor(3);
	HAL_SPI_Transmit(&hspi2, (uint8_t *) "SPI Working", 11, LCD_TIMEOUT);
#endif
	HAL_Delay(4);
}

