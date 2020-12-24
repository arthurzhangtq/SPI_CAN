
#ifndef _BSP_EXIT_C
#define _BSP_EXIT_C

/********************************************************************************************
*file description:
*
*
*
*Created by Wujun @2019/06/
*Modified by XuYinbo @2019/10/15
*Copyright (c) 2019, Dreame Inc.
********************************************************************************************/
/********************************************************************************************
* include: 
********************************************************************************************/

#include "BSP_Config.h"
#include "bsp_exit.h"
/********************************************************************************************
* Define: 
********************************************************************************************/

void exit4_init(void);

/********************************************************************************************
* Datas: 
********************************************************************************************/



/********************************************************************************************
* Function: 
********************************************************************************************/


/********************************************************************************************
* Function Name  : bsp_exit_init
* Description    : 所有外部中断初始化
* Input          : void
* Output         : void
* Return         : none
********************************************************************************************/
void bsp_exit_init(void)
{
    exit4_init();
} 


/********************************************************************************************
* Function Name  : exit4_init
* Description    : 外部中断4初始化     INT_ACCEL       PE4
* Input          : void
* Output         : void
* Return         : none
********************************************************************************************/
void exit4_init(void)
{
    /* connect EXTI line to GPIO pin */
    gpio_exti_source_select(GPIO_PORT_SOURCE_GPIOA, GPIO_PIN_SOURCE_4);

    /* configure EXTI line */
    exti_init(EXTI_4, EXTI_INTERRUPT, EXTI_TRIG_FALLING);    
    
    /* clear exti interrupt flag*/
    exti_interrupt_flag_clear(EXTI_4);
    
    //nvic_irq_disable(EXTI4_IRQn);
    nvic_irq_enable(EXTI4_IRQn, ISR_PRIORITY_EXIT4, 0);
}

/********************************************************************************************
* Function Name  : EXTI4_IRQHandler
* Description    : exit4-中断服务函数
* Input          : void
* Output         : void
* Return         : none
********************************************************************************************/
//void EXTI4_IRQHandler(void)
//{
//    if(exti_interrupt_flag_get(EXTI_4))
//    {
//        exti_interrupt_flag_clear(EXTI_4);
//    }
//}



#endif