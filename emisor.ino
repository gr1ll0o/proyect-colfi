#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <avr/pgmspace.h>
int led1 = 6;
int led2 = 3;
int sincro = 7;
char testeo[] ="10101010";
bool pasa= false;
const char texto[] PROGMEM = "010011100110111101110011001000000110110001101111011100110010000001110010011001010111000001110010011001010111001101100101011011100111010001100001011011100111010001100101011100110010000001100100011001010110110000100000011100000111010101100101011000100110110001101111001000000110010001100101001000000110110001100001001000000100111001100001011000110110100101101111011011100010000001000001011100100110011101100101011011100111010001101001011011100110000100101100001000000111001001100101011101010110111001101001011001000110111101110011001000000110010101101110001000000100001101101111011011100110011101110010011001010111001101101111001000000100011101100101011011100110010101110010011000010110110000100000010000110110111101101110011100110111010001101001011101000111010101111001011001010110111001110100011001010010000001110000011011110111001000100000011101100110111101101100011101010110111001110100011000010110010000100000011110010010000001100101011011000110010101100011011000110110100101101111011011100010000001100100011001010010000001101100011000010111001100100000011100000111001001101111011101100110100101101110011000110110100101100001011100110010000001110001011101010110010100100000011011000110000100100000011000110110111101101101011100000110111101101110011001010110111000101100";
int boton=8;
int er=0;
int conteo=0;
String palabra;
void setup() 
{
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(sincro, OUTPUT);
  pinMode(boton, INPUT);
  Serial.begin(9600);
  while(Serial.available()==0)
  {
  }
  palabra = Serial.readStringUntil('\n');
  Serial.print(texto);
  Serial.println("");
  Serial.println("ESPERANDO INCIO SECUENCIA");
  delay(300);
}


void loop() 
{
  int estadoBoton = digitalRead(boton);
  if (estadoBoton == 0) 
  {
    while(er==0)
    {
      estadoBoton = digitalRead(boton);
      /*digitalWrite(led2, HIGH);
      delay(50);
      digitalWrite(led2, LOW);
      delay(50);*/
      if(estadoBoton==1)
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
          else{
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
        er+=1;
        conteo=0;
        Serial.println("");
      }
    }
  }
  /*for(int i = 0; i < palabra.length(); i++)
  {
    char c = palabra[i];

    for(int bit = 7; bit >= 0; bit--)
    {
        int valor = bitRead(c, bit);
        delay(500);
    }
  }*/
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(sincro, LOW);
  //char c = testeo[conteo];
  er=0;
  pasa=false;
}
