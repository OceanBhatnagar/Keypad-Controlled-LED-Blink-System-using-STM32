

#include <stdint.h>


void delay(void){
	for(int i=0;i<300000;i++);
}
int main(void)
{
    /* Loop forever */
	uint32_t volatile *const RCC=(uint32_t*)0x40023830;
	uint32_t volatile *const GPIOA_MODE=(uint32_t*)0x40020000;
	uint32_t volatile *const GPIOB_MODE=(uint32_t*)0x40020400;

	uint32_t volatile *const IDRA=(uint32_t*)0x40020010;
	uint32_t volatile *const ODR_B=(uint32_t*)0x40020414;
	uint32_t volatile *const GPIOA_PULLUP=(uint32_t*)0x4002000C;
	uint32_t volatile *const GPIOB_PULLUP=(uint32_t*)0x4002040C;
    uint32_t volatile *const ODR_A=(uint32_t*)0x40020014;


    //RESET AND CLOCK CONTROL
	*RCC=*RCC | (1<<0);
	*RCC=*RCC | (1<<1);

	//CLEARING
    //KEYPAD
	*GPIOB_MODE=*GPIOB_MODE & ~(1<<12);
	*GPIOB_MODE=*GPIOB_MODE & ~(1<<13);

	*GPIOB_MODE=*GPIOB_MODE & ~(1<<18);
	*GPIOB_MODE=*GPIOB_MODE & ~(1<<19);

	*GPIOB_MODE=*GPIOB_MODE & ~(1<<10);
	*GPIOB_MODE=*GPIOB_MODE & ~(1<<11);

	*GPIOB_MODE=*GPIOB_MODE & ~(1<<20);
	*GPIOB_MODE=*GPIOB_MODE & ~(1<<21);
	//LED
	*GPIOA_MODE=*GPIOA_MODE & ~(1<<18);
	*GPIOA_MODE=*GPIOA_MODE & ~(1<<19);

	*GPIOA_MODE=*GPIOA_MODE & ~(1<<10);
	*GPIOA_MODE=*GPIOA_MODE & ~(1<<11);

	*GPIOA_MODE=*GPIOA_MODE & ~(1<<12);
	*GPIOA_MODE=*GPIOA_MODE & ~(1<<13);

	*GPIOA_MODE=*GPIOA_MODE & ~(1<<14);
	*GPIOA_MODE=*GPIOA_MODE & ~(1<<15);

	*GPIOA_MODE=*GPIOA_MODE & ~(1<<20);
	*GPIOA_MODE=*GPIOA_MODE & ~(1<<21);
	//Setting OUTPUT MODE
    //KEYPAD
	*GPIOB_MODE=*GPIOB_MODE | (1<<12);
	*GPIOB_MODE=*GPIOB_MODE | (1<<18);
	*GPIOB_MODE=*GPIOB_MODE | (1<<10);
	*GPIOB_MODE=*GPIOB_MODE | (1<<20);
	//LED
	*GPIOA_MODE=*GPIOA_MODE | (1<<18);
	*GPIOA_MODE=*GPIOA_MODE | (1<<10);
	*GPIOA_MODE=*GPIOA_MODE | (1<<12);
	*GPIOA_MODE=*GPIOA_MODE | (1<<14);
	*GPIOA_MODE=*GPIOA_MODE | (1<<20);

	//SETTING INPUT MODE
	*GPIOA_MODE=*GPIOA_MODE & ~(1<<0);
	*GPIOA_MODE=*GPIOA_MODE & ~(1<<1);

	*GPIOA_MODE=*GPIOA_MODE & ~(1<<2);
	*GPIOA_MODE=*GPIOA_MODE & ~(1<<3);

	*GPIOA_MODE=*GPIOA_MODE & ~(1<<8);
	*GPIOA_MODE=*GPIOA_MODE & ~(1<<9);

	*GPIOB_MODE=*GPIOB_MODE & ~(1<<0);
	*GPIOB_MODE=*GPIOB_MODE & ~(1<<1);

	//SETTING PULL UP RESISTOR FOR COLUMN I/0
	*GPIOA_PULLUP=*GPIOA_PULLUP | (1<<0);
	*GPIOA_PULLUP=*GPIOA_PULLUP | (1<<2);
	*GPIOA_PULLUP=*GPIOA_PULLUP | (1<<8);
	*GPIOB_PULLUP=*GPIOB_PULLUP | (1<<0);

    while(1){
    	//MAKE ALL ROW HIGH
    	*ODR_B=*ODR_B | (1<<10);
    	*ODR_B=*ODR_B | (1<<9);
    	*ODR_B=*ODR_B | (1<<5);
    	*ODR_B=*ODR_B | (1<<6);

    	//MAKE R1 LOW
    	*ODR_B=*ODR_B & ~(1<<10);
    	if(!(*IDRA & (1<<0))){
    		delay();
    		*ODR_A=*ODR_A | (1<<9);         //1 LED ON
    		for(int i=0;i<600000;i++);
    		*ODR_A=*ODR_A & ~(1<<9);
    	}

    	 if(!(*IDRA & (1<<1))){           //2 LED ON
    		            delay();
    		            *ODR_A=*ODR_A | (1<<9);
    		            *ODR_A=*ODR_A | (1<<5);
    		    		for(int i=0;i<600000;i++);
    		    		*ODR_A=*ODR_A & ~(1<<9);
    		    		*ODR_A=*ODR_A & ~(1<<5);
    	}

    	 if(!(*IDRA & (1<<4))){          //3 LED ON
    		delay();
    		                        *ODR_A=*ODR_A | (1<<9);
    		    		            *ODR_A=*ODR_A | (1<<5);
    		    		            *ODR_A=*ODR_A | (1<<10);
    		    		    		for(int i=0;i<600000;i++);
    		    		    		*ODR_A=*ODR_A & ~(1<<9);
    		    		    		*ODR_A=*ODR_A & ~(1<<5);
    		    		    		*ODR_A=*ODR_A & ~(1<<10);
    	    	}

    	//Make R2 LOW
    	*ODR_B=*ODR_B & ~(1<<9);
    	//4 LED ON
        if(!(*IDRA & (1<<0))){
    	    		   delay();
    	    		           *ODR_A=*ODR_A | (1<<9);
    	    		           *ODR_A=*ODR_A | (1<<5);
    	    		           *ODR_A=*ODR_A | (1<<10);
    	    		           *ODR_A=*ODR_A | (1<<7);
    	    		      	   for(int i=0;i<600000;i++);
    	    		      	   *ODR_A=*ODR_A & ~(1<<9);
    	    		      	   *ODR_A=*ODR_A & ~(1<<5);
    	    		           *ODR_A=*ODR_A & ~(1<<10);
    	    		           *ODR_A=*ODR_A & ~(1<<7);
    	            	}
        //5 LED ON
         if(!(*IDRA & (1<<1))){
    	    	    	delay();
    	    	    	 *ODR_A=*ODR_A | (1<<9);
    	    	    	 *ODR_A=*ODR_A | (1<<5);
    	    	    	 *ODR_A=*ODR_A | (1<<10);
    	    	    	 *ODR_A=*ODR_A | (1<<7);
    	    	    	  *ODR_A=*ODR_A | (1<<6);
    	    	    	 for(int i=0;i<600000;i++);
    	    	    	 *ODR_A=*ODR_A & ~(1<<9);
    	    	    	 *ODR_A=*ODR_A & ~(1<<5);
    	    	    	 *ODR_A=*ODR_A & ~(1<<10);
    	    	    	 *ODR_A=*ODR_A & ~(1<<7);
    	    	    	 *ODR_A=*ODR_A & ~(1<<6);
    	    	    	}

//ALL THE LED OFF
                   *ODR_B=*ODR_B & ~(1<<6);

               	    if(!(*IDRA & (1<<0))){
               	    	    	   delay();
               	    	    	   *ODR_A=*ODR_A & ~(1<<9);
               	    	           *ODR_A=*ODR_A & ~(1<<5);
               	    	    	   *ODR_A=*ODR_A & ~(1<<10);
               	    	    	   *ODR_A=*ODR_A & ~(1<<7);
               	    	    	   *ODR_A=*ODR_A & ~(1<<6);
               	    	    }
 }
}

