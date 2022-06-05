#ifndef cd77_func1_h
#define cd77_func1_h

// Chemdoc77 basic functions 1




void cd77_colorwipe(CRGB color,  uint8_t to, uint8_t wait) {
  for (uint8_t i = 0; i <to; i++) {
    leds[i] = color;
    FastLED.show();
    delay(wait);
  }
}

void cd77_colorwipe_dot(CRGB color,uint8_t from,  uint8_t to,  uint8_t wait) {
  for (uint8_t i = from; i <to; i++) {
    leds[i] = color;
    FastLED.show();
    delay(wait);
    leds[i] = CRGB::Black;
    FastLED.show();
    //delay(wait);
    
  }
}


#endif
