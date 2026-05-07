#include <stdio.h>
#include <ctype.h>
#include <string.h>
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
