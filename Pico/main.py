from machine import Pin, ADC, UART
import time


adc1 = ADC(Pin(26))
adc2 = ADC(Pin(27))
bt = UART(0, 9600, tx=Pin(0), rx=Pin(1))
led = Pin(25, Pin.OUT)


def main():
    while True:
        value1 = adc1.read_u16()
        value2 = adc2.read_u16()
        data = str(value1) + ',' + str(value2) + '\n'   # data to string
        print(data)
        print(data.encode())
        led(1)
        time.sleep(0.1)
        led(0)
        bt.write(data.encode())   # send data
        time.sleep(0.1)
        led(1)
        time.sleep(0.1)
        led(0)
        time.sleep(0.5)


if __name__ == "__main__":
    main()
