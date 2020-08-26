/*******************************************************/ 
/* Author: Nourhan Mansour                             */
/* Date  : 26/8/2020                                   */
/* Vesion: 1.1                                         */
/* File  : STK_PRIVATE.h                               */
/*******************************************************/ 
#ifndef STK_PRIVATE_H
#define STK_PRIVATE_H

/**************** Registers Definition ****************/

typedef struct 
{
    volatile u32 CTRL;
    volatile u32 LOAD;
    volatile u32 VAL;
    volatile u32 CALIB;

}t_STK;

#define STK_BASE_ADDRESS        0xE000E010 
#define STK                     ((t_STK *) STK_BASE_ADDRESS )

 /******************BITS DEFINITONS*********************/

#define STK_CTRL_ENABLE         0
#define STK_CTRL_TICKINT        1
#define STK_CTRL_CLKSPURCE      2
#define STK_CTRL_COUNTFLAG      16

/***************** Private variables ********************/

// pointter to Function callback 
void dummyFunction();
void (*functionCallBack)(void) = dummyFunction;
#endif // End Of File