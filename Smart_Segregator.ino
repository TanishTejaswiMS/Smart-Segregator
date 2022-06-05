#include <Servo.h>

const int sensor_pin = A0;
Servo myservo;

void setup() {
  Serial.begin(9600);
  myservo.attach(9);
}

void loop() {
  float moisture_percentage;
  int sensor_analog;
  sensor_analog = analogRead(sensor_pin);
  moisture_percentage = ( 100 - ( (sensor_analog/1023.00) * 100 ) );
  Serial.print("Moisture Percentage = ");
  Serial.print(moisture_percentage);
  Serial.print("%\n\n");

  if(moisture_percentage>15)
  {
    myservo.write(45);
    } 
  else
  {
    myservo.write(0);
  }
  
  delay(1000);
}
