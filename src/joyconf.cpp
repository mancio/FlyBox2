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

// Joystic configurations definitions and functions


//time in ms (ex 3 sec = 3000)
//#define exp (unsigned long)3000

// total number of joy buttons
#define totbt 16
#include <Arduino.h>
#include <emulator.h>
#include <joyconf.h>
#include <Joystick.h>
#include <CD74HC4067.h>
#include <ports.h>
#include <Timer.h>



// if true enter in test mode
bool test = true;



// configure input pin of the multiplexer logic table
CD74HC4067 my_mux(S0_MUX, S1_MUX, S2_MUX, S3_MUX);


// position of every joystick button from 1 to 16
int joy_bt_array[totbt];

// initialize Timer class to count the time
Timer_ Timer;

unsigned long exp_t = 1000;

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


// the debounce time; increase if the output flickers
unsigned long debounceDelay = 50;    


void joy_conf(){

  // Initialize Joystick Library
  Joystick.begin();

  Joystick.setXAxisRange(-1023, 1023);
  Joystick.setYAxisRange(-1023, 1023);
  Joystick.setZAxisRange(-1023, 1023);
  
 
   
}

int debouncer(int button){

  if(test){
    reading = digitalRead_em(exp_t);  
  }else{
    // read the state of the switch into a local variable:
    reading = digitalRead(button);
  }
  
  // check to see if you just pressed the button
  // (i.e. the input went from LOW to HIGH), and you've waited long enough
  // since the last press to ignore any noise:

  // If the switch changed, due to noise or pressing:
  if (reading != lastButtonState) {
    // update the debouncing timer
    Timer.update();
  }

  if (Timer.expired(debounceDelay)) {
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


void btset(int pin, int button){
    if(debouncer(pin) == HIGH){
        Joystick.setButton(button, HIGH);
    }else{
        Joystick.setButton(button,LOW);    
    }
    
}



long mapper(long m, bool rev){

  if(rev) return map(m, 0, 1023, -1023, 1023);
  else return map(m, 0, 1023, 1023, -1023);
      
}


void setX(int pin, bool rev){
    int an_val;
    if(test) an_val = analogRead_em(exp_t);
    else an_val = analogRead(pin); 
    Joystick.setXAxis(mapper(an_val,rev));
}


void setY(int pin, bool rev){
    int an_val;
    if(test) an_val = analogRead_em(exp_t);
    else an_val = analogRead(pin); 
    Joystick.setYAxis(mapper(an_val,rev));
}


void setZ(int pin, bool rev){
    int an_val;
    if(test) an_val = analogRead_em(exp_t);
    else an_val = analogRead(pin); 
    Joystick.setZAxis(mapper(an_val,rev));
}


void btArrayFiller(){
    for(int i=0; i<totbt;i++){
        joy_bt_array[i] = i;    
    }
}


void muxLooper(){
    for (int i = 0; i < 16; i++) {
        my_mux.channel(i);
        int bt_in = debouncer(SIG_MUX);
        Joystick.setButton(joy_bt_array[i], bt_in);
    }
}