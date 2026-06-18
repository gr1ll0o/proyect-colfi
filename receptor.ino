/*

Código realizado por los alumnos de la Escuela Técnica N°35
Ingeniero Eduardo Latzina:
Grillo Thiago
Lopez Ciro
Marin Lucas
Puga Thiago
Sayas Yago

Realizado en el marco de la Feria de Educación, Artes, Ciencias y Tecnología 2026 Argentina.
*/

#include <stdlib.h>

//Definición Componentes
const int ldrPin = A0;
const int ldrPin2 = A1;
const int sincro = A2;


//Variables de lecturas
int numBin1 = 0, numAct1 = 0, numAnt1;
int numBin2 = 0, numAct2 = 0, numAnt2;
int numBinSincro = 0, numActSincro = 0, numAntSincro = 0;
int umbral = 15;

//Variables string
String binario;
String finalbinary;
String vacio = "";

//Variables de control
bool reset = false;
int conteo = 0;
int i;
int lecturas = 0;
bool files = true;
bool espera = false;
int umbralsincro = 20;

void setup() {
  Serial.begin(115200);
  pinMode(ldrPin, INPUT);
  pinMode(ldrPin2, INPUT);
  pinMode(sincro, INPUT);
  Serial.println("--------------");
}

void loop() {
  numActSincro=analogRead(sincro);
  //Serial.println(numActSincro);
  if (numActSincro>numAntSincro+umbral){numBinSincro=1;}
  if (numActSincro<numAntSincro-umbral){numBinSincro=0;}
  
  numAntSincro=numActSincro;
  
  if (numActSincro<umbralsincro)
  {
    espera=true;
  }

  if(numActSincro>umbralsincro && espera)
  {
      reset = true;
  }

  numAct2 = analogRead(ldrPin2);
  numAct1 = analogRead(ldrPin);
  //Serial.println(numAct2);
  
  if (numAct1>numAnt1+umbral){numBin1=1;}
  if (numAct1<numAnt1-umbral){numBin1=0;}
  if (lecturas==0)
  {
    if (numAct2>35){numBin2=1;}
    else{numBin2=0;}
  }else
  {
      if (numAct2>numAnt2+umbral+15){numBin2=1;}
      if (numAct2<numAnt2-(umbral-15)){numBin2=0;}
  }
  
  numAnt1=numAct1;
  numAnt2=numAct2;

  if (lecturas>0)
  {
    umbralsincro=40;
  }

  if (numActSincro>umbralsincro && reset)
  {
    binario += numBin1;
    binario += numBin2;
    finalbinary += numBin1;
    finalbinary += numBin2;
    conteo+=2;
    lecturas+=1;
    //Serial.print("BIN DESPUES=");
    //Serial.println(binario);  
    reset=false;
    espera=false;
  }

  if (conteo==8)
    {
      char caracter = (char)strtol(binario.c_str(), NULL, 2);
      //Serial.print(caracter);
      conteo=0;
      binario="";
    }

  if (files==true)
  {
    if (finalbinary!=vacio)
    {
      Serial.println(finalbinary);
    }
  }
}
