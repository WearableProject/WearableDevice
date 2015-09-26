# Sense board library
The sense board - the orange one with the big blue box on top - has a temperature, humidity and light level sensor on board.
This library provides access to each sensor value when read, and also provides conversions to Fahrenheit, Kelvin, and a calculation of dewpoint which is worked out from temp and humidity readings.
## Installation
To install this library, first install the DHT11 library folder through the IDE, or by copying it into your arduino libs folder. Then remove this subfolder from this folder, and copy the Sense folder into your arduino libs folder.
## Examples
Provided is one test sketch which you can find in the examples folder - the arduino IDE should also pick this up and put it in the file menu. In addition to the libraries you already installed, it uses the Display board to show data. You may modify the sketch if you don't have this board or library and use software serial, or pearl or bluetooth, or you can find the display library in the main WearableDevices repo.
