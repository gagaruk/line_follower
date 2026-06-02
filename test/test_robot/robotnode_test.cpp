#include <Arduino.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>
 
#define potPin A0
#define ledPin 2

#define dataInterval 1000 //miliseconds

int loopStart, count=0;
uint16_t potAvg;

RF24 radio(10,9);
const byte address[][6] = {"00001", "00002"};
boolean ledState = false;


void setup(){
  Serial.begin(57600);
  pinMode(potPin, INPUT);
  pinMode(ledPin, OUTPUT);

  delay(500);
  digitalWrite(ledPin, LOW);  
  loopStart = millis();
  Serial.println("Starting transmission");

  radio.begin();
  radio.openWritingPipe(address[0]);
  radio.openReadingPipe(1, address[1]);
  radio.setChannel(76);
  radio.setDataRate(RF24_250KBPS);
  radio.setPALevel(RF24_PA_MAX);
  
}

void loop() {
  delay(5);

  Serial.println("Loop start");
  
 
  radio.stopListening();
  Serial.println("Writing Mode");
  uint16_t potValue = analogRead(A0);
  Serial.print("Get sensor value: ");
  Serial.println(potValue);
  
  Serial.println("Attempting write...");
  radio.write(&potValue, sizeof(potValue), true); 
  Serial.println("Write complete");

  delay(5);
  Serial.println("Reading Mode");
  radio.startListening();
  if(radio.available()){
    while(radio.available()){
      radio.read(&ledState, sizeof(ledState));
    }
  }
  if(ledState){
    digitalWrite(ledPin, HIGH);
  }else{
    digitalWrite(ledPin,LOW);
  }

}