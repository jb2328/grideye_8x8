//highly modified example file
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_DotStarMatrix.h>
#include <Adafruit_DotStar.h>
#ifndef PSTR
#define PSTR // Make Arduino Due happy
#endif

#define DATAPIN  4
#define CLOCKPIN 5

// MATRIX DECLARATION:
// Parameter 1 = width of DotStar matrix
// Parameter 2 = height of matrix
// Parameter 3 = pin number (most are valid)
// Parameter 4 = matrix layout flags, add together as needed:
//   DS_MATRIX_TOP, DS_MATRIX_BOTTOM, DS_MATRIX_LEFT, DS_MATRIX_RIGHT:
//     Position of the FIRST LED in the matrix; pick two, e.g.
//     DS_MATRIX_TOP + DS_MATRIX_LEFT for the top-left corner.
//   DS_MATRIX_ROWS, DS_MATRIX_COLUMNS: LEDs are arranged in horizontal
//     rows or in vertical columns, respectively; pick one or the other.
//   DS_MATRIX_PROGRESSIVE, DS_MATRIX_ZIGZAG: all rows/columns proceed
//     in the same order, or alternate lines reverse direction; pick one.
//   See example below for these values in action.
// Parameter 5 = pixel type:
//   DOTSTAR_BRG  Pixels are wired for BRG bitstream (most DotStar items)
//   DOTSTAR_GBR  Pixels are wired for GBR bitstream (some older DotStars)

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

size_t n;

void setup() {
  matrix.begin();
  matrix.setBrightness(40);
  matrix.setTextColor(colors[0]);
  Serial.begin(9600);
 n = sizeof(colors) / sizeof(uint16_t);
  Serial.println(n);
  delay(2000);
}
void loop() {
  // put your main code here, to run repeatedly:
  matrix.fillScreen(colors[2]);
  matrix.show();
  delay(20);
  int i = 0;
  for (int x = 0; x < 8; x++) {
    for (int y = 0; y < 8; y++) {
      matrix.drawPixel(x, y, colors[i]);
      
      Serial.print(x);
      Serial.print(" ");
      Serial.println(y);
      //int loc = x + y * width;

      if (i < 63) {
        i++;
      }
      else {
        i = 0;
      }
      matrix.show();
    }
  }
   delay(1000);

}
