#include <Arduino.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

int sensorVals[8];
int sensArrayLen = sizeof(sensorVals) / sizeof(sensorVals[0]);

RF24 radio(9,10);
const byte address[][6] = {"00001", "00002"};
void setup(){
  Serial.begin(57600);

  radio.begin();
  radio.openWritingPipe(address[1]);
  radio.openReadingPipe(1,address[0]);
  radio.setChannel(76);
  radio.setDataRate(RF24_250KBPS);
  radio.setPALevel(RF24_PA_MAX);
}

void loop(){
    for(int i; i<sensArrayLen; i++){
        Serial.print("Sens");
        Serial.print(i);
        Serial.print(": ");
        Serial.print(sensorVals[i]);
        Serial.print("\t");
    }
    Serial.println();

}