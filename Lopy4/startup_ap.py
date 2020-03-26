import pycom
from network import WLAN

# https://docs.pycom.io/firmwareapi/pycom/pycom.html#pycomwifionbootenable
pycom.wlan_on_boot(True)

wlan = WLAN()
wlan.init(mode=WLAN.AP, ssid='wipy-wlan', auth=(WLAN.WPA2,'www.wipy.io'), channel=7, antenna=WLAN.INT_ANT)

# id=1 is for configuring the AP mode
wlan.ifconfig(id=1, config=('192.168.4.1', '255.255.255.0', '192.168.4.1', '8.8.8.8'))

print("done")