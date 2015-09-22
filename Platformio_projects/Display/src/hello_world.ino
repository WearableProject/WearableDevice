// FlashBand Demo App
// Requires: Core, Pearl
// Optional: Blue, Motion
// Reads accelerometer values and drops blue LEDs to side point down
// Sends accelerometer values over Bluetooth LE
// If Motion not connected, then displays circling ring of Purple LEDs with trail

#include <Display.h>


#define threshold 20
Display display = Display();

void setup()
{
display.setup();
}


void loop()
{
    display.scrollVertically("Hello NigNig", 2);
}
