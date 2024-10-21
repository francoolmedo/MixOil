/*******************************************************************************
 * File:   main.c
 * Author:  Petrone
 * Title: V5 - 
 * 
 * Created on 27 de agosto de 2022, 06:32a.m. c0nsulf3mw1f1
 * 
 *  NOTA: 
 * 
 * 
 ******************************************************************************/
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


//unsigned char wSPI[20];

// ********** DEFINICIONES ***********

float version = 030423; //03 de Abril de 2023


/***************************************************************************
 *                 TODAS   VARIABLES  DEL PROCESO                              *
 ***************************************************************************/

// Orden alfabetico          E/S     Descripcion - NO implementado=XXX - NF=NO FISICA

unsigned int ND = 0; //EA10*=RC1   nivel de mix oil     
// Pcic=0    ;   //ED05    Pulsador de cicl-Repite a la Sk1   hard.h
// PEc=0     ;   //(RS232) peso de cansaste en carga 
unsigned int PIR = 0; //EA20*    Presion interna del reactor
// EApt=0   ;   //futura  Extractor de aire 
// Qarr=0   ;   //REL.K3  Quemador Arrancar                  hard.h
unsigned int Qgasoil = 0; //XXX     Habilitar Goil como combustible
//            Qmarch=0    ;   //ED06    Quemador en marcha                 hard.h
unsigned int Qmot = 0; //XXX     Quemador solo encender motor
//            Qok=0       ;   //ED07    Quemador OK

unsigned int RH = 0; //HAB     Relay de Habilitacion
// SEL=0    ;   //RD12    Seleccion de EAnalog Altas/Bajas   hard.h    
// SKC1=0   ;   //ED10    Softkey codificada en binario      hard.h
// SKC2=0   ;   //ED11    Softkey codificada en binario      hard.h 
// SKC3=0   ;   //ED12    Softkey codificada en binario      hard.h
unsigned int TCF = 0; //EA4 SEL=1*   Temperatura en la Camara de Fuego
unsigned int tCIC = 0; //NF           Tiempo en Pirolisis 
unsigned int TD = 0; //EA4 SEL=0*   Temperatura MixOil en Deposito
unsigned int TIB = 0; //EA3 SEL=0*   Temp Int Reac ETBasculante
unsigned int TIP = 0; //EA3 SEL=1*   Temp Int Reac ETPreCal
unsigned int TIR = 0; //EA2 SEL=1*   Temperatura Interna Reactor (MEDIDO))
unsigned int TIR1 = 0; // TIR CON SOBRETEMPERATURA A ENVIAR
unsigned int TIR2 = 0; // TIR PARA ENVIAR A SCC 
// unsigned int VGpc=0  ;   //REL.K1  Abrir EV Gas en Estac PreCal       hard.h 
unsigned int Pservos = 0; //        Pulsador de servos
// AlarS=0  ;   //SD08    Indicador Acustico de Alarma       hard.h
// AlarVR=0 ;   //SD07    Ind. Luminoso Alarma Bal Roja      hard.h 
// AlarVV=0 ;   //SD06    Ind. Luminoso Alarma Bal Verde     hard.h
unsigned int ApQ = 0; //SAnalog Pantalla Apert GAS Quemad (8bit)   
// ApSv1=0  ;   //SD01    Apertura Servo Val (palabra 4 bit) hard.h
// ApSv2=0  ;   //SD02    Apertura Servo Val (palabra 4 bit) hard.h
// ApSv4=0  ;   //SD03    Apertura Servo Val (palabra 4 bit) hard.h
// ApSv8=0  ;   //SD04    Apertura Servo Val (palabra 4 bit) hard.h
bool DOK = 0; //NF      Deposito de Mix Oil OK (Nivel OK)
//unsigned int  EAmarch ;   //futura  Motor Extractor de Aire en marcha
// HAB=0    ;   //SD05    Cadena de pulsadores de Emergencia hard.h
// Garr=0   ;   //Rel.K4  Grua Marcha: Habilita func grua    hard.h
// Gok=0    ;   //ED02    Grua Ok                            hard.h
// Larr=0   ;   //REL.k2  ARRANCAR LAVADORA                  hard.h
// Lmarch=0 ;   //ED03    Lavadora EN MARCHA                 hard.h
// Lok=0    ;   //ED04    Lavadora OK-Lav SIN ALARMAS        hard.h
// IArr=0   ;   //SD09    Forzar Alar Incendio               hard.h


/******************************************************************************    
 *                  FIN VARIABLES DEL PROCESO                                 *
 ******************************************************************************/

/***************************************************************************
 *                      VARIABLES NF                                       *
 ***************************************************************************/
// VARIABLE CARTELES DA
bool REhorno = 0; //NF  DA[0]   Reactor en el horno 
bool LlaQuemador = 0; //NF  DA[1]   LLama de quemador+Fuego Horno+ Cartel
bool AlarV = 0; //NF  DA[2]   Alarma Verde
bool REbasc = 0; //NF  DA[3]   Reactor en estacion Basc  
bool REpc = 0; //NF  DA[4]   Reactor en estacion PreC  
bool Ctl_Llama = 0; //NF  DA[5]   Cartel estacion PreC
bool Cesto_0 = 0; //NF  DA[6]   COndicion Cesto
bool Cesto_1 = 0; //NF  DA[7]   COndicion Cesto
bool Molino_march = 0; //NF  DA[8]   CARTEL MARCHA+LLUVIA PLASTICO
bool BombaM_march = 0; //NF  DA[9]   CARTEL MARCHA BOMBA               
bool EN_ESPERA = 0; //NF  DA[10]  EN ESPERA   
bool MODO_MANUAL = 0; //NF  DA[11]  MODO MANUAL  
bool EN_CICLO = 0; //NF  DA[12]  EN CICLO     
bool AlarR = 0; //NF  DA[13]  AlarVR 
unsigned int DA = 0;

bool Alarma_verde = 0;
bool Alarma_roja = 0;

bool QMAR = 0;
int unsigned Err = 0;
int TIRN = 0;

unsigned int DB = 0;
unsigned int ApSApSV = 0;
unsigned int ET = 0;
unsigned int tETAP = 0;
unsigned int FINAL = 0;
unsigned int RES1 = 0;
unsigned int RES2 = 0;
unsigned int RES3 = 0;
unsigned int SK = 0;


/******************************************************************************    
 *                  FIN VARIABLES DEL NF                                      *
 ******************************************************************************/


/******************************************************************************
 *     VARIABLES PARAMETROS ACTUALIZADA 8AGO23 ALMACENADA EN EEPROM24LC256    *
 ******************************************************************************/
