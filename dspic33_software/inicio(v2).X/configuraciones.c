#include "configuraciones.h"
#include "hardware.h"
#include "constantes.h"

/*
_FOSC(FCKSM_CSECMD) //Clock switching is enabled, Fail-Safe Clock Monitor is disabled     
_FOSCSEL(FNOSC_FRC & IESO_ON) //Internal Fast RC (FRC) y  Start up with FRC, then switch
 */

//----------------------------------------------------------------------------//
//                          CONFIGURACION BITS                                //
//----------------------------------------------------------------------------//


// FBS

#pragma config BWRP = WRPROTECT_OFF     // Boot Segment Write Protect (Boot Segment may be written)
#pragma config BSS = NO_FLASH           // Boot Segment Program Flash Code Protection (No Boot program Flash segment)
#pragma config RBS = NO_RAM             // Boot Segment RAM Protection (No Boot RAM)

// FSS
#pragma config SWRP = WRPROTECT_OFF     // Secure Segment Program Write Protect (Secure Segment may be written)
#pragma config SSS = NO_FLASH           // Secure Segment Program Flash Code Protection (No Secure Segment)
#pragma config RSS = NO_RAM             // Secure Segment Data RAM Protection (No Secure RAM)

// FGS
#pragma config GSS = OFF                // General Segment Code Protection (User program memory is not code-protected)
#pragma config GWRP = OFF               // General Code Segment Write Protect (User program memory is not write-protected)

// FOSCSEL
#pragma config FNOSC = FRC              // Oscillator Mode (Internal Fast RC (FRC))
#pragma config IESO = ON                // Two-speed Oscillator Start-Up Enable (Start up with FRC, then switch)

// FOSC
#pragma config POSCMD = NONE            // Primary Oscillator Source (Primary Oscillator Disabled)
#pragma config OSCIOFNC = ON            // OSC2 Pin Function (OSC2 pin has digital I/O function)
#pragma config FCKSM = CSECMD           // Clock Switching and Monitor (Clock switching is enabled, Fail-Safe Clock Monitor is disabled)

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

//-------------------------  Fin Configuracion BITS  -------------------------//

//----------------------------------------------------------------------------//
//                              Configura I/O                                 //
//----------------------------------------------------------------------------//

