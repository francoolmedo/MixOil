#include "spi_fo.h"

// Inicializaci�n de buffers y variables globales
volatile uint8_t spiTxBuffer[SPI_BUFFER_SIZE];
volatile uint8_t spiRxBuffer[SPI_BUFFER_SIZE];
volatile uint16_t spiTxIndex = 0;
volatile uint16_t spiRxIndex = 0;
volatile uint16_t spiTxLength = 0;
volatile uint16_t spiRxLength = 0;
volatile uint8_t spiRxComplete = 0; // Bandera para indicar la recepci�n completa
volatile uint8_t spiTxComplete = 0; // Bandera para indicar la transmisi�n completa

// Inicializaci�n del SPI

void SPI_Init(void) {
    SPI1STATbits.SPIEN = 0; // Deshabilitar el m�dulo SPI
    SPI1CON1bits.MSTEN = 0; // Configurar como esclavo
    SPI1CON1bits.CKE = 1; // Configurar la fase de reloj
    SPI1CON1bits.SSEN = 1; // Habilitar el pin SS
    SPI1CON1bits.MODE16 = 0; // Modo de 8 bits
    SPI1STATbits.SPIEN = 1; // Habilitar el m�dulo SPI

    // Configurar y habilitar la interrupci�n SPI
    IFS0bits.SPI1IF = 0; // Limpiar la bandera de interrupci�n SPI
    IEC0bits.SPI1IE = 1; // Habilitar la interrupci�n SPI
    IPC2bits.SPI1IP = 4; // Prioridad de la interrupci�n
}

// Manejador de interrupciones SPI

void __attribute__((interrupt, no_auto_psv)) _SPI1Interrupt(void) {
    IFS0bits.SPI1IF = 0; // Limpiar la bandera de interrupci�n SPI

    // Recepci�n de datos
    if (SPI1STATbits.SPIRBF) {
        uint8_t receivedByte = SPI1BUF;
        if (spiRxIndex < spiRxLength) {
            spiRxBuffer[spiRxIndex++] = receivedByte;
            if (spiRxIndex == spiRxLength) {
                spiRxComplete = 1; // Indicar que la recepci�n est� completa
            }
        }
    }

    // Env�o de datos
    if (!SPI1STATbits.SPITBF && spiTxIndex < spiTxLength) {
        SPI1BUF = spiTxBuffer[spiTxIndex++];
        if (spiTxIndex == spiTxLength) {
            spiTxComplete = 1; // Indicar que la transmisi�n est� completa
        }
    }
}

// Funci�n para enviar un byte

void SPI_SendByte(uint8_t data) {
    spiTxBuffer[0] = data;
    spiTxIndex = 0;
    spiTxLength = 1;
    spiTxComplete = 0;
    IFS0bits.SPI1IF = 1; // Forzar interrupci�n para iniciar la transmisi�n
    while (!spiTxComplete); // Esperar a que la transmisi�n est� completa
}

// Funci�n para enviar m�s de un byte

void SPI_SendBytes(uint8_t* data, uint16_t length) {
    for (uint16_t i = 0; i < length; i++) {
        spiTxBuffer[i] = data[i];
    }
    spiTxIndex = 0;
    spiTxLength = length;
    spiTxComplete = 0;
    IFS0bits.SPI1IF = 1; // Forzar interrupci�n para iniciar la transmisi�n
    while (!spiTxComplete); // Esperar a que la transmisi�n est� completa
}

// Funci�n para recibir un byte

uint8_t SPI_ReceiveByte(void) {
    spiRxIndex = 0;
    spiRxLength = 1;
    spiRxComplete = 0;
    while (!spiRxComplete); // Esperar a que la recepci�n est� completa
    return spiRxBuffer[0];
}

// Funci�n para recibir m�s de un byte

void SPI_ReceiveBytes(uint8_t* buffer, uint16_t length) {
    spiRxIndex = 0;
    spiRxLength = length;
    spiRxComplete = 0;
    while (!spiRxComplete); // Esperar a que la recepci�n est� completa
    for (uint16_t i = 0; i < length; i++) {
        buffer[i] = spiRxBuffer[i];
    }
}
