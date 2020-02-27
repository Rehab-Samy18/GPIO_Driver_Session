/*
 * gpio.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: pc
 */

#ifndef GPIO_H_
#define GPIO_H_

#include "RegMap.h"

typedef enum {MODE_IN = 0x00, MODE_OUT = 0xff, MODE_AF = 0x3} gpio_mode_t;
//typedef enum {PORTA, PORTB, PORTC, PORTD, PORTE, PORTF} gpio_port_t;

typedef enum { PORTA_AHB = 0x40058000, PORTA_APB = 0x40004000
              ,PORTB_APB = 0x40005000, PORTB_AHB = 0x40059000
              ,PORTC_APB = 0x40006000, PORTC_AHB = 0x4005A000
              ,PORTD_APB = 0x40007000, PORTD_AHB = 0x4005B000
              ,PORTE_APB = 0x40024000, PORTE_AHB = 0x4005C000
              ,PORTF_APB = 0x40025000, PORTF_AHB = 0x4005D000}gpio_port_t;

typedef enum {AHB=1, APB=0} gpio_bus_t;

typedef enum {Drive_2mA=0x500, Drive_4mA=0x504, Drive_8mA=0x508, Drive_8mA_Selw=0x508} gpio_drive_t;
typedef enum {Pad_PU=0x510,Pad_PD=0x514,PAD_NPU_NPD,PAD_OD=0x50C} gpio_pad_t;


//Functions prototype

void GPIOBusSet(gpio_port_t port,gpio_bus_t bus);
gpio_bus_t GPIOBusGet(gpio_port_t port);

void GPIOClockSet(gpio_port_t port);
void GPIOClockRst(gpio_port_t port);
char GPIOClockGet(gpio_port_t port);

void GPIODirModeSet(unsigned long int port, unsigned char pins, gpio_mode_t Mode);
unsigned char GPIODirGet(unsigned long int port, unsigned char pins);
unsigned char GPIOModeGet(unsigned long int port, unsigned char pins);

void GPIOPadSet(unsigned long int port, unsigned char pins, gpio_drive_t str, gpio_pad_t pad);
unsigned char GPIOPadDriveStrGet(unsigned long int port, unsigned char pins);
unsigned char GPIOPadOpenDrainGet(unsigned long int port, unsigned char pins);
unsigned char GPIOPadPullUpGet(unsigned long int port, unsigned char pins);
unsigned char GPIOPadPullDownGet(unsigned long int port, unsigned char pins);

unsigned char GPIORead(unsigned long int port, unsigned char pins);
void GPIOWrite(unsigned long int port, unsigned char pins, unsigned char data);

#endif /* GPIO_H_ */
