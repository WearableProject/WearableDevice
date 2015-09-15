#include <Display.h>

void Display::showChars(char text[])
{
    firstPage();
    do {
        drawStr( 0, 20, c);
    } while( nextPage() );

}

void Display::show(string text)
{
  char c[text.length()+1];
  text.toCharArray(c,text.length()+1);
  showChars(c);
}
