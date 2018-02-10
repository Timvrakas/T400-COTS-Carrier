#include <Arduino.h>

uint64_t lastSignalChangeTime;
bool lastSignalState;

#define INPUT_PIN 4
#define OUTPUT_PIN 3

void setup() {
  pinMode(OUTPUT_PIN, OUTPUT);
  pinMode(INPUT_PIN, INPUT);
  digitalWrite(OUTPUT_PIN, HIGH);
}

void loop() {
  bool currentSignalState = digitalRead(INPUT_PIN);
  if (currentSignalState != lastSignalState){
    lastSignalChangeTime = millis();
    lastSignalState = currentSignalState;
  }
  if (millis() - lastSignalChangeTime > 2000) {
    digitalWrite(OUTPUT_PIN, HIGH);
  } else {
    digitalWrite(OUTPUT_PIN, LOW);
  }
}
