/********************************************************/ 
/* Author : Nourhan Mansour                             */
/* Date   : 12/9/2020                                   */
/* Version: 1.0                                         */
/* File   : DMA_interface.h                             */
/********************************************************/ 
#ifndef DMA_INTERFACE_H
#define DMA_INTERFACE_H


/************** Public Constants **********************/
#define TRANSFER_COMPLETED      0
#define TRANSFER_STARTED        1
#define TRANSFER_ERROR          2
#define TRANSFER_STOPPED        3


/*************** Public Data Types *********************/
typedef enum 
{
    mem_to_mem,             // Source Address is memory address & Destination is Peripheral Address
    mem_to_Prephiral,       // Source Address is memory address & Destination is Peripheral Address
    prephiral_to_mem,       // Source Address is Peripheral address & Destination is memory Address
    prephiral_to_prephiral, // Source Address is memory address & Destination is Peripheral Address
}t_Data_Direction;

typedef enum
{
    low,
    medium, 
    high,
    very_high,

}t_CH_SW_piriority;

typedef enum
{
    Interrupt_Disabled, 
    Interrupt_Enabled,
}t_Transfer_interrupt;

typedef enum {
    bits_8  = 0b00, 
    bits_16 = 0b01, 
    bits_32 = 0b10,
}t_DATA_SIZE;

typedef enum {
    CH1 = 0,
    CH2,
    CH3, 
    CH4, 
    CH5, 
    CH6,
    CH7, 
}t_CH;

typedef struct 
{
    t_CH ch_id;                         // CH1 ~ CH7
    
    /* Memory Increment Mode values*/
    // 1: Increment memory address on each cycle 
    // 0: Don't Incremet memory address
    u8 MEM_INC_MODE;     

    /* Prephiral Increment Mode Values */
    // 1: Increment Prephiral address on each cycle 
    // 0: Don't Incremet Prephiral address
    u8 Peripheral_INC_MODE;

    u16 Block_Length;                   // Max Length of buffer : 65535
    u32 * memory_address;               // Start Address of memory
    u32 * peripheral_address;           // Start address of Prephiral 
    t_DATA_SIZE memory_data_size;       // Size of 1 unit of data
    t_DATA_SIZE peripheral_data_size;   // Size of 1 unit of data
    t_Data_Direction data_direction; 
    t_CH_SW_piriority ch_sw_piriority; 

    /* Transfer interrupt */
    // This value doesn't affect the NVIC Registers 
    // Interrupt must be enabled from NVIC_voidEnableInterrupt
    // Flag of interrupt must be cleared by NVIC_voidClearPendingFlag
    t_Transfer_interrupt transfer_interrupt;

}t_Channel_config;

/*************** Public functions ************************/

/*******************************************************
    Function Name: DMA_voidInit
    Description  : Clear Channels' configurations  
    Parameters   : none
    Return value : none
********************************************************/
void DMA_voidInit(void);

/*******************************************************
    Function Name: DMA_voidConfigChannel
    Description  : Assign values in the configuration struct 
                   to the proper register 
    Parameters   : t_Channel_config
    Return value : none
    Notes        : This function Doesn't start channel 
                   operation
********************************************************/
void DMA_voidConfigChannel(t_Channel_config channel_config );


/*******************************************************
    Function Name: DMA_voidStartChannel
    Description  : Start DMA in free run mode 
    Parameters   : 
                   ch_id         : CH1 - CH7
                   interrupt_func: Only assign if interrupts 
                   enabled, otherwise assign to NULL 
    Return value : none
********************************************************/
void DMA_voidStartChannel(t_CH cpy_ch_id , void (*interrupt_func)(void) );


/*******************************************************
    Function Name: DMA_voidStopChannel
    Description  : Stops DMA operation 
    Parameters   : ch_id : CH1 - CH7 
    Return value : none
********************************************************/
void DMA_voidStopChannel(t_CH cpy_ch_id );

/*******************************************************
    Function Name: DMA_u8ReportStatus
    Description  : Current State of a Channel 
    Parameters   : ch_id : CH1 - CH7 
    Return value : Status:
                    TRANSFER_COMPLETED
                    TRANSFER_ERROR
                    TRANSFER_STARTED
                    TRANSFER_STOPPED
********************************************************/
u8 DMA_u8ReportStatus(t_CH cpy_ch_id );

#endif // End Of File
