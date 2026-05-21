#include <stdlib.h>
const int ldrPin = A0;
const int ldrPin2 = A1;
const int ldrPin3 = A2;
int lectura1, lectura2, lectura3;
int iguales = 1;

String binario;
String vacio = "00000000";
char total;

int conteo = 0;
bool espera = false;
void setup() {
  Serial.begin(230400);
  pinMode(ldrPin, INPUT);
  pinMode(ldrPin2, INPUT);
  pinMode(ldrPin3, INPUT);
  Serial.println("--------------");
}

void loop() {

  lectura1 = analogRead(ldrPin);
  //Serial.println(lectura1);
  lectura2 = analogRead(ldrPin2);
  //Serial.println(lectura2);
  lectura3 = analogRead(ldrPin3);
  //Serial.println(lectura3);

  if (iguales==1){
    if (lectura3>5 && espera==true)
    {
      if (lectura1>6)
      {
          binario += '1';
          //Serial.println("1");
          conteo=conteo+1;
          espera=false;
      }
      else
      {
          binario += '0';
          //Serial.println("0");
          conteo=conteo+1;
          espera=false;
      }

      ////////////////////////////

      if (lectura2>6)
      {
          binario += '1';
          //Serial.println("1");
          conteo=conteo+1;
          espera=false;
      }
      else
      {
          binario += '0';
          //Serial.println("0");
          conteo=conteo+1;
          espera=false;
      }
    }
    else 
    {
      if (lectura3<=2){
      espera=true;
      }
    }
    if (conteo==8)
    {
      if (binario==vacio)
      {
        iguales=0;
      }
      char caracter = (char)strtol(binario.c_str(), NULL, 2);
      //Serial.println("--------------------");
      Serial.print(caracter); 
      conteo=0;
      binario="";
    }
  }
}
