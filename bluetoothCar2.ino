#include <AFMotor.h>
#include <SoftwareSerial.h>
#define BTTX 9
#define BTRX 10
SoftwareSerial SerialBT(BTTX, BTRX);

AF_DCMotor motor1(1, MOTOR12_1KHZ);
AF_DCMotor motor2(2, MOTOR12_1KHZ);
AF_DCMotor motor3(3, MOTOR34_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);

char val;

void setup()
{
  Serial.begin(115200);
  SerialBT.begin(9600);
  motor1.setSpeed(255);
  motor2.setSpeed(255);
  motor3.setSpeed(255);
  motor4.setSpeed(255);
}

void loop() {
  if (SerialBT.available()) {
    val = SerialBT.read();
    
    motor1.run(RELEASE); 
    motor2.run(RELEASE); 
    motor3.run(RELEASE); 
    motor4.run(RELEASE);
    
    if (val == 'F') {
      motor1.setSpeed(255); 
      motor1.run(FORWARD); 
      motor2.setSpeed(255); 
      motor2.run(FORWARD); 
      motor3.setSpeed(255);
      motor3.run(FORWARD); 
      motor4.setSpeed(255);
      motor4.run(FORWARD); 
    }
    
    if (val == 'B') {
      motor1.setSpeed(255); 
      motor1.run(BACKWARD); 
      motor2.setSpeed(255); 
      motor2.run(BACKWARD); 
      motor3.setSpeed(255);
      motor3.run(BACKWARD); 
      motor4.setSpeed(255);
      motor4.run(BACKWARD); 
    }
    
    if (val == 'L') {
      motor1.setSpeed(255); 
      motor1.run(BACKWARD); 
      motor2.setSpeed(255); 
      motor2.run(BACKWARD); 
      motor3.setSpeed(255);
      motor3.run(FORWARD);  
      motor4.setSpeed(255);
      motor4.run(FORWARD);  
    }
    
    if (val == 'R') {
      motor1.setSpeed(255); 
      motor1.run(FORWARD); 
      motor2.setSpeed(255); 
      motor2.run(FORWARD); 
      motor3.setSpeed(255);
      motor3.run(BACKWARD); 
      motor4.setSpeed(255);
      motor4.run(BACKWARD); 
    }
    
    if (val == 'I') {
      motor1.setSpeed(255 / 3.1); 
      motor1.run(FORWARD); 
      motor2.setSpeed(255 / 3.1); 
      motor2.run(FORWARD); 
      motor3.setSpeed(255);
      motor3.run(FORWARD); 
      motor4.setSpeed(255);
      motor4.run(FORWARD); 
    }
   
    if (val == 'G') {
      motor1.setSpeed(255); 
      motor1.run(FORWARD); 
      motor2.setSpeed(255); 
      motor2.run(FORWARD); 
      motor3.setSpeed(255 / 3.1); 
      motor3.run(FORWARD); 
      motor4.setSpeed(255 / 3.1); 
      motor4.run(FORWARD); 
    }
    
    if (val == 'J') {
      motor1.setSpeed(255 / 3.1); 
      motor1.run(BACKWARD); 
      motor2.setSpeed(255 / 3.1); 
      motor2.run(BACKWARD); 
      motor3.setSpeed(255); 
      motor3.run(BACKWARD); 
      motor4.setSpeed(255); 
      motor4.run(BACKWARD); 
    }
    
    if (val == 'H') {
      motor1.setSpeed(255); 
      motor1.run(BACKWARD); 
      motor2.setSpeed(255); 
      motor2.run(BACKWARD); 
      motor3.setSpeed(255 / 3.1); 
      motor3.run(BACKWARD); 
      motor4.setSpeed(255 / 3.1); 
      motor4.run(BACKWARD); 
    }
    
    if (val == 'S') {
      motor1.run(RELEASE); 
      motor2.run(RELEASE); 
      motor3.run(RELEASE); 
      motor4.run(RELEASE); 
    }
    
  }
}
