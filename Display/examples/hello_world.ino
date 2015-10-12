// FlashBand Demo App
// Requires: Core, Pearl
// Optional: Blue, Motion
// Reads accelerometer values and drops blue LEDs to side point down
// Sends accelerometer values over Bluetooth LE
// If Motion not connected, then displays circling ring of Purple LEDs with trail

#include <Display.h>
#include <U8glib.h>


#define threshold 20
Display display = Display();

void setup()
{
display.setup();
}


void loop()
{
  // string to show, speed to move, seconds to run animation
    display.scrollRightContinuous("Hello World", 2, 3);
    // same as above, but no seconds limit. Runs until it hits the end of the screen
    display.scrollRight("Hello World", 2);
    display.scrollLeftContinuous("Hello World", 2, 3);
    display.scrollLeft("Hello World", 2);
    display.scrollHorizontally("Hello World", 2);
    display.scrollHorizontallyContinuous("Hello World", 2, 3);
    display.scrollUpContinuous("Hello World", 2, 3);
    display.scrollUp("Hello World", 2);
    display.scrollDownContinuous("Hello World", 2, 3);
    display.scrollDown("Hello World", 2);
    display.scrollVertically("Hello World", 2);
    display.scrollVerticallyContinuous("Hello World", 2, 3);

    display.show(1);
    display.show(1.5);
    display.show("Wat");
}
