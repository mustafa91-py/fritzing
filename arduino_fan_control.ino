int lastValue = 0; 


void setup() {
  pinMode(9, OUTPUT); // PWM 
  // Pin 9 ve 10  PWM 31.25 kHz olarak ayarla
  TCCR1B = TCCR1B & 0b11111000 | 0x01;
  Serial.begin(9600);
  Serial.println("Fan kontrolu basladi");
}


void loop() {
  if (Serial.available() > 1) {
    // Raspberry Pi'den gelen veriyi oku
    lastValue = Serial.parseInt(); 
    analogWrite(9, lastValue);

    Serial.print("Gelen deger: ");
    Serial.println(lastValue);
    Serial.print("PWM degeri: ");
    Serial.println(lastValue);
  }





  delay(100); 
}
/* Raspberry pi ye usb ile baglanan Arduino ; 
		
Raspberyy pi 4 icin python kodu
```python
from gpiozero import LED
import time
import serial

def get_cpu_temp():
    temp = None
    with open("/sys/class/thermal/thermal_zone0/temp") as f:
        temp = f.read()
    return float(temp) / 1000
def scale_value(value, old_min, old_max, new_min, new_max):
    old_range = old_max - old_min
    new_range = new_max - new_min
    new_value = (((value - old_min) * new_range) / old_range) + new_min
    return new_value
def map_temp_to_value(temp):
    if int(temp) in range(30,44):
        return 0
    if temp >= 60:
        return 255
    else:
        return int(scale_value(temp, 36, 60, 80, 254))

def send_to_arduino(value, ser):
    ser.write(f"{value}\n".encode())

def func_red(ser):
    temp = get_cpu_temp()
    value = map_temp_to_value(temp)
    send_to_arduino(value, ser)
    print(temp,value)
    time.sleep(10)

if __name__ == "__main__":
    
    ser = serial.Serial('/dev/ttyUSB0', 9600)  # Adjust the serial port as necessary
    try:
        while True:
            func_red(ser)
    except KeyboardInterrupt as e:
        send_to_arduino(0,ser)

```
*/