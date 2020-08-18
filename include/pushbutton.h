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

#ifndef PUSHBUTTON_h
#define PUSHBUTTON_h

#include <Arduino.h>
#include <Timer.h>


class Button_ {
    private:
        // pin to debounce
        int _pin;
    public:

        /*
         * to initialize the button. 
         * Is suggested to build an array of Buttons to debonce multiple 
         * buttons.
         */
        Button_(int pin);

        /*
         * debounce the pin 
         */
        int debounce(long delay);
}







#endif
