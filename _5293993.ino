#define LED 7
#define PIR 8
#define LIGHT A0
#define BUTTON 2
// Pin 13 has an LED connected on most Arduino boards.
// give it a name:


// the setup routine runs once when you press reset:
void setup() {
  // initialize the digital pin as an output.
  pinMode(LED, OUTPUT);
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  int val = digitalRead(PIR); //read state of the PIR
  int light = 0;
  light = analogRead(LIGHT);

  if (val == LOW) {
    Serial.println("No motion"); //if the value read is low, there was no motion
    digitalWrite(LED, LOW);    // turn the LED off by making the voltage LOW
    Serial.println(light);
    delay(1000); 
  }
  else {
    Serial.println("Motion!"); //if the value read was high, there was motion
    if(light < 150) {
      Serial.println(light);
      digitalWrite(LED, HIGH);   // turn the LED on (HIGH is the voltage level)
      delay(1000); 
    }
    
  }
}
