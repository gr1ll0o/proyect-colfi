const int ldrPin = A0;
const int ledPin = 13;
int lectura;
int iguales = 0;

String binario;
char total;

int conteo = 0;
bool letra = false;
bool espera = false;
void setup() {
  Serial.begin(9600);
  pinMode(ldrPin, INPUT);
  Serial.println("--------------");
}

void loop() {
  lectura = analogRead(ldrPin);
  //Serial.println(lectura);
  if (lectura>15 || iguales==1){
    if (iguales==0){
      delay(200);
    }
    iguales=1;
    if (espera==false && lectura<20){
      espera = true;
      delay(920);
    }
    else
    {
      if (espera==true){
        if (lectura>15){
          //Serial.println("Se detecto 1");
          espera = false;
          binario += '1';
          conteo=conteo+1;
        }
        else{
          //Serial.println("Se detecto 0");
          espera = false;
          binario += '0';
          conteo=conteo+1;

        }
      }
    }
    }
    if (conteo==8 && letra==false){
      //Serial.println("Se transmitió la letra");
      letra=true;
      char caracter = (char)strtol(binario.c_str(), NULL, 2);
      Serial.println(caracter);
      delay(300);
      conteo=0;
    }
}
