// FlashBand Demo App
// Requires: Core, Pearl
// Optional: Blue, Motion
// Reads accelerometer values and drops blue LEDs to side point down
// Sends accelerometer values over Bluetooth LE
// If Motion not connected, then displays circling ring of Purple LEDs with trail

#include <Pearl.h>


#define threshold 20
int head=0;  // head of moving snake
char buffer[50];
#define tdelay 1000
int x,y,z;
Pearl pearl = Pearl();

void setup()
{
}


void loop()
{
    pearl.Change(head, CRGB(0,100,100));
    pearl.Change((head+5)%6, CRGB(0,50,50));
    pearl.Change((head+4)%6, CRGB(0,25,25));
    pearl.Change((head+3)%6, CRGB(0,10,10));
    pearl.Change((head+2)%6, CRGB(0,5,5));
    pearl.Change((head+1)%6, CRGB(0,0,0));
    pearl.show();
    head = (head+1)%6;
    delay(100);
}
