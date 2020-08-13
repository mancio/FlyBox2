/*
FlyBox2 is a flight simulator game pad for games like X-plane used together 
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

// total number of joy buttons (from 1 escluded 9 buttons for encoders)
#define totbt 16

#define left_enc1_bt 16
#define right_enc1_bt 17
#define left_enc2_bt 18
#define right_enc2_bt 19
#define left_enc3_bt 20
#define right_enc3_bt 21

#define sw1_bt 22
#define sw2_bt 23
#define sw3_bt 24

#include <Arduino.h>
#include <emulator.h>
#include <joyconf.h>
#include <Joystick.h>
#include <CD74HC4067.h>
#include <ports.h>
#include <Timer.h>
#include <Encoder.h>

Encoder_ Enc1(CLK_ENC_1, DT_ENC_1, SW_ENC_1);
Encoder_ Enc2(CLK_ENC_2, DT_ENC_2, SW_ENC_2);
Encoder_ Enc3(CLK_ENC_3, DT_ENC_3, SW_ENC_3);



// configure input pin of the multiplexer logic table
CD74HC4067 my_mux(S0_MUX, S1_MUX, S2_MUX, S3_MUX);


// position of every joystick button from 1 to 16
int joy_bt_array[totbt];

// initialize Timer class to count the time
Timer_ Timer;

//time pressed after encoder clicked in ms
long t_enc_p = 500;

//unsigned long exp_t = 3000;

// set joystick buttons and axis
Joystick_ Joystick(
  JOYSTICK_DEFAULT_REPORT_ID, // joystick ID 
  JOYSTICK_TYPE_JOYSTICK, // device type
  // buttons counting start from 0
  25, // buttons number (up,right,left,down are 2 axis)
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
int buttonState = LOW; 
// the previous reading from the input pin
int lastButtonState = LOW; 

// read the state of the switch into a local variable
int reading;

// the following variables are unsigned longs because the time, measured in
// milliseconds, will quickly become a bigger number than can be stored in an int.


// the debounce time; increase if the output flickers
unsigned long debounceDelay = 400;    

// store test state if true enter in test mode
bool test = false;

void setTest(bool testin){
  test = testin;
}

void joy_conf(){

  // Initialize Joystick Library
  Joystick.begin();

  Joystick.setXAxisRange(-1023, 1023);
  Joystick.setYAxisRange(-1023, 1023);
  Joystick.setZAxisRange(-1023, 1023);
  
 
   
}

int debouncer(int button){

  if(test){
    reading = digitalRead_em();
    //Serial.print("state: ");
    //Serial.println(reading);
  }else{
    // read the state of the switch into a local variable:
    reading = digitalRead(button);
  }  

  /* debouncing function for multiple buttons is hard to implement.
   * It requires an array where to store the last states to compare to the last
   * input. By using a multiplexer the input of several buttons is provided
   * on the same port. This hardware configuration make the software even more difficult.
   * I should have a timer for every input. The esiest way is a hardware debouncing using 
   * resistors and capacitor or the most advance MC14490P.
   * 
   * An alternative should be the usage of delay, but this function stop the execution
   * and introduce lag in the joystick movements.
   * 
   * For this reason this function is not implemented yet and it return the input read
   * directly from the port.
   */
  
  return reading;
  
}


/*void btset(int pin, int button){
    if(debouncer(pin) == HIGH){
        Joystick.setButton(button, HIGH);
    }else{
        Joystick.setButton(button,LOW);    
    }
    
}*/



long mapper(long m, bool rev){

  if(rev) return map(m, 0, 1023, -1023, 1023);
  else return map(m, 0, 1023, 1023, -1023);
      
}


long setX(int pin, bool rev){
  int an_val;
  if(test) an_val = analogRead_em_X();
  else an_val = analogRead(pin);
  long mapped = mapper(an_val,rev);
  Joystick.setXAxis(mapped);
  return mapped;
}


long setY(int pin, bool rev){
  int an_val;
  if(test) an_val = analogRead_em_Y();
  else an_val = analogRead(pin); 
  long mapped = mapper(an_val,rev);
  Joystick.setYAxis(mapped);
  return mapped;
}


long setZ(int pin, bool rev){
  int an_val;
  if(test) an_val = analogRead_em_Z();
  else an_val = analogRead(pin); 
  long mapped = mapper(an_val,rev);
  Joystick.setZAxis(mapped);
  return mapped;
}


