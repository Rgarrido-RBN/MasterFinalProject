import serial
from time import sleep

ser = serial.Serial ("/dev/ttyS0", 115200, timeout=1.0)
while True:
    received_data = ser.readline()
    print (received_data)
    # ser.write(bytes(received_data))
    # ser.write(b"sending string to Arduino\n")
    sleep(0.01)