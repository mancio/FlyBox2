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

#ifndef JOYCONF_h
#define JOYCONF_h

#define NO_REV true
#define REV false


/**
 * debounce the click button (used in addiction with hardware debounce)
 * 
 * @param int button to debounce
 * @return button state debounced
 */
int debouncer(int button);

/**
 * set joystick button state according to pin input
 * 
 * @param int input pin
 * @param int button to be modified
 */
void btset(int pin, int button);

/**
 * map the potentiometer scale to the Arduino analog input scale
 * 
 * @param long input analog value from axis
 * @param bool invert axis if false 
 * 
 * @return mapped value as long
 */
long mapper(long m, bool rev);

/**
 * check and set X-axis input value
 * 
 * @param int pin number
 * @param bool if false reverse the axis
 */
void setX(int pin, bool rev);

/**
 * check and set Y-axis input value
 * 
 * @param int pin number
 * @param bool if false reverse the axis
 */
void setY(int pin, bool rev);

/**
 * check and set Z-axis input value
 * 
 * @param int pin number
 * @param bool if false reverse the axis
 */
void setZ(int pin, bool rev);

/**
 * build an array of buttons in normal order 
 * from 1 to 16
 */
void btArrayFiller();

/**
 * loop the the multiplexer 16 pin connecting each of them to the SIG
 * pin and write the input on the right joystick button.
 */
void muxLooper();

#endif