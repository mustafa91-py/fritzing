// PIR sens�r�n�n ba?l? oldu?u pin
int pirPin = 2;
// LED'in ba?l? oldu?u pin (iste?e ba?l?)
int ledPin = 8;
// PIR sens�r�nden gelen okuma de?eri
int pirValue = 0;


void setup() {
  // PIR sens�r pinini giri? olarak ayarla
  pinMode(pirPin, INPUT);
  // LED pinini �?k?? olarak ayarla (iste?e ba?l?)
  pinMode(ledPin, OUTPUT);
  // Seri ileti?imi ba?lat
  Serial.begin(9600);
}


void loop() {
  // PIR sens�r�nden gelen de?eri oku
  pirValue = digitalRead(pirPin);
  // Seri monit�rde de?eri yazd?r
  Serial.println(pirValue);


  // Hareket alg?land???nda (pirValue == HIGH)
  if (pirValue == HIGH) {
    // LED'i yak (iste?e ba?l?)
    digitalWrite(ledPin, HIGH);
    // ?lgili i?lemi yap
    //Serial.println("Hareket alg?land?!");
  } else {
    // LED'i s�nd�r (iste?e ba?l?)
    digitalWrite(ledPin, LOW);
  }


  // K?sa bir s�re bekle
  delay(1000);
}

