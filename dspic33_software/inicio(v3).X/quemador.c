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

extern unsigned int TP10S;
extern unsigned int dR;
extern unsigned int RX_CHEKA;
extern unsigned int SOFTK_A;
extern unsigned int SOFTK_N;
extern unsigned int SK_Q;
extern unsigned int CHEK_A;
extern unsigned int num;
extern unsigned int Punto;
extern unsigned int ESTADO_1;
extern bool BANDERA_quemador;
extern bool BANDERA_ACTUALIZAQ;
extern bool BANDERA_ALARQUEM;
extern bool tabla_sk;
extern bool BANDERA_RETROCERQ;
extern bool no_quemador;
extern bool REhorno;

extern bool aviso_Qarr;
extern char dato_Rx[TAM_Rx];
extern bool APQ;
extern bool apagar_Q;
extern unsigned long int rx_enviar;
extern unsigned int RES1;
extern bool BANDERA_HELPQNDmax;
extern bool BANDERA_HELPQNDmin;
extern bool BANDERA_HELPQTCF;

void Quemador() { //MANEJO DEL QUEMADOR Y DE IMPRESIONES
    int i = 0;
    int seg = 0;
    tabla_sk = 0;
    CHEK_A = -1; // si se corta elmensaje manda H=0 OJO




    if (BANDERA_HELPQTCF == 1) {
        BANDERA_quemador = 0;
        Qarr = 1;
        num = 0;
        BANDERA_ALARQUEM = 1;
        ESTADO_1 = 99;
        CHEK_A = -1;
        RES1 = 4; // COLOCAR AVISO TCF
        tabla_sk = 1;
    }


    if (BANDERA_HELPQNDmin == 1) {

        BANDERA_quemador = 0;
        Qarr = 1;
        num = 0;
        BANDERA_ALARQUEM = 1;
        ESTADO_1 = 99;
        CHEK_A = -1;
        RES1 = 2; // COLOCAR AVISO NIVEL DEPOSITO
        tabla_sk = 1;
    }

    if (BANDERA_HELPQNDmax == 1) {

        BANDERA_quemador = 0;
        Qarr = 1;
        num = 0;
        BANDERA_ALARQUEM = 1;
        ESTADO_1 = 99;
        CHEK_A = -1;
        RES1 = 1; // COLOCAR AVISO NIVEL DEPOSITO
        tabla_sk = 1;
    }

    if (REhorno == 0) {
        BANDERA_quemador = 0;
        Qarr = 1;
        num = 0;
        BANDERA_ALARQUEM = 1;
        ESTADO_1 = 99;
        CHEK_A = -1;
        RES1 = 3; // COLOCAR AVISO NO HAY REACTOR
        tabla_sk = 1;
    }


    if (REhorno == 1 && BANDERA_HELPQNDmax == 0 && BANDERA_HELPQNDmin == 0 && BANDERA_HELPQTCF == 0) { // HAY REACTOR EN EL HORNO
        /* ALARMAS CON REACTOR EN EL HORNO */

        // MENSAJE ENCENDER QUEMADOR SI NO HAY ALARMAS 
        do {

            __delay_ms(20);
            generar_A(0x650004, 0x0400, 0, 0);
            __delay_ms(20);
            i++;


            if (strncmp(dato_Rx, "H=", 2) == 0) {
                sscanf(dato_Rx, "H=%2x", &RX_CHEKA);
            }


        } while (i <= 5 || RX_CHEKA == CHEK_A);

        i = 0;

        do {


            if (BANDERA_RETROCERQ == 1) {
                num = 0;
                break;
            }
            // ESPERANDO TECLA SK - ENCENDER- ACTUALIZAR- RETORNAR

            if (TP10S == 0)
                BANDERA_ACTUALIZAQ = 1;
            //SK ACTUALIZAR CONDICION BANDERA NUM=1 ,BANDERA tabla_sk  =0

            if (BANDERA_ACTUALIZAQ == 1) {

                __delay_ms(50);
                generar_A(0x650004, 0x0400, 0, 0);
                __delay_ms(50);

                BANDERA_ACTUALIZAQ = 0;

            }


        } while (aviso_Qarr == 0);

        CHEK_A = -1;

        if (BANDERA_RETROCERQ == 0)
            Qarr = 0; // ENCENDER RELEE    

        do {

            if (BANDERA_RETROCERQ == 1) {
                num = 0;
                break;
            }

            __delay_ms(20);
            generar_A(0x650000, 0x1500, 0, 0);
            __delay_ms(20);
            i++;
            if (strncmp(dato_Rx, "H=", 2) == 0) {
                sscanf(dato_Rx, "H=%2x", &RX_CHEKA);
            }

        } while (RX_CHEKA == CHEK_A || i <= 5);

        i = 0;
        CHEK_A = -1;

        //EN PROCESO DE ENCENDIDO
        do {

            if (BANDERA_RETROCERQ == 1) {
                num = 0;
                break;
            }


            if (BANDERA_ACTUALIZAQ == 1) {
                __delay_ms(50);
                generar_A(0x650000, 0x1500, 0, 0);
                __delay_ms(50);
                BANDERA_ACTUALIZAQ = 0;
            }

            __delay_ms(100); // NO USAR  
            i++;

            if (i == 10) {
                seg += 1;
                i = 0;
            }

            if (dR == seg) {
                Qarr = 1;
                aviso_Qarr = 0;
                BANDERA_quemador = 0;
                num = 0;
                apagar_Q = 0;
                BANDERA_ALARQUEM = 1;
                ESTADO_1 = 99;
                CHEK_A = -1;
                RES1 = 5; // ERROR EN EL TIEMPO
                tabla_sk = 1;
                break; // RETORNAR 

            }

            //ESPERANDO SEÑAL DEL QUEMADOR SK- ACTUALIDAR- RETORNAR     
        } while ((!Qmarch) != 1 || num == 0);

        if (seg < dR && BANDERA_RETROCERQ == 0) {
            APQ = 1;
            apagar_Q = 1;
            tabla_sk = 1;
            num = 0;
        }


    } //FIN IF REACTOR HORNO

    if (BANDERA_RETROCERQ == 1) {
        Qarr = 1;
        aviso_Qarr = 0;
        BANDERA_quemador = 0;
        num = 0;
        apagar_Q = 0;
        BANDERA_ALARQUEM = 1;
        ESTADO_1 = 99;
        CHEK_A = -1;
        tabla_sk = 1;
    }

    BANDERA_RETROCERQ = 0;


    return;
}





