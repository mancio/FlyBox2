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

// array with button states
int st_bt_array[16] = {
    0, //bt 0
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0,
    0
}

// rn_ax point to element 0 of array (for axes)
int* rn_ax = st_array; 

// rn_ax point to element 0 of array (for axes)
int* rn_bt = st_array;

int ran_ax;
int ran_bt;

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

void mux_channel_em(int ar_pos){

}

int digitalRead_em(unsigned long time){
    
    if(Timer_em_bt.expired(time)){
        Timer_em_bt.update();

        // reset all the buttons and axes states
        reset_joy_em();

        
        // change value of buttons randomly 
        ran_bt = random(2);
        *(rn_bt + random(3,21)) = ran_bt;
        
        //Serial.print("bt_read ");
        
        Serial.println(ran_bt);
        return ran_bt;
    }
    
    return ran_bt;
}

int analogRead_em(unsigned long time){
    if(Timer_em_ax.expired(time)){
        Timer_em_ax.update();
        
        
        // change value of pos 0,1,2 (axes) randomly 
        ran_ax = random(1024);
        *(rn_ax + random(3)) = ran_ax;

        //Serial.print("ax_read ");
        //Serial.println(rn_ax); 
        return ran_ax;   
    }
    //Serial.println("not expired");
    
    return ran_ax;
}




