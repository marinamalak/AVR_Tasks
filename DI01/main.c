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
	u8 button1,button2,button3;
	DDRA =0xff;
	PORTA =0x00;
	DDRB =0x00;
	PORTB =0xff;
	while(1){
	button1 =((PINB>>0)&1);
	button2 =((PINB>>1)&1);
	button3 =((PINB>>2)&1);

	if(button1==0){
		PORTA|=(1<<0);
		PORTA &=~(1<<1);
	}
	else if(button2==0){
		PORTA|=(1<<1);
		PORTA &=~(1<<0);
	}
	else if (button3==0){
		PORTA|=(1<<0);
		PORTA|=(1<<1);
	} else{
		PORTA =0x00;
	}

}
	return 0;
}

