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

#include <Arduino.h>
#include <Timer.h>


Timer_::Timer_(){
    
}

void Timer_::update(){
    _last = millis();
    //Serial.print("tick");
    //Serial.println(_last);
    
}

void Timer_::reset(){
    _last = 0;   
    //Serial.println("reset"); 
}

bool Timer_::expired(unsigned long t){
    //Serial.println("I'm here!");
    //Serial.println(millis());
    //Serial.println(_last);
    if(millis()-_last>t){
        //Serial.println("expired");
        return true;
    }else {
        //Serial.println("Not expired");
        return false;
    }
}
