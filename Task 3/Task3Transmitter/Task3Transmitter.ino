#include <Wire.h>

void setup()
{
  Wire.begin();
	Serial.begin(9600);
	Serial.println("Ultrasonic Basic Initialized");
}
void loop() {

	long duration;

	pinMode(4, OUTPUT);
	digitalWrite(4, LOW);
	delayMicroseconds(2);
	digitalWrite(4, HIGH);
	delayMicroseconds(10);
	digitalWrite(4,LOW);
	duration = pulseIn(3,HIGH);
  
  Wire.beginTransmission(4);
  Wire.write(highByte(duration));
  Wire.write(lowByte(duration));
  Wire.endTransmission();
  
  //for debugging
  
  Serial.print("duration = ");
  Serial.println(duration);
  	
  Serial.print("highByte = ");
  Serial.println(highByte(duration));
  
  Serial.print("lowByte = ");
  Serial.println(lowByte(duration));
  	
  delay(1000);
}
