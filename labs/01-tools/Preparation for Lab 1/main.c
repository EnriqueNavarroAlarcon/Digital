/***********************************************************************
 * Enrique Navarro Alarcon
 * Preparation for Lab 1
 * Digital Electronics 2
 * ATmega328P (Arduino Uno), 16 MHz, AVR 8-bit Toolchain 3.6.2
 *
 **********************************************************************/

/* Defines -----------------------------------------------------------*/
#define LED_GREEN   PB5     // AVR pin where green LED is connected
#define SHORT_LIGHT 500      // Delay in miliseconds
#define LONG_LIGHT 1000  
#define DELAY 500 
#ifndef F_CPU
#define F_CPU 16000000      // CPU frequency in Hz required for delay func
#endif

/* Includes ----------------------------------------------------------*/
#include <util/delay.h>     // Functions for busy-wait delay loops
#include <avr/io.h>         // AVR device-specific IO definitions

int main(void)
{
	// To Write DE2 in morse code we need to know the three letters in morse
	// D -> -..  E-> .  2-> ..---   So the word would be -> -.....---
    // Set pin as output in Data Direction Register
    // DDRB = DDRB or 0010 0000
    DDRB = DDRB | (1<<LED_GREEN);

    // Set pin LOW in Data Register (LED off)
    // PORTB = PORTB and 1101 1111
    PORTB = PORTB & ~(1<<LED_GREEN);

    // Infinite loop
    while (1)
    {
        // Pause several miliseconds
        _delay_ms(DELAY);
		// Leter D
		
        PORTB = PORTB ^ (1<<LED_GREEN);
		_delay_ms(LONG_LIGHT);
		PORTB = PORTB & ~(1<<LED_GREEN);
		_delay_ms(DELAY);

        PORTB = PORTB ^ (1<<LED_GREEN);
        _delay_ms(SHORT_LIGHT);
        PORTB = PORTB & ~(1<<LED_GREEN);
        _delay_ms(DELAY);

        PORTB = PORTB ^ (1<<LED_GREEN);
        _delay_ms(SHORT_LIGHT);
        PORTB = PORTB & ~(1<<LED_GREEN);
        _delay_ms(DELAY);				
    
		// Leter E
		
        PORTB = PORTB ^ (1<<LED_GREEN);
        _delay_ms(SHORT_LIGHT);
        PORTB = PORTB & ~(1<<LED_GREEN);
        _delay_ms(DELAY);	
		
		// Number 2 
			
        PORTB = PORTB ^ (1<<LED_GREEN);
        _delay_ms(SHORT_LIGHT);
        PORTB = PORTB & ~(1<<LED_GREEN);
        _delay_ms(DELAY);
		
        PORTB = PORTB ^ (1<<LED_GREEN);
        _delay_ms(SHORT_LIGHT);
        PORTB = PORTB & ~(1<<LED_GREEN);
        _delay_ms(DELAY);	
		
        PORTB = PORTB ^ (1<<LED_GREEN);
        _delay_ms(LONG_LIGHT);
        PORTB = PORTB & ~(1<<LED_GREEN);
        _delay_ms(DELAY);
		
        PORTB = PORTB ^ (1<<LED_GREEN);
        _delay_ms(LONG_LIGHT);
        PORTB = PORTB & ~(1<<LED_GREEN);
        _delay_ms(DELAY);					

        PORTB = PORTB ^ (1<<LED_GREEN);
        _delay_ms(LONG_LIGHT);
        PORTB = PORTB & ~(1<<LED_GREEN);
        _delay_ms(DELAY);							
	}
	 // Will never reach this
    return 0;
}
