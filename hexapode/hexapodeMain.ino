#include <Servo.h>

/*********************************************************************
 * Developpeur: Clément Saulquin, Yannick Janssens
 * 
 * Projet: robot hexapode, projet 3A 
 * 
 * Date de création: 20/02/2019
 * 
 * Description: programme permettant de contrôler les différents
 * 
 * moteur du robot hexapode avec gestion des déplacement
 * 
 **********************************************************************/

 /* Définition des fonctions */
 void initAvance(void); //fonction qui permet d'initialiser le mouvement pour avancer
 void avancer(void);  //fonction qui permet au robot d'avancer
 void finAvance(void); //fonction qui permet de terminé le processus d'avancement
 void tourner(int angle); //fonction qui permet au robot de tourner

 /* Définitions des variables gloables */
 
 // angles initiaux des servo
int angleArtiInit = 90;
int angleJambeExtInit =60;
int angleJambeIntInit =100;

int delayGlobal = 100;
int interDelay =5;

// définition des servo
Servo derDroiteArti;
Servo derDroiteJambe;

Servo derGaucheArti;
Servo derGaucheJambe;

Servo devDroiteArti;
Servo devDroiteJambe;

Servo devGaucheArti;
Servo devGaucheJambe;

Servo milDroiteArti;
Servo milDroiteJambe;

Servo milGaucheArti;
Servo milGaucheJambe;
// Fonction d'initialisation
void setup() {

  
 
  /*Définition des Pin des sortie PWM */
  derDroiteArti.attach(2);
  derGaucheArti.attach(3);
  
  devDroiteArti.attach(4);
  devGaucheArti.attach(5);

  milDroiteArti.attach(6);
  milGaucheArti.attach(7);

  derDroiteJambe.attach(8);
  derGaucheJambe.attach(9);
  
  devDroiteJambe.attach(10);
  devGaucheJambe.attach(11);

  milDroiteJambe.attach(12);
  milGaucheJambe.attach(13);
  

  /* Initialisation des angles des différents servo*/
  derDroiteArti.write(angleArtiInit);
  derGaucheArti.write(angleArtiInit);
  devDroiteArti.write(angleArtiInit);
  devGaucheArti.write(angleArtiInit);
  milDroiteArti.write(angleArtiInit);
  milGaucheArti.write(angleArtiInit);

  derDroiteJambe.write(angleJambeExtInit);
  derGaucheJambe.write(angleJambeExtInit);
  devDroiteJambe.write(angleJambeExtInit);
  devGaucheJambe.write(angleJambeExtInit);
  milDroiteJambe.write(angleJambeIntInit);
  milGaucheJambe.write(angleJambeIntInit);



   derGaucheJambe.write(100);
   delay(interDelay);
   devGaucheJambe.write(80);
   delay(interDelay);
   milDroiteJambe.write(120);
   delay(interDelay);
   milGaucheJambe.write(80);
   delay(interDelay);

  /*Fin de l'initialisation */

  //int i=0;

 /* initAvance();
 
  for(i =0; i<20; i++)
  {
    avancer();
  }

  finAvance();

  tourner(180);

  initAvance();

  for(i =0; i<6; i++)
  {
    avancer();
  }

  finAvance();*/

  
  
}

/* Boucle principale */
/*void loop ()
{
  int i=0;
  
  initAvance();
 
  for(i =0; i<5; i++)
  {
    avancer();
  }

  finAvance();

  tourner(180);

  initAvance();

  for(i =0; i<6; i++)
  {
    avancer();
  }

  finAvance();
}*/


/*************************************************
 * Nom: initAvance
 * Entrée: void
 * Sortie: void
 * Description: Permet d'éffectuer le premier 
 * mouvement permettant d'entammer le mouvement
 * avant rebouclage
 * 
 **************************************************/
