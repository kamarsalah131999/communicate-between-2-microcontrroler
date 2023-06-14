/*
 * Reciver.c
 *
 * Created: 6/13/2023 5:34:30 AM
 * Author : kamar
 */ 

#include <avr/io.h>
#include "LCD driver.h"
#include "USART.h"

int main(void)
{
    LCD_vinit ();
	UART_vInit (9600);
	char data;
	
    while (1) 
    {
		data= UART_u8ResevigData ();
		LCD_vsend_char (data);
    }
}

