int Status = 12;
int sensor = 13;
void setup() {

Serial.begin(9600);
pinMode (sensor, INPUT);
pinMode (Status, OUTPUT);
}

void loop() {
  long state = digitalRead(sensor);
  if(state == HIGH )
  {
    digitalWrite(Status, HIGH );
    Serial.println("Motion Detected");
  }
  else 
  {
    digitalWrite(Status,LOW);
    Serial.println("Motion Absent");
    delay(1000);
  }

}
