#include<uart.h>
#include<string.h>
#include<stdio.h>
#include"constantes.h"
#include "configuraciones.h"
#include "i2cEmem.h"
#include <p33FJ256MC710.h>
#define FCY 35007500UL
#define BAUDRATE 115000 //colocar 115000 para que BGRVAL=18 o 9596 para BGRVAL=227
#define BRGVAL ((FCY/BAUDRATE)/16)-1 
#include "libpic30.h"

//---------- BUFFER AUXILIAR PARA LA  DMA -------------------------------- 

extern unsigned int BufferA[TAM_DMA] __attribute__((space(dma))); // DE DECLARA TAMAÑO DMA
extern char aux_dma_tx[TAM_DMA]; // VARIABLE AUXILIAR PARA CARGAR EN DMA

/******************************************************************************
 *     VARIABLES PARAMETROS ACTUALIZADA 8AGO23 ALMACENADA EN EEPROM24LC256    *
 ******************************************************************************/
//VALOR   | UNIDAD | NRO| SIGNIFICADO
extern unsigned int dR; //Minuto | 1  | Duración MINIMA de Encendido 
extern unsigned int NDB; //cm	   | 2  | Ascenso Nivel MixOil xcada batch (Depósito)
extern unsigned int NDMAX; // cm    | 3  | Nivel Máximo MixOil (Depósito)
extern unsigned int NDMIN; // cm	   | 4  | Nivel Mínimo MixOil (Depósito)
extern unsigned int NEQ; // L/cm  | 5  | Convers Altura a Volumen (MixOil Deposito)
extern unsigned int PEMP; // kgf   | 6  | Peso de la Mat.Prima para un batch
extern unsigned int PETARA; // Kgf   | 7  | Peso del canasto vacío (en kgf) (Pesar)
extern unsigned int PIRMAX; // mBar  | 8  | Presión Máxima Interna (Umbral ALARMA)
extern unsigned int PIRNOM; // mBar  | 9  | Presión de trabajo Interna (Gauge)
extern unsigned int STALARM; // C     | 10 | Umbral de Alarma (Excede la CONSIGNA)
extern unsigned int TCCORT; // C     | 11 | Umbral de ALARMA por TC Cortada
extern unsigned int TCFAlar; // C     | 12 | Umbral de ALARMA de la Cámara de Fuego
extern unsigned int TDMax; // C     | 13 | Temp Max Interna Deposito MixOPil
extern unsigned int tESTR; // Seg   | 14 | Tiempo de Estrella (P/watch Dog)
extern unsigned int TEXT; // C     | 15 | Temp Max p/ extraer reactor Horno
extern unsigned int TIRBP; // C     | 16 | Banda Proporcioal para la TIR
extern unsigned int TIRC1; // C     | 17 | Consigna en °C para TIR en ETAPA 1
extern unsigned int TIRC2; // C     | 18 | Consigna en °C para TIR en ETAPA 2
extern unsigned int TIRC3; // C     | 19 | Consigna en °C para TIR en ETAPA 3
extern unsigned int TIRNA; // N8bits| 20 | Consigna MAX - MIN en la variable TIRN
extern unsigned int TPCMAX; // C     | 21 | Temperatura Máxima de Pre Calentamiento
extern unsigned int tPIR1; // Min   | 22 | Pirólisis: Duración Etapa 1
extern unsigned int tPIR2; // Min   | 23 | Pirólisis: Duración Etapa 2
extern unsigned int tPIR3; // Min   | 24 | Pirólisis: Duración Etapa 3
extern unsigned int TMAN; // C     | 25 | Temp a alcanzar en MODO MANUAL 
extern unsigned int TPIRO1; // C     | 26 | Temperatura de Pirólisis Etapa 1
extern unsigned int TPIRO2; // C     | 27 | Temperatura de Pirólisis Etapa 2
extern unsigned int TPIRO3; // C     | 28 | Temperatura de Pirólisis Etapa 3
extern unsigned int TVUELC; // C     | 30 | Temp Max p/ volcar la carbonilla
extern unsigned int RESP1; // NN    | 31 | Temp Max p/ volcar la carbonilla  
extern unsigned int RESP2; // NN    | 32 | Temp Max p/ volcar la carbonilla
extern unsigned int RESP3; // NN    | 33 | Temp Max p/ volcar la carbonilla
extern unsigned int RESP4; // NN    | 34 | Temp Max p/ volcar la carbonilla
extern unsigned int RESP5; // NN    | 35 | Temp Max p/ volcar la carbonilla
/******************************************************************************
 *                            FIN PARAMETROS                                  * 
 ******************************************************************************/


extern unsigned int Eparam[30]; //OJO TAMAÑO MAXIMO (32 INT) EQUIVALE A 64 BYTES POR PAGINA
extern unsigned int E1param[30];
extern unsigned int cons_param[30];
extern unsigned int cons_param1[30];

//-----------------------  BUFFER UART  1 -------------------------------- 
extern char dato_Rx[TAM_Rx];
// ----------CONTROL DE ERRORES EN COMUNICACION CHEKSUM 1 BYTE 0X00FF-----------

