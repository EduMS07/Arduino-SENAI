#define anl A0
#define limiar 1.5
#define led 8

int leitura  = 0;
float VLDR;
float resLDR;

void setup() {
  pinMode(led, OUTPUT);
  Serial.begin(9600);
  delay(100);
}

void loop() {
  leitura = analogRead(anl);
  VLDR = leitura * (5.0 / 1023);
  Serial.print("Leitura sensor LDR = ");
  Serial.println(VLDR);

  if(VLDR > limiar)
    digitalWrite(led, HIGH);
  else
    digitalWrite(led, LOW);
    delay(500);
  
}
