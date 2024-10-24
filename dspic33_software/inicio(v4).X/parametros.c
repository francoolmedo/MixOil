/*
 * File:   parametros.c
 * Author: Ing. Daniel Petrone
 *
 * Created on 15 de febrero de 2017, 10:54
 */

#include "p33Fxxxx.h"
#include <xc.h>
#include <stdint.h>            //Includes uint16_t definition                    
#include <stdbool.h>           //Includes true/false definition                  
#include "configuraciones.h"   //System funct/params, like osc/peripheral config 
#include "timer.h"
#include "hardware.h"
#include "delay.h"
#include "p33FJ256MC710.h"
#include "libpic30.h"
#include "xc.h"
#include "constantes.h"

//Polaridad Lazo 1
//PWMCON1bits.PMOD1 = 1;  // PWM in complimentary mode = 0 - single mode = 1
    bool bpolaridad_lazo_1 = 0;

//Polaridad Lazo 2
//PWMCON1bits.PMOD2 = 1;  // PWM in complimentary mode = 0 - single mode = 1
    bool bpolaridad_lazo_2 = 0;

//Polaridad Lazo 3
//PWMCON1bits.PMOD3 = 1;  // PWM in complimentary mode = 0 - single mode = 1
    bool bpolaridad_lazo_3 = 0;
    
//Paso tornillo Lazo 1
    int ipaso_1 = 10;             //paso tornillo en [mm]

//Pulsos por vuelta sistema de captacion Lazo 1
    int ippv_1 = 2500;            //pulsos por vuelta encoder

//Numerador relacion acople motor/tornillo Lazo 1
    int inumerador_1 = 1;         //polea motor

//Denominador relacion acople motor/tornillo Lazo 1
    int idenominador_1 = 1;       //polea tornillo
    
//Ganancia Proporcional
    unsigned int uiKp_1 = 100;
    
    
    