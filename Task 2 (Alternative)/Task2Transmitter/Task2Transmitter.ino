#include <Wire.h>

void setup() {
  Wire.begin();
  Serial.begin(9600);
  Serial.println("Infrared Basic Initialized");
}

void loop() {

  long analog, digital;
  
  digital = digitalRead(3);
  analog = analogRead(A1);

  Wire.beginTransmission(4);

	Wire.write(highByte(digital));
  Wire.write(lowByte(digital));

  Wire.write(highByte(analog));
  Wire.write(lowByte(analog));

  Wire.endTransmission();

  Serial.print("Digital = ");
  Serial.println(digital);

  Serial.print("Analog = ");
	Serial.println(analog);

  delay(1500);
}
