/*******************************************************************************
 * File:   main.c
 * Author:  
 * Title:  U9  
 * 
 * Created on 26 de febrero de 2024
 * 
 *  NOTA: 
 * 
 * 
 ******************************************************************************/
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
#include <spi.h>
#include <stdlib.h>

/*  Configuracion Puerto serial para velocidades de 115200 - 9600 Baudios*/
#define FCY 35007500UL
#define BAUDRATE 115000 //colocar 115000 para que BGRVAL=18 o 9596 para BGRVAL=227
#define BRGVAL ((FCY/BAUDRATE)/16)-1 
#include "libpic30.h"


uint8_t dataout = 'c';

/* SPI */

uint8_t receiveBuffer[N_BYTES] = {0};
uint8_t sendBuffer[N_BYTES] = {0};
char estado_actual = '0';
char stop_mensaje = '0';
char mensaje[N_BYTES] = {0};
int spi_timeout = 0;
int spi_timeout2 = 0;
uint8_t receiveIndex = 0;
uint8_t sendIndex = 0;
char syncspi[] = "I=";
int syncspiIndex = 0;
uint8_t synced = 0;
char indices_validos[] = {'I', 'D', 'M', 'P', 'R', 'A'};
uint8_t Write_SPI1(uint8_t command);



bool PANTALLA_PARAMETRO = 0; //BANDERAS DE MANEJO (TX/RX)_SPI PANTALLA PARAMETRO
bool PANTALLA_INICIO = 0; //BANDERAS DE MANEJO (TX/RX)_SPI PANTALLA INICIO
bool PANTALLA_PRINCIPAL = 0; //BANDERAS DE MANEJO (TX/RX)_SPI PANTALLA PRINCIPAL

unsigned int CRC_P = 0;

/*TODAS LAS VARIABLES DE PRUEBA ESTAN ACA */

unsigned int POSICION[7] = {0, 0, 1, 2, 3, 4, 5}; // posicion del servo



/*-------------------------------------------*/
// ********** DEFINICIONES ***********
float version = 260224;
/*MEMORIA 24LC256*/
//1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30
//unsigned int cons_param[30]={10,20,30,40,50,60,70,80,90,100,110,120,130,140,150,160,170,180,190,200,210,220,230,240,250,260,270,280,290,300};
//unsigned int cons_param1[30]={310,320,330,340,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
unsigned int cons_param[30] = {0};
unsigned int cons_param1[30] = {0};
unsigned long CHEKSUM = 0;
unsigned int CHEK_S = 0;
/*VARIABLES TABLA DE PARAMETROS*/
unsigned int NG1F = 0;
unsigned int NG1W = 0;
unsigned int NG2F = 0;
unsigned int NG2W = 0;
unsigned int NG3F = 0;
unsigned int NG3W = 0;
unsigned int NG4F = 0;
unsigned int NG4W = 0;
unsigned int NG5F = 0;
unsigned int NG5W = 0;
unsigned int PEP = 0;
unsigned int PEPd = 0;
unsigned int PG0F = 0;
unsigned int PG0W = 0;
unsigned int TC1 = 0;
unsigned int TC2 = 0;
unsigned int TRT = 0;
unsigned int RES1 = 0;
unsigned int RES2 = 0;
unsigned int RES3 = 0;
unsigned int RES4 = 0;
unsigned int RES5 = 0;
unsigned int RES6 = 0;
unsigned int RES7 = 0;
unsigned int RES8 = 0;
unsigned int RES9 = 0;
unsigned int RES10 = 0;
unsigned int RES11 = 0;
unsigned int RES12 = 0;
unsigned int RES13 = 0;
unsigned int RES14 = 0;
unsigned int RES15 = 0;
unsigned int RES16 = 0;
unsigned int RES17 = 0;



/*FIN VARIABLE TABLA DE PARAMETROS*/

// CINTAS -MC0A -MC0B 100 MS Y LUEGO APAGA  POR 200MS Y EMPIEZA A FUNCIONAR EL
// SENSOR CON LOS PULSOS BT  

//------------------------------------------------------------------------------ 
char dato_Rx[TAM_Rx];
unsigned int BufferA[TAM_DMA] __attribute__((space(dma)));
/*****************************************************************************
 *                          FIN VARIABLES COMUNICACION                       *
 *****************************************************************************/

