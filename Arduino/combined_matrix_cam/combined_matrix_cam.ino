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
#define MINTEMP 22

//high range of the sensor (this will be red on the screen)
#define MAXTEMP 34
Adafruit_DotStarMatrix matrix = Adafruit_DotStarMatrix(
                                  8, 8, DATAPIN, CLOCKPIN,
                                  DS_MATRIX_TOP     + DS_MATRIX_RIGHT +
                                  DS_MATRIX_COLUMNS + DS_MATRIX_PROGRESSIVE,
                                  DOTSTAR_RGB);

const uint16_t colors[] = {
  //RGB RED TO BLUE IN 64 COLORS

  matrix.Color( 255 , 0 , 0 ),
  matrix.Color( 251 , 0 , 4 ),
  matrix.Color( 247 , 0 , 8 ),
  matrix.Color( 243 , 0 , 12 ),
  matrix.Color( 240 , 0 , 15 ),
  matrix.Color( 236 , 0 , 19 ),
  matrix.Color( 232 , 0 , 23 ),
  matrix.Color( 228 , 0 , 27 ),
  matrix.Color( 224 , 0 , 31 ),
  matrix.Color( 220 , 0 , 35 ),
  matrix.Color( 216 , 0 , 39 ),
  matrix.Color( 213 , 0 , 43 ),
  matrix.Color( 209 , 0 , 46 ),
  matrix.Color( 205 , 0 , 50 ),
  matrix.Color( 201 , 0 , 54 ),
  matrix.Color( 197 , 0 , 58 ),
  matrix.Color( 193 , 0 , 62 ),
  matrix.Color( 189 , 0 , 66 ),
  matrix.Color( 185 , 0 , 70 ),
  matrix.Color( 182 , 0 , 73 ),
  matrix.Color( 178 , 0 , 77 ),
  matrix.Color( 174 , 0 , 81 ),
  matrix.Color( 170 , 0 , 85 ),
  matrix.Color( 166 , 0 , 89 ),
  matrix.Color( 162 , 0 , 93 ),
  matrix.Color( 158 , 0 , 97 ),
  matrix.Color( 155 , 0 , 100 ),
  matrix.Color( 151 , 0 , 104 ),
  matrix.Color( 147 , 0 , 108 ),
  matrix.Color( 143 , 0 , 112 ),
  matrix.Color( 139 , 0 , 116 ),
  matrix.Color( 135 , 0 , 120 ),
  matrix.Color( 131 , 0 , 124 ),
  matrix.Color( 128 , 0 , 128 ),
  matrix.Color( 124 , 0 , 131 ),
  matrix.Color( 120 , 0 , 135 ),
  matrix.Color( 116 , 0 , 139 ),
  matrix.Color( 112 , 0 , 143 ),
  matrix.Color( 108 , 0 , 147 ),
  matrix.Color( 104 , 0 , 151 ),
  matrix.Color( 100 , 0 , 155 ),
  matrix.Color( 97 , 0 , 158 ),
  matrix.Color( 93 , 0 , 162 ),
  matrix.Color( 89 , 0 , 166 ),
  matrix.Color( 85 , 0 , 170 ),
  matrix.Color( 81 , 0 , 174 ),
  matrix.Color( 77 , 0 , 178 ),
  matrix.Color( 73 , 0 , 182 ),
  matrix.Color( 70 , 0 , 185 ),
  matrix.Color( 66 , 0 , 189 ),
  matrix.Color( 62 , 0 , 193 ),
  matrix.Color( 58 , 0 , 197 ),
  matrix.Color( 54 , 0 , 201 ),
  matrix.Color( 50 , 0 , 205 ),
  matrix.Color( 46 , 0 , 209 ),
  matrix.Color( 43 , 0 , 213 ),
  matrix.Color( 39 , 0 , 216 ),
  matrix.Color( 35 , 0 , 220 ),
  matrix.Color( 31 , 0 , 224 ),
  matrix.Color( 27 , 0 , 228 ),
  matrix.Color( 23 , 0 , 232 ),
  matrix.Color( 19 , 0 , 236 ),
  matrix.Color( 15 , 0 , 240 ),
  matrix.Color( 12 , 0 , 243 ),
  matrix.Color( 8 , 0 , 247 ),
  matrix.Color( 4 , 0 , 251 )
};
Adafruit_AMG88xx amg;
unsigned long delayTime;
float pixels[AMG88xx_PIXEL_ARRAY_SIZE];

int WIDTH = 8;
int HEIGHT = 8;
void setup() {
  matrix.begin();
  matrix.setBrightness(40);
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
    int colorIndex = map(pixels[i], 15, 38, 0,63);
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
