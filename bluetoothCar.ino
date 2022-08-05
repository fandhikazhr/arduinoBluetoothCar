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
