#include <Display.h>
#include <U8glib.h>

void Display::showChars(char text[])
{
    firstPage();
    do {
        drawStr( 0, 20, text);
    } while( nextPage() );

}

void Display::showString(String text)
{
  char c[text.length()+1];
  text.toCharArray(c,text.length()+1);
  showChars(c);
}

void Display::setup()
{
  setFont(u8g_font_unifont);
  setColorIndex(1);
}
