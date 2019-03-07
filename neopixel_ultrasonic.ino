#include <Adafruit_NeoPixel.h>
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(16, 6, NEO_GRB + NEO_KHZ800);

#define trigPin 9
#define echoPin 8

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  pixels.begin();
}

void loop() {
  
  long distance = getDistance();
  Serial.println(distance);

  if (distance < 100) {
    
    pixels.setPixelColor(0, pixels.Color(0,1,0));
    pixels.setPixelColor(1, pixels.Color(0,1,0));
    pixels.setPixelColor(2, pixels.Color(0,1,0));
    pixels.setPixelColor(3, pixels.Color(0,1,0));
    pixels.show();
    delay(500);
    
  } else {
    
    pixels.clear();
    pixels.show();
    delay(500);

  }
  
}


//RETURNS THE DISTANCE MEASURED BY THE HC-SR04 DISTANCE SENSOR
float getDistance()
{
// The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(echoPin, INPUT);
  long duration = pulseIn(echoPin, HIGH);
 
  // Convert the time into a distance
  long cm = (duration/2) / 29.1;     // Divide by 29.1 or multiply by 0.0343
  long inches = (duration/2) / 74;   // Divide by 74 or multiply by 0.0135
  
  return inches;
}
