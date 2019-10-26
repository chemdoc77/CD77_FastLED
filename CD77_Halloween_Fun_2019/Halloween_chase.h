/* Created by Chemdoc77 based on code by Zaphod Beeblewurdle in:

https://plus.google.com/107029944060954069417/posts/6r7QakiLLvm

and based on code by Jason Coon’s Color Pulse in:

https://plus.google.com/+JasonCoon1/posts/gpN7pEqRQUe

*/


#ifndef Halloween_chase.h
#define Halloween_chase.h

int leds_done = 0;
uint16_t x=0;
uint16_t wait = 800;
uint16_t i=0;
CRGB Halloween_color = CRGB::Red;


  int m_red;  // RGB components of the color
  int m_green;
  int m_blue;


//======================================

void CD77_Halloween_Colors (uint16_t wait_cc){

/* Based on code in This sketch is based on the following sketch from Adafruit:
 *  
https://learn.adafruit.com/random-spooky-led-eyes/assembly?view=all 

Random Eyes sketch for WS2801 pixels
W. Earl 10/16/11
For Adafruit Industries
*/
EVERY_N_MILLIS(wait_cc){
 // Pick a random color - skew toward red/orange/yellow part of the spectrum for extra creepyness
    m_red = random8(150, 255);
    m_blue = 0;
    m_green = random8(100);

    int r =  map(m_red, 0, 255, 0, BRIGHTNESS);
    int g =  map(m_green, 0, 255, 0, BRIGHTNESS);
    int b =  map(m_blue, 0, 255, 0, BRIGHTNESS);
    
    Halloween_color = CRGB( r, g, b);
    
 }
}

//================================================================

void CD77_Chase_Halloween_random(uint16_t wait1, uint16_t wait2,uint8_t dots ) {
//shift pixels
for(int i = NUM_LEDS - 1; i >0; i--) {
leds[i] = leds[i-1];
}

//reset?
EVERY_N_MILLIS_I( Dot_time, 500) {
    // This initally defaults to 20 seconds, but then will change the run
    // period to a new random number of seconds from 10 and 30 seconds.
    // You can name "timingObj" whatever you want.
Dot_time.setPeriod( random16(wait1,wait2) );
 leds_done = 0;
}

if(leds_done <dots) {
  
leds[0] = Halloween_color; 
leds_done = leds_done + 1;
//i=i+1; if (i>=3){i=0;}
} else {
leds[0] = CRGB::Black;
  }
 }


//======================

void CD77_Chase_Halloween_fixed(uint16_t wait1,uint8_t dots ) {
//shift pixels
for(int i = NUM_LEDS - 1; i >0; i--) {
leds[i] = leds[i-1];
}

//reset?
EVERY_N_MILLIS_I( Dot_time, 500) {
    // This initally defaults to 20 seconds, but then will change the run
    // period to a new random number of seconds from 10 and 30 seconds.
    // You can name "timingObj" whatever you want.
Dot_time.setPeriod(wait1);
 leds_done = 0;
}

if(leds_done <dots) {
  
leds[0] = Halloween_color; 
leds_done = leds_done + 1;
//i=i+1; if (i>=3){i=0;}
} else {
leds[0] = CRGB::Black;
  }
 }

//================
void CD77_Chase_Halloween_fixed_color(CRGB color1, uint16_t wait1,uint8_t dots ) {
//shift pixels
for(int i = NUM_LEDS - 1; i >0; i--) {
leds[i] = leds[i-1];
}

//reset?
EVERY_N_MILLIS_I( Dot_time, 500) {
    // This initally defaults to 20 seconds, but then will change the run
    // period to a new random number of seconds from 10 and 30 seconds.
    // You can name "timingObj" whatever you want.
Dot_time.setPeriod(wait1);
 leds_done = 0;
}

if(leds_done <dots) {
  
leds[0] = color1; 
leds_done = leds_done + 1;
//i=i+1; if (i>=3){i=0;}
} else {
leds[0] = CRGB::Black;
  }
 }


#endif
