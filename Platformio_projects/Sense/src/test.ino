//
//   FILE:  dht11_test1.pde
// PURPOSE: DHT11 library test sketch for Arduino
//


#include <Display.h>
#include <Sense.h>

Sense sensor;
Display display;

#define DHT11PIN 4

void setup()
{
  Serial.begin(115200);
  display.setup();

}

void loop()
{

  int chk = sensor.read(DHT11PIN);
  double light = sensor.lightLevel();
  display.show("Read sensor: ");
  switch (chk)
  {
    case DHTLIB_OK:
		display.show("OK");
		break;
    case DHTLIB_ERROR_CHECKSUM:
		display.show("Checksum error");
		break;
    case DHTLIB_ERROR_TIMEOUT:
		display.show("Time out error");
		break;
    default:
		display.show("Unknown error");
		break;
  }
  delay(500);
  display.scrollLeft("Humidity (%): "+String(sensor.humidity), 2);
  delay(500);
  display.scrollLeft("Temperature (°C): "+String(sensor.temperature), 2);
  delay(500);
  display.scrollLeft("Temperature (°F): "+String(sensor.Fahrenheit()+2), 2);
  delay(500);
  display.scrollLeft("Temperature (°K): "+String(sensor.Kelvin()), 2);
  delay(500);
  display.scrollLeft("Dew Point (°C): "+String(sensor.Dewpoint()), 2);
  delay(500);
  display.scrollLeft("Light level: "+String(light), 2);
  delay(2000);
}
//
// END OF FILE
//
