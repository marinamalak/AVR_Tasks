/*
 * main.c
 *
 *  Created on: Aug 11, 2023
 *      Author: Admin
 */

#include "STDTYPE.h"
#include "REGISTER.h"
#include <util/delay.h>
int
main(void){
	 u8 segcthd[]= {0x3f,0x06,0x5b,
			        0x4f,0x66,0x6d,
				    0x7d,0x07,0x7f,
	                0x6f};

u8 button1 ,button2;

   DDRC=0xff;
   DDRA &=~(1<<0);
   DDRA &=~(1<<3);
   DDRD |=(1<<1); // common of 1st 7segment
   DDRD |=(1<<2); // common of 2nd 7segment
   PORTC=0;
   PORTA |=(1<<0);
   PORTA |=(1<<3);
   PORTD |=(1<<1);
   PORTD |=(1<<2);




    while(1){

    	  button1=((PINA >>0)&1);
    	  button2=((PINA >>3)&1);

  	  PORTD |=(1<<2); //disable for 2nd 7segment
  	  PORTC=segcthd[5];
  	  PORTD &=~(1<<1); //enable for 1st 7segment
  	  _delay_ms(10);

  	  PORTD |=(1<<1); //disable for 1st 7segment
  	  PORTC=segcthd[0];
  	  PORTD &=~(1<<2); //enable for 2nd 7segment
  	  _delay_ms(10);

  	 if(button1 ==0)
  	 {
  	  	  PORTD |=(1<<2); //disable for 2nd 7segment
  	  	  PORTC=segcthd[5];
  	  	  PORTD &=~(1<<1); //enable for 1st 7segment
  	  	  _delay_ms(10);

  	  	  PORTD |=(1<<1); //disable for 1st 7segment
  	  	  PORTC=segcthd[1];
  	  	  PORTD &=~(1<<2); //enable for 2nd 7segment
  	  	  _delay_ms(10);
  	  }
  	 else if(button2 ==0)
  	  {
  	  	  PORTD |=(1<<2); //disable for 2nd 7segment
  	  	  PORTC=segcthd[4];
  	  	  PORTD &=~(1<<1); //enable for 1st 7segment
  	  	  _delay_ms(10);

  	  	  PORTD |=(1<<1); //disable for 1st 7segment
  	  	  PORTC=segcthd[9];
  	  	  PORTD &=~(1<<2); //enable for 2nd 7segment
  	  	  _delay_ms(10);

  	  }
  	}
	 return 0;
}
