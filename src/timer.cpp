#include <Arduino.h>
#include <Timer.h>

Timer_::Timer_(){
    
}

void Timer_::tUpdate(){
    _last = millis()-_last;
}

void Timer_::reset(){
    _last = 0;    
}

bool Timer_::expired(unsigned long t){
    if(millis()-_last>t) return true;
    return false;
}
