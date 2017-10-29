#ifndef Halloween_breath.h 
#define Halloween_breath.h

//Halloween_breat by Chemdoc77 is based in part on Stuart Taylor's sketch, Breath.ino, at:
// https://gist.github.com/hsiboy/4eae11073e9d5b21eae3


CRGB Halloween_color2 = CRGB::DarkOrange;



void CD77_Halloween_Colors_2 (uint16_t wait_cc){

/* Based on code in This sketch is based on the following sketch from Adafruit:
 *  
https://learn.adafruit.com/random-spooky-led-eyes/assembly?view=all 

Random Eyes sketch for WS2801 pixels
W. Earl 10/16/11
For Adafruit Industries
*/

 int m_red2;  // RGB components of the color
  int m_green2;
  int m_blue2;

EVERY_N_MILLIS(wait_cc){
 // Pick a random color - skew toward red/orange/yellow part of the spectrum for extra creepyness
    m_red2 = random8(150, 255);
    m_blue2 = 0;
    m_green2 = random8(100);

    int r2 =  map(m_red2, 0, 255, 0, BRIGHTNESS_breath);
    int g2 =  map(m_green2, 0, 255, 0, BRIGHTNESS_breath);
    int b2 =  map(m_blue2, 0, 255, 0, BRIGHTNESS_breath);
    
    Halloween_color2 = CRGB( r2, g2, b2);
    
 }
}
//===============================

// CD77_Halloween_Colors function is located in Halloween_Chase.h

void CD77_breath(){
  fill_solid(leds, NUM_LEDS, Halloween_color2 );
float breath =   (exp(sin(millis()/2400.0*PI)) - 0.36787944)*108.0;//(exp(sin(millis()/2000.0*PI)) - 0.36787944)*108.0;       //(exp(sin(millis()/4000.0*PI)) - 0.36787944)*108.0;//(exp(sin(millis()/2000.0*PI)) - 0.36787944)*108.0;

 float breath2 = map(breath, 0,255,0, BRIGHTNESS_breath);
 FastLED.setBrightness(breath2);

}



#endif
