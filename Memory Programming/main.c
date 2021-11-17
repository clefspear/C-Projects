/*
 * Lab 8.c
 *
 * Created: 11/15/2020 10:02:31 PM
 * Author : Peter Azmy
 */ 
#define F_CPU 16000000UL
#define BAUD 9600                           // define baud
#define BAUDRATE ((F_CPU)/(BAUD*16UL)-1)    // set baud rate
#define LED_ON (PORTB |= (1<<5))
#define LED_OFF (PORTB &= ~(1<<5))
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdio.h>
#include <stdint.h>
#include <avr/eeprom.h>

void init(void)
{
	OCR0A = 0x4D;                            		//Set 5ms period, 77
	TCCR0A |= (1 << WGM01);							//CTC Mode
	TCCR0B |= (1 << CS00)|(1 << CS02);				//Pre-scale = 1024
	TIMSK0 |= (1 << OCIE0A)|(1 << OCIE0B);			//COMPA vect and COMPB vect;
	sei(); //enable interrupts
}

ISR (TIMER0_COMPA_vect)
{
	if(OCR0B != 0x00)
	LED_ON;
}
ISR (TIMER0_COMPB_vect)
{
	if(OCR0B < 0x4E)								//78
	LED_OFF;
}
void EEPROM(void)
{
	uint8_t Read;								//Variables for read and write BYTES
	uint8_t Load;
	
	Read = eeprom_read_byte((uint8_t*)0x22);	//Read BYTE in a location of EEPROM
	
	if(Read < 0x4D)								//Check if BYTE read is less than 10
	{
		OCR0B = Read;							//Set OCR0B as read BYTE
		Load = Read + 0x08;					//Add BYTE by 8(about 10% of 77)
		eeprom_write_byte((uint8_t*)0x22, Load);//Increase LED by 10. 
												//(0x22) Location of EEProm Address Register High Byte
	}
	
	else
	{
		OCR0B = 0x4E;								//If BYTE read is greater than 10
		Load = 0x00;							//Reset OCR0B to zero on next turn on
		eeprom_write_byte((uint8_t*)0x22, Load);//Reset LED to 0
	}
}
int main(void)
{
	cli();				//disable global interrupts
	DDRB  |= (1<<5);	// Set PinB5(LED) as an OUTPUT
	LED_OFF;			// Default OFF
	init();
	EEPROM();
	while (1)
	{
	}
}


