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
#include <ports.h>
#include <setports.h>
#include <setmicro.h>
#include <joyconf.h>
#include <emulator.h>
#include <logger.h>
#include <Timer.h>

// set test mode
bool t = true;

// log activated
bool l = true;

Timer_ Timer_main;

void setup() {

  setTest(t);  
  setLed();
  joy_conf();
  setEncoders();
  setMux();
  setPot();
}

void loop() {

  /* read input from axes not reversed
   * down = min value
   * up = max value
   */ 
  long x_pos = setX(SL_1, NO_REV);
  long y_pos = setY(SL_2, NO_REV);
  long z_pos = setZ(SL_3, NO_REV);

  // order buttons from 1 to 16
  btArrayFiller();
  // read input form every mux port 
  muxLooper();

  if(t){
    /* reset all buttons to zero and click one
     * every timer time
     */
    if(Timer_main.expired(2000)){
      Timer_main.update();
      reset_bt_em();
      click_bt_em(random(15));
    }     
    // move axis up and down; 
    loop_joy_em();
  }

  if(l){
    // print axes pos to monitor
    log_ax(x_pos, y_pos, z_pos);
  }
  
}

