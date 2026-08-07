const int bot1 = 1;
const int bot2 = 2;
const int led1 = 13;
const int led2 = 12;

// a função setup roda somente uma vez, ao ligar o arduino ou reset
void setup() {
  // configura o led interno como saida.]
  pinMode(bot1, INPUT);
  pinMode(bot2, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

// função "loop" == função "while"
void loop() {

  if (digitalRead(bot1) == HIGH){
    digitalWrite(led1, HIGH);
    delay(1000);
    digitalWrite(led1, LOW);
    delay(1000);

  }

  if (digitalRead(bot2) == HIGH){
    digitalWrite(led2, HIGH);
    delay(100);
    digitalWrite(led2, LOW);
    delay(100);

  }
    else (digitalWrite(led2, LOW));
}