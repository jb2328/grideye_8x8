### Pycom Lopy 4 

Please follow [Peter Hinch's excellent tutorial](https://github.com/peterhinch/micropython-amg88xx).

#### Other useful links to get Lopy4 set up

[Initial config](https://github.com/ttn-liv/devices/wiki/Getting-started-with-the-PyCom-LoPy)

[Using boot.py and main.py](https://github.com/johnmcdnz/LoPy/blob/master/Wifi%20config.md)

[Establishing an FTP connection](https://docs.pycom.io/gettingstarted/programming/ftp/)
/flash/ directory is used for ftp communications with Lopy4.

[Terminal over Wifi using telnet](https://docs.pycom.io/gettingstarted/programming/repl/telnet/) for more efficient testing of code.

[Micropython port of Adafruit CircuitPython libs](https://github.com/peterhinch/micropython-amg88xx)

#### Circuit Python dependencies

[Circuit Python port for AMG8833](https://github.com/adafruit/Adafruit_CircuitPython_AMG88xx) 
Did not work due to failing import `OrderedDict`.

#### I2C and SPI interfaces
[I2C](https://docs.pycom.io/firmwareapi/pycom/machine/i2c/)

[SPI](https://docs.pycom.io/firmwareapi/pycom/machine/spi/)