//VALOR   | UNIDAD | NRO| SIGNIFICADO
unsigned int T = 0; //mS    | 0 | Tiempo de muestreo
unsigned int dR = 0; //Minuto | 1  | Duración MINIMA de Encendido 
unsigned int NDB = 0; //cm	   | 2  | Ascenso Nivel MixOil xcada batch (Depósito)
unsigned int NDMAX = 0; // cm    | 3  | Nivel Máximo MixOil (Depósito)
unsigned int NDMIN = 0; // cm	   | 4  | Nivel Mínimo MixOil (Depósito)
unsigned int NEQ = 0; // L/cm  | 5  | Convers Altura a Volumen (MixOil Deposito)
unsigned int PEMP = 0; // kgf   | 6  | Peso de la Mat.Prima para un batch
unsigned int PETARA = 0; // Kgf   | 7  | Peso del canasto vacío (en kgf) (Pesar)
unsigned int PIRMAX = 0; // mBar  | 8  | Presión Máxima Interna (Umbral ALARMA)
unsigned int PIRNOM = 0; // mBar  | 9  | Presión de trabajo Interna (Gauge)
unsigned int STALARM = 0; // C     | 10 | Umbral de Alarma (Excede la CONSIGNA)
unsigned int TCCORT = 0; // C     | 11 | Umbral de ALARMA por TC Cortada
unsigned int TCFAlar = 0; // C     | 12 | Umbral de ALARMA de la Cámara de Fuego
unsigned int TDMax = 0; // C     | 13 | Temp Max Interna Deposito MixOPil
unsigned int tESTR = 0; // Seg   | 14 | Tiempo de Estrella (P/watch Dog)
unsigned int TEXT = 0; // C     | 15 | Temp Max p/ extraer reactor Horno
unsigned int TIRBP = 0; // C     | 16 | Banda Proporcioal para la TIR
unsigned int TIRC1 = 0; // C     | 17 | Consigna en °C para TIR en ETAPA 1
unsigned int TIRC2 = 0; // C     | 18 | Consigna en °C para TIR en ETAPA 2
unsigned int TIRC3 = 0; // C     | 19 | Consigna en °C para TIR en ETAPA 3
unsigned int TIRNA = 0; // N8bits| 20 | Consigna MAX - MIN en la variable TIRN
unsigned int TPCMAX = 0; // C     | 21 | Temperatura Máxima de Pre Calentamiento
unsigned int tPIR1 = 0; // Min   | 22 | Pirólisis: Duración Etapa 1
unsigned int tPIR2 = 0; // Min   | 23 | Pirólisis: Duración Etapa 2
unsigned int tPIR3 = 0; // Min   | 24 | Pirólisis: Duración Etapa 3
unsigned int TMAN = 0; // C     | 25 | Temp a alcanzar en MODO MANUAL 
unsigned int TPIRO1 = 0; // C     | 26 | Temperatura de Pirólisis Etapa 1
unsigned int TPIRO2 = 0; // C     | 27 | Temperatura de Pirólisis Etapa 2
unsigned int TPIRO3 = 0; // C     | 28 | Temperatura de Pirólisis Etapa 3
unsigned int TVUELC = 0; // C     | 30 | Temp Max p/ volcar la carbonilla
unsigned int Esc500 = 0; // Adim  | 31 | 1000XFactor Mult Escala de T Int Reactor (0,500)  
unsigned int Esc800 = 0; // Adim  | 32 | 1000XFactor Mult Escala de T Cam Fuego (0,800)
unsigned int Esc060 = 0; // Adim  | 33 | 1000XFactor Mult Escala de Temp MixOil (0,059)
unsigned int EscMPX = 0; // Adim  | 34 | 1000XFactor Mult Escala Pres Int Reactor (0,050)
unsigned int EscNIV = 0; // Adim  | 35 | 10XFactor Mult Escala Vol Int Deposito (12,10)
unsigned int dPIR = 0;
unsigned int ALARLAV = 0;
unsigned int ALARINM = 0;
//unsigned int a = 0;

/******************************************************************************
 *                            FIN PARAMETROS                                  * 
 ******************************************************************************/


/******************************************************************************
 *                        PARAMETROS DERIVADOS                                *                                    *
 ******************************************************************************/
unsigned int TCCORT_MUL2 = 0;



float TIRA = 0;
unsigned int TIRIBP = 0;
float ReLCC = 0;
float NCB = 0;
float NCMAX = 0;
float NCMIN = 0;


/*****************************************************************************
 *                       FIN DE PARAMETROS DERIVADOS                         *
 *****************************************************************************/


/******************************************************************************
 *         VARIBLES DE COMUNICACION DMA,UART 1,EEPROM                         *
 ******************************************************************************/

// ----------CONTROL DE ERRORES EN COMUNICACION CHEKSUM 1 BYTE 0X00FF-----------

int CHEK_A = 0; // VARIABLE DE CHEK A=
unsigned int CHEK_P = 0; // VARIABLE DE CHEK PARAMETROS P=
unsigned int CHEK_C = 0; // VARIABLE DE CHEK COMANDO C=
unsigned int CHEK_PAR = 0; // CHEKSUM DE PARAMETROS
//------------------------------------------------------------------------------

//-----------------------  BUFFER UART  1 -------------------------------- 
char dato_Rx[TAM_Rx] = {0};


//char *Receiveddata=dato_Rx; 
unsigned int RX_CHEKP = 0; // CONTROL DEL CHEK RECIBIDO UART 1
int RX_CHEKA = 0;
unsigned int RX_CHEKC = 0;
// unsigned int RX_CHEKS=0; // SOFTKEY
//------------------------------------------------------------------------

//---------- BUFFER AUXILIAR PARA LA  DMA -------------------------------- 

unsigned int BufferA[TAM_DMA] __attribute__((space(dma))); // DE DECLARA TAMAÑO DMA
char aux_dma_tx[TAM_DMA] = {0}; // VARIABLE AUXILIAR PARA CARGAR EN DMA

// *OBSERVACION: VERIFICAR EL TAMAÑO MAXIMO DE ENVIO Y RECEPCION CONTANDO CON 
// EL CARACTER NULL '\0' AL FINALIZAR 

//-----------------------VARIABLE DE PARAMETROS EEPROM--------------------
unsigned int Eparam[30]; //OJO TAMAÑO MAXIMO (32 INT) EQUIVALE A 64 BYTES POR PAGINA
unsigned int E1param[30];
//UTILIZADA PARA GRABAR LA MEMORIA EEPROM
//1 2  3   4  5  6   7   8   9  10  11  12 13 14 15  16  17  18  19  20 21  22 23 24  25  26  27  28 29
//unsigned int cons_param[30]={1,6,250,30,49,400,100,500,200,25,510,700,40,45,300,50,430,430,430,200,120,60,90,60,200,420,420,420,120};
unsigned int cons_param[30] = {0};
unsigned int cons_param1[30] = {0};
/*****************************************************************************
 *                          FIN VARIABLES COMUNICACION                       *
 *****************************************************************************/



/******************************************************************************
 *                   VARIABLE PARA LAS SEÑALES ANALOGICAS                     *
 ******************************************************************************/

unsigned int V[CAN_ANALOG] = {0}; // CONVERSIONES ANALOGAS DIGITALES

/******************************************************************************
 *                       FIN VARIABLES ANALOGICAS                             *  
 ******************************************************************************/

/*******************************************************************************
 *                    VARIABLES DE CONTROL                                     *
 *******************************************************************************/
volatile double VF_actual = 0;
volatile double VF_anterior = 0;
double operando_a;
double operando_b;
/******************************************************************************
 *                           FIN VARIABLES DE CONTROL                         *
 ******************************************************************************/



/******************************************************************************
 *              VARIABLE DE TIEMPO TIMER 2 TICKS DE 1 SEG 1 MIN               *            
 * ****************************************************************************/
//unsigned long int tareas = 0; // contador de tareas periodicas ticks t=20ms

#define TIC 10 // Tiempo de interrupcion en milisegundos
unsigned int NP1K = (1000 / TIC); // Variable de referencia de tiempo para TP1S
unsigned int NP2S = (8000 / TIC); // Contador para actualizar comunicacion
unsigned int NP4K = (4000 / TIC); // Contador para actualizar estado de alarmas
unsigned int NP5K = (5000 / TIC); // Contador para actualizar seniales analogicas
unsigned int NP10K = (10000 / TIC); // Variable de referencia de tiempo para TP10S
unsigned int TP1S = 0; // Contador para tareas cada 1 segundo
unsigned int TP10S = 0; // Contador para tareas cada 10 segundos


unsigned int ticks = 0;
unsigned int seg = 1;
unsigned int seg_acum = 0;
unsigned int min = 0;


/*******************************************************************************
 *                FIN VARIBLES TIEMPOS                                         *
 * *****************************************************************************/


/*******************************************************************************
 *  VARIABLES PARA EL  MANEJO DE LAS SOFTKEY FISICAS (BOTONES) ANTI REBOTE     * 
 *******************************************************************************/

unsigned int SOFTK_A = 0, SOFTK_N = 0, SOFTK_N1 = 0;
bool YAC = 0; // "Ya actualizo?" - Variable de actualizacion forzada con SoftKey
bool PASADA = 0; // N de Pasada - Variable de actualizacion forzada con SoftKey

/*******************************************************************************
 *                      FIN VARIABLES SOFTKEY                                  *
 *******************************************************************************/


/*******************************************************************************
 *           VARIABLE PARA EL REDIRECCIONAMIENTO DEL CICLO ARRANQUE            *
 *******************************************************************************/
unsigned int Punto = 0; //COMIENZO P=0; PUNTO CERO DIAGRAMA FLUJO  P=1  PUNTO UNO DIAGRAMA FLUJO
unsigned int SK_C = 0; // CARTEL DE LAS SOFTKEY
bool SALIR_MANUAL = 0; //BANDERA DE SALIDA CICLO MANUAL
unsigned int MODO = 0; // SELECCION MODO 0 NADA 1 AUTOMATICO 2 MANUAL.. etc

unsigned int num = 0; // BANDERA seleccion QUEMADOR =1 MOLINO =2 PRECALENTADOR =3

bool BANDERA_HELPQTCF = 0; // HELP TEMPERATURA CAMARA DE FUEGO
bool BANDERA_HELPQNDmax = 0; // HELP NIVEL DEPOSITO ALTO
bool BANDERA_HELPQNDmin = 0; // HELP NIVEL DEPOSITO BAJO
bool BANDERA_HELPQ = 0; // HABILITAR HELP

