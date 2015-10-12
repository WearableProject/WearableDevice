// FlashBand Demo for motion
// Also requires pearl or display to show the data, or else you can use serial instead.

#include <Pearl.h>

#include <Motion.h>
#include <Display.h>
#include <MMA7660.h>

Pearl pearl = Pearl();

#define threshold 20
int head=0;  // head of moving snake
char buffer[50];
#define tdelay 1000
Motion motion = Motion();
Display display = Display();

void setup()
{
  motion.init();
  display.setup();
  pearl.off();
}

void loop()
{
motion.update();
int x = motion.getX();
int y = motion.getY();
display.showString(String(x)+String(y));
if (x < -threshold)
{
pearl.off();
  pearl.ChangeMultiple(new int[4]{2,3,4,0}, CRGB(0,0,255));
  pearl.show();
  delay(tdelay);
}
else if (x > threshold)
{
pearl.off();
pearl.ChangeMultiple(new int[3]{1,2,5}, CRGB(0,0,255));
pearl.show();
  delay(tdelay);
}
else if (y < -threshold)
{
pearl.off();
pearl.ChangeMultiple(new int[2]{1,2}, CRGB(0,0,255));

pearl.show();
  delay(tdelay);
}
else if (y > threshold)
{
pearl.off();
pearl.ChangeMultiple(new int[2]{4,5}, CRGB(0,0,255));

pearl.show();
  delay(tdelay);
}
else
{
pearl.ChangeAll(CRGB(0,0,40));
  delay(tdelay);
}
}
