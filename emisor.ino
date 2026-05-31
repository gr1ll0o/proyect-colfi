#include <stdio.h>
#include <ctype.h>
#include <string.h>
int led1 = 6;
int led2 = 3;
int sincro = 7;
String testeo ="10101";
bool pasa= false;
String texto;
int conteo=0;
String palabra;
int espera= 2500;
float tiempo;
float acumulo;
float estimacion = 2502.4;
int car=0;
unsigned long ti=0;
void setup() 
{
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(sincro, OUTPUT);
  Serial.begin(115200);
  Serial.setTimeout(100);
  Serial.println("INGRESE PALABRA");
  while(Serial.available()==0)
  {
  }
  palabra = Serial.readStringUntil('\n');
  for(int i = 0; i < palabra.length(); i++)
  {
    char c = palabra[i];
    for(int bit = 7; bit >= 0; bit--)
    {
      int valor = bitRead(c, bit);
      texto += char(valor + '0');
    }
  }
}


void loop() 
{
  palabra = Serial.readStringUntil('\n');
  while(pasa==false)
  {
    char c = testeo[conteo];
      if (c == '0')
      {
        digitalWrite(led1, LOW);
      }
      else
      {
        digitalWrite(led1, HIGH);
      }
      Serial.print(c);
      conteo++;
      c = testeo[conteo];
      delay(espera);
      /*if(c=='0')
      {
        digitalWrite(led2, LOW);
      }
      else
      {
        digitalWrite(led2, HIGH);
      }
      Serial.print(c);
      delay(espera);
      conteo++;*/
      if(conteo==5)
      {
        digitalWrite(led1, LOW);
        digitalWrite(led2, LOW);
        conteo=0;
        Serial.println("");
        pasa=true;
      }
  }
  delay(espera);
  if (car==0)
  {
    ti = millis();
  }
  char c = texto[conteo];
  Serial.print(c);
  if(c=='0')
  {
    digitalWrite(led1, LOW);
  }
  else
  {
    digitalWrite(led1, HIGH);
  }
  conteo+=1;
  car+=1;
  c = texto[conteo];
  Serial.print(c);
  if(c=='0')
  {
    digitalWrite(led2, LOW);
  }
  else
  {
    digitalWrite(led2, HIGH);
  }
  conteo+=1;
  car+=1;
  if (car==8)
  {
    //Serial.println(millis());
    //Serial.println(ti);
    tiempo = millis() - ti;
    acumulo = estimacion*4-tiempo;
    car=0;
    if (acumulo<0)
    {
      Serial.println(acumulo);
      acumulo=acumulo*-1;
      delay(acumulo);
    }
  }
  if(conteo == texto.length() || palabra== "para gil")
  {
    delay(espera);
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    Serial.println("");
    asm volatile ("jmp 0");
  }
}
