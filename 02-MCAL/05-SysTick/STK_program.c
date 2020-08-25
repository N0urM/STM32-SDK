/*******************************************************/ 
/* Author: Nourhan Mansour                             */
/* Date  : 23/8/2020                                   */
/* Vesion: 1.0                                         */
/* File  : STK_program.c                               */
/*******************************************************/ 

// 1- include Libraries 
#include "STD_TYPES.h"
#include "BIT_MATH.h"

// 2- include interface file of needed lower layers

// 3- include driver files
#include "STK_interface.h"
#include "STK_private.h"
#include "STK_config.h"

void STK_voidInit(t_STK_CLK cpy_CLK , t_STK_INTERRUPT cpy_interrupt)
{
    switch (cpy_CLK)
    {
    case SYS_CLK:
        SET_BIT(STK -> CTRL , STK_CTRL_CLKSPURCE);      // No prescalar - Use system Clock (AHB clock)
        break;
    case SYS_CLK_DIV8:
        CLR_BIT(STK -> CTRL , STK_CTRL_CLKSPURCE);      // With prescalar - Use system Clock/8 (AHB clock /8)
        break;
    default:
        break;
    }

    switch (cpy_interrupt)
    {
    case STK_INTERRUPT_ENABLE:
        SET_BIT(STK -> CTRL , STK_CTRL_TICKINT);        // Enable interrupt
        break;
    case STK_INTERRUPT_DISABLE:
        CLR_BIT(STK -> CTRL , STK_CTRL_TICKINT);        // Disable interrupt
        break;
    default:
        break;
    }

}
void STK_voidDisableTimer(){
    CLR_BIT(STK -> CTRL , STK_CTRL_ENABLE);             // Stop Timer
}

void STK_voidEnableTimer(){
    SET_BIT(STK -> CTRL , STK_CTRL_ENABLE);

}

void STK_voidCount_ms(u16 cpy_ms , u16 cpy_STK_CLK_MHZ )
{
    u32 loadVal = cpy_ms * ( cpy_STK_CLK_MHZ * 1000 );
    STK-> LOAD = loadVal;
}

void STK_voidCount_us(u32 cpy_us , u16 cpy_STK_CLK_MHZ )
{
    u32 loadVal = cpy_us *  cpy_STK_CLK_MHZ;
    STK-> LOAD = loadVal;  
}


u32  STK_u32ReadTimerValue()
{
    u32 ret = STK -> VAL;
    return ret;
}
