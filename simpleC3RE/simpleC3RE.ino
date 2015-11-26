// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1
#define PIN1            8
#define PIN2            9
#define PIN3            10
#define PIN4            11

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      17

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels1 = Adafruit_NeoPixel(NUMPIXELS, PIN1, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels2 = Adafruit_NeoPixel(NUMPIXELS, PIN2, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels3 = Adafruit_NeoPixel(NUMPIXELS, PIN3, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels4 = Adafruit_NeoPixel(NUMPIXELS, PIN4, NEO_GRB + NEO_KHZ800);

int delayval = 500; // delay for half a second

void setup() {
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
#if defined (__AVR_ATtiny85__)
  if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
#endif
  // End of trinket special code

  pixels1.begin(); // This initializes the NeoPixel library.
  pixels2.begin();
  pixels3.begin();
  pixels4.begin();
}

void loop() {

  // For a set of NeoPixels the first NeoPixel is 0, second is 1, all the way up to the count of pixels minus one.

  for(int i=0;i<NUMPIXELS;i++){

    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels1.setPixelColor(i, pixels1.Color(0,150,0)); // Moderately bright green color.
    pixels2.setPixelColor(i, pixels1.Color(0,150,0));
    pixels3.setPixelColor(i, pixels1.Color(0,150,0));
    pixels4.setPixelColor(i, pixels1.Color(0,150,0));
    
    pixels1.show(); // This sends the updated pixel color to the hardware.
    pixels2.show();
    pixels3.show();
    pixels4.show();

    delay(delayval); // Delay for a period of time (in milliseconds).
  }
    theaterChase(pixels4.Color(0, 0, 127), 100); // Blue
    
}
//Theatre-style crawling lights.
void theaterChase(uint32_t c, uint8_t wait) {
  for (int j=0; j<10; j++) {  //do 10 cycles of chasing
    for (int q=0; q < 3; q++) {
      for (int i=0; i < pixels4.numPixels(); i=i+3) {
        pixels1.setPixelColor(i+q, c);  
        pixels2.setPixelColor(i+q, c);  
        pixels3.setPixelColor(i+q, c);  
        pixels4.setPixelColor(i+q, c);    //turn every third pixel on
      }
      
      pixels1.show();
      pixels2.show();
      pixels3.show();
      pixels4.show();

      delay(wait);

      for (int i=0; i < pixels4.numPixels(); i=i+3) {
        pixels1.setPixelColor(i+q, 0);
        pixels2.setPixelColor(i+q, 0);
        pixels3.setPixelColor(i+q, 0);
        pixels4.setPixelColor(i+q, 0);        //turn every third pixel off
      }
    }
  }
}
