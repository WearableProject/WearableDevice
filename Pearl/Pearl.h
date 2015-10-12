#include "Arduino.h"
#include <FastSPI_LED2.h>


class Pearl : public CFastSPI_LED2 {
private:
  int leds;
  CRGB* colours;
public:
  Pearl(int _leds);
  Pearl() : Pearl(6) {};
  void Change(int LED, CRGB colour);
  void ChangeMultiple(int leds[], CRGB colour);
  void off();
  void ChangeAll(CRGB colour);
};
