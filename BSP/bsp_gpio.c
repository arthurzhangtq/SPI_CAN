

#ifndef _BSP_GPIO_C
#define _BSP_GPIO_C

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
#include "bsp_gpio.h"

  
/********************************************************************************************
* Define: 
********************************************************************************************/


/********************************************************************************************
* Datas: 
********************************************************************************************/



/********************************************************************************************
* Function: 
********************************************************************************************/

/********************************************************************************************
* Function Name  : bsp_gpio_init
* Description    : gpio初始化
* Input          : void
* Output         : void
* Return         : none
********************************************************************************************/
void bsp_gpio_init(void)
{    
    /* enable clock */
    rcu_periph_clock_enable(RCU_GPIOA);
    rcu_periph_clock_enable(RCU_GPIOB);
    rcu_periph_clock_enable(RCU_GPIOC);
    rcu_periph_clock_enable(RCU_GPIOD);
    rcu_periph_clock_enable(RCU_AF);
    
    gpio_pin_remap_config(GPIO_SWJ_SWDPENABLE_REMAP,ENABLE);
    
    //input
    gpio_init(PORT_SPI_CS  , GPIO_MODE_IN_FLOATING, GPIO_OSPEED_2MHZ, BIT(PIN_SPI_CS  ));//IN_spiCs
    gpio_init(GPIOA  , GPIO_MODE_IN_FLOATING, GPIO_OSPEED_2MHZ, BIT(5  ));//IN_spiCs
    gpio_init(GPIOA  , GPIO_MODE_IN_FLOATING, GPIO_OSPEED_2MHZ, BIT(6  ));//IN_spiCs
    gpio_init(GPIOA  , GPIO_MODE_IN_FLOATING, GPIO_OSPEED_2MHZ, BIT(7  ));//IN_spiCs
    
    //output
    
    /*Nc gpio    
    gpio_init(GPIOA , GPIO_MODE_OUT_PP, GPIO_OSPEED_2MHZ, GPIO_PIN_0 ); GPIO_BC(GPIOA)=GPIO_PIN_0 ;
    gpio_init(GPIOA , GPIO_MODE_OUT_PP, GPIO_OSPEED_2MHZ, GPIO_PIN_1 ); GPIO_BC(GPIOA)=GPIO_PIN_1 ;
    gpio_init(GPIOA , GPIO_MODE_OUT_PP, GPIO_OSPEED_2MHZ, GPIO_PIN_8 ); GPIO_BC(GPIOA)=GPIO_PIN_8 ;
    gpio_init(GPIOA , GPIO_MODE_OUT_PP, GPIO_OSPEED_2MHZ, GPIO_PIN_9 ); GPIO_BC(GPIOA)=GPIO_PIN_9 ;
    gpio_init(GPIOA , GPIO_MODE_OUT_PP, GPIO_OSPEED_2MHZ, GPIO_PIN_10); GPIO_BC(GPIOA)=GPIO_PIN_10;
    gpio_init(GPIOA , GPIO_MODE_OUT_PP, GPIO_OSPEED_2MHZ, GPIO_PIN_15); GPIO_BC(GPIOA)=GPIO_PIN_15;
    
    gpio_init(GPIOB , GPIO_MODE_OUT_PP, GPIO_OSPEED_2MHZ, GPIO_PIN_0 ); GPIO_BC(GPIOB)=GPIO_PIN_0;
    gpio_init(GPIOB , GPIO_MODE_OUT_PP, GPIO_OSPEED_2MHZ, GPIO_PIN_1 ); GPIO_BC(GPIOB)=GPIO_PIN_1;
    gpio_init(GPIOB , GPIO_MODE_OUT_PP, GPIO_OSPEED_2MHZ, GPIO_PIN_2 ); GPIO_BC(GPIOB)=GPIO_PIN_2;
    gpio_init(GPIOB , GPIO_MODE_OUT_PP, GPIO_OSPEED_2MHZ, GPIO_PIN_3 ); GPIO_BC(GPIOB)=GPIO_PIN_3;
    gpio_init(GPIOB , GPIO_MODE_OUT_PP, GPIO_OSPEED_2MHZ, GPIO_PIN_4 ); GPIO_BC(GPIOB)=GPIO_PIN_4;
    gpio_init(GPIOB , GPIO_MODE_OUT_PP, GPIO_OSPEED_2MHZ, GPIO_PIN_5 ); GPIO_BC(GPIOB)=GPIO_PIN_5;
    gpio_init(GPIOB , GPIO_MODE_OUT_PP, GPIO_OSPEED_2MHZ, GPIO_PIN_6 ); GPIO_BC(GPIOB)=GPIO_PIN_6;
    gpio_init(GPIOB , GPIO_MODE_OUT_PP, GPIO_OSPEED_2MHZ, GPIO_PIN_7 ); GPIO_BC(GPIOB)=GPIO_PIN_7;
    gpio_init(GPIOB , GPIO_MODE_OUT_PP, GPIO_OSPEED_2MHZ, GPIO_PIN_8 ); GPIO_BC(GPIOB)=GPIO_PIN_8;
    gpio_init(GPIOB , GPIO_MODE_OUT_PP, GPIO_OSPEED_2MHZ, GPIO_PIN_9 ); GPIO_BC(GPIOB)=GPIO_PIN_9;
    gpio_init(GPIOB , GPIO_MODE_OUT_PP, GPIO_OSPEED_2MHZ, GPIO_PIN_10); GPIO_BC(GPIOB)=GPIO_PIN_10;
    gpio_init(GPIOB , GPIO_MODE_OUT_PP, GPIO_OSPEED_2MHZ, GPIO_PIN_11); GPIO_BC(GPIOB)=GPIO_PIN_11;
    gpio_init(GPIOB , GPIO_MODE_OUT_PP, GPIO_OSPEED_2MHZ, GPIO_PIN_14); GPIO_BC(GPIOB)=GPIO_PIN_14;
    gpio_init(GPIOB , GPIO_MODE_OUT_PP, GPIO_OSPEED_2MHZ, GPIO_PIN_15); GPIO_BC(GPIOB)=GPIO_PIN_15;
        
    gpio_init(GPIOC , GPIO_MODE_OUT_PP, GPIO_OSPEED_2MHZ, GPIO_PIN_13); GPIO_BC(GPIOC)=GPIO_PIN_13;
    */
}


#endif

