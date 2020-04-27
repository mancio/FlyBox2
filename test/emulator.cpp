#include <Arduino.h>

// current timestamp
unsigned long t_now;
//last time stamp
unsigned long last = 0;

// random button pressed
int rn = 0;


int digitalRead_em(unsigned long time){
    
    t_now = millis();
    if(t_now-last>time){
        rn = random(0,1);
        return rn;
    }
    
}


