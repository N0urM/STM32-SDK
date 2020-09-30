/********************************************************/ 
/* Author : Nourhan Mansour                             */
/* Date   : 29/9/2020                                   */
/* Version: 1.0                                         */
/* File   : ESP_program.c                               */
/********************************************************/ 

// 1- include Libraries 
#include "STD_TYPES.h"
#include "BIT_MATH.h"

// 2- include interface file of needed lower layers
#include "UART_interface.h"
#include "STK_interface.h"

// 3- include driver files
#include "ESP_interface.h"
#include "ESP_private.h"
#include "ESP_config.h"


void ESP_voidInit()
{
    volatile u8 localResponse = 0 ;
    // Stop Echo 
    while (localResponse != RETURN_CODE_OK)
    {
    	UART_voidTransmitSync(ESP_UART_CHANNEL ,"ATE0\r\n");
        localResponse = ESP_ValidatedResponse();
    }
    // Set Mode: Station
    localResponse = 0 ;
    while (localResponse != RETURN_CODE_OK)
    {
    	UART_voidTransmitSync(ESP_UART_CHANNEL ,"AT+CWMODE=1\r\n");
        localResponse = ESP_ValidatedResponse();
    }
}

u8 ESP_u8ConnectToNetwork(u8 * SSID , u8 * PASS)
{
    u8 ATCMD [100] = "AT+CWJAP=\"";
    volatile u8 localResponse = 0 ;
    volatile u8 localIdx = 10;
    volatile u8 localTimeout = 0;

    /* Append SSID to AT Command */
    while (*SSID !='\0' && localIdx < 100){
        ATCMD[localIdx ++] = *SSID++;
    }
    /* Append "," after SSID */
    ATCMD[localIdx++] = '\"';
    ATCMD[localIdx++] = ',';     
    ATCMD[localIdx++] = '\"';
    /* Append Password */
    while (*PASS !='\0' && localIdx < 100){
        ATCMD[localIdx ++] = *PASS++;
    }

    /* Finish request with "\r\n */
    ATCMD[localIdx++] = '\"';
    ATCMD[localIdx++] = '\r';
    ATCMD[localIdx++] = '\n';

    /*  Wait for OK response or Timeout*/
    while (localResponse != RETURN_CODE_OK && ++localTimeout < 255)
    {
    	UART_voidTransmitSync(ESP_UART_CHANNEL , ATCMD);
    	localResponse = ESP_ValidatedResponse();
    }
    /*      Return Result     */
    if (localTimeout < 255) 
        return RETURN_CODE_OK;
    else 
        return RETURN_CODE_ERROR;
}

u8 ESP_u8ConnectToServer(u8 * IPAddress , u8 * PortNum)
{
    u8 ATCMD [100] = "AT+CIPSTART=\"TCP\",\"";
    volatile u8 localIdx = 19;
    volatile u8 localResponse = 0;
    volatile u8 localTimeout = 0;

    /*  Append IP addres to the AT Command*/
    while (*IPAddress != '\0' && localIdx < 100){
        ATCMD[localIdx++] = *IPAddress++;
    }

    /* Finish IP address section " */
    ATCMD[localIdx++] = '\"';
    /* Comma before port number */
    ATCMD[localIdx++] = ',';

    /*  append port Num     */
    while (*PortNum != '\0' && localIdx < 100)
    {
        ATCMD[localIdx++] = *PortNum++;
    }

    /*  Finish Request  */
    ATCMD[localIdx++] = '\r';
    ATCMD[localIdx++] = '\n';

    /*  Wait for OK response or Timeout*/
    while (localResponse != RETURN_CODE_OK && ++localTimeout < 255)
    {
    	UART_voidTransmitSync(ESP_UART_CHANNEL , ATCMD);
        localResponse = ESP_ValidatedResponse();
    }

    /*   Return Result   */
    if (localTimeout < 255) 
        return RETURN_CODE_OK;
    else 
        return RETURN_CODE_ERROR;
}

u8 ESP_u8SendGetRequest(u8 * GET_Request)
{
    volatile u8 GetRequestLen = sizeof(GET_Request) / sizeof(u8);
    volatile u8 LinkLen = GetRequestLen - 4 ;        // subtract "GET "
    volatile u8 ch = (LinkLen/10) + '0';
    volatile u8 localResponse = 0; 
    volatile u8 localTimeout = 0;
    volatile u8 ATCMD[20] = "AT+CIPSEND=";
    
    /* append reguest length  & finish request*/
    ATCMD[11]=ch;
    ch = (LinkLen%10) + '0';
    ATCMD[12]=ch;
    ATCMD[13] = '\r';
    ATCMD[14] = '\n';
    
     /*  Wait for OK response or Timeout*/
    while (localResponse != RETURN_CODE_OK && ++localTimeout < 255)
    {
    	UART_voidTransmitSync(ESP_UART_CHANNEL , ATCMD);
        localResponse = ESP_ValidatedResponse();
    }

    /*   Return Result   */
    if (localTimeout < 255) 
        return RETURN_CODE_OK;
    else 
        return RETURN_CODE_ERROR;

}

static u8 ESP_ValidatedResponse(){
    volatile u8 localReceived [100] = {0};
    volatile u8 idx = 0 , counter = 0 ; 
    volatile u8 localu8Received = 0;

    while (localu8Received != 255 && idx < 100)
    {
    	STK_voidSetBusyWait(100);
    	localu8Received = UART_u8RecieveSync(ESP_UART_CHANNEL);
        localReceived[idx++] = localu8Received;
    }

    while(counter<idx-1)
    {
        if (localReceived [counter] == 'O' && localReceived[counter+1] == 'K')
        {
           return  RETURN_CODE_OK;
        }
        counter++;
    }
    return RETURN_CODE_ERROR;
}