bool BANDERA_ALARMAQENC = 0; // BANDERA DE ALARMA QUEMADOR ESTANDO ENCENDIDO
bool BANDERA_ALARQUEM = 0; // BANDERA DE ALARMA QUEMADOR NO ENCIENDE
bool BANDERA_noquema = 0; // BANDERA DE IMPRESION NO HAY REACTOR
bool BANDERA_quemador = 0; //PRIMER PULSO MODO MANUAL SK1 IMPRESION
bool aviso_Qarr = 0; // AVISA CARTEL ENCENDIENDO QUEMADOR
unsigned int SK_Q = 0; // CARTEL DE LAS SOFTKEY QUEMADOR
bool APQ = 0; // HABILITA TAREA DEL HORNO 
bool apagar_Q = 0; // BANDERA APAGAR QUEMADOR
bool BANDERA_ACTUALIZAQ = 0; // BANDERA ACTUALIZAR DENTRO DE QUEMADOR
bool BANDERA_RETROCERQ = 0; // BANDERA PARA SALIR DEL QUEMADOR
unsigned int tiempo_ENCQUEMA = 0;
unsigned int ticks_Q = 1;
unsigned int tiempo_segQ = 0;




bool BANDERA_HELPM = 0;
bool BANDERA_ALARMOL = 0;
bool BANDERA_nomolino = 0;
bool BANDERA_molino = 0; // RETIENE PRIMER PULSO MODO MANUAL SK2
bool aviso_Larr = 0; // AVISA A LA SK2 CARTEL  ENCENDER/APAGAR MOLINO
unsigned int SK_M = 0; // CARTEL DE LAS SOFTKEY MOLINO
bool APM = 0; // HABILITA TAREA DEL MOLINO
bool apagar_M = 0; // BANDERA APAGAR MOLINO
bool BANDERA_ACTUALIZAM = 0; // BANDERA ACTUALIZAR DENTRO DEL MOLINO
bool BANDERA_RETROCERM = 0; // BANDERA PARA SALIR DEL MOLINO
bool BANDERA_lluviamarch = 0;




bool BANDERA_HELPP = 0;
bool BANDERA_ALARPRE = 0;
bool BANDERA_nopre = 0;
bool BANDERA_precalentador = 0; // AVISA A LA SK3 APAGAR PRE CALENTADOR
bool aviso_Parr = 0; // AVISA A LA SK2 CARTEL  ENCENDER/APAGAR PRE CALENATADOR
unsigned int SK_PRE = 0; // CARTEL DE LAS SOFTKEY PRECALENTADOR
bool APP = 0;
bool apagar_P = 0; // BANDERA APAGAR PRECALENTADOR
bool BANDERA_ACTUALIZAP = 0;
bool BANDERA_RETROCERP = 0;


unsigned int ESTADO_0 = 0;
unsigned int ESTADO_1 = 1;
bool RETORNAR = 0; //BANDERA INDICADOR DE RETORNO


bool tabla_sk = 0; //BANDERA IMPRESION TABLA

/*******************************************************************************
 *             VARIABLES BANDERAS DE PUESTA EN MARCHA                                   *
 *******************************************************************************/
bool EnCICLO = 0;
unsigned int Ppal = 0;

/*******************************************************************************
 *             VARIABLES BANDERAS DE EMERGENCIA
 *******************************************************************************/
bool signal_emergencia = 0;

