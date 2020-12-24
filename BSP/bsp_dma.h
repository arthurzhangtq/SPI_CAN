
#ifndef _BSP_DMA_H
#define _BSP_DMA_H
#ifndef _BSP_DMA_C
#define _BSP_DMA_C extern
#endif

/********************************************************************************************
* include:
********************************************************************************************/



/********************************************************************************************
* Define:
********************************************************************************************/

#define dmaMemSize(a,b,add,size) {DMA_CHCTL(a,b)&= ~DMA_CHXCTL_CHEN;DMA_CHMADDR(a,b)=add;DMA_CHCNT(a,b)= size;DMA_CHCTL(a,b) |= DMA_CHXCTL_CHEN;}

    
    

/********************************************************************************************
* Datas:
********************************************************************************************/



/********************************************************************************************
* Function:
********************************************************************************************/

_BSP_DMA_C void dma0_ch0_config(void);
_BSP_DMA_C void dma0_ch1_config(void);
_BSP_DMA_C void dma0_ch2_config(void);
_BSP_DMA_C void dma0_ch3_config(void);
_BSP_DMA_C void dma0_ch4_config(void);
_BSP_DMA_C void dma0_ch5_config(void);
_BSP_DMA_C void dma0_ch6_config(void);
_BSP_DMA_C void dma1_ch0_config(void);
_BSP_DMA_C void dma1_ch1_config(void);
_BSP_DMA_C void dma1_ch2_config(void);
_BSP_DMA_C void dma1_ch4_config(void);

#endif
