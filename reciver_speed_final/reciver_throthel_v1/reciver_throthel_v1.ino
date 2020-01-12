#include <SPI.h>
#include "nRF24L01.h"
#include "RF24.h"
int msg[1];
//int tht[1];
RF24 radio(9,53);
const uint64_t pipe = 0xE8E8F0F0E1LL;
int v;
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
pinMode(10, OUTPUT);
pinMode(11, OUTPUT);
pinMode(12, OUTPUT);
pinMode(13, OUTPUT);
}

void loop(void){
  
  
if (radio.available()){
bool done = false;
while (!done){
 //Serial.println(msg[0][0]);
done = radio.read(msg,sizeof(msg));
//radio.read(tht,sizeof (tht));
digitalWrite(10,LOW);
digitalWrite(11,LOW);
digitalWrite(12,HIGH);
digitalWrite(13,LOW);

if(msg[0]>4 && msg[0]<260){
v=msg[0];
}
//Serial.println(msg[0][0]);
//Ser//ial.println(tht[0]);
Serial.println(v);
if (msg[0] == 0){
  analogWrite(2, 0);
  analogWrite(3, 0);
  analogWrite(4, 0);
  analogWrite(5, 0);
  }
if (msg[0] == 1){
  analogWrite(2, 0);
  analogWrite(3,v-50);
  analogWrite(4, 0);
  analogWrite(5,v-50 );
  }
if (msg[0] == 2){
  analogWrite(2,v-50);
  analogWrite(3, 0);
  analogWrite(4, v-50);
  analogWrite(5, 0);
  }
if (msg[0] == 3){
  analogWrite(2,v);
  analogWrite(3, 0);
  analogWrite(4, 0);
  analogWrite(5, v);
  }
  if (msg[0] == 4){
  analogWrite(2, 0);
  analogWrite(3, v);
  analogWrite(4, v);
  analogWrite(5, 0);
  }
if(msg[0] == 1000)
{digitalWrite(10,LOW);
digitalWrite(11,HIGH);

delay(3000);
digitalWrite(11,LOW);
msg[0]=0;

}

delay(100);
}}

else{
  
   analogWrite(2, 0);
  analogWrite(3, 0);
  analogWrite(4, 0);
  analogWrite(5, 0);
  Serial.println("no signal");
  //
//digitalWrite(12,LOW);
//digitalWrite(13,LOW);
   }
}