/******************************************************************************
 *                   VARIABLE PARA LAS SEÑALES ANALOGICAS                     *
 ******************************************************************************/
float Peso_cajon = 0;
unsigned int Peso_tara = 0;
uint8_t Tarea_Peso = 0;
unsigned int V[CAN_ANALOG] = {0}; // CONVERSIONES ANALOGAS DIGITALES

/******************************************************************************
 *                       FIN VARIABLES ANALOGICAS                             *  
 ******************************************************************************/


/* VARIABLES PARA FORMAR BASE DE TIEMPO */

bool BANDERA_FLANCO_BT = 0;
unsigned long int PERIODO_BT = 0;
unsigned int BT = 0;
unsigned int TR1_TRIG = 0;
bool NUEVO_BT = 0; // VARIABLES DE PULSO DIGITAL FLANCOS DE BT
bool ANTERIOR_BT = 0;
int retardo_bfe = 0;


// VERSION ANTERIOR
unsigned int TIEMPO_H_C0A = 0; // ESTE ES UN PARAMETRO EL CUAL CONTIENE TIEMPO ENCENDIDO+APAGADO
bool BANDERA_TIEMPO_H_COA = 0;
//---------------------------

unsigned int PERIODO1_H_COA = 0;
bool BANDERA_TIEMPO1_H_COA = 0;

unsigned int PERIODO2_H_COA = 0;
bool BANDERA_TIEMPO2_H_COA = 0;

unsigned int PERIODO_PTRG = 0;
bool BANDERA_PTRG = 0;

// unsigned long int PERIODO_PWM1=0; // SE USA PERISFERICO PWM 
unsigned PERIODO_FOTO = 0;


/*****************************************************************
 *                      FIN VARIABLES BASE TIEMPO                 *
 ******************************************************************/

/******************************************************************
 BANDERAS PULSADORES CICLO EVITAR REBOTES
 *******************************************************************/
bool CONFIRMACION_PUL_CIC = 0;
bool ANTERIOR_PUL_CIC = 0;
bool NUEVO_PUL_CIC = 0;

/******************************************************************
 BANDERAS PULSADOR DETENCION EVITAR REBOTES 
 *******************************************************************/
bool CONFIRMACION_PUL_DET = 0;
bool ANTERIOR_PUL_DET = 0;
bool NUEVO_PUL_DET = 0;

/***********************************************************************
   B= BANDERA                  BIT 2           BIT 1     BIT 0         *
 * ESTADO DEL PROGRAMA ESTADO=B_DETENCION B_REFERENCIA  B_CICLO        *
 **********************************************************************/
bool BANDERA_DETENCION = 0;
bool BANDERA_REFERENCIA = 0; // SE PRECIONO REFERENCIA 
bool BANDERA_CICLO = 0;


unsigned int ESTADO_PROGRAMA = 0;

/***********************************************************************
 *   VARIABLES DE REFERENCIA CINTA SEPARACION PAPAS                         * 
 * *********************************************************************/
bool BANDERA_SERVO_REFERENCIADO = 0;

/**********************************************************************
 *    VARIABLES DE SENSORES PARA LA CONFIRMACION L1  BF1 STROBE EVITAR REBOTES
 **********************************************************************/
bool NUEVO_RSE = 0;
bool ANTERIOR_RSE = 0;
bool CONFIRMADO_RSE = 0;

bool NUEVO_L1 = 0;
bool ANTERIOR_L1 = 0;
bool CONFIRMADO_L1 = 0;

bool NUEVO_BFE1 = 0;
bool ANTERIOR_BFE1 = 0;
bool CONFIRMADO_BFE1 = 0;
int LIMPIAR_BF1 = 0;

// SEÑAL DIGITAL RASPBERRY PI
bool NUEVO_STROBE = 0;
bool ANTERIOR_STROBE = 0;
bool CONFIRMADO_STROBE = 0;

unsigned int GRADO = 0;
unsigned int GRADO_NUEVO = 0;
unsigned int GRADO_ANTERIOR = 0;
bool INICIO_PROGRAMA = 0;


int p = 0; // PRUEBA DE POSICIONES

