/********************************************************/ 
/* Author : Nourhan Mansour                             */
/* Date   : 12/9/2020                                   */
/* Version: 1.0                                         */
/* File   : DMA_program.c                               */
/********************************************************/ 

// 1- include Libraries 
#include "STD_TYPES.h"
#include "BIT_MATH.h"

// 2- include interface file of needed lower layers

// 3- include driver files
#include "DMA_interface.h"
#include "DMA_private.h"
#include "DMA_config.h"


void DMA_voidInit(void){
    u8 i = 0; 
    for (i=0 ; i<7 ; i++){
        DMA ->DMA_CH[i].CCR = 0;
    }
}
void DMA_voidConfigChannel(t_Channel_config channel_config )
{    
    // Disable channel to Start configuration
        DMA ->DMA_CH[channel_config.ch_id].CCR = 0;

    // Source memory Address: Holds address to data to be transfered 
        DMA -> DMA_CH [channel_config.ch_id].CMAR = channel_config.memory_address;
    
    // Destination memory Address: Holds address to transfer data to 
        DMA -> DMA_CH [channel_config.ch_id].CPAR = channel_config.peripheral_address;
    
    // Data Direction : 
        switch (channel_config.data_direction)
        {
        case mem_to_mem:
            SET_BIT( DMA -> DMA_CH [channel_config.ch_id].CCR  , DMA_CCRx_M2M);     // Enable Memory to Memory
            SET_BIT( DMA -> DMA_CH [channel_config.ch_id].CCR  , DMA_CCRx_DIR);     // Read from memory Reg
            break;
        case mem_to_Prephiral:
            CLR_BIT( DMA -> DMA_CH [channel_config.ch_id].CCR  , DMA_CCRx_M2M);     // Disable Memory to Memory
            SET_BIT( DMA -> DMA_CH [channel_config.ch_id].CCR  , DMA_CCRx_DIR);     // Read from memory Reg
            break;
        case prephiral_to_mem:
            CLR_BIT( DMA -> DMA_CH [channel_config.ch_id].CCR  , DMA_CCRx_M2M);     // Disable Memory to Memory
            CLR_BIT( DMA -> DMA_CH [channel_config.ch_id].CCR  , DMA_CCRx_DIR);     // Read from Peripheral Reg
            break;
        case prephiral_to_prephiral:
            CLR_BIT( DMA -> DMA_CH [channel_config.ch_id].CCR  , DMA_CCRx_M2M);     // Disable Memory to Memory
            SET_BIT( DMA -> DMA_CH [channel_config.ch_id].CCR  , DMA_CCRx_DIR);     // Read from memory Reg
            break;
        default:
            break;
        }
    // Data Size to read for one transfer 
        // memory
        DMA -> DMA_CH [channel_config.ch_id].CCR &= ~(0b11 << DMA_CCRx_MSIZE0);      // Clear Old value
        DMA -> DMA_CH [channel_config.ch_id].CCR |= ( channel_config.memory_data_size << DMA_CCRx_MSIZE0 );
        
        // Peripheral
        DMA -> DMA_CH [channel_config.ch_id].CCR &= ~(0b11 << DMA_CCRx_PSIZE0);      // Clear Old value
        DMA -> DMA_CH [channel_config.ch_id].CCR |= ( channel_config.peripheral_data_size << DMA_CCRx_PSIZE0 );
        
    // Block Length Assign
        DMA -> DMA_CH [channel_config.ch_id].CNDTR = channel_config.Block_Length;

    // Memory Increment : MINC - PINC 
        if (channel_config.MEM_INC_MODE == 1)
            SET_BIT ( DMA -> DMA_CH [channel_config.ch_id].CCR , DMA_CCRx_MINC );
        else 
            CLR_BIT ( DMA -> DMA_CH [channel_config.ch_id].CCR , DMA_CCRx_MINC );

        if (channel_config.Peripheral_INC_MODE == 1)
            SET_BIT ( DMA -> DMA_CH [channel_config.ch_id].CCR , DMA_CCRx_PINC );
        else 
            CLR_BIT ( DMA -> DMA_CH [channel_config.ch_id].CCR , DMA_CCRx_PINC );

    // No circular 
        CLR_BIT ( DMA -> DMA_CH [channel_config.ch_id].CCR , DMA_CCRx_CIRC );

    // Interrupts Enable / Disable 
    switch (channel_config.transfer_interrupt)
    {
    
    case Interrupt_Enabled:
        SET_BIT ( DMA -> DMA_CH [channel_config.ch_id].CCR , DMA_CCRx_TCIE);
        SET_BIT ( DMA -> DMA_CH [channel_config.ch_id].CCR , DMA_CCRx_TEIE);
        break;
    
    case Interrupt_Disabled:
        CLR_BIT ( DMA -> DMA_CH [channel_config.ch_id].CCR , DMA_CCRx_TCIE);
        CLR_BIT ( DMA -> DMA_CH [channel_config.ch_id].CCR , DMA_CCRx_TEIE);
        break;
    default:
        break;
    }
    // Channel Trigger Source 
        // Configured in peripheral driver

    // Channel Priority
      DMA -> DMA_CH [channel_config.ch_id].CCR &= ~(0b11 << DMA_CCRx_PL0);      // Clear Old value
      DMA -> DMA_CH [channel_config.ch_id].CCR |= ( channel_config.ch_sw_piriority << DMA_CCRx_PL0 );
}


