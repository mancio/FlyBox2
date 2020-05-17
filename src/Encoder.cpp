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

    _last_clk = LOW;
    _current_clk = LOW;

    
}

int Encoder_::direction(long out_t){
    
    // Read the current state of CLK
	_current_clk = digitalRead(_clk);

	// If last and current state of CLK are different, then pulse occurred
	// React to only 1 state change to avoid double count
	
    if (_current_clk != _last_clk  && _current_clk == 1 && !_Timer.expired(out_t)){

        

        // If the DT state is different than the CLK state then
        // the encoder is rotating CCW so decrement
        if (digitalRead(_dt) != _current_clk) {
            // rotate anticlockwise 
            _res = -1;
        } else {
            // rotate clockwise
            _res = 1;
        }

    } else {
      _Timer.update();
      _res = 0;
    }

	// Remember last CLK state
	_last_clk = _current_clk;

    return _res;
}

int Encoder_::click(long deb_time){

    
    // read the state of the switch into a local variable:
    _sw_read = digitalRead(_sw);
  
  
  // check to see if you just pressed the button
  // (i.e. the input went from LOW to HIGH), and you've waited long enough
  // since the last press to ignore any noise:

  // If the switch changed, due to noise or pressing:
  if (_sw_read != _sw_last_state) {
    // update the debouncing timer
    _Timer.update();
  }

  if (_Timer.expired(deb_time)) {
    // whatever the reading is at, it's been there for longer than the debounce
    // delay, so take it as the actual current state:

    // if the button state has changed:
    if (_sw_read != _sw_last_state) {
      _sw_current = _sw_read;
    }
  }
 

  // save the reading. Next time through the loop, it'll be the lastButtonState:
  _sw_last_state = _sw_current;

  return _sw_current;

}