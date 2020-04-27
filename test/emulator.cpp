#include <Arduino.h>
#include <Joystick.h>

// set joystick buttons and axis
Joystick_ Joystick_em(
  JOYSTICK_DEFAULT_REPORT_ID, // joystick ID 
  JOYSTICK_TYPE_JOYSTICK, // device type
  16, // buttons number (up,right,left,down are 2 axis)
  0, // hotswitch count
  true, // X axis
  true, // Y axis
  true, // Z axis
  false, // X rotation?
  false, // Y rotation?
  false, // Z rotation?
  false, // rudder
  false, // throttle
  false, // accelerator
  false, // brake
  false // steering
);

// total number of joystick buttons (start from 1)
#define bt_num 16
// total number of joystick axis
#define ax_num 3



void bt_config(int selected){

    for (int i = 0; i < bt_num; i++){
        if(selected==i) Joystick_em.setButton(i,HIGH);
        else Joystick_em.setButton(i,LOW);
    }
}


void ax_config(int16_t x, int16_t y, int16_t z){
    Joystick_em.setXAxis(x);
    Joystick_em.setYAxis(y);
    Joystick_em.setZAxis(z);
}