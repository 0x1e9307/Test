/*
 * main.h
 *
 * Created: 06.11.2018 22:02:16
 * Author : 0x1e9307
 */ 


#ifndef MAIN_H_
#define MAIN_H_

//-------------------------------------------

#define F_CPU 8000000UL

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdio.h>
#include <stdlib.h>

//-------------------------------------------

unsigned int adc_value,adc_counter,adc_tmp;

//-------------------------------------------
#include "lcd.h"
#include "adc.h"

//-------------------------------------------



#endif /* MAIN_H_ */