void btArrayFiller(){
  for(int i=0; i<totbt;i++){
      joy_bt_array[i] = i;    
  }
}


void muxLooper(){
  for (int i = 0; i < totbt; i++) {
      if(test) mux_channel_em(i);
      else my_mux.channel(i);
      // in test mode debouncer does not read SIG_MUX
      int bt_in = debouncer(SIG_MUX);
      //Serial.print("bt_in is: ");
      //Serial.println(bt_in);
      Joystick.setButton(joy_bt_array[i], bt_in);
  }
}

void setEncoders_dir(){
  if(test){
     // click buttons according to the encoder directions
    if (read_enc(0) == -1) {
      Joystick.setButton(left_enc1_bt,HIGH);
      //Serial.println("here -1");
    } else if (read_enc(0) == 1) {
      Joystick.setButton(right_enc1_bt,HIGH);
      //Serial.println("here 1");
    } else {
      Joystick.setButton(right_enc1_bt,LOW);
      Joystick.setButton(left_enc1_bt,LOW);
      //Serial.println("here else");
    } 

    if (read_enc(1) == -1) Joystick.setButton(left_enc2_bt,HIGH);
    else if (read_enc(1) == 1) Joystick.setButton(right_enc2_bt,HIGH);
    else {
      Joystick.setButton(right_enc2_bt,LOW);
      Joystick.setButton(left_enc2_bt,LOW);
    }     

    if (read_enc(2) == -1) Joystick.setButton(left_enc3_bt,HIGH);
    else if (read_enc(2) == 1) Joystick.setButton(right_enc3_bt,HIGH);
    else {
      Joystick.setButton(right_enc3_bt,LOW);
      Joystick.setButton(left_enc3_bt,LOW);
    }         

    // check sw button states
    if(read_enc(3) == HIGH) {
      Joystick.setButton(sw1_bt,HIGH);
      //Serial.println("press 3");
    }
    else Joystick.setButton(sw1_bt,LOW);

    if(read_enc(4) == HIGH) {
      Joystick.setButton(sw2_bt,HIGH);
      //Serial.println("press 4");
    }
    else Joystick.setButton(sw2_bt,LOW);

    if(read_enc(5) == HIGH) {
      Joystick.setButton(sw3_bt,HIGH);
      //Serial.println("press 5");
    }
    else Joystick.setButton(sw3_bt,LOW);
  
  } else {
 
    // click buttons according to the encoder directions
    if (Enc1.direction(t_enc_p) == -1) Joystick.setButton(left_enc1_bt,HIGH);
    else if (Enc1.direction(t_enc_p) == 1) Joystick.setButton(right_enc1_bt,HIGH);
    else {
      Joystick.setButton(right_enc1_bt,LOW);
      Joystick.setButton(left_enc1_bt,LOW);
    } 

    if (Enc2.direction(t_enc_p) == -1) Joystick.setButton(left_enc2_bt,HIGH);
    else if (Enc2.direction(t_enc_p) == 1) Joystick.setButton(right_enc2_bt,HIGH);
    else {
      Joystick.setButton(right_enc2_bt,LOW);
      Joystick.setButton(left_enc2_bt,LOW);
    }     

    if (Enc3.direction(t_enc_p) == -1) Joystick.setButton(left_enc3_bt,HIGH);
    else if (Enc3.direction(t_enc_p) == 1) Joystick.setButton(right_enc3_bt,HIGH);
    else {
      Joystick.setButton(right_enc3_bt,LOW);
      Joystick.setButton(left_enc3_bt,LOW);
    }         

    // check sw button states
    if(Enc1.click(debounceDelay) == LOW){
      //Serial.println("click enc1");
      Joystick.setButton(sw1_bt,HIGH);
    } else {
      //Serial.println("release enc1");
      Joystick.setButton(sw1_bt,LOW);
    }

    if(Enc2.click(debounceDelay) == LOW) Joystick.setButton(sw2_bt,HIGH);
    else Joystick.setButton(sw2_bt,LOW);

    if(Enc3.click(debounceDelay) == LOW) Joystick.setButton(sw3_bt,HIGH);
    else Joystick.setButton(sw3_bt,LOW);
  }
}