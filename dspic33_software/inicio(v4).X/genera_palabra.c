
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


extern  unsigned int tCIC;
extern  unsigned int PIR;
extern  unsigned int TIR;
extern  unsigned int TIB;
extern  unsigned int TIP;
extern  unsigned int TCF;
extern  unsigned int TD;
extern  unsigned int ND;
extern  unsigned int DB;
extern  unsigned int DA;
extern  unsigned int ApSApSV;
extern unsigned int ET;
extern unsigned int tETAP;
extern unsigned int FINAL;
extern unsigned int RES1;
extern unsigned int RES2;
extern unsigned int RES3;
extern unsigned int RES4;
extern unsigned int RES5;
extern unsigned int CHEK_A; 

extern unsigned int BufferA[TAM_DMA] __attribute__((space(dma)));// DE DECLARA TAMAÑO DMA
extern char aux_dma_tx[TAM_DMA];  // VARIABLE AUXILIAR PARA CARGAR EN DMA

void generar_A( int SK, int da, int db){
   DB=db;
   DA=da|DA;  
   
 CHEK_A=(TIR+PIR+ApSApSV+tCIC+TIB+TIP+TCF+TD+ND+SK+DA+DB+ET+tETAP+FINAL)&(0x00FF);
                  //datos    1   2   3   4   5   6   7   8   9  10  11  12  13  14  15  16  17  18  19  20  21      = caracteres 65
            
   sprintf(aux_dma_tx,"A=%.3x%.3x%.3x%.3x%.3x%.3x%.3x%.3x%.3x%.2x%.3x%.3x%.4x%.4x%.3x%.3x%.3x%.3x%.3x%.2x%.2x\n",
            TIR,PIR,ApSApSV,tCIC,TIB,TIP,TCF,TD,ND,ET,tETAP,FINAL,DA,DB,RES1,RES2,RES3,RES4,RES5,SK,CHEK_A);
                cargar_DMA_A(aux_dma_tx);
                 enviar_DMA();

  return;
}