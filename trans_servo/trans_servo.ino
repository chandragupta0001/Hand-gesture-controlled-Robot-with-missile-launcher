#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"
 int val[1];
RF24 radio(9,10);
int potpin = 0; 
const uint64_t pipe = 0xE8E8F0F0E1LL;
int SW1 = 7;
void setup(void){
Serial.begin(9600);
radio.begin();

radio.openWritingPipe(pipe);}
void loop(void){
val[0] = analogRead(potpin); 
Serial.println(val[0]);  
val[0] = map(val[0], 0, 1023, 0, 180); 
radio.write(val,1);}
