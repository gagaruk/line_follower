#include <Arduino.h>

#define A1 7
#define A2 8
#define B1 5
#define B2 4
#define STBY 6
#define PWMA 9
#define PWMB 3

void forward(int);

void setup() {

  pinMode(STBY, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(B1, OUTPUT);
  pinMode(B2, OUTPUT);
  pinMode(PWMA, OUTPUT);
  pinMode(PWMB, OUTPUT);

}


void loop() {
  forward(200);
}

void forward(int speed){

  digitalWrite(STBY, HIGH);

  digitalWrite(A1, HIGH);
  digitalWrite(A2, LOW);
  analogWrite(PWMA, 200);

  digitalWrite(B1, HIGH);
  digitalWrite(B2, LOW);
  analogWrite(PWMB, 200);
}
