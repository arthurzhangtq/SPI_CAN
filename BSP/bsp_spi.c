
#ifndef _BSP_SPI_C
#define _BSP_SPI_C

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
#include "bsp_spi.h"

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
* Function Name  : spi_config
* Description    : spi外设初始化
* Input          : void
* Output         : void
* Return         : none
********************************************************************************************/
void bsp_spi_init(void)
{ 
    spi_parameter_struct spi_init_struct;
        
    /* enable clock */
    rcu_periph_clock_enable(RCU_GPIOA);
    rcu_periph_clock_enable(RCU_SPI0);
    rcu_periph_clock_enable(RCU_AF);
    
    /* SPI0 GPIO config: NSS/PA4, SCK/PA5, MOSI/PA7 */
    gpio_init(GPIOA, GPIO_MODE_AF_PP, GPIO_OSPEED_50MHZ,  GPIO_PIN_6);
    /* SPI0 GPIO config: MISO/PA6 */
    gpio_init(GPIOA, GPIO_MODE_IN_FLOATING, GPIO_OSPEED_50MHZ, GPIO_PIN_5 | GPIO_PIN_7);

    
    spi_i2s_deinit(SPI0);
    spi_struct_para_init(&spi_init_struct);
    /* SPI1 parameter config */
    spi_init_struct.trans_mode           = SPI_TRANSMODE_FULLDUPLEX;
    spi_init_struct.device_mode          = SPI_SLAVE;
    spi_init_struct.frame_size           = SPI_FRAMESIZE_8BIT;
    spi_init_struct.clock_polarity_phase = SPI_CK_PL_LOW_PH_1EDGE;
    spi_init_struct.nss                  = SPI_NSS_HARD;
    spi_init_struct.endian               = SPI_ENDIAN_MSB;        
    spi_init_struct.prescale             = SPI_PSC_8; //120/16 =1.5MHZ
    spi_init(SPI0, &spi_init_struct);
    
    dma0_ch1_config();
    dma0_ch2_config();    
    
    spi_dma_enable(SPI0, SPI_DMA_TRANSMIT);
    spi_dma_enable(SPI0, SPI_DMA_RECEIVE);
    
    /* SPI enable */
    spi_enable(SPI0);

    bsp_exit_init();
}



#endif
