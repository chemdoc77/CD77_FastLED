#ifndef Time_performance.h
#define Time_performance.h

// This code is based on the Time Performance by Mark Kriegsman of FastLED
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
  FROM(0,0,00.000)   {FastLED.setBrightness(BRIGHTNESS); random16_add_entropy(random(65535)); CD77_Halloween_Colors(1000); CD77_Chase_Halloween(100, 800,3); FastLED.delay(50);}
  // CD77_Halloween_Colors(time to repeat in milliseconds), CD77_Chase_Halloween(lower time limit for time function in milliseconds, upper time limit for time function in milliseconds,number of dot)
  FROM(0,0,20.000)   {FastLED.clear();FastLED.show();}
  FROM(0,0,20.200)   {random16_add_entropy(random(65535)); CD77_Halloween_Colors_2 (4000);  CD77_breath(); FastLED.show();}
  FROM(0,0,40.000)   {FastLED.clear();FastLED.show();}
  FROM(0,0,40.200)   {FastLED.setBrightness(BRIGHTNESS); CD77_Spooky_Eyes();}
  FROM(0,1,10.000)   {FastLED.clear();FastLED.show();}
  AT(0,1,10.200)     {RestartPerformance(); }
  
}
#endif
