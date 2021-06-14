/*
 * CAPITULO VI
 * DEBER 6.1_SE
 * NOMBRE: Pablo Ulcuango 
 * RETO 2
 */


int i=250;
void setup () {
  size (200, 200);
  fill(0, 0, 0);
  text("Presione el Botón para", 50, 15);
  text("Encender o Apagar el LED", 40, 25);
  noStroke ();
  fill(255, 0, 0);
  ellipse (100, 100, 100, 100);
  textAlign (CENTER);
  fill (255, 255, 255);
  text("Apagado", 100, 100);
}

void draw () {
}

/*void mouseClicked (){
 }*/

void mousePressed () {
  float Distancia = dist(mouseX, mouseY, 100, 100);
  if (Distancia<100) { 
    if (mousePressed==true) {
      if ( mouseButton == RIGHT) {
        fill(#892B2B);
        ellipse(100, 100, 100, 100);
      }
    }
    if ( mouseButton == LEFT) {
      fill(#188B16);
      ellipse(100, 100, 100, 100);
    }
  }
}

void mouseReleased() {
  float Distancia = dist(mouseX, mouseY, 100, 100);
  if (Distancia<100) { 
    if (mouseButton == RIGHT) {
      if (mousePressed==false) {
        fill(#1CFA19);
        ellipse(100, 100, 100, 100); 
        textAlign(CENTER); 
        textSize(19); 
        fill(255);
        text("Encendido", 100, 100);
        smooth();
        fill(#FA0808);
      }
    }
    if (mouseButton == LEFT) {
      if (mousePressed==false) {
        fill(#FA0808);
        ellipse(100, 100, 100, 100); 
        textAlign(CENTER); 
        textSize(20); 
        fill(255);
        text("Apagado", 100, 100);
        smooth();
        fill(#FA0808);
      }
    }
  }
}
