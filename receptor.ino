#include <stdlib.h>
const int ldrPin = A0;
const int ldrPin2 = A1;
const int ldrPin3 = A2;
int lectura1, lectura2, lectura3;
int activacion = false;

String binario;
String vacio = "00000000";
char total;

int conteo = 0;
bool espera = false;
void setup() {
  Serial.begin(2000000);
  pinMode(ldrPin, INPUT);
  pinMode(ldrPin2, INPUT);
  pinMode(ldrPin3, INPUT);
  Serial.println("--------------");
}

void loop() {

  lectura1 = analogRead(ldrPin);
  lectura2 = analogRead(ldrPin2);
  //Serial.println(lectura1);

  if ((lectura1>10 && lectura2>10) || activacion==true)
  {
    if (activacion==false)
    {
      activacion=true;
      delay(49);
      delayMicroseconds(940);
    }

    lectura1 = analogRead(ldrPin);
    if (lectura1>30)
    {
      if (conteo==0)
      {
        binario+="0";
        conteo+=1;
        //Serial.println("0");
      }
      else{
      binario+="1";
      conteo+=1;  
      //Serial.println("1");
      }   
    }

    else
    {
      binario+="0";
      conteo+=1;
      //Serial.println("0");
    }

    lectura2 = analogRead(ldrPin2);
    if(conteo==7){
    //Serial.print("Lectura:");
    //Serial.println(lectura2);
    }

    if (lectura2>20)
    {
      binario+="1";
      conteo+=1;  
      //Serial.println("1");
    }

    else
    {
      binario+="0";
      conteo+=1;
      //Serial.println("0");
    }

    delay(50);

    if (conteo==8)
        {
          if (binario==vacio)
          {
            activacion=false;
          }
          char caracter = (char)strtol(binario.c_str(), NULL, 2);
          //Serial.println("--------------------");
          Serial.print(caracter); 
          conteo=0;
          binario="";
        }
  }
}
