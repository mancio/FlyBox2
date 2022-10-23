# FlyBox2

<p align="center">
<img src="https://github.com/mancio/FlyBox2/blob/master/pictures/747cockpit.JPG" width="700" height="400" />
</p>

An advanced flight control pad made with an atmega32u4 pro micro (leonardo architecture)

This idea is the evolution of the first [FlyBox](https://github.com/mancio/FlyBox) a pad to be used with a joystick to control all the operation with the hand free from the axis flight controls. FlyBox2 bring the basic idea to a new level.
To keep low prices is possible to use two Arduino and a multiplexer to have multiple interrupt pins for encoders and many push button.
The main Arduino will collect signal from the other and will send to the PC using the HID driver. 

## The Arduino Pro Micro
[Full Pinout](https://cdn.sparkfun.com/datasheets/Dev/Arduino/Boards/ProMicro16MHzv1.pdf)

For better performance remember to use interrupt pins for encoder. 

Interrupt pins are 0,1,2,3,7.

## IDE
VS Studio Visual Studio Code 

## Schematics

<p align="center">
<img src="https://github.com/mancio/FlyBox2/blob/master/fritzing/project/main_with_module_bb.jpg" width="850" height="800" />
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

## Installation

* upload the code of Flybox2 to the main arduino
* unplug the usb from this arduino and plug to the second one
* upload the code of the [Flybox2_encoder_module](https://github.com/mancio/FlyBox2_encoder_module) to the second arduino
* unplug usb and plug again to the first one to play

NOTE: DO NOT PLUG TWO USB AT THE SAME TIME. 5V+ AND GND ARE IN COMMON ON BOTH ARDUINO
ALTHOUGH NOTHING BAD SHOULD HAPPEN IS NOT RECOMMENDED TO HAVE TWO POWER SOURCES.

## Clion UPDATE

For people who like Intellj CLion IDE

* install PlatformIO plug in
* search ``Cmake`` in ``Settings`` and click ``+`` button to add ``Debug``, ``leonardo`` and ``Default``
* install python3
* autogenerate ``CmakeList.txt`` if not present
* add PlatformIO configuration on the top dropdown list (build/play section)
* remove build execution from the configuration list of this new configuration
* play the configuration with leonardo selected ``PlatformIO Upload|leonardo``

some links:
* [tutorial](https://docs.platformio.org/en/latest/integration/ide/clion.html)
* [python trick](https://community.platformio.org/t/could-not-find-the-package-with-requirements-for-your-system-windows-amd64/18416)

## Sliding potentiometer UPDATE

Some sim like DCS are more sensible to potentiometer flickering. As you may notice classic hobbyist use 
pot slide and not, due to their cheap building are not keeping constant resistance in some position.
You will see the throttle of your plane vibrate and changing speed.
This problem can be solved by adding a capacitor (same concept as button debouncing) or via software.
Speaking about the software way, I found a [solution online](https://www.norwegiancreations.com/2015/10/tutorial-potentiometers-with-arduino-and-filtering/) that
involve a moving average algorithm. Even though look like very professional, I thought something much 
more simple. my code has a

* pot map function (from Arduino library)
* joystick function top set the axis scale (from Joystick.h)

With the first I can map the slider following the arduino library suggestions and with the second I can choose
how many axis positions the joystick can take (read by the operating system).
If I map a bigger range of int numbers in one smaller I will have multiple numbers in input assigned to the same
number in output. This magically will remove the vibration!.... so much math saved :)

## Altium Design

In Altium design folder you can find the design for
* [FlyBox2 Main Board](https://github.com/mancio/FlyBox2/tree/master/AltiumProject/Flybox2_main_board)
* [16 Push Button Pad](https://github.com/mancio/FlyBox2/tree/master/AltiumProject/ButtonPad)
* [Breakout module for encoders](https://github.com/mancio/FlyBox2/tree/master/AltiumProject/Encoder_Breakout_Module)
* [Breakout module for potentiometer](https://github.com/mancio/FlyBox2/tree/master/AltiumProject/Potentiometer_breakout_module)
* [Debounce signal module](https://github.com/mancio/FlyBox2/tree/master/AltiumProject/MC14490P_module)

Gerbers file are generated by .OutJob file. This file need to be configured in different why depending by the
format accepted by the printer service.
Altium using the job file is able to generate the gerber file in the specified folder. You need just to zip the output in a single file and upload it on your favorite printing web site service.

I tried
* [OSH Park](https://oshpark.com/)
* [Aisler](https://aisler.net/)
* [JLCPCB](https://jlcpcb.com/)

OSH Park unfortunately seem to be the most problematic accepting files. Is possible you need to customize the .zip file.
The others are fine.

Always write directly to the customer service to check if the design is fine before ordering. Every service interpret gerber
files in different ways.

## Box Design

I tried to design the box using cardboard and unfortunately the result wasn't so good. 
I made the template using Adobe Illustrator because is able to manage svg files. [Here](https://github.com/mancio/FlyBox2/tree/master/artdesign) you can find the project.

Looking for a better solution, I made a box using Fusion 360 [here](https://github.com/mancio/FlyBox2/tree/master/artdesign/fusion360). 

Now is the time for printing and if you live in Poland you can look at [this site](https://send3d.eu/). I still have to try them but price are amazing!


## TODO

* video on youtube (to show how much I'm cool 😎)

## What next?

* improve encoder functionality (when it turn fast is recognize as single click)
* refurbish the design using a Teensy (it has multiple interrupt pins and bigger frequency)
* try using a fpga board (push buttons operation and encoding can be hardwired to save CPU)


