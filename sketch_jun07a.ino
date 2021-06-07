/*
 * UNIDAD V: FUNCIONES ESPECÍFICAS
 * DEBER 5.2: MANEJO DE MODOS SLEEP
 * OBJETIVO: Realizar un control de modos de sleep por medio de interrupciones
 * MODO SLEEP Y DE AHORRO DE BATERIA
 *    Consumo es de 100-500mA 
 *    Ahorro de bateria es de hasta 10mA
 * Librerías:   avr/sleep.h
 *              avr/power.h  
 * Nombre: Pablo Ulcuango
 */

 #include <avr/sleep.h>
 #include <avr/power.h>
 #include <avr/wdt.h>
 #include <MsTimer2.h>
 #include <EEPROM.h>

 int dato;
 int on=0;

void(*resetFunc) (void)=0;         //es la función para el reseteo  //void on (void)--método dentro de otro método

void setup() {
  dato=EEPROM.read(0);
  Serial.begin(9600);
  Serial.println("SETUP");
  if (dato==0){
    set_sleep_mode(SLEEP_MODE_STANDBY);
    sleep_enable();
    EEPROM.write(0,1);
    wdt_enable(WDTO_8S);
  }
  else{
    sleep_disable();
      EEPROM.write(0,0);
      MsTimer2::set(10000, Tiempo_espera);      //cofiguración de timer2 a 1seg
      MsTimer2::start();
  }
  attachInterrupt(0,encender,LOW);
}

void loop() {
  if (dato==0){
    Serial.println("DORMIDO");
    delay(1000);
    sleep_mode();
  }
  else{
    Serial.println("DESPIERTO");
    delay(500);
    sleep_mode();
}
}
void Tiempo_espera(){
  Serial.println("DORMIDO");
  delay(1000);
}

void encender(){
  resetFunc();                    //llamando al método
}
