
#ifndef _BSP_UART_H
#define _BSP_UART_H
#ifndef _BSP_UART_C
#define _BSP_UART_C extern
#endif

/********************************************************************************************
* include:
********************************************************************************************/
#include <stdint.h>
#include <stdio.h>
#include <string.h>


/********************************************************************************************
* Define:
********************************************************************************************/
#define DEBUG_COM  USART1


#define serial_isr   USART1_IRQHandler
#define serial_rxdByteStatus (RESET != usart_interrupt_flag_get(DEBUG_COM, USART_INT_FLAG_RBNE))    
#define serial_getChar()   usart_data_receive(DEBUG_COM)

/********************************************************************************************
* Datas:
********************************************************************************************/


/********************************************************************************************
* Function:
********************************************************************************************/
_BSP_UART_C void bsp_uart_init(uint32_t baud);

#endif
