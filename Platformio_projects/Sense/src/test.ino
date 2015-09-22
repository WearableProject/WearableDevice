// DHT Temperature & Humidity Sensor
// Unified Sensor Library Example
// Written by Tony DiCola for Adafruit Industries
// Released under an MIT license.
// Depends on the following Arduino libraries:
// - Adafruit Unified Sensor Library: https://github.com/adafruit/Adafruit_Sensor
// - DHT Sensor Library: https://github.com/adafruit/DHT-sensor-library

#include <Display.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

#define DHTPIN            2         // Pin which is connected to the DHT sensor.

// Uncomment the type of sensor in use:
//#define DHTTYPE           DHT11     // DHT 11
#define DHTTYPE           DHT22     // DHT 22 (AM2302)
//#define DHTTYPE           DHT21     // DHT 21 (AM2301)

// See guide for details on sensor wiring and usage:
//   https://learn.adafruit.com/dht/overview

DHT_Unified dht(DHTPIN, DHTTYPE);

uint32_t delayMS;
Display display = Display();

void setup() {
  display.setup();
  Serial.begin(9600);
  // Initialize device.
  dht.begin();
  display.show("DHTxx Unified Sensor Example");
  // Print temperature sensor details.
  sensor_t sensor;
  dht.temperature().getSensor(&sensor);
  display.show("------------------------------------");
  display.show("Temperature");
  display.show  ("Sensor:       "); display.show(sensor.name);
  display.show  ("Driver Ver:   "); display.show(sensor.version);
  display.show  ("Unique ID:    "); display.show(sensor.sensor_id);
  display.show  ("Max Value:    "); display.show(sensor.max_value);
  display.show(" *C");
  display.show  ("Min Value:    ");
  display.show(sensor.min_value); display.show(" *C");
  display.show  ("Resolution:   ");
  display.show(sensor.resolution);
  display.show(" *C");
  display.show("------------------------------------");
  // Print humidity sensor details.
  dht.humidity().getSensor(&sensor);
  display.show("------------------------------------");
  display.show("Humidity");
  display.show  ("Sensor:       "); display.show(sensor.name);
  display.show  ("Driver Ver:   "); display.show(sensor.version);
  display.show  ("Unique ID:    "); display.show(sensor.sensor_id);
  display.show  ("Max Value:    "); display.show(sensor.max_value);
  display.show("%");
  display.show  ("Min Value:    ");
  display.show(sensor.min_value);
  display.show("%");
  display.show  ("Resolution:   ");
  display.show(sensor.resolution);
  display.show("%");
  display.show("------------------------------------");
  // Set delay between sensor readings based on sensor details.
  delayMS = sensor.min_delay / 1000;
}

void loop() {
  // Delay between measurements.
  delay(delayMS);
  // Get temperature event and print its value.
  sensors_event_t event;
  dht.temperature().getEvent(&event);
  if (isnan(event.temperature)) {
    display.show("Error reading temperature!");
  }
  else {
    display.show("Temperature: ");
    display.show(event.temperature);
    display.show(" *C");
  }
  // Get humidity event and print its value.
  dht.humidity().getEvent(&event);
  if (isnan(event.relative_humidity)) {
    display.show("Error reading humidity!");
  }
  else {
    display.show("Humidity: ");
    display.show(event.relative_humidity);
    display.show("%");
  }
}
