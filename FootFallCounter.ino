const int trigpin = 12;
const int echopin = 11;
int counter=0;
void setup()
{
    Serial.begin(9600);
}
float trigger()
{
  float duration;
  pinMode(trigpin, OUTPUT);
  digitalWrite(trigpin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigpin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigpin, LOW);
  pinMode(echopin, INPUT);
  duration = pulseIn(echopin, HIGH);
  return(duration);
}
void loop()
{
  long duration, inches, cm;
  duration = trigger();
  duration = duration/1000;
  long duration1 = .15/duration;
  long temp;
  temp = (duration1 - 331.4)/0.6;
  delay(5000);
  inches = duration / 74 /2;
  cm = duration / 29 /2;
  delay(100);
  if(inches < 6) //Checking for obstruction
    counter++; //Counter gets updated
  delay(1000);
}
