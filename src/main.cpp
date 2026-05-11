#include <Arduino.h>

#define A1 7
#define A2 8
#define B1 5
#define B2 4
#define STBY 6
#define PWMA 9
#define PWMB 3

#define pot A0
int potVal = 0;

void forward(bool,bool,int);

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
  potVal = analogRead(pot);

  forward(true, false, map(potVal, 0, 1023, 0, 220));
}

void forward(bool m1, bool m2, int speed){

  digitalWrite(STBY, HIGH);

  if(m1){
    digitalWrite(A1, HIGH);
    digitalWrite(A2, LOW);
    analogWrite(PWMA, speed);
  }

  if(m2){
    digitalWrite(A1, HIGH);
    digitalWrite(A2, LOW);
    analogWrite(PWMA, speed);
  }
}