int main(void) {

    int i = 0; //VARIABLE DE REPETICION EN CICLOS CONTROLADOS  

    //----------------------------------------------------------------------------//
    //        INICIO DE EJECUCION DEL PROMAGRAMA LUEGO DEL ENCENDIDO
    //----------------------------------------------------------------------------//    

    configurarSistema(); //Deshabilita WDT,configura PLL y Entradas/Salidas
    inicializaUART(BRGVAL); //Inicializa UART     
    inicializaADC(); //Inicializacion ADC 10 bit
    inicializaDMA(); //Inicializa DMA 
    inicializaTimer2(); //iniciliza timer2 (NO INICIA)

    // Inicializo valores de contadores de TAREAS PERIODICAS
    TP1S = NP1K;
    TP10S = NP10K;


    //INDICADOR OK EN PLACA LED VERDE 
    SEL = 1;

    for (i = 0; i <= 3; i++) {
        __delay_ms(200);
        printf("%d\n", i);
    }

    /*PRUEBA DE RELEES*/

    PCarr = 1; //ACTIVAS EN CERO K4 BORNERA RELE ARDUINO SON SALIDAS 
    Larr = 1; //ACTIVAS EN CERO K3 BORNERA RELE ARDUINO	
    Qarr = 1; //ACTIVAS EN CERO K2 BORNERA RELE ARDUINO
    Garr = 1;

    AlarVV = 1;

    //   escribir_Eeprom(cons_param,30,0);

    //LECTURA DE PARAMETROS DESDE LA EEPROM CON TIEMPO DE ESPERA     
    __delay_us(2);
    leer_Eeprom(Eparam, 30, 0); // Carga parametros pag 0 desde Eeprom24CL256
    __delay_us(2);
    leer_Eeprom(E1param, 30, 1); // Carga parametros pag 1 desde Eeprom24CL256

    control_param();

    __delay_ms(4000);


    /*PARAMETROS DERIVADO CALCULOS*/

    /*QUEMADOR*/
    if (TIRBP != 0)
        TIRA = (float) 255 / TIRBP;
    /*DEPOSITO */
    if (NDMAX != 0)
        ReLCC = CMAX / NDMAX;

    NCB = ReLCC*NDB;
    NCMAX = CMAX - NCB;
    NCMIN = ReLCC*NDMIN;

    TCCORT_MUL2 = TCCORT << 1; // PARAMETRO X 2

    //----FIN PARAMETROS DERIVADOS      

    ND = ND & 0x0fff;
    TIR = TIR & 0x0fff;
    TIP = TIP & 0x0fff;
    TCF = TCF & 0x0fff;
    PIR = PIR & 0x0fff;
    TIB = TIB & 0x0fff;
    TD = TD & 0x0fff;

    //------------------- LOOP TAREA NO PERIODICA (PSEUDO PERIODICA) -------------------
    while (1) {

        Punto = 0; //POSICIONA  TAREA PERIODICA EN PUNTO 0


        //-------- COMIENZO DEL PUNTO A : EMPIEZA TAREA PERIODICA 10ms ---------                        

        do { // PARA VOLVER DE PANTALLA
            //LEE ENTRADA DE WATCH DOG RELE NO HABLITADO SEGURIDAD DEPEGADO


            HAB = 0; // HABILITACION = 0 CADA VEZ QUE INGRESE
            WDD = 0;


            while (WDOK == 0) {
                __delay_ms(1000);
            }


            STATUS_LED = 1;
            PCarr = 1; //ACTIVAS EN CERO K4 BORNERA RELE ARDUINO SON SALIDAS 
            Larr = 1; //ACTIVAS EN CERO K3 BORNERA RELE ARDUINO	
            Qarr = 1; //ACTIVAS EN CERO K2 BORNERA RELE ARDUINO
            Garr = 1; //ACTIVAS EN CERO K1 BORNERA RELE ARDUINO
            apagar_Q = 0; // BANDERAS
            apagar_M = 0; // BANDERAS 
            apagar_P = 0; // BANDERAS
            RUN_Timer2();
            RX_CHEKC = 0;

            if (Punto == 0) {
                do {
                    /* CHEK DE PUERTO Y TABLA DE PARAMETROS */
                    if (strncmp(dato_Rx, "H=", 2) == 0)
                        sscanf(dato_Rx, "H=%2x", &RX_CHEKC);

                } while (RX_CHEKC != CHEK_C);

            }
            //------ HASTA AQUI SE VERIFICA EL CHEKSUM DE TABLA DE PARAMETROS VARIABLE CSUM Y PUSO PANTALLA 2  ------------------                        
            HAB = 1;
            Punto = 1; //POSICIONA  TAREA PERIODICA EN PUNTO 1

            do {
                if (Punto == 1) {
                    switch (SOFTK_A + (Ppal = (!(NO_EMER)&!(SON)) << 4)) {
                        case 2:
                            if (SOFTK_N == 0) {
                                Punto = 2;
                                SK_C = 0;
                            }
                            break;
                        case 16:
                            Punto = 3; //SE PRESIONA PULSADOR  SERVOS CASE 16
                            SK_C = 0;
                            break;
                        default: break;
                    }
                }
                if (strncmp(dato_Rx, "H=", 2) == 0)
                    sscanf(dato_Rx, "H=%2x", &RX_CHEKA); // verificacion de CRC enviado A= 

            } while (Punto != 2 && RX_CHEKA != CHEK_A);

            /*    HASTA AQUI SE ESPERA EL COMANDO SERVOS PPAL O PARAMETROS  */

            /*************************************************************************************************** 
             *    PUNTO 4 COMIENZA CON LA VERIFICACION O PRODDUCCION CON POSIBILIDAD DE ACCEDER A  PARAMETROS  *
             *    EN ESTE PUNTO YA ESTAMOS EN LA PANTALLA PRINCIPAL SE DEBEN VISUALIZAR VARIABLES FISICAS      *                          *
             ***************************************************************************************************/

            if (!(Punto == 2)) {
                do {
                    //(SOFTK_ACTUAL+PPP)) SERAN DOS VARIABLES A CONSIDERAR DE ACUERDO A ESTO SERAN 2 OPCIONES
                    switch (SOFTK_A + (Ppal = (!(NO_EMER)&!(SON)) << 4)) {

                        case 18:
                            if (Punto == 4 && SOFTK_N == 0) {
                                Punto = 2;
                            }
                            break;

                        case 0:
                            Punto = 0;
                            signal_emergencia = 1;
                            __delay_ms(10000);
                            break; // SE ACTIVA EMERGENCIA PPAL          

                        case 22:
                            if (Punto == 4 && SOFTK_A == 6 && SOFTK_N == 0) {
                                SOFTK_N = 0;
                                Punto = 0;
                                HAB = 0;
                                __delay_ms(10000);
                            }
                            // VOLVER AL PUNTO 0 PANTALLA ARRANQUE  TECLA 3  
                            break;

                        default:break;

                    }

                    //REVISAR BORRADO DE SK 
                    if (strncmp(dato_Rx, "H=", 2) == 0)
                        sscanf(dato_Rx, "H=%2x", &RX_CHEKA); // verificacion de CRC enviado A= 


                    /* EN ESTE PUNTO SE REALIZA EL CHEKEO DEL PUNTO 4 ANTES DE PASAR A PRODUCCION */

                    //PRUEBA MODO DE SELECCION        
                    switch (MODO) {
                        case 1:
                            Automatico();
                            break;


                        case 2:
                            Manual();
                            break;


                        default: break;

                    }

                } while (Punto != 2 && Punto != 0); //salida de ciclo [<---(NO)---->]
            }
        } while (Punto == 0); // TECLA VOLVER


        //--------------------------COMIENZO DEL PUNTO B (PARAMETRIZACION)-------------------------------

        /*    EN ESTE PUNTO SE DECIDE PARAMETRIZAR   */
        /*  COMIENZO DEL PUNTO B
         *  STOP_Timer2() ;//DETIENE TIMER 2 OK
         *  se envia cambio de pantalla (edicion parametros)   OK
         *  variable = variable obtenida en el ciclo anterior    OK    
         *  envio de tabla actual                                OK
         *  empieza ciclo con condicion de salida check tabla  
         *  escuchar utilizar ssprintf() en interrupcion serie para salir ciclo
         *  se procede a escribir Eeprom   
          Eeprom escribir_Eeprom(constantes_Parametro,30,0); //maximo de datos a cargar 64 para 32 variables int  
         *  produce reset absoluto  -> __asm__volatile("reset");
      
      }
         */

        //---------------- PUNTO = 2 ( PARAMETROS ) ----------------------     

        /*
             CASOS 2 : 
         * FALLA DE CHEK_P  :  NO SE ENVIA "COMANDO" A MMI 
         * PASA POR SOFTKEY :  SE ENVIA "COMANDO" Y SE VALIDA CHEK_C ANTES DE LLEGAR
         */
        switch (Punto) {
            case 2:
                for (int i = 0; i < 4; i++) {
                    __delay_ms(10);
                    generar_A(0x000000, 0x0000, 0, 0); // Limpio los letreros de las SoftKeys ya que no se utilizan
                    __delay_ms(10);
                }

                STOP_Timer2(); //DETIENE TIMER 2 (TAREA PERIODICA DE 10MS )
                HAB = 0; // SE HACE HABILITACION = 0
                WDD = 0;

                STATUS_LED = 1;
                __delay_us(50);

                parametros();
                do {
                    printf("A=00000000000000000000000000000000000000002000000000000000000202\n");
                    __delay_ms(15);
                    if (strncmp(dato_Rx, "H=", 2) == 0) {
                        sscanf(dato_Rx, "H=%2x", &RX_CHEKA);
                    } // verificacion de CRC enviado A= 

                } while (RX_CHEKA != 2);


                __asm__ volatile ( "reset "); //Instruccion de reinicio A LA SALIDA DE PARAMETROS    

                //-------------------COMIENZO DEL PUNTO C-----------------------------------    
                /*
                 * colocar MMI en pantalla principal ok
                 * Comienza envio rutinario de msj 10seg   0k
                 * salidas HAB=Garr=1; (energia electrica) 0k
                 * verificar las condiciones de ciclo:
                        -Reactor en el horno
                        -NO EMERGENCIA ED9=1
                        -ND<250-NDB
     
                 GENERAR ADVERTENCIA EN CASO DE INCUMPLIMIENTO
                     -PEc>=Ptara   Cesto en la balanza
                     -Larr=1       Molino lavador en marcha
     
                 */
                /* FIN DE PARAMATROS */
                break;
            case 5:
                /* INICIO DEL PUNTO 5*/
                /* FUNCIONAMIENTO DEL MODO MANUAL */
                //DENTRO DE MODO MANUAL TECLA QUEMADOR-MOLINO-PRECALENTADOR-       -RETROCEDER - ACTUALIZAR

                if (ESTADO_0 == 0 || ESTADO_0 == 1 || ESTADO_0 == 2 || ESTADO_0 == 3) {
                    EN_ESPERA = 0;
                    MODO_MANUAL = 1;
                    EN_CICLO = 0;
                }

                DA = AlarR << 13 | EN_ESPERA << 10 | MODO_MANUAL << 11 | EN_CICLO << 12 | BombaM_march << 9 | Molino_march << 8 | Cesto_1 << 7 | Cesto_0 << 6 | Ctl_Llama << 5 | REpc << 4 | REbasc << 3 | AlarV << 2 | LlaQuemador << 1 | REhorno;


                //-----------------------------------------------------------------------------
                if (SALIR_MANUAL == 1) {
                    switch (SK_C) {
                        case 1:
                            if (RX_CHEKA != CHEK_A && TP1S == 0) { //CARTEL PULSAR RETROCEDER PARA SALIR
                                generar_A(0x650edc, 0x0322, 0, 0);
                            }
                            if (RX_CHEKA == CHEK_A) { //
                                CHEK_A = -1;
                                SK_C = 2;
                            }
                            break;
                        default: break;
                    }
                }


                if (SALIR_MANUAL == 1) { //SE PRESIONO RETORNAR POR SEGUNDA VEZ 
                    if (SOFTK_A == 6 && SOFTK_N == 0) {
                        SOFTK_N = 0;
                        SOFTK_A = 0;
                        SALIR_MANUAL = 0;
                        MODO = 0;
                        Punto = 3;
                        SK_C = 0;
                        tabla_sk = 0;
                        ESTADO_0 = 0;
                        CHEK_A = -1;
                        num = 0;

                        /*BORRAR TODAS LAS BANDERAS*/
                        /*QUEMADOR*/
                        APQ = 0;
                        reset_tiempoQ();
                        apagar_Q = 0;
                        aviso_Qarr = 0;
                        BANDERA_quemador = 0;
                        Qarr = 1;

                        /*PRECALENTADOR*/
                        APQ = 0;
                        apagar_P = 0;
                        aviso_Parr = 0;
                        BANDERA_precalentador = 0;
                        PCarr = 1;


                        /*MOLINO*/
                        APM = 0;
                        apagar_M = 0;
                        aviso_Larr = 0;
                        BANDERA_lluviamarch = 0;
                        BANDERA_molino = 0;
                        Larr = 1;
                        break;
                    }
                }

                // PRIMER PULSO RETROCEDE  FLANCO DE BAJADA SOFT 6
                if (SOFTK_A == 6 && SOFTK_N == 0 && SALIR_MANUAL == 0 && num == 0 && BANDERA_ALARQUEM == 0 && BANDERA_ALARPRE == 0 && BANDERA_ALARMOL == 0) {
                    //  if(ESTADO_0==0  ){ // SI ESTADO == 0 VUELVE A MANUAL
                    SOFTK_N = 0;
                    SALIR_MANUAL = 1; //BANDERA DE SALIDA   
                    tabla_sk = 0; // tabla no habilitada
                    // }
                }


                // RETROCEDER DENTRO DE QUEMADOR
                if (SOFTK_A == 6 && SOFTK_N == 0 && SALIR_MANUAL == 0 && num == 1) {
                    BANDERA_RETROCERQ = 1;
                }

                // RETROCEDER DENTRO DE PRECALENTADOR
                if (SOFTK_A == 6 && SOFTK_N == 0 && SALIR_MANUAL == 0 && num == 3) {
                    BANDERA_RETROCERP = 1;
                }

                // RETROCEDER DENTRO DE MOLINO
                if (SOFTK_A == 6 && SOFTK_N == 0 && SALIR_MANUAL == 0 && num == 2) {
                    BANDERA_RETROCERM = 1;
                }



                // BORRADO DE SK Y  LETREROS DE ZONA
                if (SALIR_MANUAL == 0) {
                    switch (SK_C) {
                        case 0:
                            if (RX_CHEKA != CHEK_A && TP1S == 0) {//sk eo
                                generar_A(0x650edc, 0x0300, 0, 0);
                            }
                            if (RX_CHEKA == CHEK_A) { //CONTROL DE LOS CHEK ENVIADO BORRAR TODAS LAS SK
                                CHEK_A = -1;
                                ESTADO_0 = 0;
                                ESTADO_1 = 1;
                                SK_C = 1;
                                tabla_sk = 1;
                            }
                            break;
                        default: break;
                    }
                }

                //--------------------------------------------------------------------------------------------------                         
                ESTADO_0 = apagar_Q << 2 | apagar_M << 1 | apagar_P;

                if (tabla_sk == 1 && TP10S == NP2S) {
                    //  ESTADO 0=000
                    if (ESTADO_0 != ESTADO_1 && ESTADO_0 == 0 && BANDERA_ALARQUEM == 0 && BANDERA_ALARPRE == 0 && BANDERA_ALARMOL == 0) {

                        AlarR = 0;
                        AlarV = 0;
                        if (RX_CHEKA != CHEK_A) {
                            generar_A(0x650edc, 0x0333, 0, 0);
                        }
                    } // FIN ESTADO 0=000

                    //  ESTADO 1=001             
                    if (ESTADO_0 != ESTADO_1 && ESTADO_0 == 1 && BANDERA_ALARQUEM == 0 && BANDERA_ALARPRE == 0 && BANDERA_ALARMOL == 0) {
                        AlarR = 0;
                        AlarV = 1;
                        if (RX_CHEKA != CHEK_A) {
                            generar_A(0x650bdc, 0x0300, 0, 0);
                        }
                    } // FIN ESTADO 1=001


                    //  ESTADO 2=010             
                    if (ESTADO_0 != ESTADO_1 && ESTADO_0 == 2 && BANDERA_ALARQUEM == 0 && BANDERA_ALARPRE == 0 && BANDERA_ALARMOL == 0) {
                        AlarR = 0;
                        AlarV = 1;
                        if (RX_CHEKA != CHEK_A) {
                            generar_A(0x650eac, 0x0300, 0, 0);
                        }
                    } // FIN ESTADO 2=010


                    //  ESTADO 3=011             
                    if (ESTADO_0 != ESTADO_1 && ESTADO_0 == 3 && BANDERA_ALARQUEM == 0 && BANDERA_ALARPRE == 0 && BANDERA_ALARMOL == 0) {
                        AlarR = 0;
                        AlarV = 1;
                        if (RX_CHEKA != CHEK_A) {
                            generar_A(0x650bac, 0x0300, 0, 0);
                        }
                    } // FIN ESTADO 3=011


                    // ESTADO 4=100    
                    if (ESTADO_0 != ESTADO_1 && ESTADO_0 == 4 && BANDERA_ALARQUEM == 0 && BANDERA_ALARPRE == 0 && BANDERA_ALARMOL == 0) {
                        AlarR = 0;
                        AlarV = 1;
                        if (RX_CHEKA != CHEK_A) {
                            generar_A(0x650ed9, 0x0355, 0, 0);
                        }
                    } // ESTADO 4=100                                  


                    //  ESTADO 5=101             
                    if (ESTADO_0 != ESTADO_1 && ESTADO_0 == 5 && BANDERA_ALARQUEM == 0 && BANDERA_ALARPRE == 0 && BANDERA_ALARMOL == 0) {
                        AlarR = 0;
                        AlarV = 1;
                        if (RX_CHEKA != CHEK_A) {
                            generar_A(0x650bd9, 0x0300, 0, 0);
                        }
                    } // FIN ESTADO 5=101


                    //  ESTADO 6=110
                    if (ESTADO_0 != ESTADO_1 && ESTADO_0 == 6 && BANDERA_ALARQUEM == 0 && BANDERA_ALARPRE == 0 && BANDERA_ALARMOL == 0) {
                        AlarR = 0;
                        AlarV = 1;
                        if (RX_CHEKA != CHEK_A) {
                            generar_A(0x650ea9, 0x0300, 0, 0);
                        }
                    } // FIN ESTADO 6=110


                    //  ESTADO 7=111
                    if (ESTADO_0 != ESTADO_1 && ESTADO_0 == 7 && BANDERA_ALARQUEM == 0 && BANDERA_ALARPRE == 0 && BANDERA_ALARMOL == 0) {
                        AlarR = 0;
                        AlarV = 1;
                        if (RX_CHEKA != CHEK_A) {
                            generar_A(0x650ba9, 0x0300, 0, 0);
                        }
                    } //FIN ESTADO 7


                    //-----------ESTADOS CON ERRORES-------------------------------------
                    /*QUEMADOR*/

                    // ESTADOS CON ALERTAS QUEMADOR CON AYUDA            
                    if ((ESTADO_0 == 0 || ESTADO_0 == 1 || ESTADO_0 == 2 || ESTADO_0 == 3) && BANDERA_HELPQ == 0 && BANDERA_ALARQUEM == 1 && BANDERA_ALARPRE == 0 && BANDERA_ALARMOL == 0) {
                        AlarR = 1;
                        AlarV = 0;
                        DA = AlarR << 13 | EN_ESPERA << 10 | MODO_MANUAL << 11 | EN_CICLO << 12 | BombaM_march << 9 | Molino_march << 8 | Cesto_1 << 7 | Cesto_0 << 6 | Ctl_Llama << 5 | REpc << 4 | REbasc << 3 | AlarV << 2 | LlaQuemador << 1 | REhorno;

                        if (RX_CHEKA != CHEK_A) {
                            generar_A(0x60f000, 0x0367, 0, 0);
                        }

                    }

                    //ESTADOS CON ALERTAS QUEMADOR SIN AYUDA 
                    if ((ESTADO_0 == 0 || ESTADO_0 == 1 || ESTADO_0 == 2 || ESTADO_0 == 3) && BANDERA_ALARMAQENC == 0 && BANDERA_ALARQUEM == 1 && BANDERA_HELPQ == 1 && BANDERA_ALARPRE == 0 && BANDERA_ALARMOL == 0) {
                        AlarR = 1;
                        AlarV = 0;
                        DA = AlarR << 13 | EN_ESPERA << 10 | MODO_MANUAL << 11 | EN_CICLO << 12 | BombaM_march << 9 | Molino_march << 8 | Cesto_1 << 7 | Cesto_0 << 6 | Ctl_Llama << 5 | REpc << 4 | REbasc << 3 | AlarV << 2 | LlaQuemador << 1 | REhorno;

                        if (RX_CHEKA != CHEK_A) {
                            generar_A(0x600000, 0x0367, 0, RES1);
                        }
                    }

                    // ERROR EN EL QUEMADOR ENCENDIDO                       
                    if ((ESTADO_0 == 0 || ESTADO_0 == 1 || ESTADO_0 == 2 || ESTADO_0 == 3) && BANDERA_ALARMAQENC == 1 && BANDERA_HELPQ == 0 && BANDERA_ALARQUEM == 1 && BANDERA_ALARPRE == 0 && BANDERA_ALARMOL == 0) {
                        AlarR = 1;
                        AlarV = 0;
                        DA = AlarR << 13 | EN_ESPERA << 10 | MODO_MANUAL << 11 | EN_CICLO << 12 | BombaM_march << 9 | Molino_march << 8 | Cesto_1 << 7 | Cesto_0 << 6 | Ctl_Llama << 5 | REpc << 4 | REbasc << 3 | AlarV << 2 | LlaQuemador << 1 | REhorno;

                        if (RX_CHEKA != CHEK_A) {
                            generar_A(0x600000, 0x0367, 0, RES1);
                        }

                    }
                    //---------------------FIN ERRORES QUEMADOR--------------------------------------------------------------------------------------------------                     


                    // ESTADOS CON ALERTAS PRECALENTADOR                       
                    if ((ESTADO_0 == 0 || ESTADO_0 == 2 || ESTADO_0 == 4 || ESTADO_0 == 6) && BANDERA_HELPP == 0 && BANDERA_ALARPRE == 1 && BANDERA_ALARQUEM == 0 && BANDERA_ALARMOL == 0) {
                        AlarR = 1;
                        AlarV = 0;
                        DA = AlarR << 13 | EN_ESPERA << 10 | MODO_MANUAL << 11 | EN_CICLO << 12 | BombaM_march << 9 | Molino_march << 8 | Cesto_1 << 7 | Cesto_0 << 6 | Ctl_Llama << 5 | REpc << 4 | REbasc << 3 | AlarV << 2 | LlaQuemador << 1 | REhorno;

                        if (RX_CHEKA != CHEK_A) {
                            generar_A(0x60f000, 0x0368, 0, 0);
                        }
                    }


                    //        PRECALENTADOR CON AYUDA      
                    if ((ESTADO_0 == 0 || ESTADO_0 == 2 || ESTADO_0 == 4 || ESTADO_0 == 6) && BANDERA_HELPP == 1 && BANDERA_ALARPRE == 1 && BANDERA_ALARQUEM == 0 && BANDERA_ALARMOL == 0) {
                        AlarR = 1;
                        AlarV = 0;
                        DA = AlarR << 13 | EN_ESPERA << 10 | MODO_MANUAL << 11 | EN_CICLO << 12 | BombaM_march << 9 | Molino_march << 8 | Cesto_1 << 7 | Cesto_0 << 6 | Ctl_Llama << 5 | REpc << 4 | REbasc << 3 | AlarV << 2 | LlaQuemador << 1 | REhorno;

                        if (RX_CHEKA != CHEK_A) {
                            generar_A(0x600000, 0x0368, 0, RES1);
                        }
                    }
                    //---------------------FIN ERRORES PRECALENTADOR --------------------------------------                        


                    // ESTADOS CON ALERTAS MOLINO          
                    if ((ESTADO_0 == 0 || ESTADO_0 == 2 || ESTADO_0 == 4 || ESTADO_0 == 6) && BANDERA_ALARMOL == 1 && BANDERA_HELPM == 0 && BANDERA_ALARPRE == 0 && BANDERA_ALARQUEM == 0) {
                        AlarR = 1;
                        AlarV = 0;
                        DA = AlarR << 13 | EN_ESPERA << 10 | MODO_MANUAL << 11 | EN_CICLO << 12 | BombaM_march << 9 | Molino_march << 8 | Cesto_1 << 7 | Cesto_0 << 6 | Ctl_Llama << 5 | REpc << 4 | REbasc << 3 | AlarV << 2 | LlaQuemador << 1 | REhorno;

                        if (RX_CHEKA != CHEK_A) {
                            generar_A(0x60f000, 0x0369, 0, 0);
                        }
                    }

                    if ((ESTADO_0 == 0 || ESTADO_0 == 2 || ESTADO_0 == 4 || ESTADO_0 == 6) && BANDERA_ALARMOL == 1 && BANDERA_HELPM == 1 && BANDERA_ALARPRE == 0 && BANDERA_ALARQUEM == 0) {
                        AlarR = 1;
                        AlarV = 0;
                        DA = AlarR << 13 | EN_ESPERA << 10 | MODO_MANUAL << 11 | EN_CICLO << 12 | BombaM_march << 9 | Molino_march << 8 | Cesto_1 << 7 | Cesto_0 << 6 | Ctl_Llama << 5 | REpc << 4 | REbasc << 3 | AlarV << 2 | LlaQuemador << 1 | REhorno;

                        if (RX_CHEKA != CHEK_A) {
                            generar_A(0x600000, 0x0369, 0, RES1);
                        }
                    }
                    //---------------------FIN ERRORES MOLINO ------------------

                    if (RX_CHEKA == CHEK_A) { //CONTROL DEL CHEKSUM ENVIADO
                        CHEK_A = -1;
                        ESTADO_1 = ESTADO_0;

                    }

                } // FIN ESTADO TABLA ESTADO                 

                // FIN DE LA TABLA


                if (num == 0 && tabla_sk == 1 && TP10S == 0) { //20
                    ESTADO_1 = 10;
                    CHEK_A = -1;
                }
                //----------------- FIN MANEJO DE LA TABLA----------------------------- 


                //SOFTKEY SIN ALARMA                
                if ((SOFTK_N == 0) && (SOFTK_A == 5) && BANDERA_ALARQUEM == 0 && BANDERA_ALARPRE == 0) { //PULSO TECLA  5 ACTUALIZAR DENTRO DE MANUAL
                    SOFTK_A = 0;

                    if (num == 0 && BANDERA_quemador == 0 && BANDERA_molino == 0 && BANDERA_precalentador == 0) { // REVISAR CONDICION 
                        SOFTK_A = 0;
                        SK_C = 0;
                        CHEK_A = -1;
                        ESTADO_1 = 10;
                        SALIR_MANUAL = 0;
                        tabla_sk = 1;
                    }

                    // BANDERA DENTRO DEL QUEMADOR
                    if (num == 1 && tabla_sk == 0) {
                        BANDERA_ACTUALIZAQ = 1;
                    }

                    // BANDERA DENTRO DEL PRECALENTADOR   
                    if (num == 3 && tabla_sk == 0) {
                        BANDERA_ACTUALIZAP = 1;
                    }

                    // BANDERA DENTRO DEL MOLINO   
                    if (num == 2 && tabla_sk == 0) {
                        BANDERA_ACTUALIZAM = 1;
                    }

                } //    FIN SK5   ACTUALIZAR


                /*   QUEMADOR   */
                //PULSO TECLA  1 ENCENDER QUEMADOR DENTRO DE MANUAL                   
                if ((SOFTK_N == 0) && (SOFTK_A == 1) && (apagar_Q == 0)&& (BANDERA_ALARQUEM == 0) && Qmarch == 1) {
                    SOFTK_A = 0;
                    num = 1;

                    if (BANDERA_quemador == 1)
                        aviso_Qarr = 1;

                    BANDERA_quemador = 1;
                }// FIN DE SK1  QUEMADOR  


                //PULSO TECLA  1 APAGAR QUEMADOR DENTRO DE MANUAL          
                if ((SOFTK_N == 0) && (SOFTK_A == 1) && (apagar_Q == 1)&& (BANDERA_ALARQUEM == 0)) {
                    SOFTK_A = 0;
                    APQ = 0;
                    reset_tiempoQ();
                    apagar_Q = 0;
                    aviso_Qarr = 0;
                    BANDERA_quemador = 0;
                    Qarr = 1;
                    num = 0;

                } //FIN SK1  

                if (FINAL >= (tPIR1 + tPIR2 + tPIR3)) { // SE LLEGA AL TIEMPO MAXIMO TOTAL
                    SOFTK_A = 0;
                    APQ = 0;
                    reset_tiempoQ();
                    apagar_Q = 0;
                    aviso_Qarr = 0;
                    BANDERA_quemador = 0;
                    Qarr = 1;
                    num = 0;

                } // FIN DE CONTROL DE TIEMPO FINAL  


                // FIN SOFTKEY SIN ALARMA           


                //-------- HAY UNA ALARMA ENCENDIDA----------------- 
                if (SOFTK_A == 6 && SOFTK_N == 0 && (BANDERA_ALARQUEM == 1)) {
                    BANDERA_ALARMAQENC = 0;
                    SOFTK_A = 0;
                    BANDERA_ALARQUEM = 0;
                    BANDERA_HELPQ = 0;
                    RES1 = 0;
                }

                if (SOFTK_A == 4 && SOFTK_N == 0 && (BANDERA_ALARQUEM == 1)) {
                    SOFTK_A = 0;
                    BANDERA_HELPQ = 1;
                }


                if (APQ == 1 && TIR >= (STALARM + TCCORT)) {
                    // MODIFICAR ALARMA DE QUEMADOR ENCENDIDO CON TERMOCUPLA CORTADA
                    BANDERA_ALARMAQENC = 1;
                    RES1 = 4;
                    BANDERA_ALARQUEM = 1;
                    APQ = 0;
                    apagar_Q = 0;
                    aviso_Qarr = 0;
                    BANDERA_quemador = 0;
                    Qarr = 1;
                    num = 0;

                }

                //------------------------------------------------------------------------           
                if (APQ == 1) // TAREA ACTIVADA DEL QUEMADOR
                {
                    EN_ESPERA = 0;
                    MODO_MANUAL = 1;
                    EN_CICLO = 0;

                    tiempo_Q();
                    Apq(TMAN); //TAREA PERIODICA DEL QUEMADOR

                    //SE APAGO EL QUEMADOR
                    if (!Qmarch == 0) {
                        APQ = 0;
                        apagar_Q = 0;
                        aviso_Qarr = 0;
                        BANDERA_quemador = 0;
                        Qarr = 1;
                        num = 0;
                    }
                }
                //--------FIN QUEMADOR------------------------------------------------    



                /********************PRE CALENTADOR**************************/
                //PULSO TECLA  3 ENCENDER PRECALENTADOR DENTRO DE MANUAL                   
                if ((SOFTK_N == 0) && (SOFTK_A == 3) && (apagar_P == 0)&& (BANDERA_ALARPRE == 0) && PCmarch == 1) {
                    SOFTK_A = 0;
                    num = 3;

                    if (BANDERA_precalentador == 1)
                        aviso_Parr = 1;

                    BANDERA_precalentador = 1;
                }// FIN DE SK3  PRECALENTADOR  



                //PULSO TECLA  3 APAGAR PRECALENTADOR DENTRO DE MANUAL          
                if ((SOFTK_N == 0) && (SOFTK_A == 3) && (apagar_P == 1)&& (BANDERA_ALARPRE == 0)) {
                    SOFTK_A = 0;
                    APP = 0;
                    apagar_P = 0;
                    aviso_Parr = 0;
                    BANDERA_precalentador = 0;
                    PCarr = 1;
                    num = 0;

                } //FIN SK1  

                // FIN SOFTKEY SIN ALARMA           



                //-------- HAY UNA ALARMA ENCENDIDA----------------- 
                if (SOFTK_A == 6 && SOFTK_N == 0 && (BANDERA_ALARPRE == 1)) {
                    SOFTK_A = 0;
                    BANDERA_ALARPRE = 0;
                    BANDERA_HELPP = 0;
                    RES1 = 0;
                }

                if (SOFTK_A == 4 && SOFTK_N == 0 && (BANDERA_ALARPRE == 1)) {
                    SOFTK_A = 0;
                    BANDERA_HELPP = 1;
                }
                //------------------------------------------------------------------------           


                if (APP == 1) // TAREA ACTIVADA DEL PRECALENTADOR
                {
                    // LLego a la temperatura PARAMETRO CORTAR QUEMADOR

                    //SE APAGO EL QUEMADOR
                    if (!PCmarch == 0) {
                        APP = 0;
                        apagar_P = 0;
                        aviso_Parr = 0;
                        BANDERA_precalentador = 0;
                        PCarr = 1;
                        num = 0;
                    }
                }


                //PULSO TECLA 3 APAGAR PRECALENTADOR DENTRO DE MANUAL          
                if ((SOFTK_N == 0) && (SOFTK_A == 3) && (apagar_P == 1)&& (BANDERA_ALARPRE == 0)) {
                    SOFTK_A = 0;
                    APQ = 0;
                    apagar_P = 0;
                    aviso_Parr = 0;
                    BANDERA_precalentador = 0;
                    PCarr = 1;
                    num = 0;

                } //FIN SK1  
                //*********************FIN PRE CALENTADOR*************************************         



                /****************************MOLINO******************************************/
                //PULSO TECLA  2 ENCENDER MOLINO DENTRO DE MANUAL                   
                if ((SOFTK_N == 0) && (SOFTK_A == 2) && (apagar_M == 0) && (BANDERA_ALARMOL == 0) && (Lmarch == 0)) {
                    SOFTK_A = 0;
                    num = 2;

                    BANDERA_molino = 1;
                    // FIN DE SK2  MOLINO 
                }

                if (BANDERA_molino == 1) {
                    if ((SOFTK_N == 0) && (SOFTK_A == 1) && (apagar_M == 0) && (BANDERA_ALARMOL == 0) && (Lmarch == 0)) {
                        SOFTK_A = 0;

                        aviso_Larr = 1;
                    }
                    // FIN DE SK1  MOLINO
                }

                // Si no se cumple la condicion de funcionamiento y esta en marcha, detiene el molino
                if (Lmarch == 1 && !(PE2 == 1 && PE1 == 0)) {
                    Larr = 1;
                    APM = 0;
                    apagar_M = 0;
                    aviso_Larr = 0;
                    BANDERA_molino = 0;
                    AlarS = 0;
                    num = 0;
                    BANDERA_lluviamarch = 0;
                }


                //PULSO TECLA 2 APAGAR MOLINO DENTRO DE MANUAL          
                if ((SOFTK_N == 0) && (SOFTK_A == 2) && (apagar_M == 1) && (BANDERA_ALARMOL == 0)) {
                    SOFTK_A = 0;
                    APM = 0;
                    apagar_M = 0;
                    aviso_Larr = 0;
                    BANDERA_molino = 0;
                    Larr = 1;
                    AlarS = 0;
                    num = 0;
                    BANDERA_lluviamarch = 0;
                }

                // FIN SOFTKEY SIN ALARMA           


                //-------- HAY UNA ALARMA ENCENDIDA----------------- 
                if (SOFTK_A == 6 && SOFTK_N == 0 && (BANDERA_ALARMOL == 1)) {
                    SOFTK_A = 0;
                    BANDERA_ALARMOL = 0;
                    BANDERA_HELPM = 0;
                    RES1 = 0;
                }

                if (SOFTK_A == 4 && SOFTK_N == 0 && (BANDERA_ALARQUEM == 1)) {
                    SOFTK_A = 0;
                    BANDERA_HELPM = 1;
                }


                //------------------------------------------------------------------------           

                if (APM == 1) { // TAREA ACTIVADA DEL MOLINO
                    BANDERA_lluviamarch = 1;

                    //SE APAGO EL MOLINO
                    //                    if (Lmarch == 0) {
                    //                        APM = 0;
                    //                        BANDERA_lluviamarch = 0;
                    //                        apagar_M = 0;
                    //                        aviso_Larr = 0;
                    //                        BANDERA_molino = 0;
                    //                        Larr = 1;
                    //                        AlarS = 0;
                    //                        num = 0;
                    //                    }
                }


                //*************************FIN MOLINO***********************************  

                /* FIN DEL PUNTO 5*/
                break;
            default:
                break;
        }
        //----------------- FIN DEL SISTEMA DE ARRANQUE---------------------------------

    }// FINAL DE LA TAREA NO PERIODICA


    return 0;
}

