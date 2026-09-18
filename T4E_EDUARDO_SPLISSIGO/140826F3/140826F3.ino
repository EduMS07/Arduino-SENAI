const int ent1 = 1;
const int ent2 = 2;
const int saida = 10;

void setup() {
  pinMode(ent1, INPUT);
  pinMode(ent2, INPUT);
  pinMode(saida, OUTPUT);

}

void loop() {
  int estent1 = digitalRead(ent1);
  int estent2 = digitalRead(ent2);

  int result = (estent1 == estent2)? HIGH : LOW;

  digitalWrite(saida, result);

  delay (10);

}
