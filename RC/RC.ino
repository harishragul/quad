#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"

RF24 radio(8, 10);
const byte writeaddress[6] = "00001";

int data[5] = {0,0,0,0,0};

void setup()
{
  pinMode(digitalRead(2), INPUT);
  digitalWrite(digitalRead(2), HIGH);
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(writeaddress);
  radio.setPALevel(RF24_PA_HIGH);
  radio.stopListening();
}

void loop(){
    data[3]= analogRead(A1);//Yaw 
    data[1]= analogRead(A2);//Pitch
    data[0]= analogRead(A3);//Roll
    data[2]= analogRead(A0);//Throttle
    data[4]=digitalRead(2);
    radio.write(&data,sizeof(data));
    radio.stopListening();
    delay(2);
    
}
