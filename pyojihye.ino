#include "pitches.h"

#define PIEZO 5
#define SWITCH 6
#define LED 7
#define PIR 8

#define LIGHT A0
#define HUMI A2

int temp=200;
int melody[] = {
  NOTE_E7, NOTE_E7, 0, NOTE_E7,
  0, NOTE_C7, NOTE_E7, 0,
  NOTE_G7, 0, 0,  0,
  NOTE_G6, 0, 0, 0
};

int tempo[] = {
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12
};
const int TEMP=1;
int dustPin = A4;
float dustVal = 0;
float dustDensity = 0;

int ledPower = 2;
int delayTime = 280;
int delayTime2 = 40;
float offTime = 9680;

int redPin = 11;
int greenPin = 10;
int bluePin = 9;
int incomingByte=0;

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(PIEZO,OUTPUT);
  pinMode(SWITCH,INPUT_PULLUP);
  pinMode(ledPower,OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  Always();
  FrontDoor();
  PushButton();
}

void FrontDoor(){
  int light = analogRead(LIGHT);
  int state=0;
  if (digitalRead(PIR) == LOW && state==1) {
//    Serial.println("No motion");
    digitalWrite(LED, LOW);
//    Serial.println(light);
    delay(2000); 
  }
  else if(digitalRead(PIR) == LOW && state==0){
    digitalWrite(LED, LOW);
  }
  else {
//    Serial.println("Motion!");
    if(light < 200) {
//      Serial.println(light);
      digitalWrite(LED, HIGH);
      delay(2000); 
      state=1;
    }
  }
}

void PushButton(){
  Serial.println("L");
  if(digitalRead(SWITCH)==LOW){
    int size = sizeof(melody) / sizeof(int);
    for (int thisNote = 0; thisNote < size; thisNote++) {
      int noteDuration = 1000 / tempo[thisNote];
      buzz(PIEZO, melody[thisNote], noteDuration);
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
      buzz(PIEZO, 0, noteDuration);
    }
  }
}


void buzz(int targetPin, long frequency, long length) {
  digitalWrite(13, HIGH);
  long delayValue = 1000000 / frequency / 2;
  long numCycles = frequency * length / 1000;
  for (long i = 0; i < numCycles; i++) { 
    digitalWrite(targetPin, HIGH);
    delayMicroseconds(delayValue);
    digitalWrite(targetPin, LOW);
    delayMicroseconds(delayValue);
  }
  digitalWrite(13, LOW);
}

void Always(){
  PM();
  if(Serial.available()>=0){
    incomingByte=Serial.read();
    if(incomingByte==1){ //"T"
        setColor(0, 255, 0); //green
        delay(5000);
        setColor(0,0,0);
     }
    if(incomingByte==0){ //"F"
      setColor(255, 0, 0); //red
      delay(5000);
      setColor(0,0,0);
    }
  }
}

void PM(){
  digitalWrite(ledPower, LOW); // power on the LED
  delayMicroseconds(delayTime);
  dustVal=analogRead(dustPin); // read the dust value via pin 5 on the sensor
  delayMicroseconds(delayTime2);
  digitalWrite(ledPower, HIGH); // turn the LED off
  delayMicroseconds(offTime);
  delay(3000);
  dustDensity = 0.17*(dustVal*0.0049)-0.1;
  Serial.println(dustDensity);
}

void setColor(int red, int green, int blue)
{
  #ifdef COMMON_ANODE
    red = 255 - red;
    green = 255 - green;
    blue = 255 - blue;
  #endif
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);  
}

