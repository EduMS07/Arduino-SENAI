const int bot1 = 1;
const int bot2 = 2;
const int led1 = 13;
const int led2 = 12;
const int led3 = 11;
const int led4 = 10;


// a função setup roda somente uma vez, ao ligar o arduino ou reset
void setup() {
  // configura o led interno como saida.]
  pinMode(bot1, INPUT);
  pinMode(bot2, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
}

// função "loop" == função "while(true)"-(python)
void loop() {
 int vari2 = digitalRead(bot2);
 int vari1 = digitalRead(bot1);
  if (vari1 == HIGH){
    while(vari2 == LOW){
      vari2 = digitalRead(bot2);
      digitalWrite(led1, HIGH);
      delay(150);
      digitalWrite(led1, LOW);
      digitalWrite(led2, HIGH);
      delay(150);
      digitalWrite(led2, LOW);
      digitalWrite(led3, HIGH);
      delay(150);
      digitalWrite(led3, LOW);
      digitalWrite(led4, HIGH);
      delay(150);
      digitalWrite(led4, LOW);


    }
  }
  else   digitalWrite(led4, LOW);
}





