//lien: http://www.fablabredon.org/wordpress/2017/12/17/lumiere-sur-larduino-avec-de-la-couleur-et-des-led/

#include <Adafruit_NeoPixel.h>
 
// On définit le pin où est connecté la patte DATA du bandeau
#define PIN 50
#define PIXEL_COUNT 60
 
// Parameter 1 = number of pixels in strip
// Parameter 2 = pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
 
//Ici, le 60 correspond au nombre de led
Adafruit_NeoPixel strip = Adafruit_NeoPixel(60, PIN, NEO_GRB + NEO_KHZ800);
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void setup()
{
  Serial.begin(9600);
   strip.begin(); // Lance la connection
   strip.show(); // Initialise toute les led à 'off'
}

/* Définition des couleurs */
int RED[3] = {255, 0, 0}; // Couleur Rouge
int GREEN[3] = {0, 255, 0}; // Couleur Verte
int CYAN[3] = {0, 255, 255}; // Couleur Cyan
int YELLOW[3] = {255, 125, 0}; // Couleur Jaune
int ORANGE[3] = {255, 40, 0}; // Couleur Orange
int PURPLE[3] = {255, 0 , 255}; // Couleur Violette
int Rose[3] = {255, 0, 100}; 
int BLUE[3] = {0, 0, 255}; // Couleur Bleu
int WHITE[3] = {255, 255, 255}; // Couleur Blanche


// Definition des variables des fonctions
int lumi=100;                                         //Luminosité 100%

  //fonction : cligno_bleu

int nb_cligno=10;                                     //nombre de clignotement en bleu
int time_tic=250;                                     //temps de clignotement

  //fonction : arc_en_ciel
int temp=10000;                                       //temps d'allumage arc-en-ciel
int time_tic3=50;                                     //temps allumage led 1 à 1

  //fonction : variation_lumi
int nb_vari=5;                                        // nombre de variation de lumi alumée-éteint éteint-allumé
int time_tic2=10;                                     //temps allumage led 1 à 1

  //fonction : ping_pong
