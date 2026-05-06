#include <stdlib.h>
const int ldrPin = A0;
const int ldrPin2 = A1;
int lectura1, lectura2;
int iguales = 0;

String binario;
String vacio = "00000000";
char total;

int conteo = 0;
int letra = 0;
bool espera = true;
void setup() {
  Serial.begin(9600);
  pinMode(ldrPin, INPUT);
  pinMode(ldrPin2, INPUT);
  Serial.println("--------------");
}

void loop() {

  lectura1 = analogRead(ldrPin);
  //Serial.println(lectura1);
  lectura2 = analogRead(ldrPin2);
  //Serial.println(lectura2);

  if ((lectura1>7 && lectura2>7) || iguales==1)
  {
    //Serial.println("Hola");
    if (iguales==0){
      delay(8);
      iguales=1;
    }
    if (!espera || (lectura1 < 10 && lectura2 < 10))
    {
      espera = true;
      //Serial.println("Si");
      //delay(12);
    }

    if (espera==true) 
    {

      if (lectura1>13)
      {
        binario += '1';
        Serial.println("1");
        conteo=conteo+1;
        letra+=1;
      }
      else
      {
        binario += '0';
        Serial.println("0");
        conteo=conteo+1;
      }
      ///////////////////
      if (lectura2>13)
      {
        binario += '1';
        Serial.println("1");
        conteo=conteo+1;
        espera=true;
      }
      else
      {
        binario += '0';
        Serial.println("0");
        conteo=conteo+1;
        espera=true;
      }

    }
  }

  espera=false;
  delay(12);

  if (conteo==8)
  {
    if (binario==vacio)
    {
      iguales=0;
    }
    char caracter = (char)strtol(binario.c_str(), NULL, 2);
    Serial.print(caracter); 
    conteo=0;
    binario="";
  }
}
