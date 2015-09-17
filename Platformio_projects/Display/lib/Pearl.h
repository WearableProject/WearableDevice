#include "Arduino.h"
#include <Wire.h>
#include <MMA7660.h>
#include <FastSPI_LED2.h>
#include <SoftwareSerial.h>

class Pearl : public CFastSPI_LED2 {
private:
  const int data_pin = 4;
  int leds;
  CRGB* colours;
public:
  Pearl(int _leds);
  Pearl() : Pearl(6) {};
  void Change(int LED, CRGB colour);
  void ChangeMultiple(int leds[], CRGB colour);
};
