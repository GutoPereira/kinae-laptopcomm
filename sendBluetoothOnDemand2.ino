#include <SoftwareSerial.h>

SoftwareSerial toMobile(10, 11); //RX, TX

String data;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(57600);

  toMobile.begin(57600);

  pinMode(13, OUTPUT);
  pinMode(2, INPUT_PULLUP);
}

void loop() {
  if (digitalRead(2) == 0) {
    Serial.println("T1");
    digitalWrite(13, HIGH);
  } else {
    Serial.println("T0");
    digitalWrite(13, LOW);
  }

  // put your main code here, to run repeatedly:
  if (Serial.available()) {
    data = Serial.readStringUntil('\n');
    data.trim();
    Serial.flush();
  }

  if (toMobile.available()) {
    String in = toMobile.readStringUntil('\n');

    if (in.charAt(0) == 'r') {
      toMobile.println(data);
    }
  }
}
