 /*UNIVERSIDAD TÉCNICA DEL NORTE
 * FICA-CITEL
 * SISTEMAS EMBEBIDOS 
 * ////////DEBER 3.1///// 
 * NOMBRE: Ulcuango Pablo
 * FECHA:17-05-2021
 * DOCENTE: Ing. Pamela Godoy
 * 
 * TEMA:Comunicación I2C. 
 * 
  */
////////////////////////ESCLAVO 1////////////////////
#include<Wire.h>          // libreria I2C  
char dato;                // variable de almacenamiento de estado 
const int led1=8;         //led1 en pin 8
const int led2=9;         //led2 en pin 9
const int led3=10;        //led3 en pin 10

void setup() {
  Wire.begin(4);           // ID del esclavo 
  Wire.onReceive(receiveEvent);  //llamando al evento de recepción
  Serial.begin(9600);
  pinMode(led1,OUTPUT);    //pin8 como salida
  pinMode(led2,OUTPUT);    //pin9 como salida
  pinMode(led3,OUTPUT);    //pin10 como salida
}

void loop() {

}

void receiveEvent (int bytes){
  while(Wire.available()){
    dato=Wire.read();
     digitalWrite(led1, HIGH);  //envía 5v al pin8
 delay(20000);               //se detiene el microcontrolador por medio segundo
 digitalWrite(led1, LOW);  //envía 0v al pin8
 delay(500);               //se detiene el microcontrolador por medio segundo
 digitalWrite(led2, HIGH);  //envía 5v al pin9
 delay(20000);               //se detiene el microcontrolador por medio segundo
 digitalWrite(led2, LOW);  //envía 0v al pin9
 delay(500);               //se detiene el microcontrolador por medio segundo
 digitalWrite(led3, HIGH);  //envía 5v al pin10
 delay(20000);               //se detiene el microcontrolador por medio segundo
 digitalWrite(led3, LOW);  //envía 0v al pin10
 delay(500); 
  }
}
