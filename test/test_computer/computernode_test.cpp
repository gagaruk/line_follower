#include <Arduino.h>
#include <SPI.h>
#include <RF24.h>
#include <nRF24L01.h>

#define buttonPin 2

RF24 radio(9, 10);
const byte address[][6] = {"00001", "00002"};

boolean buttonState = false;

void setup(){
    pinMode(buttonPin, INPUT);

    Serial.begin(57600);
    while(!radio.begin()) {
    Serial.println("radio.begin() FAILED");
    }
    Serial.println("Module connection established");

    radio.openReadingPipe(1, address[0]);
    radio.openWritingPipe(address[1]);
    radio.setChannel(76);
    radio.setDataRate(RF24_250KBPS);
    radio.setPALevel(RF24_PA_MAX);
    
}

void loop() {
    delay(5);
    radio.startListening();
    if (radio.available()) {
        uint16_t receivedValue;
        radio.read(&receivedValue, sizeof(receivedValue));
        Serial.print("Data Received: ");
        Serial.println(receivedValue);
    } else {
        // This will print to tell us if the radio is just sitting idle
        static unsigned long lastPrint = 0;
        if (millis() - lastPrint > 2000) {
            Serial.println("Waiting for data...");
            lastPrint = millis();
        }
    }
    
    delay(5);
    Serial.println("Writing Mode");
    buttonState = digitalRead(buttonPin);
    Serial.println(buttonState);
    radio.stopListening();
    radio.write(&buttonState, sizeof(buttonState));


}