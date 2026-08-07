const int bot1 = 1;
const int led1 = 13;
const int led2 = 12;

// a função setup roda somente uma vez, ao ligar o arduino ou reset
void setup() {
  // configura o led interno como saida.]
  pinMode(bot1, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

// função "loop" == função "while"
void loop() {

  if (digitalRead(bot1) == HIGH){
    digitalWrite(led1, HIGH);
    delay(1000);
    digitalWrite(led1, LOW);
  }
    else digitalWrite(led1, LOW);
}