/* 
 * File:   configuracion.h
 * Author: Portatil
 *
 * Created on 12 de abril de 2023, 12:00
 */

#ifndef CONFIGURACIONES_H
#define	CONFIGURACIONES_H

#include <xc.h> 
#include <stdbool.h>

#define PLLFBD_M	36		//M = PLLFBD_ + 2 38
#define PLLPOST_N1	0		//N1 = PLLPOST_N1 + 2
#define PLLPRE_N2	0		//N2 = PLLPRE_N2 + 2

#define _ISR __attribute__((interrupt))
#define _ISRFAST __attribute__((interrupt, shadow))

/********************* PROTOTIPOS DE FUNCIONES **********************/

//******************** CONFIGURACION DEL MICRO DSPIC33F***************
void WDT_disable(void);
void configurarEntradasSalidas(void);
void configurarSistema(void);
void configurarPLL(void);

//****************** MANEJO E INICIALIZACION DEL ADC *****************
void inicializaADC(void);
unsigned int convierteAD(int icanal);

//****************** INICIALIZACION DE UART **************************
void inicializaUART(int BRGVAL);


//***************** INICIALIZACION Y CONFIGURACION DE LA DMA  ***************
void inicializaDMA(void); //prototipo de inicializacion DMA0
void enviar_DMA(void); //prototipo de enviar dato de DMA0 a UART1
void cargar_DMA_A(char *); //prototipo cargar datos a DMA0 
void cargar_DMA_C(char *); //prototipo cargar datos a DMA0
//***************** GENERAR FUNCION RAMPA MEDIANTE DAC 0808- 8 BIT 
void RAMPA_Dac(void); //prototipo de funcion para generar rampa


//****************`EEprom 24LC256****************************************** 
void escribir_Eeprom(const unsigned int *, unsigned int, unsigned int);
void leer_Eeprom(unsigned int *, unsigned int, unsigned int);

//------------------------------------------------------------------------
void control_param(void); // CRC DE LOS PARAMETROS 
//--------------------------------------------------------
void parametros(void); // CARGA LOS NUEVOS PARAMETROS EN MEMORIA
//------------------------------------------------------
void generar_A(unsigned long int, unsigned int, unsigned int, unsigned int);
//-----------------------------------------------------
void borrar_sk(void);
//--------------------------------------------------
void borrar_z31(void);
//--------------------------------------------------
void borrar_z32(void);
//--------------------------------------------------
void borrar_z33(void);
//--------------------------------------------------
void borrar_z34(void);
//----------------------------------------------------
void pulso_watchdog(void);
//--------------------------------
void Apq(unsigned int);
//----------------------------------
void Manual(void);
//----------------------------------
void Automatico(void);
//-----------------------------------
void Quemador(void);
//-----------------------
void Precalentador(void);
//-------------------------
void Molino(void);
//----------------------------------
void impresion_quemador_ok(void);
//-----------------------------------
void impresion_Qaviso(void);
//-----------------------------------
void Molino(void);
//---------------------------------
void Precalentador(void);
//---------------------------------
void sonido_2(int tic);
//---------------------------------
void sonido_1(int tic);
//---------------------------------
void tiempo_Q(void);
//---------------------------------
void reset_tiempoQ(void);
//-------------------------------
void reset_tiempoQ(void);
//-------------------------------



void inicializaSPI_MASTER(void);
void inicializaSPI_SLAVE(void);
//void write_SPI(unsigned int Dato_TX);
void write_SPI(char Dato_TX);
void _ISRFAST _SPI1Interrupt(void);

//-------------------------------

void _ISR _T1Interrupt(void);
//-------------------------------
// void inicializaQEI(void);
// float LeerPosicion(void);
// void ControlarOverflows(void);

void inicializaPrioridadInterrupciones(void);

//void transferir_PC(void);

#endif

void __attribute__((interrupt, no_auto_psv)) _T1Interrupt(void);
void __attribute__((__interrupt__, no_auto_psv)) _T2Interrupt(void);
void __attribute__((interrupt, no_auto_psv)) _U1TXInterrupt(void);
void __attribute__((__interrupt__, no_auto_psv)) _DMA0Interrupt(void);