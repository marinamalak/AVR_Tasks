#include <util/delay.h>

typedef unsigned char u8;

#define DDRD *((u8*)0x31)
#define PORTD *((u8*)0x32)
#define PIND *((volatile u8*)0x30)
int main (void){

	for(int i=0 ;i<8;i++){
		DDRD|=(1<<i);
	}
	while(1){
		for(int i=0 ;i<8;i++){
			PORTD|=(1<<i);
			_delay_ms(500);
		}
		for(int i=0 ;i<8;i++){
			PORTD &=~(1<<i);
			_delay_ms(500);
		}
	}

	return 0;
}

