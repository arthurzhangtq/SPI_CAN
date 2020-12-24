
#ifndef _BSP_CONFIG_H
#define _BSP_CONFIG_H
#ifndef _BSP_CONFIG_C
#define _BSP_CONFIG_C extern
#endif

/********************************************************************************************
* include:
********************************************************************************************/
#include "gd32e10x.h"

#include "bsp_gpio.h"
#include "bsp_uart.h"
#include "bsp_timer.h"
#include "bsp_spi.h"
#include "bsp_can.h"
#include "bsp_dma.h"
#include "bsp_delay.h"
#include "bsp_exit.h"

/********************************************************************************************
* Define:
********************************************************************************************/

//irq中断优先级
typedef enum{
    ISR_PRIORITY_NONE = 3,
    ISR_PRIORITY_EXIT4,
    ISR_PRIORITY_CAN_REV,
    //ISR_PRIORITY_CAN0_REV,
    //ISR_PRIORITY_CAN1_REV, 
    ISR_PRIORITY_USART1, 
}IsrPri_eTypeDef;


#define wait(n)     delay(n)
#define wait_us(n)  bsp_delay_us(n)

#define SPI_TX_DMA       DMA0
#define SPI_TX_DMACH     DMA_CH2    

#define SPI_RX_DMA       DMA0
#define SPI_RX_DMACH     DMA_CH1   




/********************************************************************************************
* Datas:
********************************************************************************************/


/********************************************************************************************
* Function:
********************************************************************************************/
_BSP_CONFIG_C void board_init(void);


#endif
