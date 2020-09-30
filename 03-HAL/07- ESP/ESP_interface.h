/*******************************************************/ 
/* Author : Nourhan Mansour                            */
/* Date   : 29/9/2020                                  */
/* Version: 1.0                                        */
/* File   : ESP_INTERFACE.h                            */
/*******************************************************/ 
#ifndef     ESP_INTERFACE_H
#define     ESP_INTERFACE_H

/******************* public constants *************************/
#define RETURN_CODE_ERROR   0
#define RETURN_CODE_OK      1


/******************* public functions *************************/

/**************************************************************
 * Function  : ESP_voidInit
 * Parameters: NONE
 * RETURN    : NONE
 * Description: Initialize ESP in Station mode using UART CH
 *              specified in the config channel 
 * Notes      : UART Channel must be initialized with 
 *              BaudRate = 115200
 * ***********************************************************/
void ESP_voidInit();


/**************************************************************
 * Function  : ESP_u8ConnectToNetwork
 * Parameters: SSID & PASS of the network to connect
 * RETURN    : RETURN_CODE_ERROR or RETURN_CODE_OK
 * Description: Connect ESP to a network using AT commands 
 * Notes      : UART Channel must be initialized with 
 *              BaudRate = 115200
 * ***********************************************************/
u8 ESP_u8ConnectToNetwork(u8 * SSID , u8 * PASS);

/**************************************************************
 * Function  : ESP_u8ConnectToServer
 * Parameters: IP & portNum of server to connect
 * RETURN    : RETURN_CODE_ERROR or RETURN_CODE_OK
 * Description: Connect ESP to an IP address using AT commands 
 * Notes      : UART Channel must be initialized with 
 *              BaudRate = 115200
 * ***********************************************************/
u8 ESP_u8ConnectToServer(u8 * IPAddress , u8 * PortNum);


/**************************************************************
 * Function  : ESP_u8SendGetRequest
 * Parameters: GET_Request: The full Get request string 
 * Example   : GET http://aniot.orgfree.com/status.txt
 * RETURN    : RETURN_CODE_ERROR or RETURN_CODE_OK
 * Description: Send a get request to the connected server  
 * Notes      : UART Channel must be initialized with 
 *              BaudRate = 115200
 *              ESP_u8ConnectToServer function must be used first
 * ***********************************************************/
u8 ESP_u8SendGetRequest(u8 * GET_Request);

#endif //End Of File