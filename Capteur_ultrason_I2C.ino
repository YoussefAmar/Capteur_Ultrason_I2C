#include <Wire.h> //Librairie pour l'utilisation de l'I2C

//Pins capteur
#define eco 4    //Pin de l'eco
#define trigger 5 //Pin du trigger

int cm;
char b[2];

void setup()
{
 Wire.begin(3);   //Début de la communication en I2C
 Wire.onRequest(demande);
  
 pinMode(trigger,OUTPUT);
 pinMode(eco,INPUT);
}

void loop()
{
 cm = Distance(trigger,eco);
 demande();
 delay(100);
}



//Fonction qui va répondre à une demande de communication en I2C
void demande()
{
 b[0]=lowByte(cm);
 b[1]=highByte(cm);
 Wire.write(b,2);
}

//Définition de la fonction qui renvoie la distance de l'impulsion ultrasonore

long Distance(int triggerPin, int ecoPin)
{
 pinMode(triggerPin, OUTPUT); // Supprime le trigger
 digitalWrite(triggerPin, LOW);
 delayMicroseconds(2);
 digitalWrite(triggerPin, HIGH); // Active le trigger durant 10mm secondes
 delayMicroseconds(10);
 digitalWrite(triggerPin, LOW);
 pinMode(ecoPin, INPUT);
 return 0.01723 * pulseIn(ecoPin, HIGH); //Renvoie la distance en cm
}
