
#ifndef _BSP_CAN_H
#define _BSP_CAN_H
#ifndef _BSP_CAN_C
#define _BSP_CAN_C extern
#endif

/********************************************************************************************
* include:
********************************************************************************************/
#include "gd32e10x.h"


/********************************************************************************************
* Define:
********************************************************************************************/
// Master CAN ID ///
#define CAN_ID   0x0
#define CAN_MASK 0xFFE00004

struct CANMessage{
    int id;
    uint8_t data[8];
    uint8_t len;
};


#define rxISR1  CAN0_RX0_IRQHandler
#define rxISR2  CAN1_RX0_IRQHandler


typedef void (*FuncMsg)(struct CANMessage* const msg);


struct _CAN{
    
    //can_trasnmit_message_struct* const txdMsgHandle;
    //can_receive_message_struct*  const rxdMsgHandle;
    
    const FuncMsg read;
    const FuncMsg write;
    
};

/********************************************************************************************
* Datas:
********************************************************************************************/
extern struct _CAN can1,can2;

/********************************************************************************************
* Function:
********************************************************************************************/
_BSP_CAN_C void bsp_can_init(uint32_t baud);

#endif
