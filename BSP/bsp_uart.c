
#ifndef _BSP_UART_C
#define _BSP_UART_C

/********************************************************************************************
*file description:
*
*
*
*Created by Wujun @2020/10/12
*Copyright (c) 2020, Dreame Inc.
********************************************************************************************/
/********************************************************************************************
* include: 
********************************************************************************************/
#include "BSP_Config.h"
#include "bsp_uart.h"

/********************************************************************************************
* Define: 
********************************************************************************************/


/********************************************************************************************
* Datas: 
********************************************************************************************/



/********************************************************************************************
* Function: 
********************************************************************************************/
#if 1
#pragma import(__use_no_semihosting)             
//标准库需要的支持函数                 
struct __FILE 
{ 
	int handle; 

}; 

FILE __stdout;       
//定义_sys_exit()以避免使用半主机模式    
void _sys_exit(int x) 
{ 
	x = x; 
} 
/* retarget the C library printf function to the usart */
int fputc(int ch, FILE *f)
{
    usart_data_transmit(DEBUG_COM, (uint8_t)ch);
    while (RESET == usart_flag_get(DEBUG_COM, USART_FLAG_TBE));
    return ch;
}
#endif 



/********************************************************************************************
* Function Name  : bsp_uart_init
* Description    : 串口1初始化
* Input          : uint32_t baud 通信波特率
* Output         : void
* Return         : none
********************************************************************************************/
void bsp_uart_init(uint32_t baud)
{        
    /* enable clock */
    rcu_periph_clock_enable(RCU_USART1);
    rcu_periph_clock_enable(RCU_GPIOA);    
    rcu_periph_clock_enable(RCU_AF);
    
    /* initialize USART */
    nvic_irq_enable(USART1_IRQn, ISR_PRIORITY_USART1, 0);
        
    /* connect port to USARTx_Tx */
    gpio_init(GPIOA, GPIO_MODE_AF_PP, GPIO_OSPEED_10MHZ, GPIO_PIN_2);

    /* connect port to USARTx_Rx */
    gpio_init(GPIOA, GPIO_MODE_IN_FLOATING, GPIO_OSPEED_10MHZ, GPIO_PIN_3);

    /* USART configure */
    usart_deinit(USART1);
    usart_baudrate_set(USART1, baud);
    usart_word_length_set(USART1,USART_WL_8BIT);
    usart_stop_bit_set(USART1, USART_STB_1BIT);
    usart_parity_config(USART1, USART_PM_NONE);
    usart_hardware_flow_rts_config(USART1, USART_RTS_DISABLE);
    usart_hardware_flow_cts_config(USART1, USART_CTS_DISABLE);
    usart_receive_config(USART1, USART_RECEIVE_ENABLE);
    usart_transmit_config(USART1, USART_TRANSMIT_ENABLE);        
    
    usart_enable(USART1);
    
    usart_interrupt_enable(USART1, USART_INT_RBNE);    
    
    /* USART DMA enable for transmission and reception */
    //usart_dma_transmit_config(USART1, USART_DENT_ENABLE);
    //usart_dma_receive_config(USART1, USART_DENR_DISABLE);    
}


#endif