int main(void) {


    int i = 0; // variable usada para ciclos   

    //----------------------------------------------------------------------------//
    //        INICIO DE EJECUCION DEL PROMAGRAMA LUEGO DEL ENCENDIDO
    //----------------------------------------------------------------------------//    

    configurarSistema(); //Deshabilita WDT,configura PLL y Entradas/Salidas
    //inicializaUART(BRGVAL); //Inicializa UART     
    inicializaADC(); //Inicializacion ADC 10 bit
    //    inicializaDMA(); //Inicializa DMA
    inicializaSPI_SLAVE();
    PWM_Init();
    inicializaTimer2(); //iniciliza timer2 (NO INICIA) 


    PANTALLA_INICIO = 1;
    PANTALLA_PARAMETRO = 0;
    PANTALLA_PRINCIPAL = 0;
    /* ESCRITURA/LECTURA  MEMORIA  */

    // SE DEBE ESCRIBIR LOS PARAMETROS EN MEMORIA POR PRIMERA VEZ 

    __delay_ms(2);
    escribir_Eeprom(cons_param, 30, 0); // Carga parametros pag 0 desde Eeprom24CL256
    __delay_ms(2);
    escribir_Eeprom(cons_param1, 30, 1); // Carga parametros pag 0 desde Eeprom24CL256


    // SE ESCRIBE SIEMPRE TODA UNA PAGINA Y SE LEE TODA UNA PAGINA
    //  LA PAGINA PUEDE NO ESTAR COMPLETA 30 ELEMENTOS POR PAGINA

    __delay_ms(2);
    leer_Eeprom(cons_param, 30, 0); // Carga parametros pag 0 desde Eeprom24CL256

    __delay_ms(2);
    leer_Eeprom(cons_param1, 30, 1); // Carga parametros pag 0 desde Eeprom24CL256





    for (i = 0; i <= 29; i++)
        CHEKSUM = CHEKSUM + cons_param[i]; // SUMA DE PARAMETROS DEL 0 AL 28 (29 ALMACENA CHEKSUM)


    for (i = 0; i <= 29; i++)
        CHEKSUM = CHEKSUM + cons_param1[i]; // SUMA DE PARAMETROS DEL 0 AL 28 (29 ALMACENA CHEKSUM)


    CHEK_S = (CHEKSUM & 0xFFFF); //TOMA SOLO 4 BYTE DE LA SUMATORIA COMO CHEKSUM




    /* CONFIRMACION DEL ENLACE SPI MEDIANTE CRC_PARAMETROS */


    STATUS_LED = 1;


    /*COMPROBAR LOS PARAMETROS RECIBIDO CON EL ENVIADO*/
    //    if (CHEKSUM == INI) {
    //        INI = 0;
    //        PANTALLA_PARAMETRO = 0;
    //        PANTALLA_PRINCIPAL = 0;
    //        PANTALLA_INICIO = 1;
    //
    //        /*ACTUALIZA TABLA DE PARAMETROS */
    //        NG1F = cons_param[0];
    //        NG1W = cons_param[1];
    //        NG2F = cons_param[2];
    //        NG2W = cons_param[3];
    //        NG3F = cons_param[4];
    //        NG3W = cons_param[5];
    //        NG4F = cons_param[6];
    //        NG4W = cons_param[7];
    //        NG5F = cons_param[8];
    //        NG5W = cons_param[9];
    //        PEP = cons_param[10];
    //        PEPd = cons_param[11];
    //        PG0F = cons_param[12];
    //        PG0W = cons_param[13];
    //        TC1 = cons_param[14];
    //        TC2 = cons_param[15];
    //        TRT = cons_param[16];
    //        RES1 = cons_param[17];
    //        RES2 = cons_param[18];
    //        RES3 = cons_param[19];
    //        RES4 = cons_param[20];
    //        RES5 = cons_param[21];
    //        RES6 = cons_param[22];
    //        RES7 = cons_param[23];
    //        RES8 = cons_param[24];
    //        RES9 = cons_param[25];
    //        RES10 = cons_param[26];
    //        RES11 = cons_param[27];
    //        RES12 = cons_param[28];
    //        RES13 = cons_param[29];
    //        RES14 = cons_param1[1];
    //        RES15 = cons_param1[2];
    //        RES16 = cons_param1[3];
    //        RES17 = cons_param1[4];
    //
    //        /*FIN DE CARGA DE TABLA PARAMETROS*/
    //
    //    }


    /* FIN DE LA COMPROBACION */


    /*
    if (CRC_P == RX_CRC) {
        escribir_Eeprom(cons_param, 30, 0); // Carga parametros pag 0 desde Eeprom24CL256
        __delay_ms(200);
        escribir_Eeprom(cons_param1, 4, 1); // Carga parametros pag 0 desde Eeprom24CL256
        __delay_ms(200);

        __asm__ volatile ( "reset "); //Instruccion de reinicio A LA SALIDA DE PARAMETROS 


    }
     */

    /* FIN DE LA NUEVA LECTURA DE PARAMETROS */
    sendBuffer[0] = 'I';
    sendBuffer[1] = '=';
    sendBuffer[2] = 'c';
    sendBuffer[3] = 'r';
    sendBuffer[4] = 'c';
    sendBuffer[5] = '-';
    sendBuffer[6] = '5';
    sendBuffer[7] = '9';
    sendBuffer[8] = '3';
    sendBuffer[9] = '6';
    sendBuffer[10] = 'x';
    sendBuffer[11] = 'X';


    __delay_ms(80);




    int timerx = 0;
    int oksync = 0;


    /*----------------  FIN DEL RESET ------------------- */

    /* EMPIEZA PROGRAMA PAPAS */

    HAB_SRV = 0; //DESHABILITA SERVOS  DRIVER TECO POSICIONADOR

    while (1) {

        do {

            if (!EXTCICLO) {
                LISTO = 1; // ALIMENTACION 
            }

            RUN_Timer2();

            __delay_ms(500);

            STATUS_LED = 1;
            while (A_SRV == 0);



            // ESPERA SEÑAL RSE ACTIVADA: PARA ESTO SE DEBE PULSAR SERVOS (PEMG))

        } while (CONFIRMADO_RSE == 1); // ESPERA LA ENTRADA RSE==0 (PULSADOR SERVOS=PEMG) 
        INICIO_PROGRAMA = 1;
        STATUS_LED = !CONFIRMADO_RSE;


        HAB_SRV = 1; //HABILITA SERVOS  DRIVER TECO POSICIONADOR

        do {


            for (int i = 0; i < N_BYTES - 1; i++) {
                if (receiveBuffer[i] == 'I') {
                    oksync = 1;
                } else if (receiveBuffer[i] == 'D') {
                    oksync = 1;
                } else if (receiveBuffer[i] == 'P') {
                    oksync = 1;
                } else if (receiveBuffer[i] == 'M') {
                    oksync = 1;
                } else if (receiveBuffer[i] == 'R') {
                    oksync = 1;
                } else if (receiveBuffer[i] == 'A') {
                    oksync = 1;
                } else {
                    oksync = 0;
                }
                if (oksync == 1) {
                    syncspiIndex = i;
                    for (int j = 0; j < N_BYTES - 1; j++) {
                        mensaje[j] = receiveBuffer[j];
                    }
                    estado_actual = mensaje[i];
                }
            }

            switch (estado_actual) {
                case 'I':
                    for (int i = syncspiIndex; i <= N_BYTES - 1; i++) {
                        if (mensaje[i] == 'X') {
                            for (int j = 0; j < N_BYTES - 1; j++) {
                                sendBuffer[j] = mensaje[j];
                            }
                            break;
                        }
                    }
                    break;
                case 'D':
                    for (int i = 0; i <= N_BYTES - 1; i++) {
                        if (mensaje[i] == 'X') {
                            for (int j = 0; j < N_BYTES - 1; j++) {
                                sendBuffer[j] = mensaje[j];
                            }
                            break;
                        }
                    }
                    break;
                case 'P':
                    for (int i = 0; i <= N_BYTES - 1; i++) {
                        if (mensaje[i] == 'X') {
                            for (int j = 0; j < N_BYTES - 1; j++) {
                                sendBuffer[j] = mensaje[j];
                            }
                            break;
                        }
                    }
                    break;
                case 'M':
                    for (int i = 0; i <= N_BYTES - 1; i++) {
                        if (mensaje[i] == 'X') {
                            for (int j = 0; j < N_BYTES - 1; j++) {
                                sendBuffer[j] = mensaje[j];
                            }
                            break;
                        }
                    }
                    break;
                case 'R':
                    for (int i = 0; i <= N_BYTES - 1; i++) {
                        if (mensaje[i] == 'X') {
                            for (int j = 0; j < N_BYTES - 1; j++) {
                                sendBuffer[j] = mensaje[j];
                            }
                            break;
                        }
                    }

                    break;
                case 'A':
                    for (int i = 0; i <= N_BYTES - 1; i++) {
                        if (mensaje[i] == 'X') {
                            for (int j = 0; j < N_BYTES - 1; j++) {
                                sendBuffer[j] = mensaje[j];
                            }
                            break;
                        }
                    }
                    break;
                default:
                    /*
                    if (spi_timeout2 == 12) {
                        for (int i = 0; i <= N_BYTES - 1; i++) {
                            receiveBuffer[i] = 0;
                            sendBuffer[i] = 0;
                            mensaje[i] = 0;
                        }
                        spi_timeout2 = 0;
                    } else {
                        spi_timeout2++;
                    }
                     */

                    if (spi_timeout == 150) {
                        SPI1STATbits.SPIEN = 0;
                        __delay_ms(300);
                        SPI1BUF = 0;
                        SPI1STATbits.SPIROV = 0; // Limpiar overflow
                        SPI1STATbits.SPIEN = 1;
                        spi_timeout = 0;
                    } else {
                        spi_timeout++;
                    }
                    break;

            }

            timerx++;
            if (timerx == 5) {
                STATUS_LED = 1;
            } else if (timerx == 10) {
                STATUS_LED = 0;
                timerx = 0;
            }
            if (oksync == 0) {
                __delay_ms(500);
            } else {
                __delay_ms(1000);
            }


            switch (ESTADO_PROGRAMA) // ESTADO DE LOS PULSADORES DETENCION REFERENCIA CICLO
            {
                case 0:

                    if (A_SRV == 1 && BANDERA_SERVO_REFERENCIADO == 0) { // EL SERVO ESTA LISTO VER A_SRV ESTADO INICIAL
                        referenciar(); // INICIO/FUERA DE REFERENCIA SERVO
                    }

                    break;
                case 2:

                    break;


                case 3:
                    ciclo_papas(); //SE DA COMIENZO AL CICLO  


                    break;

                case 6:
                    //Se detiene la cinta separadora con el sensor L1
                    if (L1 == 1) {
                        H_C1 = 0; // APAGA CINTA C1B
                    }
                    H_C0A = 0;
                    H_C2 = 0;
                    //Limpia bandera de ciclo, de referencia y detencion
                    BANDERA_CICLO = 0;
                    BANDERA_REFERENCIA = 0;
                    BANDERA_DETENCION = 0;

                    break;

                case 7: //  SE PULSA DETENCION
                    //Se detiene la cinta separadora con el sensor L1
                    if (!L1 == 1) {
                        H_C1 = 0; // APAGA CINTA C1B
                    }
                    H_C0A = 0;
                    H_C2 = 0;
                    //Limpia bandera de ciclo, de referencia y detencion
                    BANDERA_CICLO = 0;
                    BANDERA_REFERENCIA = 0;
                    BANDERA_DETENCION = 0;
                    break;

                default:
                    break;

            }


        } while (CONFIRMADO_RSE == 0);



        __delay_ms(100);
        __asm__ volatile ( "reset "); //Instruccion de reinicio A LA SALIDA DE PARAMETROS 


    }// FINAL DE LA TAREA NO PERIODICA     
    return 0;

}