void configurarEntradasSalidas(void) {
    //Definicion de entradas y salidas
    //*********************  P U E R T O   A  **************************************
    //Entrada = 1, Salida = 0:                 
    TRISA = 0xFF3E; // TRIS_A = 1111  1111  0011  1110

    //*********************  P U E R T O   B  **************************************
    TRISB = 0xFFF8; //Entrada = 1, Salida = 0: TRIS_B = 1111 1111 1111 1000
    /*
        //  Habilitacion pull-up PORTB
        CNPU1 = 0x0000;
        CNPU2 = 0x0000;
  
     */
    //*********************  P U E R T O   C  **************************************    
    TRISC = 0xFFFF; //Entrada = 1, Salida = 0: TRIS_C = 0000 0000 0001 1110

    //*********************  P U E R T O   D  **************************************
    TRISD = 0x0FFF; //Entrada = 1, Salida = 0: TRIS_D = 0000 1111 1111 1111

    //*********************  P U E R T O   E  **************************************
    //**** Configuracion - NORMAL -                                   
    TRISE = 0xFFFF; //Entrada = 1, Salida = 0: TRIS_E = 1111 1111 1111 1111

    //***** Configuracion con - PWM -
    //    TRISE = 0x03F0;		//Entrada = 1, Salida = 0: TRIS_E = 0000 0011 1111 0000

    //*********************  P U E R T O   F  **************************************    
    //  TRISF = 0x0080;		//Entrada = 1, Salida = 0:     TRIS_F = 0000 0000 1000 0000
    //                                                                      | || MASTER SPI
    //    TRISF = 0x00CF;		//Entrada = 1, Salida = 0:     TRIS_F = 0000 0000 1100 0000
    //                                                                      | || SLAVE SPI    

    TRISF = 0xCFCC; //Entrada = 1, Salida = 0:     TRIS_F = 1100 1111 1100 1100
    
    //*********************  P U E R T O   G  **************************************    
    TRISG = 0x0C30; //Entrada = 1, Salida = 0: TRIS_G = 0000 1100 0011 0000

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
//-------------  Deshabilita watchdog
void WDT_disable() {
    RCONbits.SWDTEN = 0; /* Disable Watch Dog Timer*/
}

//-------------  Deshabilita watchdog, configura PLL
void configurarSistema() {
    WDT_disable();
    configurarPLL();
    configurarEntradasSalidas();
}

//-------------  Configura PLL
void configurarPLL(void) {
    PLLFBD = PLLFBD_M; // M = PLLFBD_ + 2 = 47
    CLKDIVbits.PLLPOST = PLLPOST_N1; // N1 = PLLPOST_N1 + 2 = 2
    CLKDIVbits.PLLPRE = PLLPRE_N2; // N2 = PLLPRE_N2 + 2 = 2

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
    IPC0bits.T1IP = 0; //Timer1 Interrupt priority level

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
    IPC2bits.SPI1IP = 0; //SPI Interrupt Priority bits
}
//--------------  Fin Inicializacion Prioridad de Interrupciones  ------------//    


//----------------------------------------------------------------------------//
//                           Inicializa ADC                                   // 
//----------------------------------------------------------------------------// 

void inicializaADC(void) {
    /*
     AD1CON1=0x0000;
     AD1PCFGH = 0xFFF0;          //RC1=AN16(6)/RC2=AN17(7)/RC3=AN18(8)/RC4=AN19(9))
     AD1CON1bits.AD12B =1;      //MODO 12 bits
     AD1CON1bits.SIMSAM = 0;     //Muestro multicanal individualmente
     AD1CON1bits.ASAM = 0;       //Muestreo comienza con SAMP = 1
     AD1CON1bits.SSRC = 0;       //Termina el muestreo e inicia la conversion
     
     AD1CHS0=0x0010;            
     AD1CSSL=0;
     */
    //AD1CON2bits.CHPS =          //Select chanel utilized bits
    /*
   AD1CON2bits.VCFG = 0;       //+Vref=AVdd  -Vref=AVss
   AD1CON2bits.CSCNA = 0;      //Muestreo secuencial deshabilitado
   AD1CON2bits.BUFM = 0;       //Buffer fill mode
   AD1CON2bits.SMPI = 0;       //Despues de la conversion se genera la interrupcion
   AD1CON2bits.ALTS = 0;       //
     */
    /*
        AD1CON3bits.ADCS = 10;      //Conversion Clock
        AD1CON3bits.ADRC = 0;       //Clock ADC tomado del sistema
        AD1CON3=0x0002;            //TAD=INTERNAL 2*Tcy
        AD1CON2=0;
     */
    // AD1CHS0bits.CH0NB = 0;      //
    //AD1CSSHbits.CSS16 = 0;
    /* AD1PCFGL = 0xFFFF;          //TODAS DIGITAL
     AD2PCFGL = 0xFFFF;          //TODAS DIGITAL  
     AD1CON1bits.ADON = 1;       //Habilita ADC
     */
    /* ADC 10 BITS CHO + CHO -VREF */

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

    /*DMA UART TX-RX */
    U1MODEbits.STSEL = 0; // 1-stop bit
    U1MODEbits.PDSEL = 0; // No Parity, 8-data bits
    U1MODEbits.ABAUD = 0; // Autobaud Disabled

    U1BRG = BRGVAL; // BAUD Rate Setting for 115200

    U1STAbits.UTXISEL0 = 0; // Interrupt after one Tx character is transmitted
    U1STAbits.UTXISEL1 = 0;

    U1STAbits.URXISEL = 0; // Interrupt after one RX character is received
    IEC0bits.U1RXIE = 1; //Habilita UART para RX agregue
    IFS0bits.U1RXIF = 0; //Reset RX Inerrupt Flag agregue
    U1MODEbits.UARTEN = 1; // Enable UART
    U1STAbits.UTXEN = 1; // Enable UART Tx
}
//-----------------------  Fin inicializa UART  ------------------------------//


//----------------------------------------------------------------------------//
//                              Inicializa DMA 
// 
//----------------------------------------------------------------------------//

void inicializaDMA() {
    extern unsigned int BufferA[TAM_DMA] __attribute__((space(dma)));

    /*CONFIGURACION DMA  */
    DMA0CON = 0x2001; // One-Shot, Post-Increment, RAM-to-Peripheral
    DMA0CNT = (TAM_DMA - 1); //CNT=7 PARA  8 DMA requests
    DMA0REQ = 0x000C; // Select UART1 Transmitter
    DMA0PAD = (volatile unsigned int) &U1TXREG;
    DMA0STA = __builtin_dmaoffset(BufferA);
    IFS0bits.DMA0IF = 0; // Clear DMA Interrupt Flag
    IEC0bits.DMA0IE = 1; // Enable DMA interrupt

}
//-----------------------  Fin inicializa DMA  ------------------------------//

/* INTERRUPCION DMA */
void __attribute__((__interrupt__, no_auto_psv)) _DMA0Interrupt(void) {
    IFS0bits.DMA0IF = 0; // Clear the DMA0 Interrupt Flag;
}

//-----------------------  Fin interrupcion DMA  ------------------------------//





//----------------------------------------------------------------------------//
//                        Inicializa SPI MASTER                               // 
//----------------------------------------------------------------------------//
/*
 void inicializaSPI_MASTER(void){
//Interrupt Controller Settings
    IFS0bits.SPI1IF = 0;        // Clear the Interrupt flag
    IEC0bits.SPI1IE = 0;        // Disable the interrupt
//SPI1CON1 Register Settings
    SPI1CON1bits.DISSCK = 0;    // Internal serial clock is enabled
    SPI1CON1bits.DISSDO = 0;    // SDOx pin is controlled by the module
    SPI1CON1bits.MODE16 = 0;    // Communication is word-wide (1=16 bits - 0=8 bits)
    SPI1CON1bits.SSEN = 0;      // 0 = No CS
    SPI1CON1bits.MSTEN = 1;     // Master mode enabled (1=MASTER)
    SPI1CON1bits.SMP = 0;       // Input data is sampled at the middle of data output time
    SPI1CON1bits.CKE = 0;       // Serial output data changes on transition from Idle clock state to active clock state
    SPI1CON1bits.CKP = 0;       // Idle state for clock is a low level active state is a high level
    SPI1CON1bits.SPRE = 5;      // Frecuencia de clock
    SPI1CON1bits.PPRE = 1;      // 909 Khz
//SPI1STAT Register Settings    
    SPI1STATbits.SPIEN = 1;     // Enable SPI module
    SPI1STATbits.SPIROV = 0;
    SPI1STATbits.SPISIDL = 1;
//IPC2 prioridad interrupciones    
    //IPC2bits.PSPI1IP = 5;       // INTERRUPT PRIORITY CONTROL REGISTER
//Interrupt Controller Settings
    IFS0bits.SPI1IF = 0;        // Clear the Interrupt flag
    IEC0bits.SPI1IE = 1;        // Enable the interrupt
  
}
 
  
 */
//---------------------  Fin inicializa SPI MASTER  --------------------------//    


//----------------------------------------------------------------------------//
//                         Inicializa SPI SLAVE                               // 
//
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

/*
void inicializaSPI_SLAVE(void){
    SPI1BUF = 0;
    IFS0bits.SPI1IF = 0;        // Clear the Interrupt flag
    IEC0bits.SPI1IE = 0;        // Disable the interrupt
    // SPI1CON1 Register Settings
    SPI1CON1bits.DISSCK = 0;    // Internal Serial Clock is enabled
    SPI1CON1bits.DISSDO = 0;    // SDOx pin is controlled by the module
    SPI1CON1bits.MODE16 = 0;    // Communication is word-wide (1=16 bits - 0=8 bits)
    SPI1CON1bits.SSEN = 0;      // 0 = No CS
    SPI1CON1bits.SMP = 0;       // Input data is sampled at the middle of data 
                                // output time.
    SPI1CON1bits.CKE = 1;       // Serial output data changes on transition 
                                // from Idle clock state to active clock state
    SPI1CON1bits.CKP = 0;       // Idle state for clock is a low level; active 
                                // state is a high level
    SPI1CON1bits.MSTEN = 0;     // Master mode disabled (0=SLAVE)
    SPI1STATbits.SPIROV=0;      // No Receive Overflow has occurred
    SPI1STATbits.SPIEN = 1;     // Enable SPI module
    //IPC2 prioridad interrupciones    
    //IPC2bits.PSPI1IP = 5;       // INTERRUPT PRIORITY CONTROL REGISTER
    // Interrupt Controller Settings
    IFS0bits.SPI1IF = 0;        // Clear the Interrupt flag
    IEC0bits.SPI1IE = 1;        // Enable the interrupt
} 
 
 */
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

/*
void PWM_Init( void ){
    PTCONbits.PTOPS = 1;    // PWM timer post-scale - Postcaler 1:2
    PTCONbits.PTCKPS = 0;   // PWM timer pre-scale _ TCY (prescaler 1:1)
    PTCONbits.PTMOD = 2;    // PWM operates in Up-down Mode continuously
 
    PTMR = 0;               // PWM counter value, start at 0
 
    PTPER = 2200;           // PWM Timebase period - frecuencia 10Khz
    
    //PWMCON1bits.PMOD4 = 1;  // PWM in complimentary mode = 0 - single mode = 1
    PWMCON1bits.PMOD3 = bpolaridad_lazo_3;  // PWM in complimentary mode = 0 - single mode = 1
    PWMCON1bits.PMOD2 = bpolaridad_lazo_2;  // PWM in complimentary mode = 0 - single mode = 1
    PWMCON1bits.PMOD1 = bpolaridad_lazo_1;  // PWM in complimentary mode = 0 - single mode = 1
    //PWMCON1bits.PEN4H = 1;  // PWM High pin is enabled
    //PWMCON1bits.PEN3H = 1;  // PWM High pin is enabled
    //PWMCON1bits.PEN2H = 1;  // PWM High pin is enabled
    //PWMCON1bits.PEN1H = 1;  // PWM High pin is enabled
    //PWMCON1bits.PEN4L = 1;  // PWM Low pin enabled (direction control later)
    PWMCON1bits.PEN3L = 1;  // PWM Low pin enabled (direction control later)
    PWMCON1bits.PEN2L = 1;  // PWM Low pin enabled (direction control later)
    PWMCON1bits.PEN1L = 1;  // PWM Low pin enabled (direction control later)
 
    //OVDCON = 0x00ff;
    
    //PWMCON2 = 0x0000;       // PWM update info
 
    DTCON1bits.DTAPS = 0;   //DeadTime pre-scaler
    DTCON1bits.DTA = 59;    //DeadTime value for 4 us. 
 
    //FLTACON = 0x0000;       // Fault A Control
 
    //OVDCON = 0x0000;        // Override control info
 
// Duty Cycle has a max value of 2xPeriod since output can change on rising or falling edge of Tcy
    PDC1 = 2200;            // PWM#1 Duty Cycle register (11-bit) - 50%
    PDC2 = 2200;            // PWM#2 Duty Cycle register (11-bit)
    PDC3 = 2200;            // PWM#3 Duty Cycle register (11-bit)
    //PDC4 = 2200;            // PWM#3 Duty Cycle register (11-bit)
 
    PTCONbits.PTEN = 1;     // Enable PWM Timerbase!
}
  
  
 */