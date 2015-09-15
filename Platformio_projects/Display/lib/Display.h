#include "Arduino.h"
#include <U8glib.h>


class Display : public U8GLIB_SSD1306_128X64 {
public:
  Display() : u8g(U8G_I2C_OPT_NONE);
  void showChars(char c[]);
  void show(string text);
}
