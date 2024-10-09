/*
 * File:   configuraciones.c
 * Author: Ing. Daniel Petrone
 *
 * Created on 3 de abril de 2023, 10:54
 */

// DSPIC33FJ256MC710 Configuration Bit Settings

// 'C' source line config statements

// FBS
#pragma config BWRP = WRPROTECT_OFF     // Boot Segment Write Protect (Boot Segment may be written)
#pragma config BSS = NO_FLASH           // Boot Segment Program Flash Code Protection (No Boot program Flash segment)
#pragma config RBS = NO_RAM             // Boot Segment RAM Protection (No Boot RAM)

// FSS
#pragma config SWRP = WRPROTECT_OFF     // Secure Segment Program Write Protect (Secure Segment may be written)
#pragma config SSS = NO_FLASH           // Secure Segment Program Flash Code Protection (No Secure Segment)
#pragma config RSS = NO_RAM             // Secure Segment Data RAM Protection (No Secure RAM)

// FGS
#pragma config GWRP = OFF               // General Code Segment Write Protect (User program memory is not write-protected)
#pragma config GSS = OFF                // General Segment Code Protection (User program memory is not code-protected)

// FOSCSEL
#pragma config FNOSC = FRCPLL              // Oscillator Mode (Primary Oscillator (XT, HS, EC))
#pragma config IESO = OFF               // Two-speed Oscillator Start-Up Enable (Start up with user-selected oscillator)

// FOSC
#pragma config POSCMD = NONE              // Primary Oscillator Source (HS Oscillator Mode)
#pragma config OSCIOFNC = OFF           // OSC2 Pin Function (OSC2 pin has clock out function)
#pragma config FCKSM = CSECMD           // Clock Switching and Monitor (Both Clock Switching and Fail-Safe Clock Monitor are disabled)

// FWDT
#pragma config WDTPOST = PS32768        // Watchdog Timer Postscaler (1:32,768)
#pragma config WDTPRE = PR128           // WDT Prescaler (1:128)
#pragma config WINDIS = OFF             // Watchdog Timer Window (Watchdog Timer in Non-Window mode)
#pragma config FWDTEN = OFF             // Watchdog Timer Enable (Watchdog timer enabled/disabled by user software)

// FPOR
#pragma config FPWRT = PWR128           // POR Timer Value (128ms)
#pragma config LPOL = ON                // Low-side PWM Output Polarity (Active High)
#pragma config HPOL = ON                // Motor Control PWM High Side Polarity bit (PWM module high side output pins have active-high output polarity)
#pragma config PWMPIN = ON              // Motor Control PWM Module Pin Mode bit (PWM module pins controlled by PORT register at device Reset)

// FICD
#pragma config ICS = PGD1               // Comm Channel Select (Communicate on PGC1/EMUC1 and PGD1/EMUD1)
#pragma config JTAGEN = OFF             // JTAG Port Enable (JTAG is Disabled)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.


//-------------------------  Fin Configuracion BITS  -------------------------//

#include "configuraciones.h"
#include "hardware.h"
#include "constantes.h"

//----------------------------------------------------------------------------//
//                              Configura I/O                                 //
//----------------------------------------------------------------------------//

void configurarEntradasSalidas(void) {
    // TRISFbits.TRISF3=0;
    //TRISFbits.TRISF2=1;
    //Definicion de entradas y salidas
    //*********************  P U E R T O   A  **************************************
    //Entrada = 1, Salida = 0:                 
    TRISA = 0xC6FC; //Entrada = 1, Salida = 0: TRIS_A = 1100 0110 1111 1100

    //*********************  P U E R T O   B  **************************************
    TRISB = 0xF006; //Entrada = 1, Salida = 0: TRIS_B = 1111 0000 0000 0110
    
    /*
        //  Habilitacion pull-up PORTB
        CNPU1 = 0x0000;
        CNPU2 = 0x0000;
  
     */
    //*********************  P U E R T O   C  **************************************    
    TRISC = 0x001E; //Entrada = 1, Salida = 0: TRIS_C = 0000 0000 0001 1110


    //*********************  P U E R T O   D  **************************************
    TRISD = 0x0000; //Entrada = 1, Salida = 0: TRIS_D = 0000 0000 0000 0000


    //*********************  P U E R T O   E  **************************************
    //**** Configuracion - NORMAL -                                   
    TRISE = 0x03F2; //Entrada = 1, Salida = 0: TRIS_E = 0000 0011 1111 0000

    //*********************  P U E R T O   F  **************************************    

    TRISF = 0x00C0; //Entrada = 1, Salida = 0:     TRIS_F = 0000 0000 1100 0000
    //*********************  P U E R T O   G  **************************************    
    TRISG = 0x0000; //Entrada = 1, Salida = 0: TRIS_G = 0000 0000 0000 0000

    //Entradas analogicas desactivadas
    AD1PCFGL = 0xFFFF;
    AD1PCFGH = 0xFFFF;
    AD2PCFGL = 0xFFFF;

    return;
}
//----------------------------  FIN Configura I/O  ---------------------------//

