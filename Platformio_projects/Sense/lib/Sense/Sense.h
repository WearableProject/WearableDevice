#include <Arduino.h>
#include <dht11.h>

class Sense : public dht11 {
public:
  double Kelvin();
  double Fahrenheit();
  double Dewpoint();
  double lightLevel();
};