void DMA_voidStartChannel(t_CH cpy_ch_id , void (*interrupt_func)(void) )
{
    SET_BIT ( DMA ->DMA_CH[cpy_ch_id].CCR , DMA_CCRx_EN );
    DMA_functionCallBack[cpy_ch_id] = interrupt_func;
    CHANNEL_STATUS[cpy_ch_id] = TRANSFER_STARTED;
}

void DMA_voidStopChannel(t_CH cpy_ch_id )
{
    CLR_BIT ( DMA ->DMA_CH[cpy_ch_id].CCR , DMA_CCRx_EN );
    CHANNEL_STATUS[cpy_ch_id] = TRANSFER_STOPPED;
}
u8 DMA_u8ReportStatus(t_CH cpy_ch_id )
{
    return CHANNEL_STATUS[cpy_ch_id];
}

/*** interrupt handler **/
void DMA1_Channel1_IRQHandler(void)
{
    
    if ( GET_BIT(DMA -> ISR , DMA_ISR_TCIF1 )  == 1)        // Transfer Completed Flag
    {
        SET_BIT (DMA -> IFCR , DMA_IFCR_CTCF1);             // Clear TC flag
        CHANNEL_STATUS[0] = TRANSFER_COMPLETED;
    }
    else if ( GET_BIT(DMA -> ISR , DMA_ISR_TEIF1 )  == 1 )  // Transfer Error Flag
    {
        SET_BIT (DMA -> IFCR , DMA_IFCR_CTEF1);             // Clear TE flag
        CHANNEL_STATUS[0] = TRANSFER_ERROR;
    }
    SET_BIT (DMA -> IFCR , DMA_IFCR_CGIF1);                 // Clear Global interrupt Flag 
    DMA_functionCallBack[0] ();                             // Excute User Function
}

void DMA1_Channel2_IRQHandler(void)
{
    
    if ( GET_BIT(DMA -> ISR , DMA_ISR_TCIF2 )  == 1)        // Transfer Completed Flag
    {
        SET_BIT (DMA -> IFCR , DMA_IFCR_CTCF2);             // Clear TC flag
        CHANNEL_STATUS[1] = TRANSFER_COMPLETED;
    }
    else if ( GET_BIT(DMA -> ISR , DMA_ISR_TEIF2 )  == 1 )  // Transfer Error Flag
    {
        SET_BIT (DMA -> IFCR , DMA_IFCR_CTEF2);             // Clear TE flag
        CHANNEL_STATUS[1] = TRANSFER_ERROR;
    }
    SET_BIT (DMA -> IFCR , DMA_IFCR_CGIF2);                 // Clear Global interrupt Flag 
    DMA_functionCallBack[1] ();                             // Excute User Function
}

