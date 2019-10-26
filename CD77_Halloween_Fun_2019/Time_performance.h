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



void Performancex3()
{
  FROM(0,0,00.000)   {CD77_flicker(CRGB::OrangeRed, 5, 20); }
  FROM(0,0,04.000)   {CD77_flicker(CRGB::Purple, 5, 20);}
  FROM(0,0,08.000)   {CD77_flicker(CRGB::Green, 5, 20);}
  FROM(0,0,12.000)   {CD77_flicker(CRGB::OrangeRed, 1, 30); }
  FROM(0,0,16.000)   {CD77_flicker(CRGB::Purple, 1, 30);}
  FROM(0,0,20.000)   {CD77_flicker(CRGB::Green, 1, 30);}
  FROM(0,0,24.200)   {FastLED.setBrightness(BRIGHTNESS); random16_add_entropy(random(0,65535)); CD77_Halloween_Colors(600); CD77_Chase_Halloween_fixed(300,3); FastLED.delay(50);}
  FROM(0,0,32.000)   { random16_add_entropy(random(0,65535)); CD77_Halloween_Colors(600); CD77_Chase_Halloween_fixed(700,8); FastLED.delay(50);}
  FROM(0,0,40.000)   {FastLED.clear();FastLED.show();}
   FROM(0,0,40.200)   {FastLED.setBrightness(BRIGHTNESS);random16_add_entropy(random(0,65535));  gPal = HeatColors_p; Fire2012WithPalette(75,80); FastLED.delay(1000 / FRAMES_PER_SECOND);}
  FROM(0,0,50.000)   {random16_add_entropy(random(0,65535)); gPal = CRGBPalette16( CRGB::Black, CRGB::Blue, CRGB::Aqua,  CRGB::White); Fire2012WithPalette(75,80); FastLED.delay(1000 / FRAMES_PER_SECOND);}
  FROM(0,1,00.000)   {FastLED.clear();FastLED.show();}
  AT(0,1,00.200)     {RestartPerformance(); }
  
}



void Performance4c()
{
  FROM(0,0,00.000)   { CD77_Chase_Halloween_fixed_color(CRGB::OrangeRed,700,8); FastLED.delay(50);}
  FROM(0,0,02.000)   { CD77_Chase_Halloween_fixed_color(CRGB::Purple, 700,8); FastLED.delay(50);}
  FROM(0,0,04.000)   { CD77_Chase_Halloween_fixed_color(CRGB::Green, 700,8); FastLED.delay(50);}
  FROM(0,0,06.000)   { CD77_Chase_Halloween_fixed_color(CRGB::OrangeRed,700,8); FastLED.delay(50);}
  FROM(0,0,08.000)   { CD77_Chase_Halloween_fixed_color(CRGB::Purple, 700,8); FastLED.delay(50);}
  FROM(0,0,10.000)   { CD77_Chase_Halloween_fixed_color(CRGB::Green, 700,8); FastLED.delay(50);}
  AT(0,0,12.000)     {RestartPerformance(); }
}


void Performance5()
{
  FROM(0,0,00.000)   {CD77_flicker(CRGB::OrangeRed, 5, 30); }
  FROM(0,0,03.000)   {CD77_flicker(CRGB::Purple, 5, 30);}
  FROM(0,0,06.000)   {CD77_flicker(CRGB::Green, 5, 30);}
  FROM(0,0,09.000)   {CD77_flicker(CRGB::OrangeRed, 5, 30); }
  FROM(0,0,12.000)   {CD77_flicker(CRGB::Purple, 5, 30);}
  FROM(0,0,15.000)   {CD77_flicker(CRGB::Green, 5, 30);}
  FROM(0,0,18.000)   { CD77_Chase_Halloween_fixed_color(CRGB::OrangeRed,700,8); FastLED.delay(50);}
  FROM(0,0,21.000)   { CD77_Chase_Halloween_fixed_color(CRGB::Purple, 700,8); FastLED.delay(50);}
  FROM(0,0,24.000)   { CD77_Chase_Halloween_fixed_color(CRGB::Green, 700,8); FastLED.delay(50);}
  FROM(0,0,27.000)   { CD77_Chase_Halloween_fixed_color(CRGB::OrangeRed,700,8); FastLED.delay(50);}
  FROM(0,0,30.000)   { CD77_Chase_Halloween_fixed_color(CRGB::Purple, 700,8); FastLED.delay(50);}
  FROM(0,0,33.000)   { CD77_Chase_Halloween_fixed_color(CRGB::Green, 700,8); FastLED.delay(50); }
  FROM(0,0,36.000)   {FastLED.clear();FastLED.show();}
  FROM(0,0,36.200)   {FastLED.setBrightness(BRIGHTNESS);random16_add_entropy(random(0,65535));  gPal = HeatColors_p; Fire2012WithPalette(75,80); FastLED.delay(1000 / FRAMES_PER_SECOND);}
  FROM(0,0,46.000)   {random16_add_entropy(random(0,65535)); gPal = CRGBPalette16( CRGB::Black, CRGB::Blue, CRGB::Aqua,  CRGB::White); Fire2012WithPalette(75,80); FastLED.delay(1000 / FRAMES_PER_SECOND);}
  FROM(0,0,56.000)   {FastLED.clear();FastLED.show();}
  AT(0,0,56.200)     {RestartPerformance(); }
  
}






