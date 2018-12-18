#include <IRremote.h>
#include "motors_of_base.h"

int RECV_PIN = 9;

IRrecv irrecv(RECV_PIN);

decode_results results;

unsigned long _time;

#define FORWARD 0x20DF02FD
#define LEFT 0x20DFE01F
#define RIGHT 0x20DF609F
#define STOP 0x20DF22DD
#define BACKWARD 0x20DF827D


void setup()
{
  setup_motor_system(2, 3, 4, 5);
  _stop();
  irrecv.enableIRIn();
  _time = millis();
}

void loop()
{
  if(irrecv.decode(&results))
  {
    _time = millis();
    switch (results.value){
      case FORWARD:
        forward();
        break;
      case BACKWARD:
        backward();
        break;
      case LEFT:
        left();
        break;
      case RIGHT:
        right();
        break;
      case STOP:
        _stop();
        break;
    }
    irrecv.resume();
  }
  if((millis() - _time) > 150) {_stop();
 }
}
