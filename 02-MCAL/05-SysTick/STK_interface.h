/*******************************************************/ 
/* Author: Nourhan Mansour                             */
/* Date  : 25/8/2020                                   */
/* Vesion: 1.0                                         */
/* File  : STK_INTERFACE.h                             */
/*******************************************************/ 
#ifndef STK_INTERFACE_H
#define STK_INTERFACE_H

/******************************************************
 Note: The SysTick counter runs on the processor clock. 
 If this clock signal is stopped for low power mode, 
 the SysTick counter stops.
 ******************************************************/

/**************** Public DataTypes *********************/
typedef enum {
    SYS_CLK, 
    SYS_CLK_DIV8,
}t_STK_CLK;

typedef enum {
    STK_INTERRUPT_ENABLE,
    STK_INTERRUPT_DISABLE,

}t_STK_INTERRUPT;
/********************************************************/


/**************** Functions prototypes ******************/

/*
    Function Name: STK_voidInit
    Description  : initilaze timer clock & interrupt
    Parameters   :  
        cpy_CLK: use AHB clock or AHB/8 clock
        cpy_interrupt:  Enable or Disable
    No return
*/
void STK_voidInit(t_STK_CLK cpy_CLK , t_STK_INTERRUPT cpy_interrupt);

/*
    Function Name: STK_voidEnableTimer
    Description  : Start Timer operation
    Parameters   : None
    No return
*/
void STK_voidEnableTimer();

/*
    Function Name: STK_voidDisableTimer
    Description  : Srop Timer operation
    Parameters   : None
    No return
*/
void STK_voidDisableTimer();

/*
    Function Name: STK_u32ReadTimerValue
    Description  : Get current value of the timer
    Parameters   : None
    Return       : Current value
*/
u32  STK_u32ReadTimerValue();

/*
    Function Name: STK_voidCount_ms
    Description  : Set the time of timer underflow flag / interrupt
    Parameters   : 
            cpy_ms: time in ms to wait before flag set 
                    Max delay is ~16 s on 1MHZ clock
            cpy_STK_CLK_MHZ: Clock of the timer operation in MHZ
    No return
*/
void STK_voidCount_ms(u16 cpy_ms , u16 cpy_STK_CLK_MHZ );


/*
    Function Name: STK_voidCount_us
    Description  : Set the time of timer underflow flag / interrupt
    Parameters   : 
            cpy_us: time in us to wait before flag set 
                    Max delay is ~16 s on 1MHZ clock
            cpy_STK_CLK_MHZ: Clock of the timer operation in MHZ
    No return
*/
void STK_voidCount_us(u32 cpy_us , u16 cpy_STK_CLK_MHZ );


#endif // End Of File