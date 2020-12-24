
#ifndef _BSP_DMA_C
#define _BSP_DMA_C

/********************************************************************************************
*file description:
*
*
*
*Created by Wujun @2019/10/15
*Copyright (c) 2019, Dreame Inc.
********************************************************************************************/
/********************************************************************************************
* include: 
********************************************************************************************/
#include "BSP_Config.h"
#include "bsp_dma.h"

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
* Function Name  : dma0_ch0_config
* Description    : DMA0_CH0 配置---ADC0数据采集
* Input          : void
* Output         : void
* Return         : none
********************************************************************************************/
void dma0_ch0_config(void)
{
    /* ADC_DMA_channel configuration */
    dma_parameter_struct dma_data_parameter;
    
    /* enable clock */
    rcu_periph_clock_enable(RCU_DMA0);
    
    /* ADC DMA_channel configuration */
    dma_deinit(DMA0, DMA_CH0);
    
    /* initialize DMA single data mode */
    dma_data_parameter.periph_addr  = (uint32_t)(&ADC_RDATA(ADC0));
    dma_data_parameter.periph_inc   = DMA_PERIPH_INCREASE_DISABLE;
    //dma_data_parameter.memory_addr  = (uint32_t)(&adc0_value);
    dma_data_parameter.memory_inc   = DMA_MEMORY_INCREASE_ENABLE;
    dma_data_parameter.periph_width = DMA_PERIPHERAL_WIDTH_16BIT;
    dma_data_parameter.memory_width = DMA_MEMORY_WIDTH_16BIT;  
    dma_data_parameter.direction    = DMA_PERIPHERAL_TO_MEMORY;
    //dma_data_parameter.number       = ADC0_DMA_BUF_SIZE;
    dma_data_parameter.priority     = DMA_PRIORITY_HIGH;
    dma_init(DMA0, DMA_CH0, &dma_data_parameter);
    dma_circulation_enable(DMA0, DMA_CH0);
  
    /* enable DMA channel */
    dma_channel_enable(DMA0, DMA_CH0);
}

/********************************************************************************************
* Function Name  : dma0_ch1_config
* Description    : DMA0_CH1 配置---SPI0_RX
* Input          : void
* Output         : void
* Return         : none
********************************************************************************************/
void dma0_ch1_config(void)
{    
    dma_parameter_struct dma_init_struct;
    
    //clock
    rcu_periph_clock_enable(RCU_DMA0); 
    
    //nvic_irq_enable(DMA0_Channel1_IRQn, ISR_PRIORITY_DMA0CH1, 0);
        
    //DMA
    dma_deinit(DMA0, DMA_CH1);
    dma_init_struct.direction    = DMA_PERIPHERAL_TO_MEMORY;
    dma_init_struct.memory_addr  = 0;
    dma_init_struct.memory_inc   = DMA_MEMORY_INCREASE_ENABLE;
    dma_init_struct.memory_width = DMA_PERIPHERAL_WIDTH_8BIT;
    dma_init_struct.number       = 0;
    dma_init_struct.periph_addr  = (uint32_t)&SPI_DATA(SPI0);
    dma_init_struct.periph_inc   = DMA_PERIPH_INCREASE_DISABLE;
    dma_init_struct.periph_width = DMA_PERIPHERAL_WIDTH_8BIT;
    dma_init_struct.priority     = DMA_PRIORITY_ULTRA_HIGH;    
    dma_init(DMA0, DMA_CH1, &dma_init_struct);
    /* configure DMA mode */
    dma_circulation_disable(DMA0, DMA_CH1);
    
    /* enable DMA transfer complete interrupt */
    //dma_interrupt_enable(DMA0, DMA_CH1, DMA_INT_FTF);
    
    /* enable DMA channel */
    //dma_channel_enable(DMA0, DMA_CH1);  
} 
    

/********************************************************************************************
* Function Name  : dma0_ch2_config
* Description    : DMA0_CH2 配置---SPI0_TX
* Input          : void
* Output         : void
* Return         : none
********************************************************************************************/
void dma0_ch2_config(void)
{ 
    dma_parameter_struct dma_init_struct; 
    
    //clock
    rcu_periph_clock_enable(RCU_DMA0); 
    
    //nvic_irq_enable(DMA0_Channel2_IRQn, ISR_PRIORITY_DMA0CH2, 0);
        
    //DMA
    dma_deinit(DMA0, DMA_CH2);
    dma_init_struct.direction    = DMA_MEMORY_TO_PERIPHERAL;
    dma_init_struct.memory_addr  = 0;
    dma_init_struct.memory_inc   = DMA_MEMORY_INCREASE_ENABLE;
    dma_init_struct.memory_width = DMA_PERIPHERAL_WIDTH_8BIT;
    dma_init_struct.number       = 0;
    dma_init_struct.periph_addr  = (uint32_t)&SPI_DATA(SPI0);
    dma_init_struct.periph_inc   = DMA_PERIPH_INCREASE_DISABLE;
    dma_init_struct.periph_width = DMA_PERIPHERAL_WIDTH_8BIT;
    dma_init_struct.priority     = DMA_PRIORITY_ULTRA_HIGH;    
    dma_init(DMA0, DMA_CH2, &dma_init_struct);
    /* configure DMA mode */
    dma_circulation_enable(DMA0, DMA_CH2);
    
    /* enable DMA transfer complete interrupt */
    //dma_interrupt_enable(DMA0, DMA_CH2, DMA_INT_FTF);
    
    /* enable DMA channel */
    //dma_channel_enable(DMA0, DMA_CH2); 
}

