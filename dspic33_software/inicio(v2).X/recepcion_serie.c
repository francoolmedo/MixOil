          /* RUTINA DE RECEPCION DEL PUERTO UART 1*/
#include "p33Fxxxx.h"
#include <xc.h>
#include <stdint.h>            //Includes uint16_t definition                    
#include <stdbool.h>           //Includes true/false definition          
#include <stdio.h>
#include <string.h>
#include "configuraciones.h"   //System funct/params/osc/peripheral config 
#include "timer.h"
#include <uart.h>
#include "i2cEmem.h"           //manejo de memoria EEprom 24LC256
#include "hardware.h"          //Definicion de nombres para pines  de puertos E/S
#include "constantes.h"
#include <p33FJ256MC710.h>
/*  Configuracion Puerto serial para velocidades de 115200 - 9600 Baudios*/
#define FCY 35007500UL
#define BAUDRATE 115000 //colocar 115000 para que BGRVAL=18 o 9596 para BGRVAL=227
#define BRGVAL ((FCY/BAUDRATE)/16)-1 
#include "libpic30.h"


//-----------------------  BUFFER UART  1 -------------------------------- 
extern char dato_Rx[TAM_Rx];
extern unsigned int RX_CHEKA;
//------------------------------------------------------------------------
       


  void __attribute__((__interrupt__,no_auto_psv)) _U1RXInterrupt(void)
{
   static int r=0;
   
   
   
       
   while(DataRdyUART1())
 {
  dato_Rx[r]= ReadUART1();
    
  }
   if(dato_Rx[r]!='\n'){ 
       r++;
   }
   else{     
   dato_Rx[r]='\0';
   r=0;
    } 
   if(r==TAM_Rx)
       r=0;
   
        
    IFS0bits.U1RXIF = 0; // clear RX interrupt flag
} 

 