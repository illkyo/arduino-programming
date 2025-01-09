#include <Wire.h>

void setup() { 
  Wire.begin(4);
  Wire.onReceive(receiveEvent);
	Serial.begin(9600);
	Serial.println("Infrared Basic Initialized");
}


void loop() {

  delay(100);

}

void receiveEvent(int howMany)
{
  byte digitalByte1 = Wire.read();
  byte digitalByte2 = Wire.read();

	byte analogByte1 = Wire.read();
  byte analogByte2 = Wire.read();

  long digital = (int)digitalByte1 << 8 | (int)digitalByte2;

  long analog = (int)analogByte1 << 8 | (int)analogByte2;

  Serial.print("Digital = ");
  Serial.println(digital);

  bool analogBin = bit.read(analog, 0);

  Serial.print("Analog = ")
  Serial.println(analogBin)

  Serial.print("Analog (Full Binary) = ");
	Serial.println(analog, BIN);

	delay(1000);

}