/********************************************************************************************
* Function Name  : dma0_ch3_config
* Description    : DMA0_CH3 配置---核心板通信串口1发送数据（UART0_TX）
* Input          : void
* Output         : void
* Return         : none
********************************************************************************************/
void dma0_ch3_config(void)
{ 
    dma_parameter_struct dma_init_struct; 
    
    //clock
    rcu_periph_clock_enable(RCU_DMA0); 
    
    //nvic_irq_enable(DMA0_Channel3_IRQn, ISR_PRIORITY_DMA0CH3, 0);
        
    //DMA
    dma_deinit(DMA0, DMA_CH3);
    dma_init_struct.direction    = DMA_MEMORY_TO_PERIPHERAL;
    dma_init_struct.memory_addr  = 0;
    dma_init_struct.memory_inc   = DMA_MEMORY_INCREASE_ENABLE;
    dma_init_struct.memory_width = DMA_PERIPHERAL_WIDTH_8BIT;
    dma_init_struct.number       = 0;
    dma_init_struct.periph_addr  = (uint32_t)(&USART_DATA(USART0));
    dma_init_struct.periph_inc   = DMA_PERIPH_INCREASE_DISABLE;
    dma_init_struct.periph_width = DMA_PERIPHERAL_WIDTH_8BIT;
    dma_init_struct.priority     = DMA_PRIORITY_ULTRA_HIGH;    
    dma_init(DMA0, DMA_CH3, &dma_init_struct);
    /* configure DMA mode */
    dma_circulation_disable(DMA0, DMA_CH3);
    
    /* enable DMA transfer complete interrupt */
    //dma_interrupt_enable(DMA0, DMA_CH3, DMA_INT_FTF);
    
    /* enable DMA channel */
    dma_channel_enable(DMA0, DMA_CH3);
}  

/********************************************************************************************
* Function Name  : dma0_ch4_config
* Description    : DMA0_CH4 配置---风机速度检测 TIM1_CH0
* Input          : void
* Output         : void
* Return         : none
********************************************************************************************/
void dma0_ch4_config(void)
{  
    dma_parameter_struct dma_init_struct; 
    
    //clock
    rcu_periph_clock_enable(RCU_DMA0); 
    
    //DMA
    dma_deinit(DMA0, DMA_CH4);
    dma_init_struct.direction     = DMA_PERIPHERAL_TO_MEMORY;
    dma_init_struct.memory_addr   = 0;//(uint32_t)(encoderFan.cntMarkBuf);
    dma_init_struct.memory_inc    = DMA_MEMORY_INCREASE_ENABLE;
    dma_init_struct.memory_width  = DMA_MEMORY_WIDTH_32BIT;
    dma_init_struct.number        = 0;//CNT_MARK_BUF_SIZE;
    dma_init_struct.periph_addr   = 0;//CAP_TIMER_REG;
    dma_init_struct.periph_inc    = DMA_PERIPH_INCREASE_DISABLE;
    dma_init_struct.periph_width  = DMA_PERIPHERAL_WIDTH_16BIT;
    dma_init_struct.priority      = DMA_PRIORITY_ULTRA_HIGH;
    dma_init(DMA0, DMA_CH4, &dma_init_struct);
    /* configure DMA mode */
    dma_circulation_enable(DMA0, DMA_CH4);        
    /* enable DMA channel */
    dma_channel_enable(DMA0, DMA_CH4); 
}

