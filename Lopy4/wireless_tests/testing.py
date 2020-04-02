from  network import WLAN
import time
import pycom

# setup as a station
# wlan=WLAN()
# wlan.connect('Mano', auth=(WLAN.WPA2, 'alausalaus'))
# while not wlan.isconnected():
#    time.sleep_ms(50)
#    print("waiting")
# print(wlan.ifconfig())

##initiate as STA
wlan = WLAN(mode=WLAN.STA)
wlan.antenna(WLAN.EXT_ANT)
nets = wlan.scan()
for net in nets:
	print(net)

##reinitiate as AP

wlan=WLAN()

wlan.antenna(WLAN.EXT_ANT)

wlan.init(mode=WLAN.AP, ssid='wipy-wlan', auth=(WLAN.WPA2,'www.wipy.io'), channel=7, antenna=WLAN.EXT_ANT)
wlan.antenna(WLAN.EXT_ANT)

print("done")
pycom.heartbeat(False)

pycom.rgbled(0x010101) # yellow
#time.sleep(1)