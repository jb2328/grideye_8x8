### Raspberry Pi

![Pi](https://github.com/jb2328/grideye_8x8/blob/master/images/RPi.gif?raw=true "Pi")

AMG8833 requires Adafruit libraries to be installed on Raspberry Pi. 

[Adafruit's official guide.](https://learn.adafruit.com/adafruit-amg8833-8x8-thermal-camera-sensor/raspberry-pi-thermal-camera)

Run `blinkatest.py` to make sure your Pi is configured to use I2C (as well as have it enabled in `raspi-config`).

#### Dependencies

AMG8833

`sudo pip3 install adafruit-circuitpython-amg88xx`

DotStar 8x8 LED matrix

`sudo pip3 install adafruit-circuitpython-dotstar`

#### Connecting to the Pi
![Pi pinout](https://github.com/jb2328/grideye_8x8/blob/master/images/pi_pinout.png?raw=true "Pi pinout")

**AMG8833:**

`SCL` goes to `SCL` @ `GPIO3` | I2C

`SDA` goes to `SDA` @ `GPIO2` | I2C

`VIN` goes to `5V`

`GND` goes to `Ground`

**8x8 Matrix:**

`CI` goes to `SCK` @ `GPIO11` | SPI


`DI` goes to `MOSI` @ `GPI10` | SPI

`VIN` goes to `5V`

`GND` goes to `Ground`

#### Possible issues

##### 1. Running `blinkatest.py`

I had to go to `~/.local/lib/python3.7/site-packages`

and paste `adafruit_platformdetect` from https://github.com/adafruit/Adafruit_Python_PlatformDetect

to `~/.local/lib/python3.7/site-packages/adafruit_platformdetect`

otherwise `blinkatest.py` would not run.

##### 2. Running `init_test_8x8_IR.py`

The following line kept giving an eror in `smbus.py` in library files.

`amg = adafruit_amg88xx.AMG88XX(i2c)`

The solution was to modify `smbus.py` (the error will tell you where the file is on your Pi) by typecasting to int().





