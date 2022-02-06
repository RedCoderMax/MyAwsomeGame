#include <Servo.h>
Servo myservo;  
int pos = 0;
void setup() {
  myservo.attach(9);
  pinMode(13,HIGH);
  pinMode(12,HIGH);
  pinMode(11,HIGH);
}

void loop() {
  digitalWrite(13,HIGH);
  delay(150);
  digitalWrite(13,LOW);
  
  digitalWrite(12,HIGH);
  delay(150);
  digitalWrite(12,LOW);
  
  digitalWrite(11,HIGH);
  delay(150);
  digitalWrite(11,LOW);

  delay(150);
  for (pos = 0; pos <= 180; pos += 1) {
    myservo.write(pos);
    digitalWrite(12,HIGH);
    delay(15);
    digitalWrite(12,LOW);                   
  }
  for (pos = 180; pos >= 0; pos -= 1) { 
    myservo.write(pos);              
    digitalWrite(11,HIGH);
    delay(15);
    digitalWrite(11,LOW);                      
  }
}
