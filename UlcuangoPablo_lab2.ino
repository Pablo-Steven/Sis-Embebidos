/*
 * UNIVERSIDAD TÉCNICA DEL NORTE
 * FICA-CITEL
 * SISTEMAS EMBEBIDOS
 * NOMBRE: ULCUANGO PABLO 
 * FECHA: 20/05/2020
 * Laboratorio 2 : COMUNICACIÓN - CAD - INTERRUPCIONES 
 */
#include <MsTimer2.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd{13,12,11,10,9,8};

int h=0;
int m=0;
int s=0;

int j=0;
int i=0;

int hora;
int minuto;

int activarL=0;

int alarma=0;

void setup() {
  Serial.begin(9600);
  lcd.begin(16,2);

  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  
  attachInterrupt(0,on,FALLING);
  attachInterrupt(1,modo,FALLING);

  MsTimer2::set(100,reloj);
  MsTimer2::stop();
}

void loop() {
//-------------MODO 1-------------------
  if(j==1 && i==1){
    activarL=1;
    alarma=0;
    }
//----------------MODO 2--------------------
  if(j==1 && i==2){
    activarL=0;
    hora=analogRead(0);
    minuto=analogRead(1);

    h=map(hora,0,1023,0,23);
    m=map(minuto,0,1023,0,59);

  lcd.setCursor(0,1);
  lcd.print("                ");
  lcd.setCursor(0,1);
  lcd.print("Time: ");
  lcd.print(h);
  lcd.print(":");
  lcd.print(m);
  lcd.print(":");
  lcd.print(s);

  delay(200);
    }
//--------------- MODO 3------------------
  if(j==1 && i==3){
    if(digitalRead(A2)==HIGH || digitalRead(A3)==HIGH || digitalRead(A4)==HIGH){
      alarma=1;
      delay(100);
      }
    if(alarma==1){
      Serial.println("Peligro - ALARMA ON");
      }
    }

}


void reloj(){
//-------------RELOJ----------------
  m++;
  if(m==60){
    h++;
    m=0;
    }
  if(h==24){
    h=0;
    }
  lcd.setCursor(0,1);
  lcd.print("                ");
  lcd.setCursor(0,1);
  lcd.print("Time: ");
  lcd.print(h);
  lcd.print(":");
  lcd.print(m);
  lcd.print(":");
  lcd.print(s);
  
//------------ACTIVAR LUCES--------------------
   if(activarL==1 && (m==20 || m==40 || m==60)){
     Serial.println("Luces");
     int Nr=random(4,8);
    digitalWrite(Nr,HIGH);
    
    }
  
  }

void on(){
  j=1-j;
  if(j==0){
    MsTimer2::stop();
    lcd.clear();
//    lcd.setCursor(0,0);
//    lcd.print("++++APAGADO+++++");
//    lcd.setCursor(0,1);
//    lcd.print("++++++++++++++++");
//
//    delay(700);
    
    }
    else{
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(" ELIGE UN MODO: ");
    MsTimer2::start();
      }
  }

void modo(){
  i++;
  switch(i){
    case 1:
    lcd.setCursor(0,0);
    lcd.print("1. ACTIVAR LUCES");
    
    break;

    case 2:
    lcd.setCursor(0,0);
    lcd.print("2.CAMBIO DE HORA");
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
    activarL=0;
    MsTimer2::stop();
    break;

    case 3:
    lcd.setCursor(0,0);
    lcd.print("3.   SEGURIDAD  ");
    MsTimer2::start();
    
    break;

    default:
    i=0;
    break;
    
    }
  }
