#include <stdio.h>
#include <ctype.h>
#include <string.h>
int led1 = 6;
int led2 = 3;
int sincro = 7;
char testeo[] ="10101";
bool pasa= false;
String texto;
int conteo=0;
String palabra;
int espera=1000;
void setup() 
{
  Serial.println("");
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
    if(c=='0')
    {
      digitalWrite(led1, LOW);
    }
    else
    {
      digitalWrite(led1, HIGH);
    }
    Serial.print(c);
    delay(espera);
    conteo+=1;
    if(conteo==5)
    {
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      Serial.println("");
      conteo=0;
      pasa=true;
    }
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
  delay(espera/2);
  digitalWrite(sincro, HIGH);
  delay(espera/5);
  digitalWrite(sincro, LOW);
  delay(espera/2);
  conteo+=1;

  if(conteo >= texto.length() || palabra== "para gil")
  {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    asm volatile ("jmp 0");
  }
}