void initAvance(void)
{
  
  //lever des jambes
   derGaucheJambe.write(100);
   delay(interDelay);
   devGaucheJambe.write(80);
   delay(interDelay);
   milDroiteJambe.write(120);
   delay(interDelay);
   milGaucheJambe.write(80);
   delay(interDelay);
    
}

/*************************************************
 * 
 * Nom: avancer
 * Entrée: void
 * Sortie: void
 * Description: Permet de faire avancer le robot
 * avec une séquence de pas prédéfinis
 * 
 **************************************************/
void avancer(void)
{
   
   //On avance les articulation pour avancer le robot
   derGaucheArti.write(60);
   delay(5);
   devGaucheArti.write(60);
   delay(5);  
   milDroiteArti.write(110);
   

   delay(delayGlobal);  //On attends un peu avant d'effectuer la suite du mouvement
    
   //on repose les jambes précédemment lever
   //à la première utilisation, le lever de la jambe c'est fait dans la fonction initAvance()
   derGaucheJambe.write(angleJambeExtInit);
   delay(interDelay);
   devGaucheJambe.write(angleJambeExtInit-10);
   delay(interDelay);
   milDroiteJambe.write(angleJambeIntInit);

    delay(delayGlobal); //On attends un peu avant d'effectuer la suite du mouvement
    
   //On lève les trois autres jambes
   milGaucheJambe.write(110);
   delay(interDelay);
   derDroiteJambe.write(20);
   delay(interDelay);
   devDroiteJambe.write(100);
   

   delay(delayGlobal); //On attends un peu avant d'effectuer la suite du mouvement
   
   //On remet les articulation dans l'état initial pour faire avancer le robot
   derGaucheArti.write(angleArtiInit);
   delay(interDelay);
   devGaucheArti.write(angleArtiInit);
   delay(interDelay);  
   milDroiteArti.write(angleArtiInit);
   

   delay(delayGlobal); //On attends un peu avant d'effectuer la suite du mouvement
   
   //On avance les articulation pour la suite du mouvement
   milGaucheArti.write(60);
   delay(interDelay);
   derDroiteArti.write(120);
   delay(interDelay);
   devDroiteArti.write(120);

   delay(delayGlobal); //On attends un peu avant d'effectuer la suite du mouvement
   
   //On repose les jambes
   milGaucheJambe.write(angleJambeIntInit-10);
   delay(interDelay);
   derDroiteJambe.write(angleJambeExtInit);
   delay(interDelay);
   devDroiteJambe.write(angleJambeExtInit);

   delay(delayGlobal); //On attends un peu avant d'effectuer la suite du mouvement
   
   //lever jambe 1
   derGaucheJambe.write(100);
   delay(interDelay);
   devGaucheJambe.write(80);
   delay(interDelay);
   milDroiteJambe.write(120);
   delay(interDelay);
   milGaucheJambe.write(80);

   delay(delayGlobal);
   
   //avance articulation 2
   milGaucheArti.write(angleArtiInit);
   delay(interDelay);
   derDroiteArti.write(angleArtiInit);
   delay(interDelay);
   devDroiteArti.write(angleArtiInit);   
}

/*************************************************
 * Nom: finAvance
 * Entrée: void
 * Sortie: void
 * Description: Permet de terminer le mouvement
 * qui permet d'avancer  
 **************************************************/
void finAvance(void)
{
  
  //lever des jambes
   derGaucheJambe.write(angleJambeExtInit);
   delay(interDelay);
   devGaucheJambe.write(angleJambeExtInit);
   delay(interDelay);
   milDroiteJambe.write(angleJambeIntInit);
   delay(interDelay);
   milGaucheJambe.write(angleJambeIntInit-10);
   delay(interDelay);
    
}

