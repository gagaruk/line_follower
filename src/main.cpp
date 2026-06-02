#include <Arduino.h>
#include <SPI.h>
#include <RF24.h>
#include <nRF24L01.h>

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

const byte address[][6] = {"00001", "00002"};
RF24 radio(10,9);
#define transmissonInterval 500 //ms
int prev_t=0;

double pidConstants[3] = {0.0, 0.0, 0.0};


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

  radio.begin();
  radio.openWritingPipe(address[0]);
  radio.openReadingPipe(1,address[1]);
  radio.setChannel(76);
  radio.setDataRate(RF24_250KBPS);
  radio.setPALevel(RF24_PA_MAX);
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

  radio.stopListening();
  if(millis() - prev_t < transmissonInterval){
    radio.write(&sensorVals, sizeof(sensorVals));
    prev_t = millis();
  }else{
    prev_t=0;
  }

  radio.startListening();
  radio.read(&pidConstants, sizeof(pidConstants));

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
