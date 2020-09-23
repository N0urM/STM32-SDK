/********************************************************/ 
/* Author : Nourhan Mansour                             */
/* Date   : 5/9/2020                                    */
/* Version: 1.0                                         */
/* File   : LEDMRX_program.c                            */
/********************************************************/ 

// 1- include Libraries 
#include "STD_TYPES.h"
#include "BIT_MATH.h"

// 2- include interface file of needed lower layers
#include "GPIO_interface.h"
#include "RCC_interface.h"
#include "STK_interface.h"

// 3- include driver files
#include "LEDMRX_interface.h"
#include "LEDMRX_private.h"
#include "LEDMRX_config.h"

void LEDMRX_voidInit(void)
{
    // Enable clock 
    #if ROWS_PORT == 0
        RCC_voidEnableClock(t_APB2, APB2ENR_IOPAEN);
    #elif ROWS_PORT == 1
        RCC_voidEnableClock(t_APB2, APB2ENR_IOPBEN);
    #elif ROWS_PORT == 2
        RCC_voidEnableClock(t_APB2, APB2ENR_IOPCEN); 
    #endif

    #if COLS_PORT == 0
        RCC_voidEnableClock(t_APB2, APB2ENR_IOPAEN);
    #elif COLS_PORT == 1
        RCC_voidEnableClock(t_APB2, APB2ENR_IOPBEN);
    #elif COLS_PORT == 2
        RCC_voidEnableClock(t_APB2, APB2ENR_IOPCEN);
    #endif


    // init GPIO
    u8 x = 0;
    for (x = 0 ; x < NO_OF_ROWS ; x++)
    {
        GPIO_voidInitPortPinDirection(ROWS_PORT ,  rows_pins[x] , OUTPUT_PUSH_PULL_2MHZ);
    }

    x = 0;
    for (x = 0 ; x < NO_OF_COLS ; x++)
    {
        GPIO_voidInitPortPinDirection(COLS_PORT , cols_pins[x] , OUTPUT_PUSH_PULL_2MHZ);
    }

    // init SysTick
    STK_voidInit();
}


void LEDMRX_voidDisplay(u8 cpy_dis [] , u8 cpy_size)
{
    u8 x = 0;                   // loop counter
    u8 local_bitValue = 0 ;    
    u8 local_colNum = 0 ;
    u8 local_offset = 0;
    u16 local_timeCounter = 0;
    u16 local_FPS = (1000 / (NO_OF_COLS * 50 ) );   
    u16 local_msWait = local_FPS * 1000;       // SYSTick initialized with 1MHZ clock, ms = ticks * 1000 

    while (1)
    {

        // Clear all columns 
        for (x = 0 ; x < NO_OF_COLS ; x++)
        {
            GPIO_voidSetPortPinValue(COLS_PORT ,  cols_pins[x] , ROW_VOLT );
        }

        // Set new value for ROWS
        for (x = 0 ; x < NO_OF_ROWS ; x++)
        {
              local_bitValue = GET_BIT(cpy_dis[local_colNum+ local_offset] , x);
              #if ROW_VOLT == 1
                GPIO_voidSetPortPinValue(ROWS_PORT ,  rows_pins[x] , local_bitValue );
              #elif ROW_VOLT == 0 
               GPIO_voidSetPortPinValue(ROWS_PORT ,  rows_pins[x] , ~local_bitValue );
              #endif
        }     
        // set Col value
        GPIO_voidSetPortPinValue(COLS_PORT ,  cols_pins[local_colNum] , COL_VOLT );
        
        // Set Delay
        STK_voidSetBusyWait(local_msWait);

        // Switch column    
        if(++local_colNum > NO_OF_COLS )local_colNum = 0;

        // wait for desired delay then shift columns 
        if(++local_timeCounter > ( DELAY_ms / local_FPS)  )
        {
            if ( (++local_offset + local_colNum ) > cpy_size) local_offset = 0;
            local_timeCounter = 0;
        }

    }
}
