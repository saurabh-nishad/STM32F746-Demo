#include "stm32f7xx_hal.h"

void lcd_init_spi (void);   // initialize lcd

void lcd_send_cmd_spi (char cmd);  // send command to the lcd

void lcd_send_data_spi (char data);  // send data to the lcd

void lcd_send_string_spi (char *str);  // send string to the lcd

void lcd_clear_spi (void);  
