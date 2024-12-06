#include <Servo.h>
#include <math.h>

Servo botServo;
Servo topServo;
const int trigPin = 4;
const int echoPin = 5;

float duration, distance;

float ping(){
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration*.0343)/2;
  Serial.print("Distance: ");
  Serial.println(distance);
  return distance;
}

void lerpTop(int start, int end, float duration, float timeStep){
  for(float i = 0.0; i <= 1.0; i+= (timeStep/duration)){
    topServo.write((abs(end-start)*i)+start);
    delay(timeStep*1000);
  }
}

void lerpBot(int start, int end, float duration, float timeStep){
  for(float i = 0.0; i <= 1.0; i+= (timeStep/duration)){
    botServo.write((abs(end-start)*i)+start);
    delay(timeStep*1000);
  }
}

void RadarScan(){
  for(float i = 0.0; i <= 1.0; i+= (timeStep/duration)){
    botServo.write((abs(end-start)*i)+start);
    for(float i = 0.0; i <= 1.0; i+= (timeStep/duration)){
      botServo.write((abs(end-start)*i)+start);
      delay(timeStep*1000);
    }
  }
}


void setup(){
  botServo.attach(2);
  topServo.attach(3);

  botServo.write(50);
  topServo.write(100);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop(){
  
  lerpBot(50,100,8.0, 0.01);
  lerpTop(100,50,8.0, 0.01);
  delay(1000);
}
