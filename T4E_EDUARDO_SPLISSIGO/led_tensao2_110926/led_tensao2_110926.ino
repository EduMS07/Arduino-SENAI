
#define led1 13
#define led2 12
#define led3 11
#define led4 10
#define led5 9
#define led6 8
#define led7 7
#define led8 6
#define led9 5
#define ent1 A0

int valor_digital = 0;
float tensao;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(led7, OUTPUT);
  pinMode(led8, OUTPUT);
  pinMode(led9, OUTPUT);
  
  Serial.begin(9600);



}

void loop() {

  valor_digital = analogRead(ent1);
  tensao = valor_digital * (5.0 / 1023);
  Serial.print(tensao);
   Serial.print("V  Dgital = ");
  Serial.println(valor_digital);
  

  if((tensao >= 0.5) && (tensao < 1.0))
    digitalWrite(led1, HIGH);
  else
    digitalWrite(led1, LOW);


  if((tensao >= 1.0) && (tensao < 1.5))
    digitalWrite(led2, HIGH);
  else
    digitalWrite(led2, LOW);


  if((tensao >= 1.5) && (tensao < 2.0))
    digitalWrite(led3, HIGH);
  else
    digitalWrite(led3, LOW);


  if((tensao >= 2.0) && (tensao < 2.5))
    digitalWrite(led4, HIGH);
  else
    digitalWrite(led4, LOW);


  if((tensao >= 2.5) && (tensao < 3.0))
    digitalWrite(led5, HIGH);
  else
    digitalWrite(led5, LOW);


  if((tensao >= 3.0) && (tensao < 3.5))
    digitalWrite(led6, HIGH);
  else
    digitalWrite(led6, LOW);


  if((tensao >= 3.5) && (tensao < 4.0))
    digitalWrite(led7, HIGH);
  else
    digitalWrite(led7, LOW);


  if((tensao >= 4.0) && (tensao < 4.5))
    digitalWrite(led8, HIGH);
  else
    digitalWrite(led8, LOW);


  if(tensao >= 4.5)
    digitalWrite(led9, HIGH);
  else
    digitalWrite(led9, LOW);

}
