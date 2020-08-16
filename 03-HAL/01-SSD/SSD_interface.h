/*******************************************************/ 
/* Author: Nourhan Mansour                             */
/* Date  : 14/8/2020                                   */
/* Vesion: 1.0                                         */
/* File  : SSD_interface.h                             */
/*******************************************************/ 
#ifndef     SSD_INTERFACE_H
#define     SSD_INTERFACE_H

/******************* public Constants *************************/


/******************* public dataTypes *************************/
typedef enum{
    COMMON_ANODE,
    COMMON_CATHODE,
}t_SSD_TYPE;

typedef struct
{
    t_SSD_TYPE Type;
    t_PORT port; 
    t_PIN start_pin;
    t_PIN end_pin; 
    t_PIN Control_pin;
}t_SSD;

/******************* public functions *************************/
void SSD_voidInit(t_SSD cpy_SSD);
void SSD_voidDisplay (t_SSD cpy_SSD , u8 cpy_digit);

#endif
