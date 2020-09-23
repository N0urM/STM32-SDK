/********************************************************/ 
/* Author : Nourhan Mansour                             */
/* Date   : 21/9/2020                                   */
/* Version: 1.0                                         */
/* File   : UART_interface.h                            */
/********************************************************/ 
#ifndef UART_INTERFACE_H
#define UART_INTERFACE_H

typedef enum {
    UART1_CH = 0, 
    UART2_CH,
    UART3_CH,
}UART_CH;


/****************** Functions prototypes ********************/

/*************************************************************
    Function Name: UART_voidInit
    Description  : Initialize UART(s) according to config file 
    Parameters   : none
    Return value : none
***************************************************************/
void UART_voidInit();


/*************************************************************
    Function Name: UART_voidTransmitSync
    Description  : Send array of data through UART CH and halts
                   the processor till finish 
    Parameters   : cpy_ch : Specify which UART channel
                   cpy_arr: array of data to transmit
    Return value : none
***************************************************************/

void UART_voidTransmitSync(UART_CH cpy_ch , u8 cpy_arr[] );

/*************************************************************
    Function Name: UART_u8RecieveSync
    Description  : Recieve a char of data through UART CH 
                   halt the processor till Recieve complete 
    Parameters   : cpy_ch : Specify which UART channel
    Return value : byte recieved from UART CH
***************************************************************/
u8 UART_u8RecieveSync(UART_CH cpy_ch);

#endif // End Of File
