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
  int data_L = 1500, data_R = 1500;
  if (!Bluetooth.hasClient()) {
    Serial.println("Bluetooth connection . . .");
    Bluetooth.connect(mac_address);
  }
  if (Bluetooth.available()) {
    String data = Bluetooth.readStringUntil('\n');
    data_L = data.substring(0, data.indexOf(',')).toInt();
    data_R = data.substring(data.indexOf(',') + 1).toInt();
    data_L = map(data_L, 0, 65535, 500, 2500);
    data_R = map(data_R, 0, 65535, 2500, 500);
    if (data_L <=1600 && data_L >=1400) data_L = 1500;
    else if (data_L >= 2400) data_L = 2500;
    else if (data_L <= 600) data_L = 500;
    if (data_R <=1600 && data_R >=1400) data_R = 1500;
    else if (data_R >= 2400) data_R = 2500;
    else if (data_R <= 600) data_R = 500;
    if (!Bluetooth.hasClient()) {
      data_L = 1500; 
      data_R = 1500;
    }
    Servo_1.writeMicroseconds(data_L);
    Servo_2.writeMicroseconds(data_R);
    Serial.println("Bluetooth: " + data + " - "+ data_L +","+ data_R);
  }
}
