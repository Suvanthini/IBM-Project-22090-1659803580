int e=3;
int temp=2;
void setup()
{
  Serial.begin(9600);
  pinMode(temp,OUTPUT);
  pinMode(e,INPUT);
  pinMode(12,OUTPUT);
}

void loop()
{
  //ultrasonic sensor
  digitalWrite(temp,LOW);
  digitalWrite(temp,HIGH);
  delayMicroseconds(10);
  digitalWrite(temp,LOW);
  float dur=pulseIn(e,HIGH);
  float distance=(dur*0.0343)/2;
  Serial.print("Distance is: ");
  Serial.println(dist);
  
  
    //LED ON
  if(dist>=105)
  {
    digitalWrite(8,HIGH);
    digitalWrite(7,HIGH);
  }
  
  //Buzzer For ultrasonic Sensor
  if(dist>=105)
  {
  for(int k=0;k<=30000;k=k+10)
  {
  tone(12,k);
  delay(3000);
  noTone(12);
  delay(3000);
  }
  }
  //Temperate Sensor
  double a=analogRead(A0);
  double t=(((a/1024)*5)-0.5)*100;
  Serial.print("Temp value: ");
  Serial.println(t);
  delay(3000);
  
  //LED ON
  if(t>=105)
  {
    digitalWrite(8,HIGH);
    digitalWrite(7,HIGH);
  }
  
  //Buzzer for Temperature Sensor
  if(t>=105)
  {
  for(int k=0;k<=30000;k=k+10)
  {
  tone(12,k);
  delay(3000);
  noTone(12);
  delay(3000);
  }
  }
  
  //LED OFF
  if(t<105)
  {
    digitalWrite(8,LOW);
    digitalWrite(7,LOw);
  }
}
