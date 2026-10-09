#include <LiquidCrystal.h>

#define BT1 8     // Botão de Iniciar
#define BT2 19    // Botão de Parar (Interrupção no Mega)
#define M1 10     // Esteira
#define M2 11     // Ventilador
#define R1 12     // Resistência
#define L1 13     // Lâmpada/Led Indicador

const int RS=7, EN=6, D4=5, D5=4, D6=3, D7=2;   
LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);      

// Flag de emergência
volatile bool parado = false;

// Função da Interrupção: Desliga TUDO imediatamente na hora do clique
void interrupcaoParar() {
  digitalWrite(R1, LOW);
  digitalWrite(M1, LOW);
  digitalWrite(M2, LOW);
  digitalWrite(L1, LOW);
  parado = true; 
}

// Substitui o delay travante. Checa a flag 'parado' a cada 1 milissegundo
bool esperarOuAbortar(unsigned long tempoMs) {
  unsigned long inicio = millis();
  while (millis() - inicio < tempoMs) {
    if (parado) {
      return true; // Aborta imediatamente se o botão foi pressionado
    }
    delay(1); 
  }
  return false; 
}

void setup() {
  pinMode(BT1, INPUT);    
  pinMode(BT2, INPUT); 
  pinMode(M1, OUTPUT);    
  pinMode(M2, OUTPUT);    
  pinMode(R1, OUTPUT);    
  pinMode(L1, OUTPUT);    
  
  lcd.begin(16, 2);    
  
  // Interrupção no pino 19 
  attachInterrupt(digitalPinToInterrupt(BT2), interrupcaoParar, RISING);
}

void loop() {
  // 1. SE O PROCESSO FOI INTERROMPIDO, TRATA ISSO PRIMEIRO DE TUDO
  if (parado) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("PROCESSO");
    lcd.setCursor(0, 1);
    lcd.print("INTERROMPIDO!");
    
    // Espera 3 segundos travado nesta mensagem
    esperarOuAbortar(3000); 
    
    parado = false; // Reseta a flag para permitir ligar de novo
    return;         // Retorna para o topo do loop para limpar o estado
  }

  // Se não foi interrompido, mostra a tela inicial (apenas se não estiver rodando o ciclo)
  lcd.setCursor(0, 0);
  lcd.print("Pronto Para    "); 
  lcd.setCursor(0, 1);
  lcd.print("Iniciar        ");
  
  if (digitalRead(BT1) == HIGH && !parado) {

    // --- ETAPA 1: RESISTÊNCIA ---
    digitalWrite(R1, HIGH);
    for (int i = 0; i < 10; i++) {
      if (parado) return; // Sai imediatamente se foi interrompido
      
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Resistencia Lig");
      lcd.setCursor(0, 1);
      lcd.print(i);
      lcd.print("s");
      
      if (esperarOuAbortar(1000)) return; 
    }

    // --- ETAPA 2: VENTILADOR ---
    digitalWrite(M2, HIGH);
    for (int i = 0; i < 5; i++) {
      if (parado) return; 
      
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Ventilador Lig");
      lcd.setCursor(0, 1);
      lcd.print(i);
      lcd.print("s");
      
      if (esperarOuAbortar(1000)) return;
    }

    // --- ETAPA 3: ESTEIRA ---
    digitalWrite(M1, HIGH);
    for (int i = 0; i < 3; i++) {
      if (parado) return; 
      
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Esteira Lig");
      lcd.setCursor(0, 1);
      lcd.print(i);
      lcd.print("s");
      
      if (esperarOuAbortar(1000)) return;
    }
    
    // Finalização do ciclo
    if (!parado) {
      digitalWrite(L1, HIGH);
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Ciclo Concluido");
      esperarOuAbortar(3000);
      digitalWrite(L1, LOW);
      digitalWrite(R1, LOW);
      digitalWrite(M1, LOW);
      digitalWrite(M2, LOW);
    }
  }
}