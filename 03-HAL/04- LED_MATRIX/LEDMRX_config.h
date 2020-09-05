/*******************************************************/ 
/* Author : Nourhan Mansour                            */
/* Date   : 5/9/2020                                   */
/* Version: 1.0                                        */
/* File   : LEDMRX_config.h                            */
/*******************************************************/ 
#ifndef     LEDMRX_CONFIG_H
#define     LEDMRX_CONFIG_H

#define NO_OF_ROWS      8           // Number of rows
#define NO_OF_COLS      5           // Number of columns 

// PORTA = 0
// PORTB = 1
// PORTC = 2
#define ROWS_PORT       0           // PORT Number for rows 
#define COLS_PORT       1           // PORT Number for columns

#define DELAY_ms        100         // Time to delay before sliding columns 

// pins wiring for raws and cols 
const int rows_pins [NO_OF_ROWS] = {2 , 3 , 4 , 5 , 6 , 7 , 8 , 9};
const int cols_pins [NO_OF_COLS] = { 5 , 6 , 7 , 8 , 9};

#endif //End Of File
