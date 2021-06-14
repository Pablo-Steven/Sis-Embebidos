/*
 * CAPITULO VI
 * DEBER 6.1_SE
 * NOMBRE: Pablo Ulcuango
 * RETO 4 :La interfaz de Processing contará con un botón virtual, el cual al dar 
           click derecho sobre éste, transmitirá serialmente un dato que le informará 
           a la tarjeta Arduino que deberá de encender un LED y si se da click 
           izquierdo, deberá apagarlo
 */
 

int led = 8;
byte byteRecibido=0; 


void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);
}

void loop() {
  if (Serial.available()>0) {
   byteRecibido = Serial.read();
    Serial.println();
    if(byteRecibido == 65){
      digitalWrite(led, HIGH);
    }
    else {//if(byteRecibido == 'B'){
      digitalWrite(led, LOW);
    }
  }
}
