#include <Display.h>
#include <U8glib.h>

void Display::showChars(char text[])
{
    firstPage();
    do {
        drawStr( 0, 20, text);
    } while( nextPage() );

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