/********************************************************************************************
* Function Name  : dma0_ch5_config
* Description    : DMA0_CH5 配置:自动记录左轮轮脉冲捕获时间标记 TIM2_CH0
* Input          : void
* Output         : void
* Return         : none
********************************************************************************************/
void dma0_ch5_config(void)
{  
    dma_parameter_struct dma_init_struct; 
    
    //clock
    rcu_periph_clock_enable(RCU_DMA0); 
    
    //DMA
    dma_deinit(DMA0, DMA_CH5);
    dma_init_struct.direction     = DMA_PERIPHERAL_TO_MEMORY;
    dma_init_struct.memory_addr   = 0;//(uint32_t)(encoderLeft.cntMarkBuf);
    dma_init_struct.memory_inc    = DMA_MEMORY_INCREASE_ENABLE;
    dma_init_struct.memory_width  = DMA_MEMORY_WIDTH_32BIT;
    dma_init_struct.number        = 0;//CNT_MARK_BUF_SIZE;
    dma_init_struct.periph_addr   = 0;//CAP_TIMER_REG;
    dma_init_struct.periph_inc    = DMA_PERIPH_INCREASE_DISABLE;
    dma_init_struct.periph_width  = DMA_PERIPHERAL_WIDTH_16BIT;
    dma_init_struct.priority      = DMA_PRIORITY_ULTRA_HIGH;
    dma_init(DMA0, DMA_CH5, &dma_init_struct);
    /* configure DMA mode */
    dma_circulation_enable(DMA0, DMA_CH5);        
    /* enable DMA channel */
    dma_channel_enable(DMA0, DMA_CH5);     
}

/********************************************************************************************
* Function Name  : dma0_ch6_config
* Description    : DMA0_CH6 配置 --调试串口发送数据（UART1_TX）
* Input          : void
* Output         : void
* Return         : none
********************************************************************************************/
void dma0_ch6_config(void)
{    
    dma_parameter_struct dma_init_struct; 
    
    //clock
    rcu_periph_clock_enable(RCU_DMA0);
    
    //nvic_irq_enable(DMA0_Channel6_IRQn, ISR_PRIORITY_DMA0CH6, 0);
        
    //DMA
    dma_deinit(DMA0, DMA_CH6);
    dma_init_struct.direction    = DMA_MEMORY_TO_PERIPHERAL;
    dma_init_struct.memory_addr  = 0;
    dma_init_struct.memory_inc   = DMA_MEMORY_INCREASE_ENABLE;
    dma_init_struct.memory_width = DMA_PERIPHERAL_WIDTH_8BIT;
    dma_init_struct.number       = 0;
    dma_init_struct.periph_addr  = (uint32_t)(&USART_DATA(USART1));
    dma_init_struct.periph_inc   = DMA_PERIPH_INCREASE_DISABLE;
    dma_init_struct.periph_width = DMA_PERIPHERAL_WIDTH_8BIT;
    dma_init_struct.priority     = DMA_PRIORITY_ULTRA_HIGH;    
    dma_init(DMA0, DMA_CH6, &dma_init_struct);
    /* configure DMA mode */
    dma_circulation_disable(DMA0, DMA_CH6);
    
    /* enable DMA transfer complete interrupt */
    //dma_interrupt_enable(DMA0, DMA_CH6, DMA_INT_FTF);
    
    /* enable DMA channel */
    dma_channel_enable(DMA0, DMA_CH6);  
}

/********************************************************************************************
* Function Name  : dma1_ch0_config
* Description    : DMA1_CH0 配置---右全向红外 TIM7_CH2
* Input          : void
* Output         : void
* Return         : none
********************************************************************************************/
void dma1_ch0_config(void)
{
    dma_parameter_struct dma_init_struct; 
    
    //clock
    rcu_periph_clock_enable(RCU_DMA1); 
    
    //DMA
    dma_deinit(DMA1, DMA_CH0);
    dma_init_struct.direction     = DMA_PERIPHERAL_TO_MEMORY;
    dma_init_struct.memory_addr   = 0;//(uint32_t)(irR.timeMarkBuf);
    dma_init_struct.memory_inc    = DMA_MEMORY_INCREASE_ENABLE;
    dma_init_struct.memory_width  = DMA_MEMORY_WIDTH_16BIT;
    dma_init_struct.number        = 0;//IR_TIME_BUF_SIZE;
    dma_init_struct.periph_addr   = (uint32_t)(&TIMER_CH2CV(TIMER7));
    dma_init_struct.periph_inc    = DMA_PERIPH_INCREASE_DISABLE;
    dma_init_struct.periph_width  = DMA_PERIPHERAL_WIDTH_16BIT;
    dma_init_struct.priority      = DMA_PRIORITY_ULTRA_HIGH;
    dma_init(DMA1, DMA_CH0, &dma_init_struct);
    /* configure DMA mode */
    dma_circulation_enable(DMA1, DMA_CH0);        
    /* enable DMA channel */
    dma_channel_enable(DMA1, DMA_CH0); 
}

