// lampu tepuk
const int pinlampu = 3;
const int pinanalog = A0;
const int ambangrerata = 15;
const int jumpSempel = 128;
const int nilaidasar = 514;

int totalisyarat = 0;
boolean statuslampu = false;

void setup() {
  Serial.begin (9600);
  pinMode (pinlampu, OUTPUT);
}

void loop() {
 int nilaianalog;
 totalisyarat = 0;
 for (int j = 1; j<=jumpSempel; j++)
 {
  nilaianalog = analogRead (pinanalog);

  int isyarat = abs (nilaianalog - nilaidasar);
  totalisyarat += isyarat;
 }



int rerataisyarat = totalisyarat / jumpSempel;
Serial.print("nilai analog : ");
Serial.print(nilaianalog);
Serial.print("rerata : " );
Serial.println(rerataisyarat);

if(rerataisyarat >= ambangrerata)
  {
  statuslampu = not statuslampu;
  digitalWrite (pinlampu, statuslampu);
  delay(2000);
  }
}
