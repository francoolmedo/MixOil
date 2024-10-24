
#ifndef HARDWARE_IO_H
#define	HARDWARE_IO_H

#include "xc.h"
#include <stdbool.h>
#include "p33FJ256MC710.h"



//---------------------------- PINERA P6 SALIDA DIGITAL -----------------------------------

#define PCarr   LATAbits.LATA7  // K1  BORNERA RELE ARDUINO   PRE CALENTADOR
#define Larr 	LATAbits.LATA6	// K2  BORNERA RELE ARDUINO   LAVADORA	este es Larr original
#define Qarr 	LATBbits.LATB2	// K3  BORNERA RELE ARDUINO   QUEMADOR este es Qarr original
#define Garr 	LATBbits.LATB1  // K4  BORNERA RELE ARDUINO	  GRUA este es Garr original


/* En conector P1-DISP
#define SFK5                PORTDbits.RD6	//Softkey 5
#define SFK6                PORTDbits.RD7	//Softkey 6
#define SFK7                PORTDbits.RD4	//
#define SFK8             	PORTDbits.RD5	//
*/

//SALIDA DIGITAL MANEJO CD4043 EN CONECTOR P4-DISP

#define SEL             	LATDbits.LATD12	// pin 79 uprocesador RD12


//--------------------------------------------------------------------------

//-------------------------TECLADO MATRICIAL -------------------------------
/* NO USADO
#define S_C4	LATBbits.LATB8	//Columna 4
#define S_C3	LATBbits.LATB9	//Columna 3
#define S_C2 	LATBbits.LATB10	//Columna 2
#define S_C1	LATBbits.LATB11	//Columna 1
#define E_F4 	PORTBbits.RB12	//Fila 4
#define E_F3 	PORTBbits.RB13	//Fila 3
#define E_F2 	PORTBbits.RB14	//Fila 2
#define E_F1	PORTBbits.RB15	//Fila 1
*/
//-------------------------------------------------------------------------

//---------------------- SALIDAS DIGITALES --------------------------------                      CABLE   BORNERA 
#define ApSv1               LATGbits.LATG0      //SD1 Apertura servo valvula bit 1             165       B4 1
#define ApSv2               LATGbits.LATG1      //SD2 Apertura servo valvula bit 2             166       B4 3  
#define ApSv4               LATAbits.LATA0      //SD3 Apertura servo valvula bit 3             167       B4 5   
#define ApSv8               LATBbits.LATB0      //SD4 Apertura servo valvula bit 4             168       B4 7  
#define HAB                 LATGbits.LATG6      //SD5 Cadena de pulsadores de Emergencia       151 
#define AlarVV              LATGbits.LATG7      //SD6 indicador luminoso Alarma (Baliza verde) 169 B4 11
#define AlarVR              LATGbits.LATG8      //SD7 indicador luminoso Alarma                170 B4 13 
#define AlarS               LATGbits.LATG9      //SD8 indicador acustico Alarma (Buzzer)       171 B4 15
#define Iarr                LATGbits.LATG12     //SD9 Forzar alarma de incendio                172  B4 17 
#define WDD                 LATGbits.LATG13     //SD10 WAtch dog  
#define SD11                LATGbits.LATG14     //SD11 
#define SD12                LATGbits.LATG15     //SD12

   // TOTAL : 10/12
//-------------------------------------------------------------------------

//---------------------- ENTRADAS DIGITALES -------------------------------
#define WDOK                PORTEbits.RE0      //ED1 Watch dog ok
#define Gok                 PORTEbits.RE1      //ED2 GRUA OK
#define Lmarch              PORTEbits.RE2      //ED3 Lavadora en marcha
#define LBA                 PORTEbits.RE3      //ED4 
#define Pcic                PORTEbits.RE4      //ED5 Pulsador de ciclo-Repite la SK1
#define Qmarch              PORTEbits.RE5      //ED6 Quemador en marcha
#define QOK                 PORTEbits.RE6      //ED7 
#define DET                 PORTEbits.RE7      //ED8
#define NO_EMER             PORTAbits.RA2      //ED9  NO EMERGENCIA  
#define SKC1                PORTAbits.RA3      //ED10  Softkey 1  
#define SKC2                PORTAbits.RA4      //ED11  Softkey 2 
#define SKC3                PORTAbits.RA5      //ED12  Softkey 3
#define PCmarch             PORTEbits.RE8      //ED13 PRE CALENTADOR en marcha
#define SON                 PORTEbits.RE9      //ED14 SERVOS ON
#define PE1                 PORTAbits.RA9      //ED15 
#define PE2                 PORTAbits.RA10     //ED16

// TOTAL: 16/16

//-------------------------------------------------------------------------

//------------------------ SALIDAS CONVERSOR DAC --------------------------
#define PIN_A1              LATFbits.LATF13   //A1 Bit mas significativo
#define PIN_A2              LATFbits.LATF12   //A2   
#define PIN_A3              LATFbits.LATF5    //A3
#define PIN_A4              LATFbits.LATF4    //A4
#define PIN_A5              LATDbits.LATD14   //A5
#define PIN_A6              LATDbits.LATD15   //A6
#define PIN_A7              LATFbits.LATF1    //A7
#define PIN_A8              LATFbits.LATF0    //A8 Bit menos significativo
//-------------------------------------------------------------------------


//------------------------- SALIDAS INDICADORAS ---------------------------
#define STATUS_LED          LATDbits.LATD13 //Led de Ciclo
#define ST1                 LATGbits.LATG3  //Test point 1 - Pin 5
#define ST2                 LATGbits.LATG2  //Test point 2 - Pin 6

//-------------------------------------------------------------------------

#endif