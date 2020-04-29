#include <Arduino.h>
#include <Timer.h>


Timer_::Timer_(){
    
}

void Timer_::update(){
    _last = millis()-_last;
    //Serial.print("tick");
    //Serial.println(_last);
    
}

void Timer_::reset(){
    _last = 0;    
}

bool Timer_::expired(unsigned long t){
    if(millis()-_last>t) return true;
    return false;
}
