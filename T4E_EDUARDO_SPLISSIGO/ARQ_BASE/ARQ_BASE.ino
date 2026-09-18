/*
Projeto: Pisca LED
Instituição: SENAI Jaguariuna
Autor: Eduardo Splissigo
Data: 07/08/2026                  Rev.:0
*/

//Incluir Bibliotécas}

//Nomear os pinos
const int bot_1 = 1;
const int led_vermelho = 13;
const int led_amarelo = 12;
const int led_verde = 11;

//Declarar as variaveis globais

void setup() {
  pinMode(bot_1, INPUT);
  pinMode(led_vermelho, OUTPUT);
  pinMode(led_amarelo, OUTPUT);
  pinMode(led_verde, OUTPUT);

}

void loop() {
  digitalWrite(led_vermelho, HIGH);
  delay(500);
  digitalWrite(led_amarelo, HIGH);
  delay(500);
  digitalWrite(led_verde, HIGH);
  delay(500);
  digitalWrite(led_vermelho, LOW);
  digitalWrite(led_amarelo, LOW);
  digitalWrite(led_verde, LOW);
  delay(500);
}
