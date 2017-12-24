#ifndef Chase.h
#define Chase.h

/* This code is inspired and partially based on code by Zaphod Beeblewurdle in:

https://plus.google.com/107029944060954069417/posts/6r7QakiLLvm

and based on code by Jason Coon’s Color Pulse in:

https://plus.google.com/+JasonCoon1/posts/gpN7pEqRQUe

*/

int leds_done = 0;
uint16_t x=0;
uint16_t wait = 800;
uint16_t i=0;
uint8_t dotnumber=3;
uint8_t colorIndex =0;
CRGB colorarry[]=  {CRGB::Red,CRGB::Grey, CRGB::Blue, CRGB::Green, CRGB::Yellow};
CRGB Array_color= colorarry[0];
uint8_t Array_Size = ARRAY_SIZE(colorarry);

CRGBPalette16 currentPalette (PartyColors_p);
TBlendType    currentBlending (NOBLEND);
CRGB Color2=CRGB::Green;

//=================palettes==========================

// Gradient palette "bhw1_28_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/bhw/bhw1/tn/bhw1_28.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 32 bytes of program space.

DEFINE_GRADIENT_PALETTE( bhw1_28_gp ) {
    0,  75,  1,221,
   30, 252, 73,255,
   48, 169,  0,242,
  119,   0,149,242,
  170,  43,  0,242,
  206, 252, 73,255,
  232,  78, 12,214,
  255,   0,149,242};


// Gradient palette "temperature_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/arendal/tn/temperature.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 144 bytes of program space.

DEFINE_GRADIENT_PALETTE( temperature_gp ) {
    0,   1, 27,105,
   14,   1, 27,105,
   14,   1, 40,127,
   28,   1, 40,127,
   28,   1, 70,168,
   42,   1, 70,168,
   42,   1, 92,197,
   56,   1, 92,197,
   56,   1,119,221,
   70,   1,119,221,
   70,   3,130,151,
   84,   3,130,151,
   84,  23,156,149,
   99,  23,156,149,
   99,  67,182,112,
  113,  67,182,112,
  113, 121,201, 52,
  127, 121,201, 52,
  127, 142,203, 11,
  141, 142,203, 11,
  141, 224,223,  1,
  155, 224,223,  1,
  155, 252,187,  2,
  170, 252,187,  2,
  170, 247,147,  1,
  184, 247,147,  1,
  184, 237, 87,  1,
  198, 237, 87,  1,
  198, 229, 43,  1,
  212, 229, 43,  1,
  212, 220, 15,  1,
  226, 220, 15,  1,
  226, 171,  2,  2,
  240, 171,  2,  2,
  240,  80,  3,  3,
  255,  80,  3,  3};


// Gradient palette "GMT_panoply_gp", originally from
// http://soliton.vm.bytemark.co.uk/pub/cpt-city/gmt/tn/GMT_panoply.png.index.html
// converted for FastLED with gammas (2.6, 2.2, 2.5)
// Size: 128 bytes of program space.

DEFINE_GRADIENT_PALETTE( GMT_panoply_gp ) {
    0,   1,  1,168,
   15,   1,  1,168,
   15,   1, 19,255,
   31,   1, 19,255,
   31,   7, 79,255,
   47,   7, 79,255,
   47,  27,138,255,
   63,  27,138,255,
   63,  47,178,255,
   79,  47,178,255,
   79,  71,219,255,
   95,  71,219,255,
   95,  95,233,255,
  111,  95,233,255,
  111, 146,255,255,
  127, 146,255,255,
  127, 255,252, 10,
  143, 255,252, 10,
  143, 255,213,  0,
  159, 255,213,  0,
  159, 255,142,  0,
  175, 255,142,  0,
  175, 255, 72,  0,
  191, 255, 72,  0,
  191, 255, 15,  0,
  207, 255, 15,  0,
  207, 255,  0,  0,
  223, 255,  0,  0,
  223, 159,  0,  0,
  239, 159,  0,  0,
  239,  73,  0,  0,
  255,  73,  0,  0};


//=======================end palettes======================

//========================Functions=========================
void CD77_array_change(uint16_t wait_ac){

EVERY_N_MILLIS(wait_ac){
i++;
 if (i > Array_Size-1) {i = 0;}
Array_color = colorarry[i];
   }
 }

