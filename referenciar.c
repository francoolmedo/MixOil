/*
 * File:   referenciar.c
 * Author: carlos
 *
 * Created on 29 de febrero de 2024, 10:44
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

extern bool BANDERA_DETENCION;
extern bool BANDERA_REFERENCIA;
extern bool BANDERA_CICLO;

extern bool BANDERA_SERVO_REFERENCIADO;

void referenciar() {

    BANDERA_CICLO = 0;


    if (BANDERA_DETENCION == 0 && HAB_SRV == 1 && BANDERA_SERVO_REFERENCIADO == 0) { // INICIO BUSQUEDA DEL ORIGEN

        // GENERA EL PULSO SHOME
        SHOME = 1; //     SHOME SALIDA PULLUP
        __delay_ms(20);
        SHOME = 0;



        do {
            // ESPERA QUE EL SERVO SE POSICIONE   

        } while (HOME == 1); //REVISAR CONDICION ANTES HOME!=1


        BANDERA_SERVO_REFERENCIADO = 1;


    }









    return;
}