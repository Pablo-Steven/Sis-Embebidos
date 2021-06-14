/*
 * CAPITULO VI
 * DEBER 6.1_SE
 * NOMBRE: Pablo Ulcuango
 * RETO 4 :La interfaz de Processing contará con un botón virtual, el cual al dar 
           click derecho sobre éste, transmitirá serialmente un dato que le informará 
           a la tarjeta Arduino que deberá de encender un LED y si se da click 
           izquierdo, deberá apagarlo
 */
import processing.serial.*;
Serial miPuerto;

void setup() {
  size(400, 400);
  miPuerto = new Serial(this,"COM14",9600);

  background(#D0D8D7);
  fill(#FF0313);
  stroke(#FF0313);
  ellipse(200, 200, 100, 100);
  fill(#0A0A0A);
  textSize(20);
  textAlign(CENTER);
  text("PRESIONE CLIC DERECHO", 200, 70);
  text("PARA ENCENDER LED", 200, 90);
  fill(#FAFFFE);
  textSize(15);
  text("¡APAGADO!", 200, 200);
}

void draw (){
}

void mousePressed() {
  if (mouseButton == RIGHT) {
    miPuerto.write('A');
    background(#D0D8D7);
    fill(#18FA05);
    stroke(#18FA05);
    ellipse(200, 200, 100, 100);
    fill(#0A0A0A);
    textSize(20);
    textAlign(CENTER);
    text("PRESIONE CLIC DERECHO", 200, 70);
    text("PARA ENCENDER LED", 200, 90);
    fill(#FAFFFE);
    textSize(15);
    text("¡ENCENDIDO!", 200, 200);
  
  }
  
  if(mouseButton == LEFT){
   miPuerto.write('B');
    background(#D0D8D7);
    fill(#FF0313);
    stroke(#FF0313);
    ellipse(200, 200, 100, 100);
    fill(#0A0A0A);
    textSize(20);
    textAlign(CENTER);
    text("PRESIONE EL BOTÓN", 200, 70);
    text("PARA APAGAR EL LED", 200, 90);
    fill(#FAFFFE);
    textSize(15);
    text("APAGADO", 200, 200);
    
  }
}
