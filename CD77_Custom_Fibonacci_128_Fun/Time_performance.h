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
  FROM(0,0,0.010)    {cd77_police_lights_one(0, 2, 50);} // Note: cd77_police_lights_one(color array used, number of segments, wait)
  FROM(0,0,5.000)    {cd77_police_lights_all(0, 2, 50);} // Note: cd77_police_lights_all(color array used, number of segments, wait)
  FROM(0,0,10.000)   {cd77_police_lights_one(1, 3, 50);}
  FROM(0,0,15.000)   {cd77_police_lights_all(1, 3, 50);}
  FROM(0,0,20.000)   {cd77_police_lights_one(1, 6, 50);}
  FROM(0,0,25.000)   {cd77_police_lights_all(1, 6, 50);}
  FROM(0,0,30.000)   {cd77_police_lights_one(2, 5, 50);}
  FROM(0,0,35.000)   {cd77_police_lights_all(2, 5, 50);}
  FROM(0,0,40.000)   {cd77_police_lights_one(2, 10, 50);}
  FROM(0,0,45.000)   {cd77_police_lights_all(2, 10, 50);}
 FROM(0,0,50.000)    {cd77_police_lights_one_palette(1,48,6,50);currentPalette = PartyColors_p;  currentBlending = LINEARBLEND;} //note: cd77_police_lights_all_palette( colorIndex,  deltacolorIndex, number of segments,  wait )
 FROM(0,0,55.000)    {cd77_police_lights_all_palette(1,48,6,50);currentPalette = PartyColors_p;  currentBlending = LINEARBLEND;} //note: cd77_police_lights_one_palette( colorIndex,  deltacolorIndex, number of segments,  wait )
  AT(0,1,00.000)     {RestartPerformance(); }
}





#endif
