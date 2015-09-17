#include <FastSPI_LED2.h>
#include <Pearl.h>

Pearl::Pearl() : CFastSPI_LED2()
{
  addLeds(new WS2811Controller800Khz<data_pin>(), colours, leds, 0);
  setBrightness(40);
}

void Pearl::Change(int LED, CRGB colour)
{
  colours[LED] = colour;
}

void Pearl::ChangeMultiple(int leds[], CRGB colour)
{
  for(int i=0;i<sizeof(leds)/sizeof(int);i++)
  {
    colours[leds[i]] = colour;
  }
}

void Pearl::Update()
{
  show();
}
