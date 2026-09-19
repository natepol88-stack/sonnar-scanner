#include <Servo.h>

Servo myservo;

int trig = 10;
int echo = 11;

long duration;
float distance;

int buzzer = 9;
int r = 4;
int g = 5;
int b = 6;

void setup() {
  // put your setup code here, to run once:
  myservo.attach(3);
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(r, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(b, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int deg = 0; deg <= 180; deg++) {
    myservo.write(deg);
    delay(10);

    digitalWrite(trig, LOW);
    delay(10);
    digitalWrite(trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig, LOW);
    duration = pulseIn(echo, HIGH);
    distance = duration * 0.017;

    if (distance > 40) {
      digitalWrite(g, HIGH);
      digitalWrite(r, LOW);
      digitalWrite(b, LOW);
      noTone(buzzer);
    } else if (distance > 10) {
      digitalWrite(r, HIGH);
      digitalWrite(g, HIGH);
      digitalWrite(b, LOW);
      tone(buzzer, 100);
    } else {
      digitalWrite(r, HIGH);
      digitalWrite(g, LOW);
      digitalWrite(b, LOW);
      tone(buzzer, 500);
    }
  }
  for (int deg = 180; deg >= 0; deg--) {
    myservo.write(deg);
    delay(10);

    digitalWrite(trig, LOW);
    delay(10);
    digitalWrite(trig, HIGH);
    delayMicroseconds(10);
    digitalWrite(trig, LOW);
    duration = pulseIn(echo, HIGH);
    distance = duration * 0.017;

    if (distance > 40) {
      digitalWrite(g, HIGH);
      digitalWrite(r, LOW);
      digitalWrite(b, LOW);
      noTone(buzzer);
    } else if (distance > 10) {
      digitalWrite(r, HIGH);
      digitalWrite(g, HIGH);
      digitalWrite(b, LOW);
      tone(buzzer, 100);
    } else {
      digitalWrite(r, HIGH);
      digitalWrite(g, LOW);
      digitalWrite(b, LOW);
      tone(buzzer, 500);
    }
  }
}
