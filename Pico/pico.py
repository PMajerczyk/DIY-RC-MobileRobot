from machine import Pin, ADC, UART
import time


adc1 = ADC(Pin(26))
adc2 = ADC(Pin(27))
bt = UART(0, 9600, tx=Pin(0), rx=Pin(1))


def main():
    while True:
        value1 = adc1.read_u16()
        value2 = adc2.read_u16()
        data = str(value1) + ',' + str(value2) + '\n'
        bt.write(data.encode())
        time.sleep(100)


if __name__ == "__main__":
    main()
