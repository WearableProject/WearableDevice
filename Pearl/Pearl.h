#include "Arduino.h"
#include <Wire.h>
#include <MMA7660.h>
#include "FastSPI_LED2.h"
#include <SoftwareSerial.h>

class Pearl: public FastLED {
private:
  const int leds = 6;
  int data_pin;
  CRGB colours[leds];
public:
  Pearl();
  void Change(int LED, uint_32 colour);
  void Update();
}