void tourner(int angle)
{
  int nbTour =0;
  int i =0;
  
  if (angle>0)
  {
    nbTour =int(angle/15);

    for (i =0; i<nbTour; i++)
    {
        devDroiteJambe.write(angleJambeExtInit + 40);
        delay(interDelay);
        derGaucheJambe.write(angleJambeExtInit + 40);
        delay(delayGlobal);
        devDroiteArti.write(angleArtiInit + 30);
        delay(interDelay);
        derGaucheArti.write(angleArtiInit + 30);
        delay(delayGlobal);
        devDroiteJambe.write(angleJambeExtInit);
        delay(interDelay);
        derGaucheJambe.write(angleJambeExtInit);
        delay(delayGlobal);
      
        milDroiteJambe.write(angleJambeIntInit + 40);
        delay(interDelay);
        milGaucheJambe.write(angleJambeIntInit + 40);
        delay(delayGlobal);
        milDroiteArti.write(angleArtiInit + 30);
        delay(interDelay);
        milGaucheArti.write(angleArtiInit + 30);
        delay(delayGlobal);
        milDroiteJambe.write(angleJambeIntInit-5);
        delay(interDelay);
        milGaucheJambe.write(angleJambeIntInit-5);
        delay(delayGlobal);
      
        derDroiteJambe.write(angleJambeExtInit - 40);
        delay(interDelay);
        devGaucheJambe.write(angleJambeExtInit + 40);
        delay(delayGlobal);
        derDroiteArti.write(angleArtiInit + 30);
        delay(interDelay);
        devGaucheArti.write(angleArtiInit + 30);
        delay(delayGlobal);
        derDroiteJambe.write(angleJambeExtInit);
        delay(interDelay);
        devGaucheJambe.write(angleJambeExtInit);
        delay(delayGlobal);
      
        derDroiteArti.write(angleArtiInit);
        derGaucheArti.write(angleArtiInit);
        devDroiteArti.write(angleArtiInit);
        devGaucheArti.write(angleArtiInit);
        milDroiteArti.write(angleArtiInit);
        milGaucheArti.write(angleArtiInit);

        delay(delayGlobal);
    }
  }
  
  else if(angle<0)
  {
    nbTour =int(-angle/15);

    for(i =0; i<nbTour; i++)
    {
      devDroiteJambe.write(angleJambeExtInit + 40);
      delay(interDelay);
      derGaucheJambe.write(angleJambeExtInit + 40);
      delay(delayGlobal);
      devDroiteArti.write(angleArtiInit - 30);
      delay(interDelay);
      derGaucheArti.write(angleArtiInit - 30);
      delay(delayGlobal);
      devDroiteJambe.write(angleJambeExtInit);
      delay(interDelay);
      derGaucheJambe.write(angleJambeExtInit);
      delay(delayGlobal);
    
      milDroiteJambe.write(angleJambeIntInit + 40);
      delay(interDelay);
      milGaucheJambe.write(angleJambeIntInit - 40);
      delay(delayGlobal);
      milDroiteArti.write(angleArtiInit - 30);
      delay(interDelay);
      milGaucheArti.write(angleArtiInit - 30);
      delay(delayGlobal);
      milDroiteJambe.write(angleJambeIntInit-5);
      delay(interDelay);
      milGaucheJambe.write(angleJambeIntInit-5);
      delay(delayGlobal);
    
      derDroiteJambe.write(angleJambeExtInit - 40);
      delay(interDelay);
      devGaucheJambe.write(angleJambeExtInit + 40);
      delay(delayGlobal);
      derDroiteArti.write(angleArtiInit - 30);
      delay(interDelay);
      devGaucheArti.write(angleArtiInit - 30);
      delay(delayGlobal);
      derDroiteJambe.write(angleJambeExtInit);
      delay(interDelay);
      devGaucheJambe.write(angleJambeExtInit);
      delay(delayGlobal);
    
      derDroiteArti.write(angleArtiInit);
      derGaucheArti.write(angleArtiInit);
      devDroiteArti.write(angleArtiInit);
      devGaucheArti.write(angleArtiInit);
      milDroiteArti.write(angleArtiInit);
      milGaucheArti.write(angleArtiInit);

      delay(delayGlobal);
      
    }
  }
}
