# Motion board library
The motion board - the black one - has an accelerometer and magnetometer on board. This enables you to monitor the orientation of the device.
This library provides the ability to update the X, Y, Z values of the board, fetch each one individually or get all three at once.
## Installation
To install this library, first install the MMA7660 library folder through the IDE, or by copying it into your Arduino libs folder. Then remove this subfolder from this folder, and copy the Motion folder into your Arduino libs folder.
## Examples
Provided is one test sketch which you can find in the examples folder - the Arduino IDE should also pick this up and put it in the file menu. It also uses the display and pearl library to show the data. You can find the install instructions for those in WearableDevice/Display and WearableDevice/Pearl folders, or change the code so that it uses serial or bluetooth depending what you have.
