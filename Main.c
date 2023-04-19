#include "UART.h"

int main(){ //huvudfunktion som kallar på UART-drivrutinen och testar dess funktion
  USART2_Init();
  
  test_setup();
  
  while(1){}
  
}
