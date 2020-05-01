#include <Arduino.h>
#include <Timer.h>
#include <emulator.h>

// array of button and axes state
int st_array[] = {
    511, // X-axis
    511, // Y-axis
    511, // Z-axis
    1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 // 16 buttons
};

// rn_ax point to element 0 of array (for axes)
int* rn_ax = st_array; 

// rn_ax point to element 0 of array (for axes)
int* rn_bt = st_array;

// initialize timer for button pressing
Timer_ Timer_em_bt;

// initialize the timer for axis
Timer_ Timer_em_ax;

void reset_joy_em(){
    for (size_t i = 0; i < sizeof(st_array)/sizeof(st_array[0]); i++){
        if(i==0 || i==1 || i==2){
            st_array[i] = 511;
        }else{
            st_array[i] = 1;
        }        
    }
    
    
}

int digitalRead_em(unsigned long time){
    if(Timer_em_bt.expired(time)){
        Timer_em_bt.update();

        // reset all the buttons and axes states
        reset_joy_em();

        // change value of buttons randomly 
        *(rn_bt + random(3,21)) = random(2);
        
        //Serial.print("bt_read ");
        Serial.println("d\n",*rn_bt);
        return *rn_bt;
    }
    
    return *rn_bt;
}

int analogRead_em(unsigned long time){
    if(Timer_em_ax.expired(time)){
        Timer_em_ax.update();
        
        
        // change value of pos 0,1,2 (axes) randomly 
        *(rn_ax + random(3)) = random(1024);

        //Serial.print("ax_read ");
        //Serial.println(rn_ax); 
        return *rn_ax;   
    }
    //Serial.println("not expired");
    
    return *rn_ax;
}




