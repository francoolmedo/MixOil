/*
 * File:   APQ.c
 * Author: carlos
 *
 * Created on 4 de diciembre de 2023, 13:38
 */
#include "configuraciones.h"
#include "hardware.h"

extern unsigned int ET;

extern bool QMAR;
extern float TIRA;
extern int TIRIBP;
extern int TIRBP;
extern int TMAN;
extern int TIR;
extern int TIRN;
extern int TIRNA;
extern unsigned int Err;

void Apq(unsigned int CONSIGNA) {
    float TIR_MITAD;

    ET = 0;

    TIR_MITAD = (float) TIR / 2;
    /*CALCULOS DE PARAMETROS DERIVADOS*/
    TIRIBP = CONSIGNA - TIRBP;
    Err = CONSIGNA - TIR_MITAD;


    if (TIR_MITAD <= TIRIBP)
        TIRN = 255;

    if (TIR_MITAD > TIRIBP && TIR_MITAD < CONSIGNA)
        TIRN = TIRA * Err;

    if (TIR_MITAD >= CONSIGNA) {
        TIRN = 52;
    }

    if (TIRN < 52) {
        TIRN = 52;
    }



    PIN_A1 = (TIRN & 128) == 128 ? 1 : 0;
    PIN_A2 = (TIRN & 64) == 64 ? 1 : 0;
    PIN_A3 = (TIRN & 32) == 32 ? 1 : 0;
    PIN_A4 = (TIRN & 16) == 16 ? 1 : 0;
    PIN_A5 = (TIRN & 8) == 8 ? 1 : 0;
    PIN_A6 = (TIRN & 4) == 4 ? 1 : 0;
    PIN_A7 = (TIRN & 2) == 2 ? 1 : 0;
    PIN_A8 = (TIRN & 1) == 1 ? 1 : 0;



    return;
}