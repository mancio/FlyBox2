/*
FlyBox2 is a flight simulator game pad for games like X-plane used togheder 
with a joystick 

Copyright (C) 2020  Andrea Mancini

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

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
