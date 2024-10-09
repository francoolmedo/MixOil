
#ifndef HARDWARE_IO_H
#define	HARDWARE_IO_H

#include "xc.h"
#include <stdbool.h>
#include "p33FJ256MC710.h"



//---------------------------- PINERA P6 SALIDA DIGITAL -----------------------------------

#define SFK4 	PORTAbits.RA7	//Softkey 4
#define EXTRESET 	PORTAbits.RA6	//Reset externo
#define SS1 	PORTBbits.RB2	//Bit de Seleccion de Escalvo SPI
#define EXTCICLO 	PORTEbits.RE1//Senial de ciclo externa


// En conector P1-DISP
#define SFK5                PORTDbits.RD6	//Softkey 5
#define SFK6                PORTDbits.RD7	//Softkey 6
#define SFK7                PORTDbits.RD4	//
#define SFK8             	PORTDbits.RD5	//
#define PAD4                LATDbits.LATD11 // SD16

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

//---------------------- SALIDAS DIGITALES --------------------------------        
#define PTRG              LATGbits.LATG0      //S01 - SERVO - moverse a posisción pedida
#define POS1              LATGbits.LATG1      //S02 - SERVO - BIT 1 codificación posición
#define POS2              LATAbits.LATA0      //S03 - SERVO - BIT 2 codificación posición
#define POS3              LATBbits.LATB0      //S04 - SERVO - BIT 3 codificación posición
#define POS4              LATGbits.LATG6      //S05 - SERVO - BIT 4 codificación posición
#define SHOME             LATGbits.LATG7      //S06 - SERVO - buscar origen
#define LISTO             LATGbits.LATG8      //S07 - CNC OK 
#define HAB_SRV           LATGbits.LATG9      //S08 - SERVO - Habilita Servo (TECO)
#define H_C0A             LATGbits.LATG12     //S09 - Habilita Reg M_C0A, MC0B (SEW)), M_C1A
#define H_C1              LATGbits.LATG13     //S10 - Habilita Reg MC_1 (POWTRAN)
// No esta instalado
#define H_C2              LATGbits.LATG14     //S11 - Habilita Reg M_C2 (POWTRAN) //VER
#define DF              LATGbits.LATG15     //S12 - VISION - Sacar Foto
// TOTAL : 12/12
//-------------------------------------------------------------------------

//------------ SALIDAS AGREGADAS ------------------------------------------ 
#define PAD1             LATBbits.LATB3  // SD13
#define PAD2             LATBbits.LATB4  // SD14 
#define PAD3             LATBbits.LATB5  // SD15


//PINERA ENTRADA P3 ¡ CON SALIDAS DIGITALES ! 
#define PWM1                LATEbits.LATE0      //ED1
#define PWM2                LATEbits.LATE2      //ED3

//---------------------- ENTRADAS DIGITALES P3 -------------------------------

//#define SALIDAS           PORTEbits.RE1      //ED2  SON SALIDAS 
//#define ED4               PORTEbits.RE3      //ED4  SALIDAS
#define PUL_DET             PORTEbits.RE4      //E05 - EMERGENCIA ver placa o micro
#define BFE1                PORTEbits.RE5      //E06 - Sensor de papa en primer cinta en V
#define PUL_CIC             PORTEbits.RE6      //E07 - Pulsador CICLO
#define RSE                 PORTEbits.RE7      //E08 - Pulsador DETENCION
//#define e_A_REG             PORTEbits.RE7    //E06 - Alarma reguladores M_C1/M_C2/M_C0A
#define A_SRV               PORTAbits.RA2      //E09 - SERVO - ready
#define L1                  PORTAbits.RA3      //E10 - ED10 - Sensor de proximidad detecta separadores en cinta plana
#define HOME                PORTAbits.RA4      //E11 - SERVO - referenciado
#define INP                 PORTAbits.RA5      //E12 - SERVO - alcanzo posición
#define SEL1                PORTEbits.RE8      //E13 - VISION - nueva detección
#define SEL2                PORTEbits.RE9      //E14 - VISION - BIT 1 codificación clase
#define SEL3                PORTAbits.RA9      //E15 - VISION - BIT 2 codificación clase
#define STROBE              PORTAbits.RA10     //E16 - VISION - BIT 3 codificación clase

// TOTAL: 12/16

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