//----------------------------------------------------------------------------//
//                       W A T C H D O G   -   P L L                          //
//----------------------------------------------------------------------------//
//-------------  Desshabilita watchdog

void WDT_disable() {
    RCONbits.SWDTEN = 0; /* Disable Watch Dog Timer*/
}

//-------------  Dehabilita watchdog, configura PLL

void configurarSistema() {
    WDT_disable();
    configurarPLL();
    configurarEntradasSalidas();
}

//-------------  Configura PLL

void configurarPLL(void) {
    //    // Configure PLL prescaler, PLL postscaler, PLL divisor
    //    PLLFBD = 15; // M = 20 (PLLFBD + 2)
    //    CLKDIVbits.PLLPRE = 0; // N1 = 2 (PLLPRE + 2)
    //    CLKDIVbits.PLLPOST = 0; // N2 = 2 (PLLPOST + 2)
    //
    //    // Initiate Clock Switch to Primary Oscillator with PLL (NOSC = 0x3)
    //    __builtin_write_OSCCONH(0x03);
    //    __builtin_write_OSCCONL(OSCCON | 0x01);
    //
    //    // Wait for Clock switch to occur
    //    while (OSCCONbits.COSC != 0x3);
    //
    //    // Wait for PLL to lock
    //    while (OSCCONbits.LOCK != 1);

    PLLFBD = PLLFBD_M; // M = PLLFBD_ + 2 = 47
    CLKDIVbits.PLLPOST = PLLPOST_N1; // N1 = PLLPOST_N1 + 2 = 2
    CLKDIVbits.PLLPRE = PLLPRE_N2; // N2 = PLLPRE_N2 + 2 = 2
    /*
        FIN  = FRC = 7,37MHz
        FOSC = FRC * (M/(N1*N2)) = 7,37MHz * (47/4) = 86,5975 MHz
        TOSC = 1/FOSC = 11,5 ns
        FCY  = FOSC / 2 = 43,298 MHz = 43,298 MIPS
        TCY = 1/ FCY = 23 ns    Base de tiempo de los timers
     */
    __builtin_write_OSCCONH(0x01);
    __builtin_write_OSCCONL(0x01);
    //Espera que el cambio de reloj ocurra
    while (OSCCONbits.COSC != 0b001);
    //Espera que se estabilice el PLL
    while (OSCCONbits.LOCK != 1) {
    };

}
//------------------------  Fin Watchdoy y PLL  ------------------------------//

//----------------------------------------------------------------------------//
//               Inicializa PRIORIDAD DE INTERRUPCIONES                       // 
//----------------------------------------------------------------------------// 

void inicializaPrioridadInterrupciones(void) {
    /*  
        INTERRUPT PRIORITY CONTROL LEVEL
            111 = Interrupt is priority 7 (highest priority interrupt)
            110 = Interrupt is priority 6
            101 = Interrupt is priority 5
            100 = Interrupt is priority 4
            011 = Interrupt is priority 3
            010 = Interrupt is priority 2
            001 = Interrupt is priority 1 (lowest priority interrupt)
            000 = Interrupt is priority 0 (Interrupt source is disabled)
     */
    //TIMER 1
    IPC0bits.T1IP = 5; //Timer1 Interrupt priority level

    //UART
    IPC2bits.U1RXIP = 0; //UART Interrupt priority level

    //TIMER 3
    IPC2bits.T3IP = 0; //TIMER 3 y 2 Interrupt priority level

    //QEI
    IPC14bits.QEIIP = 0; //QEI Interrupt Priority bits

    //INT3
    IPC13bits.INT3IP = 0; //INT3 Interrupt Priority bits

    //INT4
    IPC13bits.INT4IP = 0; //INT4 Interrupt Priority bits

    //SPI
    IPC2bits.SPI1IP = 7; //SPI Interrupt Priority bits
}
//--------------  Fin Inicializacion Prioridad de Interrupciones  ------------//    

