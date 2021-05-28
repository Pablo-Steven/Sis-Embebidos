/*UNIVERSIDAD TÉCNICA DEL NORTE
FICA-CITEL
SISTEMAS EMBEBIDOS
DEBER 5.1: Funciones Específicas - Memoria EEPROM
Nombre: Ulcuango Pablo
Fecha: 27-05-2021
Docente: Ing. Pamela Godoy
*/

#include <LiquidCrystal.h>
#include <Keypad.h>
#include <EEPROM.h>

LiquidCrystal lcd(13,12,11,10,9,8);

char reiniciar;
int i=0;
int j=0;
int dato;
char DATO[15], POS[1];
const byte filas = 4; 
const byte columnas = 4;
byte pinesFilas[]  = {7,6,5,4};
byte pinesColumnas[] = {3,2,A0,A1};
char teclas[4][4] = {{'7','8','9','A'},
                     {'4','5','6','B'},
                     {'1','2','3','C'},
                     {'*','0','#','<'}};
Keypad teclado1 = Keypad( makeKeymap(teclas), pinesFilas, pinesColumnas, filas, columnas);  
void setup() {
  lcd.begin(20,4);
  lcd.setCursor(0,0);
  lcd.print("PABLO ULCUANGO");
  lcd.setCursor(0,1);
  lcd.print("INGRESE CARACTER");
  Serial.begin(9600);
  Serial.println("Teclado MATRICIAL");
  Serial.println();
}
void loop() {
  char tecla_presionada = teclado1.getKey();
  if(tecla_presionada){
    lcd.setCursor(0,1);
    lcd.print("REGISTRANDO DATOS");
    lcd.setCursor(0,2);
    lcd.print(tecla_presionada);
    DATO[i]=tecla_presionada;
    i++;
    for(int h=0;h<16;h++){
    EEPROM.write(h,DATO[h]);
    }
    if(i==15){
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.println("GRABADO");
      i=0;
    }
    POS[j]=tecla_presionada;
    if(POS[0]=='<'){
      lcd.clear();
      lcd.setCursor(0,1);
      lcd.print("Datos grabados");
      lcd.setCursor(0,1);
      for(int k=0;k<16;k++){
      reiniciar=EEPROM.read(k);
      lcd.print(reiniciar);
      }
      delay(2000);
      i=0;
      j=0;
      lcd.clear();
      lcd.setCursor(0,1);
      lcd.print("INGRESE DATOS");
    }
  }
}
/*  //Monitor Serial
  if (tecla_presionada)
  {
    Serial.print("Tecla: ");
    Serial.println(tecla_presionada);
  } 
}
*/
