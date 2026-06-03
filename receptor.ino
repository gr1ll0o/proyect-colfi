#include <stdlib.h>
const int ldrPin = A1;
const int ldrPin2 = A0;
const int sincro = A2;
const int Sincro = 7;
int lectura1, lectura2;
int iguales = 0;

String binario;
String vacio = "00000000";
int lectura;
float estimacion=1000;
int estimacionfinal=0;
float K[5]={0.35, 0.25, 0.20, 0.12, 0.08};
int acomodo=0;
char total;
int valDel = 2;
int umbral = 1;
int numBin1=0, numAct1=0, delays, tiempoact, diftiempo;
int numBin2=0, numAct2=0;
bool espera=false;
bool eravez=false;

int numAnt1=0;
int numAnt2=0;
unsigned long t2;
int inicio = 0;
int conteo = 0;
unsigned long t1[8];
unsigned long tf1[8];
unsigned long tf2[8];
unsigned long tiempo;
bool cambio=false;
bool cambio2=false;
int i;
int lecturas=0;
int a=1;
int b=1;
unsigned long t0=0;
void setup() {
  Serial.begin(115200);
  pinMode(ldrPin, INPUT);
  pinMode(ldrPin2, INPUT);
  Serial.println("--------------");
}

void loop() {
  lectura=analogRead(sincro);
  if (espera==false && lecturas==5)
  {
    numAct2=0;
    numAct1=0;
    numAnt2=0;
    numAnt1=0;
    numBin1=0;
    numBin2=0;
  }
  while(lecturas==5 && lectura<10)
  {
    lectura=analogRead(sincro);
    if (lectura>10)
    {
      break;
    }
    espera=true;
  }
  numAct2 = analogRead(ldrPin2);
  numAct1 = analogRead(ldrPin);
  if (numAct1>numAnt1+umbral){numBin1=1;}
  if (numAct1<numAnt1-umbral){numBin1=0;}
  if (numAct2>numAnt2+umbral){numBin2=1;}
  if (numAct2<numAnt2-umbral){numBin2=0;}
  numAnt1=numAct1;
  numAnt2=numAct2;
  //Serial.println(eravez);
  if (lecturas==5)
  {
    if (numBin1==1)
    {
      if(eravez==false)
      {
        binario+="0";
        conteo+=1;
        //Serial.print("Caracter:");
        Serial.println("Hola");
      }
      else
      {
      binario+="1";
      conteo+=1;
      //Serial.print("Caracter:");
      //Serial.println("1");
      }
    }
    else
    {
      binario+="0";
      conteo+=1;
      //Serial.print("Caracter:");
      //Serial.println("0");
    }

    if (numBin2==1)
    {
      binario+="1";
      conteo+=1;
      //Serial.print("Caracter:");
      //Serial.println("1");
      eravez=true;
    }
    else
    {
      if(eravez==false)
      {
        binario+="1";
        conteo+=1;
        //Serial.print("Caracter:");
        Serial.println("Hola");
        eravez=true;
      }
      else
      {
      binario+="0";
      conteo+=1;
      //Serial.print("Caracter:");
      //Serial.println("0");
      }
    }
  }

  if (conteo==8)
    {
      if (binario==vacio)
      {
        iguales=0;
        asm volatile ("jmp 0");
      }
      char caracter = (char)strtol(binario.c_str(), NULL, 2);
      Serial.print(caracter); 
      conteo=0;
      binario="";
    }
    delay(estimacionfinal/4);

  while(lecturas!=5)
  {
    //Serial.println(numAct2);
    numAct1 = analogRead(ldrPin);
    if (numAct1>numAnt1+umbral){numBin1=1;}
    if (numAct1<numAnt1-umbral){numBin1=0;}
    numAnt1=numAct1;
    unsigned long t0 = millis();
    while(numBin1==1 && (lecturas==0 || lecturas==2 || lecturas==4))
    {
      numAct1 = analogRead(ldrPin);
      //Serial.print("Bit actual:");
      //Serial.println(numAct1);
      //Serial.print("Bit anterior:");
      //Serial.println(numAnt1);
      //if (numAct1>numAnt1+umbral){}
      if (numAct1<numAnt1-umbral){cambio=true;}
      //if (numAct2<numAnt2-umbral){}
      numAnt1=numAct1;
      if (cambio==true)
      {
        tiempo = millis() - t0;
        tf1[lecturas]= millis() - t0;
        Serial.println(tiempo);
        estimacion = estimacion + K[lecturas] * (tiempo-estimacion);
        cambio=false;
        lecturas++;
        if (lecturas==5)
        {         
        Serial.print("Estimación:");
        Serial.println(estimacion);
        estimacionfinal=estimacion;
        umbral=50;
        }
      }
      delay(10);
    }
    //////////////
    t0 = millis();
    while(numBin1==0 && (lecturas==1 || lecturas==3))
    {
      numAct1 = analogRead(ldrPin);
      //Serial.print("Bit actual:");
      //Serial.println(numAct1);
      //Serial.print("Bit anterior:");
      //Serial.println(numAnt1);
      if (numAct1>numAnt1+umbral){cambio=true;}
      //if (numAct1<numAnt1-umbral){}
      //if (numAct2>numAnt2+umbral){}
      numAnt1=numAct1;
      if (cambio==true){
        cambio=false;
        tiempo = millis() - t0;
        tf1[lecturas]= millis() - t0;
        Serial.println(tiempo);
        estimacion = estimacion + K[lecturas] * (tiempo-estimacion);
        lecturas++;
      }
      delay(10);
    }
  }
}
