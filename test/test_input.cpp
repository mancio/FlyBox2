#include <Arduino.h>
#include <unity.h>

// total number of joystick buttons (start from 1)
#define bt_num 16

// array with the button state
int bt_conf_array[bt_num];



void bt_config(int selected){
    
    for (int i = 0; i < bt_num; i++){
        if(selected==i) bt_conf_array[i] = HIGH;
        else bt_conf_array[i] = LOW;
                
    }
    
}

/*void test_selectMuxPin(){
    selectMuxPin(0)
}*/