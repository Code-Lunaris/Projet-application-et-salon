  /* =========================== DEFINE ET INCLUDE ========================================== */

#include <gamma.h>
#include <Adafruit_GFX.h>   // Core graphics library
#include <RGBmatrixPanel.h> // Hardware-specific library

#define CLK 8  // MUST be on PORTB! (Use pin 11 on Mega)
#define LAT A3
#define OE  9
#define A   A0
#define B   A1
#define C   A2
RGBmatrixPanel matrix(A, B, C, CLK, LAT, OE, false);
#define F2(progmem_ptr) (const __FlashStringHelper *)progmem_ptr


  /* =========================== CONSTANTES BOULLES ANIMATION ========================================== */

  #define F2(progmem_ptr) (const __FlashStringHelper *)progmem_ptr

 int8_t ball[3][4] = {
  {  3,  0,  1,  1 }, // Initial X,Y pos & velocity for 3 bouncy balls
  { 17, 15,  1, -1 },
  { 27,  4, -1,  1 }
};
  static const uint16_t PROGMEM ballcolor[3] = {
  0x0080, // Green=1
  0x0002, // Blue=1
  0x1000  // Red=1
};


  /* =========================== CONSTANTES BOUCLES ET LOGO ========================================== */

int i,j,k; //Variables de boucles
int decale = 1; // Variable de décalage du logo P

 
int tab[67][2] = { {4,2},{5,2},{6,2},    // {colonne, ligne}
                    {2,3},{3,3},{4,3},{5,3},{6,3},{7,3},{8,3}
                    ,{1,4},{2,4},{3,4},{4,4},{5,4},{6,4},{7,4},{8,4},{9,4}
                    ,{0,5},{1,5},{2,5},{3,5},{7,5},{8,5},{9,5},
                    {0,6},{1,6},{2,6},{8,6},{9,6},{10,6},
                    {9,7},{10,7},
                    {9,8},{10,8},
                    {0,9},{1,9},{2,9},{8,9},{9,9},{10,9}
                    ,{0,10},{1,10},{2,10},{3,10},{7,10},{8,10},{9,10},
                    {0,11},{1,11},{2,11},{3,11},{4,11},{5,11},{6,11},{7,11},{8,11},{9,11}
                    ,{0,12},{1,12},{3,12},{4,12},{5,12},{6,12},{7,12},
                    {1,13} };


       
void setup() {
    matrix.begin();

 /* ========================= DEFILEMENT ================================================= */
 
    matrix.setTextWrap(false); // Allow text to run off right edge
    matrix.setTextSize(1);
}



void loop() {
  // put your main code here, to run repeatedly:

   /* ========================= SET UP LOGO ET "SIR" ======================================= */
    
   for(j = 0 ; j < 67 ; j++)
   {
    matrix.drawPixel(tab[j][0] + decale,tab[j][1], matrix.Color333(0, 0, 0x0002));  //LOGO
   }

   matrix.setCursor(14, 4);   // start at top left, with one pixel of spacing
   matrix.setTextSize(1); // size 1 == 8 pixels high

   matrix.setTextColor(matrix.Color333(0,0,0x0002));
   matrix.print('S');
   matrix.print('I');
   matrix.print('R');


  /*===========================CONSTANTES POUR LES BOULLES ========================================== */ 
  
  byte n;        // variable des boucles pour les boulles
  byte nbBoule; // nombre de rebond des boulles

 
  delay(5000);
    
  /*=========================== AFFICHAGE DU LOGO POLYTECH ========================================== */

  for(i = 0 ; i < 32; i++)
  {
   for(j = 0 ; j < 67 ; j++)
   {
    matrix.drawPixel(tab[j][0] + decale + i,tab[j][1], matrix.Color333(0, 0, 0x0002));    
   }

  
  /* ============================= AFFICHAGE DE "SIR" ================================================= */
   
   matrix.setCursor(i+14, 4);   // start at top left, with one pixel of spacing
   matrix.setTextSize(1);      // size 1 == 8 pixels high
  
  
   matrix.setTextColor(matrix.Color333(0,0,0x0002));
   matrix.print('S');
   matrix.print('I');
   matrix.print('R'); 

   delay(100); // vitesse de défilement 
   matrix.fillRect(0, 0, 32, 16, matrix.Color333(0, 0, 0));  //Permet le défilment de "SIR" en éteignant les led 
  }

  /* ============================= AFFICHAGE ET DEFILEMENT DE "Polytech" ================================================= */
   
   delay(300);

    
   matrix.setTextSize(1); // size 1 == 8 pixels high
   matrix.setTextWrap(false);
  
   for(i = 33 ; i > -45; i--)
   {
    matrix.setCursor(i, 4);   // start at top left, with one pixel of spacing
         
    matrix.setTextColor(matrix.Color333(0,1,0x0080));
    matrix.print('P');
    matrix.print('o');
    matrix.print('l');
    matrix.print('y');
    matrix.print('t');
    matrix.print('e');
    matrix.print('c');
    matrix.print('h');
   
    delay(80); // vitesse de défilement
    matrix.fillRect(0, 0, 32, 16, matrix.Color333(0, 0, 0)); 
   }
   
  /* ============================= ANIMATIONS DES BOULLES ================================================= */

  for(nbBoule =0; nbBoule<65 ; nbBoule++)
  {
    matrix.fillScreen(0);
    // Bounce three balls around
    for(n=0; n<3; n++) 
    {
     // Draw 'ball'
      matrix.fillCircle(ball[n][0], ball[n][1], 5, pgm_read_word(&ballcolor[n]));
      
      // Update X, Y position
      ball[n][0] += ball[n][2];
      ball[n][1] += ball[n][3];
     
      // Bounce off edges
      if((ball[n][0] == 0) || (ball[n][0] == (matrix.width() - 1)))
        ball[n][2] *= -1;
      if((ball[n][1] == 0) || (ball[n][1] == (matrix.height() - 1)))
        ball[n][3] *= -1;
    }
    delay(50);    
  }

 /* ============================= AFFICHAGE ET DEFILEMENT DE "SYSTEMES INDUSTRIELS ET ROBOTIQUES"================================================= */
   
   delay(30);
   
   for(i = 33 ; i > -90; i--)
   {
    matrix.setCursor(i, 4);   // start at top left, with one pixel of spacing
    matrix.setTextSize(1);      // size 1 == 8 pixels high
  
    matrix.setTextColor(matrix.Color333(0,0,0x0002));
    matrix.print('S');
    matrix.print('Y');
    matrix.print('S');
    matrix.print('T');
    matrix.print('E');
    matrix.print('M');
    matrix.print('E');
    matrix.print('S');

    matrix.print(' ');
    matrix.print('I');
    matrix.print('N');
    matrix.print('D');
    matrix.print('U');
    matrix.print('S');
    matrix.print('T');
    matrix.print('R');
    matrix.print('I');
    matrix.print('E');
    matrix.print('L');
    matrix.print('S');  
    matrix.print(' ');
    
  //  matrix.setCursor(i, 8); 
    
    matrix.print('E');
    matrix.print('T');

    matrix.print(' ');
    matrix.print('R');
    matrix.print('O');
    matrix.print('B');
    matrix.print('O');
    matrix.print('T');
    matrix.print('I');
    matrix.print('Q');
    matrix.print('U');
    matrix.print('E');

    delay(50); // vitesse de défilement 
    matrix.fillRect(0, 0, 32, 16, matrix.Color333(0, 0, 0));  //Permet le défilment du text en éteignant les led 
   } 
}
