## Adafruit Feather M0 guide

### Arduino IDE
#### Follow instructions on to download SAMD libraries
https://learn.adafruit.com/adafruit-feather-m0-basic-proto/using-with-arduino-ide
#### Adapting old sketches
https://learn.adafruit.com/adafruit-feather-m0-basic-proto/adapting-sketches-to-m0

Afterwards just run your old Arduino C++ code

### CircuitPython
Full instructions
https://learn.adafruit.com/adafruit-feather-m0-express-designed-for-circuit-python-circuitpython/kattni-circuitpython
https://learn.adafruit.com/welcome-to-circuitpython/installing-circuitpython
Downloader CircuitPython bootloader
https://circuitpython.org/board/feather_m0_rfm9x/

### Important considerations
https://learn.adafruit.com/adafruit-feather-m0-radio-with-lora-radio-module/circuitpython-for-rfm9x-lora

'Receiving packets is a 'best effort' in pure Python code.  Unlike the Arduino versions of the RFM9x library there is no interrupt support which means when a packet is received it must be immediately processed by the Python code or it could be lost'
'Sending and receiving packets will 'block' your Python code until the packet is fully processed.  This means you can't do a lot of other things while sending and waiting for packets to be received.'
