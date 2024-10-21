#include "configuraciones.h"

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

extern unsigned int Eparam[30]; //OJO TAMAÑO MAXIMO (32 INT) EQUIVALE A 64 BYTES POR PAGINA
extern unsigned int E1param[30];

// ----------CONTROL DE ERRORES EN COMUNICACION CHEKSUM 1 BYTE 0X00FF-----------

extern unsigned int CHEK_A; // VARIABLE DE CHEK A=
extern unsigned int CHEK_P; // VARIABLE DE CHEK PARAMETROS P=
extern unsigned int CHEK_C; // VARIABLE DE CHEK COMANDO C=
extern unsigned int CHEK_PAR; // CHEKSUM DE PARAMETROS

/******************************************************************************
 *                            FIN PARAMETROS                                  * 
 ******************************************************************************/

/******************************************************************************
 *                        PARAMETROS DERIVADOS                                *                                    *
 ******************************************************************************/
extern unsigned int TIRA;
extern unsigned int TIRIBP;

void control_param(void) {
    int i = 0;
    //CARGA DE PARAMETROS EXTRAIDOS DE MEMORIA A VARIABLES PARAMETROS
    // pagina 0
    dR = Eparam[0]; //Minuto | 1  | Duración MINIMA de Encendido
    NDB = Eparam[1]; // cm	  | 2  | Ascenso Nivel MixOil xcada batch (Depósito)
    NDMAX = Eparam[2]; // cm    | 3  | Nivel Máximo MixOil (Depósito)
    NDMIN = Eparam[3]; // cm	  | 4  | Nivel Mínimo MixOil (Depósito)
    NEQ = Eparam[4]; // L/cm  | 5  | Convers Altura a Volumen (MixOil Deposito)
    PEMP = Eparam[5]; // kgf   | 6  | Peso de la Mat.Prima para un batch
    PETARA = Eparam[6]; // Kgf   | 7  | Peso del canasto vacío (en kgf) (Pesar)
    PIRMAX = Eparam[7]; // mBar  | 8  | Presión Máxima Interna (Umbral ALARMA)
    PIRNOM = Eparam[8]; // mBar  | 9  | Presión de trabajo Interna (Gauge)
    STALARM = Eparam[9]; // C     | 10 | Umbral de Alarma (Excede la CONSIGNA)
    TCCORT = Eparam[10]; // C     | 11 | Umbral de ALARMA por TC Cortada
    TCFAlar = Eparam[11]; // C     | 12 | Umbral de ALARMA de la Cámara de Fuego
    TDMax = Eparam[12]; // C     | 13 | Temp Max Interna Deposito MixOPil
    tESTR = Eparam[13]; // Seg   | 14 | Tiempo de Estrella (P/watch Dog)
    TEXT = Eparam[14]; // C     | 15 | Temp Max p/ extraer reactor Horno
    TIRBP = Eparam[15]; // C     | 16 | Banda Proporcioal para la TIR
    TIRC1 = Eparam[16]; // C     | 17 | Consigna en °C para TIR en ETAPA 1
    TIRC2 = Eparam[17]; // C     | 18 | Consigna en °C para TIR en ETAPA 2
    TIRC3 = Eparam[18]; // C     | 19 | Consigna en °C para TIR en ETAPA 3
    TIRNA = Eparam[19]; // N8bits| 20 | Consigna MAX - MIN en la variable TIRN
    TPCMAX = Eparam[20]; // C     | 21 | Temperatura Máxima de Pre Calentamiento
    tPIR1 = Eparam[21]; // Min   | 22 | Pirólisis: Duración Etapa 1
    tPIR2 = Eparam[22]; // Min   | 23 | Pirólisis: Duración Etapa 2
    tPIR3 = Eparam[23]; // Min   | 24 | Pirólisis: Duración Etapa 3
    TMAN = Eparam[24]; // C     | 25 | Temperatura de Pirólisis Etapa 1
    TPIRO1 = Eparam[25]; // C     | 26 | Temperatura de Pirólisis Etapa 1
    TPIRO2 = Eparam[26]; // C     | 27 | Temperatura de Pirólisis Etapa 2
    TPIRO3 = Eparam[27]; // C     | 28 | Temperatura de Pirólisis Etapa 3
    TVUELC = Eparam[28]; // C     | 29 | Temp Max p/ volcar la carbonilla

    // pagina 1

    RESP1 = E1param[0]; // RESERVADO
    RESP2 = E1param[1]; // RESERVADO 
    RESP3 = E1param[2]; // RESERVADO
    RESP4 = E1param[3]; // RESERVADO 
    RESP5 = E1param[4]; // RESERVADO

    // HASTA EL MOMENTO SON 34 PARAMETROS TOTAL

    // *OBSERVACION : MAS DE 30 (SE DEBE CAMBIAR DE PAGINA EN LA EEPROM)

    /*SUMATORIA DE LOS PARAMETROS (CHEKSUM) CHEQUEO POR SUMA */

    for (i = 0; i <= 28; i++) {
        CHEK_PAR = Eparam[i] + E1param[i] + CHEK_PAR;
    }
    CHEK_P = CHEK_PAR & 0x00ff; // SOLO SE TOMA 1 BYTE DEL CHEKSUM (EL MAS BAJO)
    CHEK_C = (CHEK_P + 1)& 0x00ff;
    // CALCULOS DE PARAMETROS DERIVADOS DE LA TABLA DE PARAMETROS OJO DIVISION
    TIRA = TIRNA >= TIRBP ? (TIRNA / TIRBP) : 1;
    TIRIBP = TIRC1 >= TIRBP ? (TIRC1 - TIRBP) : 1;
    //------------------------------------------------------------ 

    return;
}
