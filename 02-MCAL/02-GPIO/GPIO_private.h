/******************************************************/ 
/* Author: Nourhan Mansour                            */
/* Date  : 13/8/2020                                  */
/* Vesion: 1.0                                        */
/* File  : GPIO_private.h                             */
/******************************************************/ 
#ifndef     GPIO_PRIVATE_H
#define     GPIO_PRIVATE_H


/*************** Registers definitions ****************/

/*********************** PORT A **********************/
#define GPIOA_CRL           *((u8 *) 0x40010800)
#define GPIOA_CRH           *((u8 *) 0x40010804)
#define GPIOA_IDR           *((u8 *) 0x40010808)
#define GPIOA_ODR           *((u8 *) 0x4001080C)
#define GPIOA_BSRR          *((u8 *) 0x40010810)
#define GPIOA_BRR           *((u8 *) 0x40010814)
#define GPIOA_LCKR          *((u8 *) 0x40010818)

/*********************** PORT B **********************/
#define GPIOB_CRL           *((u8 *) 0x40010C00)
#define GPIOB_CRH           *((u8 *) 0x40010C04)
#define GPIOB_IDR           *((u8 *) 0x40010C08)
#define GPIOB_ODR           *((u8 *) 0x40010C0C)
#define GPIOB_BSRR          *((u8 *) 0x40010C10)
#define GPIOB_BRR           *((u8 *) 0x40010C14)
#define GPIOB_LCKR          *((u8 *) 0x40010C18)

/*********************** PORT C **********************/
#define GPIOC_CRL           *((u8 *) 0x40011000)
#define GPIOC_CRH           *((u8 *) 0x40011004)
#define GPIOC_IDR           *((u8 *) 0x40011008)
#define GPIOC_ODR           *((u8 *) 0x4001100C)
#define GPIOC_BSRR          *((u8 *) 0x40011010)
#define GPIOC_BRR           *((u8 *) 0x40011014)
#define GPIOC_LCKR          *((u8 *) 0x40011018)

#endif  // End Of File
