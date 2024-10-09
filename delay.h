/* 
 * File:   delay.h
 * Author: Portatil
 *
 * Created on 12 de abril de 2023, 12:00
 */

#ifndef DELAY_H
#define	DELAY_H

#define Fcy 7370000 //8000000//16000000

void Delay(unsigned int delay_count);
void Delay_Us(unsigned int delayUs_count);
void Delay_10Us(unsigned int delay10Us_count);

#define Delay10uS_count (Fcy * 0.0002) / 1080
#define Delay15uS_count (Fcy * 0.0002) / 750   //1080
#define Delay200uS_count (Fcy * 0.0002) / 1080
#define Delay_1mS_Cnt (Fcy * 0.001) / 2950
#define Delay_2mS_Cnt (Fcy * 0.002) / 2950
#define Delay_5mS_Cnt (Fcy * 0.005) / 2950
#define Delay_15mS_Cnt (Fcy * 0.015) / 2950
#define Delay_100mS_Cnt (Fcy * 0.1) / 2950 
#define Delay_500mS_Cnt (Fcy * 0.5) / 2950 
#define Delay_1S_Cnt (Fcy * 1) / 2950 


#endif	/* DELAY_H */

