#include <Arduino.h>

// current timestamp
unsigned long t_now = 0;


// random button pressed
int rn = 0;


int digitalRead_em(unsigned long time){
    if(millis()-t_now > time){
        rn = random(0,1);
        return rn;
    }
    t_now = millis();
    return rn;
}

int analogRead_em(unsigned long time){
    
}


