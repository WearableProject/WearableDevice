// FlashBand Demo App
// Requires: Core, Pearl
// Optional: Blue, Motion
// Reads accelerometer values and drops blue LEDs to side point down
// Sends accelerometer values over Bluetooth LE
// If Motion not connected, then displays circling ring of Purple LEDs with trail

#include <Wire.h>
#include <MMA7660.h>
#include "FastSPI_LED2.h"
#include <SoftwareSerial.h>

SoftwareSerial BLE (2, 3); // RX, TX

// OLED Stuff
#include <U8glib.h>

U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NONE);
//
 // Instructs the display to draw with a pixel on.

// WS2812B definitions
#define NUM_LEDS 6
#define DATA_PIN 4
CRGB leds[NUM_LEDS];

#define threshold 20
int head=0;  // head of moving snake
char buffer[50];
#define tdelay 1000
int x,y,z;

void setup()
{
  Serial.begin(115200);
  BLE.begin(9600);
  MMA7660.init();
  FastLED.addLeds<WS2812B, DATA_PIN, RGB>(leds, NUM_LEDS);
  FastLED.setBrightness(40);
  Serial.println("Starting");
  allOff();

  u8g.setFont(u8g_font_unifont);
  u8g.setColorIndex(1); // Instructs the display to draw with a pixel on.

  showChars("FlashBand!");
  delay(1000);
  MMA7660.getValues(&x,&y,&z);
  if (x==0 && y==0)
//    showChars2("Motion disconnected");
    showChars2("Motion notfitted");
}

void showChars(char c[])
{
  u8g.firstPage();
  do {
      u8g.drawStr( 0, 20, c);
  } while( u8g.nextPage() );
}

void showChars2(char c[])
{
  u8g.firstPage();
  do
  {
    u8g.drawStr(0, 20, "Flashband!");
    u8g.drawStr(0, 36, c);
  } while( u8g.nextPage() );
}

void showString(String text)
{
  char c[text.length()+1];
  text.toCharArray(c,text.length()+1);
  showChars(c);

}

void loop()
{
  MMA7660.getValues(&x,&y,&z);
  int i = sprintf(buffer, "X:%d Y:%d Z:%d", x, y, z);
  buffer[i] = 0;
  Serial.println(buffer);
  BLE.println(buffer);
  if(x!=0 && y!=0)
    showChars2(buffer);
  if (x==0 && y==0)
  {
    leds[head] = CRGB(0,100,100);
    leds[(head+5)%6] = CRGB(0,50,50);
    leds[(head+4)%6] = CRGB(0,25,25);
    leds[(head+3)%6] = CRGB(0,10,10);
    leds[(head+2)%6] = CRGB(0,5,5);
    leds[(head+1)%6] = CRGB(0,0,0);
    FastLED.show();
    head = (head+1)%6;
    delay(100);
  }
  else if (x < -threshold)
  {
    set345(CRGB(0,0,255));
    set126(CRGB(0,0,0));
    delay(tdelay);
  }
  else if (x > threshold)
  {
    set345(CRGB(0,0,0));
    set126(CRGB(0,0,255));
    delay(tdelay);
  }
  else if (y < -threshold)
  {
    set23(CRGB(0,0,255));
    set1456(CRGB(0,0,0));
    delay(tdelay);
  }
  else if (y > threshold)
  {
    set56(CRGB(0,0,255));
    set1234(CRGB(0,0,0));
    delay(tdelay);
  }
  else
  {
    setAll(CRGB(40,0,0));
    delay(tdelay);
  }
}

void allOff()
{
  for (int i=0; i<NUM_LEDS; i++)
    leds[i] = 0;
  FastLED.show();
}

void setAll(CRGB colour)
{
  for (int i=0; i<NUM_LEDS; i++)
  {
    leds[i] = colour;
  }
  FastLED.show();
}

void set345(CRGB colour)
{
  leds[2] = colour;
  leds[3] = colour;
  leds[4] = colour;
  FastLED.show();
}

void set126(CRGB colour)
{
  leds[0] = colour;
  leds[1] = colour;
  leds[5] = colour;
  FastLED.show();
}

void set56(CRGB colour)
{
  leds[4] = colour;
  leds[5] = colour;
  FastLED.show();
}

void set23(CRGB colour)
{
  leds[1] = colour;
  leds[2] = colour;
  FastLED.show();
}

void set1456(CRGB colour)
{
  leds[0] = colour;
  leds[3] = colour;
  leds[4] = colour;
  leds[5] = colour;
  FastLED.show();
}

void set1234(CRGB colour)
{
  leds[0] = colour;
  leds[1] = colour;
  leds[2] = colour;
  leds[3] = colour;
  FastLED.show();
}
