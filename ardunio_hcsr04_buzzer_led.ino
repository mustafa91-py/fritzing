

#define echo_pin 6
#define trig_pin 7
#define buzzer_pin 8
#define led_pin 9


int maximum_range = 50;
int minimum_range = 0;


void setup() {
  // put your setup code here, to run once:
  pinMode(trig_pin,OUTPUT);
  pinMode(echo_pin,INPUT);
  pinMode(buzzer_pin,OUTPUT);
  pinMode(led_pin,OUTPUT);
  //Serial.begin(9600);
}


void loop() {
  // put your main code here, to run repeatedly:
  int olcum = mesafe(maximum_range,minimum_range);
//  Serial.println(olcum);
  melodi(olcum*10);


}
int mesafe(int max ,int min){
  long duration,distance;
  digitalWrite(trig_pin,LOW);
  delayMicroseconds(2);
  digitalWrite(trig_pin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig_pin,LOW);
  duration = pulseIn(echo_pin,HIGH);
  distance = duration / 58.2;
  delay(50);
  if (distance > max || distance <= min)
  return 0;
  return distance;
}
int melodi(int dly){


  if (dly){
    tone(buzzer_pin, 440);
    digitalWrite(led_pin,HIGH);
    delay(dly);
    digitalWrite(led_pin,LOW);
    noTone(buzzer_pin);
    delay(dly);
    }
  }


