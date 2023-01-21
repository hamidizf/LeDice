#include <Arduino.h>
#define Sensor1 8 //define sensor1 on pin D8
#define Sensor2 9 //define sensor2 on pin D9
#define Dice1_Light1 3 //define the first light for the first dice on pin D3
#define Dice1_Light6 2 //define the 6th lights for the first dice on pin D2
#define Dice1_Light23 5 //define the 2nd and 3rd lights for the first dice on pin D5
#define Dice1_Light45 4 //define the 4th and 5th lights for the first dice on pin D4
#define Dice2_Light6 A5 //define the 6th lights for the second dice on pin A5
#define Dice2_Light23 A4 //define the 2nd and 3rd lights for the second dice on pin A4
#define Dice2_Light45 A3 //define the 4th and 5th lights for the second dice on pin A3
#define Dice2_Light1 A2 //define the 1st light for the second dice on pin A2
int Dice1_number=0; //initialize a random number to be displayed on the first dice
int Dice2_number=0; //initialize a random number to be displayed on the second dice  
int animation1_number=0; //initialize a random number for the animation of the lights
int animation2_number=0; //initialize a random number for the animation of the lights  
int d=1; //define a variable to be used in the animation function
unsigned long previousTime1 = 0; //initialize the previous time as 0 it will be updated during the program
unsigned long previousTime2 = 0; //initialize the previous time as 0 it will be updated during the program
const unsigned long Time = 6000; //define a time in miliseconds so that LEDs go off if this amount of time is passed

