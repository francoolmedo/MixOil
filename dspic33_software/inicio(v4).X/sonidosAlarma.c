/*
 * File:   sonidosAlarma.c
 * Author: carlos
 *
 * Created on 4 de enero de 2024, 9:45
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

void sonido_1(int tic) {
    if (tic > 600 && tic <= 700) {
        tic -= 600;
    } else if (tic > 700 && tic <= 800) {
        tic -= 700;
    } else if (tic > 800 && tic <= 900) {
        tic -= 800;
    } else if (tic > 900 && tic <= 1000) {
        tic -= 900;
    }

    if (tic <= 13) {
        AlarS = 0;
    } else if (tic > 13 && tic <= 26) {
        AlarS = 1;
    } else if (tic > 26 && tic <= 39) {
        AlarS = 0;
    } else if (tic > 39 && tic <= 70) {
        AlarS = 1;
    } else if (tic > 70 && tic <= 83) {
        AlarS = 0;
    } else if (tic > 83 && tic <= 100) {
        AlarS = 1;
    }
    //    __delay_ms(130);
    //    AlarS = 0;
    //    __delay_ms(130);
    //    AlarS = 1;
    //    __delay_ms(130);
    //    AlarS = 0;
    //    __delay_ms(380);
    //    AlarS = 1;
    //    __delay_ms(130);
    //    AlarS = 0;
    //    __delay_ms(380);
    //    AlarS = 1;
    //    __delay_ms(130);
    //    AlarS = 0;

    return;
}

void sonido_2(int tic) {
    if (tic > 100 && tic <= 200) {
        tic -= 100;
    } else if (tic > 200 && tic <= 300) {
        tic -= 200;
    } else if (tic > 300 && tic <= 400) {
        tic -= 300;
    } else if (tic > 400 && tic <= 500) {
        tic -= 400;
    } else if (tic > 500 && tic <= 600) {
        tic -= 500;
    }

    if (tic <= 10) {
        AlarS = 0;
    } else if (tic > 10 && tic <= 30) {
        AlarS = 1;
    } else if (tic > 30 && tic <= 40) {
        AlarS = 0;
    } else if (tic > 40 && tic <= 80) {
        AlarS = 1;
    } else if (tic > 80 && tic <= 100) {
        AlarS = 0;
    }
    return;
}
