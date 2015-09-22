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
  void scrollRight(char* text, int speed);
  void scrollLeft(char* text, int speed);
  void scrollUp(char* text, int speed);
  void scrollDown(char* text, int speed);
  void scrollHorizontally(char* text, int speed);
  void scrollVertically(char* text, int speed);
  char* floatToString(char* outstr, double val, byte precision, byte widthp);
};