void setup() {
  TurnOffLights1(); //turn all lights off at the begining of the program
  TurnOffLights2();
  for (int i=0; i <= 2; i++){
    digitalWrite(Dice1_Light1,HIGH);
    digitalWrite(Dice1_Light23,HIGH);
    digitalWrite(Dice2_Light1,HIGH);
    digitalWrite(Dice2_Light23,HIGH);
    delay(150);
      digitalWrite(Dice1_Light1,LOW);
    digitalWrite(Dice1_Light23,LOW);
    digitalWrite(Dice2_Light1,LOW);
    digitalWrite(Dice2_Light23,LOW);
    delay(120);
     digitalWrite(Dice1_Light1,HIGH);
     digitalWrite(Dice1_Light6,HIGH);
     digitalWrite(Dice2_Light1,HIGH);
     digitalWrite(Dice2_Light6,HIGH);
     delay(150);
      digitalWrite(Dice1_Light1,LOW);
     digitalWrite(Dice1_Light6,LOW);
     digitalWrite(Dice2_Light1,LOW);
     digitalWrite(Dice2_Light6,LOW);
     delay(120);
     digitalWrite(Dice1_Light1,HIGH);
     digitalWrite(Dice1_Light45,HIGH);
     digitalWrite(Dice2_Light1,HIGH);
     digitalWrite(Dice2_Light45,HIGH);
     delay(150);
     digitalWrite(Dice1_Light1,LOW);
     digitalWrite(Dice1_Light45,LOW);
     digitalWrite(Dice2_Light1,LOW);
     digitalWrite(Dice2_Light45,LOW);
 delay(120);
    
  }
  // Set up code, to run once:
  Serial.begin(9600);// baud rate 
  pinMode(Sensor1, INPUT); //deine sensor's pin as input
  pinMode(Sensor2, INPUT); //deine sensor's pin as input
  pinMode(Dice1_Light1, OUTPUT);//deine LEDs' pins as output
  pinMode(Dice1_Light23, OUTPUT);
  pinMode(Dice1_Light45, OUTPUT);
  pinMode(Dice1_Light6, OUTPUT);
  pinMode(Dice2_Light1, OUTPUT);//deine LEDs' pins as output
  pinMode(Dice2_Light23, OUTPUT);
  pinMode(Dice2_Light45, OUTPUT);
  pinMode(Dice2_Light6, OUTPUT);
  TurnOffLights1(); //turn all lights off at the begining of the program
  TurnOffLights2();
  
}
void TurnOffLights1(){ //this function is responsible for turning the LEDs on the first dice off
    digitalWrite(Dice1_Light1,LOW);
    digitalWrite(Dice1_Light6,LOW);
    digitalWrite(Dice1_Light23,LOW);
    digitalWrite(Dice1_Light45,LOW);
}
void TurnOffLights2(){//this function is responsible for turning the LEDs on the second dice off
  digitalWrite(Dice2_Light1,LOW);
  digitalWrite(Dice2_Light6,LOW);
  digitalWrite(Dice2_Light23,LOW);
  digitalWrite(Dice2_Light45,LOW);
}
void Animation1(){ //this function is in charge of the animation on the lights of the first dice before the actual number appears on the dice
    if (animation1_number==1){ //if the animation1_number is equal to 1
    digitalWrite(Dice1_Light1,HIGH);//light up the light in the middle of the dice 
    delay(100); //pause for 100 milisecond
    digitalWrite(Dice1_Light1,LOW); //turn the light off
  }
  else if(animation1_number==2){ //same path is followed for the rest of the conditional
    digitalWrite(Dice1_Light23,HIGH);
    delay(100);
    digitalWrite(Dice1_Light23,LOW);
  }
  else if(animation1_number==3){
    digitalWrite(Dice1_Light45,HIGH);
    delay(100);
    digitalWrite(Dice1_Light45,LOW);
  }
  else{
    digitalWrite(Dice1_Light6,HIGH);
    delay(100);
    digitalWrite(Dice1_Light6,LOW);
    
  }
}
  void Animation2(){ //this function is in charge of the animation on the lights of the second dice before the actual number appears on the dice
    if (animation2_number==1){ //if the animation2_number is equal to 1
    digitalWrite(Dice2_Light1,HIGH);//light up the light in the middle of the dice 
    delay(100); //pause for 100 milisecond
    digitalWrite(Dice2_Light1,LOW); //turn the light off
  }
  else if(animation2_number==2){ //same path is followed for the rest of the conditional
    digitalWrite(Dice2_Light23,HIGH);
    delay(100);
    digitalWrite(Dice2_Light23,LOW);
  }
  else if(animation2_number==3){
    digitalWrite(Dice2_Light45,HIGH);
    delay(100);
    digitalWrite(Dice2_Light45,LOW);
  }
  else{
    digitalWrite(Dice2_Light6,HIGH);
    delay(100);
    digitalWrite(Dice2_Light6,LOW);
    
  }
}
void TurnOnLights1(){ //this function is in charge of turning random LEDs on for the first dice
  if (Dice1_number==1){ //if the Dice1_number is 1, the LED in the middle will light up
    digitalWrite(Dice1_Light1,HIGH);
    unsigned long currentTime1 = millis(); //measure the current time 
    previousTime1 = currentTime1; //update the previous time so that LEDs do not go off sonner than expected 
  }
  else if(Dice1_number==2){ //if the Dice1_number is 2, the LED in the diagonal will light up
    digitalWrite(Dice1_Light23,HIGH);
    unsigned long currentTime1 = millis(); //measure the current time 
    previousTime1 = currentTime1;//update the previous time so that LEDs do not go off sonner than expected 
  }
  else if(Dice1_number==3){// same path is followed for the rest of the conditional
    digitalWrite(Dice1_Light1,HIGH);
    digitalWrite(Dice1_Light23,HIGH);
    unsigned long currentTime1 = millis(); 
    previousTime1 = currentTime1;
  }
  else if (Dice1_number==4){
    digitalWrite(Dice1_Light23,HIGH);
    digitalWrite(Dice1_Light45,HIGH);
    unsigned long currentTime1 = millis(); 
    previousTime1 = currentTime1;
  }
  else if(Dice1_number==5){
    digitalWrite(Dice1_Light23,HIGH);
    digitalWrite(Dice1_Light1,HIGH);
    digitalWrite(Dice1_Light45,HIGH);
    unsigned long currentTime1 = millis(); 
    previousTime1 = currentTime1;
  }
  else{
    digitalWrite(Dice1_Light6,HIGH);
    digitalWrite(Dice1_Light23,HIGH);
    digitalWrite(Dice1_Light45,HIGH);
    unsigned long currentTime1 = millis(); 
    previousTime1 = currentTime1;
  }
}

