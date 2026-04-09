int led = 3;
int brillo;
String texto = "01000001";

void setup() {
  // put your setup code here, to run once:
  pinMode(3, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  analogWrite(led, 0);
  delay(1000);

  for (int i = 0; i < texto.length(); i++) {
    analogWrite(led, 0);
    delay(500);
    char c = texto.charAt(i); // Obtiene el carácter en la posición i
    Serial.print("Caracter: ");
    Serial.println(c);

    if (c == 0) {
      analogWrite(led, 20);
    }
    if (c== 1){
      analogWrite(led, 255);
    }
    delay(500);
  }
  analogWrite(led, 0);
  delay(10000);
  
  /*analogWrite(led, 0); // APAGADO
  delay(1000);
  analogWrite(led, 30); // 0
  delay(1000);
  analogWrite(led, 255); // 1
  delay(1000); */
}
