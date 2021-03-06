import time
import random
import board
#import RPi.GPIO as GPIO
#import busio

import adafruit_dotstar as dotstar
 
# On-board DotStar for boards including Gemma, Trinket, and ItsyBitsy
dots = dotstar.DotStar(board.SCK, board.MOSI, 64, brightness=0.5)
 
# Using a DotStar Digital LED Strip with 30 LEDs connected to hardware SPI
# dots = dotstar.DotStar(board.SCK, board.MOSI, 30, brightness=0.2)
 
# Using a DotStar Digital LED Strip with 30 LEDs connected to digital pins
# dots = dotstar.DotStar(board.D6, board.D5, 30, brightness=0.2)
 
 
# HELPERS
# a random color 0 -> 224
def random_color():
    return random.randrange(0, 7) * 32
 
 
# MAIN LOOP
n_dots = len(dots)
while True:
    #print("hello")
    # Fill each dot with a random color
    for dot in range(n_dots):
        dots[dot] = (random_color(), random_color(), random_color())
 
    time.sleep(0.25)