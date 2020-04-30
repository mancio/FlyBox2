#ifndef TIMER_h
#define TIMER_h


#include <Arduino.h>

class Timer_ {
    private:
        unsigned long _last = 0; //last timestamp stored
    public:
        Timer_ ();

        /**
         * update the time spent from Arduino boot
         * 
         */
        void update();

        /**
         * reset the timer
         */
        void reset();

        /**
         * check if the time expire 
         * 
         * @param unsigned long limit
         * 
         * @return true if time expired otherwise false
         */
        bool expired(unsigned long t);
};

#endif