#include "CustomStepper.h"
#include <SoftwareSerial.h>
// IR radar mapping by sdizdarevic
//using 28BYJ-48 stepper motor
 
SoftwareSerial pc(10, 11);

int sensorPin = A0;    // select the input pin for the potentiometer
  

 
CustomStepper motor(2, 3, 4, 5);
   


 /* distance {   10 ,   15 ,   20 ,   25 ,   30 ,   35 ,   40 ,   45 ,   50 ,    55 ,   60 ,   65 ,   70 ,   75 ,   80 ,   85 ,   90 }
    voltages   { 0.89 , 0.87 , 0.81 , 0.71 , 0.62 , 0.54 , 0.47 , 0.43 , 0.39 ,  0.34 , 0.32 , 0.29 , 0.28 , 0.25 , 0.24 , 0.23 , 0.21 } */
 
void setup() {
  // put your setup code here, to run once:
 
   // Open serial communications and wait for port to open:

 Serial.begin(57600); 
 pc.begin(4800);   // set the data rate for the SoftwareSerial port



motor.setRPM(12);  //set motor speed 
motor.setSPR(4075.7728395); //steps per rotation

//direction CW - clockwise or CCW counterclockwise


}

int provjeri(float n){
    if(n<0.21)return 80;
    if(n>0.89)return 1;
    if(n<=0.89 && n>0.87) return 10;
    if(n<=0.87 && n>0.81) return 15;
    if(n<=0.81 && n>0.71) return 20;
    if(n<=0.71 && n>0.62) return 25;
    if(n<=0.62 && n>0.54) return 30;
    if(n<=0.54 && n>0.47) return 35;
    if(n<=0.47 && n>0.43) return 40;
    if(n<=0.43 && n>0.39) return 45;
    if(n<=0.39 && n>0.34) return 50;
    if(n<=0.34 && n>0.32) return 55;
    if(n<=0.32 && n>0.29) return 60;
    if(n<=0.29 && n>0.28) return 65;
    if(n<=0.28 && n>0.25) return 70;
    if(n<=0.25 && n>0.24) return 75;
    if(n<=0.24 && n>0.23) return 80;
    if(n<=0.23 && n>0.21) return 80;
}

void loop() {
  // put your main code here, to run repeatedly:
    
        float a;
        int brojac=0;
        a =  analogRead(sensorPin);

        brojac++;
        if(brojac==36){
          brojac=0;
          //direction=1-direction;
          motor.setDirection(CW);
          }
          else {
            motor.setDirection(CCW);
            }
          
        int b=provjeri(a);
         
          pc.println(b); 
   
        delay(1000);
    
        motor.run();
}
