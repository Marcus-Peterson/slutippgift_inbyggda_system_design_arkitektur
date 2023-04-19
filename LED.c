#include "LED.h"

void Led_ctor(Led_Type * const me, LedColor_Type _color, LedState_Type _state){

  me->color = _color;
  me->state = _state;
  
}

void Led_setState(Led_Type * const me, LedState_Type _state){
  me->state = _state;
  
  printf("Den %d LED-lampan är satt till %d \n\r",me->color,me->state);
}
