/*******************************************************************************
 * File:   interrupts.c
 * Author: Ing. Daniel Petrone
 * Title:  U9_05 - Clasificador de papas
 *
 *          Interrupción Periodica - TIMER 1
 *          Interrupcion Contador cuadratura - QEI
 *          Interrupciones UART - Tx, Rx
 *          Interrupciones externas - INT3, INT4
 * 
 * Created on 15 de febrero de 2017, 18:56
 * 
 ******************************************************************************/

#if defined(__dsPIC33F__)
#include "p33Fxxxx.h"
#elif defined(__PIC24H__)
#endif
#include <stdbool.h>
#include "hardware.h"
#include "delay.h"
#include "p33FJ256MC710.h"

// ********** DEFINICIONES ***********

bool bactualiza1, bactualiza2, bactualiza3, bactualiza4, bactualiza5 = 0;
int int5ms = 0;
int icomunicacion = 0;
int ianchopulso = 0;

//extern bool bEC;
extern bool bciclo;

int iBT = 0;                //Contador Base de Tiempos
#define iTC  1000           //Tiempo de ciclo en ms
#define iAC  7              //Ancho del pulso BT en ms
#define iTF  20             //Tiempo para sacar foto en ms
bool b_BT = 0;              //Base de Tiempos
bool bFU_BT = 0;            //Flanco UP BT
bool bFD_BT = 0;            //Flanco DW BT

bool bBFE1 = 0;             //Barrera
int iTOUT_FU_BFE1 = 0;
int iTOUT_FD_BFE1 = 0;
bool bFU_BFE1 = 0;
bool bFD_BFE1 = 0;
bool bFU_anterior = 0;
bool bFD_anterior = 0;

int iTOUT_FU_C1B = 0;
int iTOUT_FD_C1B = 0;
bool bFU_C1B = 0;
bool bFD_C1B = 0;
bool bFUC1B_anterior = 0;
bool bFDC1B_anterior = 0;
        
int iTOUT_FU_L1 = 0;
int iTOUT_FD_L1 = 0;
bool bFU_L1 = 0;
bool bFD_L1 = 0;
bool bFUL1_anterior = 0;
bool bFDL1_anterior = 0;

//bool xxx = 0;

bool b_CA = 0;
bool b_FU_CA = 0;
bool b_FD_CA = 0;
int iTOUT_FU_CA = 0;
int iTOUT_FD_CA = 0;
bool bFUCA_anterior = 0;
bool bFDCA_anterior = 0;

extern bool barranque_s_H_C1;

unsigned int uicontador_papa = 0;

bool b_M1 = 0;
bool b_PP = 0;
bool b_FOTO = 0;
int iTOUT_TF = 0;
bool b_FU_FOTO = 0;

unsigned int uidwell = 0;
 unsigned int uisetvaldwell;// VA EXTERN 
bool b_fin_dwell = 0;

extern bool bservosOK;

int b_pulso_DF = 0;

//----------------------------
//bool ciclo = 0;
bool STROBE = 0;

//----------------------------
bool bSTROBE = 0;
//bool breset_atraso_STROBE = 0;
int iatraso_STROBE = 0;
bool FU_e_STROBE = 0;
extern bool bselecciono;

//----------------------------

int rndant = 0;

int a = 0;
//----------------------------

