#include "timer.h"

//------------------------------------------------------------------------------
//                          Funciones TIMER 1
//------------------------------------------------------------------------------
/*
void inicializaTimer1(void){
    T1CON = 0;              // Timer reset (Stop T1 - Prescaler 1:1 - Internal Clock)
    resetTimer1();          // Reset Timer1 Interrupt Flag, timer1 value and period1 value
//    IPC0bits.T1IP = 5;      // Timer1 Interrupt priority level = 6
    //IEC0bits.T1IE = 0;      // Disable Timer1 interrupt
    IEC0bits.T1IE = 1;      // Enable Timer1 interrupt
    //T1CONbits.TON = 0;      // Stop Timer 1
    T1CONbits.TON = 1;      // Start Timer 1
    return;
}
void RUN_Timer1(void){
    IEC0bits.T1IE = 1;      // Enable Timer1 interrupt
    T1CONbits.TON = 1;      // Start Timer 1
    return;
}
void STOP_Timer1(void){
    IEC0bits.T1IE = 0;      // Disable Timer1 interrupt
    T1CONbits.TON = 0;      // Stop Timer 1
    return;
}
void resetTimer1(void){
    IFS0bits.T1IF = 0;      // Reset Timer1 interrupt flag
    TMR1 = TMR1_INIT;       // Timer1 register
    PR1 = PR1_INIT;         // Timer1 period register
}
//------------------------------------------------------------------------------
 */
//------------------------------------------------------------------------------
//                          Funciones TIMER 2 y 3
//------------------------------------------------------------------------------

/*TIMER 2/3 UNIDOS PARA FORMAR UN TIMER DE 32BIT */

/*

void inicializaTimer2(void){
    
    T3CONbits.TON = 0;      // Stop any 16-bit Timer3 operation
    T2CONbits.TON = 0;      // Stop any 16/32-bit Timer2 operation
    T2CONbits.T32 = 1;      //Timer 2 y Timer 3 Modo 32 bits
                            //1 = Timer2 and Timer3 form a single 32-bit timer
                            //0 = Timer2 and Timer3 act as two 16-bit timers
    T2CONbits.TCS = 0;      //Timer2 Clock Source Select bit
                            //1 = External clock from pin TxCK (rising edge)
                            //0 = Internal clock (FCY = FOSC/2 = 7,37Mhz/2 = 3,685Mhz)
    T2CONbits.TGATE = 0;    //Timer2 Gated Time Accumulation Enable bit
                            //TCS = 1: This bit is ignored
                            //TCS = 0: 1 = Gated time accumulation enabled
                            //         0 = Gated time accumulation disabled
    T2CONbits.TCKPS = 0b00; //Timer2 Input Clock Prescale Select bits
                            //3 = 11 = 1:256
                            //2 = 10 = 1:64
                            //1 = 01 = 1:8
                            //0 = 00 = 1:1
    TMR3 = 0;               //Valor de inicio contador timer 3
    TMR2 = 0;               //Valor de inicio contador timer 2
    PR3 = PR3_INIT;                //(Parte Baja) - Timer3 period register
    PR2 = PR2_INIT;                //(Parte Alta) - Timer2 period register
    
    //IPC2bits.T3IP = 6;      //Prioridad - xxx = Interrupt priority 
                              //            000 = Interrupt source is disabled
    IFS0bits.T3IF = 0;      //Clear Timer3 Interrupt Flag   
    IEC0bits.T3IE = 1;      //Timer2_3 Interrupt Enable bit (en modo 32 bits)
  
    T2CONbits.TON = 1;      //Start Timer 2
    
}
void RUN_Timer2(void){
    IEC0bits.T2IE = 1;      //Timer2_3 Interrupt Enable bit (en modo 32 bits)
    T2CONbits.TON = 1;      //Start Timer 2
    return;
}
void STOP_Timer2(void){
    IEC0bits.T2IE = 0;      //Disable Timer 2 interrupt
    T2CONbits.TON = 0;      //Stop Timer 2
    return;
}
void resetTimer2(void){
    IFS0bits.T2IF = 0;      //Reset Timer 2 interrupt flag
    TMR2 = TMR2_INIT;       //Timer 2 register
    TMR3 = TMR3_INIT;       //Timer 3 register
    PR2 = PR2_INIT;         //Parte Alta - Timer 2 period register
    PR3 = PR3_INIT;         //Parte Baja - Timer 3 period register
}
 */
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
//                          Funciones TIMER 2 (10ms)
//------------------------------------------------------------------------------
/*TIMER 2  CONFIGURACION*/

/*
T2CONbits.TON = 0; // Disable Timer
T2CONbits.TCS = 0; // Select internal instruction cycle clock
T2CONbits.TGATE = 0; // Disable Gated Timer mode
T2CONbits.TCKPS = 0b01; // Select 1:1 Prescaler
TMR2 = 0x00; // Clear timer register
PR2 =21880; // valor cargado para generar interrupcion 5ms= 21880 pre 0b01 43760
IPC1bits.T2IP = 0x01; // Set Timer1 Interrupt Priority Level
IFS0bits.T2IF = 0; // Clear Timer1 Interrupt Flag
IEC0bits.T2IE = 1; // Enable Timer1 interrupt
T2CONbits.TON = 1; // Start Timer
 */


void inicializaTimer2(void) {
    T2CONbits.TON = 0; // Disable Timer
    T2CONbits.TCS = 0; // Select internal instruction cycle clock
    T2CONbits.TGATE = 0; // Disable Gated Timer mode
    T2CONbits.TCKPS = 0b10; // Select 1:64 Prescaler 01

    TMR2 = 0x00; // Clear timer register
    PR2 = 5469; // valor cargado para generar interrupcion 10ms 
    IPC1bits.T2IP = 0x06; // Set Timer1 Interrupt Priority Level 1 estaba
    IFS0bits.T2IF = 0; // Clear Timer1 Interrupt Flag

}

void RUN_Timer2(void) {
    IEC0bits.T2IE = 1; //Timer2 Interrupt Enable bit (en modo 16 bits)
    T2CONbits.TON = 1; //Start Timer 2
    return;
}

void STOP_Timer2(void) {
    IEC0bits.T2IE = 0; //Disable Timer 2 interrupt
    T2CONbits.TON = 0; //Stop Timer 2
    return;
}

void resetTimer2(void) {
    IFS0bits.T2IF = 0; //Reset Timer 2 interrupt flag
    TMR2 = TMR2_INIT; //Timer 2 register
    PR2 = PR2_INIT2; // Timer 2 period register

}

















