const int ldrPin = A0;
const int ledPin = 13;
int lectura;
bool iguales = true;

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
  if (espera==false && lectura<20){
    espera = true;
  }
  else
  {
    if (espera==true){
      if (lectura>30 and lectura<100){
        Serial.println("Se detecto 0");
        espera = false;
      }
      else{if(lectura>120){
        Serial.println("Se detecto 1");
        espera = false;
      }
      }
    }
  }

}
