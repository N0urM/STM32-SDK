/*******************************************************/ 
/* Author: Nourhan Mansour                             */
/* Date  : 20/8/2020                                   */
/* Vesion: 2.0                                         */
/* File  : GPIO_program.c                              */
/*******************************************************/ 

// 1- include Libraries 
#include "STD_TYPES.h"
#include "BIT_MATH.h"

// 2- include interface file of needed lower layers

// 3- include driver files
#include "GPIO_interface.h"
#include "GPIO_private.h"
#include "GPIO_config.h"


void GPIO_voidInitPortPinDirection(t_PORT cpy_port , t_PIN cpy_pin  ,t_MODE mode){
    switch (cpy_port)
    {
    case PORTA:
        
        if (cpy_pin < 8){
            GPIOA_CRL &= ~ ( (0b1111)<< ( cpy_pin * 4 ) );      // Clear configuration bits
            GPIOA_CRL |= (mode << ( cpy_pin * 4 ) );            // Set configuration
        }else {
            GPIOA_CRH &= ~ ( (0b1111)<< ( (cpy_pin-8) * 4 ) );  // Clear configuration bits
            GPIOA_CRH |= (mode << ( (cpy_pin-8) * 4 ) );        // Set configuration    
        }

        if (mode == INPUT_PULL_UP_DOWN){
			#if PULL_TYPE == 1
                SET_BIT(GPIOA_BSRR , cpy_pin);                  // Activate internal pull up
        	#else
         	    SET_BIT(GPIOA_BRR , cpy_pin);                   // Activate internal pull down
         	#endif
        }
        break;
    case PORTB:
    
        
        if (cpy_pin < 8){
            GPIOB_CRL &= ~ ( (0b1111)<< ( cpy_pin * 4 ) );      // Clear configuration bits
            GPIOB_CRL |= (mode << ( cpy_pin * 4 ) );            // Set configuration
        }else {
            GPIOB_CRH &= ~ ( (0b1111)<< ( (cpy_pin-8) * 4 ) );  // Clear configuration bits
            GPIOB_CRH |= (mode << ( (cpy_pin-8) * 4 ) );        // Set configuration    
        }
        if (mode == INPUT_PULL_UP_DOWN){
        	#if PULL_TYPE == 1
                SET_BIT(GPIOB_BSRR , cpy_pin);                  // Activate internal pull up
        	#else
        	    SET_BIT(GPIOB_BRR , cpy_pin);                   // Activate internal pull down
        	#endif
         }
        break;
    case PORTC:
        
        if (cpy_pin < 8){
            GPIOC_CRL &= ~ ( (0b1111)<< ( cpy_pin * 4 ) );      // Clear configuration bits
            GPIOC_CRL |= (mode << ( cpy_pin * 4 ) );            // Set configuration
        }else {
            GPIOC_CRH &= ~ ( (0b1111)<< ( (cpy_pin-8) * 4 ) );  // Clear configuration bits
            GPIOC_CRH |= (mode << ( (cpy_pin-8) * 4 ) );        // Set configuration    
        }
        
        if (mode == INPUT_PULL_UP_DOWN){
        	#if PULL_TYPE == 1
                SET_BIT(GPIOC_BSRR , cpy_pin);                   // Activate internal pull up
        	#else
                SET_BIT(GPIOC_BRR , cpy_pin);                    // Activate internal pull down
            #endif
         }
        break;
    default:
        /*Shouldn't be here 
            Retun error
        */
        break;
    }    
}

