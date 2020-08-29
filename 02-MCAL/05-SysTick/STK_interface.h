/*******************************************************/ 
/* Author: Nourhan Mansour                             */
/* Date  : 29/8/2020                                   */
/* Vesion: 2.0                                         */
/* File  : STK_INTERFACE.h                             */
/*******************************************************/ 
#ifndef STK_INTERFACE_H
#define STK_INTERFACE_H

/******************************************************
 Note: The SysTick counter runs on the processor clock. 
 If this clock signal is stopped for low power mode, 
 the SysTick counter stops.
 ******************************************************/


/**************** Functions prototypes ******************/

/*
    Function Name: STK_voidInit
    Description  : initilaze timer clock from config file, disable interrupt and timer
    Parameters   : none
    Return value : none
*/
void STK_voidInit(void);


void STK_voidSetBusyWait(u32 copy_Ticks);

/*
    Function Name: STK_voidSetIntervalSingle
    Description  : Assigns the function to be excuted when Interrupt occurs once after number of ticks 
    Parameters   : 
            copy_ticks  : nu,ber of ticks till next interrupt
            void (*func): pointer to a void function to be excuted when the intterrupt occurs 
    Notes        : This function doesn't halt the processor 
    Return value : none
*/
void STK_voidSetIntervalSingle (u32 copy_ticks , void (*func)(void) );


/*
    Function Name: STK_voidSetIntervalPeriodic
    Description  : Assigns the function to be excuted when Interrupt occurs periodically after number of ticks 
    Parameters   : 
            copy_ticks  : nu,ber of ticks till next interrupt
            void (*func): pointer to a void function to be excuted when the intterrupt occurs 
    Notes        : • This function doesn't halt the processor 
                   • It will excute as long as the timer is not disabled 
    Return value : none
*/
void STK_voidSetIntervalPeriodic(u32 copy_ticks , void (*func)(void) );

/*
    Function Name: STK_voidStopTimer
    Description  : Stop Timer operation
    Parameters   : none
    Return value : none
*/
void STK_voidStopTimer(void);

/*
    Function Name: STK_u32GetElapsedTime
    Description  : Get number of ticks since the timer loaded
    Parameters   : None
    Return value : number of ticks
*/
u32 STK_u32GetElapsedTime(void);

/*
    Function Name: STK_u32GetRemainingTime
    Description  : Get number of ticks remaining till underflow
    Parameters   : None
    Return value : number of ticks
*/
u32 STK_u32GetRemainingTime(void);

/**********************************************************/

#endif // End Of File