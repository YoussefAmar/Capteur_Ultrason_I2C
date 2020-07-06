#include <Wire.h>		//Librairie pour l'utilisation de l'I2C
#include <LiquidCrystal.h> //Librairie pour l'utilisation du LCD



LiquidCrystal lcd(12, 11, 5, 4, 3, 2);


int cm1,cm2, cm;
char ss[20];



void setup()
{
  Wire.begin();	//Début de la communication en I2C
  
  lcd.begin(16, 2);		//Début de la communication avec le LCD
  lcd.print("AMAR  YOUSSEF");	//Affichage de la 1er ligne du LCD
}

void loop()
{
 lcd.setCursor(0,1);	//On place le cursor dans la 2eme ligne du LCD
 Wire.requestFrom(3,2);	//Demande de l'information par I2C
 cm1 = Wire.read() ;	//Lecture du 1er octet
 cm2 = Wire.read() ;	//Lecture du 2er octet
 cm = (cm2 << 8) + cm1;	//Placement des 2 octets dans une variable
  
 sprintf(ss,"%03i",cm);	//Limite la distance à 3 digits
 lcd.print(ss);			//Affiche la distance
 lcd.print(" cm");
 
 delay(1000);
}
