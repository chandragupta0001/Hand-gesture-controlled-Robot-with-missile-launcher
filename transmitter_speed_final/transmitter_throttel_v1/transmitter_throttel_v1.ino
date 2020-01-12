#include "I2Cdev.h"
#include "MPU6050.h"
#include "Wire.h"
#include <SPI.h>
#include "nRF24L01.h"
const uint64_t pipe = 0xE8E8F0F0E1LL;
#include "RF24.h"
MPU6050 accelgyro;

RF24 radio(9,10);
int msg[1];


int16_t ax, ay, az;
#define OUTPUT_READABLE_ACCELGYRO
void setup(){
           Serial.begin(9600);
           Serial.println("Initializing I2C devices...");
           
           radio.begin();
radio.openWritingPipe(pipe);
           
    accelgyro.initialize();
      Serial.println("Testing device connections...");
    Serial.println(accelgyro.testConnection() ? "MPU6050 connection successful" : "MPU6050 connection failed");
radio.stopListening();
pinMode(A0,INPUT);
pinMode(6,INPUT);
pinMode(7,INPUT);
    
}
void loop() {
 msg[0] =analogRead(A0)*0.25;
  
 //Serial.println((tht[0]));
 radio.write(msg,sizeof(msg));
  accelgyro.getAcceleration(&ax, &ay, &az);
  if((ax<7000 && ax>-7000) &&(ay<7000 && ay>-7000))
  
{Serial.println("stay");
msg[0]= 0;
radio.write(msg,1);
}
{
      if(ay>7000)
           {
            Serial.println("LEFT");
            msg[0]= 4;
              radio.write(msg,1);
            }

      if(ay<-7000){
             Serial.println("RIGHT");
             msg[0]= 3;
              radio.write(msg,1);
              }  
{
if(ax>7000)
{Serial.println("reverse");
 msg[0]= 2;
              radio.write(msg,1);}

if(ax<-7000){
  Serial.println("forward");
   msg[0]= 1;
              radio.write(msg,1);
}}}

if(digitalRead(6)== 1 && digitalRead(7)== 1)
{
  msg[0]= 1000;
  radio.write(msg,sizeof(msg));
  Serial.println(digitalRead(6));
}
}

