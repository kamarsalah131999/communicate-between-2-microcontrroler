/*
 * Transmitter.c
 *
 * Created: 6/13/2023 5:28:24 AM
 * Author : kamar
 */ 

#include <avr/io.h>
#include "USART.H"
#define F_CPU 8000000UL
#include <util/delay.h>

int main(void)
{
	UART_vInit (9600);
	_delay_ms (300);                                                          // delay untill other microcontroller and LCD intialize
	UART_vSendString ("Kamar");
    
    while (1) 
    {
    }
}

