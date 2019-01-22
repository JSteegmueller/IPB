// Setup( läuft 1mal, dann nimmer)
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

// looping
void loop() {
  // liest den analogPin A0
  double wert = analogRead(A0);
  // "Printed" den wert
  Serial.println(-1*((wert/1023*100)-100));
  delay(1000);        // Programmstopp in ms ( 1000ms = 1s )
}