/********************************************************************************************
* Function Name  : dma1_ch1_config
* Description    : DMA1_CH1 配置:用来自动记录右轮脉冲捕获时间标记 TIM7_CH3
* Input          : void
* Output         : void
* Return         : none
********************************************************************************************/
void dma1_ch1_config(void)
{  
    dma_parameter_struct dma_init_struct; 
    
    //clock
    rcu_periph_clock_enable(RCU_DMA1); 
    
    //DMA
    dma_deinit(DMA1, DMA_CH1);
    dma_init_struct.direction     = DMA_PERIPHERAL_TO_MEMORY;
    dma_init_struct.memory_addr   = 0;//(uint32_t)(encoderRight.cntMarkBuf);
    dma_init_struct.memory_inc    = DMA_MEMORY_INCREASE_ENABLE;
    dma_init_struct.memory_width  = DMA_MEMORY_WIDTH_32BIT;
    dma_init_struct.number        = 0;//CNT_MARK_BUF_SIZE;
    dma_init_struct.periph_addr   = (uint32_t)(&TIMER_CH3CV(TIMER7));
    dma_init_struct.periph_inc    = DMA_PERIPH_INCREASE_DISABLE;
    dma_init_struct.periph_width  = DMA_PERIPHERAL_WIDTH_16BIT;
    dma_init_struct.priority      = DMA_PRIORITY_ULTRA_HIGH;
    dma_init(DMA1, DMA_CH1, &dma_init_struct);
    /* configure DMA mode */
    dma_circulation_enable(DMA1, DMA_CH1);        
    /* enable DMA channel */
    dma_channel_enable(DMA1, DMA_CH1); 
}

/********************************************************************************************
* Function Name  : dma1_ch2_config
* Description    : DMA1_CH2 配置---左前全向红外 TIM7_CH0
* Input          : void
* Output         : void
* Return         : none
********************************************************************************************/
void dma1_ch2_config(void)
{
    dma_parameter_struct dma_init_struct; 
    
    //clock
    rcu_periph_clock_enable(RCU_DMA1); 
    
    //DMA
    dma_deinit(DMA1, DMA_CH2);
    dma_init_struct.direction     = DMA_PERIPHERAL_TO_MEMORY;
    dma_init_struct.memory_addr   = 0;//(uint32_t)(irML.timeMarkBuf);
    dma_init_struct.memory_inc    = DMA_MEMORY_INCREASE_ENABLE;
    dma_init_struct.memory_width  = DMA_MEMORY_WIDTH_16BIT;
    dma_init_struct.number        = 0;//IR_TIME_BUF_SIZE;
    dma_init_struct.periph_addr   = (uint32_t)(&TIMER_CH0CV(TIMER7));
    dma_init_struct.periph_inc    = DMA_PERIPH_INCREASE_DISABLE;
    dma_init_struct.periph_width  = DMA_PERIPHERAL_WIDTH_16BIT;
    dma_init_struct.priority      = DMA_PRIORITY_ULTRA_HIGH;
    dma_init(DMA1, DMA_CH2, &dma_init_struct);
    /* configure DMA mode */
    dma_circulation_enable(DMA1, DMA_CH2);        
    /* enable DMA channel */
    dma_channel_enable(DMA1, DMA_CH2); 
}

/********************************************************************************************
* Function Name  : dma1_ch4_config
* Description    : DMA1_CH4 配置---右前全向红外 TIM7_CH1
* Input          : void
* Output         : void
* Return         : none
********************************************************************************************/
void dma1_ch4_config(void)
{
    dma_parameter_struct dma_init_struct; 
    
    //clock
    rcu_periph_clock_enable(RCU_DMA1); 
    
    //DMA
    dma_deinit(DMA1, DMA_CH4);
    dma_init_struct.direction     = DMA_PERIPHERAL_TO_MEMORY;
    dma_init_struct.memory_addr   = 0;//(uint32_t)(irMR.timeMarkBuf);
    dma_init_struct.memory_inc    = DMA_MEMORY_INCREASE_ENABLE;
    dma_init_struct.memory_width  = DMA_MEMORY_WIDTH_16BIT;
    dma_init_struct.number        = 0;//IR_TIME_BUF_SIZE;
    dma_init_struct.periph_addr   = (uint32_t)(&TIMER_CH1CV(TIMER7));
    dma_init_struct.periph_inc    = DMA_PERIPH_INCREASE_DISABLE;
    dma_init_struct.periph_width  = DMA_PERIPHERAL_WIDTH_16BIT;
    dma_init_struct.priority      = DMA_PRIORITY_ULTRA_HIGH;
    dma_init(DMA1, DMA_CH4, &dma_init_struct);
    /* configure DMA mode */
    dma_circulation_enable(DMA1, DMA_CH4);        
    /* enable DMA channel */
    dma_channel_enable(DMA1, DMA_CH4); 
}

#endif