void TurnOnLights2(){ //this function is in charge of turning random LEDs on for the second dice
  if (Dice2_number==1){ //if the Dice2_number is 1, the LED in the middle will light up
    digitalWrite(Dice2_Light1,HIGH);
    unsigned long currentTime2 = millis(); //measure the current time 
    previousTime2 = currentTime2; //update the previous time so that LEDs do not go off sonner than expected 
  }
  else if(Dice2_number==2){ //if the Dice2_number is 2, the LED in the diagonal will light up
    digitalWrite(Dice2_Light23,HIGH);
    unsigned long currentTime2 = millis(); //measure the current time 
    previousTime2 = currentTime2;//update the previous time so that LEDs do not go off sonner than expected 
  }
  else if(Dice2_number==3){// same path is followed for the rest of the conditional
    digitalWrite(Dice2_Light1,HIGH);
    digitalWrite(Dice2_Light23,HIGH);
    unsigned long currentTime2 = millis(); 
    previousTime2 = currentTime2;
  }
  else if (Dice2_number==4){
    digitalWrite(Dice2_Light23,HIGH);
    digitalWrite(Dice2_Light45,HIGH);
    unsigned long currentTime2 = millis(); 
    previousTime2 = currentTime2;
  }
  else if(Dice2_number==5){
    digitalWrite(Dice2_Light23,HIGH);
    digitalWrite(Dice2_Light1,HIGH);
    digitalWrite(Dice2_Light45,HIGH);
    unsigned long currentTime2 = millis(); 
    previousTime2 = currentTime2;
  }
  else{
    digitalWrite(Dice2_Light6,HIGH);
    digitalWrite(Dice2_Light23,HIGH);
    digitalWrite(Dice2_Light45,HIGH);
    unsigned long currentTime2 = millis(); 
    previousTime2 = currentTime2;
  }
}





void loop() { 
 Dice2_number= rand() % 6 + 1; //find a random number between 1-6 to be showed on the second dice
    Dice1_number= rand() % 6 + 1; //find a random number between 1-6 to be showed on the first dice
 animation1_number= rand() % 4 + 1; //find a random number between 1-4
animation2_number= rand() % 4 + 1; //find a random number between 1-4
  int SensorValue1 = digitalRead(Sensor1); //collect the data from the sensor1
  delay(1);
  int SensorValue2 = digitalRead(Sensor2); //collect the data from the sensor2
  Serial.print(SensorValue1); //to check the sensor's value on Serial monitor
  delay(1);

    



  unsigned long currentTime1 = millis(); 
  unsigned long currentTime2 = millis(); 
   if (currentTime1 - previousTime1 >=Time){ //if the LEDs have been on for 6 executive seconds  on the first dice
     TurnOffLights1(); //turn the lights off
     previousTime1 = currentTime1; //update the previous time
 }
 if (currentTime2 - previousTime2 >=Time){ //if the LEDs have been on for 6 executive seconds on the second dice 
     TurnOffLights2(); //turn the lights off
     previousTime2 = currentTime2; //update the previous time
 }
if (SensorValue1==0 ){//if the hand of the user is detected by the first sensor use both dices
    TurnOffLights2(); //turn all the lights from the previous round off
    TurnOffLights1();
    delay(170); //pause for 170 milisecond

    for (int i=0; i <= 7; i++){ //run this for loop 8 times
      
      animation2_number=animation2_number+d; //add one or negative one to that number to make sure the same number is not appeard two executive times
      
      animation1_number=animation2_number+d; //add one or negative one to that number to make sure the same number is not appeard two executive times
      Animation1();//run the animation function on the first dice
      Animation2();//run the animation function on the second dice

      d=-d;  //d will become negative for the next iteration
    }
    
    delay(150);
    TurnOnLights2();//turn on the lights based on the dice random number on the second dice
    TurnOnLights1();//turn on the lights based on the dice random number on the first dice

    
  }
  else if (SensorValue2==0){//if the hand of the user is detected by the second sensor use one dice only
    TurnOffLights2(); //turn all the lights from the previous round off
    delay(170); //pause for 170 milisecond

    for (int i=0; i <= 7; i++){ //run this for loop 8 times
      
      animation2_number=animation2_number+d; //add one or negative one to that number to make sure the same number is not appeard two executive times
      Animation2();//run the animation function

      d=-d;  //d will become negative for the next iteration
    }
    
    delay(150);
    TurnOnLights2();//turn on the lights based on n

    
  }







}
