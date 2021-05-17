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
 ///////////// MASTER //////////////////
#include <Wire.h>
char dato;
int cont=0;

void setup() {
  Wire.begin();
  Serial.begin(9600);        // habilita la comunicación serial  
}

void loop() {
  if(Serial.available()){     // verificar si existe datos
    cont++;
    if(cont==1){
       dato=Serial.read();     // almacena el dato del serial en una variable  
       Wire.beginTransmission(4);// empieza la comunicacion I2C
       Wire.write(dato);       // envio dato
       Wire.endTransmission(); // termina la comunicacion I2C
       delay(1000);
    }
    else{
      if(cont==2){
       dato=Serial.read();     // almacena el dato del serial en una variable  
       Wire.beginTransmission(5);// empieza la comunicacion I2C
       Wire.write(dato);       // envio dato
       Wire.endTransmission(); // termina la comunicacion I2C 
       delay(1000);          
    }
    else{
      if(cont==3){
         dato=Serial.read();     // almacena el dato del serial en una variable  
       Wire.beginTransmission(6);// empieza la comunicacion I2C
       Wire.write(dato);       // envio dato
       Wire.endTransmission(); // termina la comunicacion I2C
       delay(1000);
       }
      }
    }
  }
}
