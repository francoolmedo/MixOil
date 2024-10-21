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

extern unsigned int num;
//------------------------
extern bool APQ;
extern bool apagar_Q;
extern bool BANDERA_quemador;
//------------------------
extern bool APP;
extern bool apagar_P;
extern bool BANDERA_precalentador;
//-------------------------------
extern bool APM;
extern bool apagar_M;
extern bool BANDERA_molino;

void Manual() {





    switch (num) {

        case 1:
            if (BANDERA_quemador == 1) { // SK1 QUEMADOR
                if (!Qmarch == 0 && apagar_Q == 0) {
                    Quemador();
                }
            }
            break;


        case 2:
            if (BANDERA_molino == 1) { // SK2  MOLINO LAVADORA
                if (Lmarch == 0 && apagar_M == 0) { // !Lmarch
                    Molino();
                }
            }

            break;


        case 3:
            if (BANDERA_precalentador == 1) { // SK3 PRECALENTADOR
                if (!PCmarch == 0 && apagar_P == 0) {
                    Precalentador();
                }
            }
            // SK3 PRE CALENTADOR   


            break;

        default: break;


    }






    return;
}