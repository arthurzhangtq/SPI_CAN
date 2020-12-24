
#ifndef _BSP_CAN_C
#define _BSP_CAN_C

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
#include "bsp_can.h"

#include <stdint.h>

/********************************************************************************************
* Define: 
********************************************************************************************/


/********************************************************************************************
* Datas: 
********************************************************************************************/
can_trasnmit_message_struct can0_txd_msg,can1_txd_msg;
can_receive_message_struct  can0_rxd_msg,can1_rxd_msg;


/********************************************************************************************
* Function: 
********************************************************************************************/

void can0_rxdMsg(struct CANMessage* const msg)
{
    can_message_receive(CAN0, CAN_FIFO0, &can0_rxd_msg);
    
    //if(can0_rxd_msg.rx_dlen == msg->len)
    memcpy(msg->data,can0_rxd_msg.rx_data,can0_rxd_msg.rx_dlen);
    
    msg->len = can0_rxd_msg.rx_dlen;
}

void can0_txdMsg(struct CANMessage* const msg)
{
    
    can0_txd_msg.tx_sfid = msg->id;
    memcpy(can0_txd_msg.tx_data,msg->data,msg->len);
    can_message_transmit(CAN0, &can0_txd_msg);
}

void can1_rxdMsg(struct CANMessage* const msg)
{
    can_message_receive(CAN1, CAN_FIFO0, &can1_rxd_msg);
    
    //if(can1_rxd_msg.rx_dlen == msg->len)
    memcpy(msg->data,can1_rxd_msg.rx_data,can1_rxd_msg.rx_dlen);
    
    msg->len = can1_rxd_msg.rx_dlen;
}

void can1_txdMsg(struct CANMessage* const msg)
{
    can1_txd_msg.tx_sfid = msg->id;
    memcpy(can1_txd_msg.tx_data,msg->data,msg->len);
    can_message_transmit(CAN1, &can1_txd_msg);
}


struct _CAN can1={
          .read  = can0_rxdMsg,
          .write = can0_txdMsg,
                 },
            can2={
          .read  = can1_rxdMsg,
          .write = can1_txdMsg,
                 };

/********************************************************************************************
* Function Name  : bsp_can_init
* Description    : CAN初始化
* Input          : uint32_t baud 通信波特率
* Output         : void
* Return         : none
********************************************************************************************/
void bsp_can_init(uint32_t baud)
{
    can_parameter_struct can_parameter;
    
    /* initialize transmit message */
    can_struct_para_init(CAN_TX_MESSAGE_STRUCT, &can0_txd_msg);
    can0_txd_msg.tx_sfid = 0x00;
    can0_txd_msg.tx_efid = 0x00;
    can0_txd_msg.tx_ft = CAN_FT_DATA;
    can0_txd_msg.tx_ff = CAN_FF_STANDARD;
    can0_txd_msg.tx_dlen = 8;
    can_struct_para_init(CAN_TX_MESSAGE_STRUCT, &can1_txd_msg);
    can1_txd_msg.tx_sfid = 0x00;
    can1_txd_msg.tx_efid = 0x00;
    can1_txd_msg.tx_ft = CAN_FT_DATA;
    can1_txd_msg.tx_ff = CAN_FF_STANDARD;
    can1_txd_msg.tx_dlen = 8;
    /* initialize receive message */
    can_struct_para_init(CAN_RX_MESSAGE_STRUCT, &can0_rxd_msg);
    can_struct_para_init(CAN_RX_MESSAGE_STRUCT, &can1_rxd_msg);  
    
    /* enable CAN clock */
    rcu_periph_clock_enable(RCU_CAN0);
    rcu_periph_clock_enable(RCU_CAN1);
    rcu_periph_clock_enable(RCU_GPIOA);
    rcu_periph_clock_enable(RCU_GPIOB);
    rcu_periph_clock_enable(RCU_AF);
    
    /* configure CAN0 GPIO */
    gpio_init(GPIOA,  GPIO_MODE_IPU,GPIO_OSPEED_50MHZ,GPIO_PIN_11);
    gpio_init(GPIOA,GPIO_MODE_AF_PP,GPIO_OSPEED_50MHZ,GPIO_PIN_12);
    
    /* configure CAN1 GPIO */
    gpio_init(GPIOB,   GPIO_MODE_IPU, GPIO_OSPEED_50MHZ, GPIO_PIN_12);
    gpio_init(GPIOB, GPIO_MODE_AF_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_13);
    
    
    can_struct_para_init(CAN_INIT_STRUCT, &can_parameter);
    /* initialize CAN register */
    can_deinit(CAN0);
    can_deinit(CAN1);
    
    /* initialize CAN parameters */
    can_parameter.time_triggered = DISABLE;
    can_parameter.auto_bus_off_recovery = ENABLE;
    can_parameter.auto_wake_up = DISABLE;
    can_parameter.auto_retrans = ENABLE;
    can_parameter.rec_fifo_overwrite = DISABLE;
    can_parameter.trans_fifo_order = DISABLE;
    can_parameter.working_mode = CAN_NORMAL_MODE;//CAN_LOOPBACK_MODE;//
    
    /* initialize CAN */
    can_init(CAN0, &can_parameter);
    can_init(CAN1, &can_parameter);
    
    /* config CAN0 baud rate */
    can_frequency_set(CAN0, baud);
    /* config CAN1 baud rate */
    can_frequency_set(CAN1, baud);
    
    /* initialize filter */ 
    can1_filter_start_bank(14);
    can_filter_mask_mode_init(CAN_ID, CAN_MASK, CAN_STANDARD_FIFO0, 0);
    can_filter_mask_mode_init(CAN_ID, CAN_MASK, CAN_STANDARD_FIFO0, 15);
    
    /* configure CAN0 NVIC */
    nvic_irq_enable(CAN0_RX0_IRQn, ISR_PRIORITY_CAN_REV, 0);
    /* configure CAN1 NVIC */
    nvic_irq_enable(CAN1_RX0_IRQn, ISR_PRIORITY_CAN_REV, 0);
    /* enable can receive FIFO0 not empty interrupt */
    can_interrupt_enable(CAN0, CAN_INTEN_RFNEIE0);
    can_interrupt_enable(CAN1, CAN_INTEN_RFNEIE0);
    
      
    
}

#endif
