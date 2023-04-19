#include "stm32f4xx.h"
#include <stdio.h>

void USART2_Init(void) {

// 1. Enablea klocktillgång för uart2

RCC->APB1ENR |= 0x20000;

// 2. Enablea klocktillgång för portA

RCC->AHB1ENR |= 0x01;

// 3. Enablea pins relaterade till vald port, för alternativ funktion

GPIOA->0x00A0;

// 4. Välja typen av alternativ funktion för de valde pinsen

GPIOA->AFR[0] |= 0x7700;

/* Konstruktion av enhetens kommunikation avslutas */

// Konfiguration utav UART

USART2->BRR = 0x0683;
USART2->CR1 = 0x000C;
USART2->CR2 = 0x000;
USART2->CR3 = 0x000;
USART2->CR1 = 0x2000;

}

// Testfunktion för att testa UART
