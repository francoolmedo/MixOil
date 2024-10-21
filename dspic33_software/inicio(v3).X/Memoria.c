/*
 * File:   Memoria.c
 * Author: Contraut
 *
 * Created on 15 de febrero de 2017, 11:44
 */

/*

#include "xc.h"
#include "libpic30.h"
#include "Memoria.h"

int parametros[_FLASH_ROW] = {0};
int parametros_leidos[_FLASH_ROW] = {0};
unsigned long address_inicial = 0x21000;
int *param = parametros;

extern int DATO[4];

void grabaflash (){
    int indice = 0;
    
    address_inicial = 0x21000;
    //_memcpy_p2d16(parametros,address_inicial,sizeof(parametros));
    _erase_flash(address_inicial);

    for (indice=0; indice<_FLASH_ROW; indice++){
        parametros[indice] = parametros_leidos[indice];
    }
        
    _write_flash16(address_inicial, parametros);
    
}

void leeflash(){
    
    _memcpy_p2d16(parametros_leidos, address_inicial, sizeof(parametros_leidos));
    
    
}
*/