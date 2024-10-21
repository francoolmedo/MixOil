/*
 * File:   rutinas_genericas.c
 * Author: Ing. Daniel Petrone
 *
 * Created on 3 de abril de 2023
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



//******************************************************************************
//                               CONVERSOR A/D
//******************************************************************************
//*******  Adquiere 4 canal analogico

unsigned int convierteAD(int icanal) {
    unsigned int uivalor_analogico;
    AD1CHS0bits.CH0SA = icanal + 16; //seleccion canal analogico
    AD1CHS0bits.CH0SB = 0;
    AD1CON1bits.SAMP = 1;
    __delay_us(100);
    AD1CON1bits.SAMP = 0;
    while (!AD1CON1bits.DONE); //espera fin de conversion
    uivalor_analogico = ADC1BUF0;

    //DATO[canal_analogico] = (((ADC1BUF0) + offset[columna]) * (ganancia[columna]/1000)); 
    //icanal = 0;
    return uivalor_analogico; //lleva nuevo valor analogico
}
//*******************  Fin adquisicion canal analogico  ************************





//******************************************************************************
//                                 U A R T
//******************************************************************************
//Transmite un caracter

/*
void putUART1(unsigned char cc) {
    while (U1STAbits.UTXBF); // Espera mientras el buffer de transmisión está lleno.
    U1TXREG = cc;
}

//Transmite una cadena

void putsUART1(unsigned char *s) {
    unsigned int a = 0;
    while (s[a]) // Se repite hasta el final de la cadena (*s == ?\0?).
        putUART1(s[a++]); // Envía un carácter y se posiciona para enviar el siguiente.
}

void getUART1(unsigned char rr) {
    while (U1STAbits.URXDA)
        rr = U1RXREG;
}

void getsUART1(unsigned char *r) {
    unsigned int a = 0;
    while (r[a])
        getUART1(r[a++]);
}
 */
//*******************************  Fin UART  ***********************************  


//******************************************************************************
//                                 D M A
//******************************************************************************

void enviar_DMA(void) {
    if (DMA0REQbits.FORCE == 0) {
        DMA0CONbits.CHEN = 1; // Enable DMA 
        DMA0REQbits.FORCE = 1; // Manual mode: Kick-start the 1st transfer  

    }

    return;
}

void cargar_DMA_A(char *enviar) {
    extern unsigned int BufferA[TAM_DMA] __attribute__((space(dma)));
    DMA0CNT = (TAM_DMA - 1); //CNT=7 PARA  8 DMA requests
    int h;
    //PONE A CERO EL BUFFER DE LA DMA
    for (h = 0; h <= (TAM_DMA - 1); h++) {
        BufferA[h] = 0;
    }
    //CARGA  EL BUFFER DE LA DMA
    for (h = 0; h <= (TAM_DMA - 1); h++) {
        BufferA[h] = enviar[h];
    }

    return;
}
//sobrecarga de funciom cargar_DMA_A para enviar 8 caracteres

void cargar_DMA_C(char *enviar) {
    extern unsigned int BufferA[TAM_DMA] __attribute__((space(dma)));
    DMA0CNT = 9; //CNT=7 PARA  8 DMA requests
    int h;
    //PONE A CERO EL BUFFER DE LA DMA
    for (h = 0; h <= (TAM_DMA - 1); h++) {
        BufferA[h] = 0;
    }
    //CARGA  EL BUFFER DE LA DMA
    for (h = 0; h <= (TAM_DMA - 1); h++) {
        BufferA[h] = enviar[h];
    }

    return;
}





//*******************************  Fin DMA  ***********************************

//******************************************************************************
//                               EEPROM 24CL256
//******************************************************************************
// EJEMPLO DE USO DE LA FUNCION escribir_Eeprom()
// escribir_Eeprom(constantes_Parametro,30,0); //maximo de datos a cargar 64 para 32 variables int

