#ifndef Time_performance.h
#define Time_performance.h

// Time Performance by Mark Kriegsman of FastLED
// at https://gist.github.com/kriegsman/a916be18d32ec675fea8

#define TC(HOURS,MINUTES,SECONDS) \
  ((uint32_t)(((uint32_t)((HOURS)*(uint32_t)(3600000))) + \
  ((uint32_t)((MINUTES)*(uint32_t)(60000))) + \
  ((uint32_t)((SECONDS)*(uint32_t)(1000)))))


#define AT(HOURS,MINUTES,SECONDS) if( atTC(TC(HOURS,MINUTES,SECONDS)) )
#define FROM(HOURS,MINUTES,SECONDS) if( fromTC(TC(HOURS,MINUTES,SECONDS)) )

static bool atTC( uint32_t tc)
{
  bool maybe = false;
  if( gTimeCode >= tc) {
    if( gLastTimeCodeDoneAt < tc) {
      maybe = true;
      gLastTimeCodeDoneAt = tc;
    }
  }
  return maybe;
}

static bool fromTC( uint32_t tc)
{
  bool maybe = false;
  if( gTimeCode >= tc) {
    if( gLastTimeCodeDoneFrom <= tc) {
      maybe = true;
      gLastTimeCodeDoneFrom = tc;
    }
  }
  return maybe;
} 

void RestartPerformance()
{
  gLastTimeCodeDoneAt = 0;
  gLastTimeCodeDoneFrom = 0;
  gTimeCodeBase = millis();
}


void Performance()
{
  FROM(0,0,00.000)   {CD77_rotatingPalette(); gCurrentPalette= CD77_BR2D_p;  FastLED.show();}
  FROM(0,0,08.000)   {speed = 20; CD77_fallingPalette(); gCurrentPalette= CD77_BR2_p;  FastLED.show();}
  FROM(0,0,16.000)   {speed = 50; northwardRainbow(); FastLED.show();}
  FROM(0,0,24.000)   {CD77_northeastwardRainbow_15(); FastLED.show();}
  FROM(0,0,32.000)   {speed = 30; CD77_rotatingPalette();gCurrentPalette= CD77_Bgold_p ;  FastLED.show();}
  FROM(0,0,40.000)   {fallingPalette(); gCurrentPalette= Magenta_Evening_gp; FastLED.show();} 
  FROM(0,0,48.010)   {speed = 50; rotatingRainbow();FastLED.show();} 
  FROM(0,0,56.000)   { westwardRainbow();FastLED.show();}
  FROM(0,1,04.000)   {speed= 30; CD77_rotatingPalette(); gCurrentPalette= CD77_RYGB_p; FastLED.show();}  
  FROM(0,1,12.000)   {rotatingPalette(); gCurrentPalette= jet_gp; FastLED.show();}  
  FROM(0,1,20.000)   {CD77_west_rotatingPalette(); gCurrentPalette= Sunset_Real_gp; FastLED.show();}
  FROM(0,1,28.000)   {CD77_west_rotatingPalette_xy(); gCurrentPalette= Sunset_Real_gp; FastLED.show();}
  FROM(0,1,36.000)   {CD77_west_norteastPalette_xy(); gCurrentPalette= Sunset_Real_gp; FastLED.show();}
  AT(0,1,44.000)     {speed = 50; RestartPerformance(); }
  
}
#endif