extern unsigned int CHEK_A; // VARIABLE DE CHEK A=
extern unsigned int CHEK_P; // VARIABLE DE CHEK PARAMETROS P=
extern unsigned int CHEK_C; // VARIABLE DE CHEK COMANDO C=
extern unsigned int CHEK_PAR; // CHEKSUM DE PARAMETROS


//char *Receiveddata=dato_Rx; 
extern unsigned int RX_CHEKP; // CONTROL DEL CHEK RECIBIDO UART 1
extern unsigned int RX_CHEKA;
extern unsigned int RX_CHEKC;
// unsigned int RX_CHEKS=0; // SOFTKEY

extern unsigned int SK_C; // CARTEL DE LAS SOFTKEY

void parametros(void) {

    SK_C = 2; // cambiar a pantalla de parametros
    CHEK_P = (CHEK_PAR + SK_C)&0X00FF;
    do {

        //    1   2   3   4   5   6   7   8   9   10  11  12  13  14  15  16  17  18  19  20  21  22  23  24  25  26  27  28  29  30  31  32  33  34        
        printf("P=%.3x%.3x%.3x%.3x%.3x%.3x%.3x%.3x%.3x%.3x%.3x%.3x%.3x%.3x%.3x%.3x%.3x%.3x%.3x%.3x%.3x%.3x%.3x%.3x%.3x%.3x%.3x%.3x%.3x%.3x%.3x%.3x%.3x%.3x%.2x%.2x\n",
                dR, NDB, NDMAX, NDMIN, NEQ, PEMP, PETARA, PIRMAX, PIRNOM, STALARM, TCCORT, TCFAlar, TDMax, tESTR, TEXT, TIRBP, TIRC1, TIRC2, TIRC3, TIRNA, TPCMAX, tPIR1, tPIR2, tPIR3, TMAN, TPIRO1, TPIRO2, TPIRO3, TVUELC, RESP1, RESP2, RESP3, RESP4, RESP5, SK_C, CHEK_P);
        //               1  2   3    4     5   6     7      8      9      10      11     12      13    14    15   16   17     18    19    20     21    22     23   24   25       26    27     28     29   30   31

        __delay_ms(20);
        if (strncmp(dato_Rx, "H=", 2) == 0)
            sscanf(dato_Rx, "H=%2x", &RX_CHEKP);
        __delay_ms(30);
    } while (RX_CHEKP != CHEK_P);

    //------------- ESPERA LA RECEPCION DE DATOS VALIDA POR UART 1 ------------ 

    SK_C = 0;
    CHEK_P = (CHEK_PAR + SK_C)&0X00FF;
    do {

        //    1   2   3   4   5   6   7   8   9   10  11  12  13  14  15  16  17  18  19  20  21  22  23  24  25  26  27  28  29  30  31  32  33  34  35 36      
        printf("P=%.3x%.3x%.3x%.3x%.3x%.3x%.3x%.3x%.3x%.3x%.3x%.3x%.3x%.3x%.3x%.3x%.3x%.3x%.3x%.3x%.3x%.3x%.3x%.3x%.3x%.3x%.3x%.3x%.3x%.3x%.3x%.3x%.3x%.3x%.2x%.2x\n",
                dR, NDB, NDMAX, NDMIN, NEQ, PEMP, PETARA, PIRMAX, PIRNOM, STALARM, TCCORT, TCFAlar, TDMax, tESTR, TEXT, TIRBP, TIRC1, TIRC2, TIRC3, TIRNA, TPCMAX, tPIR1, tPIR2, tPIR3, TMAN, TPIRO1, TPIRO2, TPIRO3, TVUELC, RESP1, RESP2, RESP3, RESP4, RESP5, SK_C, CHEK_P);
        //               1  2   3    4     5   6     7      8      9      10      11     12      13    14    15   16   17     18    19    20     21    22     23   24   25     26    27     28     29     30    31     32   33    34   35    36                                                                              26    27     28     29   30   31

        __delay_ms(20);
        if (strncmp(dato_Rx, "H=", 2) == 0)
            sscanf(dato_Rx, "H=%2x", &RX_CHEKP);
        __delay_ms(10);
    } while (RX_CHEKP != CHEK_P);


    RX_CHEKP = 0;



    do {


        if (strncmp(dato_Rx, "G=", 2) == 0) {
            //1  2  3  4  5  6  7  8  9 10  11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 
            sscanf(dato_Rx, "G=%3x%3x%3x%3x%3x%3x%3x%3x%3x%3x%3x%3x%3x%3x%3x%3x%3x%3x%3x%3x%3x%3x%3x%3x%3x%3x%3x%3x%3x%3x%3x%3x%3x%3x%2x",
                    &dR, &NDB, &NDMAX, &NDMIN, &NEQ, &PEMP, &PETARA, &PIRMAX, &PIRNOM, &STALARM, &TCCORT, &TCFAlar, &TDMax, &tESTR, &TEXT, &TIRBP, &TIRC1, &TIRC2, &TIRC3, &TIRNA, &TPCMAX, &tPIR1, &tPIR2, &tPIR3, &TMAN, &TPIRO1, &TPIRO2, &TPIRO3, &TVUELC, &RESP1, &RESP2, &RESP3, &RESP4, &RESP5, &RX_CHEKP);
            //  1   2     3       4     5    6     7       8       9        10       11     12       13     14    15     16     17     18    19      20     21      22     23    24     25    26      27      28       29     30      31    32     33     34     35      36 

            //      1    2    3    4    5    6      7      8      9     10     11    12      13    14    15    16    17    18    19    20    21    22     23     24   25   26     27    28     29     30      31   32   33     34                                                                                             
            CHEK_P = (dR + NDB + NDMAX + NDMIN + NEQ + PEMP + PETARA + PIRMAX + PIRNOM + STALARM + TCCORT + TCFAlar + TDMax + tESTR + TEXT + TIRBP + TIRC1 + TIRC2 + TIRC3 + TIRNA + TPCMAX + tPIR1 + tPIR2 + tPIR3 + TMAN + TPIRO1 + TPIRO2 + TPIRO3 + TVUELC + RESP1 + RESP2 + RESP3 + RESP4 + RESP5)&(0x00ff);

        }

        __delay_ms(50);

    } while (CHEK_P != RX_CHEKP);


    //CARGA DE PARAMETROS EXTRAIDOS DE MEMORIA A VARIABLES PARAMETROS

    //PAG 0

    cons_param[0] = dR; //Minuto | 1  | Duración MINIMA de Encendido
    cons_param[1] = NDB; // cm	| 2  | Ascenso Nivel MixOil xcada batch (Depósito)
    cons_param[2] = NDMAX; // cm    | 3  | Nivel Máximo MixOil (Depósito)
    cons_param[3] = NDMIN; // cm	| 4  | Nivel Mínimo MixOil (Depósito)
    cons_param[4] = NEQ; // L/cm  | 5  | Convers Altura a Volumen (MixOil Deposito)
    cons_param[5] = PEMP; // kgf   | 6  | Peso de la Mat.Prima para un batch
    cons_param[6] = PETARA; // Kgf   | 7  | Peso del canasto vacío (en kgf) (Pesar)
    cons_param[7] = PIRMAX; // mBar  | 8  | Presión Máxima Interna (Umbral ALARMA)
    cons_param[8] = PIRNOM; // mBar  | 9  | Presión de trabajo Interna (Gauge)
    cons_param[9] = STALARM; // C     | 10 | Umbral de Alarma (Excede la CONSIGNA)
    cons_param[10] = TCCORT; // C     | 11 | Umbral de ALARMA por TC Cortada
    cons_param[11] = TCFAlar; // C     | 12 | Umbral de ALARMA de la Cámara de Fuego
    cons_param[12] = TDMax; // C     | 13 | Temp Max Interna Deposito MixOPil
    cons_param[13] = tESTR; // Seg   | 14 | Tiempo de Estrella (P/watch Dog)
    cons_param[14] = TEXT; // C     | 15 | Temp Max p/ extraer reactor Horno
    cons_param[15] = TIRBP; // C     | 16 | Banda Proporcioal para la TIR
    cons_param[16] = TIRC1; // C     | 17 | Consigna en °C para TIR en ETAPA 1
    cons_param[17] = TIRC2; // C     | 18 | Consigna en °C para TIR en ETAPA 2
    cons_param[18] = TIRC3; // C     | 19 | Consigna en °C para TIR en ETAPA 3
    cons_param[19] = TIRNA; // N8bits| 20 | Consigna MAX - MIN en la variable TIRN
    cons_param[20] = TPCMAX; // C     | 21 | Temperatura Máxima de Pre Calentamiento
    cons_param[21] = tPIR1; // Min   | 22 | Pirólisis: Duración Etapa 1
    cons_param[22] = tPIR2; // Min   | 23 | Pirólisis: Duración Etapa 2
    cons_param[23] = tPIR3; // Min   | 24 | Pirólisis: Duración Etapa 3
    cons_param[24] = TMAN; // C     | 25 | Temperatura de Pirólisis Etapa 1
    cons_param[25] = TPIRO1; // C     | 26 | Temperatura de Pirólisis Etapa 1
    cons_param[26] = TPIRO2; // C     | 27 | Temperatura de Pirólisis Etapa 2
    cons_param[27] = TPIRO3; // C     | 28 | Temperatura de Pirólisis Etapa 3
    cons_param[28] = TVUELC; // C     | 29 | Temp Max p/ volcar la carbonilla
    // PAG 1
    cons_param1[0] = RESP1; // RESERVADO
    cons_param1[1] = RESP2; // RESERVADO
    cons_param1[2] = RESP3; // RESERVADO
    cons_param1[3] = RESP4; // RESERVADO
    cons_param1[4] = RESP5; // RESERVADO



    escribir_Eeprom(cons_param, 30, 0);
    __delay_ms(5);
    escribir_Eeprom(cons_param1, 30, 1);
    __delay_ms(5);


    return;
} 