void escribir_Eeprom(const unsigned int *buff, unsigned int n, unsigned int pag) {
    // n cantidad de elementos maximo de datos a cargar (maximo 31 int) para 64 bytes
    // pag numero de pag partiendo del cero 0

    // Instantiate Drive and Data objects 

    I2CEMEM_DRV i2cmem = I2CSEMEM_DRV_DEFAULTS;
    I2CEMEM_DATA wData;
    unsigned int wBuff[64];
    unsigned int i;
    unsigned int direccion = 64;
    direccion = direccion*pag;

    direccion = direccion < 0x8000 ? direccion : 0;

    n = n <= 31 ? n : 0;

    i2cmem.init(&i2cmem); // Initialise I2C peripheral and Driver
    // Initialise Data to be written to serial EEPROM         
    for (i = 0; i < n; i++) {
        wBuff[2 * i] = (buff[i] & 0xFF00) >> 8; //parte alta 
        wBuff[2 * i + 1] = (buff[i] & 0x00FF); //parte baja

    }

    wData.buff = wBuff;
    wData.n = n << 1; //se escriben la cantidad *2 hasta completar 64 byte
    wData.addr = direccion; // direccion de la pagina 
    wData.csel = 0x00;

    // Write Data
    i2cmem.oData = &wData;
    i2cmem.cmd = I2C_WRITE;

    while (i2cmem.cmd != I2C_IDLE) {
        i2cmem.tick(&i2cmem);
    }



    return;
}

void leer_Eeprom(unsigned int *Eparam, unsigned int cantidad, unsigned int pag) {

    // n cantidad de elementos maximo de datos a leer (maximo 31 int) para 64 bytes
    // pag numero de pag partiendo del cero 0

    I2CEMEM_DRV i2cmem = I2CSEMEM_DRV_DEFAULTS;
    I2CEMEM_DATA rData;
    unsigned int rBuff[64];
    unsigned int i;
    unsigned int direccion = 64; //direccionen en multiplos de 64

    direccion = direccion*pag; // direccionen en multiplos de 64

    direccion = direccion < 0x8000 ? direccion : 0; //control de direccion final
    cantidad = cantidad <= 31 ? cantidad : 0;

    i2cmem.init(&i2cmem); // Initialise I2C peripheral and Driver

    // Initialise I2C Data Object for Read operation            

    rData.buff = rBuff;
    rData.n = (cantidad << 1); // cantidad de byte a leer de la memoria X2 byte
    rData.addr = direccion; // direccion de pagina en multiplo de  64d o 0x40h
    rData.csel = 0x00;


    // Read Data
    i2cmem.oData = &rData;
    i2cmem.cmd = I2C_READ;
    while (i2cmem.cmd != I2C_IDLE) {
        i2cmem.tick(&i2cmem);
    }


    for (i = 0; i <= cantidad; i++) {
        Eparam[i] = (rBuff[2 * i] << 8) | (rBuff[2 * i + 1]);

    }

    return;
}



//******************************************************************************
//                               RAMPA  DAC 0-255
//******************************************************************************
// GENERA LA RAMPA CON UN CONTADOR DE 0 A 255 

void RAMPA_Dac() {
    static unsigned char DAC;
    PIN_A1 = (DAC & 128) == 128 ? 1 : 0; //MSB
    PIN_A2 = (DAC & 64) == 64 ? 1 : 0;
    PIN_A3 = (DAC & 32) == 32 ? 1 : 0;
    PIN_A4 = (DAC & 16) == 16 ? 1 : 0;
    PIN_A5 = (DAC & 8) == 8 ? 1 : 0;
    PIN_A6 = (DAC & 4) == 4 ? 1 : 0;
    PIN_A7 = (DAC & 2) == 2 ? 1 : 0;
    PIN_A8 = (DAC & 1) == 1 ? 1 : 0; //LSB
    DAC++;



    return;
}




//*******************************  Fin RAMPA DAC  ******************************




//******************************************************************************
//                               Gestion QEI
//******************************************************************************
/*
int iOvf = 0;
//Lee valor contador

float LeerPosicion(void) {
    //Posicion lee el valor de cuenta cuando hay desborde del POSCNT
    float PosicionReal;

    PosicionReal = (POSCNT) +((float) (iOvf)*65535);
    return PosicionReal;
}
//Contador de overflow

void ControlarOverflows(void) {
    if ((!QEI1CONbits.UPDN)) {
        iOvf--;
    }
    if ((QEI1CONbits.UPDN)) {
        iOvf++;
    }
    return;
}

 */
//********************************  Fin QEI  ***********************************

