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


void log_ax(long x_p, long y_p, long z_p){
    
    
    Serial.print("Axis X: ");
    Serial.print(x_p);
    Serial.print("    Axis Y: ");
    Serial.print(y_p);
    Serial.print("    Axis Z: ");
    Serial.print(z_p);
    Serial.println("");
}