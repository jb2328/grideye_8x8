from machine import I2C

print("Initialising I2C")
i2c = I2C(0)                         # create on bus 0
i2c = I2C(0, I2C.MASTER)             # create and init as a master
i2c = I2C(0, pins=('P10','P11'))     # create and use non-default PIN assignments (P10=SDA, P11=SCL)
print(i2c)
i2c.init(I2C.MASTER, baudrate=20000) # init as a master
print(i2c)

i2c.deinit()                         # turn off the periphera
print("done")