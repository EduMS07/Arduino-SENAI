
const int LED1 = 10;
const int BOT1 = 1;

bool ESTLED1 = 0;
bool ESTBOT1 = 0;
bool TRAVA = 0;

void setup() {

  pinMode(LED1, OUTPUT);
  pinMode(BOT1, INPUT);
}

void loop() {
  ESTBOT1 = digitalRead(BOT1);

  if((ESTBOT1 == 1) && (TRAVA == 0)){
    ESTLED1 = !ESTLED1;
    TRAVA = 1;
  }
  if((ESTBOT1 == 0) && (TRAVA == 1)){
    TRAVA = 0;
  }
digitalWrite(LED1, ESTLED1);
}
