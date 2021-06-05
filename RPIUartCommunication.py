# import serial
# from time import sleep

# ser = serial.Serial ("/dev/ttyS0", 11520)    #Open port with baud rate
# while True:
#     received_data = ser.read()              #read serial port
#     sleep(0.03)
#     data_left = ser.inWaiting()             #check for remaining byte
#     received_data += ser.read(data_left)
#     print (received_data)                   #print received data
#     ser.write(received_data)                #transmit data serially
import serial

serialport = serial.Serial("serial0", baudrate=115200, timeout=3.0)

while True:
    serialport.write("rnSay something:")
    rcv = port.read(10)
    serialport.write("rnYou sent:" + repr(rcv))