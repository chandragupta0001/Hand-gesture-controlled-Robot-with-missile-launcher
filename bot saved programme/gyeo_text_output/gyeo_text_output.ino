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
    
}
void loop() {
  accelgyro.getAcceleration(&ax, &ay, &az);
  if((ax<2000 && ax>-2000) &&(ay<2000 && ay>-2000))
{Serial.println("stay");
msg[0]= 0;
radio.write(msg,1);
}
{
      if(ay>5000)
           {
            Serial.println("reverse");
            msg[0]= 1;
              radio.write(msg,1);
            }

      if(ay<-5000){
             Serial.println("forward");
             msg[0]= 2;
              radio.write(msg,1);
              }  
else{
if(ax>5000)
{Serial.println("left");
 msg[0]= 3;
              radio.write(msg,1);}

if(ax<-5000){
  Serial.println("right");
   msg[0]= 4;
              radio.write(msg,1);
}}}
  
}

