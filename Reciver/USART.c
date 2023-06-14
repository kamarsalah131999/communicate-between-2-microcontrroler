/*
 * USART.c
 *  
 * Created: 6/13/2023 2:36:09 AM
 *  Author: kamar
 */ 

#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include "macros.h"

/* Normal Asyncronous Mode with 8 bit data, No Parity and 1_bit for Stop bit */

void UART_vInit ( unsigned long baud_rate)
{
	
	/* choose Baud rate that will be used by sender and reciver */
	unsigned short UBRR;
	UBRR=(F_CPU/(16*baud_rate))-1;
	UBRRH= (unsigned char*) (UBRR>>8);
	UBRRL= (unsigned char*) UBRR ;
	
	/* enable UART sender & reciver */
	SET_BIT(UCSRB,TXEN);
	SET_BIT(UCSRB,RXEN);
	
	/* enable Size of bit == 8 bit  and enable to write in UCSRC Regester */
	UCSRC= (1<<URSEL)| (1<<UCSZ0)| (1<<UCSZ1);
	
}

void UART_vSendData ( char data)
{
	
	/* wait fot transmit Buffer to be embty << sending all data to Shift register>> */
	while ( READ_BIT(UCSRA,UDRE) ==0 );
	
	/* send data to transmit buffer */
	UDR= data;
}
	
char UART_u8ResevigData ()
{
	/* wait fot recive  Buffer to be filled with data */
	while ( READ_BIT(UCSRA,RXC) ==0 );
	
	/* recive data from  ricever  buffer */
	if (READ_BIT(UCSRA,FE) ==0 && READ_BIT(UCSRA,PE) ==0 )                                  // we recived expected data
	{
		return UDR;
	}
	
}

void UART_vSendString (char *ptr)
{
	while ( *ptr!=0)
	{
	   UART_vSendData (*ptr);
	   ptr++;
	   _delay_ms(100);
	}
}