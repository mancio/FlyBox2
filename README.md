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
The hardware approach give the possibility to save some code avoiding a complex function for the pin status. Pin status are read by the same pin using the multiplexer. This would make the pin status storage more difficult.

You can find the board ready to print on [OSHPark](https://oshpark.com/shared_projects/8fIAeRlI)

## Component list

* 1x Arduino pro micro atmega32u4 (native USB port not like Arduino nano)
* 3x 10k slide potentiometers
* 3x rotary encoders 
* 1x CD74HC4067 16-Channel Analog Digital Multiplexers
* 1x MC14490P hardware debouncer
* 1x 10nf capacitor(change capacitor change delay)
* 16X push buttons

## Documentation

[Here](https://github.com/mancio/FlyBox2/tree/master/docs/doxygen) you can find the documentations written in Doxygen 

## TODO

* rewire board to match interrupts with encoder pins
* connect button pad
* test multiplexer
* test not working due to python problem with vs IDE

## Still under construction 
## STAY TUNED!
