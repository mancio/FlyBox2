#ifndef EMULATOR_h
#define EMULATOR_h

#include <Arduino.h>

/**
 * randomly press one single button and store the other as 0
 */ 
void bt_conf();

/**
 * simulate digital read by reading HIGH or LOW randomly
 * 
 * @param unsigned long maxtime one button is keep pressed
 * 
 * @return int can be HIGH or LOW as 1 or 0;
 */
int digitalRead_em(unsigned long time);

#endif