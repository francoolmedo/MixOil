/*
 * File:   tiempo_Quemador.c
 * Author: carlos
 *
 * Created on 8 de enero de 2024, 11:36
 */


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


extern unsigned int tiempo_ENCQUEMA;
extern unsigned int ticks_Q;
extern unsigned int tiempo_segQ;
extern unsigned int FINAL;
extern unsigned int tETAP;

void tiempo_Q() {

    if (ticks_Q == 6000) {
        tiempo_ENCQUEMA++;
        FINAL = tiempo_ENCQUEMA;
        tETAP = FINAL;
        ticks_Q = 1;
    }
    ticks_Q++;

    return;
}

void reset_tiempoQ() {
    ticks_Q = 1;
    tiempo_ENCQUEMA = 0;
    tETAP = 0;
    FINAL = 0;

    return;
}



