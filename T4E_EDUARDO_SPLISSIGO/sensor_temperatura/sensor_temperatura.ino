/*
Projeto: Serial + entrada analogica
instituição: senai jaguariuna
*/

#define LEDR 13
#define LEDY 12
#define LEDG 11
#define Pot A0
//#define Modo_Debug

int valor_digital = 0;
float valor_tensao = 0;
float valor_temp = 0;

void setup() {

  pinMode(LEDR, OUTPUT);
  pinMode(LEDY, OUTPUT);
  pinMode(LEDG, OUTPUT); //pino config saida
  Serial.begin(9600); // inicializa a comunicação serial
 // Serial.print("Elestricista de Manuteção Eletroeletrônica"); // Envia dados pela porta serial

}

void loop() {
 /*
  #ifdef Modo_Debug
  digitalWrite(LED1, HIGH);

  Serial.println("LED Ligado"); // Envia dados pela porta serial
  delay(500);

  digitalWrite(LED1, LOW);

  Serial.println("LED Desligado"); // Envia dados pela porta serial
  delay(500);  

  #endif


*/
  valor_digital = analogRead(Pot);
 
  valor_tensao = (valor_digital * 5.00)/1023;
  valor_temp = (valor_tensao / 0.01);
  Serial.print(valor_temp, 1);
  Serial.println("°C");
  delay(500);
  
  if (valor_temp > 31)
    digitalWrite(LEDR, HIGH);
  else
    digitalWrite(LEDR, LOW);
  
  if (valor_temp > 30 and valor_temp <= 31)
    digitalWrite(LEDY, HIGH);
  else
    digitalWrite(LEDY, LOW);

  if (valor_temp <= 30)
    digitalWrite(LEDG, HIGH);
  else
   digitalWrite(LEDG, LOW);
  
/*
  digitalWrite(LEDR, LOW);
  digitalWrite(LEDY, LOW);
  digitalWrite(LEDG, LOW);
  */
}
