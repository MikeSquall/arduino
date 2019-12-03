//déclaration des variables
int ledHautGauche=2;
int ledBasGauche=3;
int ledCentre=4;
int ledHautDroite=6;
int ledBasDroite=5;

//fonction d'initialisation
void setup() {
  //mise en mode OUTPUT des pins 2 à 6 et positionnement en LOW
  for (int t=2;t<7;t++){
    pinMode(t,OUTPUT);
    digitalWrite(t,LOW);
  }
}

//boucle principale
void loop() {
  // boucle pour faire varier le nombre
  for (int nb=0;nb<6;nb++){
    affichage(nb);//appel de la fonction d'allumage des LEDs
    delay(500);
  }
}

// déclaration des fonctions

//cette fonction sert à éteindre toutes les diodes
void setZero(){
  for (int t=2;t<7;t++){
    digitalWrite(t,LOW);
  }
}

//cette fonction récupère un nombre et allume les LED en conséquence
void affichage(int nombre){
  setZero();//appel de la fonction qui éteint toutes les LED
    
  //il suffit maintenant d'allumer les bonnes diodes
  //en testant la valeur de 'nombre'
  if (nombre==1){
    digitalWrite(ledCentre,HIGH); //on allume la diode du centre
    return;//sortie de la fonction
  }
  if (nombre==2){
    //on allume les diodes haut/droite et bas/gauche
    digitalWrite(ledHautGauche,HIGH);
    digitalWrite(ledBasDroite,HIGH);
    return;//sortie de la fonction
  }
  if (nombre==3){
    //on allume les diodes centre, haut/gauche, bas/droite
    digitalWrite(ledHautDroite,HIGH);
    digitalWrite(ledCentre,HIGH);
    digitalWrite(ledBasGauche,HIGH);
    return;//sortie de la fonction
  }
  if (nombre==4){
    //on allume toutes les diodes sauf celle du centre
    digitalWrite(ledHautGauche,HIGH);
    digitalWrite(ledHautDroite,HIGH);
    digitalWrite(ledBasGauche,HIGH);
    digitalWrite(ledBasDroite,HIGH);
    return;//sortie de la fonction
  }
  if (nombre==5){
    //on allume toutes les diodes
    digitalWrite(ledHautGauche,HIGH);
    digitalWrite(ledBasGauche,HIGH);
    digitalWrite(ledHautDroite,HIGH);
    digitalWrite(ledBasDroite,HIGH);
    digitalWrite(ledCentre,HIGH);
    return;//sortie de la fonction
  }
  //inutile de tester le 0 car on a commencé par tout éteindre
  return;//sortie de la fonction
}


