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


//=========CD77_Code=====================

void Performance()
{  
   // strobe fill all

  FROM(0,0,00.000)   {  CD77_Strobe_2(CRGB::Red,  40);}
  FROM(0,0,00.600)   {  fill_solid(leds, NUM_LEDS, CRGB::Black); FastLED.show();}
  FROM(0,0,01.000)   {  CD77_Strobe_2(CRGB::Grey,  40);}
  FROM(0,0,01.600)   {  fill_solid(leds, NUM_LEDS, CRGB::Black); FastLED.show();}
  FROM(0,0,02.000)   {  CD77_Strobe_2(CRGB::Blue,  40);}
  FROM(0,0,02.600)   {  fill_solid(leds, NUM_LEDS, CRGB::Black); FastLED.show();}
  FROM(0,0,03.000)   {  CD77_Strobe_2(CRGB::Red,  40);}
  FROM(0,0,03.600)   {  fill_solid(leds, NUM_LEDS, CRGB::Black); FastLED.show();}
  FROM(0,0,04.000)   {  CD77_Strobe_2(CRGB::Grey,  40);}
  FROM(0,0,04.600)   {  fill_solid(leds, NUM_LEDS, CRGB::Black); FastLED.show();}
  FROM(0,0,05.000)   {  CD77_Strobe_2(CRGB::Blue,  40);}
  FROM(0,0,05.600)   {  fill_solid(leds, NUM_LEDS, CRGB::Black); FastLED.show();}


  //1/3 strobe fill  
  FROM(0,0,06.000)   {  CD77_Strobe_CRGBSet_3_1_on(0, CRGB::Red, 40);}
  FROM(0,0,06.600)   {  fill_solid(leds, NUM_LEDS, CRGB::Black); FastLED.show();}
  FROM(0,0,07.000)   {  CD77_Strobe_CRGBSet_3_1_on(1, CRGB::Grey, 40);}
  FROM(0,0,07.600)   {  fill_solid(leds, NUM_LEDS, CRGB::Black); FastLED.show();}
  FROM(0,0,08.000)   {  CD77_Strobe_CRGBSet_3_1_on(2, CRGB::Blue, 40);}
  FROM(0,0,08.600)   {  fill_solid(leds, NUM_LEDS, CRGB::Black); FastLED.show();}
  FROM(0,0,09.000)   {  CD77_Strobe_CRGBSet_3_1_on(0, CRGB::Red, 40);}
  FROM(0,0,09.600)   {  fill_solid(leds, NUM_LEDS, CRGB::Black); FastLED.show();}
  FROM(0,0,10.000)   {  CD77_Strobe_CRGBSet_3_1_on(1, CRGB::Grey, 40);}
  FROM(0,0,10.600)   {  fill_solid(leds, NUM_LEDS, CRGB::Black); FastLED.show();}
  FROM(0,0,11.000)   {  CD77_Strobe_CRGBSet_3_1_on(2, CRGB::Blue, 40);}
  FROM(0,0,11.600)   {  fill_solid(leds, NUM_LEDS, CRGB::Black); FastLED.show();}
  FROM(0,0,12.000)   {  CD77_Strobe_CRGBSet_6_3_on(0, 2,4,CRGB::Red, CRGB::Grey,  CRGB::Blue,40); }
  FROM(0,0,12.600)   {  fill_solid(leds, NUM_LEDS, CRGB::Black); FastLED.show();}
  FROM(0,0,13.000)   {  CD77_Strobe_CRGBSet_6_3_on(1,3,5,CRGB::Red, CRGB::Grey,  CRGB::Blue,40);}
  FROM(0,0,13.600)   {  fill_solid(leds, NUM_LEDS, CRGB::Black); FastLED.show();}
  FROM(0,0,14.000)   {  CD77_Strobe_CRGBSet_6_3_on(0, 2,4,CRGB::Red, CRGB::Grey,  CRGB::Blue,40); }
  FROM(0,0,14.600)   {  fill_solid(leds, NUM_LEDS, CRGB::Black); FastLED.show();}
  FROM(0,0,15.000)   {  CD77_Strobe_CRGBSet_6_3_on(1,3,5,CRGB::Red, CRGB::Grey,  CRGB::Blue,40);}
  FROM(0,0,15.600)   {  fill_solid(leds, NUM_LEDS, CRGB::Black); FastLED.show();}
  AT(0,0,16.000)     {  RestartPerformance(); }
}  


#endif
