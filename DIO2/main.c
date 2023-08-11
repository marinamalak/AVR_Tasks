/*
 * main.c
 *
 *  Created on: Jul 17, 2023
 *      Author: Admin
 */

#include "STDTYPE.h"
#include "REGISTER.h"
int
main(void){
	 u8 segcthd[]= {0x3f,0x06,0x5b,
			        0x4f,0x66,0x6d,
				    0x7d,0x07,0x7f,
	                0x6f};
	s8 button1,button2,count=0;
	DDRA=0x00;
	PORTA=0xff;
	DDRC=0xff;
	PORTC=0x00;

	while(1){
		button1 =((PINA>>0)&1);
		button2 =((PINA>>1)&1);
		if(button1==0){
			count++;
			 while(((PINA>>0)&1)==0);
		}
		else if (button2==0){
			count--;
			 while(((PINA>>1)&1)==0);
		}
		if(count >9 )
			count =9;
		else if (count<0)
			count =0;
		PORTC =segcthd[count];
	}

	return 0;
}