uint8_t Write_SPI1(uint8_t command) { //Does work    
    SPI1BUF = command; // send data over SPI
    while (!SPI1STATbits.SPIRBF); //wait until SPIRBF goes high 

    return SPI1BUF; //KEY STATEMENT THAT MADE A DIFFERENCE, Return the actual data received
}

void __attribute__((__interrupt__, no_auto_psv)) _SPI1Interrupt(void) {
    SPI1STATbits.SPIROV = 0; // Limpiar overflow


    receiveBuffer[receiveIndex] = Write_SPI1(sendBuffer[sendIndex]);
    sendIndex++;
    receiveIndex++;

    if (sendBuffer[sendIndex] == '\0') {
        sendIndex = 0;
    }

    if ((receiveBuffer[receiveIndex] == '\0') || (receiveIndex == N_BYTES)) {
        receiveIndex = 0;
    }

    //    if (!SPI1STATbits.SPITBF) {
    //        if ((sendIndex < N_BYTES - 1) || (receiveIndex == N_BYTES)) {
    //            //            SPI1BUF = sendBuffer[sendIndex];
    //            WriteSPI1(sendBuffer[sendIndex]);
    //            sendIndex++;
    //        } else if (sendBuffer[sendIndex] == '\0') {
    //            sendIndex = 0;
    //        }
    //    }
    //
    //
    //    if (DataRdySPI1()) {
    //        if (receiveIndex < N_BYTES - 1) {
    //            //receiveBuffer[receiveIndex] = SPI1BUF;
    //            receiveBuffer[receiveIndex] = ReadSPI1();
    //            receiveIndex++;
    //        } else if ((receiveBuffer[receiveIndex] == '\0') || (receiveIndex == N_BYTES)) {
    //            receiveIndex = 0;
    //        }
    //    }


    IFS0bits.SPI1IF = 0; // Limpiar la bandera de interrupción SPI
}

