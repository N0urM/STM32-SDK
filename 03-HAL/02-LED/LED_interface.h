/*******************************************************/ 
/* Author: Nourhan Mansour                             */
/* Date  : 13/8/2020                                   */
/* Vesion: 1.0                                         */
/* File  : LED_interface.h                             */
/*******************************************************/ 

#ifndef     LED_INTERFACE_H
#define     LED_INTERFACE_H

/******************* public constants *************************/
typedef enum{
    LED_FREQ_2MHZ,   
    LED_FREQ_10MHZ,  
    LED_FREQ_50MHZ,  
}LED_FREQ;

/******************* public functions *************************/

/**************************************************************
 * Function  : LED_voidInitLED
 * Parameters: PORT: A,B,C
 *             Pin : 0~15
 *             Frequency: 2,10,50 MHZ
 * Description: initialize clock and GPIO pin for the LED
 * ***********************************************************/
void LED_voidInitLED(t_PORT cpy_port , t_PIN cpy_pin , LED_FREQ cpy_freq);

void LED_voidTurnOn(t_PORT cpy_port , t_PIN cpy_pin );
void LED_voidTurnOff(t_PORT cpy_port , t_PIN cpy_pin );
void LED_voidToggle(t_PORT cpy_port , t_PIN cpy_pin );

/*************************** Notes ****************************
 * This Driver is dependant on the GPIO driver 
**************************************************************/
#endif  //End of File