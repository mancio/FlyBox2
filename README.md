# FlyBox2
An advanced flight control pad made with an atmega32u4 pro micro (leonardo architecture)

This idea is the evolution of the First [FlyBox](https://github.com/mancio/FlyBox) that unfortunately never took flight but is still very good to take an inspiration.

## The Arduino Pro Micro
[Full Pinout](https://cdn.sparkfun.com/datasheets/Dev/Arduino/Boards/ProMicro16MHzv1.pdf)

For better performance remember to use interrupt pins for encoder. 

Interrupt pins are 0,1,2,3,7.

## IDE
VS Studio Visual Studio Code 

## Schematics

<p align="center">
<img src="https://github.com/mancio/FlyBox2/blob/master/fritzing/project/main_wiring.jpg" width="850" height="800" />
</p>

## MC14490P Signal Debounce Module

I build a small module to fit the [MC14490P](https://www.onsemi.com/pub/Collateral/MC14490-D.PDF) a debouncer signal chip. The delay can be changed by changing the cap impedance. Bigger value = bigger delay.
The hardware approach help the software debounce, anyway is just an optional.

You can find the board ready to print on [OSHPark](https://oshpark.com/shared_projects/8fIAeRlI)

## The encoder tragedy 

Unfortunately the Pro Micro has only 5 interrupt (pins: 0,1,2,3,7). If we wire the encoder output pins to not-external interrupt pins of Arduino, the encoder will become very imprecise showing movement in the both directions during one side turn of the knob.
This happen because classic pins can be read every loop, instead an external interrupt is catch immediately, so we can say like is "over the loop".
Every encoder need 2 interrupts so we do not have enough pins available for 3 or more knobs.

To solve this issue I decide to build an additional module to attach to this board: [The FlyBox2_encoder_module](https://github.com/mancio/FlyBox2_encoder_module)

## The CD74HC4067 Multiplexer

The multiplexer give the possibility, as the name say, to have many output from few inputs. This can be done by using a
reading input pin and a function that connect all the multiplexed pin to this input one by one. The switch is done by using a [truth table](https://www.instructables.com/id/Tutorial-74HC4067-16-Channel-Analog-Multiplexer-De/).

One easier solution should be using a button matrix having less pins but in this case I cannot press multiple button at the same 
time.

## Component list

* 1x Arduino pro micro atmega32u4 (native USB port not like Arduino nano)
* 3x 10k slide potentiometers
* 3x rotary encoders 
* 1x CD74HC4067 16-Channel Analog Digital Multiplexers
* 1x MC14490P hardware debouncer
* 1x 10nf capacitor(change capacitor change delay)
* 16X push buttons

## Documentation

[Here](http://mancioboxblog.altervista.org/flybox2Doc/files.html) you can find the documentations written in Doxygen 

## TODO

* connect button pad
* try #define ENCODER_OPTIMIZE_INTERRUPTS to override attachInterrupt() function and using faster assembler routines
* test not working due to python problem with vs IDE

## Still under construction 
## STAY TUNED!
