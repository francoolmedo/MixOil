#include "configuraciones.h"

/******************************************************************************
 *     VARIABLES PARAMETROS ACTUALIZADA 8AGO23 ALMACENADA EN EEPROM24LC256    *
 ******************************************************************************/
//VALOR   | UNIDAD | NRO| SIGNIFICADO
extern unsigned int T; //mS      | 0 | Tiempo de Muestreo
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
extern unsigned int Esc500; // Adim  | 31 | 1000XFactor Mult Escala de T Int Reactor (0,500)  
extern unsigned int Esc800; // Adim  | 32 | 1000XFactor Mult Escala de T Cam Fuego (0,800)
extern unsigned int Esc060; // Adim  | 33 | 1000XFactor Mult Escala de Temp MixOil (0,059)
extern unsigned int EscMPX; // Adim  | 34 | 1000XFactor Mult Escala Pres Int Reactor (0,050)
extern unsigned int EscNIV; // Adim  | 35 | 10XFactor Mult Escala Vol Int Deposito (12,10)
extern unsigned int dPIR;
extern unsigned int ALARLAV;
extern unsigned int ALARINM;

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
    T = Eparam[0]; //mS      | 0 | Tiempo de Muestreo
    dR = Eparam[1]; //Minuto | 1  | Duración MINIMA de Encendido
    NDB = Eparam[2]; // cm	  | 2  | Ascenso Nivel MixOil xcada batch (Depósito)
    NDMAX = Eparam[3]; // cm    | 3  | Nivel Máximo MixOil (Depósito)
    NDMIN = Eparam[4]; // cm	  | 4  | Nivel Mínimo MixOil (Depósito)
    NEQ = Eparam[5]; // L/cm  | 5  | Convers Altura a Volumen (MixOil Deposito)
    PEMP = Eparam[6]; // kgf   | 6  | Peso de la Mat.Prima para un batch
    PETARA = Eparam[7]; // Kgf   | 7  | Peso del canasto vacío (en kgf) (Pesar)
    PIRMAX = Eparam[8]; // mBar  | 8  | Presión Máxima Interna (Umbral ALARMA)
    PIRNOM = Eparam[9]; // mBar  | 9  | Presión de trabajo Interna (Gauge)
    STALARM = Eparam[10]; // C     | 10 | Umbral de Alarma (Excede la CONSIGNA)
    TCCORT = Eparam[11]; // C     | 11 | Umbral de ALARMA por TC Cortada
    TCFAlar = Eparam[12]; // C     | 12 | Umbral de ALARMA de la Cámara de Fuego
    TDMax = Eparam[13]; // C     | 13 | Temp Max Interna Deposito MixOPil
    tESTR = Eparam[14]; // Seg   | 14 | Tiempo de Estrella (P/watch Dog)
    TEXT = Eparam[15]; // C     | 15 | Temp Max p/ extraer reactor Horno
    TIRBP = Eparam[16]; // C     | 16 | Banda Proporcioal para la TIR
    TIRC1 = Eparam[17]; // C     | 17 | Consigna en °C para TIR en ETAPA 1
    TIRC2 = Eparam[18]; // C     | 18 | Consigna en °C para TIR en ETAPA 2
    TIRC3 = Eparam[19]; // C     | 19 | Consigna en °C para TIR en ETAPA 3
    TIRNA = Eparam[20]; // N8bits| 20 | Consigna MAX - MIN en la variable TIRN
    TPCMAX = Eparam[21]; // C     | 21 | Temperatura Máxima de Pre Calentamiento
    tPIR1 = Eparam[22]; // Min   | 22 | Pirólisis: Duración Etapa 1
    tPIR2 = Eparam[23]; // Min   | 23 | Pirólisis: Duración Etapa 2
    tPIR3 = Eparam[24]; // Min   | 24 | Pirólisis: Duración Etapa 3
    TMAN = Eparam[25]; // C     | 25 | Temperatura de Pirólisis Etapa 1
    TPIRO1 = Eparam[26]; // C     | 26 | Temperatura de Pirólisis Etapa 1
    TPIRO2 = Eparam[27]; // C     | 27 | Temperatura de Pirólisis Etapa 2
    TPIRO3 = Eparam[28]; // C     | 28 | Temperatura de Pirólisis Etapa 3

    // pagina 1

    TVUELC = E1param[0]; // C     | 29 | Temp Max p/ volcar la carbonilla
    Esc500 = E1param[1]; // RESERVADO
    Esc800 = E1param[2]; // RESERVADO 
    Esc060 = E1param[3]; // RESERVADO
    EscMPX = E1param[4]; // RESERVADO 
    EscNIV = E1param[5]; // RESERVADO
    dPIR = E1param[6]; // RESERVADO
    ALARLAV = E1param[7]; // RESERVADO
    ALARINM = E1param[8]; // RESERVADO
    

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
