#ifndef ENCODER_h
#define ENCODER_h

#include <Arduino.h>
#include <Timer.h>
#include <joyconf.h>

/**
 * The encoder class is used to control a classic multiturn rotary encoder
 * with click button
 * 
 * The encoder is able to sense a left or right turn thanks to two pins
 * connected to on different part of the wheel. The wheel turning pull-up or down 
 * the pins in different order.
 * 
 * The alternate LOW and HIGH state of the pins describes two squared waves 90 degrees
 * out of phase.
 *
 *   ---     ---     ---            ---     ---     ---
 *  |   |   |   |   |   |     A    |   |   |   |   |   |  
 * -     ---     ---     -        -     ---     ---     --
 * ---     ---     ---                ---     ---     ---
 *   |   |   |   |   |       B      |   |   |   |   |   | 
 *    ---     ---     ---        ---     ---    ---  
 *      Turn Left                       Turn right
 *    A 1 1 0 0 1                    A 1 1 1 0 1
 *    B 1 0 0 1 1                    B 0 1 0 0 0
 */
class Encoder_ {
    private:
        // one encoder input 
        int _clk;
        // the other encoder input
        int _dt;
        // click push button
        int _sw;

        // read state of sw
        int _sw_read;
        // current sw state
        int _sw_current; 
        // last sw state
        int _sw_last_state;

        // state encoder pin A
        int _current_clk;
        // last state pin A
        int _last_clk;

        //last saved direction result
        int _res;

        // timer class for debouncing and direction time
        Timer_ _Timer;

    public:
        
        /**
         * to initialize the encoder with input pins and click pin.
         * All af them are digital inputs.
         */
        Encoder_(int clk, int dt, int sw);

        /**
         * give the direction (one step change)
         * 
         * @param how long time give the same output before reset to 0 output 
         * 
         * @return 1 if clockwise (right) or 0 if no changes or -1 if anticlock-wise (left)
         */
        int direction(long out_t);

        /**
         * return the SW push button state. It is debounced to avoid false clicks.
         * 
         * @param long deboucing time
         * 
         * @return int 0 LOW or 1 HIGH clicked.
         */ 
        int click(long deb_time);
};

#endif