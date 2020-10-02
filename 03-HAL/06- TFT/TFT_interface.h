/*******************************************************/ 
/* Author : Nourhan Mansour                            */
/* Date   : 27/9/2020                                  */
/* Version: 1.0                                        */
/* File   : TFT_interface.h                            */
/*******************************************************/ 
#ifndef     TFT_INTERFACE_H
#define     TFT_INTERFACE_H

/* TFT - SPI Configurations: 
    CPOL = 1
    CPHA = 1
    MSB FIRST 
*/   
void TFT_voidInit();

/* Pass an an image as an array */
void TFT_voidDisplayImage(const u16 * cpy_ptr_img);

/* Color Value between 0x0000 and 0xFFFF*/
void TFT_voidFillColor (u16 copy_FillColor);

/* Make sure x1 < x2 & y1 < y2 & values within range of TFT Size*/
void TFT_voidDrawRect (u8 x1 , u8 x2 , u8 y1 , u8 y2 , u16 copy_FillColor);

#endif //End Of File