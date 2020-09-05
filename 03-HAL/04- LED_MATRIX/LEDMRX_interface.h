/*******************************************************/ 
/* Author : Nourhan Mansour                            */
/* Date   : 5/9/2020                                   */
/* Version: 1.0                                        */
/* File   : LEDMRX_interface.h                         */
/*******************************************************/ 
#ifndef     LEDMRX_INTERFACE_H
#define     LEDMRX_INTERFACE_H

/******************* public functions *************************/

/**************************************************************
 * Function  : LEDMRX_voidInit
 * Parameters: NONE
 * RETURN    : NONE
 * Description: initialize clock and GPIO pin for the LED MATRIX
 *              specified in the config file
 * ***********************************************************/
void LEDMRX_voidInit(void);

/**************************************************************
 * Function   : LEDMRX_voidDisplay
 * Parameters : 
 *          cpy_dis: array of columns to display 
 *          cpy_size: size of the array
 * RETURN     : NONE
 * Description: an infinite loop to Display columns from the 
 *              dis array with delay between shifing specified 
 *              in the config file. 
 * NOTES      : DELAY parameter can be omitted if the array size 
 *              is less than or equal no. of columns        
 * ***********************************************************/
void LEDMRX_voidDisplay(u8 cpy_dis []  , u8 cpy_size);


#endif //End Of File