int nb_aller_retour=3;                                //nombre d'aller retour
int time_tic4=10;                                     //temps allumage de la led

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void loop() 
{
 // cligno_bleu(lumi,nb_cligno,time_tic);    
  arc_en_ciel2(lumi,temp,time_tic3);
  
  variation_lumi( time_tic2, nb_vari, time_tic3);
  ping_pong(time_tic3,nb_aller_retour);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void cligno_bleu(int lumi,int nb_cligno, int time_tic)// Clignoter en bleu
{
  
 for ( int i =0; i < nb_cligno; i++)                  //répète le nombre de clignotement
 {
    lumi=0;                                           //luminosité min 0
    strip.setBrightness(lumi);                        //deffinie la luminosité
    strip.show();                                     //afficher
    delay(time_tic);                                  //Durée leds éteintes
    lumi=100;                                         //luminosité max 100
       
    strip.setBrightness(lumi);                        //deffinie la luminosité
    for(int i = 0 ; i < PIXEL_COUNT ; i++)            //allumer toutes les leds
        {
           strip.setPixelColor(i, 0, 0, 255);         //couleur leds
        }
     
 strip.show();                                        //afficher
 delay(time_tic);                                     // Durée leds allumées
 }
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void arc_en_ciel (int lumi,int temp)                  //allumage de toutes les leds en arc en ciel de 7 leds
{
 strip.setBrightness(lumi);                           //deffinie la luminosité
 for(int i = 0 ; i < PIXEL_COUNT ; i++)               //allumer toutes les leds
    {
     
       strip.setPixelColor(i, 255,0,0);               //couleur leds arc en ciel
       strip.setPixelColor(i+1, 255, 40, 0); 
       strip.setPixelColor(i+2,255, 125, 0);
       strip.setPixelColor(i+3,0, 255, 0);
       strip.setPixelColor(i+4,0, 255, 255);
       strip.setPixelColor(i+5,0, 0, 255);
       strip.setPixelColor(i+6,255, 0 , 255);
       
       i=i+6;                                         //allumage de 7 led en arc en ciel
       
    }
     
 strip.show();                                        //afficher 
 delay(temp);                                         //temps d'affichage
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void arc_en_ciel2 (int lumi,int temp,int time_tic3)   //allumage de toutes les leds en arc en ciel de 7 leds progressivement
{
  strip.setBrightness(0);                             //deffinie la luminosité nul
   strip.show();                                      //afficher 
  delay(500);                                               
 strip.setBrightness(lumi);
 for(int i = 0 ; i < PIXEL_COUNT ; i=i+7)             //allumer toutes les leds
    {
     
       strip.setPixelColor(i, 255,0,0);               //couleur rouge
        strip.show();
       delay(time_tic3);
       strip.setPixelColor(i+1, 255, 40, 0);          //couleur orange
        strip.show();
       delay(time_tic3);
       strip.setPixelColor(i+2,255, 125, 0);          //couleur jaune
        strip.show();
       delay(time_tic3);
       strip.setPixelColor(i+3,0, 255, 0);           //couleur vert
        strip.show();
       delay(time_tic3);
       strip.setPixelColor(i+4,0, 255, 255);         //couleur cyan
        strip.show();
       delay(time_tic3);
       strip.setPixelColor(i+5,0, 0, 255);           //couleur Bleu
        strip.show();
       delay(time_tic3);
       strip.setPixelColor(i+6,255, 0 , 255);        //couleur violet
       strip.show();
       delay(time_tic3);
    }
     delay(temp);                                       //temps d'affichage
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void variation_lumi(int time_tic2,int nb_vari,int time_tic3)
{
  strip.setBrightness(0);                             //deffini la luminosité nul
   strip.show();                                      //afficher 
  delay(500);
  strip.setBrightness(100);
  for(int i = 0 ; i < PIXEL_COUNT ; i++)               //allumer toutes les leds progressivement
            {
               strip.setPixelColor(i, 0, 0, 255);      //couleur leds = bleu
  
               strip.show();
               delay(time_tic3);
            }
            
  for ( int j =0; j < nb_vari; j++)                    //parcour le nombre de variation
    {
      
      for (int lumi = 100 ; lumi > 0 ; lumi = lumi - 1)//éteindre progressivement les led
        {
           strip.setBrightness(lumi);
           for(int i = 0 ; i < PIXEL_COUNT ; i++)      //appliquer à toutes les leds
            {
     
               strip.setPixelColor(i, 0, 0, 255);      //couleur leds = bleu
            }
     
           strip.show();
           delay(time_tic2);
        }
           for (int lumi = 0 ; lumi < 100 ; lumi = lumi + 1)//allumer progressivement les led
         {
          Serial.print(lumi);
           strip.setBrightness(lumi);
           for(int i = 0 ; i < PIXEL_COUNT ; i++)        //appliquer à toutes les leds
            {
     
              strip.setPixelColor(i, 0, 0, 255);         //couleur leds
            }
     
          strip.show();
          delay(time_tic2);
         }     
   } 
} 

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void ping_pong(int time_tic4,int nb_aller_retour)
{
  strip.setBrightness(0);                                    //deffinie la luminosité nul
   strip.show();                                             //afficher 
  delay(500);
  for ( int j =0; j < nb_aller_retour; j++)                  //parcour le nombre d'aller retour
    {
      
  for(int i = 0 ; i < PIXEL_COUNT ; i++)                     //allumer toutes les leds progressivement dans un sens
            {
               strip.setBrightness(100);
               strip.setPixelColor(i, 0, 0, 255);            //couleur leds
               strip.show();
               delay(time_tic4);                             //durer allumé
               strip.setBrightness(0);
            }
 for(int i = PIXEL_COUNT ; i >= 0 ; i--)                     //allumer toutes les leds progressivement dans l'autre sens
            {
               strip.setBrightness(100);
               strip.setPixelColor(i, 0, 0, 255);            //couleur leds
               strip.show();
               delay(time_tic4);                             //durer allumé
               strip.setBrightness(0);
            }
    }
}
