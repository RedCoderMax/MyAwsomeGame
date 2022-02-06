#define A 5000

void setup() 
{
  pinMode(0,INPUT);
  pinMode(12,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(5,OUTPUT);
}
void loop() 
{
  digitalWrite(12,HIGH);
  delay(A);
  digitalWrite(12,LOW);
  digitalWrite(11,HIGH);
  delay(A);
  digitalWrite(11,LOW);
  digitalWrite(10,HIGH);
  delay(A);
  digitalWrite(10,LOW);
  digitalWrite(9,HIGH);
  delay(A);
  digitalWrite(9,LOW);
  digitalWrite(8,HIGH);
  delay(A);
  digitalWrite(8,LOW);
  digitalWrite(7,HIGH);
  delay(A);
  digitalWrite(7,LOW);
  digitalWrite(6,HIGH);
  delay(A);
  digitalWrite(6,LOW);
  digitalWrite(5,HIGH);
  delay(A);
  digitalWrite(5,LOW);
}
