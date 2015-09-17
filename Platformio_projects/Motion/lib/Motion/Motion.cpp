#include <Arduino.h>
#include <Motion.h>
#include <MMA7660.h>


void Motion::update()
{
  getValues(&x, &y, &z);
}

int Motion::getX()
{
  return x;
}

int Motion::getY()
{
  return y;
}

int Motion::getZ()
{
  return z;
}

int* Motion::getVector()
{
  int* returnValue = new int[3]{x, y, z};
  return returnValue;
}
