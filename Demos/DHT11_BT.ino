//
//   FILE:  dht11_test1.pde
// PURPOSE: DHT11 library test sketch for Arduino
//

#include <dht11.h>
#include <SoftwareSerial.h>

SoftwareSerial BLE (2, 3); // RX, TX
int av;
char buf[300];
dht11 DHT11;

#define DHT11PIN 4

void setup()
{
  Serial.begin(115200);
  BLE.begin(9600);
  Serial.println("DHT11 TEST PROGRAM ");
  Serial.print("LIBRARY VERSION: ");
  Serial.println(DHT11LIB_VERSION);
  Serial.println();
}

void loop()
{
  Serial.println("\n");

  int chk = DHT11.read(DHT11PIN);

  Serial.print("Read sensor: ");
  switch (chk)
  {
    case 0: Serial.println("OK"); break;
    case -1: Serial.println("Checksum error"); break;
    case -2: Serial.println("Time out error"); break;
    default: Serial.println("Unknown error"); break;
  }

  BLE.println("Humidity (%): " + String(DHT11.humidity));
  delay(100);
  BLE.println("Temp (oC): " + String(DHT11.temperature));
  delay(100);
  BLE.println("Light: " + String(analogRead(A0)));

  delay(2000);
}
//
// END OF FILE
//
