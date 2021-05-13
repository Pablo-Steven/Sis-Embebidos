/* PRACTICA DE LABORATORIO 1
 *  NOMBRE: PABLO ULCUANGO
 *  FECHA:13-05-2021
 *  MATERIA:SISTEMAS EMBEBIDOS
 *  DOCENTE: ING. PAMELA GODOY
 *  TÉCNICO DOCENTE: ING. ALEJANDRA PINTO 
 * 
 */
 
#include <LiquidCrystal.h>                 //permite utilizar la lcd 
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);   //definir los pines de la lcd

String pass1="ad102344";                   //Introducción de variable tipo string para la contraseña de usuario
String pass2="dc774235";                   //Introducción de variable tipo string para la contraseña de usuario
String pass3="ca543187";                   //Introducción de variable tipo string para la contraseña de usuario
String pass4="pu951213";                   //Introducción de variable tipo string para la contraseña de usuario
String nombre1="Ariel Davalos";            //Introducción de variable tipo string para el nombre se usuario 
String nombre2="Damian Cervantes";         //Introducción de variable tipo string para el nombre se usuario 
String nombre3="Carlos Benavides";         //Introducción de variable tipo string para el nombre se usuario 
String nombre4="Pablo Ulcuango";           //Introducción de variable tipo string para el nombre se usuario 
String dato; 
int a=0;                                  // para terminar un ciclo de contraseña e iniciar el ciclo de mensaje de bienvenida 
int cont=0;                               // las veces que se muestra el mensaje de bienvenido 
int estado1=0;                            //para saber si ya a ingresado la contraseña 
int estado2=0;
int estado3=0;
int estado4=0;

void setup() {
  pinMode(7,INPUT);
  Serial.begin(9600);                     // iniciar la comunicacion serial
  lcd.begin(16,2);                        // iniciar la lcd columnas y filas del display 
  lcd.setCursor(0,0);
  lcd.print("Insert pass");
  delay(1000);
}

void loop() {
  if (Serial.available()>0 && a==0){                  //para detectar la comunacaión serial en el teminal virtual 
     
    dato=Serial.readString();                         // se ingresa la contraseña y se guarda el dato
    if (dato==pass1 || dato==pass2 || dato==pass3 || dato==pass4) {
      lcd.setCursor(0,1);
      lcd.print("Right pass");
      Serial.println("");                             //salto de linea en el terminal virtual
      delay(1000);  
      lcd.clear();
      a=1;
    }
    else{
      lcd.setCursor(0,1);
      lcd.print("Error pass");
      Serial.println("");
      delay(1000);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Insert pass");   
    }     
  }
  
if (a==1){
  imprimirID();
  cont++;
}
if (cont==2){
  a=0;
  lcd.setCursor(0,0);
  lcd.print("Insert pass");
  if (dato==pass1){
    estado1=1;
  }
  else if (dato==pass2){
    estado2=1;
  }
  else if (dato==pass3){
    estado3=1;
  }
  else if (dato==pass4){
    estado4=1;
  }
  cont=0;  
  
}
 if (digitalRead(7)==HIGH){
  Serial.println("");
  Serial.print("Ariel Davalos");
  if (estado1==1){
  Serial.print(" **REGISTRADO**  "); 
  }
  else{
    Serial.print(" **AUSENTE**  ");
    
  }
  Serial.println("");
  Serial.print("Damian Cervantes");
  if (estado2==1){
  Serial.print(" **REGISTRADO**  "); 
  }
  else{
    Serial.print(" **AUSENTE**  ");
    
  }
  Serial.println("");
  Serial.print("Carlos Benavides");
  if (estado3==1){
  Serial.print(" **REGISTRADO**  "); 
  }
  else{
    Serial.print(" **AUSENTE**  ");
    
  }
   Serial.println("");
  Serial.print("Pablo Ulcuango");
  if (estado4==1){
  Serial.print(" **REGISTRADO**  "); 
  }
  else{
    Serial.print(" **AUSENTE**  ");
    
  }
  Serial.println("");
  delay(400);
 }
  
  }

void imprimirID(){
  if (dato==pass1){
  for (int y=-15;y<16;y++){ 
  lcd.setCursor(y,0);// lugar donde inicia el texto
  lcd.print("  BIENVENIDO  ");
  lcd.setCursor(y,1);// lugar donde inicia el texto
  lcd.print(nombre1);
  delay(50);
  lcd.clear();
   
}
  }
  if (dato==pass2){
  for (int y=-15;y<16;y++){ 
  lcd.setCursor(y,0);// lugar donde inicia el texto
  lcd.print("  BIENVENIDO  ");
  lcd.setCursor(y,1);// lugar donde inicia el texto
  lcd.print(nombre2);
  delay(50);
  lcd.clear();
   
}
  }
  if (dato==pass3){
  for (int y=-15;y<16;y++){ 
  lcd.setCursor(y,0);             // lugar donde inicia el texto
  lcd.print("  BIENVENIDO  ");
  lcd.setCursor(y,1);             // lugar donde inicia el texto
  lcd.print(nombre3);
  delay(50);
  lcd.clear();   
   }
  }
  if (dato==pass4){
  for (int y=-15;y<16;y++){ 
  lcd.setCursor(y,0);             // lugar donde inicia el texto
  lcd.print("  BIENVENIDO  ");
  lcd.setCursor(y,1);             // lugar donde inicia el texto
  lcd.print(nombre4);
  delay(50);
  lcd.clear();   
   }
  }
}
