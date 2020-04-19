#include <Arduino.h>

/**
 The selectMuxPin function sets the S0, S1, and S2 pins
 accordingly, given a pin from 0-7.

 @param pin pin number
 @param pinarray array of pins to control the mux 
 @return -1 if no pin is changed 1 if pin is written
*/
int selectMuxPin(byte pin, int pinarray[]){
  
  if (pin > 7) return -1; // Exit if pin is out of scope
  
  for (int i=0; i<3; i++){
    if (pin & (1<<i))
      digitalWrite(pinarray[i], HIGH);
    else
      digitalWrite(pinarray[i], LOW);
  }

  return 1;

}
