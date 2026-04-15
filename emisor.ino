#include <stdio.h>
int a;
int led = 3;
int brillo;
String texto = "101000001";
int boton=8;
int er=0;
//entrada del enter
int estadoBoton = digitalRead(boton);
void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  pinMode(boton, INPUT);
  Serial.begin(9600);
}

void loop() {
  analogWrite(led, 0);
  delay(1000);
  if (estadoBoton == 0) {
    while(er==0)
    {
      int estadoBoton = digitalRead(boton);
      if(estadoBoton==1)
      {
        er+=1;
      }
    }
  }
  for (int i = 0; i < texto.length(); i++) {
    analogWrite(led, 0);
    delay(500);
    char c = texto.charAt(i); // Obtiene el carácter en la posición i
    Serial.print("Caracter: ");
    Serial.println(c);
    if (c == '0') {
      analogWrite(led, 0);
    }
    if (c== '1'){
      analogWrite(led, 255);
    }
    delay(500);
  }
  analogWrite(led, 0);
  estadoBoton=0;
  
  /*analogWrite(led, 0); // APAGADO
  delay(1000);
  analogWrite(led, 30); // 0
  delay(1000);
  analogWrite(led, 255); // 1
  delay(1000); */
}
