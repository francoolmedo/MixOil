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

    //********* TAMAÑOS DE BUFER ********
#define TAM_DMA  80  //tamaño buffer de la DMA 100 si esta mal colocado reemplaza valores

#define TAM_Rx   150  //tamaño buffer de recepcion rx UART1

#define TAMPAR   20   //tamaño buffer de parametros

    //********* CONVERSOR A/D  ***********    
#define TAM_CONVERSOR  4  //TAMAÑO DE CONVERSION
#define CAN_ANALOG     8   


    // ********** PARAMETROS PROMEDIO   ***********
#define NDa  0.6//(0.8F)
#define NDb (1-NDa)
#define TIRa 0.6   
#define TIRb (1-TIRa)    
#define a 0.6
#define b (1-a)


#define CMAX 1023
    //******* tiempos de recepcion **********

    //*********** PARAMETROS TABLA      ***********

    //       NOMBRE   VALOR INICIAL  UNIDADES           DEFINICION             
    /*
    #define  TEXT        300         //C       Temp Max para extraer reactor 
    #define  TVUELCO     120         //C       Temp Max para volcar carbonilla
    #define  TMAXMIX     40          //C       Temp Max inter Deposito MixOPil
    #define  TPIRO1      420         //C       Temperatura de Pirolisis(tram1) 
    #define  TPIRO2      420         //C       Temperatura de Pirolisis(tram2)
    #define  TPIRO3      420         //C       Temperatura de Pirolisis(tram3)
    #define  THMAX       500         //C       HORNO: Umbral alerta sobre temp
    #define  tpir1       0           //Minutos Tiempo de Pirolisis inicio Tramo1 
    #define  tpir2       0           //Minutos Tiempo de Pirolisis inicio Tramo2
    #define  tpir3       200         //Minutos Tiempo de Pirolisis inicio Tramo3
    #define  PIRNom      1200        //mBar    Presion de trabajo interna
    #define  NMAXMIX     2450        //mm      Nivel Maximo MixOil (Deposito)
    #define  NMINMIX     300         //mm      Nivel Minimo MixOil (Deposito)
    #define  BP          50          //C       Banda proporcional
    #define  NT          100         //        Numero defracciones potencia Nom
    #define  d           2           //S       Duracion Encendido Minimo
    #define  TGC         200         //S       Tiempo de gran ciclo- TGC=NT*d
  
     */
    //*********** CONSTANTES DE LA PLANTA ***********
    //       CONSTANTE  VALOR  UNIDADES  DEFINICION               

#define  NR         2      C/u       Numero minimo de reactores
#define  CR         1131   Litros    Capacidad volumetrica de cada reactor
#define  PNOM       0      Kcal/h    Capacidad calorifica del quemador (Pot.Nom)
#define  VC         12000  Litros    Volumen del tanque de condensacion y alm. 





#ifdef	__cplusplus
}
#endif

#endif	/* CONSTANTES_H */

