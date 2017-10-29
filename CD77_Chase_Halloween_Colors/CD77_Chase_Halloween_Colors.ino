//CD77_Halloween Chase by Chemdoc77

/* thie code is based on code by Zaphod Beeblewurdle in:

https://plus.google.com/107029944060954069417/posts/6r7QakiLLvm

and based on code by Jason Coon’s Color Pulse in:

https://plus.google.com/+JasonCoon1/posts/gpN7pEqRQUe

and based on code by  W. Earl:

https://learn.adafruit.com/random-spooky-led-eyes/assembly?view=all 

*/

#include <FastLED.h>

#define LED_PIN 6
#define CHIPSET WS2811 //NEOPIXEL 
#define NUM_LEDS 50

#define BRIGHTNESS 160


CRGB leds[NUM_LEDS];
int leds_done = 0;
uint16_t x=0;
uint16_t wait = 800;
uint16_t i=0;

CRGB CD77_Halloween_Color = CRGB::Red;

  int m_red;  // RGB components of the color
  int m_green;
  int m_blue;

  
void setup() {

delay(1000); // sanity delay
FastLED.addLeds<CHIPSET, LED_PIN>(leds, NUM_LEDS);
FastLED.setBrightness( BRIGHTNESS );
FastLED.setMaxPowerInVoltsAndMilliamps(5,500);
 set_max_power_indicator_LED(13);
}

//============================================
void loop() {
 
  random16_add_entropy(random(65535)); // Add entropy to random number generator.

  CD77_Halloween_Colors(1000);  //CD77_Halloween_Colors(time delay in milliseconds between color changes)

  CD77_Chase_Halloween(100, 800,3);  //CD77_Chase_Halloween(lower time limit for time function in milliseconds, upper time limit for time function in milliseconds,number of dots)

  FastLED.delay(50);

}

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
    
    CD77_Halloween_Color = CRGB( r, g, b);
    
 }
}

//=============================================

void CD77_Chase_Halloween(uint16_t wait1, uint16_t wait2,uint8_t dots ) {
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
   //Halloween_Colors ();
leds[0] = CD77_Halloween_Color; //colorarry[i];
leds_done = leds_done + 1;
} else {
leds[0] = CRGB::Black;
  }
 }
