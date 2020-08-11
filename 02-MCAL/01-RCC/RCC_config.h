/*******************************************************/ 
/* Author: Nourhan Mansour                             */
/* Date  : 8/8/2020                                    */
/* Vesion: 1.0                                         */
/* File  : RCC_config.h                                */
/*******************************************************/ 
#ifndef     RCC_CONFIG_H
#define     RCC_CONFIG_H


/* Clock Source
    HSI         
    HSE_RC      
    HSE_XTAL    
    PLL      
*/   
#define CLOCK_SRC   PLL

#if CLOCK_SRC == PLL
    /* Options: 
        RCC_PLL_HSI_DIV2
        RCC_PLL_HSE_DIV2
        RCC_PLL_HSE
    */
    #define PLL_SRC     RCC_PLL_HSI_DIV2

    /* Choose multiplier
        integer value:  2 ~ 16 
        Warning: result clock MUST NOT exceed 72MHZ
    */
    #define PLL_MUL     2
#endif

#if CLOCK_SRC == HSE_RC ||  CLOCK_SRC == HSE_XTAL 
    /**
     * Choose to 1 enable Security , 0 to diable 
    */
    #define CSSON   0 
#endif

#endif  // Enf Of File
