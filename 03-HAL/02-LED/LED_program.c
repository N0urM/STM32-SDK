/*******************************************************/ 
/* Author: Nourhan Mansour                             */
/* Date  : 13/8/2020                                   */
/* Vesion: 1.0                                         */
/* File  : LED_program.c                               */
/*******************************************************/ 

// 1- include Libraries 
#include "STD_TYPES.h"
#include "BIT_MATH.h"

// 2- include interface file of needed lower layers
#include "GPIO_interface.h"
#include "RCC_interface.h"

// 3- include driver files
#include "LED_interface.h"
#include "LED_private.h"
#include "LED_config.h"

void LED_voidInitLED(t_PORT cpy_port , t_PIN cpy_pin  , LED_FREQ cpy_freq){
    switch (cpy_port)
    {
    case PORTA:
        RCC_voidEnableClock(t_APB2 , RCC_APB2ENR_IOPAEN);
        switch (cpy_freq)
        {
        case LED_FREQ_2MHZ:
            GPIO_voidInitPortPinDirection(PORTA , cpy_pin ,  OUTPUT_PUSH_PULL_2MHZ);    
            break;
        case LED_FREQ_10MHZ:
            GPIO_voidInitPortPinDirection(PORTA , cpy_pin ,  OUTPUT_PUSH_PULL_10MHZ);    
            break;
        case LED_FREQ_50MHZ:
            GPIO_voidInitPortPinDirection(PORTA , cpy_pin ,  OUTPUT_PUSH_PULL_50MHZ);    
            break;
        default:
            break;
        }
        break;
    case PORTB:
        RCC_voidEnableClock(t_APB2 , RCC_APB2ENR_IOPBEN);
        switch (cpy_freq)
        {
        case LED_FREQ_2MHZ:
            GPIO_voidInitPortPinDirection(PORTB , cpy_pin ,  OUTPUT_PUSH_PULL_2MHZ);    
            break;
        case LED_FREQ_10MHZ:
            GPIO_voidInitPortPinDirection(PORTB , cpy_pin ,  OUTPUT_PUSH_PULL_10MHZ);    
            break;
        case LED_FREQ_50MHZ:
            GPIO_voidInitPortPinDirection(PORTB , cpy_pin ,  OUTPUT_PUSH_PULL_50MHZ);    
            break;
        default:
            break;
        }
        break;
    case PORTC:
        RCC_voidEnableClock(t_APB2 , RCC_APB2ENR_IOPCEN);
        switch (cpy_freq)
        {
        case LED_FREQ_2MHZ:
            GPIO_voidInitPortPinDirection(PORTC , cpy_pin ,  OUTPUT_PUSH_PULL_2MHZ);    
            break;
        case LED_FREQ_10MHZ:
            GPIO_voidInitPortPinDirection(PORTC , cpy_pin ,  OUTPUT_PUSH_PULL_10MHZ);    
            break;
        case LED_FREQ_50MHZ:
            GPIO_voidInitPortPinDirection(PORTC , cpy_pin ,  OUTPUT_PUSH_PULL_50MHZ);    
            break;
        default:
            break;
        }
        break;
    
    default:
        break;
    }
}

void LED_voidTurnOn(t_PORT cpy_port , t_PIN cpy_pin ){
    #if LED_HIGH == 1
        GPIO_voidSetPortPinValue(cpy_port , cpy_pin , 1);
    #else
        GPIO_voidSetPortPinValue(cpy_port , cpy_pin , 0);
    #endif 
}
void LED_voidTurnOff(t_PORT cpy_port , t_PIN cpy_pin ){
    #if LED_LOW == 0
        GPIO_voidSetPortPinValue(cpy_port , cpy_pin , 0);
    #else 
        GPIO_voidSetPortPinValue(cpy_port , cpy_pin , 1);
    #endif
}
void LED_voidToggle(t_PORT cpy_port , t_PIN cpy_pin ){
     if ( GPIO_u8GetPortPinValue(cpy_port , cpy_pin) == 1){
        GPIO_voidSetPortPinValue(cpy_port , cpy_pin , 0);
    }
    else {
        GPIO_voidSetPortPinValue(cpy_port , cpy_pin , 1);
    }
}
