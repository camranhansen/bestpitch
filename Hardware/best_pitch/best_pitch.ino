#include <Romeo_m.h>
void setup(void)
{ 
     Romeo_m.Initialise();
     Serial.begin(115200); //Set Serial Baud
} 
void loop(void)
{ 
  char val;
  if(Serial.available()>0)
    {  
     val = Serial.read();
     }
      switch(val){
            case 'a'://Go forward
            Romeo_m.motorControl(Forward,200,Forward,200);
            break;
            case'b'://Go back
            Romeo_m.motorControl(Reverse,100,Reverse,100);
            break;
            case'c'://Turn left
            Romeo_m.motorControl(Forward,100,Reverse,100);
            break;
            case'd'://Turn right
            Romeo_m.motorControl(Reverse,200,Forward,100);
            break;
            case'e'://Stop 
            Romeo_m.motorStop();
            break;
            default: break;
            }
}







void setup(){
  Serial.begin(9600);
  pinMode(RedLedPin, OUTPUT);
  pinMode(GreenLedPin, OUTPUT);
}

void RightPitch(){
  digitalWrite(RedLedPin, LOW);   
  digitalWrite(GreenLedPin, HIGH);
}

void WrongPitch(){
  digitalWrite(RedLedPin, HIGH);   
  digitalWrite(GreenLedPin, LOW);
}

void loop(){
               
}


