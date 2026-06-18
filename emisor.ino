#include <stdio.h>
#include <ctype.h>
#include <string.h>
int led1 = 6;
int led2 = 3;
int sincro = 5;
char testeo[] ="";
bool pasa= false;
String texto="";
String term="";
String resp="";
int conteo=0;
String palabra="";
float espera=500;
char c[9];
int bit = 0;
int a=true;
bool opcion=true;
void setup() 
{
  Serial.println("");
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(sincro, OUTPUT);
  Serial.begin(115200);
  Serial.setTimeout(100);
  Serial.println("Que quiere emitir?");
  Serial.println("1. Archivos (En binario)");
  Serial.println("2. Palabras");
  while(Serial.available()==0)
  {
  }
  resp = Serial.readStringUntil('\n');
  if(resp=="1")
  {
    Serial.println("INGRESE ARCHIVO");
    while(Serial.available()==0)
    {
    }
    palabra = Serial.readStringUntil('\n');
    term=palabra;
  }
  else if(resp=="2"){
    opcion=false;
    Serial.println("INGRESE PALABRA");
    while(Serial.available()==0)
    {
    }
    palabra = Serial.readStringUntil('\n');
  }
  else{
    Serial.println("Numero equivocado intente de nuevo");
    asm volatile ("jmp 0");
  }
  //int cant=palabra.length();
  //char buffer[cant];
  //itoa(palabra, buffer, 10);
}


void loop() 
{
    if(a){
      delay(2000);
      a=false;
    }
  if(bit == 0 && !opcion)
  {
    char letra = palabra[conteo];

    for(int i = 0; i < 8; i++)
    {
      c[i] = bitRead(letra, 7 - i) + '0';
    }

    c[8] = '\0';
  }
  //palabra = Serial.readStringUntil('\n');
  if(Serial.available())
  {
    palabra = Serial.readStringUntil('\n');
  }
  /*while(pasa==false)
  {
    char c = testeo[conteo];
    if(c=='0')
    {
      digitalWrite(led1, LOW);
    }
    else
    {
      digitalWrite(led1, HIGH);
    }
    Serial.print(c);
    delay(espera);
    conteo+=1;
    if(conteo==5)
    {
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      Serial.println("");
      conteo=0;
      pasa=true;
    }
  }*/
  Serial.println(opcion ? palabra[conteo] : c[bit]);
  if((opcion ? palabra[conteo] : c[bit]) == '0')
  {
    digitalWrite(led1, LOW);
  }
  else
  {
    digitalWrite(led1, HIGH);
  }
  if(opcion){
    conteo++;
  }
  else{
    bit++;
  }
  Serial.println(opcion ? palabra[conteo] : c[bit]);
  if((opcion ? palabra[conteo] : c[bit]) == '0')
  {
    digitalWrite(led2, LOW);
  }
  else
  {
    digitalWrite(led2, HIGH);
  }
  delay((espera/100)*40);
  digitalWrite(sincro, HIGH);
  delay((espera/100)*20);
  digitalWrite(sincro, LOW);
  delay((espera/100)*40);
  if(opcion){
    conteo++;
  }
  else{
    bit++;
  } 
  if(bit == 8 && !opcion)
  {
    bit = 0;
    conteo++;
  }

  if(conteo >= palabra.length() || palabra== "para gil")
  {
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    asm volatile ("jmp 0");
  }
}
