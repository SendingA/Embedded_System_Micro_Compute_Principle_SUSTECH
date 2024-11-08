import serial
# 创建串口对象
ser = serial.Serial("COM3", 1000000, 8, "N", 1, timeout=None)
test_string = "test"
ser.write(test_string.encode('utf-8'))

