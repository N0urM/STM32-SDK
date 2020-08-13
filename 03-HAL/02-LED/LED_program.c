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

// 3- include driver files
#include "LED_interface.h"
#include "LED_private.h"
#include "LED_config.h"


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