//----------------------------------------------------------------------------//
//                           Inicializa ADC                                   // 
//----------------------------------------------------------------------------// 

void inicializaADC(void) {
    //    AD1CON1bits.ADON = 0; // Apagado del modulo A/D
    //    AD1PCFGH = 0xFFF0; //RC1=AN16(6)/RC2=AN17(7)/RC3=AN18(8)/RC4=AN19(9)) como entradas analogicas
    //    AD1CON1 = 0x00E0;
    //    AD1CSSL = 0x0030; // Include All Analog Channels in Scanning
    //    AD1CON2bits.VCFG = 0; // Voltaje de referncia = AVdd - AVss
    //    AD1CON3 = 0x0F00;
    //    AD1CON2 = 0x0430;
    //    AD1CON1bits.FORM = 0; // Formato de dato = Entero sin signo
    //    AD1CON2bits.BUFM = 0; // Buffer dividido en 2 registros
    //    AD1CON2bits.SMPI = 0; // Interrupcion por cada 1 conversion realizada
    //
    //    IFS0bits.AD1IF = 0; // Limpia bandera del A/D
    //    IEC0bits.AD1IE = 0; // Habilita interrupcion del A/D
    //    IPC3bits.AD1IP = 5; // Prioridad 5 de la interrupcion
    //
    //    AD1CON1bits.ADON = 1; // Encendido del modulo A/D


    AD1CON1 = 0x0000;
    AD1PCFGH = 0xFFF0; //RC1=AN16(6)/RC2=AN17(7)/RC3=AN18(8)/RC4=AN19(9))
    AD1CHS0 = 0x0010;
    AD1CSSL = 0;
    AD1CON3 = 0x0002; //TAD=INTERNAL 2*Tcy
    AD1CON2 = 0;
    AD1CON1bits.ADON = 1; //Habilita ADC
}
//---------------------------  Fin Inicializa ADC  ---------------------------//

//----------------------------------------------------------------------------//
//                              Inicializa UART                               // 
//----------------------------------------------------------------------------//

void inicializaUART(int BRGVAL) {

    /*
    U1MODEbits.STSEL = 0;           //Stop Bit: 0=1 Stot bit - 1=2 stop bits
    U1MODEbits.PDSEL = 0;           //Parity Bits: 00=8 bit data, No Parity
    U1MODEbits.ABAUD = 0;           //Auto-Baud
    U1MODEbits.BRGH = 0;            //Standard Speed Mode
    U1BRG = BRGVAL;                 //Set Baud Rate
    U1STAbits.UTXISEL0 = 0;         //Interrupcion despues de TX un caracter
    U1STAbits.UTXISEL1 = 0;
    IEC0bits.U1TXIE = 1;            //Habilita Interrupcion de TX
    IFS0bits.U1RXIF = 0;            //Reset RX Inerrupt Flag
    //IPC2bits.U1RXIP = 2;            //Set priority
    U1STAbits.URXISEL = 0;          //Interrumpe despues de recibir un caracter   *
    U1STAbits.UTXEN = 1;            //Habilita UART para TX
    IEC0bits.U1RXIE = 1;          //Habilita UART para RX                         *
    U1STAbits.URXISEL = 0;      // Interrupt after one RX character is received;
    U1MODEbits.UARTEN = 1;          //Habilita UART
     */

    //    /*DMA UART TX-RX */
    //    U1MODEbits.STSEL = 0; // 1-stop bit
    //    U1MODEbits.PDSEL = 0; // No Parity, 8-data bits
    //    U1MODEbits.ABAUD = 0; // Autobaud Disabled
    //
    //    U1BRG = BRGVAL; // BAUD Rate Setting for 115200
    //
    //    U1STAbits.UTXISEL0 = 0; // Interrupt after one Tx character is transmitted
    //    U1STAbits.UTXISEL1 = 0;
    //
    //    U1STAbits.URXISEL = 0; // Interrupt after one RX character is received
    //    IEC0bits.U1RXIE = 0; //Habilita UART para RX agregue
    //    IFS0bits.U1RXIF = 0; //Reset RX Inerrupt Flag agregue
    //    U1MODEbits.UARTEN = 0; // Enable UART
    //    U1STAbits.UTXEN = 0; // Enable UART Tx
}
//-----------------------  Fin inicializa UART  ------------------------------//

