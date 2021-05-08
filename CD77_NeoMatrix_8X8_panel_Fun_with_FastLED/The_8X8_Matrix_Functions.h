#ifndef The_8X8_Matrix_Functions_h
#define The_8X8_Matrix_Functions_h

// Functions for loop -----------------------------------------------------------------


// Fills the NeoMatrix 8X8 panel with in a spiral -  one neopixel after the other
void cd77_8X8_spiral_colorWipe(uint8_t ghue, uint8_t wait) {    
  
  for(uint16_t j=0; j<bigboxarray_Size; j++) {
     uint16_t x=boxtotalarray[j];
  for(uint16_t k=0; k<x; k++) {
     leds[bigboxarray[j][k]]= CHSV(ghue, 255,255);
     FastLED.delay(wait);
   }
  }
}

// Fills the NeoMatrix 8X8 panel with in a reverse spiral -  one neopixel after the other
void cd77_8X8_reverse_spiral_colorWipe(uint8_t ghue, uint8_t wait) {    
  
  for(uint16_t j=0; j<bigboxarray_Size; j++) {
     uint16_t x=boxtotalarray[3-j];
  for(uint16_t k=0; k<x; k++) {
     leds[bigboxarray[3-j][(x-1)-k]]= CHSV(ghue, 255,255);
     FastLED.delay(wait);
   }
  }
}

// Fills the each of 4 seperate 4X4 matrixes in the NeoMatrix 8X8 panel with in a spiral -  one neopixel after the other
void cd77_8X8_fourmatrixes_colorWipe(uint8_t ghue, uint16_t wait) {    
  
   for(uint16_t j=0; j<bigfourarray_Size; j++) {
      uint16_t x=bigfourarray_size[j];
  for(uint16_t k=0; k<x; k++) {
       leds[bigfourarray[j][k]]= CHSV(ghue, 255,255);
       FastLED.delay(wait);
    }
  }
}  

// Fills the all of the 4 seperate 4X4 matrixes in the NeoMatrix 8X8 panel in a spiral -  one neopixel after the other
void cd77_8X8_fourmatrixes_same_colorWipe(uint8_t ghue, uint16_t wait) { 
    
  for(uint16_t k=0; k<16; k++) {
     
       leds[bigfourarray[0][k]] = CHSV(ghue, 255,255);
       leds[bigfourarray[1][k]] = CHSV(ghue, 255,255);
       leds[bigfourarray[2][k]] = CHSV(ghue, 255,255);
       leds[bigfourarray[3][k]] = CHSV(ghue, 255,255);
       FastLED.delay(wait);
    }
}  


//Fills the NeoMatrix 8X8 panel half a side at a time together

void cd77_8X8_split_spiral_colorWipe(uint8_t ghue, uint16_t wait) {    
  
  for(uint16_t j=0; j<8; j+=2) {
     uint16_t x=splitboxtotalarray[j];
  for(uint16_t k=0; k<x; k++) {
      leds[splitbigboxarray[j][k]] = CHSV(ghue, 255,255);  
     leds[splitbigboxarray[j+1][k]] = CHSV(ghue, 255,255);    
       FastLED.delay(wait);
   }
  }
}


// Fills the NeoMatrix 8X8 panel in a spiral -  one neopixel after the other with only one neoPixel light at a time
void cd77_8X8_onepixel_spiral_colorWipe(uint8_t ghue, uint16_t wait) {    
  
  for(uint16_t j=0; j<4; j++) {
     uint16_t x=boxtotalarray[j];
  for(uint16_t k=0; k<x; k++) {
      leds[bigboxarray[j][k]]= CHSV(ghue, 255,255);      
       FastLED.delay(wait);
      leds[bigboxarray[j][k]]= CRGB::Black;      
       FastLED.show();
      
   }
  }
}


// Fills the NeoMatrix 8X8 panel in a squares -  one square after the other
void cd77_8X8_box_colorWipe(uint8_t ghue, uint16_t wait) {    
  
  for(uint16_t j=0; j<4; j++) {
     uint16_t x=boxtotalarray[j];
  for(uint16_t k=0; k<x; k++) {
      leds[bigboxarray[j][k]]= CHSV(ghue, 255,255);            
   } 
    FastLED.delay(wait);
  }
   
}

 
// Fills the NeoMatrix 8X8 panel - one square at a time
void cd77_fullallbox_colorWipe(uint8_t ghue, uint16_t wait, uint8_t* boxarray, uint16_t x) { // Note: boxarray is the name of the array being used.  x is the number of members in the array being used.
  
   for(uint16_t i=0; i<x; i++) {
     leds[boxarray[i]]=CHSV(ghue, 255,255);     
   }   
      FastLED.delay(wait); 
  } 


// Fills the NeoMatrix 8X8 panel with all of the NeoPixes at one time 
void cd77colorallfill(uint8_t ghue, uint16_t wait) {  
      for(uint16_t i=0; i<NUM_LEDS; i++) {
      leds[i]= CHSV(ghue, 255,255);      
      }       
       FastLED.delay(wait);
}      

#endif
