const int buzzerPin = 12; // Pino onde o buzzer está ligado

void setup() {
  pinMode(buzzerPin, OUTPUT); // Configura o pino do buzzer como saída
}

void loop() {
  // Toca 3 bipes ("pi pi pi")
  for (int i = 0; i < 3; i++) {
    digitalWrite(buzzerPin, HIGH); // Liga o buzzer
    delay(150);                    // Duração do bipe
    digitalWrite(buzzerPin, LOW);  // Desliga o buzzer
    delay(150);                    // Pausa entre os bipes
  }
  
  // Pausa maior antes de repetir a sequência toda de novo
  delay(50000); 
}