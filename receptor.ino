#include <stdlib.h>
const int ldrPin = A0;
const int ldrPin2 = A1;
int lectura1, lectura2;
int iguales = 0;

String binario;
String vacio = "00000000";
char total;

int valDel = 2;

int umbral = 2;
int numBin1, numAct1, delays, tiempoact, diftiempo;
int numBin2, numAct2;
bool espera=false;

int numAnt1=0;
int numAnt2=0;

int inicio = 0;
int conteo = 0;

int tiempo;

void setup() {
  Serial.begin(115200);
  pinMode(ldrPin, INPUT);
  pinMode(ldrPin2, INPUT);
  Serial.println("--------------");
}

void loop() {
  numAct1 = analogRead(ldrPin);
  //Serial.println(numAct1);
  numAct2 = analogRead(ldrPin2);
  //Serial.println(numAct2);

  //Serial.print("NumAct:");
  //Serial.println(numAct1);


  //Serial.print("NumAnt:");
  //Serial.println(numAnt1);

  if (numAct1>numAnt1+umbral)
  {
    numBin1=1;
  }
  if (numAct1<numAnt1-umbral)
  {
    numBin1=0;
  }

//////////////////

  if (numAct2>numAnt2+umbral)
  {
    numBin2=1;
  }
  if (numAct2<numAnt2-umbral)
  {
    numBin2=0;
  }

  numAnt1=numAct1;
  numAnt2=numAct2;
  
  //Serial.println(numBin1);


  unsigned long t0 = millis();
  while (numBin1==1 && inicio==0)
  {
    numAct1 = analogRead(ldrPin);
    //Serial.println(numAct1);
    if (numAct1>numAnt1+umbral){numBin1=1;}
    if (numAct1<numAnt1-umbral){numBin1=0;}
    numAnt1=numAct1;
    delay(1);
  }


  if (espera==false)
  {
    tiempo = millis() - t0;
  }
  if (tiempo>0 && espera==false){
    Serial.print("Delay detectado:");
    Serial.println(tiempo);
    inicio+=1;
    espera=true;
  }


  //Serial.println(inicio);
 
 if (inicio>=2)
 {
  if (numBin1==1)
  {
    binario+="1";
    conteo+=1;
    Serial.print("Caracter:");
    Serial.println("1");

  }
  else
  {
    binario+="0";
    conteo+=1;
    Serial.print("Caracter:");
    Serial.println("0");
  }

  
  if (numBin2==1)
  {
    binario+="0";
    conteo+=1;
  unsigned long t0 = millis();
  while (numBin2==1 && conteo!=8)
  {
    numAct2 = analogRead(ldrPin);
    //Serial.println(numAct2);
    if (numAct2>numAnt2+umbral){numBin2=1;}
    if (numAct2<numAnt2-umbral){numBin2=0;}
    numAnt2=numAct2;
    delay(1);
  }
  tiempoact=millis()-t0;
  diftiempo=tiempo-tiempoact;
  if(diftiempo>0)
  {
    delay(diftiempo);
  }
    binario+="1";
    conteo+=1;
    Serial.print("Caracter:");
    Serial.println("1");
    
  }
  else
  {
  binario+="0";
  conteo+=1;
  unsigned long t0 = millis();
  while (numBin2==0 && conteo!=8)
  {

    numAct2 = analogRead(ldrPin);
    //Serial.println(numAct2);
    if (numAct2>numAnt2+umbral){numBin2=1;}
    if (numAct2<numAnt2-umbral){numBin2=0;}
    numAnt2=numAct2;
    delay(1);
  }
  tiempoact=millis()-t0;
  diftiempo=tiempo-tiempoact;
  if(diftiempo>0)
  {
    delay(diftiempo);
  }

    Serial.print("Caracter:");
    Serial.println("0");
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
    Serial.println(caracter); 
    conteo=0;
    binario="";
  } 

  if (espera==true)
  {
    inicio+=1;
    delay(tiempo);
    umbral=20;
  }
}
