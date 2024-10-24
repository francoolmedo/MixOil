#include "configuraciones.h"
#include "constantes.h"


 extern bool rx_enviar;
 extern unsigned long int time_rx;
 
void rx_time(){

if(rx_enviar==1){    
    time_rx++;

    if(time_rx == TIME_RX){
       rx_enviar=0;
       time_rx=0;
   }
    
}
return;
}        