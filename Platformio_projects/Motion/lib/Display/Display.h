#include "Arduino.h"
#include <U8glib.h>

class Display : public U8GLIB_SSD1306_128X64 {
public:
  Display() : U8GLIB_SSD1306_128X64(U8G_I2C_OPT_NONE) {};
  void setup();
  void showChars(char text[], int x, int y);
  void show(String text);
  void show(float value);
  void show(int32_t value);
  void scrollRight(String text, int speed);
  void scrollRightContinuous(String text, int speed, int _seconds);
  void scrollLeftContinuous(String text, int speed, int _seconds);
  void scrollLeft(String text, int speed);
  void scrollUp(String text, int speed);
  void scrollUpContinuous(String text, int speed, int _seconds);
  void scrollDown(String text, int speed);
  void scrollDownContinuous(String text, int speed, int _seconds);
  void scrollHorizontally(String text, int speed);
  void scrollHorizontallyContinuous(String text, int speed, int _seconds);
  void scrollVertically(String text, int speed);
  void scrollVerticallyContinuous(String text, int speed, int _seconds);
  char* floatToString(char* outstr, double val, byte precision, byte widthp);
};
