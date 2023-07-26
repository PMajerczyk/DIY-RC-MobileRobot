# DIY RC Mobile Robot / ESP32

<br>ESP32 CP2102 gets data by Bluetooth and controls two Servo 360 MG966R<br>
The robot is powered by 6V from a battery box 4xAAA <br><br>

## Tasks ToDo:

Find and change the MAC address of the bluetooth device to be paired according to my example in the code (6th and 7th lines) <br>
```cpp
// 98:da:50:01:9f:7d - MAC address my device
uint8_t mac_address[] = {0x98,0xda,0x50,0x01,0x9f,0x7d}; 
```
Connect the electronic components according to the wiring diagram. <br>
Upload the code to the ESP32 from src/main.cpp <br><br>

## Wiring diagram:

<p >
    <img src="https://github.com/PMajerczyk/DIY-RC-MobileRobot/blob/main/ESP32/ESP32.png" alt="png" width="450" align="left">
    <img src="https://github.com/PMajerczyk/DIY-RC-MobileRobot/blob/main/ESP32/ESP32_connection.jpg" alt="png" width="450" align="right">
</p>

