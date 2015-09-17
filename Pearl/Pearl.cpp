#include <FastSPI_LED2.h>
#include <Pearl.h>

Pearl::Pearl(int _leds) : CFastSPI_LED2()
{
  leds = _leds;
  colours = new CRGB[leds];
  // this is hacky. For some reason wasn't allowed to define const int in the class that would be acceptable in WS2811 template
  addLeds(new WS2811Controller800Khz<4>(), colours, leds, 0);
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
