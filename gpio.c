/*
 * gpio.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Rehab Samy
 *      Not compeleted
 */

#include"gpio.h"
#include "RegMap.h"
void GPIOBusSet(gpio_port_t port,gpio_bus_t bus){
    *GPIOHBCTL   |= (bus<<port);
}

gpio_bus_t GPIOBusGet(gpio_port_t port){

}

void GPIOClockSet(gpio_port_t port){
    *GPIORCGC |= (1<<port);
}

void GPIOClockRst(gpio_port_t port){
    *GPIORCGC &= ~(1<<port);
}

char GPIOClockGet(gpio_port_t port){
    return *((volatile unsigned long int *)(port+GPIORCGC));
}

void GPIODirModeSet(unsigned long int port, unsigned char pins, gpio_mode_t mode){
   //For Mode
    volatile unsigned long int *reg = port+GPIOAFSEL;
    unsigned long int data = *reg;

    data &=~(pins);
    if(mode == MODE_AF)
    {
        data |=(0xFF & pins);
    }
    else
    {
        data |=(0x00 & pins);
    }

    *reg = data;

   //For Direction
    reg = port+GPIODIR;
    data = *reg;
    data &=~(pins);

    if(mode == MODE_OUT)
    {
        data |=(0xFF & pins);
    }
    else if(mode == MODE_IN){
        data |=(0x00 & pins);
    }

    *reg = data;


}

unsigned char GPIODirGet(unsigned long int port, unsigned char pins){
     return (*(volatile unsigned long int *)(port+GPIODIR));
}

unsigned char GPIOModeGet(unsigned long int port, unsigned char pins){
    return *(volatile unsigned long int *)(port+GPIOAFSEL);
}

void GPIOPadSet(unsigned long int port, unsigned char pins, gpio_drive_t str, gpio_pad_t pad){

}

unsigned char GPIOPadDriveStrGet(unsigned long int port, unsigned char pins){
//////////////
}

unsigned char GPIOPadOpenDrainGet(unsigned long int port, unsigned char pins){
    return *(volatile unsigned long int *)(port+GPIOODR);
}

unsigned char GPIOPadPullUpGet(unsigned long int port, unsigned char pins){
    return *(volatile unsigned long int *)(port+GPIOPUR);
}

unsigned char GPIOPadPullDownGet(unsigned long int port, unsigned char pins){
    return *(volatile unsigned long int *)(port+GPIOPDR);
}

unsigned char GPIORead(unsigned long int port, unsigned char pins){
    return *(volatile unsigned long int *)(port+ GPIODATA);
}

void GPIOWrite(unsigned long int port, unsigned char pins, unsigned char data){
    *(volatile unsigned long int *)(port+ GPIODATA)=data;
}
