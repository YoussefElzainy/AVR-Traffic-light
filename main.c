/*
 * traffic light.c
 *
 * Created: 8/8/2025 8:16:45 PM
 * Author : DELL
 */ 

#define F_CPU 8000000
typedef unsigned char U8;
#include <avr/delay.h>
#include <avr/io.h>

U8 seven_seg[] = {
	0x3F,
	0x06,
	0x5B,
	0x4F,
	0x66,
	0x6D,
	0x7D,
	0x07,
	0x7F,
	0x6F
};





int main(void)
{
	DDRC = 0xff;
	DDRA = 0xff;
	DDRB |= (1<<0) | (1<<1) | (1<<2);
	
    U8 state = 0;
    while (1) 
    {
		for(int i = 30 ; i >= 0 ; i--){
			PORTA = seven_seg[(i/10)];
			PORTC = seven_seg[(i%10)];
			
			if (state % 2 == 0)
			{
				PORTB |= 1<<0;
				PORTB &= ~((1<<1) | (1<<2)); 
			}else{
				PORTB |= 1<<2;
				PORTB &= ~((1<<1) | (1<<0));
			}
			
			_delay_ms(1000);
		}
		
		for (int i = 10 ; i >= 0 ; i--)
		{
			if (state % 2 != 0)
			{
				break;
			}
			PORTA = seven_seg[(i/10)];
			PORTC = seven_seg[(i%10)];
			
			PORTB |= 1<<1;
			PORTB &= ~((1<<2) | (1<<0));
			_delay_ms(1000);
		}
		state++;
    }
}