//----------------------------------------------------------------------------//
//                              Inicializa DMA 
// 
//----------------------------------------------------------------------------//

void inicializaDMA() {
    extern unsigned int BufferA[TAM_DMA] __attribute__((space(dma)));

    //    /*CONFIGURACION DMA  */
    DMA0CON = 0x2001; // One-Shot, Post-Increment, RAM-to-Peripheral
    DMA0CNT = (TAM_DMA - 1); //CNT=7 PARA  8 DMA requests
    DMA0REQ = 0x000C; // Select UART1 Transmitter
    DMA0PAD = (volatile unsigned int) &U1TXREG;
    DMA0STA = __builtin_dmaoffset(BufferA);
    IFS0bits.DMA0IF = 0; // Clear DMA Interrupt Flag
    IEC0bits.DMA0IE = 0; // Enable DMA interrupt


}
//-----------------------  Fin inicializa DMA  ------------------------------//

/* INTERRUPCION DMA */
//void __attribute__((__interrupt__, no_auto_psv)) _DMA0Interrupt(void) {
//    IFS0bits.DMA0IF = 0; // Clear the DMA0 Interrupt Flag;
//}

//-----------------------  Fin interrupcion DMA  ------------------------------//






//----------------------------------------------------------------------------//
//                         Inicializa SPI SLAVE                               // 

/*
To set up the SPI module for the Slave mode of operation:
1. Clear the SPIxBUF register.
2. If using interrupts:
    a) Clear the SPIxIF bit in the respective IFSn register.
    b) Set the SPIxIE bit in the respective IECn register.
    c) Write the SPIxIP bits in the respective IPCn register to set the interrupt priority.
3. Write the desired settings to the SPIxCON1 and SPIxCON2 registers with MSTEN (SPIxCON1<5>) = 0.
4. Clear the SMP bit.
5. If the CKE bit is set, then the SSEN bit (SPIxCON1<7>) must be set to enable the SSx pin.
6. Clear the SPIROV bit (SPIxSTAT<6>).
7. Enable SPI operation by setting the SPIEN bit (SPIxSTAT<15>).
 */


void inicializaSPI_SLAVE(void) {
    //    // Configura los pines SPI
    //    TRISFbits.TRISF6 = 1; // SCK como entrada
    //    TRISFbits.TRISF7 = 1; // SDI como entrada
    //    TRISFbits.TRISF8 = 0; // SDO como salida
    //    
    //    // Configuración SPI
    //    SPI1STATbits.SPIEN = 0; // Deshabilitar el módulo SPI
    //    SPI1CON1bits.DISSCK = 0; // Habilitar reloj interno
    //    SPI1CON1bits.DISSDO = 0; // Habilitar pin SDO
    //    SPI1CON1bits.MODE16 = 0; // Comunicación de 8 bits
    //    SPI1CON1bits.SMP = 1; // Datos muestreados en el medio del ciclo de reloj
    //    SPI1CON1bits.CKE = 0; // Transición de datos de baja a alta
    //    SPI1CON1bits.CKP = 0; // Reloj en estado bajo
    //    SPI1CON1bits.SSEN = 0; // Habilitar SS para modo esclavo
    //    SPI1CON1bits.MSTEN = 0; // Modo esclavo
    //    SPI1STATbits.SPIEN = 1; // Habilitar el módulo SPI

    TRISFbits.TRISF6 = 0; // SCK como salida
    TRISFbits.TRISF6 = 1; // SCK como entrada
    TRISFbits.TRISF7 = 1; // SDI como entrada
    TRISFbits.TRISF8 = 0; // SDO como salida
    SPI1STATbits.SPIEN = 0; // Deshabilitar el módulo SPI

    SPI1BUF = 0;

    SPI1STATbits.SPIEN = 0; // Deshabilitar el módulo SPI

    // SPI1CON1 Register Settings
    SPI1CON1bits.DISSCK = 0; // Internal Serial Clock is enabled
    SPI1CON1bits.DISSDO = 0; // SDOx pin is controlled by the module
    SPI1CON1bits.MODE16 = 0; // Communication is word-wide (16 bits)
    SPI1CON1bits.SMP = 0; // Input data is sampled at the middle of data output time.
    SPI1CON1bits.CKE = 1; // ((en 0 andaba)) 1 Serial output data changes on transition from Idle clock state to active clock state
    SPI1CON1bits.CKP = 0; // 1 Idle state for clock is a low level; active state is a high level
    SPI1CON1bits.SSEN = 1; // ((intentar poner en 1 y usar el slave selection)) deshabilitar SS para modo esclavo
    SPI1CON1bits.MSTEN = 0; // Master mode disabled

    // Interrupt Controller Settings
    SPI1CON2bits.FRMEN = 0;

    SPI1STATbits.SPIEN = 1; // Enable SPI module

    IPC2bits.SPI1IP = 6;

    IFS0bits.SPI1IF = 0; // Clear the Interrupt flag
    IEC0bits.SPI1IE = 1; // Enable the interrupt

}


