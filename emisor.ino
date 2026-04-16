#include <stdio.h>
int a;
int led = 3;
int brillo;
String texto = "101000011";
int boton=8;
int er=0;
int estadoBoton = digitalRead(boton); //entrada del enter

struct Diccionario {
  String clave;
  int valor;
};

Diccionario datos[] = {
  {"a", "01000001"},
  {"b", ""},
  {"c", 3}
};

void setup() {
  // put your setup code here, to run once:
  pinMode(led, OUTPUT);
  pinMode(boton, INPUT);
  Serial.begin(9600);
}

void loop() {
  Serial.println("");
  Serial.println("ESPERANDO INCIO SECUENCIA");
  digitalWrite(led, LOW);
  delay(1000);
  if (estadoBoton == 0) {
    while(er==0)
    {
      int estadoBoton = digitalRead(boton);
      if(estadoBoton==1)
      {
        er+=1;
        digitalWrite(led, HIGH);
      }
    }
  }
  digitalWrite(led, LOW);
  for (int i = 0; i < texto.length(); i++) {
    digitalWrite(led, LOW);
    delay(500);
    char c = texto.charAt(i); // Obtiene el carácter en la posición i
    Serial.print("Caracter: ");
    Serial.println(c);
    if (c == '0') {
      digitalWrite(led, LOW);
    }
    if (c== '1'){
      digitalWrite(led, HIGH);
    }
    delay(500);
  }
 digitalWrite(led, LOW);
  er=0;
  
  /*analogWrite(led, 0); // APAGADO
  delay(1000);
  analogWrite(led, 30); // 0
  delay(1000);
  analogWrite(led, 255); // 1
  delay(1000); */
}
