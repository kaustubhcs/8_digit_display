void setup()
{
  Serial.begin(9600);
  sec = EEPROM.read(0);
  mins = EEPROM.read(1);
  hour = EEPROM.read(2);

  Serial.begin(9600);
  for (int i=0;i<70;i++)
  {
    pinMode(i,OUTPUT);
    digitalWrite(i,LOW);  
  }
  analogWrite(69,127); 
  pinMode(A0,OUTPUT);
}




void loop()
{ 

  for (long int i=0;i<2000;i+=1)
 {
 number(i);
 tone(A0,i);
 delay(1);
 }
  for (long int i=2000;i>0;i--)
 {
 number(i);
 tone(A0,i);
 delay(4);
 }
 
}

