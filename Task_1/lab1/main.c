#include <util/delay.h>

typedef unsigned char u8;

#define DDRA *((u8*)0x3A)
#define PORTA *((u8*)0x3B)
#define PINA *((volatile u8*)0x39)

int main (void){

//pin 0 in DDRA is output
	DDRA|=(1<<0);
	while(1){
//pin 0 in PORTA is high
	PORTA|=(1<<0);
	_delay_ms(1000);
//pin 0 in PORTA is high
	PORTA &=~(1<<0);
	_delay_ms(1000);

	}
	return 0;
}

