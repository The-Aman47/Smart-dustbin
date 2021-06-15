#include <Servo.h>
#define trigPin 9
#define echoPin 10
Servo servo;
int sound =250;
void setup(){
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  servo.attach(9);
}
void loop() {
  // put your main code here, to run repeatedly:
long duration, distance;
digitalWrite(trigPin,LOW);
delay(2);
digitalWrite(trigPin,HIGH);
delay(10);
digitalWrite(trigPin,LOW);
duration = pulseIn(echoPin,HIGH);
distance = (duration/2)/29.1;
if(distance<30){
  Serial.println("the distance is less than 15");
  servo.write(120);
  delay(1500);
}
else{
  servo.write(0);
}
if(distance>60||distance<=0){
  Serial.println("The distance is more than 60");
}
else{
  Serial.print(distance);
  Serial.println("cm");
}
delay(500);
}
