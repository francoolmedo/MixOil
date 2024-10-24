#ifndef CONFIGURACIONES_H
#define	CONFIGURACIONES_H

#include <xc.h> 
#include <stdbool.h>

//---------------CONSTANTES DE TIEMPO DEL CLOCK
#define PLLFBD_M	36		//M = PLLFBD_ + 2 38
#define PLLPOST_N1	0		//N1 = PLLPOST_N1 + 2
#define PLLPRE_N2	0		//N2 = PLLPRE_N2 + 2

#define _ISR __attribute__((interrupt))
#define _ISRFAST __attribute__((interrupt, shadow))

/********************* PROTOTIPOS DE FUNCIONES **********************/

//---------------CONFIGURACION DEL MICRO DSPIC33F--------------------
void WDT_disable(void);
void configurarEntradasSalidas(void);
void configurarSistema(void);
void configurarPLL(void);
//-------------------------------------------------------------------

//---------------MANEJO E INICIALIZACION DEL ADC---------------------
void inicializaADC(void);
unsigned int convierteAD(int icanal);
//-------------------------------------------------------------------

//---------------INICIALIZACION DE UART------------------------------
void inicializaUART(int BRGVAL);
//-------------------------------------------------------------------

//---------------INICIALIZACION Y CONFIGURACION DE LA DMA------------
void inicializaDMA(void); // Inicializacion DMA0
void enviar_DMA(void); // Enviar dato de DMA0 a UART1
void cargar_DMA_A(char *); // Cargar datos a DMA0 
void cargar_DMA_C(char *); // Cargar datos a DMA0
//-------------------------------------------------------------------

//---------------GENERAR FUNCION RAMPA MEDIANTE DAC 0808- 8 BIT 
void RAMPA_Dac(void); // Funcion para generar Rampa DAC
//-------------------------------------------------------------------

//---------------LECTURA Y ESCRITURA EEPROM 24LC256------------------
void escribir_Eeprom(const unsigned int *, unsigned int, unsigned int);
void leer_Eeprom(unsigned int *, unsigned int, unsigned int);
//-------------------------------------------------------------------

//---------------CRC DE LOS PARAMETROS-------------------------------
void control_param(void);
//---------------CARGA DE NUEVOS PARAMETROS A MEMORIA----------------
void parametros(void);
//---------------GENERA EL MENSAJE DE LA COMUNICACION----------------
void generar_A(unsigned long int, unsigned int, unsigned int, unsigned int);
//---------------GENERA PULSO DE WATCHDOG EXTERNO--------------------
void pulso_watchdog(void);
//---------------GENERA CONSIGNA CODIFICADA PARA DAC DEL QUEMADOR----
void Apq(unsigned int);
//---------------CONTROL DEL MODO MANUAL-----------------------------
void Manual(void);
//---------------CONTROL DEL MODO AUTOMATICO-------------------------
void Automatico(void);
//---------------SUBRUTINA PARA EL QUEMADOR--------------------------
void Quemador(void);
//---------------SUBRUTINA PARA EL PRECALENTADOR---------------------
void Precalentador(void);
//---------------SUBRUTINA PARA EL MOLINO----------------------------
void Molino(void);
//---------------GENERA SONIDO ALARMA LAVADORA-----------------------
void sonido_2(int tic);
//---------------GENERA SONIDO ALARMA INMINENTE----------------------
void sonido_1(int tic);
//---------------CONTROLA TIEMPOS DEL QUEMADOR-----------------------
void tiempo_Q(void);
//---------------CONTROLA TIEMPOS DEL QUEMADOR-----------------------
void reset_tiempoQ(void);
//-------------------------------------------------------------------


//---------------CONTROL DEL SPI-------------------------------------
void inicializaSPI_MASTER(void);
void inicializaSPI_SLAVE(void);
//void write_SPI(unsigned int Dato_TX);
void write_SPI(char Dato_TX);
void _ISRFAST _SPI1Interrupt(void);
//-------------------------------------------------------------------

//---------------FUNCION ESPECIAL DE INTERRUPCION POR TIMER2---------
void _ISR _T1Interrupt(void);
//-------------------------------------------------------------------

//---------------ESTABLECE PRIORIDADES DE INTERRUPCIONES-------------
void inicializaPrioridadInterrupciones(void);
//-------------------------------------------------------------------

// void inicializaQEI(void);
// float LeerPosicion(void);
// void ControlarOverflows(void);
//void transferir_PC(void);
#endif

void __attribute__((interrupt, no_auto_psv)) _T1Interrupt(void);
void __attribute__((__interrupt__, no_auto_psv)) _T2Interrupt(void);
void __attribute__((interrupt, no_auto_psv)) _U1TXInterrupt(void);
void __attribute__((__interrupt__, no_auto_psv)) _DMA0Interrupt(void);