void GPIO_voidInitPortDirection (t_PORT cpy_port , t_MODE mode){
	u8 pins_num = 0 ;
	switch (cpy_port)
    {
    case PORTA:

        GPIOA_CRL = 0;                                          // Clear configuration bits
        GPIOA_CRH = 0;                                          // Clear configuration bits
        pins_num =  0;
        /*  Initialize all port pins to the selected mode*/
        for(pins_num = 0 ; pins_num < 8; pins_num ++){          
             GPIOA_CRL |= (mode << ( pins_num * 4 ) );      
        }
        for(pins_num = 0 ; pins_num < 8; pins_num ++){
             GPIOA_CRH |= (mode << ( pins_num * 4 ) );
        }
        
        if (mode == INPUT_PULL_UP_DOWN){
    		#if PULL_TYPE == 1
         		GPIOA_BSRR = 0xFF;                       // Activate internal pull up
   			#else
        		GPIOA_BRR  = 0xFF;                       // Activate internal pull down
        	#endif
         }
        break;

    case PORTB:

        GPIOB_CRL = 0;
        GPIOB_CRH = 0;
        pins_num = 0 ;
        /*  Initialize all port pins to the selected mode*/
        for(pins_num = 0 ; pins_num < 8; pins_num ++){
             GPIOB_CRL |= (mode << ( pins_num * 4 ) );
        }
        for(pins_num = 0 ; pins_num < 8; pins_num ++){
             GPIOB_CRH |= (mode << ( pins_num * 4 ) );
        }

        if (mode == INPUT_PULL_UP_DOWN){
        	#if PULL_TYPE == 1
        		GPIOB_BSRR = 0xFF;                          // Activate internal pull up
        	#else
          		GPIOB_BRR  = 0xFF;                          // Activate internal pull down
          	#endif
              
        }
        break;
    
    case PORTC:
        
        GPIOC_CRL = 0;
        GPIOC_CRH = 0;
        pins_num = 0 ;
        /*  Initialize all port pins to the selected mode*/
        for(pins_num = 0 ; pins_num < 8; pins_num ++){
             GPIOC_CRL |= (mode << ( pins_num * 4 ) );
        }
        for(pins_num = 0 ; pins_num < 8; pins_num ++){
             GPIOC_CRH |= (mode << ( pins_num * 4 ) );
        }

        if (mode == INPUT_PULL_UP_DOWN){
        	#if PULL_TYPE == 1
            	GPIOC_BSRR = 0xFF;                          // Activate internal pull up
        	#else
                GPIOC_BRR  = 0xFF;                          // Activate internal pull down
            #endif
        }
        break;
    default:
        break;
    }

}
void GPIO_voidSetPortPinValue(t_PORT cpy_port , t_PIN cpy_pin , u8 cpy_value){
    switch (cpy_port)
    {
    case PORTA:
        if(cpy_value == 0){
            SET_BIT(GPIOA_BRR , cpy_pin);                   // Reset Pin
        }else { 
            SET_BIT(GPIOA_BSRR , cpy_pin);                  // Set Pin
        }
        break;
    case PORTB:
        if(cpy_value == 0){
           SET_BIT(GPIOB_BRR  , cpy_pin);                    // Reset pin
        }else { 
           SET_BIT(GPIOB_BSRR , cpy_pin);                    // Set pin
        }
        break;
    case PORTC:
        if(cpy_value == 0){
           SET_BIT(GPIOC_BRR  , cpy_pin);                   // Reset Pin
        }else {
           SET_BIT(GPIOC_BSRR , cpy_pin);                   // Set Pin
        }
        break;    
    default:
        break;
    }
}

void GPIO_voidSetPortValue(t_PORT cpy_port , u16 cpy_value){
    /* Set the value of the output data register */
    switch (cpy_port)
    {
    case PORTA:
        GPIOA_ODR = cpy_value;
        break;
    case PORTB:
        GPIOB_ODR = cpy_value;
        break;
    case PORTC:
        GPIOC_ODR = cpy_value;
        break;
    default:
        break;
    }
}


u8 GPIO_u8GetPortPinValue(t_PORT cpy_port , t_PIN cpy_pin){
    /* Get the pin value from the input data register */
    u8 retValue = 0;
    switch (cpy_port)
    {
    case PORTA:
        retValue = GET_BIT(GPIOA_IDR , cpy_pin);
        break;
    case PORTB:
        retValue = GET_BIT(GPIOB_IDR , cpy_pin);
        break;
    case PORTC:
        retValue = GET_BIT(GPIOC_IDR , cpy_pin);
        break;    
    default:
        break;
    }
    return retValue;
}

u16 GPIO_u16GetPortValue(t_PORT cpy_port){
    /* Get the value of the input data register */
     u16 retValue = 0;
    switch (cpy_port)
    {
    case PORTA:
        retValue = (GPIOA_IDR);
        break;
    case PORTB:
        retValue = (GPIOB_IDR);
        break;
    case PORTC:
        retValue = (GPIOC_IDR);
        break;    
    default:
        break;
    }
    return retValue;
}

void EnableLockOnPortPin(t_PORT port ,t_PIN pin){
	u32 tmp = 0x00010000;
	tmp |=  (1 << pin);
	switch (port)
    {
    case PORTA:
    	// Initiate Lock sequence
    	GPIOA_LCKR = tmp;
    	/* Reset LCKK bit */
    	GPIOA_LCKR =  (1 << pin);
    	/* Set LCKK bit */
    	GPIOA_LCKR = tmp;
    	/* Read LCKK bit*/
     	tmp = GPIOA_LCKR;
      	/* Read LCKK bit*/
       	tmp = GPIOA_LCKR;

    	break;
    case PORTB:
    	// Initiate Lock sequence
    	GPIOB_LCKR = tmp;
    	/* Reset LCKK bit */
    	GPIOB_LCKR =  (1 << pin);
    	/* Set LCKK bit */
    	GPIOB_LCKR = tmp;
    	/* Read LCKK bit*/
    	tmp = GPIOB_LCKR;
    	/* Read LCKK bit*/
    	tmp = GPIOB_LCKR;
        break;
    case PORTC:
    	// Initiate Lock sequence
    	GPIOC_LCKR = tmp;
    	/* Reset LCKK bit */
      	GPIOC_LCKR =  (1 << pin);
     	/* Set LCKK bit */
       	GPIOC_LCKR = tmp;
      	/* Read LCKK bit*/
       	tmp = GPIOC_LCKR;
       	/* Read LCKK bit*/
     	tmp = GPIOC_LCKR;
    	break;

    default:
        break;
    }
}

