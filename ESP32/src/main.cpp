#include "BluetoothSerial.h"
#include "ESP32Servo.h"

BluetoothSerial Bluetooth;
Servo Servo_1, Servo_2;
// 98:da:50:01:9f:7d - MAC address my device
uint8_t mac_address[] = {0x98,0xda,0x50,0x01,0x9f,0x7d}; 

void setup() {
  Serial.begin(115200);
  Bluetooth.begin("ESP32test", true);
  Bluetooth.connect(mac_address);
  Servo_1.attach(33);
  Servo_2.attach(32);
}

void loop() {
  int data_L = 500, data_R = 1500;
  if (Bluetooth.available()) {
    String data = Bluetooth.readStringUntil('\n');
    data_L = data.substring(0, data.indexOf(',')).toInt();
    data_R = data.substring(data.indexOf(',') + 1).toInt();
    Serial.println("Bluetooth: " + data);
  }
  Servo_1.writeMicroseconds(data_L);
  Servo_2.writeMicroseconds(data_R);
}
