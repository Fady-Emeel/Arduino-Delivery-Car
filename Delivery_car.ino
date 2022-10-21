/*variables*/
int rm1=13;
int rm2=12;
int lm1=11;
int lm2=10;
int buzzer=9;
int arrElement = 0;
char arr[20];
char revMsg;
char B_read;
/*
f=>forward
b=>backward
r=>right
l=>left
s=>stop
h=>horn
x=>reverse steps
*/
void setup() 
{
  Serial.begin(9600);
  pinMode(rm1,OUTPUT);
  pinMode(rm2,OUTPUT);
  pinMode(lm1,OUTPUT);
  pinMode(lm2,OUTPUT);
  pinMode(buzzer,OUTPUT);
}

void loop() 
{
  if(Serial.available()>0)
  {
    B_read= Serial.read();
    mesgFunc(B_read);
  }

}

//functions
void stop_func(void)
{
  digitalWrite(rm1,LOW);
  digitalWrite(rm2,LOW);
  digitalWrite(lm1,LOW);
  digitalWrite(lm2,LOW);
  Serial.println("stop");
}
void forward(void)
{
  digitalWrite(rm1,HIGH);
  digitalWrite(rm2,LOW);
  digitalWrite(lm1,HIGH);
  digitalWrite(lm2,LOW);
  Serial.println("forward");
  delay(2000);
}
void backward(void)
{
  digitalWrite(rm1,LOW);
  digitalWrite(rm2,HIGH);
  digitalWrite(lm1,LOW);
  digitalWrite(lm2,HIGH);
  Serial.println("backward");
  delay(2000);
}
void right ()
{  
  digitalWrite(rm1,LOW);
  digitalWrite(rm2,LOW);
  digitalWrite(lm1,HIGH);
  digitalWrite(lm2,LOW);
  delay(3100);
  Serial.println("right");
}
void left ()
{
  digitalWrite(lm1,LOW);
  digitalWrite(lm2,LOW);
  digitalWrite(rm1,HIGH);
  digitalWrite(rm2,LOW);
  delay(3100);
  Serial.println("left");
}
void horn(void)
{
  digitalWrite(buzzer,HIGH);
  delay(180);
  digitalWrite(buzzer,LOW);
  Serial.println("horn");
}
void steps(char store)
{
  arr[arrElement]=store;
  arrElement++;
}
void reverseSteps()
{
  for(int j = arrElement-1 ; j>=0 ; j--)
  {
    revMsg = arr[j];
    if (revMsg=='f')   
    {
      backward();
      stop_func();
    }
    if (revMsg=='b')
    {
      forward();
      stop_func();
    }
    if (revMsg=='r')
    {
      digitalWrite(rm1,LOW);
      digitalWrite(rm2,LOW);
      digitalWrite(lm1,LOW);
      digitalWrite(lm2,HIGH);
      delay(3100);
      stop_func();
    }
    if (revMsg=='l')
    {
      digitalWrite(lm1,LOW);
      digitalWrite(lm2,LOW);
      digitalWrite(rm1,LOW);
      digitalWrite(rm2,HIGH);
      delay(3100);
      stop_func();
    }
    if (revMsg=='s')
    {
      stop_func();
    }
  }
  arrElement=0;
}

void mesgFunc(char msg)
{
  if (msg=='f')
  {
    forward();
    steps(msg);
    stop_func();
  }
  if (msg=='b')
  {
    backward();
    steps(msg);
    stop_func();
  }
  if (msg=='r')
  {
    right();
    steps(msg);
    stop_func();
  }
  if (msg=='l')
  {
    left();
    steps(msg);
    stop_func();
  }
  if (msg=='s')
  {
    stop_func();
  }
  if (msg=='h')
  {
    horn();
  }
  if (msg=='x')
  {
    reverseSteps();
  }
  
}
