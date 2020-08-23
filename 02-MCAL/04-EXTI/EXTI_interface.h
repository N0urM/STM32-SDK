/*******************************************************/ 
/* Author: Nourhan Mansour                             */
/* Date  : 23/8/2020                                   */
/* Vesion: 1.0                                         */
/* File  : EXTI_interface.h                            */
/*******************************************************/ 
#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

typedef enum{
    FALLING_EDGE, 
    RISING_EDGE,
    ON_CHANGE,
}t_EDGE;

/*
    Function Name: EXTI_voidEnableExternalInterrupt
    Description  : Enable External interrupt on line: cpy_line with Edge: cpy_Edge_Selection
    Parameters   :  
        cpy_line: 0 - 18
        cpy_Edge_Selection: Falling, rising, on_change  
    No return
*/
void EXTI_voidEnableExternalInterrupt (u8 cpy_line  , t_EDGE cpy_Edge_Selection);

/*
    Function Name: EXTI_voidDisableExternalInterrupt
    Description  : Disable External interrupt on line: cpy_line 
    Parameters   :  
        cpy_line: 0 - 18
    No return
*/
void EXTI_voidDisableExternalInterrupt(u8 cpy_line);


/*
    Function Name: EXTI_voidSetSoftwareInterrupt
    Description  : Set pending flag for interrupt on line: cpy_line
    Parameters   :  
        cpy_line: 0 - 18
    No return
*/
void EXTI_voidSetSoftwareInterrupt (u8 cpy_line);

/*
    Function Name: EXTI_voidClearInterruptSignal
    Description  : Clear pending flag for interrupt on line: cpy_line
    Parameters   :  
        cpy_line: 0 - 18
    No return
*/
void EXTI_voidClearInterruptSignal (u8 cpy_line);


#endif // End Of File