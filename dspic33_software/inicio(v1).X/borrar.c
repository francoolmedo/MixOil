#include "configuraciones.h"

void borrar_sk(void){
            cargar_DMA_A("A=0000000000000000000000000000000000000000000000000000000000e0e0\n");//BORRAR SK
            enviar_DMA();
            return;
}


void borrar_z31(void){
cargar_DMA_A("A=00000000000000000000000000000000000000000220000000000000000022\n");
enviar_DMA();
     return;
}


void borrar_z32(void){
cargar_DMA_A("A=00000000000000000000000000000000000000000420000000000000000042\n");
enviar_DMA();

    return;
}

void borrar_z33(void){
cargar_DMA_A("A=00000000000000000000000000000000000000000620000000000000000062\n");
enviar_DMA();
    return;
}

void borrar_z34(void){
cargar_DMA_A("A=00000000000000000000000000000000000000000820000000000000000082\n");
enviar_DMA();

    return;
}