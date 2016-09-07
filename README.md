# Intro
This is a simple library to use the [SHT21P Sensirion](https://www.sensirion.com/products/humidity-sensors/humidity-temperature-sensor-sht2x-digital-i2c-accurate/) sensor with an Arduino.
The SHT21P uses pulse width modulation (PWM) to express its temperature and humidity readings.

**Warning:** the SHT21P uses 3.3V to power up. It's pins SDA and SCL should also be at the 3.3V level. If you are using UNO or other boards that have 5V output at its pins, be sure to level-shift it.

# Basic example
The sample sketch `examples/basic` simply prints sensor data to Serial. The important parts are:

1. Initialize your sensor at the pins.

 `SHT21P sensor(5,4,3);`  
 Here, pin 5 corresponds to the VDD, pin 4 with SDA, and pin 3 with SCL.  
 Connecting the VDD pin to a GPIO port allows us to power up/down the sensor.
 
 | SHT21P | Arduino |
 | --- | --- |
 | VDD | 5 |
 | SDA | 4 |
 | SCL | 3 |
 | VSS | GND |
 
2. Power up the sensor.

 `sensor.powerUp();`  
 This has a built-in 150ms delay to allow the sensor to start up.
 
3. Read the temperature or relative humidity and print it to Serial.

 `sensor.readTemp()` returns the degrees Celsius as a `float`.
 `sensor.readRH()` returns the %RH as a float.
 
 Both functions include the 1.2s delay to wait for the sensor to output the correct PWM signal for either temperature or relative humidity.  
 Both functions will return a `-100` if the expected PWM signal output is not present.
 
# Other functions

`sensor.powerDown();` allows you to power down the sensor which can save about 180uA.