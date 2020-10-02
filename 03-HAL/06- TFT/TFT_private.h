/*******************************************************/ 
/* Author : Nourhan Mansour                            */
/* Date   : 27/9/2020                                  */
/* Version: 1.0                                        */
/* File   : TFT_private.h                              */
/*******************************************************/ 
#ifndef     TFT_PRIVATE_H
#define     TFT_PRIVATE_H


/*** TFT COMMANDS **/

#define TFT_CMD_SLPIN       0x10
#define TFT_CMD_SLPOUT      0x11
#define TFT_CMD_DISPOFF     0x28
#define TFT_CMD_DISPON      0x29
#define TFT_CMD_COLORMODE   0x3A


static void TFT_voidWriteCommand(u8 cpy_Command);
static void TFT_voidWriteData(u8 cpy_Data);
static void TFT_voidSet_X_Y(u8 x1 , u8 x2 , u8 y1 , u8 y2);
static void TFT_voidWriteWord(u16 copy_Word);

#endif //End Of File
