/*UNIVERSIDAD TÉCNICA DEL NORTE
 * FICA-CITEL
 * SISTEMAS EMBEBIDOS 
 * 
 * NOMBRE: Ulcuango Pablo
 * FECHA:06-05-2021
 * DOCENTE: Ing. Pamela Godoy
 * 
 * TEMA: Puertos como salidas. 
 * - Realizar el codigo necesario para encender 4 leds de forma síncrona,es decxir,
 *   encende uno por uno. Cada vez ue se enciende un led los demás deben estar apagados.
 * 
 */

 // variables de tipo entero (int)
 int led1 = 8;
 int led2 = 9;
 int led3 = 10;
 int led4 = 11;
 
void setup() {
  // asognación a los pines como salidas digitales 
 pinMode(led1,OUTPUT);
 pinMode(led2,OUTPUT);
 pinMode(led3,OUTPUT);
 pinMode(led4,OUTPUT);

}

void loop() {
 digitalWrite(led1, HIGH);  //envía 5v al pin8
 delay(500);               //se detiene el microcontrolador por medio segundo
 digitalWrite(led1, LOW);  //envía 0v al pin8
 delay(500);               //se detiene el microcontrolador por medio segundo
 digitalWrite(led2, HIGH);  //envía 5v al pin9
 delay(500);               //se detiene el microcontrolador por medio segundo
 digitalWrite(led2, LOW);  //envía 0v al pin9
 delay(500);               //se detiene el microcontrolador por medio segundo
 digitalWrite(led3, HIGH);  //envía 5v al pin10
 delay(500);               //se detiene el microcontrolador por medio segundo
 digitalWrite(led3, LOW);  //envía 0v al pin10
 delay(500);               //se detiene el microcontrolador por medio segundo
 digitalWrite(led4, HIGH);  //envía 5v al pin11
 delay(500);               //se detiene el microcontrolador por medio segundo
 digitalWrite(led4, LOW);  //envía 0v al pin11
 delay(500);               //se detiene el microcontrolador por medio segundo
}
