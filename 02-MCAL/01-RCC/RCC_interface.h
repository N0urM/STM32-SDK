/*******************************************************/ 
/* Author: Nourhan Mansour                             */
/* Date  : 8/8/2020                                    */
/* Vesion: 1.0                                         */
/* File  : RCC_interface.h                             */
/*******************************************************/ 
#ifndef     RCC_INTERFACE_H
#define     RCC_INTERFACE_H



typedef enum {
    t_AHB,
    t_APB1,
    t_APB2,
}BUS_ID;

// Select init option in the config file
void RCC_voidInitSystemClock();

/* Bus options:
    AHB , APB1 , APB2
*/


/* Pripheral Naming:
    AHB bus: 
    RCC_AHBENR_DMA1EN       
    RCC_AHBENR_DMA2EN       
    RCC_AHBENR_SRAMEN       
    RCC_AHBENR_FLITFEN      
    RCC_AHBENR_CRCEN        
    RCC_AHBENR_FSMCEN       
    RCC_AHBENR_SDIOEN       

    APB2 bus:
   RCC_APB2ENR_AFIOEN         
   RCC_APB2ENR_IOPAEN         
   RCC_APB2ENR_IOPBEN          
   RCC_APB2ENR_IOPCEN          
   RCC_APB2ENR_IOPDEN          
   RCC_APB2ENR_IOPEEN          
   RCC_APB2ENR_IOPFEN          
   RCC_APB2ENR_IOPGEN         
   RCC_APB2ENR_ADC1EN         
   RCC_APB2ENR_ADC2EN          
   RCC_APB2ENR_TIM1EN         
   RCC_APB2ENR_SPI1EN         
   RCC_APB2ENR_TIM8EN         
   RCC_APB2ENR_USART1EN       
   RCC_APB2ENR_ADC3EN          
   RCC_APB2ENR_TIM9EN         
   RCC_APB2ENR_TIM10EN        
   RCC_APB2ENR_TIM11EN        


    APB1 bus:
    
    RCC_APB1ENR_TIM2EN      
    RCC_APB1ENR_TIM3EN      
    RCC_APB1ENR_TIM4EN      
    RCC_APB1ENR_TIM5EN      
    RCC_APB1ENR_TIM6EN      
    RCC_APB1ENR_TIM7EN      
    RCC_APB1ENR_TIM12EN     
    RCC_APB1ENR_TIM13EN     
    RCC_APB1ENR_TIM14EN     
    RCC_APB1ENR_WWDGEN      
    RCC_APB1ENR_SPI2EN      
    RCC_APB1ENR_SPI3EN      
    RCC_APB1ENR_USART2EN    
    RCC_APB1ENR_USART3EN    
    RCC_APB1ENR_USART4EN    
    RCC_APB1ENR_USART5EN    
    RCC_APB1ENR_I2C1EN      
    RCC_APB1ENR_I2C2EN      
    RCC_APB1ENR_USBEN       
    RCC_APB1ENR_CANEN       
    RCC_APB1ENR_BKPEN       
    RCC_APB1ENR_PWREN       
    RCC_APB1ENR_DACEN       
*/
void RCC_voidEnableClock(BUS_ID copy_bus_id , u8 copy_prephiral_id );
void RCC_voidDisableClock(BUS_ID , u8 );


#endif  // End Of File
