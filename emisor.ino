#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <avr/pgmspace.h>
int led1 = 3;
int led2 = 6;
int sincro = 7;
char testeo[] ="01000001";
bool pasa= false;
String texto;
int conteo=0;
int indice = 0;
String palabra;
void setup() 
{
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(sincro, OUTPUT);
  Serial.begin(115200);
  Serial.setTimeout(100);
  Serial.print("INGRESE PALABRA");
  while(Serial.available()==0)
  {
  }
  palabra = Serial.readStringUntil('\n');
  digitalWrite(led1, HIGH);
  delay(1000);
  digitalWrite(led1, LOW);
  //delay(500);
}


void loop() 
{
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
  }
  conteo=0;
  for(int i = 0; i < palabra.length(); i++)
  {
    char c = palabra[i];
    for(int bit = 7; bit >= 0; bit--)
    {
      int valor = bitRead(c, bit);
      texto += char(valor + '0');
    }
  }
  Serial.print(texto);
  while(true)
  {
  }
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(sincro, LOW);
  //char c = testeo[conteo];
}
