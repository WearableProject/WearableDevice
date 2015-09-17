#include <Arduino.h>
#include <MMA7660.h>

class Motion : public MMA {
private:
  int x;
  int y;
  int z;

public:
  Motion() : MMA() {};
  int getX();
  int getY();
  int getZ();
  int* getVector();
  void update();
};
