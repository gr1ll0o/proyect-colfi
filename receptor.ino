#include <stdlib.h>
const int ldrPin = A0;
const int ldrPin2 = A1;
const int ldrPin3 = A2;
const int ledPin = 13;
int lectura1, lectura2, lectura3;
int iguales = 0;

String binario;
char total;

int conteo = 0;
int letra = 0;
bool espera = false;
void setup() {
  Serial.begin(9600);
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


  if ((lectura1>20 && lectura2>20 && lectura3>20) || iguales==1)
  {
    if (iguales==0){
      delay(20);
    }
    if (espera==false && (lectura1<20 || lectura2<20 || lectura3<20)){
      espera = true;
      Serial.println("Si");
      delay(49);
    }

    if (espera==true){
    if(lectura1>10 && lectura1<30)
    {
      binario += '1';
      Serial.println("1");
      conteo=conteo+1;
    }
    else {if (lectura1>=36){
      
    }
    else
    {
      binario += '0';
      Serial.println("0");
      conteo=conteo+1;
    }
    }
/////////////////////////////////
    if(lectura2>10 && lectura2<30)
    {
      binario += '1';
      Serial.println("1");
      conteo=conteo+1;
    }
    else {if (lectura2>=36){
      
    }
    else
    {
      binario += '0';
      Serial.println("0");
      conteo=conteo+1;
    }
    }
/////////////////////////////////
    if(lectura3>10 && lectura3<30)
    {
      binario += '1';
      Serial.println("1");
      conteo=conteo+1;
      espera = true;
    }
    else {if (lectura3>=36){
      espera = true;
    }
    else
    {
      binario += '0';
      Serial.println("0");
      conteo=conteo+1;
      espera = true;
    }
    }
  }
  /////////////////////////////////
   if (conteo==8){
      char caracter = (char)strtol(binario.c_str(), NULL, 2);
      Serial.print(caracter);
      conteo=0;
      binario="";
    }
}
}