// ************   I N T E R R U P C I O N   P E R I O D I C A   ****************
void __attribute__((interrupt, no_auto_psv)) _T1Interrupt(void) {
        
    T1CONbits.TON = 1;      //se inhibe interrupcion
    IFS0bits.T1IF = 0;      //reset flag interrupt
    TMR1 = 0;               //registro timer 1
// Atencion Interrupcion
    int5ms++;
    icomunicacion++;
    
    if (s_HAB_SRV == 0 || uidwell >= uisetvaldwell) uidwell++;         //Temporizacion Dwell
        
//******************************************************************************
// Hilos de ejecucion    
//***** 1    
    if(int5ms == 1){
        //s_LED_ESTADO = 1;
        //STATUS_LED = ~STATUS_LED;
        ianchopulso++;              //Ancho pulso SHOME (Origen Servo))
        bactualiza1 = 1;
    }
//***** 2
    if(int5ms == 2){
        bactualiza2 = 1;
    }
//***** 3    
     if(int5ms == 3){
        bactualiza3 = 1;
    }
//***** 4    
    if(int5ms == 4){
        bactualiza4 = 1;
    }
//***** 5    
    if(int5ms == 5){
        //s_LED_ESTADO = 0;
        bactualiza5 = 1;
        int5ms = 0;
    }
    
//******************************************************************************
    
//*****  INICIO SEPARACION PAPAS  **********************************************    
  
//*****  Generacion Base de Tiempos  *******************************************
    iBT++;                      //Contador Base de Tiempos
    
    if(iBT >= (iTC - iAC) && iBT <= iTC){      //Ancho pulso BT
        b_BT = 1;               //Set pulso base de tiempos
        bFU_BT = 1;             //SET Flanco UP base de tiempos
    }
    if(bFU_BT == 1 && iBT >= (iTC - iAC - 1)){
        bFU_BT = 0;             //RESET Flanco UP base de tiempos
    }
    if(iBT >= iTC){
        b_BT = 0;               //Reset pulso base de tiempos
        iBT = 0;                //Reset contador base de tiempos
        bFD_BT = 1;             //SET Flanco DW base de tiempos
    }
    if(bFD_BT == 1 && iBT >= 1){
        bFD_BT = 0;             //RESET Flanco DW base de tiempos
    }

    //Test Point
    //e_4 = b_BT;

//******************************************************************************
//******************************************************************************
//******************************************************************************   
    //if(bEC == 0){
    if(bciclo == 0){    
        s_C1B = 0;
        
        bFU_BFE1 = 0;
        bFD_BFE1 = 0;
        
        bFU_L1 = 0;
        bFD_L1 = 0;
        iTOUT_FU_L1 = 0;
        iTOUT_FD_L1 = 0;
        bFUL1_anterior = 1;
        bFDL1_anterior = 0;
        
        bFU_C1B = 0;
        bFD_C1B = 0;
    }
  
    //if(bEC == 1){      //Se dan las condiciones para que inicie la clasificacion
    if(bciclo == 1){      //Se dan las condiciones para que inicie la clasificacion    

//******************************************************************************
//
//      INICIO - Comando cintas y generacion señal sacar foto    
//    
//*****  Deteccion Barrera  ****************************************************    
        bBFE1 = e_BFE1;                     //Barrera         1 = Detecta

    //Detecta Flanco UP barrera
        if(bBFE1 == 1 && bFD_anterior == 1){
            iTOUT_FU_BFE1++;                //Contador timout flanco UP
        }
        if(bBFE1 == 1 && iTOUT_FU_BFE1 >= 3){
            bFU_BFE1 =  1;                  //SET Flanco UP Barrera
        }
        if(bFU_BFE1 == 1 && iTOUT_FU_BFE1 >= 6){
            bFU_BFE1 = 0;                   //RESET Flanco UP Barrera
            iTOUT_FU_BFE1 = 0;              //Inicializa contador timout flanco DW
            bFU_anterior = 1;
            bFD_anterior = 0;
        }

    //Detecta Flanco DW barrera
        if(bBFE1 == 0 && bFU_anterior == 1){
            iTOUT_FD_BFE1++;                //contador timout flanco DW
        }
        if(bBFE1 == 0 && iTOUT_FD_BFE1 >= 3){
            bFD_BFE1 =  1;                  //SET Flanco DW Barrera
        }
        if(bFD_BFE1 == 1 && iTOUT_FD_BFE1 >= 6){
            bFD_BFE1 = 0;                   //RESET Flanco DW Barrera
            iTOUT_FD_BFE1 = 0;              //Inicializa contador timout flanco UP
            bFU_anterior = 0;
            bFD_anterior = 1;
        }
    
//******************************************************************************
//    
//      INICIO - Comando Cinta Plana   --    C1B    --  ESPACIADO
//    
//******************************************************************************        
        
        //ST2 = b_BT;
        if (b_BT == 1){                 //Arranca con BT = 1
            s_C1B = 1;
        }

        if (bFU_L1 == 1){               //Para con L1 = 
        //if (e_L1 == 1){               //Para con L1 = 
            s_C1B = 0;
        }

    //Detecta Flanco UP e_L1
        if((e_L1 == 1 && bFDL1_anterior == 1) || iTOUT_FU_L1 > 0){
            iTOUT_FU_L1++;                //Contador timout flanco UP
        }
        if(e_L1 == 1 && iTOUT_FU_L1 >= 2 && iTOUT_FU_L1 < 4){
            bFU_L1 = 1;                   //SET Flanco UP
        }
        if(bFU_L1 == 1 && iTOUT_FU_L1 >= 4){
            bFU_L1 = 0;                   //RESET Flanco UP
            iTOUT_FU_L1 = 0;              //Inicializa contador timout flanco DW
            bFUL1_anterior = 1;
            bFDL1_anterior = 0;
        }
    
    //Detecta Flanco DW e_L1
        if(e_L1 == 0 && bFUL1_anterior == 1){
            iTOUT_FD_L1++;                //Contador timout flanco UP
        }
        if(e_L1 == 0 && iTOUT_FD_L1 >= 3 && iTOUT_FD_L1 < 6){
            bFD_L1 =  1;                  //SET Flanco UP
        }
        if(bFD_L1 == 1 && iTOUT_FD_L1 >= 6){
            bFD_L1 = 0;                   //RESET Flanco UP
            iTOUT_FD_L1 = 0;              //Inicializa contador timout flanco DW
            bFUL1_anterior = 0;
            bFDL1_anterior = 1;
        }
        
    //Detecta Flanco UP s_C1B
        if(s_C1B == 1 && bFDC1B_anterior == 1){
            iTOUT_FU_C1B++;                //Contador timout flanco UP
        }
        if(s_C1B == 1 && iTOUT_FU_C1B >= 3){
            bFU_C1B =  1;                  //SET Flanco UP
        }
        if(bFU_C1B == 1 && iTOUT_FU_C1B >= 6){
            bFU_C1B = 0;                   //RESET Flanco UP
            iTOUT_FU_C1B = 0;              //Inicializa contador timout flanco DW
            bFUC1B_anterior = 1;
            bFDC1B_anterior = 0;
        }
    
    //Detecta Flanco DW s_C1B
        if(s_C1B == 0 && bFUC1B_anterior == 1){
            iTOUT_FD_C1B++;                //Contador timout flanco UP
        }
        if(s_C1B == 0 && iTOUT_FD_C1B >= 3){
            bFD_C1B =  1;                  //SET Flanco UP
        }
        if(bFD_C1B == 1 && iTOUT_FD_C1B >= 6){
            bFD_C1B = 0;                   //RESET Flanco UP
            iTOUT_FD_C1B = 0;              //Inicializa contador timout flanco DW
            bFUC1B_anterior = 0;
            bFDC1B_anterior = 1;
        }
    
//******************************************************************************
//    
//      FIN - Comando Cinta Plana   --    C1B    --
//    
//******************************************************************************       

//******************************************************************************
//    
//      INICIO - Comando Cinta en V   --    C1A    --  ENFILADO
//    
//******************************************************************************        

        if (bFU_C1B == 1){          //Arranca con Flanco ascendente de C1B
            s_C1A = 1;
        }
        if (bFU_BFE1 == 1){         //Para con flanco ascendente de BFE1
            s_C1A = 0;
        }

        //ST1 = bBFE1;
        //ST2 = s_C1A;
    
//******************************************************************************
//    
//      FIN - Comando Cinta en V   --    C1A    --
//    
//******************************************************************************       
    
//******************************************************************************
//    
//      INICIO - Comando Sacar Foto   --    DF    --
//    
//******************************************************************************        

        if (bFD_L1 == 1 || b_pulso_DF >= 1){
            b_pulso_DF++;
        }
        
        if(b_pulso_DF >= 1 && b_pulso_DF <= 50){    //Ancho pulso sacar foto
            s_DF = 0;
        }
        if(b_pulso_DF >= 1 && b_pulso_DF <= 60){
            STROBE = 1;
        }
        if(b_pulso_DF >= 61){
            s_DF = 1;
        }
        if (b_pulso_DF >= 100){                     //Ancho pulso STROBE = PTRIG
            STROBE = 0;
            b_pulso_DF = 0;
        }

        //ST1 = s_DF; 
        //ST2 = STROBE;
        
    
//******************************************************************************
//    
//      FIN - Comando Sacar Foto   --    DF    --
//    
//******************************************************************************         

//******************************************************************************
//    
//      INICIO - Seleccion   --    STROBE    --
//    
//******************************************************************************        
        
        if(e_STROBE == 1 && FU_e_STROBE == 0){
            iatraso_STROBE = 0; 
            FU_e_STROBE = 1;
        } 
        
        if(FU_e_STROBE == 1){
    // Set STROBE - Retrasado 4ms y 10 ms de ancho    
            if(iatraso_STROBE >= 5 && iatraso_STROBE <= 14){
                bSTROBE = 1;
            }
    // Reset STROBE
            if((bSTROBE == 1 && iatraso_STROBE > 14) || bselecciono == 1){
                //bSTROBE = 0;
            }        
      
            if(bSTROBE == 0 && iatraso_STROBE > 6){
                FU_e_STROBE = 0;
            }
            iatraso_STROBE++;
        }
        //STATUS_LED = e_STROBE;
        //ST2 = bSTROBE;
        //ST1 = FU_e_STROBE;
                
    
//******************************************************************************
//    
//      FIN - Comando cintas y generacion señal sacar foto
//    
//******************************************************************************    
//******************************************************************************


    
    
//******************************************************************************
//******************************************************************************
//******************************************************************************        
    }  //if (bEC == 1)        Se dieron las condiciones para arrancar
//******************************************************************************    

    // Fin Atencion Interrupcion    
    //TMR1 = 0;
    T1CONbits.TON = 1; //reset Timer 1 interrupt flag
}//_T1Interrupt