///* RUTINA DE RECEPCION DEL PUERTO UART 1*/
//
//void __attribute__((__interrupt__, no_auto_psv)) _U1RXInterrupt(void) {
//    //    static int r = 0;
//    //
//    //    while (DataRdyUART1()) {
//    //        dato_Rx[r] = ReadUART1();
//    //
//    //    }
//    //    if (dato_Rx[r] != '\n') {
//    //        r++;
//    //    } else {
//    //
//    //        dato_Rx[r] = '\0';
//    //        r = 0;
//    //    }
//    //
//    //
//    IFS0bits.U1RXIF = 0; // clear RX interrupt flag
//}

/*INTERRUPCION TIMER2 10ms TAREA PERIODICA */

void __attribute__((__interrupt__, no_auto_psv)) _T2Interrupt(void) {
    /* Interrupt Service Routine code goes here */

    if (!EXTCICLO) {
        LISTO = 1; // ALIMENTACION 
    } else {
        LISTO = 0;
    }

    if (EXTRESET == 1) {
        __asm__ volatile ( "reset ");
    }


    if (INICIO_PROGRAMA == 1) {
        HAB_SRV = !RSE;

        if (CONFIRMADO_RSE == 1 || EXTRESET) // MANTIENE LECTURA DE RSE UNA VEZ INICIADO EL PROGRAMA      
            __asm__ volatile ( "reset "); //Instruccion de reinicio A LA SALIDA DE PARAMETROS 

    }
    // LECTURA Y CONFIRMACION DE PULSADORES FISICOS PRESIONADOS     

    if (ANTERIOR_PUL_CIC == NUEVO_PUL_CIC)
        CONFIRMACION_PUL_CIC = ANTERIOR_PUL_CIC;

    ANTERIOR_PUL_CIC = NUEVO_PUL_CIC;
    NUEVO_PUL_CIC = (!PUL_CIC);

    if (ANTERIOR_PUL_DET == NUEVO_PUL_DET)
        CONFIRMACION_PUL_DET = ANTERIOR_PUL_DET;

    ANTERIOR_PUL_DET = NUEVO_PUL_DET;
    NUEVO_PUL_DET = (!PUL_DET);

    //------------------------------------------------------------------------------


    // BANDERAS PARA PULSADORES  DETENER--REFERENCIAR---CICLO   

    if (BANDERA_REFERENCIA == 1 && BANDERA_CICLO == 0 && CONFIRMACION_PUL_CIC == 1 && ANTERIOR_PUL_CIC == 0) {

        if (BANDERA_SERVO_REFERENCIADO == 1)
            BANDERA_CICLO = 1;

    }


    if (BANDERA_CICLO == 0 && BANDERA_REFERENCIA == 0 && CONFIRMACION_PUL_CIC == 1 && ANTERIOR_PUL_CIC == 0) {

        BANDERA_REFERENCIA = 1;
    }


    if (BANDERA_DETENCION == 0 && CONFIRMACION_PUL_DET == 1 && ANTERIOR_PUL_DET == 0) {

        BANDERA_DETENCION = 1;
    }

    //-------------------------------------------------------------------------------------------------   


    /*GENERA SEÑAL BT */

    if (PERIODO_BT < TAM_PERIODO) {
        PERIODO_BT++;
    } else {
        PERIODO_BT = 0;
    }

    if (PERIODO_BT < (TAM_PERIODO - BT_OFF)) {
        BT = 1;
    } else {
        BT = 0;
    }

    //********************************************************************  

    /*GENERA ANCHO DE PULSO DE LA SEÑAL FOTO */
    if (PERIODO_BT >= 30) {
        DF = 0;
    }



    //****************************************************************

    // VARIABLES DE PULSO DIGITAL GENERA FLACOS DE BT 
    ANTERIOR_BT = NUEVO_BT;
    NUEVO_BT = BT;


    //------------------------------------------------------------------------   
    /*ENTRADA DE ALIMENTACION */

    if (ANTERIOR_RSE == NUEVO_RSE)
        CONFIRMADO_RSE = ANTERIOR_RSE;

    ANTERIOR_RSE = NUEVO_RSE;
    NUEVO_RSE = (RSE);

    //************************************************************************   


    /* LECTURA Y CONFIRMCION DE LOS  SENSORES  BF1=ED6 Y L1=ED10  */

    if (ANTERIOR_L1 == NUEVO_L1)
        CONFIRMADO_L1 = ANTERIOR_L1;

    ANTERIOR_L1 = NUEVO_L1;
    NUEVO_L1 = (!L1);

    if (ANTERIOR_BFE1 == NUEVO_BFE1)
        CONFIRMADO_BFE1 = ANTERIOR_BFE1;

    ANTERIOR_BFE1 = NUEVO_BFE1;
    NUEVO_BFE1 = (!BFE1);

    if (ANTERIOR_STROBE == NUEVO_STROBE)
        CONFIRMADO_STROBE = ANTERIOR_STROBE;

    ANTERIOR_STROBE = NUEVO_STROBE;
    NUEVO_STROBE = (!STROBE);


    //---------------------------------------------------------------------  

    // ESTADO DEL PROGRAMA
    ESTADO_PROGRAMA = BANDERA_DETENCION << 2 | BANDERA_REFERENCIA << 1 | (!EXTCICLO & BANDERA_CICLO);



    //------------------------------------------------------------------------------     

    if (ESTADO_PROGRAMA == 2) {//ESTADO_PROGRAMA==3)

        if (Tarea_Peso == 5) {
            int peso_prom = 0;
            for (int i = 0; i < 10; i++) {
                peso_prom += convierteAD(19);
            }
            Peso_cajon = ((peso_prom / 10) / 40.65);
            Tarea_Peso = 0;
        }



        if (Tarea_Peso <= 5) {
            Tarea_Peso++;
        }



        /* BANDERA DE TIEMPO 3 MOTORES 100MS ENCIENDE APAGA 200MS Y LUEGO QUEDAN ENCENDIDOS */

        if (PERIODO1_H_COA <= TAM_PERIODO_TC1) {
            PERIODO1_H_COA++;
        } else {
            PERIODO1_H_COA = 0;
        }

        if (PERIODO1_H_COA <= (TAM_PERIODO_TC1 - TC1_OFF)) {
            BANDERA_TIEMPO1_H_COA = 1;
        } else {
            BANDERA_TIEMPO1_H_COA = 0;
        }


        if (PERIODO2_H_COA <= TAM_PERIODO_TC2) {
            PERIODO2_H_COA++;
        } else {
            PERIODO2_H_COA = 0;
        }

        if (PERIODO2_H_COA <= (TAM_PERIODO_TC2 - TC2_OFF)) {
            BANDERA_TIEMPO2_H_COA = 1;
        } else {
            BANDERA_TIEMPO2_H_COA = 0;
        }
        //---------------------------------------------------------------------     

        //Si hay papa en cinta V
        if (CONFIRMADO_BFE1 == 0) {
            if (retardo_bfe >= 35) {
                H_C0A = BANDERA_TIEMPO1_H_COA + ((!BANDERA_TIEMPO2_H_COA)*(CONFIRMADO_BFE1));
                H_C2 = 1;
            } else {
                retardo_bfe++;
            }
        } else if (CONFIRMADO_BFE1 == 1) {
            retardo_bfe = 0;
            H_C0A = 1;
            H_C2 = 1;
        }


        /*TIEMPO DE TRIGGER DEL SERVO MOTOR PASADO 50MS DEL FLANCO DE BT Y ACTIVA 100MS DENTRO DEL PERIODO BT*/
        if ((BT == 1) || (TR1_TRIG > 0)) {
            TR1_TRIG++;
            if (PERIODO_BT == 20) {
                if (p == 0) {
                } else {
                    PTRG = 1;
                }
            } else if (PERIODO_BT == 25) {
                PTRG = 0;
                TR1_TRIG = 0;
            }
        }

        // FLANCO DE SUBIDA ENCIENDE MOTOR H_C1 Y ACTIVA BANDERA PARA LOS 3 MOTORES    
        if (ANTERIOR_BT == 0 && BT == 1) {
            DF = 1;
            H_C1 = 1;
        }
        /*
                bool se1 = 0;
                bool se2 = 1;
                bool se3 = 1;

                bool strobee = 1;
         */
        //aca en el if va el de abajo
        //if (strobee == 1) {
        if (ANTERIOR_STROBE == 1 && STROBE == 0) {
            p = (SEL3 << 2) | (SEL2 << 1) | (SEL1);
            //El de abajo es de prueba
            //p = ((se3 << 2) | (se2 << 1) | (se1));
            if (p >= 7) {
                p = 0;
            }
        }


        if (ANTERIOR_L1 == 0 && NUEVO_L1 == 1) {
            H_C1 = 0; // APAGA CINTA C1B 
            GRADO = GRADO_ANTERIOR;
            GRADO_ANTERIOR = POSICION[p];

            POS1 = ((GRADO & 1) == 1) ? 1 : 0;
            POS2 = ((GRADO & 2) == 2) ? 1 : 0;
            POS3 = ((GRADO & 4) == 4) ? 1 : 0;
            POS4 = 0;

        }



    }





    // UTILIZA FLANCOS PARA ACTIVAR    PRUEBA ANTERIOR
    //    if (ESTADO_PROGRAMA == 2) {//ESTADO_PROGRAMA==2)// EL PROGRAMA ESTA EN CICLO
    //
    //        // FLANCO DE SUBIDA ENCIENDE MOTOR H_C1 Y ACTIVA BANDERA PARA LOS 3 MOTORES    
    //        if (ANTERIOR_BT == 0 && NUEVO_BT == 1) {
    //
    //            /*ACTIVAR BANDERA BASE DE TIEMPO TIEMPO_H_C0A */
    //            BANDERA_TIEMPO_H_COA = 1;
    //            TIEMPO_H_C0A = 0;
    //            //H_C1 = 1; //maybe comentar
    //        }
    //
    //        // FLANCO DE SUBIDA ENCIENDE MOTOR SERVO  
    //        if (ANTERIOR_BT == 0 && NUEVO_BT == 1) {
    //
    //        }
    //
    //
    //        /* BANDERA DE TIEMPO 3 MOTORES 100MS ENCIENDE APAGA 200MS Y LUEGO QUEDAN ENCENDIDOS */
    //        if (BANDERA_TIEMPO_H_COA == 1) {
    //
    //            TIEMPO_H_C0A++;
    //
    //            if (TIEMPO_H_C0A <= 100) {
    //                //ENCENDER MOTOR POR 100MS
    //                H_C0A = 1;
    //            }
    //
    //
    //            if (TIEMPO_H_C0A > 10 && TIEMPO_H_C0A <= 200) {
    //                // APAGAR CINTA POR 200MS
    //                H_C0A = 0;
    //            }
    //            if (TIEMPO_H_C0A > 20) {
    //                BANDERA_TIEMPO_H_COA = 0; // RESET DE LA BANDERA 
    //                TIEMPO_H_C0A = 0; // RESET DE LA BASE DE TIEMPO
    //                H_C0A = 1; //ENCIENDE LOS 3 MOTORES Y ESPERA LA DETENCION POR SENSOR
    //            }
    //        }
    //
    //
    //        // LEE ENTRADA DE SENSOR L1 PARA DETENER CINTA Y SACAR FOTO
    //        if (ANTERIOR_L1 == 0 && NUEVO_L1 == 1) {
    //
    //            H_C1 = 0; // APAGA CINTA C1B 
    //            DF = 1; //ORDEN PARA SACAR FOTO
    //        }
    //
    //
    //        // SENSOR CINTA EN V PARADA DE LOS 3 MOTORES LLEGADA DE PAPA   
    //        if (CONFIRMADO_BFE1 == 1 && BANDERA_TIEMPO_H_COA == 0) {
    //            // PARA EL MOTOR CUANDO LLEGA EL SENSOR DESPUES DE HABER PASADO UN TIEMPO
    //            H_C0A = 0;
    //        }
    //
    //        // FIN DE ESTADO DEL PROGRAMA 2 
    //    }   

    //-----------------------------------------------------------------------------    


    ST1 ^= 1; // CONTROL PERIODO DE LA TAREA PIN 5 DSPIC  




    IFS0bits.T2IF = 0; // Clear Timer1 Interrupt Flag

    return;
}
