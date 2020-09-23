/********************************************************/ 
/* Author : Nourhan Mansour                             */
/* Date   : 21/9/2020                                   */
/* Version: 1.0                                         */
/* File   : UART_program.c                              */
/********************************************************/ 

// 1- include Libraries 
#include "STD_TYPES.h"
#include "BIT_MATH.h"

// 2- include interface file of needed lower layers

// 3- include driver files
#include "UART_interface.h"
#include "UART_private.h"
#include "UART_config.h"

void UART_voidInit()
{
    u8 i = 0 ;
    for (i=0 ; i< MAX_UART_CH ; i++){
        if (user_configuration_t[i].uart_mode == UART_Enable)
        {
            // Baud Rate selection
           	if (user_configuration_t[i].baudrate == BPS_4800){
                UARTx[i] -> BRR  = 0x4143;
            }else if (user_configuration_t[i].baudrate == BPS_9600){
                UARTx[i] -> BRR  = 0x341;
            }else if (user_configuration_t[i].baudrate == BPS_19200){
                UARTx[i] -> BRR  = 0x1A1;
            } else if (user_configuration_t[i].baudrate == BPS_57600){
                UARTx[i] -> BRR  = 0x8B;
            }else if (user_configuration_t[i].baudrate == BPS_11500){
                UARTx[i] -> BRR  = 0x46;
            }

            // Clear configuration bits 
            UARTx[i] -> CR1 = 0 ;

            // Enable TX - RX 
            if (user_configuration_t[i].transmitionMode == TRANSMIT_ONLY){
                SET_BIT(UARTx[i] -> CR1 , USART_CR1_TE);
            }else if (user_configuration_t[i].transmitionMode == RECIEVE_ONLY){
                SET_BIT(UARTx[i] -> CR1 , USART_CR1_RE); 
            }else if (user_configuration_t[i].transmitionMode == TRANSMIT_RECIEVE) {
                SET_BIT(UARTx[i] -> CR1 , USART_CR1_TE);
                SET_BIT(UARTx[i] -> CR1 , USART_CR1_RE);
            }

            // Enable UART
            SET_BIT (UARTx[i] -> CR1 , USART_CR1_UE);

            // Clear Status Register 
            UARTx[i] -> SR = 0 ;
        }
    }    
}

void UART_voidTransmitSync(UART_CH cpy_ch , u8 cpy_arr[] )
{    
    u16 i=0;
    while (cpy_arr[i] != '\0'){
        UARTx[cpy_ch] -> DR =  cpy_arr[i];
        while (GET_BIT (UARTx[cpy_ch] -> SR , USART_SR_TC) == 0);
        CLR_BIT (UARTx[cpy_ch] -> SR , USART_SR_TC);
        i++;
    }
}

u8 UART_u8RecieveSync(UART_CH cpy_ch )
{
    while (GET_BIT (UARTx[cpy_ch] -> SR , USART_SR_RXNE) == 0);
    CLR_BIT(UARTx[cpy_ch] -> SR , USART_SR_RXNE);
    return ( 0xFF & UARTx[cpy_ch] -> DR );
}

