#include <Wire.h>

void setup()
{
  Wire.begin(4);
  Wire.onReceive(receiveEvent);
  Serial.begin(9600);
	Serial.println("Ultrasonic Basic Initialized");
}

void loop()
{
  delay(100);
}

void receiveEvent(int howMany)
{
	byte byte1 = Wire.read();
  byte byte2 = Wire.read();
  
  long duration = (int)byte1 << 8 | (int)byte2;
  
  const long speed_of_sound = 34300;
  
	float time_taken = duration / 1000000.0;

	Serial.print("Time = ");
	Serial.print(time_taken, 6);
  Serial.println("s");

	float distance = (speed_of_sound * time_taken) / 2;
  
	Serial.print("Distance = ");
	Serial.print(distance);
  Serial.println("cm");
  
  	//for debugging
  
  Serial.print("duration = ");
  Serial.println(duration);
  
	Serial.print("highByte = ");
  Serial.println(byte1);
  
  Serial.print("lowByte = ");
  Serial.println(byte2);
  
	delay(1000);

}
