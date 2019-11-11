#include <Servo.h>
Servo myservo;

int OPEN_pos = 0;             ////set servo open angel
int CLOSE_pos = 90;           ////set servo close angel
int Food_Level = 10;          ////set food level in cm


int PIR = 2;
int trigPin = 11;
int echoPin = 12;
long duration, cm, inches;
void setup() {
  Serial.begin(9600);
  myservo.attach(9);
  pinMode(PIR, INPUT);
  pinMode(echoPin, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(8, OUTPUT);
}


void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  cm = (duration / 58);
  inches = (duration / 148);
  Serial.print(cm);
  Serial.println(" cm");

  if (cm > Food_Level) {
    myservo.write(OPEN_pos);
  }
  else if (cm <= Food_Level) {
    myservo.write(CLOSE_pos);
  }
  int PIRState = digitalRead(PIR);
  Serial.println(PIR);
  if (PIRState == 1) {
    digitalWrite(10, HIGH);
    digitalWrite(8, HIGH);
  }
  else {
    digitalWrite(10, LOW);
    digitalWrite(8, LOW);
  }
  delay(100);
}
