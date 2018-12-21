#include <IRremote.h>
#include "motors_of_base.h"

int RECV_PIN = 9;
int left_sensor_line = 11;
int right_sensor_line = 12;

unsigned long _time;

IRrecv irrecv(RECV_PIN);
decode_results results;

#define SPEED1 0x20DF8877
#define SPEED2 0x20DF48B7
#define SPEED3 0x20DFC837
#define SPEED4 0x20DF28D7
#define SPEED5 0x20DFA857
#define SPEED6 0x20DF6897
#define SPEED7 0x20DFE817
#define SPEED8 0x20DF18E7
#define SPEED9 0x20DF9867
#define DOWN 0x20DFC03F
#define UP 0x20DF40BF
#define FORWARD 0x20DF02FD
#define LEFT 0x20DFE01F
#define RIGHT 0x20DF609F
#define STOP 0x20DF22DD
#define BACKWARD 0x20DF827D
#define LINE 0x20DF08F7

void setup()
{
  setup_motor_system(2, 3, 4, 5, 6, 8);
  _stop();
  irrecv.enableIRIn();
  pinMode(left_sensor_line, INPUT);
  pinMode(right_sensor_line, INPUT);
  _time = millis();
  Serial.begin(9600);
}

void loop()
{
  if(irrecv.decode(&results))
  {
    _time = millis();
    switch (results.value){
      case SPEED1:
        speedCar = 120;
        break;
      case SPEED2:
        speedCar = 140;
        break;
      case SPEED3:
        speedCar = 160;
        break;
      case SPEED4:
        speedCar = 180;
        break;
      case SPEED5:
        speedCar = 200;
        break;
      case SPEED6:
        speedCar = 220;
        break;
      case SPEED7:
        speedCar = 230;
        break;
      case SPEED8:
        speedCar = 240;
        break;
      case SPEED9:
        speedCar = 250;
        break;
      case UP:
        speedCar += 10;
        break;
      case DOWN:
        speedCar -= 10;
        break;
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
      case LINE:
        while(true)
  {
    bool ls = digitalRead(left_sensor_line);
    bool rs = digitalRead(right_sensor_line);

    if((!ls) && (!rs))
    {
      forward();
    }
    else
    {
      if(ls)
      {
        left();
      }
      else
      {
        right();
      }
    }
    delayMicroseconds(500);
    _stop();
    delayMicroseconds(100);
  }
    }
    irrecv.resume();
  }
  if((millis() - _time) > 150) {_stop();}
}
