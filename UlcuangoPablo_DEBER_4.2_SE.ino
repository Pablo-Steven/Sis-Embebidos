/*UNIVERSIDAD TÉCNICA DEL NORTE
FICA-CITEL
SISTEMAS EMBEBIDOS
DEBER 4.2: Periféricos Especiales - Interrupciones
Nombre: Ulcuango Pablo
Fecha: 21-05-2021
Docente: Ing. Pamela Godoy
*/

const int leds[6]={13,12,11,10,9,8};        //define pines de leds
int on=0;                                   //interrupcion int 0 pin2
int cont;                                   //interrupcion int 1 pin3
int i;
int j=0;                                    //variable de conteo

void setup() {
for(i=0;i<6;i++){                           //incremento de leds de uno en uno
  pinMode(leds[i],OUTPUT);                  //salida de leds  
  }
  i=0;
  Serial.begin(9600);
  attachInterrupt(0,activacion,RISING);        //habilitacion de la interrupcion 0 llamada activacion
  attachInterrupt(1,contador,RISING);          //habilitacion de la interrupcion 1 llamada contador
}


void loop() {
  if(on==2){
    for(;i<cont;i++){
      for(j=0;j<6;j++){
        digitalWrite(leds[j],HIGH);
        delay(200);        
        digitalWrite(leds[j],LOW);
        delay(200);
      }
      
    }
  }
}

void activacion(){
switch (on){                                //opciones de los botones 
  case 0:
  Serial.println("Inicio del sistema");
  Serial.println("Ingrese el numero de veces a jugar");
  on++;
  break;
  case 1:
  Serial.println("Inicio del juego");
  on++;
  break;
  case 2:
  Serial.println("Fin del juego");
  cont=0;
  on=0;
  i=0;
  break;
} 
}

void contador(){
  if(on==1){
    cont++;
    Serial.print(String("JUEGA!!! ")+String(cont)+String(" veces\n"));    
    }
}
