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



#ifndef EMULATOR_h
#define EMULATOR_h

#include <Arduino.h>

/**
 * reset the state of the emulated axes to center and buttons to not pressed
 */
void reset_joy_em();

/**
 * reset state of the emulated buttons to 0;
 */
void reset_bt_em();

/**
 * emulate click of button
 * 
 * @param int button to click (from 0 tp 15)
 */
void click_bt_em(int button);

/**
 * set joystick axes in the emulator array
 * 
 * @param int X
 * @param int Y
 * @param int Z
 */
void move_joy_em(int X, int Y, int Z);

/**
 * move emulated axes up and down gradually
 */
void loop_joy_em();

/**
 * set encoders array right and after 360 steps to left
 */
void click_enc_em();

/**
 * read the encoder emulated position from the array
 * 0-2 = directions
 * 3-5 = click buttons
 * 
 * @param int encoder number 
 * 
 * @return encoder position or click state as int
 */
int read_enc(int enc);

/**
 * reset all the encoder buttons to state zero released
 * in the array
 */
void reset_enc_click_em();

/**
 * emulate a click of a button by changing state in the array
 * 
 * @param int encoder button number (between 3 and 5)
 */
void click_enc_em(int bt_en);

/**
 * set encoders to center
 */
void stop_enc();

/**
 * emulate the multiplexer by reading from an array
 * of button states
 * 
 * @param int array position
 */
void mux_channel_em(int ar_pos);

/**
 * read value from array previously set by mux emulator
 * 
 * @return 1 or 0
 */
int digitalRead_em();

/**
 * return the value from emulated X
 * 
 * @return emulated X value (0-1023)
 */
int analogRead_em_X();

/**
 * return the value from emulated Y
 * 
 * @return emulated Y value (0-1023)
 */
int analogRead_em_Y();

/**
 * return the value from emulated Z
 * 
 * @return emulated Z value (0-1023)
 */
int analogRead_em_Z();




#endif