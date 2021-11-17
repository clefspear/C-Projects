/*
 * Lab7.c
 *
 * Created: 11/12/2020 9:56:14 PM
 * Author : Peter Azmy
 * REDID: 820015437
 * myY%8 = 3, so ADC channel 3
 */ 
#define myX 4
#define myZ 7
#define LED_TOGGLE (PORTB ^= (1<<PORTB5))	//Toggle ON/OFF
#define LED_ON (PORTB |= (1<<5))
#define LED_OFF (PORTB &= ~(1<<5))
#include <avr/io.h>
#include <avr/interrupt.h>

int main(void)
{
	DDRB	|= (1 << DDB5);	// PB5 As LED Output pin
	DDRC	&= ~(1 << DDC3);	// Sets PC3 as input for the wheel
	
	sei();		// Enables interrupts
	
	Timer0_Init();
	Timer2_Init();
	
	// Set AVcc as Vref and set ADC3 as input channel (PC3)
	ADMUX |= (1 << REFS0) | (1<< MUX1) | (1 << MUX0);
	// Enable ADC, start conversion, auto trigger, interrupts, prescalar to 64
	ADCSRA |= (1 << ADEN) | (1 << ADATE) | (1 << ADIE) | (1 << ADPS2) | (1 << ADPS1);
	ADCSRB |= (1 << ADTS1) | (1 << ADTS0);
	while (1)
	{
		
	}
}

void Timer0_Init(void)
{
	// Timer 0 initialize
	// Set clock prescalar to 256 and set CTC mode
	TCCR0B |= (1 << CS10) | (1 << CS12) | (1 << WGM12);
	TIMSK0 |= (1 << OCIE0A); 
	
	OCR0A = (16000000/(256*(1000/(1/((myZ+1)*100)))));	
}

void Timer2_Init(void)
{
	// Timer 2 initialize
	// Set clock prescalar to 256 and set CTC mode
	TCCR2B |= (1 << CS10) | (1 << CS12) | (1 << WGM12);
	TIMSK2 |= (1 << OCIE2A)|(1 << OCIE2B);
	
	OCR2A = (16000000/(256*(1000/(myX + 1))));	

}

ISR(TIMER2_COMPA_vect)
{
		LED_ON;
	
}
ISR(TIMER2_COMPB_vect)
{
		LED_OFF;
}
		

ISR (ADC_vect)
{
	// Read the A/D result
	uint16_t result = ADC;

	OCR2B = ((result/1024.0) * OCR2A);
}