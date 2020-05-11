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

/* log activated
 * remember to stop log when using joytick
 * continuos print can disturb joystick functionality
 */
bool l = false;

Timer_ Timer_main;
Timer_ Enc_speed;

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
  // click one button or another depending by the encoder movement
  setEncoders_dir();

  if(t){
    /* reset all buttons to zero and click one
     * every timer time
     */
    if(Timer_main.expired(2000)){
      Timer_main.update();
      reset_bt_em();
      reset_enc_click_em();

      click_bt_em(random(16));
      click_enc_em(random(3,6));
      
    }     
    // move axis up and down; 
    loop_joy_em();

    //encoders
    if(Enc_speed.expired(500)){
      Enc_speed.update();
      click_enc_em();
    }
    stop_enc();
    
  }

  if(l){
    // print axes pos to monitor
    log_ax(x_pos, y_pos, z_pos);
  }
  
}

