#include <Arduino.h>
#include <Timer.h>
#include <emulator.h>

// array of axes state
int st_array[3] = {
    511, // X-axis
    511, // Y-axis
    511, // Z-axis
};

// array with button states
int st_bt_array[16] = {
    0, // bt 1
    0, // bt 2
    0, // bt 3
    0, // bt 4
    0, // bt 5
    0, // bt 6
    0, // bt 7
    0, // bt 8
    0, // bt 9
    0, // bt 10
    0, // bt 11
    0, // bt 12
    0, // bt 13
    0, // bt 14
    0, // bt 15
    0  // bt 16
};

// store bt value from array ready for reading for emulation
int bt_em = 0;

// add or subtract value from axes
int sum_X = 1;
int sum_Y = 1;
int sum_Z = 1;

void reset_joy_em(){
    for (size_t i = 0; i < sizeof(st_array)/sizeof(st_array[0]); i++){
        st_array[i] = 511;    
    }
}

void reset_bt_em(){
    for (size_t i = 0; i < sizeof(st_bt_array)/sizeof(st_bt_array[0]); i++){
        st_bt_array[i] = 0;    
    }
}

void click_bt_em(int button){
    st_bt_array[button] = 1;
}

void move_joy_em(int X, int Y, int Z){
    st_array[0] = X;
    st_array[1] = Y;
    st_array[2] = Z; 
}

void loop_joy_em(){
    if(st_array[0] == 0) sum_X = 1;
    else if(st_array[0] == 1023) sum_X = -1;

    if(st_array[1] == 0) sum_Y = 1;
    else if(st_array[1] == 1023) sum_Y = -1;

    if(st_array[2] == 0) sum_Z = 1;
    else if(st_array[2] == 1023) sum_Z = -1;

    st_array[0] = st_array[0]+sum_X;
    st_array[1] = st_array[1]+sum_Y;
    st_array[2] = st_array[2]+sum_Z;

}

void mux_channel_em(int ar_pos){
    bt_em = st_bt_array[ar_pos];
}

int digitalRead_em(){
    return bt_em;   
}

int analogRead_em_X(){
    return st_array[0];
}

int analogRead_em_Y(){
    return st_array[1];
}

int analogRead_em_Z(){
    return st_array[2];
}




