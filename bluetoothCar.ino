#include <AFMotor.h>
#include <SoftwareSerial.h>
#define BTTX 9
#define BTRX 10
SoftwareSerial SerialBT(BTTX, BTRX);

// inisialisasi motor
AF_DCMotor motor1(1, MOTOR12_1KHZ);
AF_DCMotor motor2(2, MOTOR12_1KHZ);
AF_DCMotor motor3(3, MOTOR34_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);

char val;

void setup()
{
  Serial.begin(115200);
  SerialBT.begin(9600);   // baud rate untuk module bluetooth
  motor1.setSpeed(255);   // atur kecepatan motor
  motor2.setSpeed(255);   // atur kecepatan motor
  motor3.setSpeed(255);   // atur kecepatan motor
  motor4.setSpeed(255);   // atur kecepatan motor
}

void loop() {
  if (SerialBT.available()) {
    val = SerialBT.read();
    
    // inisialisasi kondisi stop motor
    motor1.run(RELEASE); 
    motor2.run(RELEASE); 
    motor3.run(RELEASE); 
    motor4.run(RELEASE); 
    
    // inisialisasi kondisi maju kedepan
    if (val == 'F') {
      motor1.run(FORWARD); 
      motor2.run(FORWARD); 
      motor3.run(FORWARD);
      motor4.run(FORWARD); 
    }
    
    // inisialisasi kondisi mundur ke belakang
    if (val == 'B') {
      motor1.run(BACKWARD); 
      motor2.run(BACKWARD); 
      motor3.run(BACKWARD); 
      motor4.run(BACKWARD);
    }
  }
}