//----------------------  Fin inicializa SPI SLAVE  --------------------------//

//----------------------------------------------------------------------------//
//                           Transmite por SPI                                // 
//----------------------------------------------------------------------------//
/*
void write_SPI(char Dato_TX){
//void write_SPI(unsigned int Dato_TX){    
        
        SPI1BUF;                        //Clear register
        SPI1BUF = Dato_TX;              //Transfer data
        while(SPI1STATbits.SPITBF){}    //Wait for operation to complete    
    }
 */
//----------------------------------------------------------------------------//
//                       Recibe/Transmite por SPI                             // 
//----------------------------------------------------------------------------//
//void _ISRFAST _SPI1Interrupt(void)
//void _ISR _SPI1Interrupt(void){
/*
    unsigned int index = 0;
    //unsigned int spi[20] = {0};
    char spi[20] = {0};
    //bool recibio = 0;
    extern unsigned char wSPI[20];
    
void __attribute__((interrupt,no_auto_psv)) _ISR _SPI1Interrupt(void){
    //unsigned int buffer;
    // BUG WORKAROUND: If SSx is active, then proceed -- otherwise, disregard, reset, and return
    //if (PORTBbits.RB2 == 1) {
        IFS0bits.SPI1IF = 0;            //Clear the interrupt flag
        //IEC0bits.SPI1IE = 0;            //Disable Interrupt
        SPI1STATbits.SPIROV = 0;        //Clear any errors
        //buffer = SPI1BUF;               //Read in SPI1 buffer
       
        if(index <= 3){    

            spi[index] = SPI1BUF;
            
            SPI1BUF = 0;
            SPI1BUF = wSPI[index];              //Transfer data
            while(SPI1STATbits.SPITBF){}    //Wait for operation to complete  
            index++;
        }
        if(index >= 4){
            index = 0;
        }
    return;
    //}
}
 */

//----------------------------------------------------------------------------//
//                           Inicializa QEI                                   // 
//----------------------------------------------------------------------------//
/*
void inicializaQEI(void){
    QEICONbits.QEIM = 0;
    QEICONbits.CNTERR = 0;    // Clear any count errors
    QEICONbits.QEISIDL = 0;   // Continue operation during sleep
    QEICONbits.SWPAB = 0;     // QEA and QEB not swapped
    QEICONbits.PCDOUT = 0;    // Normal I/O pin operation
    QEICONbits.POSRES = 0;    // Index pulse resets position counter
    DFLTCONbits.CEID = 1;     // Count error interrupts disabled
    DFLTCONbits.QEOUT = 1;    // Digital filters output enabled for QEn pins
    DFLTCONbits.QECK = 5;     // 1:64 clock divide for digital filter for QEn
    
    POSCNT = 0;               // Reset position counter
    MAXCNT = 0xFFFF;
    QEICONbits.QEIM0 = 1;      // X4 mode with position counter reset by Index
    QEICONbits.QEIM1 = 1;      // X4 mode with position counter reset by Index
    QEICONbits.QEIM2 = 1;      // X4 mode with position counter reset by Index
        
    //IPC14bits.QEIIP  = 6;               //QEI Interrupt Priority bits - 0=deshabilitada 7=max prioridad
    //IPC14bits.QEIIP0 = 1;             //QEI Interrupt Priority bits
    //IPC14bits.QEIIP1 = 1;             //QEI Interrupt Priority bits
    //IPC14bits.QEIIP2 = 1;             //QEI Interrupt Priority bits
    IEC3bits.QEIIE   = 1;               //QEI Event Interrupt Enable bit
    IFS3bits.QEIIF   = 0;               //QEI Interrupt Flag Enable bit
}
 
 */
//------------------------  Fin inicializa QEI  ------------------------------//

//----------------------------------------------------------------------------//
//                              Inicializa INT3                               // 
//----------------------------------------------------------------------------//
//  RA14 - pin 66

