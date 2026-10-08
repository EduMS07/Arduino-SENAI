#include <LiquidCrystal.h>

#define BT1 8    //DEFINE SCRIPT SECADORA
#define BT2 9    //
#define M1 10    //
#define M2 11    //
#define R1 12    //
#define L1 13    //

const int RS=7, EN=6, D4=5, D5=4, D6=3, D7=2;   //DEFINE SCRIPT DISPLAY
LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);      //

void setup() {

  pinMode(BT1, INPUT);    //PINO MODE SCRIPT SECADORA
  pinMode(BT2, INPUT);    //
  pinMode(M1, OUTPUT);    //
  pinMode(M2, OUTPUT);    //
  pinMode(R1, OUTPUT);    //
  pinMode(L1, OUTPUT);    //
  
  lcd.begin(16, 2);    // inicializa o display com o tamanho de 16x2

}

void loop() {

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Pronto Para");
  lcd.setCursor(0, 1);
  lcd.print("Iniciar");
  digitalWrite(L1, HIGH);

  if (digitalRead(BT1) == HIGH) {

  

    for (int i = 0; i < 10; i++) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Resistencia Lig");
      lcd.setCursor(0, 1);
      lcd.print(i);
      lcd.print("s");
      digitalWrite(R1, HIGH);
      delay(1000);
    }

    for (int i = 0; i < 5; i++) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Ventilador Lig");
      lcd.setCursor(0, 1);
      lcd.print(i);
      lcd.print("s");
      digitalWrite(M2, HIGH);
      delay(1000);
    }
    
    for (int i = 0; i < 3; i++) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Esteira Lig");
      lcd.setCursor(0, 1);
      lcd.print(i);
      lcd.print("s");
      digitalWrite(M1, HIGH);
      delay(1000);
    }


  }
  if (digitalRead(BT2) == HIGH) {
    lcd.clear();
    digitalWrite(R1, LOW);
    digitalWrite(M1, LOW);
    digitalWrite(M2, LOW);
    digitalWrite(L1, LOW);
  }


}
