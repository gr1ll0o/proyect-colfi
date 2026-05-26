#include <stdlib.h>
const int ldrPin = A0;
const int ldrPin2 = A1;
int lectura1, lectura2, tiempo;
int iguales = 0;

String binario;
String vacio = "00000000";
char total;

int valDel = 2;

int numBin1, numAct1, numAnt1=0;
int numBin2, numAct2, numAnt2=0;

int inicio = 0;
int conteo = 0;

void setup() {
  Serial.begin(9600);
  pinMode(ldrPin, INPUT);
  pinMode(ldrPin2, INPUT);
  Serial.println("--------------");
}

void loop() {
  lectura1 = analogRead(ldrPin);
  numAct1 = lectura1;
  //Serial.println(lectura1);
  lectura2 = analogRead(ldrPin2);
  numAct2 = lectura2;
  //Serial.println(lectura2);

  if (numAct1>numAnt1)
  {
    numBin1=1;
  }
  if (numAct1<numAnt1-15)
  {
    numBin1=0;
  }

//////////////////

  if (numAct2>numAnt2)
  {
    numBin2=1;
  }
  if (numAct2<numAnt2-15)
  {
    numBin2=0;
  }

  numAnt1=numAct1;
  numAnt2=numAct2;

  if (inicio!=8){
  if (numBin1==1 && inicio==0)
  {

      while(numBin1==1 && inicio==0)
    {     
        lectura1 = analogRead(ldrPin);
        numAct1=lectura1;

        if (numAct1>numAnt1)
        {
          numBin1=1;
        }
        if (numAct1<numAnt1-10)
        {
          numBin1=0;
        }

        numAnt1=numAct1;

        delay(1);
        tiempo+=1;
      }
      inicio+=1;
      Serial.println(tiempo);
  }
      if (numBin1==0 && inicio==1)
      {
        delay(tiempo);
        inicio+=1;
      }
      if (numBin1==1 && inicio==2)
        {
          delay(tiempo);
          inicio+=1;
        }
          if (numBin1==0 && inicio==3)
          {
            delay(tiempo);
            inicio+=1;
          }
            if (numBin1==1 && inicio==4)
            {
              delay(tiempo);
              inicio+=1;
            }
              if (numBin1==0 && inicio==5)
              {
                delay(tiempo);
                inicio+=1;
              }
                if (numBin1==1 && inicio==6)
                {
                delay(tiempo);
                inicio+=1;
                }
                if (numBin1==0 && inicio==7)
                {
                  Serial.println("Código recibido");
                  inicio+=1;
                }
    }

 if (inicio==8)
 {
  delay(tiempo);
  if (numBin1==1)
  {
    binario+="1";
    conteo+=1;
    Serial.println("1");
  }
  else
  {
    binario+="0";
    conteo+=1;
    Serial.println("0");
  }

  
  if (numBin2==1)
  {
    binario+="1";
    conteo+=1;
    Serial.println("1");
  }
  else
  {
    binario+="0";
    conteo+=1;
    Serial.println("0");
  }
 }
   if (conteo==8)
  {
    if (binario==vacio)
    {
      iguales=0;
      exit(0);
    }
    char caracter = (char)strtol(binario.c_str(), NULL, 2);
    Serial.print(caracter); 
    conteo=0;
    binario="";
  } 
}
