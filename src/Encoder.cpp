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

#include <Encoder.h>

Encoder_::Encoder_(int clk, int dt, int sw){
    _clk = clk;
    _dt = dt;
    _sw = sw;

    _last_clk = HIGH;
    _last_dt = HIGH;

    _current_clk = HIGH;
    _current_dt = HIGH;

    _sw_last_state = HIGH;

    _last_res = 0;

    _ready = 0;
}

int Encoder_::direction(long out_t){

  
    
    // Read the current state of CLK
	_current_clk = digitalRead(_clk);

  _current_dt = digitalRead(_dt);

  /*Serial.print("clk: ");
  Serial.print(_current_clk);
  Serial.print(" dt: ");
  Serial.println(digitalRead(_dt));*/

	// If last and current state of CLK are different, then pulse occurred
	// React to only 1 state change to avoid double count


  if((!_current_clk && _current_dt) ||(_current_clk && !_current_dt)){
    _ready = 1;
  }else if((!_current_clk && !_current_dt) || (_current_clk && _current_dt)){
    _ready = 0;
  }
  
  if(_ready && _Timer2.expired(out_t)){
    if(!_current_clk && _current_dt && _res != 1){
      //Serial.println("fw");
      return _res = 1;
    }else if(_current_clk && !_current_dt && _res != -1){
      //Serial.println("bw");
      return _res = -1;
    }
    _Timer2.update();
  } else {
    return _res = 0;
  }
  
}

int Encoder_::click(long deb_time){

    
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

int Encoder_::lastState(){
  return _res;
}