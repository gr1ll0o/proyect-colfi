#include <stdio.h>
#include <ctype.h>
#include <string.h>
int led1 = 6;
int led2 = 3;
int sincro = 7;
char testeo[] ="";
bool pasa= false;
String texto="";
String resp="";
int conteo=0;
String palabra="";
float espera=5;
char c[9];
int bit = 0;
bool a=true;
bool opcion=true;
void setup() 
{
  //espera*=1000;
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
    delay(10);
    asm volatile ("jmp 0");
  }
  //int cant=palabra.length();
  //char buffer[cant];
  //itoa(palabra, buffer, 10);
}


void loop() 
{
    if(a){
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      delay(2000);
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      a=false;
    }

    if(Serial.available()){palabra=Serial.readStringUntil('\n');}
    char dato;
    if(opcion){dato=palabra[conteo];}
    else
    {
      char letra=palabra[conteo];
      dato=bitRead(letra, 7-bit) ? '1' : '0';
    }

    if(dato=='0'){digitalWrite(led1, LOW);}
    else{digitalWrite(led1, HIGH);}
    if(opcion){conteo++;}
    else{bit++;}

    if(opcion){dato = palabra[conteo];}
    else
    {
      char letra=palabra[conteo];
      dato=bitRead(letra, 7-bit) ? '1' : '0';
    }

    if(dato == '0'){digitalWrite(led2, LOW);}
    else{digitalWrite(led2, HIGH);}

    delay((espera/100)*40);
    digitalWrite(sincro, HIGH);
    delay((espera/100)*20);
    digitalWrite(sincro, LOW);
    delay((espera/100)*40);
    if(opcion){conteo++;}
    else{bit++;}
    if(bit == 8 && !opcion)
    {
      bit = 0;
      conteo++;
    }

    if(conteo >= palabra.length() || palabra == "para gil")
    {
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      asm volatile ("jmp 0");
    }
}
