#ifndef TIMER_H
#define	TIMER_H

#include "p33Fxxxx.h"
#include <stdbool.h>

//******************************   TIMER 1   ***********************************
//#define TMR1_INIT	0x0000      //Valor inicial del contador del timer 1
//#define PR1_INIT    0x01B9      //10us
//#define PR1_INIT    0x0437      //25us
//#define PR1_INIT    0xAC5D      //1ms
//#define PR1_INIT	  0x07D0      //

//***************************   TIMER 2 y 3   **********************************
/*
#define TMR2_INIT	0x0000      //Valor inicial del contador del timer 2
#define TMR3_INIT	0x0000      //Valor inicial del contador del timer 3
#define PR2_INIT    0xffff      //(LSW) - Load 32-bit period value
#define PR3_INIT    0xffff      //(MSW) - Load 32-bit period value
*/
//***************************   TIMER 2   **********************************

#define TMR2_INIT	0x00          //Valor inicial del contador del timer 2
#define PR2_INIT1   21880           // Valor para  (5ms)
#define PR2_INIT2   10940           // Valor para  (10ms)


//********************   Definicion Funciones TIMERS   *************************
void inicializaTimer1(void);
void resetTimer1(void);
void RUN_Timer1(void);
void STOP_Timer1(void);

void inicializaTimer2(void);
void resetTimer2(void);
void RUN_Timer2(void);
void STOP_Timer2(void);

#endif	/* TIMER_H */

