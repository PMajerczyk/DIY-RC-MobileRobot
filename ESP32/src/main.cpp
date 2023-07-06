#include "BluetoothSerial.h"
#include "ESP32Servo.h"

BluetoothSerial Bluetooth;
Servo Servo_1, Servo_2;

void setup() {

  Serial.begin(9600);
  Bluetooth.begin();
  Servo_1.attach(33);
  Servo_2.attach(32);
}

void loop() {

  int data_L = 0, data_R = 0;
  if (Bluetooth.available() >= sizeof(int) * 2) {
    data_L = Bluetooth.read();
    data_R = Bluetooth.read();
  }
  Servo_1.writeMicroseconds(data_L);
  Servo_2.writeMicroseconds(data_R);
  delay(100);
}
