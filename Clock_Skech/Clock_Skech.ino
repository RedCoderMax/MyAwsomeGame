#include <TimeLib.h>
int digit[] = {10, 13, 11, 12};
int segpin[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
int segs[10][9] = {
//{0, 1, 2, 3, 4, 5, 6, 7, 8}
  {0, 1, 0, 0, 0, 0, 0, 0, 1},
  {1, 1, 1, 1, 0, 1, 1, 0, 1},
  {2, 0, 1, 0, 0, 0, 0, 1, 1},
  {3, 0, 1, 0, 0, 1, 0, 0, 1},
  {4, 0, 0, 1, 0, 1, 1, 0, 1},
  {5, 0, 0, 0, 1, 1, 0, 0, 1},
  {6, 0, 0, 0, 1, 0, 0, 0, 1},
  {7, 1, 1, 0, 0, 1, 1, 0, 1},
  {8, 0, 0, 0, 0, 0, 0, 0, 1},
  {9, 0, 0, 0, 0, 1, 0, 0, 1}
};
#define GMT 19800
void setup()
{
  Serial.begin(9600);
  for (int i = 0; i <= 3; i++)
    pinMode(digit[i], OUTPUT);
  for (int i = 1; i <= 8; i++)
    pinMode(segpin[i], OUTPUT);

  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  setTime(1642088546 + GMT);
}
void loop()
{
  int s = second();
  int m = minute();
  int h = hour();
  h = button(h);
  h = h * 100;
  h = h + m;
  if (analogRead(A1) > 1000)
  Butt(h);
  disp(h);
  sec(s);
}
void sec(int s)
{
  if (s % 2 == 0)
    digitalWrite(9, 1);
  else
    digitalWrite(9, 0);
}
int button(int h)
{
  if (h > 12 & analogRead(A0) > 1000)
    h -= 12;
  else if (h == 0 & analogRead(A0) > 1000)
    h = 12;
  return h;
}
int Butt(int h)
{
  if (analogRead(A2) == 0)
    adjustTime(1);
  else if (analogRead(A3) == 0)
    adjustTime(50);
}
void disp(int n)
{
  int d;
  for(int i=3;i>=0;i--)
  {
    d = n % 10;
    n = n / 10;
    diginum(d, i);
  }
}
void display(int num)
{
  for (int i = 1; i <= 8; i++)
    digitalWrite(segpin[i], segs[num][i]);
}
void diginum(int d, int n)
{
  display(d);
  digitalWrite(digit[n], 1);
  display(d);
  digitalWrite(digit[n], 0);
}
