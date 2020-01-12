#include <SPI.h>
#include "nRF24L01.h"
#include <Servo.h>
#include "RF24.h"
Servo myservo; 
int val[1];
RF24 radio(9,53);
const uint64_t pipe = 0xE8E8F0F0E1LL;
int LED1 = 3;
void setup(void)
{
  myservo.attach(7); 
Serial.begin(9600);


radio.begin();
radio.openReadingPipe(1,pipe);
radio.startListening();
pinMode(LED1, OUTPUT);

}

void loop(void){
  
if (radio.available()){
bool done = false;
while (!done){
 
done = radio.read(val,1);
Serial.println(val[0]);
int cal=val[0];
  myservo.write(cal); 
delay(100);
}}
else{Serial.println("No radio available");}}
