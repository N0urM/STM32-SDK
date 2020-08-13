/*******************************************************/ 
/* Author: Nourhan Mansour                             */
/* Date  : 13/8/2020                                   */
/* Vesion: 1.0                                         */
/* File  : GPIO_interface.h                            */
/*******************************************************/ 
#ifndef     GPIO_INTERFACE_H
#define     GPIO_INTERFACE_H

/*********** Pulbic data types *************/
typedef enum {
    PORTA,
    PORTB,
    PORTC,
}t_PORT;

typedef enum{
    PIN0,
    PIN1,
    PIN2,
    PIN3,
    PIN4,
    PIN5,
    PIN6,
    PIN7,
    PIN8,
    PIN9,
    PIN10,
    PIN11,
    PIN12,
    PIN13,
    PIN14,
    PIN15,
}t_PIN;

/******************* public constants *************************/
// GPIO MODES definitions
// Used with GPIO_voidInitPortPinDirection() function

#define INPUT_ANALOG                0b0000
#define INPUT_FLOATING              0b0100
#define INPUT_PULL_DOWN_UP          0b1000
    
#define OUTPUT_PUSH_PULL_10MHZ      0b0001
#define OUTPUT_OPEN_DRAIN_10MHZ     0b0101
#define AF_PUSH_PULL_10MHZ          0b1001
#define AF_OPEN_DRAIN_10MHZ         0b1101

#define OUTPUT_PUSH_PULL_50MHZ      0b0011
#define OUTPUT_OPEN_DRAIN_50MHZ     0b0111
#define AF_PUSH_PULL_50MHZ          0b1011
#define AF_OPEN_DRAIN_50MHZ         0b1111

#define OUTPUT_PUSH_PULL_2MHZ       0b0010
#define OUTPUT_OPEN_DRAIN_2MHZ      0b0110
#define AF_PUSH_PULL_2MHZ           0b1010
#define AF_OPEN_DRAIN_2MHZ          0b1110

/******************* public functions *************************/

/*
    Function Name: GPIO_voidInitPortPinDirection
    Description  : initializa a GPIO pin direction and mode
    Parameters   :  
        port: PORTA,PORTB,PORTC
        pin : 0-15
        mode: input/output definitions 
    No return
*/
void GPIO_voidInitPortPinDirection(t_PORT cpy_port , t_PIN cpy_pin  ,u8 mode);


/*
    Function Name: GPIO_voidInitPortDirection
    Description  : initializa a GPIO port direction and mode
    Parameters   :  
        port: PORTA,PORTB,PORTC
        mode: input/output definitions 
    No return

*/
void GPIO_voidInitPortDirection (t_PORT cpy_port , u8 mode);

/*
    Function Name: GPIO_voidSetPortPinValue
    Description  : set a GPIO pin value to 1 or 0
    Parameters   :  
        port   : PORTA,PORTB,PORTC
        pin    : 0-15
        value  : 1 / 0
    No return
*/
void GPIO_voidSetPortPinValue(t_PORT cpy_port , t_PIN cpy_pin , u8 cpy_value);


/*
    Function Name: GPIO_voidSetPortValue
    Description  : set a GPIO port value 0 - 0XFF
    Parameters   :  
        port   : PORTA, PORTB, PORTC
        value  : 0 ~ 0xFF
    No return
*/
void GPIO_voidSetPortValue(t_PORT cpy_port , u16 cpy_value);


/*
    Function Name: GPIO_u8GetPortPinValue
    Description  : Get a GPIO pin value 1 or 0
    Parameters   :  
        port   : PORTA,PORTB,PORTC
        pin    : 0-15
    Return  :  pin value 0 or 1
*/
u8 GPIO_u8GetPortPinValue(t_PORT cpy_port , t_PIN cpy_pin);

/*
    Function Name: GPIO_u8GetPortValue
    Description  : Get a GPIO port value  0 ~ 0xFF
    Parameters   :  
            port   : PORTA,PORTB,PORTC
    Return  :  port value 
*/
u16 GPIO_u8GetPortValue(t_PORT cpy_port);

/***********************************************************/

#endif  // End Of File
