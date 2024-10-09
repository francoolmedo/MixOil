#ifndef SPI_FO_H
#define SPI_FO_H

#include <xc.h>
#include <stdint.h>

// Definiciones de buffers
#define SPI_BUFFER_SIZE 256

// Buffers y variables globales
extern volatile uint8_t spiTxBuffer[SPI_BUFFER_SIZE];
extern volatile uint8_t spiRxBuffer[SPI_BUFFER_SIZE];
extern volatile uint16_t spiTxIndex;
extern volatile uint16_t spiRxIndex;
extern volatile uint16_t spiTxLength;
extern volatile uint16_t spiRxLength;
extern volatile uint8_t spiRxComplete; // Bandera para indicar la recepción completa
extern volatile uint8_t spiTxComplete; // Bandera para indicar la transmisión completa

// Prototipos de funciones
void SPI_Init(void);
void SPI_SendByte(uint8_t data);
void SPI_SendBytes(uint8_t* data, uint16_t length);
uint8_t SPI_ReceiveByte(void);
void SPI_ReceiveBytes(uint8_t* buffer, uint16_t length);

#endif // SPI_PROPIO_H