void Performance2()
{
  FROM(0,0,00.000)   {CD77_flicker(CRGB::OrangeRed, 5, 30); }
  FROM(0,0,04.000)   {CD77_flicker(CRGB::Purple, 5, 30);}
  FROM(0,0,08.000)   {CD77_flicker(CRGB::Green, 5, 30);}
 
  AT(0,0,12.000)     {RestartPerformance(); }
  
}

void Performancex2()
{
  FROM(0,0,00.000)   {CD77_flicker(CRGB::OrangeRed, 5, 30); }
  FROM(0,0,04.000)   {CD77_flicker(CRGB::Purple, 5, 30);}
  FROM(0,0,08.000)   {CD77_flicker(CRGB::Green, 5, 30);}
  FROM(0,0,12.000)   {CD77_flicker(CRGB::OrangeRed, 5, 30); }
  FROM(0,0,16.000)   {CD77_flicker(CRGB::Purple, 5, 30);}
  FROM(0,0,20.000)   {CD77_flicker(CRGB::Green, 5, 30);}
  FROM(0,0,24.000)   {FastLED.setBrightness(BRIGHTNESS); random16_add_entropy(random(0,65535)); CD77_Halloween_Colors(600); CD77_Chase_Halloween_fixed(300,3); FastLED.delay(50);}
  FROM(0,0,39.000)   { random16_add_entropy(random(0,65535)); CD77_Halloween_Colors(600); CD77_Chase_Halloween_fixed(700,8); FastLED.delay(50);}
  FROM(0,0,54.000)   {FastLED.clear();FastLED.show();}
  //FROM(0,0,54.200)   {random16_add_entropy(random(0,65535)); CD77_Halloween_Colors_2 (4000);  CD77_breath(); FastLED.show();}
  FROM(0,0,74.000)   {FastLED.clear();FastLED.show();}
  FROM(0,0,74.200)   {FastLED.setBrightness(BRIGHTNESS);random16_add_entropy(random(0,65535));  gPal = HeatColors_p; Fire2012WithPalette(75,80); FastLED.delay(1000 / FRAMES_PER_SECOND);}
  FROM(0,1,29.000)   {random16_add_entropy(random(0,65535)); gPal = CRGBPalette16( CRGB::Black, CRGB::Blue, CRGB::Aqua,  CRGB::White); Fire2012WithPalette(75,80); FastLED.delay(1000 / FRAMES_PER_SECOND);}
  FROM(0,1,44.000)   {FastLED.clear();FastLED.show();}
  AT(0,1,44.200)     {RestartPerformance(); }
  
}

void Performance()
{
  FROM(0,0,00.000)   {FastLED.setBrightness(BRIGHTNESS); random16_add_entropy(random(0,65535)); CD77_Halloween_Colors(600); CD77_Chase_Halloween_fixed(300,3); FastLED.delay(50);}
  FROM(0,0,15.000)   { random16_add_entropy(random(0,65535)); CD77_Halloween_Colors(600); CD77_Chase_Halloween_fixed(700,8); FastLED.delay(50);}
  FROM(0,0,30.000)   {FastLED.clear();FastLED.show();}
  //FROM(0,0,30.200)   {random16_add_entropy(random(0,65535)); CD77_Halloween_Colors_2 (4000);  CD77_breath(); FastLED.show();}
  FROM(0,0,50.000)   {FastLED.clear();FastLED.show();}
  FROM(0,0,50.200)   {FastLED.setBrightness(BRIGHTNESS);random16_add_entropy(random(0,65535));  gPal = HeatColors_p; Fire2012WithPalette(75,80); FastLED.delay(1000 / FRAMES_PER_SECOND);}
  FROM(0,1,05.000)   {random16_add_entropy(random(0,65535)); gPal = CRGBPalette16( CRGB::Black, CRGB::Blue, CRGB::Aqua,  CRGB::White); Fire2012WithPalette(75,80); FastLED.delay(1000 / FRAMES_PER_SECOND);}
  FROM(0,1,20.000)   {FastLED.clear();FastLED.show();}
  AT(0,1,20.200)     {RestartPerformance(); }



  
}


#endif
