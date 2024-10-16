/* 
 * File:   constantes.h
 * Author: Portatil
 *
 * Created on 1 de junio de 2023, 11:22
 */

#ifndef CONSTANTES_H
#define	CONSTANTES_H

#ifdef	__cplusplus
extern "C" {
#endif

    //********* TAMA�OS DE BUFER ********
#define TAM_DMA  65  //tama�o buffer de la DMA 100 si esta mal colocado reemplaza valores

#define TAM_Rx   110  //tama�o buffer de recepcion rx UART1

#define TAMPAR   30  //tama�o buffer de parametros

#define N_BYTES 30
#define TAM_P_SPI 30
#define TAM_E_SPI 4    
    //********* CONVERSOR A/D  ***********    
#define TAM_CONVERSOR  4  //TAMA�O DE CONVERSION
#define CAN_ANALOG     8   

    //---------------------------------------------
    //********* SE�AL BF **********************
#define TAM_PERIODO 100 //fra debe ser 100
#define BT_OFF 90 //fra debe ser 90

    // Senial habilitacion ServoMotor 50ms
#define TR1 15

#define TAM_PERIODO_TC1 100
#define TC1_OFF 70    

#define TAM_PERIODO_TC2 100
#define TC2_OFF 60    





    //--------------------------------------------

    //******SE�AL PWM1 **********************    
#define TAM_PWM1_PERIODO 100
#define PWM1_OFF 72 



#ifdef	__cplusplus
}
#endif

#endif	/* CONSTANTES_H */

