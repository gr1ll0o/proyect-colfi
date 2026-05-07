#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <avr/pgmspace.h>
int led1 = 3;
int led2 = 5;
const char texto[] PROGMEM = "01000010";
int boton=8;
int er=0;
int cambio=0;
void setup() 
{
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(boton, INPUT);
  Serial.begin(9600);
}

void loop() 
{
  Serial.println("");
  Serial.println("ESPERANDO INCIO SECUENCIA");
  delay(500);
  int estadoBoton = digitalRead(boton);
  if (estadoBoton == 0) 
  {
    while(er==0)
    {
      estadoBoton = digitalRead(boton);
      if(estadoBoton==1)
      {
        er+=1;
        digitalWrite(led1, HIGH);
        digitalWrite(led2, HIGH);
        delay(20);
      }
    }
  }
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  for (int i = 0; i < strlen(texto); i++) 
  {
    //delay(19);
    delayMicroseconds(181200);
    char c = pgm_read_byte(&texto[i]);
    Serial.print("Caracter: ");
    Serial.println(c);
    if (c == '0')
    {
      if(cambio==0)
      {
        digitalWrite(led1, LOW);
        cambio=1;
      }
      else
      {
        digitalWrite(led2, LOW);
        cambio=0;
      }
    }
    if (c== '1')
    {
      if(cambio==0)
      {  
        digitalWrite(led1, HIGH);
        cambio=1;
      }
      else
      {
        digitalWrite(led2, HIGH);
        cambio=0;
      }
    }
    delay(20);
  }
  er=0;
  delay(15);
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
}