//======================================

void CD77_chase_one_color_symet(CRGB color_one, uint16_t wait1, uint8_t dots ) {
//shift pixels
for(int i =  NUM_LEDS - 1; i >0; i--) {
leds[i] = leds[i-1];
}

//reset
EVERY_N_MILLIS_I( Dot_time, 500) {
    
Dot_time.setPeriod( wait1 );
 leds_done = 0;

}

if(leds_done <dots) {
leds[0] = color_one; 
leds_done = leds_done + 1;
 } else {
leds[0] = CRGB::Black;

  }
 }

//===================================================

void CD77_chase_array_color_symet(uint16_t wait1,uint16_t wait_Array , uint8_t dots ) {
//shift pixels

EVERY_N_MILLIS_I( Array_time, 500){ 
  Array_time.setPeriod( wait_Array );
  i++;
  if (i > Array_Size-1) {i = 0;}
  Array_color = colorarry[i];
  }

for(int i =  NUM_LEDS - 1; i >0; i--) {
leds[i] = leds[i-1];
}

//reset
EVERY_N_MILLIS_I( Dot_time, 500) {
 Dot_time.setPeriod( wait1 );
 leds_done = 0;
}

if(leds_done <dots) {
leds[0] = Array_color;
leds_done = leds_done + 1;
 } else {
leds[0] = CRGB::Black;

  }

 }


//============================================

void CD77_chase_one_color_unsymet(CRGB color_one, uint16_t wait1, uint16_t wait2,uint8_t dots ) {
//shift pixels
for(int i = NUM_LEDS - 1; i >0; i--) {
leds[i] = leds[i-1];
}

//reset
EVERY_N_MILLIS_I( Dot_time, 500) {
Dot_time.setPeriod( random16(wait1,wait2) );
leds_done = 0;
}

if(leds_done <dots) {
leds[0] = color_one; 
leds_done = leds_done + 1;
 } else {
leds[0] = CRGB::Black;
  }
 }
 
//=============================================
void CD77_chase_array_color_unsymet(uint16_t wait1, uint16_t wait2,uint16_t wait_Array, uint8_t dots ) {

EVERY_N_MILLIS_I( Array_time, 500){ 
  Array_time.setPeriod( wait_Array );
  i++;
  if (i > Array_Size-1) {i = 0;}
  Array_color = colorarry[i];
  }

//shift pixels
for(int i = NUM_LEDS - 1; i >0; i--) {
leds[i] = leds[i-1];
}

//reset
EVERY_N_MILLIS_I( Dot_time, 200) {
 Dot_time.setPeriod( random16(wait1,wait2) );
 leds_done = 0;

}

if(leds_done <dots) {
leds[0] = Array_color; //colorarry[i];
leds_done = leds_done + 1;
} else {
leds[0] = CRGB::Black;
  }
 }

//=================================================

void CD77_chase_PAL_symet( uint16_t deltacolorIndex, uint16_t wait1, uint8_t dots ) {
//shift pixels
for(int i =  NUM_LEDS - 1; i >0; i--) {
leds[i] = leds[i-1];
colorIndex += deltacolorIndex;

}

//reset
EVERY_N_MILLIS_I( Dot_time, 400) {
    
Dot_time.setPeriod( wait1 );
 leds_done = 0;

}

if(leds_done <dots) {
leds[0] = ColorFromPalette( currentPalette, colorIndex, 255, currentBlending);

leds_done = leds_done + 1;
 } else {
leds[0] = CRGB::Black;

  }
 }

//=============================

void CD77_chase_PAL_unsymet(uint16_t deltacolorIndex, uint16_t wait1, uint16_t wait2,uint8_t dots ) {
//shift pixels
for(int i = NUM_LEDS - 1; i >0; i--) {
leds[i] = leds[i-1];
colorIndex += deltacolorIndex;
}

//reset
EVERY_N_MILLIS_I( Dot_time, 500) {
Dot_time.setPeriod( random16(wait1,wait2) );
leds_done = 0;
}

if(leds_done <dots) {
leds[0] = ColorFromPalette( currentPalette, colorIndex, 255, currentBlending);
leds_done = leds_done + 1;
 } else {
leds[0] = CRGB::Black;
  }
 }
 
#endif  
