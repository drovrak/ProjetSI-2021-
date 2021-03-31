#define led 8
int echo= 6;
int trigger =7;
long lecture;
long cm;

void setup()
{ 
  
  pinMode(echo, INPUT);
  pinMode(trigger, OUTPUT);
   digitalWrite(trigger,LOW);
  Serial.begin(9600);
}

void loop()
{
   digitalWrite(trigger, HIGH);//
    delayMicroseconds(10);
    digitalWrite(trigger, LOW);
    lecture = pulseIn(echo,HIGH);
  cm= lecture/3333;
  if( cm <5){
  //arretter 1 des 2 moteurs 
  }
  
  Serial.print(" Distance en cm:");
  Serial.println(cm);
  delay(1000);
	
}
