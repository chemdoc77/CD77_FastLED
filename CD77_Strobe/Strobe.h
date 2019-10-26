#ifndef Strobe.h   
#define Strobe.h   



//=============== Strobe Functions ====================


void CD77_Strobe_CRGBSet_all( CRGB strobeColor,  uint16_t strobeIntervalMs) {
  
 
  if ((millis() / strobeIntervalMs) % 2) {
    
    for(int i = 0; i <Array_Size_3; i++) { 
    fill_solid(ledarray_3[i],NUM_LEDS/3, CRGB::Black);
    }
    
  } else {
    for(int i_1 = 0; i_1 <Array_Size_3; i_1++) {
       fill_solid(ledarray_3[i_1], NUM_LEDS/3,strobeColor);       
    }
   
  }
  FastLED.show();
 
}



void CD77_Strobe_CRGBSet_3_1_on(uint16_t array_num_1, CRGB strobeColor_1,  uint16_t strobeIntervalMs) {
  
 
  if ((millis() / strobeIntervalMs) % 2) {
    
    fill_solid(ledarray_3[array_num_1],NUM_LEDS/3, CRGB::Black);
    FastLED.show();
    } else {
    fill_solid(ledarray_3[array_num_1], NUM_LEDS/3,strobeColor_1);
    FastLED.show();
   
  }
  
}




void CD77_Strobe_CRGBSet_3_3_on(uint16_t array_num_1, uint16_t array_num_2,uint16_t array_num_3,CRGB strobeColor_1, CRGB strobeColor_2, CRGB strobeColor_3,  uint16_t strobeIntervalMs) {
  
 
  if ((millis() / strobeIntervalMs) % 2) {
    fill_solid(ledarray_3[array_num_1],NUM_LEDS/3, CRGB::Black);
    fill_solid(ledarray_3[array_num_2],NUM_LEDS/3, CRGB::Black);
    fill_solid(ledarray_3[array_num_3],NUM_LEDS/3, CRGB::Black);
    FastLED.show();
  } else {
    fill_solid(ledarray_3[array_num_1], NUM_LEDS/3,strobeColor_1);
    fill_solid(ledarray_3[array_num_2], NUM_LEDS/3,strobeColor_2);
    fill_solid(ledarray_3[array_num_3],NUM_LEDS/3, strobeColor_3);
    FastLED.show();
  }

 
}






void CD77_Strobe_CRGBSet_6_3_on(uint16_t array_num_1, uint16_t array_num_2,uint16_t array_num_3,CRGB strobeColor_1, CRGB strobeColor_2,  CRGB strobeColor_3, uint16_t strobeIntervalMs) {
  
 
  if ((millis() / strobeIntervalMs) % 2) {
    fill_solid(ledarray_6[array_num_1],NUM_LEDS/6, CRGB::Black);
    fill_solid(ledarray_6[array_num_2],NUM_LEDS/6, CRGB::Black);
    fill_solid(ledarray_6[array_num_3],NUM_LEDS/6, CRGB::Black);
  } else {
    fill_solid(ledarray_6[array_num_1], NUM_LEDS/6,strobeColor_1);
    fill_solid(ledarray_6[array_num_2], NUM_LEDS/6,strobeColor_2);
    fill_solid(ledarray_6[array_num_3],NUM_LEDS/6, strobeColor_3);
  }
  FastLED.show();
 
}


void CD77_Strobe_CRGBSet_2_1_on(uint16_t array_num_1, CRGB strobeColor_1, uint16_t strobeIntervalMs) {
  
 
  if ((millis() / strobeIntervalMs) % 2) {
    fill_solid(ledarray_2[array_num_1],NUM_LEDS/2, CRGB::Black);
   // fill_solid(ledarray_4[array_num_2],NUM_LEDS/4, CRGB::Black);
  } else {
    fill_solid(ledarray_2[array_num_1], NUM_LEDS/2,strobeColor_1);
   // fill_solid(ledarray_4[array_num_2], NUM_LEDS/4,strobeColor_2);
  }
  FastLED.show();
 
}



void CD77_Strobe_CRGBSet_4_2_on(uint16_t array_num_1, uint16_t array_num_2,CRGB strobeColor_1, CRGB strobeColor_2,  uint16_t strobeIntervalMs) {
  
 
  if ((millis() / strobeIntervalMs) % 2) {
    fill_solid(ledarray_4[array_num_1],NUM_LEDS/4, CRGB::Black);
    fill_solid(ledarray_4[array_num_2],NUM_LEDS/4, CRGB::Black);
  } else {
    fill_solid(ledarray_4[array_num_1], NUM_LEDS/4,strobeColor_1);
    fill_solid(ledarray_4[array_num_2], NUM_LEDS/4,strobeColor_2);
  }
  FastLED.show();
 
}

void CD77_Strobe_CRGBSet_4(uint16_t array_num, CRGB strobeColor,  uint16_t strobeIntervalMs) {
  
 
  if ((millis() / strobeIntervalMs) % 2) {
    fill_solid(ledarray_4[array_num],NUM_LEDS/4, CRGB::Black);
  } else {
    fill_solid(ledarray_4[array_num], NUM_LEDS/4,strobeColor);
  }
  FastLED.show();
 
}

void CD77_Strobe_CRGBSet_3(uint16_t array_num, CRGB strobeColor,  uint16_t strobeIntervalMs) {
  
 
  if ((millis() / strobeIntervalMs) % 2) {
    fill_solid(ledarray_3[array_num],NUM_LEDS/3, CRGB::Black);
  } else {
    fill_solid(ledarray_3[array_num], NUM_LEDS/3,strobeColor);
  }
  FastLED.show();
 
}

void CD77_Strobe_3(CRGB strobeColor,  uint16_t strobeIntervalMs ) {
  
 
  if ((millis() / strobeIntervalMs) % 2) {
    fill_solid(leds, NUM_LEDS, CRGB::Black);
  } else {
    fill_solid(leds, NUM_LEDS, strobeColor);
  }
  FastLED.show();

   
}

void CD77_Strobe_2(CRGB strobeColor,  uint16_t strobeIntervalMs ) {
  
 
  if ((millis() / strobeIntervalMs) % 2) {
    fill_solid(leds, NUM_LEDS, CRGB::Black);
  } else {
    fill_solid(leds, NUM_LEDS, strobeColor);
  }
  FastLED.show();
 
}

void CD77_Strobe(CRGB strobeColor,  uint16_t strobeIntervalMs, uint16_t wait,uint16_t wait2 ) {
  if ((millis() / strobeIntervalMs) % 2) {
    fill_solid(leds, NUM_LEDS, CRGB::Black);
  } else {
    fill_solid(leds, NUM_LEDS, strobeColor);
  }
  FastLED.show();

  EVERY_N_MILLIS(wait){ 
  fill_solid(leds, NUM_LEDS, CRGB::Black);
 // FastLED.show();
 FastLED.delay (wait2);
  }
}

#endif  
