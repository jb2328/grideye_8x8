//highly modified example file
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_DotStarMatrix.h>
#include <Adafruit_DotStar.h>

#include <Wire.h>
#include <Adafruit_AMG88xx.h>

#ifndef PSTR
#define PSTR // Make Arduino Due happy
#endif

#define DATAPIN  4
#define CLOCKPIN 5

//low range of the sensor (this will be blue on the screen)
#define MINTEMP 22//22

//high range of the sensor (this will be red on the screen)
#define MAXTEMP 32//34
Adafruit_DotStarMatrix matrix = Adafruit_DotStarMatrix(
                                  8, 8, DATAPIN, CLOCKPIN,
                                  DS_MATRIX_TOP     + DS_MATRIX_RIGHT +
                                  DS_MATRIX_COLUMNS + DS_MATRIX_PROGRESSIVE,
                                  DOTSTAR_RGB);

const uint16_t colors[] = {
  //RGB RED TO BLUE IN 64 COLORS




 matrix.Color( 255 , 0 , 0 ),
 matrix.Color( 247 , 8 , 0 ),
 matrix.Color( 239 , 16 , 0 ),
 matrix.Color( 231 , 24 , 0 ),
 matrix.Color( 223 , 32 , 0 ),
 matrix.Color( 215 , 40 , 0 ),
 matrix.Color( 207 , 48 , 0 ),
 matrix.Color( 199 , 56 , 0 ),
 matrix.Color( 191 , 64 , 0 ),
 matrix.Color( 183 , 72 , 0 ),
 matrix.Color( 175 , 80 , 0 ),
 matrix.Color( 167 , 88 , 0 ),
 matrix.Color( 159 , 96 , 0 ),
 matrix.Color( 151 , 104 , 0 ),
 matrix.Color( 143 , 112 , 0 ),
 matrix.Color( 135 , 120 , 0 ),
 matrix.Color( 128 , 128 , 0 ),
 matrix.Color( 120 , 135 , 0 ),
 matrix.Color( 112 , 143 , 0 ),
 matrix.Color( 104 , 151 , 0 ),
 matrix.Color( 96 , 159 , 0 ),
 matrix.Color( 88 , 167 , 0 ),
 matrix.Color( 80 , 175 , 0 ),
 matrix.Color( 72 , 183 , 0 ),
 matrix.Color( 64 , 191 , 0 ),
 matrix.Color( 56 , 199 , 0 ),
 matrix.Color( 48 , 207 , 0 ),
 matrix.Color( 40 , 215 , 0 ),
 matrix.Color( 32 , 223 , 0 ),
 matrix.Color( 24 , 231 , 0 ),
 matrix.Color( 16 , 239 , 0 ),
 matrix.Color( 8 , 247 , 0 ),
 matrix.Color( 0 , 255 , 0 ),
 matrix.Color( 0 , 247 , 8 ),
 matrix.Color( 0 , 239 , 16 ),
 matrix.Color( 0 , 231 , 24 ),
 matrix.Color( 0 , 223 , 32 ),
 matrix.Color( 0 , 215 , 40 ),
 matrix.Color( 0 , 207 , 48 ),
 matrix.Color( 0 , 199 , 56 ),
 matrix.Color( 0 , 191 , 64 ),
 matrix.Color( 0 , 183 , 72 ),
 matrix.Color( 0 , 175 , 80 ),
 matrix.Color( 0 , 167 , 88 ),
 matrix.Color( 0 , 159 , 96 ),
 matrix.Color( 0 , 151 , 104 ),
 matrix.Color( 0 , 143 , 112 ),
 matrix.Color( 0 , 135 , 120 ),
 matrix.Color( 0 , 128 , 128 ),
 matrix.Color( 0 , 120 , 135 ),
 matrix.Color( 0 , 112 , 143 ),
 matrix.Color( 0 , 104 , 151 ),
 matrix.Color( 0 , 96 , 159 ),
 matrix.Color( 0 , 88 , 167 ),
 matrix.Color( 0 , 80 , 175 ),
 matrix.Color( 0 , 72 , 183 ),
 matrix.Color( 0 , 64 , 191 ),
 matrix.Color( 0 , 56 , 199 ),
 matrix.Color( 0 , 48 , 207 ),
 matrix.Color( 0 , 40 , 215 ),
 matrix.Color( 0 , 32 , 223 ),
 matrix.Color( 0 , 24 , 231 ),
 matrix.Color( 0 , 16 , 239 ),
 matrix.Color( 0 , 8 , 247 )
};
Adafruit_AMG88xx amg;
unsigned long delayTime;
float pixels[AMG88xx_PIXEL_ARRAY_SIZE];

int WIDTH = 8;
int HEIGHT = 8;
void setup() {
  matrix.begin();
  matrix.setBrightness(10);
  Serial.begin(9600);
  Serial.println(F("AMG88xx thermal camera!"));

  bool status;

  // default settings
  status = amg.begin();
  if (!status) {
    Serial.println("Could not find a valid AMG88xx sensor, check wiring!");
    while (1);
  }
  matrix.fillScreen(255);

  Serial.println("-- Thermal Camera Test --");
  delay(100); // let sensor boot up

}

void loop() { // put your main code here, to run repeatedly:
  //read all the pixels
  amg.readPixels(pixels);

  for (int i = 0; i < AMG88xx_PIXEL_ARRAY_SIZE; i++) {
    int colorIndex = map(pixels[i], MINTEMP, MAXTEMP, 0,63);
    colorIndex = constrain(colorIndex, 0,64);
    draw_pixel(i,colorIndex);
  // print_data(i,colorIndex);

}
   matrix.show();

}

void print_data( int i,int col_index){
     Serial.print(col_index);
    Serial.print(" ");
    if ((i + 1) % 8 == 0) {
      Serial.println();
    }

                

  Serial.println("--------------------");
  }

void draw_pixel(int loc, int col){
        int x=loc%WIDTH;
        int y=ceil(float(loc/HEIGHT));
        matrix.drawPixel(x, y, colors[col]);

  }
