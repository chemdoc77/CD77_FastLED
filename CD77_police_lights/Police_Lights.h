#ifndef Police_lights_h
#define Police_lights_h

int x = 0;  

long colorarray0[] = {CRGB::Blue,CRGB::Red};
long colorarray1[] = {CRGB::Blue,CRGB::Grey,CRGB::Red};
long colorarray2[] = {CRGB::Red,CRGB::Grey,CRGB::Blue,CRGB::Green,CRGB::Yellow};
long colorarray3[] = {CRGB::Green,CRGB::Blue,CRGB::Red,CRGB::Yellow,CRGB::Purple,CRGB::Lime,CRGB::Grey};
long colorarray4[] = {CRGB::Red,CRGB::Grey};
long * bigarray[] ={colorarray0, colorarray1, colorarray2, colorarray3, colorarray4 }; 

uint8_t size_ca0= ARRAY_SIZE(colorarray0);
uint8_t size_ca1= ARRAY_SIZE(colorarray1);
uint8_t size_ca2= ARRAY_SIZE(colorarray2);
uint8_t size_ca3= ARRAY_SIZE(colorarray3);
uint8_t size_ca4= ARRAY_SIZE(colorarray4);
uint8_t sizearray[]= {size_ca0,size_ca1,size_ca2,size_ca3,size_ca4};

//============================================================
//Sketch Functions

void cd77_police_lights_all(int carray, int segments, int wait){
  EVERY_N_MILLIS(wait){ 
  x++;
  if (x >=  NUM_LEDS) {x = 0;}
  for (int z=0; z< segments;z++){
  uint8_t q=z;
  if (q>(sizearray[carray]-1)){q= z%sizearray[carray];};
  int y = x + (z*NUM_LEDS)/segments;
  if ((x + (z*NUM_LEDS)/segments) >= NUM_LEDS) {y = (x + (z*NUM_LEDS)/segments)%NUM_LEDS; }

  leds[y]=  bigarray[carray][q];
}
  FastLED.show();  
   }
}
//====================================
void cd77_police_lights_one(int carray, int segments, int wait){
  EVERY_N_MILLIS(wait){ 
  x++;
  if (x >=  NUM_LEDS) {x = 0;}
  fill_solid(leds,NUM_LEDS, CRGB::Black); 
  for (int z=0; z< segments;z++){
  uint8_t q=z;
  if (q>(sizearray[carray]-1)){q= z%sizearray[carray];}
  int y = x + (z*NUM_LEDS)/segments;
  if ((x + (z*NUM_LEDS)/segments) > NUM_LEDS-1) {y = (x + (z*NUM_LEDS)/segments)%NUM_LEDS; }
  leds[y]=  bigarray[carray][q];
}
  FastLED.show();    
   }   
}
//===================================

void cd77_police_lights_all_palette( int colorIndex, int deltacolorIndex, int segments, int wait ){
  EVERY_N_MILLIS(wait){    
  x++;
  if (x >=  NUM_LEDS) {x = 0;}
  for (int z=0; z< segments;z++){

  int y = x + (z*NUM_LEDS)/segments;
  if ((x + (z*NUM_LEDS)/segments) >= NUM_LEDS) {y = (x + (z*NUM_LEDS)/segments)%NUM_LEDS; }

  leds[y]=  ColorFromPalette( currentPalette, colorIndex+triwave8(y), 255, currentBlending);
  
  colorIndex += deltacolorIndex;
}
  FastLED.show();  
   }
}

//===============================================

void cd77_police_lights_one_palette( int colorIndex,int deltacolorIndex, int segments, int wait){
  EVERY_N_MILLIS(wait){
  x++;
  if (x >=  NUM_LEDS) {x = 0;}
  fill_solid(leds,NUM_LEDS, CRGB::Black); 
  for (int z=0; z< segments;z++){
   
  int y = x + (z*NUM_LEDS)/segments;
  if ((x + (z*NUM_LEDS)/segments) > NUM_LEDS-1) {y = (x + (z*NUM_LEDS)/segments)%NUM_LEDS; }

  leds[y]= ColorFromPalette( currentPalette, colorIndex+triwave8(y), 255, currentBlending);
  colorIndex += deltacolorIndex;
    }
  FastLED.show();    
  }
}    
//============================================

void cd77_police_lights_all_random(uint8_t cycles,int wait){
    EVERY_N_MILLIS(wait*(NUM_LEDS*cycles)){
    int size_CA = ARRAY_SIZE(bigarray);
    random_carray = random8(size_CA);
    random_segment = random8(2,NUM_LEDS/2);    
    }   
  EVERY_N_MILLIS(wait){ 
  x++;
  if (x >=  NUM_LEDS) {x = 0;}
  for (int z=0; z< random_segment;z++){
  uint8_t q=z;
  if (q>(sizearray[random_carray]-1)){q= z%sizearray[random_carray];};
  int y = x + (z*NUM_LEDS)/random_segment;
  if ((x + (z*NUM_LEDS)/random_segment) >= NUM_LEDS) {y = (x + (z*NUM_LEDS)/random_segment)%NUM_LEDS; }

  leds[y]=  bigarray[random_carray][q];
     }
  FastLED.show();  
   }
}

//===============================================

void cd77_police_lights_one_random(uint8_t cycles, int wait){
   EVERY_N_MILLIS(wait*(NUM_LEDS*cycles)){
    int size_CA = ARRAY_SIZE(bigarray);
    random_carray = random8(size_CA);
    random_segment = random8(2,NUM_LEDS/2);    
    }
  EVERY_N_MILLIS(wait){ 
  
  x++;
  if (x >=  NUM_LEDS) {x = 0;}
  fill_solid(leds,NUM_LEDS, CRGB::Black); 
  for (int z=0; z< random_segment;z++){
  uint8_t q=z;
  if (q>(sizearray[random_carray]-1)){q= z%sizearray[random_carray];}
  int y = x + (z*NUM_LEDS)/random_segment;
  if ((x + (z*NUM_LEDS)/random_segment) > NUM_LEDS-1) {y = (x + (z*NUM_LEDS)/random_segment)%NUM_LEDS; }
  leds[y]=  bigarray[random_carray][q];
     }
  FastLED.show();    
   }   
}

#endif
