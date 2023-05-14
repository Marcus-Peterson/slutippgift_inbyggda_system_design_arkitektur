#include "led.h"
#include <cstdlib>
// En funktion för att kontrollera om en LED är null
bool isLedNull(Led *led)
{
  return led == nullptr;
}

// Skapar globala variabler för att hålla LED-lampornas status
LedState_Type led1_state;
LedState_Type led2_state;
LedState_Type led3_state;

// Skapar en global Led-instans (led1) av färgen RED och sätter dess initiala tillstånd till ON
Led led1(RED, ON);
int main()
{
  // Huvudfunktionen initierar UART, skapar och hanterar LED-lamporna
  USART2_Init();

  // Skapar en lokal Led-instans (led2) av färgen BLUE och initialiserar tillståndet till ON
  Led led2(BLUE, ON);
  // Skapar en dynamiskt allokerad Led-instans (led3) av färgen YELLOW och initaliserar tillståndet till ON
  Led *led3 = new Led(YELLOW, ON);

  if (led3 == nullptr)
  {
    // Om led3 är null, skriv ut ett felmeddelande och returnera
    printf("Error: could not allocate memory for led3\n");
    return 1;
  }
  // Hämtar led1:s tillstånd och sparar det i led1_state
  led1_state = led1.getState();
  // Sätter led1:s tillstånd till OFF
  led1.setState(OFF);
  // Lade till felhantering utifall någon av lamporna inte skulle fungera
  while (1)
  {
    // Kontrollera om någon av LED-objekten är null
    if(isLedNull(&led1) || isLedNull(&led2) || isLedNull(led3))
    {
      printf("Error: a LED object is null\n");
      return 1;
    }
  }

  // Frigör minnet allokerat till led3
  delete led3;
  return 0;
}
