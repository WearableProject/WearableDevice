#include "Arduino.h"
#include <U8glib.h>

class Display : public U8GLIB_SSD1306_128X64 {
public:
  Display() : U8GLIB_SSD1306_128X64(U8G_I2C_OPT_NONE) {};
  void setup();
  void showChars(char text[]);
  void showString(String text);
};
