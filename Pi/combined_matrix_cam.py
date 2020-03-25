import time
import random
import board
import busio
import adafruit_amg88xx
import adafruit_dotstar as dotstar
import math
from numpy import interp



i2c = busio.I2C(board.SCL, board.SDA)
amg = adafruit_amg88xx.AMG88XX(i2c)#had to modify smbus.py

 
# On-board DotStar for boards including Gemma, Trinket, and ItsyBitsy
dots = dotstar.DotStar(board.SCK, board.MOSI, 64, brightness=0.1)
# MAIN LOOP

color_pallete=[ 
 [ 255 , 0 , 0 ],
 [ 247 , 8 , 0 ],
 [ 239 , 16 , 0 ],
 [ 231 , 24 , 0 ],
 [ 223 , 32 , 0 ],
 [ 215 , 40 , 0 ],
 [ 207 , 48 , 0 ],
 [ 199 , 56 , 0 ],
 [ 191 , 64 , 0 ],
 [ 183 , 72 , 0 ],
 [ 175 , 80 , 0 ],
 [ 167 , 88 , 0 ],
 [ 159 , 96 , 0 ],
 [ 151 , 104 , 0 ],
 [ 143 , 112 , 0 ],
 [ 135 , 120 , 0 ],
 [ 128 , 128 , 0 ],
 [ 120 , 135 , 0 ],
 [ 112 , 143 , 0 ],
 [ 104 , 151 , 0 ],
 [ 96 , 159 , 0 ],
 [ 88 , 167 , 0 ],
 [ 80 , 175 , 0 ],
 [ 72 , 183 , 0 ],
 [ 64 , 191 , 0 ],
 [ 56 , 199 , 0 ],
 [ 48 , 207 , 0 ],
 [ 40 , 215 , 0 ],
 [ 32 , 223 , 0 ],
 [ 24 , 231 , 0 ],
 [ 16 , 239 , 0 ],
 [ 8 , 247 , 0 ],
 [ 0 , 255 , 0 ],
 [ 0 , 247 , 8 ],
 [ 0 , 239 , 16 ],
 [ 0 , 231 , 24 ],
 [ 0 , 223 , 32 ],
 [ 0 , 215 , 40 ],
 [ 0 , 207 , 48 ],
 [ 0 , 199 , 56 ],
 [ 0 , 191 , 64 ],
 [ 0 , 183 , 72 ],
 [ 0 , 175 , 80 ],
 [ 0 , 167 , 88 ],
 [ 0 , 159 , 96 ],
 [ 0 , 151 , 104 ],
 [ 0 , 143 , 112 ],
 [ 0 , 135 , 120 ],
 [ 0 , 128 , 128 ],
 [ 0 , 120 , 135 ],
 [ 0 , 112 , 143 ],
 [ 0 , 104 , 151 ],
 [ 0 , 96 , 159 ],
 [ 0 , 88 , 167 ],
 [ 0 , 80 , 175 ],
 [ 0 , 72 , 183 ],
 [ 0 , 64 , 191 ],
 [ 0 , 56 , 199 ],
 [ 0 , 48 , 207 ],
 [ 0 , 40 , 215 ],
 [ 0 , 32 , 223 ],
 [ 0 , 24 , 231 ],
 [ 0 , 16 , 239 ],
 [ 0 , 8 , 247 ]]
#print(color_pallete)

while True:
    pixels=[]
   #definitely don't need 2 for loops (or 3 for that matter) 
   #but as a temp solution this will do
    for row in amg.pixels:
         for temp in row:
              pixels.append(temp)
 
    i=0
    for pixel in pixels:       
        remap=int(interp(pixel,[20,35],[50,0]))         

        colors=color_pallete[remap]
        dots[i] = (colors[0], colors[1], colors[2])
        i+=1
        
   # time.sleep(0.01);
    
   