//*********  I n t e r r u p c i o n  T r a n s m i c i o n  U A R T  **********
void __attribute__((interrupt,no_auto_psv)) _U1TXInterrupt(void){
    IFS0bits.U1TXIF = 0;        //Clear TX Interrupt Flag
}

//***********  I n t e r r u p c i o n  R e c e p c i o n  U A R T  ************
void __attribute__((interrupt,no_auto_psv)) _U1RXInterrupt(void){
    unsigned char datosEntrada[20];
    int iDatos = 0;
    
    datosEntrada[iDatos] = U1RXREG;     
    iDatos++;
    IFS0bits.U1RXIF = 0;                //Clear RX Interrupt Flag
    if(iDatos == 20){
        iDatos = 0;
    }
}

//******************  I n t e r r u p c i o n    I N T 3  **********************

//  RA14 - pin 66  ************ Flanco UP

void __attribute__((interrupt,auto_psv)) _INT3Interrupt(void){
    IFS3bits.INT3IF = 0;        //Clear INT3 Interrupt Flag
}

//******************  I n t e r r u p c i o n    I N T 4  **********************

//  RA15 - pin 67   ********** Flanco DW

void __attribute__((interrupt,auto_psv)) _INT4Interrupt(void){
    IFS3bits.INT4IF = 0;        //Clear INT4 Interrupt Flag
}