/*
void inicializaINT3(void){
    INTCON2bits.INT3EP = 0;     //Polaridad del flanco - 1-Negativo/0-Positivo
    IEC3bits.INT3IE = 0;        //Interrupcion Habilitada - 1-Habilitada
    //IPC13bits.INT3IP = 7;       //Prioridad - 7-Alta/0-Baja
    IFS3bits.INT3IF = 0;        //Clear INT3 Interrupt Flag
}
 
 */
//------------------------  Fin inicializa INT3  -----------------------------//

//----------------------------------------------------------------------------//
//                              Inicializa INT4                               // 
//----------------------------------------------------------------------------//
//  RA15 - pin 67
/*

    void inicializaINT4(void){
    INTCON2bits.INT4EP = 1;     //Polaridad del flanco - 1-Negativo/0-Positivo
    IEC3bits.INT4IE = 0;        //Interrupcion Habilitada - 1-Habilitada
    //IPC13bits.INT4IP = 7;       //Prioridad - 7-Alta/0-Baja
    IFS3bits.INT4IF = 0;        //Clear INT4 Interrupt Flag
}
 
 */
//------------------------  Fin inicializa INT4  -----------------------------//

//----------------------------------------------------------------------------//
//                           Inicializa PWM                                   // 
//----------------------------------------------------------------------------//
//      PIN  93 - PWM1L (RE0)    PIN 94 - PWM1H(RE1)
//      PIN  98 - PWM2L (RE2)    PIN 99 - PWM2H(RE3)
//      PIN 100 - PWM3L (RE4)    PIN  3 - PWM3H(RE5)
//      PIN   4 - PWM4L (RE6)    PIN  5 - PWM4H(RE7)
//


//extern bool bpolaridad_lazo_1, bpolaridad_lazo_2, bpolaridad_lazo_3;

void PWM_Init(void) {
    PTCONbits.PTOPS = 1; // PWM timer post-scale - Postcaler 1:2
    PTCONbits.PTCKPS = 2; // PWM timer pre-scale _ TCY (prescaler 1:1)
    PTCONbits.PTMOD = 2; // PWM operates in Up-down Mode continuously
    PTMR = 0; // PWM counter value, start at 0

    PTPER = 2200; // PWM Timebase period - frecuencia 10Khz
    //PWMCON1bits.PMOD4 = 1;  // PWM in complimentary mode = 0 - single mode = 1
    //PWMCON1bits.PMOD3 = 0; // bpolaridad_lazo_3;  // PWM in complimentary mode = 0 - single mode = 1
    PWMCON1bits.PMOD2 = 1; //bpolaridad_lazo_2;  // PWM in complimentary mode = 0 - single mode = 1
    PWMCON1bits.PMOD1 = 1; //bpolaridad_lazo_1;  // PWM in complimentary mode = 0 - single mode = 1
    //PWMCON1bits.PEN4H = 1;  // PWM High pin is enabled
    //PWMCON1bits.PEN3H = 1;  // PWM High pin is enabled
    //PWMCON1bits.PEN2H = 1;  // PWM High pin is enabled
    PWMCON1bits.PEN1H = 1; // PWM High pin is enabled
    //PWMCON1bits.PEN4L = 1;  // PWM Low pin enabled (direction control later)
    // PWMCON1bits.PEN3L = 1;  // PWM Low pin enabled (direction control later)
    PWMCON1bits.PEN2L = 1; // PWM Low pin enabled (direction control later)
    PWMCON1bits.PEN1L = 1; // PWM Low pin enabled (direction control later)

    //OVDCON = 0x00ff;

    //PWMCON2 = 0x0000;       // PWM update info

    DTCON1bits.DTAPS = 0; //DeadTime pre-scaler
    DTCON1bits.DTA = 59; //DeadTime value for 4 us. 

    //FLTACON = 0x0000;       // Fault A Control

    //OVDCON = 0x0000;        // Override control info

    // Duty Cycle has a max value of 2xPeriod since output can change on rising or falling edge of Tcy
    PDC1 = 1200; // PWM#1 Duty Cycle register (11-bit) - 50% PERIODO T=2MS
    PDC2 = 1200; // PWM#2 Duty Cycle register (11-bit)
    // PDC3 = 2200;            // PWM#3 Duty Cycle register (11-bit)
    //PDC4 = 2200;            // PWM#3 Duty Cycle register (11-bit)

    PTCONbits.PTEN = 1; // Enable PWM Timerbase!
}



