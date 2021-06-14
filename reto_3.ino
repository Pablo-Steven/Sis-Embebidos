
int boton = 8;
void setup() {
  pinMode(boton, INPUT); 
  Serial.begin(9600); 
}
void loop() {
  Serial.print(digitalRead(8));
  delay(500); 
  if (digitalRead(boton) == 0) {
    Serial.println("Boton Activado");
  }
}
