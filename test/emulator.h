#ifndef EMULATOR_h
#define EMULATOR_h

#include <Arduino.h>


/**
 * emulate push button
 * pull up one single button and set down all the others
 * 
 * @param int button selected
 */
void bt_config(int selected);

/**
 * emulate axes positions
 * 
 * @param int16_t X-axis pos
 * @param int16_t Y-axis pos
 * @param int16_t Z-axis pos
 */
void ax_config(int16_t x, int16_t y, int16_t z);


#endif