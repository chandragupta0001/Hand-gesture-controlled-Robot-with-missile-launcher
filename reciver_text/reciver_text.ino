#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"

RF24 radio(9,53);
const uint64_t pipe = 0xE8E8F0F0E1LL;
int LED1 = 3;
void setup(void)
{
Serial.begin(9600);
radio.begin();
radio.openReadingPipe(1,pipe);
radio.startListening();
pinMode(LED1, OUTPUT);}

void loop(void){
if (radio.available()){Serial.println("r");
bool done = false;
while (!done){
  char msg[32]={0};
done = radio.read(&msg,sizeof(msg));
Serial.println(msg);
if (msg[0] == 111){delay(10);digitalWrite(LED1, HIGH);}
else {digitalWrite(LED1, LOW);}
delay(1000);}}
else{Serial.println("No radio available");}}
