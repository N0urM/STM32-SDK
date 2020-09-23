/*******************************************************/ 
/* Author: Nourhan Mansour                             */
/* Date  : 8/8/2020                                    */
/* Vesion: 1.1                                         */
/* File  : RCC_interface.h                             */
/*******************************************************/ 
#ifndef     RCC_INTERFACE_H
#define     RCC_INTERFACE_H

/************** Public Constants ***********************/


/***********AHB Enable Register bits*****************/

#define AHBENR_DMA1EN       0
#define AHBENR_DMA2EN       1
#define AHBENR_SRAMEN       2
#define AHBENR_FLITFEN      4
#define AHBENR_CRCEN        6
#define AHBENR_FSMCEN       8
#define AHBENR_SDIOEN       10

/********** APB2 Enable Register bits *****************/

#define APB2ENR_AFIOEN         0
#define APB2ENR_IOPAEN         2
#define APB2ENR_IOPBEN         3
#define APB2ENR_IOPCEN         4
#define APB2ENR_IOPDEN         5
#define APB2ENR_IOPEEN         6
#define APB2ENR_IOPFEN         7
#define APB2ENR_IOPGEN         8
#define APB2ENR_ADC1EN         9
#define APB2ENR_ADC2EN         10
#define APB2ENR_TIM1EN         11
#define APB2ENR_SPI1EN         12
#define APB2ENR_TIM8EN         13
#define APB2ENR_USART1EN       14
#define APB2ENR_ADC3EN         15
#define APB2ENR_TIM9EN         19
#define APB2ENR_TIM10EN        20
#define APB2ENR_TIM11EN        21

/****************** APB1 Enable Register *****************/

#define APB1ENR_TIM2EN      0
#define APB1ENR_TIM3EN      1
#define APB1ENR_TIM4EN      2
#define APB1ENR_TIM5EN      3
#define APB1ENR_TIM6EN      4
#define APB1ENR_TIM7EN      5
#define APB1ENR_TIM12EN     6
#define APB1ENR_TIM13EN     7
#define APB1ENR_TIM14EN     8
#define APB1ENR_WWDGEN      11
#define APB1ENR_SPI2EN      14
#define APB1ENR_SPI3EN      15
#define APB1ENR_USART2EN    17
#define APB1ENR_USART3EN    18
#define APB1ENR_USART4EN    19
#define APB1ENR_USART5EN    20
#define APB1ENR_I2C1EN      21
#define APB1ENR_I2C2EN      22
#define APB1ENR_USBEN       23
#define APB1ENR_CANEN       25
#define APB1ENR_BKPEN       27
#define APB1ENR_PWREN       28
#define APB1ENR_DACEN       29
/*************************************************************/


/************** Public DataTypes ****************************/
typedef enum {
    t_AHB,
    t_APB1,
    t_APB2,
}BUS_ID;
/*************************************************************/


/************** Public Functions *****************************/

/* 
    System Clock initilaization function
    Select initialization option in the config file
*/
void RCC_voidInitSystemClock();


/* Functions Enable/Disable Clock
    Bus options:
    AHB , APB1 , APB2
*/

void RCC_voidEnableClock(BUS_ID copy_bus_id , u8 copy_prephiral_id );
void RCC_voidDisableClock(BUS_ID copy_bus_id, u8 copy_prephiral_id );

/*************************************************************/

#endif  // End Of File
