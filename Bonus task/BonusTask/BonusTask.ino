#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // change address

void setup()
{
	//Serial.begin(9600);
	//Serial.println("test");
	lcd.init();
	lcd.backlight();
}

void loop()
{
  long duration, analog, digital;

  digital = digitalRead(3);
  analog = analogRead(A1);
  
  const long speed_of_sound = 34300;
  
	pinMode(4, OUTPUT);
	digitalWrite(4, LOW);
	delayMicroseconds(2);
	digitalWrite(4, HIGH);
	delayMicroseconds(10);
	digitalWrite(4,LOW);
	duration = pulseIn(3,HIGH);
  
	Serial.println(duration);
  
  float time_taken = duration / 1000000.0;
  
  float distance = (speed_of_sound * time_taken) / 2;

  // for debugging
  
	//Serial.print("Distance = ");
	//Serial.println(distance);

	//Serial.print("Time = ");
  //Serial.println(time_taken, 6);

  // for debugging

  //Serial.print("Digital = ");
  //Serial.println(digital);

  //Serial.print("Analog = ")
  //Serial.println(analog)
  
	lcd.clear(); 
	lcd.setCursor(0, 0); 
	lcd.print("Distance="); 
  lcd.print(distance);
  lcd.println("cm")

	lcd.setCursor(0, 1); 
	lcd.print("Time="); 
  lcd.print(time_taken, 6);
  lcd.println("s");

	delay(2000);

	lcd.setCursor(0, 1); 
	lcd.print("Digital= ");
  lcd.println(digital)

  delay(2000);

  lcd.clear(); 
	lcd.setCursor(0, 0); 
  if (analog >= 529){
    lcd.print("Analog= 1");
  } else{
    lcd.print("Analog= 0");
  }

}
