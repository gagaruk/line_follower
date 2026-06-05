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

const byte sensorPins[9] = {A0, A1, A2, A3, A4, A5, A6, A7, 2};
const double sensorWeights[8] = {-4.1, -3.4, -2.2, -1.2, 1.2, 2.2, 3.4, 4.1};
int sensorVals[8], weightedSensorVals[8];


const byte address[][6] = {"00001", "00002"};
RF24 radio(10,9);
#define transmissonInterval 500 //ms
int prev_t=0;

double kp, kd, ki = 0.0;


void forward(bool,bool,int);
void radioComs();
void readSensorVals();
void calculateWeightedSensorVals();
double calculateError();

void setup() {
  Serial.begin(57600);

  pinMode(STBY, OUTPUT);
  pinMode(mA1, OUTPUT);
  pinMode(mA2, OUTPUT);
  pinMode(mB1, OUTPUT);
  pinMode(mB2, OUTPUT);
  pinMode(PWMA, OUTPUT);
  pinMode(PWMB, OUTPUT);

  for(int i=0; i<8; i++){
    pinMode(sensorPins[i], INPUT);
  }
 
  pinMode(sensorPins[8], OUTPUT);
  digitalWrite(sensorPins[8], HIGH);

  radio.begin();
  radio.openWritingPipe(address[0]);
  radio.openReadingPipe(1,address[1]);
  radio.setChannel(76);
  radio.setDataRate(RF24_250KBPS);
  radio.setPALevel(RF24_PA_MAX);
}


void loop() {
  forward(false, false, 200);
  readSensorVals();
  calculateWeightedSensorVals();
  double error = calculateError();
  radioComs();

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


void readSensorVals(){
  for(int i=0; i<8; i++){
    sensorVals[i] = analogRead(sensorPins[i]);
  }
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
}

void radioComs(){
  radio.stopListening();
  if(millis() - prev_t > transmissonInterval){
    radio.write(&sensorVals, sizeof(sensorVals));
    prev_t = millis();
  }
  
  radio.startListening();
  if(radio.available()){
    int pidConstants[3];
    radio.read(&pidConstants, sizeof(pidConstants));  
    Serial.print(pidConstants[0]);
    Serial.print(pidConstants[1]);
    Serial.println(pidConstants[2]);
  }
}


void calculateWeightedSensorVals(){
  for(int i = 0; i<8; i++){
    weightedSensorVals[i] = sensorVals[i]*sensorWeights[i];
  }

}

double calculateError(){
  double weightedSum, rawSum, error = 0;
  
  for(int i = 0; i < 8; i++){
    rawSum += sensorVals[i];
    weightedSum += weightedSensorVals[i];
  }
  error = weightedSum / rawSum;
  Serial.print("Error: ");
  Serial.println(error);
  return error;
}
