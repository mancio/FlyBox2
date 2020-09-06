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

//my lib
#include <Encoders.h>
//#include<Encoder.h>



Encoders_::Encoders_(int clk, int dt, int sw){

  _MyEnc = new Encoder(clk, dt);
  
  _clk = clk;
  _dt = dt;
  _sw = sw;

  _last_enc_pos = -99999;

  _dir = 0;
 

  _sw_last_state = HIGH;

  _sw_read = HIGH;

  _res = HIGH;
  
}



int Encoders_::direction(long out_t){
  
  long newpos = _MyEnc->read();

  //Serial.println(newpos);

  if(_Timer2.expired(out_t)){
    
    if(newpos ==_last_enc_pos) _dir = 0;
    else if(newpos < _last_enc_pos) _dir = -1;
    else _dir = 1; 
    _Timer2.update();
  }

  

  _last_enc_pos = newpos;

  

    
  //Serial.println(_dir);

  return _dir;
}

int Encoders_::ext_direction(long out_t){
  
  if(_Timer3.expired(out_t)){
    int left = digitalRead(_clk);
    //Serial.println(left);
    int right = digitalRead(_dt);
    //Serial.println(right);
    if(left) _dir = -1;
    if(right) _dir = 1;
    else _dir = 0;
    _Timer3.update();
  }

  return _dir;
}

int Encoders_::click(long deb_time){

    
  // read the state of the switch into a local variable:
  // normal open state is HIGH
  _sw_read = digitalRead(_sw);

  /*if(_sw_read) Serial.println("HIGH");
  else Serial.println("LOW");*/
  
  /*save the state before timer check to not stuck on a
  specific state*/
  _sw_last_state = _sw_read;

  //Serial.println(_sw_last_state);

  if(_Timer1.expired(deb_time)){
    _Timer1.update();
    if (!_sw_read){
      return 0;
    } else {
      return 1;
    } 
  }

  
  return _sw_last_state;
}

int Encoders_::lastState(){
  return _res;
}



