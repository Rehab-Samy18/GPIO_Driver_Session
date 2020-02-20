/*
 * gpio.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: Rehab Samy
 *      Not compeleted
 */

#include"gpio.h"
#include "RegMap.h"
void GPIOBusSet(unsigned long int port,gpio_bus_t bus){

}

gpio_bus_t GPIOBusGet(unsigned long int port){

}

void GPIOClockSet(unsigned long int port){

}

void GPIOClockRst(unsigned long int port){

}

char GPIOClockGet(unsigned long int port){

}

void GPIODirModeSet(unsigned long int port, unsigned char pins, gpio_mode_t mode){
   if(mode == MODE_AF )
   {
       *(volatile unsigned long int *)(port+GPIOAFSEL)= 0xFF;
   }
   else if(mode == MODE_OUT )
   {
       *(volatile unsigned long int *)(port+GPIODIR)= 0xFF;
   }
   else if(mode == MODE_IN )
   {
       *(volatile unsigned long int *)(port+GPIODIR)= 0x00;
   }

}

unsigned char GPIODirGet(unsigned long int port, unsigned char pins){
     return *(volatile unsigned long int *)(port+GPIODIR);
}

unsigned char GPIOModeGet(unsigned long int port, unsigned char pins){
    return *(volatile unsigned long int *)(port+GPIOAFSEL);
}

void GPIOPadSet(unsigned long int port, unsigned char pins, GpioCng_t *obj){
if(obj -> DriveCurrentSel == Drive_2mA){
    *(volatile unsigned long int *)(port+GPIODR2R)= 0xFF;
}
else if(obj -> DriveCurrentSel == Drive_4mA){
    *(volatile unsigned long int *)(port+GPIODR4R)= 0xFF;
}
else if(obj -> DriveCurrentSel == Drive_8mA){
    *(volatile unsigned long int *)(port+GPIODR8R)= 0xFF;
}
else if(obj -> DriveCurrentSel == Drive_8mA_Slew){
    *(volatile unsigned long int *)(port+GPIOSLR)= 0xFF;
}
else if(obj -> ResTypeSel == Pad_PU){
    *(volatile unsigned long int *)(port+GPIOPUR)= 0xFF;
}
else if(obj -> ResTypeSel == Pad_PD){
    *(volatile unsigned long int *)(port+GPIOPDR)= 0xFF;
}
else if(obj -> ResTypeSel == PAD_OD){
    *(volatile unsigned long int *)(port+GPIOODR)= 0xFF;
}
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
