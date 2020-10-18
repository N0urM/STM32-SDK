/********************************************************/ 
/* Author : Nourhan Mansour                             */
/* Date   : 13/10/2020                                  */
/* Version: 1.0                                         */
/* File   : FPEC_private.h                              */
/********************************************************/ 
#ifndef FPEC_PRIVATE_H
#define FPEC_PRIVATE_H

#define FPEC         ( (volatile t_FPEC*) 0x40022000 )

typedef struct 
{
    volatile u32 ACR;
    volatile u32 KEYR;
    volatile u32 OPTKEYR;
    volatile u32 SR;
    volatile u32 CR;
    volatile u32 AR;
    volatile u32 OBR;
    volatile u32 WRPR; 
}t_FPEC;


#define FLASH_CR_PG         0
#define FLASH_CR_PER        1
#define FLASH_CR_MER        2
#define FLASH_CR_OPTPG      4
#define FLASH_CR_OPTER      5
#define FLASH_CR_STRT       6
#define FLASH_CR_LOCK       7
#define FLASH_CR_OPTWRE     9
#define FLASH_CR_ERRIE      10
#define FLASH_CR_EOPIE      12

#define FLASH_SR_BSY        0
#define FLASH_SR_PGERR      2
#define FLASH_SR_WRPRTERR   4
#define FLASH_SR_EOP        5


#endif // End Of File
