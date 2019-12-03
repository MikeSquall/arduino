/*

char NOMBRE[10]  = "BTDENIS01";    // le nom du module
char BPS         = '4'        ;           // 1=1200 , 2=2400, 3=4800, 4=9600, 5=19200, 6=38400, 7=57600, 8=115200
char PASS[10]    = "1234"     ;   // le mot de passe        
int pinLed = 8                ;

void setup()
{
   Serial.begin(9600)         ;
   pinMode(13,OUTPUT)         ;
   digitalWrite(13,HIGH)      ;
   delay(10000)               ;
   digitalWrite(13,LOW)       ;
   
   Serial.print("AT")         ; 
   delay(1000)                ;

   Serial.print("AT+NAME")    ; 
   Serial.print(NOMBRE)       ;
   delay(1000)                ;

   Serial.print("AT+BAUD")    ;    
   Serial.print(BPS)          ; 
   delay(1000)                ;

   Serial.print("AT+PIN")     ;
   Serial.print(PASS)         ; 
   delay(1000)                ;  

   pinMode(pinLed, OUTPUT)    ;  
}

void loop()
{
   digitalWrite(13, !digitalRead(13))  ;
   delay(500)                          ;
}
*/

//**********************************************
// Module bluetooth HC06  envoi de commandes AT
// et affichage de la réponse du module
// D'après http://nicolasz68.blogspot.fr/2012/09/module-bluetooth-jy-mcu-v104-pour.html
//
//
//***********************************************/* 
/* 
#include <SoftwareSerial.h>  //Software Serial Port  
#define RxD 2    //Pin 2 pour RX (pin0=serial) vert
#define TxD 3    //Pin 3 pour TX, on peut changer noir
SoftwareSerial BTSerie(RxD,TxD);  

void setup()  
{  
  Serial.begin(9600);    //115200 si on veut
  delay(500);  
  Serial.println("Bonjour - Pret pour les commandes AT");  
  // Configuration du bluetooth  
  pinMode(RxD, INPUT);  
  pinMode(TxD, OUTPUT);  
  BTSerie.begin(57600);  //57600
  delay(500);  
  BTSerie.print("AT+VERSION");  //Demande le N° de version
  delay(1000);  
  // BTSerie.print("\n");  
}  
void loop()  
{  
  char recvChar;  
  //On lit caractere par caractere sur le BTSerie et on affiche sur le Terminal Serie  
  if (BTSerie.available()) {  
    recvChar = BTSerie.read();  
    Serial.print(recvChar);  
  }  
  // Serial.write(blueToothSerial.read());  
  if (Serial.available()) {  
    recvChar = Serial.read();  
    BTSerie.write(recvChar);  
  }  
} 
*/
