/*******************************************************/ 
/* Author: Nourhan Mansour                             */
/* Date  : 13/8/2020                                   */
/* Vesion: 1.0                                         */
/* File  : LED_interface.h                             */
/*******************************************************/ 

#ifndef     LED_INTERFACE_H
#define     LED_INTERFACE_H

/******************* public constants *************************/


/******************* public functions *************************/
void LED_voidTurnOn(t_PORT cpy_port , t_PIN cpy_pin );
void LED_voidTurnOff(t_PORT cpy_port , t_PIN cpy_pin );
void LED_voidToggle(t_PORT cpy_port , t_PIN cpy_pin );

/*************************** Notes ****************************
 * This Driver is dependant on the GPIO driver 
**************************************************************/
#endif  //End of File