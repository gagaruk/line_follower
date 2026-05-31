#include <Arduino.h>

#define mA1 7
#define mA2 8
#define mB1 5
#define mB2 4
#define STBY 6
#define PWMA 9
#define PWMB 3

#define SenD0 A0
#define SenD1 A1
#define SenD2 A2
#define SenD3 A3
#define SenD4 A4
#define SenD5 A5
#define SenD6 A6
#define SenD7 A7
#define IR 2

int sensorVals[8];

void forward(bool,bool,int);

void setup() {
  Serial.begin(115200);

  pinMode(STBY, OUTPUT);
  pinMode(mA1, OUTPUT);
  pinMode(mA2, OUTPUT);
  pinMode(mB1, OUTPUT);
  pinMode(mB2, OUTPUT);
  pinMode(PWMA, OUTPUT);
  pinMode(PWMB, OUTPUT);

  pinMode(SenD0, INPUT);
  pinMode(SenD1, INPUT);
  pinMode(SenD2, INPUT);
  pinMode(SenD3, INPUT);
  pinMode(SenD4, INPUT);
  pinMode(SenD5, INPUT);
  //A6 and A7 are input-only pins and require no pinMode decleration
  pinMode(IR, OUTPUT);
  digitalWrite(IR, HIGH);
}


void loop() {
  forward(false, false, 200);

  sensorVals[0] = analogRead(SenD0);
  sensorVals[1] = analogRead(SenD1);
  sensorVals[2] = analogRead(SenD2);
  sensorVals[3] = analogRead(SenD3);
  sensorVals[4] = analogRead(SenD4);
  sensorVals[5] = analogRead(SenD5);
  sensorVals[6] = analogRead(SenD6);
  sensorVals[7] = analogRead(SenD7);

  for( int i = 0; i < 8; i++){
    Serial.print("SensorVal");
    Serial.print(i);
    Serial.print(":");
    Serial.print(sensorVals[i]);
    Serial.print("\t");
  }
  Serial.println("");
  Serial.println("------------------------------------------------");
  Serial.println("");

  delay(500);
}

void forward(bool m1, bool m2, int speed){

  digitalWrite(STBY, HIGH);

  if(m1){
    digitalWrite(mA1, HIGH);
    digitalWrite(mA2, LOW);
    analogWrite(PWMA, speed);
  }
  else{
    digitalWrite(mA1, LOW);
    digitalWrite(mA2, LOW);
  }

  if(m2){
    digitalWrite(mB1, HIGH);
    digitalWrite(mB2, LOW);
    analogWrite(PWMB, speed);
  }
  else{
    digitalWrite(mB1, LOW);
    digitalWrite(mB2, LOW);
  }
}