void DMA1_Channel3_IRQHandler(void){

    if ( GET_BIT(DMA -> ISR , DMA_ISR_TCIF3 )  == 1)        // Transfer Completed Flag
    {
        SET_BIT (DMA -> IFCR , DMA_IFCR_CTCF3);             // Clear TC flag
        CHANNEL_STATUS[2] = TRANSFER_COMPLETED;
    }
    else if ( GET_BIT(DMA -> ISR , DMA_ISR_TEIF3 )  == 1 )  // Transfer Error Flag
    {
        SET_BIT (DMA -> IFCR , DMA_IFCR_CTEF3);             // Clear TE flag
        CHANNEL_STATUS[2] = TRANSFER_ERROR;
    }
    SET_BIT (DMA -> IFCR , DMA_IFCR_CGIF3);                 // Clear Global interrupt Flag 
    DMA_functionCallBack[2] ();                             // Excute User Function
}

void DMA1_Channel4_IRQHandler(void){
    
    if ( GET_BIT(DMA -> ISR , DMA_ISR_TCIF4 )  == 1)        // Transfer Completed Flag
    {
        SET_BIT (DMA -> IFCR , DMA_IFCR_CTCF4);             // Clear TC flag
        CHANNEL_STATUS[3] = TRANSFER_COMPLETED;
    }
    else if ( GET_BIT(DMA -> ISR , DMA_ISR_TEIF4 )  == 1 )  // Transfer Error Flag
    {
        SET_BIT (DMA -> IFCR , DMA_IFCR_CTEF4);             // Clear TE flag
        CHANNEL_STATUS[3] = TRANSFER_ERROR;
    }
    SET_BIT (DMA -> IFCR , DMA_IFCR_CGIF4);                 // Clear Global interrupt Flag 
    DMA_functionCallBack[3] ();                             // Excute User Function
}

void DMA1_Channel5_IRQHandler(void){

     if ( GET_BIT(DMA -> ISR , DMA_ISR_TCIF5 )  == 1)       // Transfer Completed Flag
    {
        SET_BIT (DMA -> IFCR , DMA_IFCR_CTCF5);             // Clear TC flag
        CHANNEL_STATUS[4] = TRANSFER_COMPLETED;
    }
    else if ( GET_BIT(DMA -> ISR , DMA_ISR_TEIF5 )  == 1 )  // Transfer Error Flag
    {
        SET_BIT (DMA -> IFCR , DMA_IFCR_CTEF5);             // Clear TE flag
        CHANNEL_STATUS[4] = TRANSFER_ERROR;
    }
    SET_BIT (DMA -> IFCR , DMA_IFCR_CGIF5);                 // Clear Global interrupt Flag 
    DMA_functionCallBack[4] ();                             // Excute User Function
}


void DMA1_Channel6_IRQHandler(void)
{
    
    if ( GET_BIT(DMA -> ISR , DMA_ISR_TCIF6 )  == 1)        // Transfer Completed Flag
    {
        SET_BIT (DMA -> IFCR , DMA_IFCR_CTCF6);             // Clear TC flag
        CHANNEL_STATUS[5] = TRANSFER_COMPLETED;
    }
    else if ( GET_BIT(DMA -> ISR , DMA_ISR_TEIF6 )  == 1 )  // Transfer Error Flag
    {
        SET_BIT (DMA -> IFCR , DMA_IFCR_CTEF6);             // Clear TE flag
        CHANNEL_STATUS[5] = TRANSFER_ERROR;
    }
    SET_BIT (DMA -> IFCR , DMA_IFCR_CGIF6);                 // Clear Global interrupt Flag 
    DMA_functionCallBack[5] ();                             // Excute User Function
}

void DMA1_Channel7_IRQHandler(void){

    if ( GET_BIT(DMA -> ISR , DMA_ISR_TCIF7 )  == 1)        // Transfer Completed Flag
    {
        SET_BIT (DMA -> IFCR , DMA_IFCR_CTCF7);             // Clear TC flag
        CHANNEL_STATUS[6] = TRANSFER_COMPLETED;
    }
    else if ( GET_BIT(DMA -> ISR , DMA_ISR_TEIF7 )  == 1 )  // Transfer Error Flag
    {
        SET_BIT (DMA -> IFCR , DMA_IFCR_CTEF7);             // Clear TE flag
        CHANNEL_STATUS[6] = TRANSFER_ERROR;
    }
    SET_BIT (DMA -> IFCR , DMA_IFCR_CGIF7);                 // Clear Global interrupt Flag 
    DMA_functionCallBack[6] ();                             // Excute User Function
}