#include <Mouse.h>

const int16_t scale=10;
#define STEPS 100

void setup()
{
  Mouse.begin();
  delay(2000);
}

void loop()
{
  uint16_t x, y, ox, oy;
  uint16_t i;
  
  for (i=0; i<=STEPS; i++)
  {
    float t=1.0*i/STEPS*M_PI*2;
    x=scale*16*pow(sin(t),3);
    y=-scale*(13*cos(t)-5*cos(t*2)-2*cos(t*3)-cos(t*4));
    if (i!=0)
    {
      if (!Mouse.isPressed(MOUSE_LEFT))
      {
        Mouse.press(MOUSE_LEFT);
      }
      Mouse.move(x-ox, y-oy, 0);
      delay(10);
    }
    ox=x;
    oy=y;
  }
  Mouse.release(MOUSE_LEFT);
  while(1);
}
