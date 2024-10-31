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
extern unsigned int TP1S;
extern unsigned int quemadorloop;
extern unsigned int NP5S;

void Quemador() { //MANEJO DEL QUEMADOR Y DE IMPRESIONES
    tabla_sk = 0;
    CHEK_A = -1; // si se corta elmensaje manda H=0 OJO


    if (BANDERA_HELPQTCF == 1) {
        BANDERA_quemador = 0;
        Qarr = 1;
        num = 0;
        BANDERA_ALARQUEM = 1;
        CHEK_A = -1;
        RES1 = 4; // COLOCAR AVISO TCF
        tabla_sk = 1;
    }


    if (BANDERA_HELPQNDmin == 1) {
        BANDERA_quemador = 0;
        Qarr = 1;
        num = 0;
        BANDERA_ALARQUEM = 1;
        CHEK_A = -1;
        RES1 = 2; // COLOCAR AVISO NIVEL DEPOSITO
        tabla_sk = 1;
    }


    if (BANDERA_HELPQNDmax == 1) {
        BANDERA_quemador = 0;
        Qarr = 1;
        num = 0;
        BANDERA_ALARQUEM = 1;
        CHEK_A = -1;
        RES1 = 1; // COLOCAR AVISO NIVEL DEPOSITO
        tabla_sk = 1;
    }

    if (REhorno == 0) {
        BANDERA_quemador = 0;
        Qarr = 1;
        num = 0;
        BANDERA_ALARQUEM = 1;
        CHEK_A = -1;
        RES1 = 3; // COLOCAR AVISO NO HAY REACTOR
        tabla_sk = 1;
    }


    if (REhorno == 1 && BANDERA_HELPQNDmax == 0 && BANDERA_HELPQNDmin == 0 && BANDERA_HELPQTCF == 0) { // HAY REACTOR EN EL HORNO
        /* ALARMAS CON REACTOR EN EL HORNO */

        if (!aviso_Qarr) {

            if (!TP1S) {
                // MENSAJE ENCENDER QUEMADOR SI NO HAY ALARMAS
                generar_A(0x650004, 0x0400, 0, 0);

                // ESPERANDO TECLA SK - ENCENDER- ACTUALIZAR- RETORNAR
                if (BANDERA_RETROCERQ == 1) {
                    num = 0;
                    AlarS = 0;
                    aviso_Qarr = 0;
                    BANDERA_quemador = 0;
                    apagar_Q = 0;
                    BANDERA_ALARQUEM = 1;
                    BANDERA_RETROCERQ = 0;
                    CHEK_A = -1;
                    tabla_sk = 1;
                    return;
                }
            }

            if (TP10S == NP5S) {
                BANDERA_ACTUALIZAQ = 1;

                //SK ACTUALIZAR CONDICION BANDERA NUM=1 ,BANDERA tabla_sk  =0
                if (BANDERA_ACTUALIZAQ == 1) {
                    generar_A(0x650004, 0x0400, 0, 0);
                    BANDERA_ACTUALIZAQ = 0;
                }
            }
            CHEK_A = -1;
        }

        // Se presiono ENCENDER QUEMADOR
        if (aviso_Qarr) {
            if (BANDERA_RETROCERQ == 1) {
                num = 0;
                AlarS = 0;
                aviso_Qarr = 0;
                BANDERA_quemador = 0;
                apagar_Q = 0;
                BANDERA_ALARQUEM = 1;
                CHEK_A = -1;
                tabla_sk = 1;
                BANDERA_RETROCERQ = 0;
                return;
            }

            //            if (TP1S == 0) {
            
            generar_A(0x650000, 0x1500, 0, 0); // MENSAJE EN PROCESO DE ENCENDIDO

//            if (strncmp(dato_Rx, "H=", 2) == 0)
//                sscanf(dato_Rx, "H=%2x", &RX_CHEKA);
            //            }
            CHEK_A = -1;
        }


        //Comienza Rutina de Arranque: EN PROCESO DE ENCENDIDO
        if (aviso_Qarr) {

            if (BANDERA_RETROCERQ == 1) {
                num = 0;
                AlarS = 0;
                aviso_Qarr = 0;
                BANDERA_quemador = 0;
                apagar_Q = 0;
                BANDERA_ALARQUEM = 1;
                CHEK_A = -1;
                tabla_sk = 1;
                BANDERA_RETROCERQ = 0;
                return;
            }

            if (BANDERA_ACTUALIZAQ == 1) {
                generar_A(0x650000, 0x1500, 0, 0);
                BANDERA_ACTUALIZAQ = 0;
            }

            if (quemadorloop >= (dR * 100)) {
                if (!Qmarch) {
                    Qarr = 1;
                    aviso_Qarr = 0;
                    BANDERA_quemador = 0;
                    num = 0;
                    apagar_Q = 0;
                    APQ = 0;
                    BANDERA_ALARQUEM = 1;
                    CHEK_A = -1;
                    RES1 = 5; // ERROR EN EL TIEMPO
                    tabla_sk = 1;
                    quemadorloop = 0;
                    return;
                } else {
                    aviso_Qarr = 0;
                    BANDERA_quemador = 0;
                    num = 0;
                    apagar_Q = 1;
                    APQ = 1;
                    BANDERA_ALARQUEM = 0;
                    CHEK_A = -1;
                    RES1 = 0; // NO ERRORES
                    tabla_sk = 1;
                    quemadorloop = 0;
                    return;
                }
            } else if ((quemadorloop >= 500) && (quemadorloop < (dR * 100))) {
                Qarr = 0;
            } else if (quemadorloop < 500) {
                sonido_2(quemadorloop);
            }
        }
        /*FIN del Ciclo de Encendido QUEMADOR*/

    } //FIN IF REACTOR HORNO

    if (BANDERA_RETROCERQ == 1) {
        Qarr = 1;
        aviso_Qarr = 0;
        BANDERA_quemador = 0;
        num = 0;
        apagar_Q = 0;
        BANDERA_ALARQUEM = 1;
        CHEK_A = -1;
        tabla_sk = 1;
        BANDERA_RETROCERQ = 0;
        return;
    }


    return;
}





