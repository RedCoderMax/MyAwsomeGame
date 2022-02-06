int ledpin[] = {4,3,5,0,1,2};

void setup () 
{
  for(int i=0; i<=5; i++){ pinMode(ledpin[i],OUTPUT); }
}
void loop ()
{
    for(int i=0; i<=59; i++)
     {
      displayBinary(i); delay(1000);  
    }
}
void displayBinary(byte number)
{
  for(int i=0; i<=5; i++)
  {
    if(bitRead(number,i))
      digitalWrite(ledpin[i],HIGH);
    else
      digitalWrite(ledpin[i],LOW);  
  }
}
