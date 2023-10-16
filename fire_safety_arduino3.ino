#include <Servo.h>

int sensorPin1 = 0;
int pos ;
int pos1;
int pos2;
int pos3;
Servo servo_9;

void setup()
{
  Serial.begin(9600);
  servo_9.attach(9, 500, 2500);
}

void loop()
{
  // Read and calculate temperature for sensorPin1
  int reading1 = analogRead(sensorPin1);
  float voltage1 = reading1 * 4.68 / 1024.0;
  float temperatureC1 = (voltage1 - 0.5) * 100;

  // Print the temperature for sensorPin1
  Serial.print("Room 3 temperature: ");
  Serial.print(temperatureC1);
  Serial.println(" degrees Celsius");

  delay(1000);
  
   if (temperatureC1 <=50.0) 
     {
   
    for (pos1 = 0; pos <= 0; pos1 += 1) {
      servo_9.write(pos);
      delay(15);
      pos=pos1;
    }}
  
  if (temperatureC1 >= 50.0) {
    // Move the servo from 0 to 90 degrees
    for (pos2 = 0; pos <= 90; pos2 += 1) {
      servo_9.write(pos2);
      delay(15); 
      pos=pos2;
    } }

     if (temperatureC1 >= 70.0 ) 
  {
    // Move the servo from 90 to 180 degrees
       for (pos3 = 90; pos <= 180; pos3 += 1) {
      servo_9.write(pos3);
      delay(15); 
      pos=pos3;
       }
     
     }   
}


  