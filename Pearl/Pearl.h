#include "Arduino.h"
#include <Wire.h>
#include <MMA7660.h>
#include <FastSPI_LED2.h>
#include <SoftwareSerial.h>

class Pearl : public CFastSPI_LED2 {
private:
  static const int leds = 6;
  static const int data_pin = 4;
  CRGB colours[leds];
public:
  Pearl();
  void Change(int LED, CRGB colour);
  void ChangeMultiple(int leds[], CRGB colour);
  void Update();
};
