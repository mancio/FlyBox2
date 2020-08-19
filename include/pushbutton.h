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
        // previous reading state
        int _last_state;

        int _state;

        Timer_ _Timer;

        String _name;
    public:

        /**
         * to initialize the button. 
         * Is suggested to build an array of Buttons to debonce multiple 
         * buttons.
         */
        Button_();

        /**
         * debounce the pin 
         *  
         * @param long delay time in milliseconds
         * 
         * @return int 1 pressed and 0 released (using pullup configuration)
         */
        int debounce(long delay);

        /**
         * set the pin to be debounced
         * 
         * @param int pin number
         */
        void setPin(int pin);

        void setName(String name);

        String getName();
};







#endif
