/* 
 * File:   variables.h
 * Author: Portatil
 *
 * Created on 6 de julio de 2023, 10:43
 */

#ifndef VARIABLES_H
#define	VARIABLES_H

#elif defined(__XC16__)

#ifdef __CCI__
        __persistent int Parametros ;
    #else
        int Parametros __attribute__((persistent));
    #endif




#endif	/* VARIABLES_H */

