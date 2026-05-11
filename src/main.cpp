#include <Arduino.h>

#define A1PIN 7
#define A2PIN 8
#define B1PIN 5
#define B2PIN 4
#define STBY 6
#define PWMA 9
#define PWMB 3

void forward(int);

void setup() {

  pinMode(STBY, OUTPUT);
  pinMode(A1PIN, OUTPUT);
  pinMode(A2PIN, OUTPUT);
  pinMode(B1PIN, OUTPUT);
  pinMode(B2PIN, OUTPUT);
  pinMode(PWMA, OUTPUT);
  pinMode(PWMB, OUTPUT);

}


void loop() {
  digitalWrite(A1PIN, HIGH);
  digitalWrite(A2PIN, HIGH);
  analogWrite(PWMA, 200);

  digitalWrite(B1PIN, HIGH);
  digitalWrite(B2PIN, HIGH);
  analogWrite(PWMB, 200);
}

void forward(int speed){

  digitalWrite(STBY, HIGH);

  digitalWrite(A1PIN, HIGH);
  digitalWrite(A2PIN, HIGH);
  analogWrite(PWMA, 200);

  digitalWrite(B1PIN, HIGH);
  digitalWrite(B2PIN, HIGH);
  analogWrite(PWMB, 200);
}
