#ifndef EMULATOR_h
#define EMULATOR_h

#include <Arduino.h>

/**
 * reset the state of axes to center and buttons to not pressed
 */
void reset_joy_em();

/**
 * simulate digital read by reading HIGH or LOW randomly
 * 
 * @param unsigned long maxtime one button is keep pressed
 * 
 * @return int can be HIGH or LOW as 1 or 0;
 */
int digitalRead_em(unsigned long time);

/**
 * simulate an analog read form the axis with a value between
 * 0 and 1023
 * 
 * @param time in ms button is pressed
 * 
 * @return a random int value between 0 and 1023
 */
int analogRead_em(unsigned long time);

#endif