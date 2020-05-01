#ifndef EMULATOR_h
#define EMULATOR_h

#include <Arduino.h>

/**
 * reset the state of the emulated axes to center and buttons to not pressed
 */
void reset_joy_em();

/**
 * reset state of the emulated buttons to 0;
 */
void reset_bt_em();

/**
 * emulate click of button
 * 
 * @param int button to click (from 0 tp 15)
 */
void click_bt_em(int button);

/**
 * set joystick axes in the emulator array
 * 
 * @param int X
 * @param int Y
 * @param int Z
 */
void move_joy_em(int X, int Y, int Z);

/**
 * emulate the multiplexer by reading from an array
 * of button states
 * 
 * @param int array position
 */
void mux_channel_em(int ar_pos);

/**
 * read value from array previously set by mux emulator
 * 
 * @return 1 or 0
 */
int digitalRead_em();

/**
 * return the value from emulated X
 * 
 * @return emulated X value (0-1023)
 */
int analogRead_em_X();

/**
 * return the value from emulated Y
 * 
 * @return emulated Y value (0-1023)
 */
int analogRead_em_Y();

/**
 * return the value from emulated Z
 * 
 * @return emulated Z value (0-1023)
 */
int analogRead_em_Z();

#endif