/*INTERRUPCION TIMER2 10ms TAREA PERIODICA */
void __attribute__((__interrupt__, no_auto_psv)) _T2Interrupt(void) {

    if (HAB == 1) {
        pulso_watchdog();
    }

    if ((signal_emergencia == 1)) { // PULSADOR DE EMERGENCIA BORRAR TODAS LAS BANDERAS Y APAGAR MAQUINAS
        __asm__ volatile ("reset "); //Instruccion de reinicio A LA SALIDA DE PARAMETROS    
    }

    // Lectura de Softkeys
    SOFTK_N1 = (!SKC3) << 2 | (!SKC2) << 1 | (!SKC1);

    if (SOFTK_A != SOFTK_N1) {
        SOFTK_A = SOFTK_N;
        SOFTK_N = SOFTK_N1;
    }

    // Habilitacion de Grua, ahora mismo sigue SERVOSON
    Garr = SON;

    // Timer de 1 segundo
    if (TP1S == 0) {
        TP1S = NP1K;
    } else {
        TP1S--;
    }

    //-------------- INICIO TAREA PERIODICA DE 10 SEGUNDOS  -------------------
    if (TP10S == 0) {
        TP10S = NP10K; // Reinicio contador
    } else {
        TP10S--; // Decremento contador
    }

    if (Punto > 2) { // Si sale de parametros
        if (SOFTK_N == 5 || SOFTK_A == 5) {
            SOFTK_A = 0;
            YAC = 0;
        }
        if (YAC == 0) {
            TP10S = NP10K;
            PASADA = 0;
        }

        if (TP10S >= NP5K || PASADA == 0) {
            SEL = 1;
            if (TP10S == NP5K || YAC == 0) {
                // Muestreo de seniales analogicas
                for (int i = 0; i <= TAM_CONVERSOR - 1; i++)
                    V[i + 4] = convierteAD(i);
                ND = ND * a + V[4] * b;
                PIR = PIR * a + V[5] * b;
                TIB = TIB * a + V[6] * b;
                TD = TD * a + V[7] * b;
            }

        } else if (TP10S < NP5K || PASADA == 1) {
            SEL = 0;
            if (TP10S == 0 || YAC == 0) {
                // Muestreo de seniales analogicas
                for (int i = 0; i <= TAM_CONVERSOR - 1; i++)
                    V[i] = convierteAD(i);
                ND = (ND * NDa + V[0] * NDb);
                TIR = TIR * TIRa + V[1] * TIRb;
                TIP = TIP * a + V[2] * b;
                TCF = (TCF * a + V[3] * b);

                //-------------- ACTUALIZACION VARIABLES ANALOG/DIGITALES  ------------------- 

                LlaQuemador = apagar_Q; //__________________NF  DA[1]   LLama de quemador+Fuego Horno+ Cartel
                REhorno = (TIR <= TCCORT_MUL2) ? 1 : 0; //__NF  DA[0]   Reactor en el horno 
                AlarV = Alarma_verde; //____________________NF  DA[2]   Alarma Verde
                REbasc = (TIB <= TCCORT_MUL2) ? 1 : 0; //___NF  DA[3]   Reactor en estacion Basc  
                REpc = (TIP <= TCCORT_MUL2) ? 1 : 0; //_____NF  DA[4]   Reactor en estacion PreC
                Ctl_Llama = apagar_P; //____________________NF  DA[5]   Cartel estacion PreC
                Cesto_0 = (!PE1) && (PE2); //_______________NF  DA[6]   COndicion Cesto
                Cesto_1 = (!PE2) && (!PE1); //______________NF  DA[7]   COndicion Cesto
                Molino_march = BANDERA_lluviamarch; //______NF  DA[8]   
                BombaM_march = !LBA; //_____________________NF  DA[9]   COndicion Cesto  
                AlarR = Alarma_roja; //_____________________NF  DA[13]   Alarma Roja

                BANDERA_HELPQNDmax = ((float) ND >= NCMAX) ? 1 : 0; //no se puede realizar mas ciclos deposito lleno
                BANDERA_HELPQNDmin = ((float) ND < NCMIN) ? 1 : 0; // falta nivel para realizar pirolisis
                BANDERA_HELPQTCF = !QOK;

                TP10S = NP10K; // Reinicio contador
            }
        }

        DA = AlarR << 13 | EN_ESPERA << 10 | MODO_MANUAL << 11 | EN_CICLO << 12 | BombaM_march << 9 | Molino_march << 8 | Cesto_1 << 7 | Cesto_0 << 6 | Ctl_Llama << 5 | REpc << 4 | REbasc << 3 | AlarV << 2 | LlaQuemador << 1 | REhorno;
        generar_A(0x650321, 0x0100, 1, 0);

        if (PASADA == 0) {
            PASADA = 1;
        } else if (PASADA == 1) {
            YAC = 1;
        }
    }
    //-------------- FIN TAREA PERIODICA DE 10S Y ACTUALIZACION VARIABLES ANALOG/DIGITAL  -------------------



    switch (Punto) {
        case 0:
            /* INICIO DE PUNTO 0 */
            /* ENVIO EL CHSUM DE LA TABLA DE PARAMETROS CAMBIO A PANTALLA 2  */
            if (TP1S == 0) {
                if (RX_CHEKC != CHEK_C && DMA0REQbits.FORCE == 0) {
                    sprintf(aux_dma_tx, "C=%.2x%.2x%.2x\n", 1, CHEK_P, CHEK_C); // ME DEVUELVE LO QUE YO LE ENVIO COMO CHEK_P
                    cargar_DMA_C(aux_dma_tx);
                    enviar_DMA();
                }
                if (RX_CHEKC == CHEK_C) {
                    RX_CHEKC = 0;
                    CHEK_A = -1; // si se corta elmensaje manda H=0 OJO
                    SK_C = 0;
                }
            }
            /* FIN DE PUNTO 0 */
            break;

        case 1:
            /* INICIO DEL PUNTO 1 PANTALLA ARRANQUE Y LETREROS ESTADOS */
            if (TP1S == 0) {
                if (SK_C == 0) {
                    if (RX_CHEKA != 49) { //CONTROL DE LOS CHEK ENVIADO
                        cargar_DMA_A("A=00000000000000000000000000000000000000001110000000000000200031\n");
                        enviar_DMA();

                    }
                    if (RX_CHEKA == 49) {
                        SK_C = 1;
                        CHEK_A = -1;
                    }
                }
            }
            /* FIN DEL PUNTO 1*/
            break;

        case 2:
            /* INICIO DEL PUNTO 2 PANTALLA PARAMETROS */
            if (TP1S == 0) {
                if (RX_CHEKA != CHEK_A) {//sk eo
                    generar_A(0x000000, 0x0000, 0, 0);
                }
            }
            /* FIN DEL PUNTO 2*/
            break;

        case 3:
            /* INICIO DEL PUNTO 3 (SE ACCIONO SERVOS) PASA A PANTALLA PPAL*/

            //IMPRESION LETREROS SELECCION AUTOMATICO-MANUAL-PARAMETROS-ACTUALIZAR-RETROCEDER
            Alarma_verde = 1;
            EN_ESPERA = 1;
            MODO_MANUAL = 0;
            EN_CICLO = 0;
            DA = AlarR << 13 | EN_ESPERA << 10 | MODO_MANUAL << 11 | EN_CICLO << 12 | BombaM_march << 9 | Molino_march << 8 | Cesto_1 << 7 | Cesto_0 << 6 | Ctl_Llama << 5 | REpc << 4 | REbasc << 3 | AlarV << 2 | LlaQuemador << 1 | REhorno;


            // IMPRESION DE  LETREROS DE LAS SOFTKEY
            if (SK_C == 0) {
                /* SE PASA A PANTALLA PRINCIPAL Y SE IMPRIMEN SOFTKEY */
                if (RX_CHEKA != CHEK_A && (TP1S == 0)) {
                    generar_A(0x650321, 0x0100, 1, 0);
                }

                if (RX_CHEKA == CHEK_A) { //CONTROL DE LOS CHEK ENVIADO CAMBIO DE PANTALLA
                    CHEK_A = -1;
                    SK_C = 1;
                    Punto = 4;
                }
            }
            /* FIN DEL PUNTO 3*/
            break;

        case 4:
            /* INICIO DEL PUNTO 4*/
            //ESPERANDO COMANDO - MANUAL- AUTOMATICO- ACTUALIZAR

            // TECLA RETROCEDER SK 6
            if (SOFTK_A == 6 && SOFTK_N == 0) {
                SOFTK_A = 0;
                SK_C = 0;
                Punto = 0;
            }

            // ENVIO DE MSJ ACTUALIZACION DE PANTALLA CADA 10 SEGUNDOS
            if (TP10S == 0) {
                DA = AlarR << 13 | EN_ESPERA << 10 | MODO_MANUAL << 11 | EN_CICLO << 12 | BombaM_march << 9 | Molino_march << 8 | Cesto_1 << 7 | Cesto_0 << 6 | Ctl_Llama << 5 | REpc << 4 | REbasc << 3 | AlarV << 2 | LlaQuemador << 1 | REhorno;
                generar_A(0x650321, 0x0100, 1, 0);
            }

            // TECLA ACTUALIZAR SK 5    
            if (SOFTK_A == 5 || SOFTK_N == 0) {
                SOFTK_A = 0;
                //generar_A(0x650321, 0x0100, 1, 0);
            }

            //TECLA SK 3 MODO MANUAL
            if (SOFTK_A == 3 && SOFTK_N == 0) { // PRESIONO SK 3- ELIJO MODO MANUAL
                SOFTK_A = 0;
                SOFTK_N = 0;
                Punto = 5; //MODO MANUAL
                MODO = 2; // TAREA NO PERIODICA ENTRA EN MANUAL
                SK_C = 0;
                ESTADO_0 = 0;
                tabla_sk = 0;
            }
            /* FIN DEL PUNTO 4*/
            break;

        default: break;
    }

    IFS0bits.T2IF = 0; // Clear Timer1 Interrupt Flag
    return;
}



