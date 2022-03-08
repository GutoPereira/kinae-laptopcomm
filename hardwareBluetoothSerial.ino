#include <SoftwareSerial.h>

SoftwareSerial toMobile(10,11);//RX, TX

void setup() {
  // put your setup code here, to run once:
  Serial.begin(57600);

  toMobile.begin(57600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()) {
    toMobile.write(Serial.read());
    Serial.flush();
  }
}
