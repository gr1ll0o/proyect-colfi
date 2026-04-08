int led = 6;
int brillo;
String texto = "01000001";

void setup() {
  // put your setup code here, to run once:
  pinMode(6, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(led, LOW);

  for (int i = 0; i < texto.length(); i++) {
    char c = texto.charAt(i); // Obtiene el carácter en la posición i
    Serial.print("Caracter: ");
    Serial.println(c);

  }

  /*
  analogWrite(led, 0); // APAGADO
  delay(1000);
  analogWrite(led, 30); // 0
  delay(1000);
  analogWrite(led, 255); // 1
  delay(1000); */
}
