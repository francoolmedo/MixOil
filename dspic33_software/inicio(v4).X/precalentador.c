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
extern unsigned int NP5S;
extern unsigned int TP10S;
extern unsigned int dR;
extern unsigned int RX_CHEKA;
extern unsigned int SOFTK_A;
extern unsigned int SOFTK_N;
extern unsigned int SK_PRE;
extern unsigned int CHEK_A;
extern unsigned int num;
extern unsigned int Punto;
extern unsigned int ESTADO_1;

extern bool BANDERA_precalentador;
extern bool BANDERA_ACTUALIZAP;
extern bool BANDERA_ALARPRE;
extern bool tabla_sk;
extern bool BANDERA_RETROCERP;
extern bool no_precalentador;
extern bool REpc;

extern bool aviso_Parr; // VER CUAL CORRESPONDE
extern char dato_Rx[TAM_Rx];
extern bool APP;
extern bool apagar_P;
extern unsigned long int rx_enviar;
extern char aux_dma_tx[TAM_DMA]; // VARIABLE AUXILIAR PARA CARGAR EN DMA

extern unsigned int RES1;

extern unsigned int precalloop;
extern unsigned int TP1S;

void Precalentador() { //MANEJO DEL PREQUEMADOR Y DE IMPRESIONES

    tabla_sk = 0;
    CHEK_A = -1; // si se corta elmensaje manda H=0 OJO


    if (REpc == 0) {
        BANDERA_precalentador = 0;
        PCarr = 1;
        num = 0;
        BANDERA_ALARPRE = 1;
        CHEK_A = -1;
        RES1 = 6; // COLOCAR AVISO NO HAY REACTOR PRE
        tabla_sk = 1;

    }


    if (REpc == 1) { // HAY REACTOR EN EL PRE CALENTADOR

        if (!aviso_Parr) {

            if (!TP1S) {
                // MENSAJE ENCENDER PRE CALENTADOR
                generar_A(0x650800, 0x0600, 0, 0);

                if (BANDERA_RETROCERP == 1) {
                    num = 0;
                    AlarS = 0;
                    aviso_Parr = 0;
                    BANDERA_precalentador = 0;
                    apagar_P = 0;
                    BANDERA_ALARPRE = 1;
                    CHEK_A = -1;
                    tabla_sk = 1;
                    BANDERA_RETROCERP = 0;
                    return;
                }
            }

            // ESPERANDO TECLA SK - ENCENDER- ACTUALIZAR- RETORNAR
            if (TP10S == NP5S) {
                BANDERA_ACTUALIZAP = 1;

                //SK ACTUALIZAR CONDICION BANDERA NUM=1 ,BANDERA tabla_sk  =0
                if (BANDERA_ACTUALIZAP == 1) {
                    generar_A(0x650800, 0x0600, 0, 0);
                    BANDERA_ACTUALIZAP = 0;
                }
            }
            CHEK_A = -1;
        }


        if (aviso_Parr) {

            if (BANDERA_RETROCERP == 1) {
                num = 0;
                AlarS = 0;
                aviso_Parr = 0;
                BANDERA_precalentador = 0;
                apagar_P = 0;
                BANDERA_ALARPRE = 1;
                CHEK_A = -1;
                tabla_sk = 1;
                BANDERA_RETROCERP = 0;
                return;
            }

            generar_A(0x650000, 0x1700, 0, 0); // MENSAJE EN PROCESO DE ENCENDIDO

            CHEK_A = -1;

            //Comienza Rutina de Arranque: EN PROCESO DE ENCENDIDO

            if (aviso_Parr) {

                if (BANDERA_RETROCERP == 1) {
                    num = 0;
                    AlarS = 0;
                    aviso_Parr = 0;
                    BANDERA_precalentador = 0;
                    apagar_P = 0;
                    BANDERA_ALARPRE = 1;
                    CHEK_A = -1;
                    tabla_sk = 1;
                    BANDERA_RETROCERP = 0;
                    return;
                }

                if (BANDERA_ACTUALIZAP == 1) {
                    generar_A(0x650000, 0x1700, 0, 0);
                    BANDERA_ACTUALIZAP = 0;
                }


                if (precalloop >= (dR * 100)) {
                    if (!PCmarch) {
                        PCarr = 1;
                        aviso_Parr = 0;
                        BANDERA_precalentador = 0;
                        num = 0;
                        apagar_P = 0;
                        APP = 0;
                        BANDERA_ALARPRE = 1;
                        CHEK_A = -1;
                        RES1 = 5; // ERROR EN EL TIEMPO
                        tabla_sk = 1;
                        precalloop = 0;
                        return;
                    } else {
                        aviso_Parr = 0;
                        BANDERA_precalentador = 0;
                        num = 0;
                        apagar_P = 1;
                        APP = 1;
                        BANDERA_ALARPRE = 0;
                        CHEK_A = -1;
                        RES1 = 0; // NO ERRORES
                        tabla_sk = 1;
                        precalloop = 0;
                        return;
                    }
                } else if ((precalloop >= 500) && (precalloop < (dR * 100))) {
                    Qarr = 0;
                } else if (precalloop < 500) {
                    sonido_2(precalloop);
                }
            }

        } /*FIN del Ciclo de Encendido PRECALENTADOR*/

        if (BANDERA_RETROCERP == 1) {
            PCarr = 1;
            aviso_Parr = 0;
            BANDERA_precalentador = 0;
            num = 0;
            apagar_P = 0;
            BANDERA_ALARPRE = 1;
            CHEK_A = -1;
            tabla_sk = 1;
            BANDERA_RETROCERP = 0;
            return;
        }

        return;
    }




}
