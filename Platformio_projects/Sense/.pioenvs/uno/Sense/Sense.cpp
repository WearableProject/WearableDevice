#include <Sense.h>

double Sense::Dewpoint()
{
	double a = 17.271;
	double b = 237.7;
	double temp = (a * temperature) / (b + temperature) + log(humidity*0.01);
	double Td = (b * temp) / (a - temp);
	return Td;
}

double Sense::Fahrenheit()
{
	return 1.8 * temperature + 32;
}

double Sense::Kelvin()
{
	return temperature + 273.15;
}
