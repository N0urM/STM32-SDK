/*******************************************************/ 
/* Author: Nourhan Mansour                             */
/* Date  : 14/8/2020                                   */
/* Vesion: 1.0                                         */
/* File  : SSD_program.c                               */
/*******************************************************/ 

// 1- include Libraries 
#include "STD_TYPES.h"
#include "BIT_MATH.h"

// 2- include interface file of needed lower layers
#include "GPIO_interface.h"
#include "RCC_interface.h"

// 3- include driver files
#include "SSD_interface.h"
#include "SSD_private.h"
#include "SSD_config.h"

void SSD_voidInit(t_SSD cpy_SSD){
    switch (cpy_SSD.port)
    {
    case PORTA:
        RCC_voidEnableClock(t_APB2, RCC_APB2ENR_IOPAEN);
        break;
    case PORTB:
        RCC_voidEnableClock(t_APB2, RCC_APB2ENR_IOPBEN);
        break;
    case PORTC:
        RCC_voidEnableClock(t_APB2, RCC_APB2ENR_IOPCEN);
        break;
    default:
        break;
    }

    u8 i = 0;
    GPIO_voidInitPortPinDirection(cpy_SSD.port , cpy_SSD.Control_pin , OUTPUT_PUSH_PULL_10MHZ);
    for(i=cpy_SSD.start_pin ; i <= cpy_SSD.end_pin ; i++)
    {
        GPIO_voidInitPortPinDirection(cpy_SSD.port, i , OUTPUT_PUSH_PULL_10MHZ);
    }
}

void SSD_voidDisplay(t_SSD cpy_SSD , u8 cpy_digit){

    u8 toDisplay = number[cpy_digit];
    switch (cpy_SSD.Type)
    {
    case COMMON_ANODE:
        toDisplay = ~ toDisplay ;
        GPIO_voidSetPortPinValue(cpy_SSD.port, cpy_SSD.Control_pin , 1 );
        break;
    case COMMON_CATHODE:
        GPIO_voidSetPortPinValue(cpy_SSD.port, cpy_SSD.Control_pin , 0 );
        break;
    default:
        break;
    }
    u8 i = 0 , j=0;
    for(i=cpy_SSD.start_pin ; i <= cpy_SSD.end_pin ; i++)
    {
        GPIO_voidSetPortPinValue(cpy_SSD.port, i , (toDisplay >> j) & 0x01 );
        j++;
    }

}
