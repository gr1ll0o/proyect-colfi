#include <stdio.h>
#include <ctype.h>
#include <string.h>
int led1 = 3;
int led2 = 6;
int sincro = 7;
char testeo[] ="10101010";
bool pasa= false;
String texto;
int conteo=0;
String palabra;
int espera =1000;
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
  digitalWrite(led1, HIGH);
  delay(1000);
  digitalWrite(led1, LOW);
  //delay(500);
}


void loop() 
{
  palabra = Serial.readStringUntil('\n');
  /*while(pasa==false)
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
      if (c == testeo[conteo])
      {
        conteo++;
      }
      else
      {
        exit(0);
      }
      Serial.print("Caracter: ");
      Serial.println(c);
      delay(1000);
      if(conteo==8)
      {
        pasa=true;
      }
  }*/
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
  delay(1000);
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  conteo+=1;

  if(conteo >= texto.length() || palabra== "para gil")
  {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    asm volatile ("jmp 0");
  }
}
