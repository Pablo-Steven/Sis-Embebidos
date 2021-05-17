 /*UNIVERSIDAD TÉCNICA DEL NORTE
 * FICA-CITEL
 * SISTEMAS EMBEBIDOS 
 * ////////DEBER 4.1///// 
 * NOMBRE: Ulcuango Pablo
 * FECHA:17-05-2021
 * DOCENTE: Ing. Pamela Godoy
 * 
 * TEMA:CAD Y PWM. 
 * 
  */

#include <LiquidCrystal.h>            //inicializar lalibreria para la LCD
LiquidCrystal lcdmotor1(13,12,5,4,3,2);    //asignar pines para la lcd1
LiquidCrystal lcdmotor2(9,8,7,6,1,0);      //asignar pines para la lcd2

int conversormotor1;
int conversormotor2;
float voltajemotor1;
float voltajemotor2;
int duttymotor1;
int duttymotor2;


void setup() {
  lcdmotor1.begin(16,2);
  lcdmotor2.begin(12,2);
}

void loop() {

  conversormotor1=analogRead(A0);
  voltajemotor1=(conversormotor1*0.5)/1023.0;
  duttymotor1=conversormotor1/4;
  analogWrite(11,duttymotor1);
  lcdmotor1.setCursor(0,0);
  lcdmotor1.print("CAD");
  lcdmotor1.setCursor(5,0);
  lcdmotor1.print(conversormotor1);
  lcdmotor1.setCursor(0,1);
  lcdmotor1.print("V: ");
  lcdmotor1.setCursor(3,1);
  lcdmotor1.print(voltajemotor1);
  lcdmotor1.setCursor(9,1);
  lcdmotor1.print("PWM: ");
  lcdmotor1.setCursor(13,1);
  lcdmotor1.print(duttymotor1*100/255);
  delay(300);


  conversormotor2=analogRead(A1);
  voltajemotor2=(conversormotor2*0.5)/1023.0;
  duttymotor2=conversormotor2/4;
  analogWrite(10,duttymotor2);
  lcdmotor2.setCursor(0,0);
  lcdmotor2.print("CAD");
  lcdmotor2.setCursor(5,0);
  lcdmotor2.print(conversormotor2);
  lcdmotor2.setCursor(0,1);
  lcdmotor2.print("V: ");
  lcdmotor2.setCursor(3,1);
  lcdmotor2.print(voltajemotor2);
  lcdmotor2.setCursor(9,1);
  lcdmotor2.print("PWM: ");
  lcdmotor2.setCursor(13,1);
  lcdmotor2.print(duttymotor2*100/255);
  delay(300);
  //lcdmotor1.clear();
 // lcdmotor2.clear();
}
