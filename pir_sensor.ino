// PIR sensörünün ba?l? oldu?u pin
int pirPin = 2;
// LED'in ba?l? oldu?u pin (iste?e ba?l?)
int ledPin = 8;
// PIR sensöründen gelen okuma de?eri
int pirValue = 0;


void setup() {
  // PIR sensör pinini giri? olarak ayarla
  pinMode(pirPin, INPUT);
  // LED pinini ç?k?? olarak ayarla (iste?e ba?l?)
  pinMode(ledPin, OUTPUT);
  // Seri ileti?imi ba?lat
  Serial.begin(9600);
}


void loop() {
  // PIR sensöründen gelen de?eri oku
  pirValue = digitalRead(pirPin);
  // Seri monitörde de?eri yazd?r
  Serial.println(pirValue);


  // Hareket alg?land???nda (pirValue == HIGH)
  if (pirValue == HIGH) {
    // LED'i yak (iste?e ba?l?)
    digitalWrite(ledPin, HIGH);
    // ?lgili i?lemi yap
    //Serial.println("Hareket alg?land?!");
  } else {
    // LED'i söndür (iste?e ba?l?)
    digitalWrite(ledPin, LOW);
  }


  // K?sa bir süre bekle
  delay(1000);
}

