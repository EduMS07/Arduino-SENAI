
int contador = 0;
int botaoinc = 10;
int botaodec = 11;
int botaoreset = 12;

int estadobotinc = 0;
int estadobotdec = 0;
int estadobotrst = 0;
int bloqueio1 = 0;
int bloqueio2 = 0;

int segA = 1;
int segB = 2;
int segC = 3;
int segD = 4;
int segE = 5;
int segF = 6;
int segG = 7;


void setup() {
  
pinMode(botaoinc, INPUT);
pinMode(botaodec, INPUT);
pinMode(botaoreset, INPUT);
pinMode(segA, OUTPUT);
pinMode(segB, OUTPUT);
pinMode(segC, OUTPUT);
pinMode(segD, OUTPUT);
pinMode(segE, OUTPUT);
pinMode(segF, OUTPUT);
pinMode(segG, OUTPUT);

digitalWrite(segA, LOW);
digitalWrite(segB, LOW);
digitalWrite(segC, LOW);
digitalWrite(segD, LOW);
digitalWrite(segE, LOW);
digitalWrite(segF, LOW);
digitalWrite(segG, LOW);


}

void loop() {
  
  estadobotinc = digitalRead(botaoreset);
  if((estadobotinc == 1) && (bloqueio1 == 0))
    {
      contador++;
      bloqueio1 = 1;
    }

  if((estadobotinc == 0) && (bloqueio1 ==1))
    {
      bloqueio1 = 0;
    }
  
  estadobotdec = digitalRead(botaodec);

  if((estadobotdec == 1) && (bloqueio2 == 0));
    {
      contador--;
      bloqueio2 = 1;
    }

  if((estadobotdec == 0) && (bloqueio2 == 1));
    {
      bloqueio2 = 0;
    }

  if((contador > 9) || (contador < 0) || (estadobotrst == 1));
    {
      contador = 0;
    }

  estadobotrst = digitalRead(botaoreset);

  if(contador == 0)
    {
      digitalWrite(segA, HIGH);
      digitalWrite(segB, HIGH);
      digitalWrite(segC, HIGH);
      digitalWrite(segD, HIGH);
      digitalWrite(segE, HIGH);
      digitalWrite(segF, HIGH);
      digitalWrite(segG, LOW);
    }

  if(contador == 1)
    {
      digitalWrite(segA, LOW);
      digitalWrite(segB, HIGH);
      digitalWrite(segC, HIGH);
      digitalWrite(segD, LOW);
      digitalWrite(segE, LOW);
      digitalWrite(segF, LOW);
      digitalWrite(segG, LOW);
    }

  if(contador == 2)
    {
      digitalWrite(segA, HIGH);
      digitalWrite(segB, HIGH);
      digitalWrite(segC, LOW);
      digitalWrite(segD, HIGH);
      digitalWrite(segE, HIGH);
      digitalWrite(segF, LOW);
      digitalWrite(segG, HIGH);
    }

  if(contador == 3)
    {
      digitalWrite(segA, HIGH);
      digitalWrite(segB, HIGH);
      digitalWrite(segC, HIGH);
      digitalWrite(segD, HIGH);
      digitalWrite(segE, LOW);
      digitalWrite(segF, LOW);
      digitalWrite(segG, HIGH);
    }
    
  if(contador == 4)
    {
      digitalWrite(segA, LOW);
      digitalWrite(segB, HIGH);
      digitalWrite(segC, HIGH);
      digitalWrite(segD, LOW);
      digitalWrite(segE, LOW);
      digitalWrite(segF, HIGH);
      digitalWrite(segG, HIGH);
    }

  if(contador == 5)
    {
      digitalWrite(segA, HIGH);
      digitalWrite(segB, LOW);
      digitalWrite(segC, HIGH);
      digitalWrite(segD, HIGH);
      digitalWrite(segE, LOW);
      digitalWrite(segF, HIGH);
      digitalWrite(segG, HIGH);
    }

  if(contador == 6)
    {
      digitalWrite(segA, HIGH);
      digitalWrite(segB, LOW);
      digitalWrite(segC, HIGH);
      digitalWrite(segD, HIGH);
      digitalWrite(segE, HIGH);
      digitalWrite(segF, HIGH);
      digitalWrite(segG, HIGH);
    }

  if(contador == 7)
    {
      digitalWrite(segA, HIGH);
      digitalWrite(segB, HIGH);
      digitalWrite(segC, HIGH);
      digitalWrite(segD, LOW);
      digitalWrite(segE, LOW);
      digitalWrite(segF, LOW);
      digitalWrite(segG, LOW);
    }

  if(contador == 8)
    {
      digitalWrite(segA, HIGH);
      digitalWrite(segB, HIGH);
      digitalWrite(segC, HIGH);
      digitalWrite(segD, HIGH);
      digitalWrite(segE, HIGH);
      digitalWrite(segF, HIGH);
      digitalWrite(segG, HIGH);
    }

  if(contador == 9)
    {
      digitalWrite(segA, HIGH);
      digitalWrite(segB, HIGH);
      digitalWrite(segC, HIGH);
      digitalWrite(segD, HIGH);
      digitalWrite(segE, LOW);
      digitalWrite(segF, HIGH);
      digitalWrite(segG, HIGH);
    }

}
