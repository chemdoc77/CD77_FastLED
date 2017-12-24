#ifndef Time_performance.h
#define Time_performance.h

/*
 
 Based on the Time Performance sketch by Mark Kriegsman of FastLED at:
 https://gist.github.com/kriegsman/a916be18d32ec675fea8
 
*/


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
  FROM(0,0,00.000)   {CD77_chase_one_color_symet(CRGB::Red, 400, 2); FastLED.delay(50);}
  FROM(0,0,06.000)   {CD77_chase_one_color_symet(CRGB::DarkBlue, 800, 6); FastLED.delay(50);}
  FROM(0,0,12.000)   {CD77_chase_array_color_symet(400,800,2); FastLED.delay(50);}
  FROM(0,0,20.000)   {random16_add_entropy(random(65535)); CD77_chase_one_color_unsymet(CRGB::Yellow,200,800,3); FastLED.delay(50);}
  FROM(0,0,26.000)   {random16_add_entropy(random(65535)); CD77_chase_array_color_unsymet(200,800,400, 2); FastLED.delay(50);}
  FROM(0,0,32.000)   {random16_add_entropy(random(65535));  EVERY_N_MILLIS(750){dotnumber = random16(3,6);};  CD77_chase_array_color_unsymet(200,800,400, dotnumber); FastLED.delay(50);}
  FROM(0,0,40.000)   {currentPalette = CRGBPalette16(CRGB::Blue, CRGB::Blue, CRGB::Red, CRGB::Red); CD77_chase_PAL_symet( 5, 400, 4 );FastLED.delay(50);}
  FROM(0,0,50.000)   {random16_add_entropy(random(65535)); currentPalette =  bhw1_28_gp; CD77_chase_PAL_unsymet(5, 200,800,4); FastLED.delay(50);}
  AT(0,0,60.000)     {RestartPerformance(); }
  
}
#endif
