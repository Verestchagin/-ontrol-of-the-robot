int motor_L1, motor_L2;
int motor_R1, motor_R2;
int motor_ENB, motor_ENA;

int speedCar = 100;

void setup_motor_system(int L1, int L2, int R1, int R2, int ENb, int ENa)
{
  motor_L1 = L1;
  motor_L2 = L2;
  motor_R1 = R1;
  motor_R2 = R2;
  motor_ENA = ENa;
  motor_ENB = ENb;  
  
  pinMode(motor_ENA, OUTPUT);
  pinMode(motor_ENB, OUTPUT);
  pinMode(motor_L1, OUTPUT);
  pinMode(motor_R1, OUTPUT);
  pinMode(motor_L2, OUTPUT);
  pinMode(motor_R2, OUTPUT);
}
  void forward()
  {
    digitalWrite(motor_L1, HIGH);
    digitalWrite(motor_L2, LOW);
    analogWrite(motor_ENB, speedCar);
    
    digitalWrite(motor_R1, HIGH);
    digitalWrite(motor_R2, LOW);
    analogWrite(motor_ENA, speedCar);
  }

  void left()
  {
    digitalWrite(motor_L1, LOW);
    digitalWrite(motor_L2, HIGH);
    analogWrite(motor_ENB, speedCar);
    
    digitalWrite(motor_R1, HIGH);
    digitalWrite(motor_R2, LOW);
    analogWrite(motor_ENA, speedCar);
  }

  void right()
  {
    digitalWrite(motor_L1, HIGH);
    digitalWrite(motor_L2, LOW);
    analogWrite(motor_ENB, speedCar);
    
    digitalWrite(motor_R1, LOW);
    digitalWrite(motor_R2, HIGH);
    analogWrite(motor_ENA, speedCar);
  }

  void backward()
  {
    digitalWrite(motor_L1, LOW);
    digitalWrite(motor_L2, HIGH);
    analogWrite(motor_ENB, speedCar);
    
    digitalWrite(motor_R1, LOW);
    digitalWrite(motor_R2, HIGH);
    analogWrite(motor_ENA, speedCar);
  }

  void _stop()
  {
    digitalWrite(motor_L1, LOW);
    digitalWrite(motor_L2, LOW);
    digitalWrite(motor_R1, LOW);
    digitalWrite(motor_R2, LOW);
  }
