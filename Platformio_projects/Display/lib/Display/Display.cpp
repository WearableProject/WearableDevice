#include <Display.h>
#include <U8glib.h>


void Display::showChars(char text[], int x=0, int y=20)
{
    firstPage();
    do {
        drawStr( x, y, text);
    } while( nextPage() );

}

void Display::scrollRight(char* text, int speed)
{
  int x = 0;
  int screenWidth = getWidth();
  while(x < screenWidth)
  {
    showChars(text, x, 20);
    x+= speed;
  }
}

void Display::scrollRightContinuous(char* text, int speed, int _seconds)
{
  int x = 0;
  int screenWidth = getWidth();
  int seconds = 0;
  while(seconds < _seconds)
  {
    while(x < screenWidth)
    {
      showChars(text, x, 20);
      x+= speed;
    }
    x = -screenWidth;
    seconds += 1;
  }
}

void Display::scrollLeft(char* text, int speed)
{
  int x = 0;
  int screenWidth = getWidth();
  while(x > -screenWidth)
  {
    showChars(text, x, 20);
    x-= speed;
  }
}

void Display::scrollLeftContinuous(char* text, int speed, int _seconds)
{
  int x = 0;
  int screenWidth = getWidth();
  int seconds = 0;
  while(seconds < _seconds)
  {
    while(x > -screenWidth)
    {
      showChars(text, x, 20);
      x-= speed;
    }
    seconds += 1;
    x = screenWidth;
  }

}

void Display::scrollHorizontally(char* text, int speed)
{
  int x = 0;
  int screenWidth = getWidth();
  while(x < screenWidth)
  {
    showChars(text, x, 20);
    x+= speed;
  }
  while(x > -screenWidth)
  {
    showChars(text,x,20);
    x-= speed;
  }
}

void Display::scrollHorizontallyContinuous(char* text, int speed, int _seconds)
{
  int x = 0;
  int screenWidth = getWidth();
  int seconds = 0;
  while(seconds < _seconds)
  {
    while(x < screenWidth)
    {
      showChars(text, x, 20);
      x+= speed;
    }
    while(x > -screenWidth)
    {
      showChars(text,x,20);
      x-= speed;
    }
  }
}

void Display::scrollUp(char* text, int speed)
{
  int y = 0;
  int screenHeight = getHeight();
  while(y > -screenHeight)
  {
    showChars(text, 0, y);
    y-= speed;
  }
}

void Display::scrollUpContinuous(char* text, int speed, int _seconds)
{
  int y = 0;
  int screenHeight = getHeight();
  int seconds = 0;
  while(seconds > _seconds)
  {
    while(y > -screenHeight)
    {
      showChars(text, 0, y);
      y-= speed;
    }
    seconds += 1;
    y = screenHeight;
  }

}

void Display::scrollDown(char* text, int speed)
{
  int y = 0;
  int screenHeight = getHeight();
  while(y < screenHeight)
  {
    showChars(text, 0, y);
    y+= speed;
  }
}

void Display::scrollDownContinuous(char* text, int speed, int _seconds)
{
  int y = 0;
  int screenHeight = getHeight();
  int seconds = 0;
  while(seconds < _seconds)
  {
    while(y < screenHeight)
    {
      showChars(text, 0, y);
      y+= speed;
    }
    y = -screenHeight;
    seconds += 1;
  }

}
void Display::scrollVertically(char* text, int speed)
{
  int y = 0;
  int screenHeight = getHeight();
  while(y < screenHeight)
  {
    showChars(text, 0, y);
    y+= speed;
  }
  while(y > -screenHeight)
  {
    showChars(text, 0, y);
    y-= speed;
  }
}

void Display::scrollVerticallyContinuous(char* text, int speed, int _seconds)
{
  int y = 0;
  int screenHeight = getHeight();
  int seconds = 0;
  while(seconds < _seconds)
  {
    while(y < screenHeight)
     {
       showChars(text, 0, y);
       y+= speed;
     }
     while(y > -screenHeight)
     {
       showChars(text, 0, y);
       y-= speed;
     }
     seconds += 1;
  }
}

void Display::show(String text)
{
  char c[text.length()+1];
  text.toCharArray(c,text.length()+1);
  showChars(c);
}

void Display::show(int32_t value)
{
  char* result;
  itoa(value,result,0);
  show(result);
}

void Display::show(float value)
{
  char* stringOutput;
  floatToString(stringOutput, value, 3, 7);
  show(stringOutput);

}

void Display::setup()
{
  setFont(u8g_font_unifont);
  setColorIndex(1);
}

char * Display::floatToString(char * outstr, double val, byte precision, byte widthp){
 char temp[16]; //increase this if you need more digits than 15
 byte i;

 temp[0]='\0';
 outstr[0]='\0';

 if(val < 0.0){
   strcpy(outstr,"-\0");  //print "-" sign
   val *= -1;
 }

 if( precision == 0) {
   strcat(outstr, ltoa(round(val),temp,10));  //prints the int part
 }
 else {
   unsigned long frac, mult = 1;
   byte padding = precision-1;

   while (precision--)
     mult *= 10;

   val += 0.5/(float)mult;      // compute rounding factor

   strcat(outstr, ltoa(floor(val),temp,10));  //prints the integer part without rounding
   strcat(outstr, ".\0"); // print the decimal point

   frac = (val - floor(val)) * mult;

   unsigned long frac1 = frac;

   while(frac1 /= 10)
     padding--;

   while(padding--)
     strcat(outstr,"0\0");    // print padding zeros

   strcat(outstr,ltoa(frac,temp,10));  // print fraction part
 }

 // generate width space padding
 if ((widthp != 0)&&(widthp >= strlen(outstr))){
   byte J=0;
   J = widthp - strlen(outstr);

   for (i=0; i< J; i++) {
     temp[i] = ' ';
   }

   temp[i++] = '\0';
   strcat(temp,outstr);
   strcpy(outstr,temp);
 }

 return outstr;
}
