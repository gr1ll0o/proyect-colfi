#include <stdio.h>
#include <ctype.h>
#include <string.h>#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <avr/pgmspace.h>
int a;
int led1 = 3;
int led2 = 5;
int led3 = 6;
int brillo;
const char texto[] PROGMEM = "101000001";
int boton=8;
int er=0;
void setup() 
{
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(boton, INPUT);
  Serial.begin(9600);
}

void loop() 
{
  Serial.println("");
  Serial.println("ESPERANDO INCIO SECUENCIA");
  delay(1000);
  int estadoBoton = digitalRead(boton);
  if (estadoBoton == 0) 
  {
    while(er==0)
    {
      estadoBoton = digitalRead(boton);
      Serial.println(estadoBoton);
      if(estadoBoton==1)
      {
        er+=1;
        digitalWrite(led1, HIGH);
        digitalWrite(led2, HIGH);
        digitalWrite(led3, HIGH);
        delay(20);

      }
    }
  }
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  for (int i = 0; i < strlen(texto); i++) 
  {
    char c = pgm_read_byte(&texto[i]);
    Serial.print("Caracter: ");
    Serial.println(c);
    if(i%3==0){
        delay(25);
      if (c == '0')
      {
        digitalWrite(led1, LOW);
      }
      if (c== '1')
      {
        digitalWrite(led1, 120);
      }
    }
    if(i%3==1){
      if (c == '0')
      {
        digitalWrite(led2, LOW);
      }
      if (c== '1')
      {
        digitalWrite(led2, 120);
      }
    }
    if(i%3==2){
      if (c == '0')
      {
        digitalWrite(led3, LOW);
      }
      if (c== '1')
      {
        digitalWrite(led3, 120);
      }
    }
    delay(25);
  }
  er=0;
  digitalWrite(led3, HIGH);
  delay(30);
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
}
#include <avr/pgmspace.h>
int a;
int led = 3;
int brillo;
const char texto[] PROGMEM = "101101000011011110110110001100001001000000110110101110101011011100110010001101111";
int boton=8;
int er=0;
int estadoBoton = digitalRead(boton);

void setup() 
{
  pinMode(led, OUTPUT);
  pinMode(boton, INPUT);
  Serial.begin(9600);
}

void loop() 
{
  Serial.println("");
  Serial.println("ESPERANDO INCIO SECUENCIA");
  digitalWrite(led, LOW);
  delay(1000);
  if (estadoBoton == 0) 
  {
    while(er==0)
    {
      int estadoBoton = digitalRead(boton);
      if(estadoBoton==1)
      {
        er+=1;
        digitalWrite(led, HIGH);
      }
    }
  }
  digitalWrite(led, LOW);
  for (int i = 0; i < strlen(texto); i++) 
  {
    digitalWrite(led, LOW);
    delay(25);
    char c = pgm_read_byte(&texto[i]);
    Serial.print("Caracter: ");
    Serial.println(c);
    if (c == '0') 
    {
      digitalWrite(led, LOW);
    }
    if (c== '1')
    {
      digitalWrite(led, HIGH);
    }
    delay(25);
  }
 digitalWrite(led, LOW);
  er=0;
}
