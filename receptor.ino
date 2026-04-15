const int ldrPin = A0;
const int ledPin = 13;
int lectura;
int iguales = 0;

int umbral = 500;
bool espera = false;
void setup() {
  Serial.begin(9600);
  pinMode(ldrPin, INPUT);
  Serial.println("--------------");
}

void loop() {
  lectura = analogRead(ldrPin);
  Serial.println(lectura);
  if (lectura>80 || iguales==1){
    iguales=1;
    if (espera==false && lectura<20){
      espera = true;
      delay(930);
    }
    else
    {
      if (espera==true){
        if (lectura>80){
          Serial.println("Se detecto 1");
          espera = false;
        }
        else{
          Serial.println("Se detecto 0");
          espera = false;
        }
      }
    }
    }
    else{
  }
}
