/*
 * USART.h
 *
 * Created: 6/13/2023 2:36:26 AM
 *  Author: kamar
 */ 


#ifndef USART_H_
#define USART_H_

void UART_vInit ( unsigned long baud_rate);
void UART_vSendData ( char data);
char UART_u8ResevigData ();
void UART_vSendString (char *ptr);



#endif /* USART_H_ */