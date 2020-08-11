/******************************************************/ 
/* Author: Nourhan Mansour                            */
/* Date  : 8/8/2020                                   */
/* Vesion: 1.0                                        */
/* File  : RCC_private.h                              */
/******************************************************/ 
#ifndef     RCC_PRIVATE_H
#define     RCC_PRIVATE_H

// Buses types
typedef enum {
    AHB, 
    APB1,
    APB2,
}BUS_ID;

/*************** Registers definitions ****************/
#define  RCC_CR             *((volatile u32) 0x40021000)
#define  RCC_CFGR           *((volatile u32) 0x40021004)
#define  RCC_CIR            *((volatile u32) 0x40021008)
#define  RCC_APB2RSTR       *((volatile u32) 0x4002100c)
#define  RCC_APB1RSTR       *((volatile u32) 0x40021010)
#define  RCC_AHBENR         *((volatile u32) 0x40021014)
#define  RCC_APB2ENR        *((volatile u32) 0x40021018)
#define  RCC_APB1ENR        *((volatile u32) 0x4002101c)
#define  RCC_BDCR           *((volatile u32) 0x40021020)
#define  RCC_CSR            *((volatile u32) 0x40021024)
#define  RCC_AHBSTR         *((volatile u32) 0x40021028)


// Clock source definitions 
#define HSI         0
#define HSE_RC      1
#define HSE_XTAL    2
#define PLL         3

// PLL options 
#define RCC_PLL_HSI_DIV2    0
#define RCC_PLL_HSE_DIV2    1
#define RCC_PLL_HSE         2

/************* bits naming ***************************/


/************* Clock Control Register ****************/
#define RCC_CR_HSION    0
#define RCC_CR_HSIRDY   1

#define RCC_CR_HSITRIM0 3
#define RCC_CR_HSITRIM1 4
#define RCC_CR_HSITRIM2 5
#define RCC_CR_HSITRIM3 6
#define RCC_CR_HSITRIM4 7

#define RCC_CR_HSICAL0  8
#define RCC_CR_HSICAL1  9
#define RCC_CR_HSICAL2  10
#define RCC_CR_HSICAL3  11
#define RCC_CR_HSICAL4  12
#define RCC_CR_HSICAL5  13
#define RCC_CR_HSICAL6  14
#define RCC_CR_HSICAL7  15

#define RCC_CR_HSEON    16
#define RCC_CR_HSERDY   17
#define RCC_CR_HSEPYB   18
#define RCC_CR_CSSON    19

#define RCC_CR_PLLON    24
#define RCC_CR_PLLRDY   25

#define RCC_CR_PLL2ON   26
#define RCC_CR_PLL2RDY  27

#define RCC_CR_PLL3ON   28
#define RCC_CR_PLL3RDY  29


/************* Clock Configuration Register *************/
#define RCC_CFGR_SW0     0
#define RCC_CFGR_SW1     1   

#define RCC_CFGR_SWS0    2
#define RCC_CFGR_SWS1    3

#define RCC_CFGR_HPRE0   4
#define RCC_CFGR_HPRE1   5
#define RCC_CFGR_HPRE2   6
#define RCC_CFGR_HPRE3   7

#define RCC_CFGR_PPRE10  8
#define RCC_CFGR_PPRE11  9
#define RCC_CFGR_PPRE12  10

#define RCC_CFGR_PPRE20  11
#define RCC_CFGR_PPRE21  12
#define RCC_CFGR_PPRE22  13

#define RCC_CFGR_ADCPRE0 14
#define RCC_CFGR_ADCPRE1 15


#define RCC_CFGR_PLLSRC   16
#define RCC_CFGR_PLLXTPRE 17


#define RCC_CFGR_PLLMUL0 18
#define RCC_CFGR_PLLMUL0 19
#define RCC_CFGR_PLLMUL0 20
#define RCC_CFGR_PLLMUL0 21

#define RCC_CFGR_OTGFSPRE 22

#define RCC_CFGR_MCO0   24
#define RCC_CFGR_MCO1   25
#define RCC_CFGR_MCO2   26
#define RCC_CFGR_MCO3   27
/****************** AHB Enable Register *****************/

#define RCC_AHBENR_DMA1EN       0
#define RCC_AHBENR_DMA2EN       1
#define RCC_AHBENR_SRAMEN       2
#define RCC_AHBENR_FLITFEN      4
#define RCC_AHBENR_CRCEN        6
#define RCC_AHBENR_FSMCEN       8
#define RCC_AHBENR_SDIOEN       10

/****************** APB2 Enable Register *****************/

#define RCC_APB2ENR_AFIOEN         0
#define RCC_APB2ENR_IOPAEN         2 
#define RCC_APB2ENR_IOPBEN         3 
#define RCC_APB2ENR_IOPCEN         4 
#define RCC_APB2ENR_IOPDEN         5 
#define RCC_APB2ENR_IOPEEN         6 
#define RCC_APB2ENR_IOPFEN         7 
#define RCC_APB2ENR_IOPGEN         8
#define RCC_APB2ENR_ADC1EN         9
#define RCC_APB2ENR_ADC2EN         10 
#define RCC_APB2ENR_TIM1EN         11
#define RCC_APB2ENR_SPI1EN         12
#define RCC_APB2ENR_TIM8EN         13
#define RCC_APB2ENR_USART1EN       14
#define RCC_APB2ENR_ADC3EN         15 
#define RCC_APB2ENR_TIM9EN         19
#define RCC_APB2ENR_TIM10EN        20
#define RCC_APB2ENR_TIM11EN        21

/****************** APB1 Enable Register *****************/

#define RCC_APB1ENR_TIM2EN      0
#define RCC_APB1ENR_TIM3EN      1
#define RCC_APB1ENR_TIM4EN      2
#define RCC_APB1ENR_TIM5EN      3
#define RCC_APB1ENR_TIM6EN      4
#define RCC_APB1ENR_TIM7EN      5
#define RCC_APB1ENR_TIM12EN     6
#define RCC_APB1ENR_TIM13EN     7
#define RCC_APB1ENR_TIM14EN     8
#define RCC_APB1ENR_WWDGEN      11
#define RCC_APB1ENR_SPI2EN      14
#define RCC_APB1ENR_SPI3EN      15
#define RCC_APB1ENR_USART2EN    17
#define RCC_APB1ENR_USART3EN    18
#define RCC_APB1ENR_USART4EN    19
#define RCC_APB1ENR_USART5EN    20
#define RCC_APB1ENR_I2C1EN      21
#define RCC_APB1ENR_I2C2EN      22
#define RCC_APB1ENR_USBEN       23
#define RCC_APB1ENR_CANEN       25
#define RCC_APB1ENR_BKPEN       27
#define RCC_APB1ENR_PWREN       28
#define RCC_APB1ENR_DACEN       29

/*************************************************************/

#endif  // Enf Of File
