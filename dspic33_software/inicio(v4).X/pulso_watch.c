#include "configuraciones.h"
#include "hardware.h"

extern unsigned int ticks;
extern unsigned int seg;
extern unsigned int seg_acum;
extern unsigned int min;

void pulso_watchdog(void) {
    ticks++;

    if (ticks == 50)
        ticks = 0;
    
    if (ticks >= 100) { //Tiempo Watchdog 1seg
        STATUS_LED = 0;
        WDD = 0;
    } else {
        WDD = 1;
        STATUS_LED = 1;
    }

    return;
}