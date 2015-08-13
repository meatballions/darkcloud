//Dark Cloud 1.0 by Meatballion
//Licensed in the Public Domain
//Originally a design to simulate lightning using Adafruit NeoPixels
//based on samples from Adafruit and 
//For a Tifo idea in support of the greatest football team on the planet
//Minnesota United FC
//You dive like Jamie Watson

#include <Adafruit_NeoPixel.h>
#include <math.h>

//Here is the pin you connect your NeoPixel Control to.  Designing for Adafruit Trinket controller

      #define PIN 1

// Parameter 1 = number of pixels in strip
// Parameter 2 = pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//ibarra is the name of the lightning
Adafruit_NeoPixel ibarra = Adafruit_NeoPixel(20, PIN, NEO_GRB + NEO_KHZ800);


//initialize pixels off
void setup() {
  ibarra.begin();
  ibarra.show(); // Initialize all pixels to 'off'
}

uint32_t white = ibarra.Color(250, 250, 250);
uint32_t purple = ibarra.Color(200, 10, 200);
uint32_t blue = ibarra.Color(0, 0, 150);
uint32_t red = ibarra.Color(75, 0, 0);

void loop (){
//reset all variables

int bolts = 0;
long flash = 0;
int colorChoice = 0;

//choose color of ibarra -- for version 1.1
//colorChoice = random(0,6);
//if (colorChoice == 0 || colorChoice == 2 || colorChoice == 4) {
// boltColor = "white"; 
//}
//else if (colorChoice == 1) {
//  boltColor = "purple";
//}
//
//else if (colorChoice == 3) {
//  boltColor = "blue";
//}
//
//else  {
//  boltColor = "red";
//}

  
//choose number of bolts (neoPixels)of ibarra
bolts = random(0,19);

//Flash ibarra lightly for .1 s
ibarra.setBrightness(64);
 for (int i = 0; i < bolts+1; i++)  {
    ibarra.setPixelColor(i - 1, blue); 
 }
 ibarra.show();
 delay(500);
 
    for (int i=0; i <= 3; i++){           // i is the pixel number. This forloop selects all the pixels between 0 - 50
    ibarra.setPixelColor(i,0,0,0);        // the last 3 values are RGB values, red blue and green respectivly. Currently set to off, adjust these to change the color.
    ibarra.show();                        //Sends the comand to the pixels to Light up in the specified code above.
  }
  delay (50);
 
//choose duration of secondary ibarra flash between .5 ans 1.25 seconds of ibarra at full brightness
ibarra.setBrightness(100);
flash = random(1250,2500);
 for (int i = 0; i < bolts+1; i++)  {
    ibarra.setPixelColor(i - 1, purple); 
    
 }
 ibarra.show();
 delay(flash);
 // turn pixels off
   for (int i=0; i <= 3; i++){           // i is the pixel number. This forloop selects all the pixels between 0 - 50
    ibarra.setPixelColor(i,0,0,0);        // the last 3 values are RGB values, red blue and green respectivly. Currently set to off, adjust these to change the color.
    ibarra.show();                        //Sends the comand to the pixels to Light up in the specified code above.
  }
  delay (50);                           //delay of half a second
}
//ibarra.setPixelColor(0, white);
//ibarra.setPixelColor(1, white);
//ibarra.setPixelColor(2, white);
//  
//ibarra.show();
  
//ibarra.setPixelColor(0, purple);
//ibarra.setPixelColor(1, blue);
//ibarra.setPixelColor(2, red);






    

