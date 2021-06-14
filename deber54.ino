/*
 * CAPITULO V:  Funciones Específicas 
 * DEBER 5.4_SE
 * TEMA:  Manejo de modos Sleep
 * Instrucciones:Realizar el funcionamiento de un semáforo basados en las funciones y tareas de RTOS.
 * NOMBRE: Pablo Ulcuango
 */
 
#include <Arduino_FreeRTOS.h> // librería de RTOS
 
#define rojo 10                 //Pin 8 led Rojo
#define amarillo  9             //Pin 9 led amarillo
#define verde 8               //Pin 10 led verde  
          
//objeto del gestor tareas
typedef int TaskProfiler;
//definir las tareas
TaskProfiler rojoProfiler;
TaskProfiler amarilloProfiler;
TaskProfiler verdeProfiler;
int monitor_suspend=0;

void setup() {
Serial.begin(9600);
//crear las rutinas de cada tarea
xTaskCreate(rojoControllerTask,"rojo LED Task",100,NULL,1,NULL);               //rutina,nombre,memoria,NULL,prioridad,NULL
xTaskCreate(amarilloControllerTask,"amarillo LED Task",100,NULL,1,NULL);       //rutina,nombre,memoria,NULL,prioridad,NULL
xTaskCreate(verdeControllerTask,"verde LED Task",100,NULL,1,NULL);             //rutina,nombre,memoria,NULL,prioridad,NULL
  digitalWrite(rojo, LOW);
  digitalWrite(amarillo, LOW);
  digitalWrite(verde, LOW);
}


void rojoControllerTask(void *pvParameters){                                   //tarea LED ROJO
  pinMode(rojo,OUTPUT);
  while(1){
      rojoProfiler++;
      Serial.print("rojo");
      Serial.println(rojoProfiler);
      digitalWrite(rojo,digitalRead(rojo)^1);
       vTaskDelay(200);
    }
}

void amarilloControllerTask (void *pvParameters){                             //tarea LED AMARILLO
 pinMode(amarillo,OUTPUT);
 while(1){
      amarilloProfiler++;
      Serial.print("amarillo:");
      Serial.println(amarilloProfiler);
      digitalWrite(amarillo,digitalRead(amarillo)^1);
     vTaskDelay(200);
  } 
 }
void verdeControllerTask (void *pvParameters){
 pinMode(verde,OUTPUT);
  while(1){
      verdeProfiler++;
      Serial.print("verde:");
      Serial.println(verdeProfiler);
      digitalWrite(verde,digitalRead(verde)^1);      
      monitor_suspend++;
      if(monitor_suspend==3){
        if(digitalRead(rojo==HIGH)){
       digitalWrite(verde,LOW); 
       digitalWrite(amarillo,LOW); 
       delay(1000);
      }      
      }
       if(monitor_suspend==4){
      if(digitalRead(amarillo==HIGH)){
      digitalWrite(rojo,LOW); 
      digitalWrite(verde,LOW); 
       delay(1000);
      }      
      }  
      if(monitor_suspend==5){
      if(digitalRead(verde==HIGH)){
      digitalWrite(rojo,LOW); 
      digitalWrite(amarillo,LOW);
       delay(1000); 
      }      
     // monitor_suspend=0;    
      }
      vTaskDelay(200);
    } 
 }

void loop() {
}
