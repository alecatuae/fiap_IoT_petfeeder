#include <Servo.h>
#define PIR 7
#define SERVO 9
#define INTERVAL 1000

Servo servo;

unsigned long previousMillis = 0;

void abrir() {
  for (pos = 180; pos >= 0; pos--) {
    Serial.write(pos);
    delay(10);
  }
}

void fechar() {
  for (pos = 0; pos <= 180; pos++) {
    Serial.write(pos);
    delay(10);
  }
}

boolean feedTime() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= INTERVAL) {
    previousMillis = currentMillis;
    return true;
  } else {
    return false;
  }
}

void setup() {
  Serial.begin(9600);
  pinMode(PIR, INPUT);
  servo.attach(SERVO);
  servo.write(180);
}

void loop() {
  if ((digitalRead(PIR) == HIGH) && feedTime() == true) {
    Serial.println("Alimentando...");
    abrir();
    fechar();
  } else {
    Serial.println("Nenhum movimento.");
  }
}
