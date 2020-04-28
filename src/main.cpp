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



void setup() {
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
  setX(SL_1, NO_REV);
  setY(SL_2, NO_REV);
  setZ(SL_3, NO_REV);

  // order buttons from 1 to 16
  btArrayFiller();
  // read input form every mux port 
  muxLooper();
}

