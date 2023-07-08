#include "BluetoothSerial.h"
#include "ESP32Servo.h"

BluetoothSerial Bluetooth;
Servo Servo_1, Servo_2;

void setup() {

  Bluetooth.begin();
  Servo_1.attach(33);
  Servo_2.attach(32);
}

void loop() {

  int data_L = 0, data_R = 0;
  if (Bluetooth.available()) {
    String data = Bluetooth.readStringUntil('\n');
    data_L = data.substring(0, data.indexOf(',')).toInt();
    data_R = data.substring(data.indexOf(',') + 1).toInt();
  }
  Servo_1.writeMicroseconds(data_L);
  Servo_2.writeMicroseconds(data_R);
  delay(100);
}