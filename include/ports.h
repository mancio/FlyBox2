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

// port definitions

#ifndef PORTS_h
#define PORTS_h



/*
    9x pin rotary encoders
    3x slide potentiometers
    5x ports multiplexer
*/
#define total_pins 17 

//#define total_buttons 16

// 9x pin rotary encoders
#define SW_ENC_1 9 // click button encoder 1
#define SW_ENC_2 6 // click button encoder 2
#define SW_ENC_3 3 // rx1 click button encoder 3

#define CLK_ENC_1 8 // clock encoder 1
#define CLK_ENC_2 5 // clock encoder 2
#define CLK_ENC_3 2 // clock encoder 3

#define DT_ENC_1 7 // data encoder 1
#define DT_ENC_2 4 // data encoder 2
#define DT_ENC_3 0 // data encoder 3


// 3x slide potentiometers
#define SL_1 A0 // OTB sl pot 1
#define SL_2 A1 // OTB sl pot 2
#define SL_3 A2 // OTB ls pot 3


// 5x ports multiplexer
#define SIG_MUX A3 // multiplexer selected pin reading
#define S0_MUX 10 // S0 port
#define S1_MUX 16 // S1 port
#define S2_MUX 14 // S2 port
#define S3_MUX 15 // S3 port

#endif