#ifndef Time_performance.h
#define Time_performance.h

/* This code is based on the Time Performance sketch by Mark Kriegsman of FastLED at:
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

//note: add  random16_add_entropy( random(0,65535)); and FastLED.delay(1000 / FRAMES_PER_SECOND); for Fire2012 entries
void Performance()
{
  FROM(0,0,00.000)   {FastLED.setBrightness(BRIGHTNESS); random16_add_entropy(random(0,65535)); CD77_Halloween_Colors(600); CD77_Chase_Halloween_fixed(300,3); FastLED.delay(50);}
  FROM(0,0,15.000)   {/*FastLED.setBrightness(BRIGHTNESS);*/ random16_add_entropy(random(0,65535)); CD77_Halloween_Colors(600); CD77_Chase_Halloween_fixed(700,8); FastLED.delay(50);}
  FROM(0,0,30.000)   {FastLED.clear();FastLED.show();}
  FROM(0,0,30.200)   {random16_add_entropy(random(0,65535)); CD77_Halloween_Colors_2 (4000);  CD77_breath(); FastLED.show();}
  FROM(0,0,50.000)   {FastLED.clear();FastLED.show();}
  FROM(0,0,50.200)   {FastLED.setBrightness(BRIGHTNESS);random16_add_entropy(random(0,65535));  gPal = HeatColors_p; Fire2012WithPalette(75,80); FastLED.delay(1000 / FRAMES_PER_SECOND);}
  FROM(0,1,05.000)   {random16_add_entropy(random(0,65535)); gPal = CRGBPalette16( CRGB::Black, CRGB::Blue, CRGB::Aqua,  CRGB::White); Fire2012WithPalette(75,80); FastLED.delay(1000 / FRAMES_PER_SECOND);}
  FROM(0,1,20.000)   {FastLED.clear();FastLED.show();}
  AT(0,1,20.200)     {RestartPerformance(); }
  
}
#endif
