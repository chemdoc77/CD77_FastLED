//NeoPixel NeoMatrix 8X8 panel fun with FastLED by Chemdoc77

//Tour de force use of arrays and arrays of arrays.
 
#include "FastLED.h"
#define NUM_LEDS 64
#define Data_Pin 6
#define chipset NEOPIXEL 
#define BRIGHTNESS  30

CRGB leds[NUM_LEDS];

#define ARRAY_SIZE(A) (sizeof(A) / sizeof((A)[0]))

#include "The_8x8_Arrays.h"
#include "The_8X8_Matrix_Functions.h"

void setup() { 
 delay(1200); // power-up safety delay 
 FastLED.addLeds<chipset, Data_Pin>(leds, NUM_LEDS);
 
 // for other chipsets you may need to determine what the RGB ordering for your chipset should be.  See:
 // https://github.com/FastLED/FastLED/blob/master/examples/RGBCalibrate/RGBCalibrate.ino
 
 FastLED.setBrightness(BRIGHTNESS);
 FastLED.setMaxPowerInVoltsAndMilliamps(5,900);
 set_max_power_indicator_LED(13);
}

void loop() {
  
      // Fills the NeoMatrix 8X8 panel in a spiral -  one neopixel after the other
         cd77_8X8_spiral_colorWipe(0, 50); //red spiral 
         cd77_8X8_spiral_colorWipe(160, 50); //blue spiral
         cd77_8X8_spiral_colorWipe(0, 50); //red spiral
        fill_solid( leds, NUM_LEDS, CRGB::Black);          // clears color fill_solid( leds, NUM_LEDS, CRGB::Black);

      // Fills the NeoMatrix 8X8 panel in a reverse spiral -  one neopixel after the other
         cd77_8X8_reverse_spiral_colorWipe(0, 50); //red reverse spiral
         cd77_8X8_reverse_spiral_colorWipe(160, 50); //blue reverse spiral 
         cd77_8X8_reverse_spiral_colorWipe(0, 50); //red reverse spiral
         fill_solid( leds, NUM_LEDS, CRGB::Black);          // clears color
  
      // Fills the NeoMatrix 8X8 panel using both spirals -  one neopixel after the other
         cd77_8X8_spiral_colorWipe(0, 50); //red spiral 
         cd77_8X8_reverse_spiral_colorWipe(160, 50); //blue reverse spiral
         cd77_8X8_spiral_colorWipe(0, 50); //red spiral 
         fill_solid( leds, NUM_LEDS, CRGB::Black);          // clears color
  
        
      // Fills the NeoMatrix 8X8 panel using one 4X4 minimatrix at a time in the 8X8 panel
         cd77_8X8_fourmatrixes_colorWipe(0, 50); // red
         cd77_8X8_fourmatrixes_colorWipe(160, 50); //blue
         cd77_8X8_fourmatrixes_colorWipe(0, 50); //red
        fill_solid( leds, NUM_LEDS, CRGB::Black);          // clears color
     
        
      // Fills the NeoMatrix 8X8 panel using all of the 4X4 minimatrix at the same time in the 8X8 panel
         cd77_8X8_fourmatrixes_same_colorWipe(0, 110); // red
         cd77_8X8_fourmatrixes_same_colorWipe(160, 110); //blue
         cd77_8X8_fourmatrixes_same_colorWipe(0, 110); // red
         fill_solid( leds, NUM_LEDS, CRGB::Black);          // clears color
 
           
        // Fills the NeoMatrix 8X8 panel with - one full square at a time - all with same color
        // All blue squares
        cd77_8X8_box_colorWipe(160, 750); // blue boxes       
       fill_solid( leds, NUM_LEDS, CRGB::Black); // clears color 

        
        // All red squares
        cd77_8X8_box_colorWipe(0, 750); // red boxes      
        fill_solid( leds, NUM_LEDS, CRGB::Black); // clears color    

        
        //  Fills the NeoMatrix 8X8 panel with one full square at a time - all with same color one full square at a time - all with different colors        
        cd77_fullallbox_colorWipe(160, 750, boxarray4, 4); // single blue box
        cd77_fullallbox_colorWipe(0, 750, boxarray3, 12); // single red box
        cd77_fullallbox_colorWipe(160, 750, boxarray2, 20); // single blue box
        cd77_fullallbox_colorWipe(0, 750, boxarray1, 28); // single red box       
        fill_solid( leds, NUM_LEDS, CRGB::Black); // clears color 
  
        // Fills the NeoMatrix 8X8 panel with with split spiral one full box at a time  
       cd77_8X8_split_spiral_colorWipe(0, 100); //red reverse spiral   
       cd77_8X8_split_spiral_colorWipe(160, 100); //blue reverse spiral
       cd77_8X8_split_spiral_colorWipe(0, 100); //red reverse spiral 
       fill_solid( leds, NUM_LEDS, CRGB::Black);          // clears color
 
}
