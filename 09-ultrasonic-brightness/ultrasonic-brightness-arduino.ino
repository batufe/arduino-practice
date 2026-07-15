float y = 0;

void setup() {
  pinMode(3, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, INPUT);
  
  Serial.begin(9600);
}



void loop() {

  digitalWrite(9, LOW);
  delayMicroseconds(2);
  digitalWrite(9, HIGH);
  delayMicroseconds(10);
  digitalWrite(9, LOW);

  long sure = pulseIn(10, HIGH);
  if (sure > 2000 || sure == 0) {sure =2000;}
  float t = map(sure, 300, 2000, 255, 0);
  t = constrain(t, 0, 255);
  y = (y*0.5 + t*0.5);
  analogWrite(3, y);

 
 

}
