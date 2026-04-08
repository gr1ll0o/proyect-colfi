const int ldrPin = A0;
const int ledPin = 13;

int umbral = 500;
bool espera = false;

void setup() {
    Serial.begin(9600);
    pinMode(ledPin, OUTPUT);
}

void loop() {
    if (espera == false) {
        espera = true;
    }
    if (espera && analogRead(ldrPin))
}