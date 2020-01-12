#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"
int msg[1];
RF24 radio(9,53);
const uint64_t pipe = 0xE8E8F0F0E1LL;

void setup(void)
{
  
Serial.begin(9600);


radio.begin();
radio.openReadingPipe(1,pipe);
radio.startListening();
pinMode(2, OUTPUT);
pinMode(3, OUTPUT);
pinMode(4, OUTPUT);
pinMode(5, OUTPUT);
pinMode(10,OUTPUT);
pinMode(11,OUTPUT);
pinMode(12,OUTPUT);
pinMode(13,OUTPUT);
}

void loop(void){
  msg[0]=0;
if (radio.available()){
bool done = false;
digitalWrite(11,HIGH);
digitalWrite(10,LOW);
digitalWrite(12,LOW);
digitalWrite(13,LOW);



while (!done){
 
done = radio.read(msg,1);
Serial.println(msg[0]);
if (msg[0] == 0){
  analogWrite(2, 0);
  analogWrite(3, 0);
  analogWrite(4, 0);
  analogWrite(5, 0);
  }
if (msg[0] == 1){
 analogWrite(2, 100);
  analogWrite(3, 0);
  analogWrite(4, 100);
  analogWrite(5, 0);
  
  }
if (msg[0] == 2){
  analogWrite(2, 0);
  analogWrite(3, 1000);
  analogWrite(4, 0);
  analogWrite(5, 1000);
  
if (msg[0] == 3){
 analogWrite(2, 500);
  analogWrite(3, 0);
  analogWrite(4, 0);
  analogWrite(5, 500);
 
  }
  if (msg[0] == 4){
 analogWrite(2, 0);
  analogWrite(3, 500);
  analogWrite(4, 500);
  analogWrite(5, 0);
  }

else{
  digitalWrite(11,LOW);
digitalWrite(10,LOW);
digitalWrite(13,HIGH);
digitalWrite(12,LOW);

}
}

//delay(700);
}}}


