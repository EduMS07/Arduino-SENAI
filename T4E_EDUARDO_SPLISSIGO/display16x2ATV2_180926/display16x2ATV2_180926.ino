#include <LiquidCrystal.h>



//#define colunas 16
//#define linhas 2

const int RS=12, EN=11, D4=5, D5=4, D6=3, D7=2;

LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);

void setup() {

  lcd.begin(16, 2);    // inicializa o display com o tamanho de 16x2
  lcd.clear();                 // limpa o texto do display   
  lcd.setCursor(0, 0);        // Posiciona o cursor na coluna 0 e na linha 0
  lcd.print("Eduardo Murari ");
  //lcd.print("Bem-Vindo");
}

void loop() {

  for (int positionCounter = 0; positionCounter < 13; positionCounter++) {
    // scroll one position left:
    lcd.scrollDisplayLeft();
    // wait a bit:
    delay(500);
  }

  for (int positionCounter = 0; positionCounter < 13; positionCounter++) {
    // scroll one position left:
    lcd.scrollDisplayRight();
    // wait a bit:
    delay(500);
  }

}
