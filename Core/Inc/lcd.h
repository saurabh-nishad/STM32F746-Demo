#include "stm32f7xx_hal.h"

/*
 * Newhaven LCD Related Info
 * I2C frequency = 50kHz
 * SPI frequency = 100 kHz Note: SPI Mode 3;	CPOL = 1;	CPHA = 1
 */

// LCD Related Define
#define DISPLAY_ON			0x41
#define DISPLAY_OFF			0x42
#define SET_CURSOR			0x45
#define CURSOR_HOME			0x46
#define BLINK_CURSOR_ON		0x4B
#define BLINK_CURSOR_OFF	0x4C
#define BACKSPACE 			0x4E
#define CLEARSCREEN			0x51
#define BRIGHTNESS			0x53

#define FW_VERSION			0x70
#define BAUD_RATE			0x71
#define I2C_ADDR			0x72

#define LINE_1				0x00
#define LINE_2				0x40
#define LINE_3				0x14
#define LINE_4				0x54

#define SHIFT_LEFT			0x55
#define SHIFT_RIGHT			0x56

#define SLAVE_ADDRESS_LCD	0x50
#define LCD_TIMEOUT			100


void lcd_on (void);

void lcd_off (void);

void lcd_clear (void);

void lcd_set_cursor (uint8_t line);

void lcd_backspace (void);

void lcd_fw (void);

void lcd_baud_rate (void);

void lcd_i2c_addr (void);

void lcd_test(void);

void lcd_send_string (char *str);
