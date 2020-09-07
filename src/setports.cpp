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

// set ports and manage multiplexing

#include <Arduino.h>
#include <setports.h>
#include <ports.h>

// keep off for better performance
/*void activeSerial(){
    Serial.begin(9600);
}*/


void setEncoders(){

    // sw is normally HIGH
    pinMode(SW_ENC_1, INPUT);
    pinMode(SW_ENC_2, INPUT);
    pinMode(SW_ENC_3, INPUT);

    pinMode(CLK_ENC_1,INPUT);
    pinMode(CLK_ENC_2,INPUT);
    pinMode(CLK_ENC_3,INPUT);

    pinMode(DT_ENC_1,INPUT);
    pinMode(DT_ENC_2,INPUT);
    pinMode(DT_ENC_3,INPUT);

}


void setPot(){
    pinMode(SL_1,INPUT);
    pinMode(SL_2,INPUT);
    pinMode(SL_3,INPUT);
}


void setMux(){
    pinMode(S0_MUX,OUTPUT);
    pinMode(S1_MUX,OUTPUT);
    pinMode(S2_MUX,OUTPUT);
    pinMode(S2_MUX,OUTPUT);
    pinMode(SIG_MUX,INPUT_PULLUP);
}

