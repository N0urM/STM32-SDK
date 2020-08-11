/*******************************************************/ 
/* Author: Nourhan Mansour                             */
/* Date  : 8/8/2020                                    */
/* Vesion: 1.0                                         */
/* File  : RCC_program.c                               */
/*******************************************************/ 

// 1- include Libraries 
#include "STD_TYPES.h"
#include "BIT_MATH.h"

// 2- include interface file of needed lower layers

// 3- include driver files 
#include "RCC_interface.h"
#include "RCC_private.h"
#include "RCC_config.h"


void RCC_voidInitSystemClock(){
   
    #if CLOCK_SRC == HSE_RC
        
        SET_BIT(RCC_CR , RCC_CR_HSEON);             // Enable External clock
        while ( !(RCC_CR & 1<<RCC_CR_HSERDY) );     // Wait till ready
        SET_BIT(RCC_CR , RCC_CR_HSEPYB);            // Enable ByPass 
        
        // Turn on External Clock
        CLR_BIT (RCC_CFGR , RCC_CFGR_SW1);      
        SET_BIT (RCC_CFGR , RCC_CFGR_SW0);

        // Turn on security 
        #if CSSON == 1
            SET_BIT (RCC_CR , RCC_CR_CSSON);
        #endif
    #elif CLOCK_SRC == HSE_XTAL

        SET_BIT(RCC_CR , RCC_CR_HSEON);            // Enable External clock
        while (!(RCC_CR & 1<<RCC_CR_HSERDY) );     // Wait till ready

        CLR_BIT(RCC_CR , RCC_CR_HSEPYB);           // Disbale ByPass
        
        // Turn on External Clock
        CLR_BIT (RCC_CFGR , RCC_CFGR_SW1);      
        SET_BIT (RCC_CFGR , RCC_CFGR_SW0); 

        // Turn on security 
        #if CSSON == 1
            SET_BIT (RCC_CR , RCC_CR_CSSON);
        #endif     

    #elif CLOCK_SRC == HSI
        SET_BIT(RCC_CR , RCC_CR_HSION);             // Enable Internal clock
        while ( !(RCC_CR & 1<<RCC_CR_HSIRDY) );     // Wait till ready
        // Turn on Internal Clock
        CLR_BIT (RCC_CFGR , RCC_CFGR_SW0);      
        CLR_BIT (RCC_CFGR , RCC_CFGR_SW1);
    
        /********** TO DO PLL*****************/

    #elif CLOCK_SRC == PLL

        // init PLL MUL:
        RCC_CFGR |=  ( (PLL_MUL - 2) << RCC_CFGR_PLLMUL0 )
        
        // Check External clock PreScalar & select clock source
        #if PLL_SRC == RCC_PLL_HSE_DIV2
            SET_BIT(RCC_CFGR , RCC_CFGR_PLLXTPRE);  // Enable PreScalar
            SET_BIT(RCC_CFGR , RCC_CFGR_PLLSRC);    // Select External source
        #elif PLL_SRC == RCC_PLL_HSE
            CLR_BIT(RCC_CFGR , RCC_CFGR_PLLXTPRE);  //Disable PreScalar
            SET_BIT(RCC_CFGR , RCC_CFGR_PLLSRC);    // Select External source
        #elif PLL_SRC == RCC_PLL_HSI_DIV2
            CLR_BIT(RCC_CFGR  , RCC_CFGR_PLLSRC);   // Select Internal source
        #endif

        SET_BIT(RCC_CR , RCC_CR_PLLON);        // Enable PLL
        while (RCC_CR & 1<<RCC_CR_PLLRDY);     // Wait till ready    

        // Turn on PLL
        SET_BIT (RCC_CFGR , RCC_CFGR_SW1);
        CLR_BIT (RCC_CFGR , RCC_CFGR_SW0);      
    
    #endif
}

void RCC_voidEnableClock(BUS_ID copy_bus_id , u8 copy_periphiral_id){
    if (copy_periphiral_id <= 31){
        switch (copy_bus_id)
        {
        case AHB:
            SET_BIT(RCC_AHBENR , copy_periphiral_id);
            break;  
        case APB1:
            SET_BIT(RCC_APB1ENR , copy_periphiral_id);
            break;
        case APB2:
            SET_BIT(RCC_APB2ENR , copy_periphiral_id);
            break;
        default:
            break;
        }

    }else {

        /* Return Error */
    }
}


void RCC_voidDisableClock(BUS_ID copy_bus_id , u8 copy_periphiral_id){
    if (copy_periphiral_id <= 31){
        switch (copy_bus_id)
        {
        case AHB:
            CLR_BIT(RCC_AHBENR , copy_periphiral_id);
            break;  
        case APB1:
            CLR_BIT(RCC_APB1ENR , copy_periphiral_id);
            break;
        case APB2:
            CLR_BIT(RCC_APB2ENR , copy_periphiral_id);
            break;
        default:
            break;
        }

    }else {

        /* Return Error */
    }
}