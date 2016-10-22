#include <SoftwareSerial.h>
#include "Arduino.h"
#include "DFRobotRomeoBLEMini.h"
DFRobotRomeoBLEMini myDFRobotRomeoBLEMini;
int RedLedPin = 2;
int GreenLedPin = 4;
SoftwareSerial BT(10, 11); 

int xpotPin = 0;  //set the port for x input设置模拟口0为X的信号输入端口
int ypotPin = 1;  //set the port for y input设置模拟口1为Y的信号输入端口 

int xval=0;    //set variable x,y value
int yval=0;    //设置x,y轴变量

void setup(){
  pinMode(RedLedPin, OUTPUT);
  pinMode(GreenLedPin, OUTPUT);
  Serial.begin(9600);
  BT.begin(9600);
}

void RightPitch(){
  digitalWrite(RedLedPin, LOW);   
  digitalWrite(GreenLedPin, HIGH);
  myDFRobotRomeoBLEMini.speed(0, 0);
}

void HighPitch(){
  digitalWrite(RedLedPin, HIGH);   
  digitalWrite(GreenLedPin, LOW);
  myDFRobotRomeoBLEMini.speed(150, 0); //extend for sharp

}

void LowPitch(){
  digitalWrite(RedLedPin, HIGH);   
  digitalWrite(GreenLedPin, LOW);
  myDFRobotRomeoBLEMini.speed(-150, 0); //shorten for flat

}



void loop()
{
  xval = analogRead(xpotPin);   //xval equals to the x value from port 2变量为从0信号口读取到的数值
  yval = analogRead(ypotPin);   //xval equals to the x value from port 1变量为从1信号口读取到的数值
   
  Serial.print("X=");      
  Serial.print(xval);
  Serial.print(",");
  Serial.print("  Y=");    
  Serial.print(yval);
  Serial.println(",");
  
if(yval>1000)
{
  HighPitch();
  Serial.print("right");
}
else if(yval<100)
{
  LowPitch();
  Serial.print("left");
}
else
{
  RightPitch();
  Serial.print("stay");
}
 
}
