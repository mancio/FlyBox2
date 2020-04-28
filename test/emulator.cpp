#include <Arduino.h>
#include <Timer.h>



// random button pressed
int rn_bt = 0;
// random axis position
int rn_ax = 0;

// initialize timer for button pressing
Timer_ Timer_em_bt;

// initialize the timer for axis
Timer_ Timer_em_ax;

int digitalRead_em(unsigned long time){
    if(Timer_em_bt.expired(time)){
        Timer_em_bt.update();
        rn_bt = random(0,1);
        return rn_bt;
    }
    return rn_bt;
}

int analogRead_em(unsigned long time){
    if(Timer_em_ax.expired(time)){
        Timer_em_bt.update();
        rn_ax = random(0,1023); 
        return rn_ax;   
    }
    return rn_ax;
}


