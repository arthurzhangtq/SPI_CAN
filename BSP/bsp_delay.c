
#ifndef _BSP_DELAY_C
#define _BSP_DELAY_C

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
#include "gd32e10x.h"
#include "bsp_delay.h"
  
/********************************************************************************************
* Define: 
********************************************************************************************/


/********************************************************************************************
* Datas: 
********************************************************************************************/
static uint8_t  fac_us=0;	//us延时倍乘数			   
static uint16_t fac_ms=0;	//ms延时倍乘数,在ucos下,代表每个节拍的ms数
static uint32_t reload=0;

static uint32_t tickBak=0;
static uint64_t tickTotal= 0;
/********************************************************************************************
* Function: 
********************************************************************************************/


/********************************************************************************************
* Function Name  : bsp_delay_init
* Description    : 延时配置
* Input          : void
* Output         : void
* Return         : none
********************************************************************************************/
void bsp_delay_init(void)
{
    SysTick->CTRL = 0;
    systick_clksource_set(SYSTICK_CLKSOURCE_HCLK_DIV8);

    fac_us = SystemCoreClock/8000000;
    fac_ms = (uint16_t)fac_us*1000;	

    reload = (uint32_t)fac_us*1000000;

    SysTick->LOAD  = reload-1;
    SysTick->VAL   = 0;
    SysTick->CTRL |= SysTick_CTRL_ENABLE_Msk;
}

/********************************************************************************************
* Function Name  : tickReset
* Description    : tick计时复位
* Input          : void
* Output         : void
* Return         : none
********************************************************************************************/
void tickReset(void)
{
    tickBak  = SysTick->VAL;
    tickTotal = 0;
}

/********************************************************************************************
* Function Name  : tickGet
* Description    : tick获取
* Input          : void
* Output         : uint64_t
* Return         : tick值
********************************************************************************************/
uint64_t tickGet(void)
{
    uint32_t tickNow = SysTick->VAL;
    
    if(tickNow <= tickBak)
        tickTotal += (tickBak - tickNow);
    else
        tickTotal += (reload + tickBak - tickNow);
    
    tickBak = tickNow;
    
    return tickTotal;
}



/********************************************************************************************
* Function Name  : bsp_delay_ms
* Description    : ms延时
* Input          : uint32_t ms
* Output         : void
* Return         : none
********************************************************************************************/
void bsp_delay_ms(uint32_t ms)
{
    uint64_t tickNeed;
    
    tickReset();
    tickNeed = fac_ms*ms;
    
    while(tickNeed > tickGet()) ;
}

/********************************************************************************************
* Function Name  : bsp_delay_us
* Description    : us延时
* Input          : uint32_t us
* Output         : void
* Return         : none
********************************************************************************************/
void bsp_delay_us(uint32_t us)
{
    uint64_t tickNeed;
    tickReset();
    tickNeed = fac_us*us;
    
    while(tickNeed > tickGet()) ;    
}    


/********************************************************************************************
* Function Name  : soft_delay_ms
* Description    : ms延时
* Input          : uint32_t ms
* Output         : void
* Return         : none
********************************************************************************************/
void soft_delay_ms(uint32_t ms)
{
    uint32_t i=0,m=0;
    
    for(i=0;i<ms;i++)
    {
        for(m=0;m<18000;m++)
        { 
        }
    }
}
/********************************************************************************************
* Function Name  : soft_delay_us
* Description    : us延时
* Input          : uint32_t us
* Output         : void
* Return         : none
********************************************************************************************/
void soft_delay_us(uint32_t us)
{
    uint32_t i=0,m=0;
    
    for(i=0;i<us;i++)
    {
        for(m=0;m<18;m++)
        { 
        }
    }
}


/********************************************************************************************
* Function Name  : delay
* Description    : 延时--单位s
* Input          : float
* Output         : void
* Return         : none
********************************************************************************************/
void delay(float sec)
{
    uint64_t tickNeed;
    tickReset();
    tickNeed = (uint64_t)((double)sec*reload);
    
    while(tickNeed > tickGet()) ;
}



#endif


