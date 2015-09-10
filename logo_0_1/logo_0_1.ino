#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN 6

// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(17, PIN, NEO_GRB + NEO_KHZ800);

// IMPORTANT: To reduce NeoPixel burnout risk, add 1000 uF capacitor across
// pixel power leads, add 300 - 500 Ohm resistor on first pixel's data input
// and minimize distance between Arduino and first pixel.  Avoid connecting
// on a live circuit...if you must, connect GND first.

void setup() {
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
  //#if defined (__AVR_ATtiny85__)
  //  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
  //#endif
  // End of trinket special code


  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}

void loop() {
  yellow_green_heartbeat();
}


void yellow_green_heartbeat() {
//Herzschlag 1 grün an
   for(uint16_t f=10; f<80; f++) {
      for(uint16_t i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i,0,f,0);
      }
  delay(2);    
  strip.show();
  }
//Herzschlag 1 grün aus  
  for(uint16_t f=80; f>10; f--) {
      for(uint16_t i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i,0,f,0);
      }
  delay(5);    
  strip.show();
  }
//Herzschlag 2 grün an  
  for(uint16_t f=10; f<80; f++) {
      for(uint16_t i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i,0,f,0);
      }
  delay(5);    
  strip.show();
  }
//Herzschlag 2 grün aus
  for(uint16_t f=80; f>10; f--) {
      for(uint16_t i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i,0,f,0);
      }
  delay(10);    
  strip.show();
  }
//Zwischenpause
delay(300);
//Herzschlag 3 gelb an
 for(uint16_t f=10; f<80; f++) {
      for(uint16_t i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i,f,f,0);
      }
  delay(2);    
  strip.show();
  }
//Herzschlag 3 gelb aus
  for(uint16_t f=80; f>10; f--) {
      for(uint16_t i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i,f,f,0);
      }
  delay(5);    
  strip.show();
  }
//Herzschlag 4 gelb an
  for(uint16_t f=10; f<80; f++) {
      for(uint16_t i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i,f,f,0);
      }
  delay(5);    
  strip.show();
  }
//Herzschlag 4 gelb aus
  for(uint16_t f=80; f>10; f--) {
      for(uint16_t i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i,f,f,0);
      }
  delay(10);    
  strip.show();
  }
//Zwischenpause
delay(300);
}

