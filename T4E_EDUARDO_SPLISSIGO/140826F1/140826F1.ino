const int BOT1 = 1;
const int BOT2 = 2;
const int BOT3 = 3;

const int LED1 = 8;
const int LED2 = 9;
const int LED3 = 10;
const int LED4 = 11;

void setup() {
  pinMode(BOT1, INPUT);
  pinMode(BOT2, INPUT);
  pinMode(BOT3, INPUT);

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
}

void loop() {
  if(digitalRead(BOT1) && digitalRead(BOT2)){
    digitalWrite(LED1, HIGH);
  }
  else {
    digitalWrite(LED1, LOW);
  }
  if(digitalRead(BOT1) || digitalRead(BOT2)){
    digitalWrite(LED2, HIGH);
  }
  else {
    digitalWrite(LED2, LOW);
  }
  if(!digitalRead(BOT3)){
    digitalWrite(LED3, HIGH);
  }
  else {
    digitalWrite(LED3, LOW);
  }
}
