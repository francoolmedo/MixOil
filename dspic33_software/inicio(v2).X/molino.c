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


extern bool Alarma_roja;
extern bool Alarma_verde;

extern unsigned int dR;
extern unsigned int RX_CHEKA;
extern unsigned int SOFTK_A;
extern unsigned int SOFTK_N;
extern unsigned int SK_PRE;
extern unsigned int CHEK_A;
extern unsigned int num;
extern unsigned int Punto;
extern unsigned int ESTADO_1;

extern bool BANDERA_molino;
extern bool BANDERA_ACTUALIZAM;
extern bool BANDERA_ALARMOL;
extern bool tabla_sk;
extern bool BANDERA_RETROCERM;
extern bool Cesto_0;
extern bool Cesto_1;

extern bool aviso_Larr; // VER CUAL CORRESPONDE
extern char dato_Rx[TAM_Rx];
extern bool APM;
extern bool apagar_M;
extern unsigned long int rx_enviar;

unsigned int timeout = 0;
unsigned int iloop = 0;

void Molino() {
    tabla_sk = 0;
    CHEK_A = -1; // si se corta elmensaje manda H=0 OJO


    /*CONDICIONES DEL CESTO EN ERROR */
    if (PE2 == 0 && PE1 == 1 && BANDERA_RETROCERM == 0) {
        Alarma_verde = 0;
        Alarma_roja = 1;

        Larr = 1;

        do { // Generar mensaje con error de Cesto escurrido: Condicion Problema en balanza
            __delay_ms(100);
            generar_A(0x600000, 0x2a6a, 0, 0);
            __delay_ms(100);

            if (strncmp(dato_Rx, "H=", 2) == 0)
                sscanf(dato_Rx, "H=%2x", &RX_CHEKA);

            timeout++;
        } while ((RX_CHEKA != CHEK_A) && timeout != 8);
        timeout = 0;

        do {
            if (BANDERA_RETROCERM == 1) {
                num = 0;
                break;
            }
        } while (!BANDERA_RETROCERM && PE2 == 0 && PE1 == 1);
    }

    if (PE2 == 1 && PE1 == 1 && BANDERA_RETROCERM == 0) {
        Alarma_verde = 0;
        Alarma_roja = 1;

        Larr = 1;

        do { // Generar mensaje con error de Cesto escurrido: No hay cesto
            __delay_ms(100);
            generar_A(0x600000, 0x5a6a, 0, 0);
            __delay_ms(100);

            if (strncmp(dato_Rx, "H=", 2) == 0)
                sscanf(dato_Rx, "H=%2x", &RX_CHEKA);

            timeout++;
        } while ((RX_CHEKA != CHEK_A) && timeout != 8);
        timeout = 0;

        do {
            if (BANDERA_RETROCERM == 1) {
                num = 0;
                break;
            }
        } while (!BANDERA_RETROCERM && PE2 == 1 && PE1 == 1);
    }

    if (PE2 == 0 && PE1 == 0 && BANDERA_RETROCERM == 0) {
        Alarma_verde = 0;
        Alarma_roja = 1;

        Larr = 1;

        do {
            // Generar mensaje con error de Cesto escurrido: Cesto lleno
            __delay_ms(100);
            generar_A(0x600000, 0x6a6a, 0, 0);
            __delay_ms(100);

            if (strncmp(dato_Rx, "H=", 2) == 0)
                sscanf(dato_Rx, "H=%2x", &RX_CHEKA);


            timeout++;
        } while ((RX_CHEKA != CHEK_A) && timeout != 8);
        timeout = 0;

        do {
            if (BANDERA_RETROCERM == 1) {
                num = 0;
                break;
            }
        } while (!BANDERA_RETROCERM && PE2 == 0 && PE1 == 0);
    }


    /*CONDICIONES DEL CESTO VACIO*/
    if (PE2 == 1 && PE1 == 0) { // HAY CESTO EN EL MOLINO VA ESTO (FRANCOCAMBIO) : PE2 == 1 && PE1 == 0

        AlarS = 0;

        if (BANDERA_molino == 1) {
            do {

                if (BANDERA_RETROCERM == 1) {
                    num = 0;
                    break;
                }
                // MENSAJE ENCENDER MOLINO
                __delay_ms(100);
                generar_A(0x650007, 0x0800, 0, 0);
                __delay_ms(100);

                if (strncmp(dato_Rx, "H=", 2) == 0)
                    sscanf(dato_Rx, "H=%2x", &RX_CHEKA);

                timeout++;
            } while (((RX_CHEKA != CHEK_A) && timeout != 8) && PE2 == 1 && PE1 == 0);
            timeout = 0;
        }

        do {

            if (BANDERA_RETROCERM == 1) {
                num = 0;
                break;
            }
            // ESPERANDO TECLA SK - ENCENDER- ACTUALIZAR- RETORNAR

            //SK ACTUALIZAR CONDICION BANDERA NUM=1 ,BANDERA tabla_sk  =0
            if (BANDERA_ACTUALIZAM == 1) {

                __delay_ms(100);
                generar_A(0x650007, 0x0800, 0, 0);
                __delay_ms(100);

                BANDERA_ACTUALIZAM = 0;

            }

            //AlarS = 1;
            __delay_ms(600);
            //sonido_2();

        } while (aviso_Larr == 0 && PE2 == 1 && PE1 == 0);

        CHEK_A = -1;


        if (BANDERA_molino == 1 && aviso_Larr == 1) {
            do {
                if (BANDERA_RETROCERM == 1) {
                    num = 0;
                    break;
                }
                //MENSAJE EN PROCESO DE ENCENDIDO
                __delay_ms(100);
                generar_A(0x650000, 0x1900, 0, 0);
                __delay_ms(100);

                if (strncmp(dato_Rx, "H=", 2) == 0)
                    sscanf(dato_Rx, "H=%2x", &RX_CHEKA);

                timeout++;
            } while ((RX_CHEKA != CHEK_A) && timeout != 8);
            timeout = 0;
            CHEK_A = -1;
        }

        //EN PROCESO DE ENCENDIDO
        if (BANDERA_molino == 1 && aviso_Larr == 1) {
            do {
                if (BANDERA_RETROCERM == 1) {
                    num = 0;
                    break;
                }

                if (BANDERA_ACTUALIZAM == 1) {
                    __delay_ms(100);
                    generar_A(0x650000, 0x1900, 0, 0);
                    __delay_ms(100);
                    BANDERA_ACTUALIZAM = 0;
                }


                if (iloop >= 1000) {
                    Larr = 0; // ENCENDER RELEE   
                    AlarS = 0;
                    BANDERA_ALARMOL = 0;
                    apagar_M = 1;
                    iloop = 0;
                    APM = 1;
                    num = 0;
                    tabla_sk = 1;
                    aviso_Larr = 0;
                    BANDERA_molino = 0;
                    break;
                }

                if (iloop <= 600) {
                    sonido_2(iloop);
                } else if (iloop > 600) {
                    sonido_1(iloop);
                }
                Alarma_verde = 1;
                Alarma_roja = 1;


                iloop++;
                __delay_ms(10);
            } while (Lmarch == 0 && PE2 == 1 && PE1 == 0); // mientras este apagado que intente prenderlo pasado el tiempo
        }
        /*FIN del Ciclo de Encendido MOLINO*/
    } 

    if (BANDERA_RETROCERM == 1) {
        AlarS = 0;
        aviso_Larr = 0;
        BANDERA_molino = 0;
        num = 0;
        apagar_M = 0;
        BANDERA_ALARMOL = 1;
        ESTADO_1 = 99;
        CHEK_A = -1;
        tabla_sk = 1;
    }

    Alarma_verde = 0;
    Alarma_roja = 0;
    BANDERA_RETROCERM = 0;
    return;
}