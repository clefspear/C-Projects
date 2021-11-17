/*
 * GccApplication2.c
 *
 * Created: 6/7/2020 9:51:28 AM
 * Author : Peter Azmy
 */ 
#define F_CPU 16000000UL
#define BAUD 9600							
#define BAUDRATE ((F_CPU)/(BAUD*16UL)-1)	
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>


// function to initialize USART
void USART_intlize (void)			
{
	UBRR0H  = (BAUDRATE>>8);			// Set UBRRHigh -> Shift the register right by 8 bits
	UBRR0L  = BAUDRATE;					// Set UBRRLow -> Set BAUD rate
	UCSR0B |= ((1<<TXEN0)|(1<<RXEN0));	// Set register B; TXEN -> Enable receiver, RXEN -> transmitter
	UCSR0C |= ((1<<UCSZ00)|(1<<UCSZ01));// Set register C; UCSZ00 -> 8bit data format,USBS -> 1 stop-bit initially 0
}

void USART_transm(unsigned char data)	
{
	while (! ( UCSR0A & (1<<UDRE0) ) );	// While buffer; Check register A; check location to see if register is empty
	UDR0 = data;						// Load data into the USART data register
}

unsigned char keyboard[4][4]= 
{{'1','2','3','A'},
{'4','5','6','B'},
{'7','8','9','C'},
{'*','0','#','D'}};

int main(void)
{
	USART_intlize();							// Initialize USART
	unsigned int r = 0;
	unsigned int c = 0;
	DDRB &= ~((1<<0)|(1<<1)|(1<<2)|(1<<3)); 	//Set PORTB as input 0
	DDRD |= ((1<<4)|(1<<5)|(1<<6)|(1<<7)); 		//Set PORTD as output 1
	PORTB |= ((1<<0)|(1<<1)|(1<<2)|(1<<3));		//Pull-up resistor enabled by default at 1
	PORTD |= ((1<<4)|(1<<5)|(1<<6)|(1<<7));		//Sets Ports on rows as outputs high
	
	while (1)
	{
		for(r=0; r< 4; r++)
		{
			PORTD &= ~(1<<(r+4));						//Set PORT LOW one at a time to check
			for(c=0;c<=3; c++)
			{
					
				if ((!(PINB & (1<<c))))				//Checking if push button is pressed
				{
					_delay_ms(150);//Delay for button bounce
					USART_transm(keyboard[r][c]);	//Transmit the index [r][c]
				}
			}
			PORTD |= (1<<(r+4));						//Set PORT back to HIGH after checking entire row
		}
	}								
}										

