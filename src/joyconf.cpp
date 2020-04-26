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
#include <Joystick.h>


// set joystick buttons and axis
Joystick_ Joystick(
  JOYSTICK_DEFAULT_REPORT_ID, // joystick ID 
  JOYSTICK_TYPE_JOYSTICK, // device type
  16, // buttons number (up,right,left,down are 2 axis)
  0, // hotswitch count
  true, // X axis
  true, // Y axis
  true, // Z axis
  false, // X rotation?
  false, // Y rotation?
  false, // Z rotation?
  false, // rudder
  false, // throttle
  false, // accelerator
  false, // brake
  false // steering
);

// the current reading from the input pin
int buttonState = HIGH; 
// the previous reading from the input pin
int lastButtonState = HIGH; 

// read the state of the switch into a local variable
int reading;

// the following variables are unsigned longs because the time, measured in
// milliseconds, will quickly become a bigger number than can be stored in an int.

// the last time the output pin was toggled
unsigned long lastDebounceTime = 0;  
// the debounce time; increase if the output flickers
unsigned long debounceDelay = 50;    


/**
 * debounce the click button (used in addiction with hardware debounce)
 * 
 * @param int button to debounce
 * @return button state debounced
 */
int debouncer(int button){

  // read the state of the switch into a local variable:
  reading = digitalRead(button);

  // check to see if you just pressed the button
  // (i.e. the input went from LOW to HIGH), and you've waited long enough
  // since the last press to ignore any noise:

  // If the switch changed, due to noise or pressing:
  if (reading != lastButtonState) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    // whatever the reading is at, it's been there for longer than the debounce
    // delay, so take it as the actual current state:

    // if the button state has changed:
    if (reading != buttonState) {
      buttonState = reading;
    }
  }
 

  // save the reading. Next time through the loop, it'll be the lastButtonState:
  lastButtonState = reading;

  return lastButtonState;
  
}

/**
 * set joystick button state according to pin input
 * 
 * @param int input pin
 * @param int button to be modified
 */
void btset(int pin, int button){
    if(debouncer(pin) == HIGH){
        Joystick.setButton(button, HIGH);
    }else{
        Joystick.setButton(button,LOW);    
    }
    
}


/**
 * map the potentiometer scale to the Arduino analog input scale
 * 
 * @param long input analog value from axis
 * @param bool invert axis if false 
 * 
 * @return mapped value as long
 */
long mapper(long m, bool rev){

  if(rev) return map(m, 0, 1023, -1023, 1023);
  else return map(m, 0, 1023, 1023, -1023);
      
}

/**
 * check and set X-axis input value
 * 
 * @param int pin number
 * @param bool if false reverse the axis
 */
void setX(int pin, bool rev){
    Joystick.setXAxis(mapper(pin,rev));
}

/**
 * check and set Y-axis input value
 * 
 * @param int pin number
 * @param bool if false reverse the axis
 */
void setY(int pin, bool rev){
    Joystick.setYAxis(mapper(pin,rev));
}

/**
 * check and set Z-axis input value
 * 
 * @param int pin number
 * @param bool if false reverse the axis
 */
void setZ(int pin, bool rev){
    Joystick.setZAxis(mapper(pin,rev));
}


