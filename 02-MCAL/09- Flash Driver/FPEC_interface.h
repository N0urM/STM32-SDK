/********************************************************/ 
/* Author : Nourhan Mansour                             */
/* Date   : 13/10/2020                                  */
/* Version: 1.0                                         */
/* File   : FPEC_interface.h                            */
/********************************************************/ 
#ifndef FPEC_INTERFACE_H
#define FPEC_INTERFACE_H

/****************** Functions prototypes ********************/

/*************************************************************
    Function Name: FPEC_voidInit
    Description  : Initialize Flash memory to enable data write
    Parameters   : none
    Return value : none
***************************************************************/
void FPEC_voidInit();

/*************************************************************
    Function Name: FPEC_voidWriteData
    Description  : Assign data to a specific address
    Parameters   : cpy_address: start address of data to write
                   cpy_data   : array of data to send  
                   cpy_length : array length 
    Return value : none
***************************************************************/
void FPEC_voidWriteData ( u16 * cpy_address , u16 * cpy_data , u8 cpy_length);

/*************************************************************
    Function Name: FPEC_voidEraseDataPage
    Description  : Reset a page to initial state of all ones 
    Parameters   : cpy_page: pageNo to erase 
                             Page size = 1k 
                             Max No of pages in stm10x = 64
    Return value : none
***************************************************************/
void FPEC_voidEraseDataPage (u32 cpy_page);

/*************************************************************
    Function Name: FPEC_voidEraseDataPage
    Description  : Specify a range of pages to clear 
    Parameters   : cpy_startPage: Start pageNo to erase 
                   cpy_endPage  : Final pageNo to erase        
    Return value : none
    Notes        : •Page size = 1k 
                   •Max No of pages in stm10x = 64
                   •Start page must be less than end page
***************************************************************/
void FPEC_voidEraseRange(u8 cpy_startPage , u8 cpy_endPage);

/*************************************************************
    Function Name: FPEC_voidEraseAllFlash
    Description  : Clear Flash Memory 
    Parameters   : none
    Return value : none
***************************************************************/
void FPEC_voidEraseAllFlash();

#endif // End Of File
