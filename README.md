This sketch measures the current up to 26V / 3.2A of an electrical consumer.
It uses the INA219 High Side DC Current Sensor Breakout Board from Adafruit.

![Hardware](/hardware.jpg "")

Requirements
* Breakout Board: http://www.adafruit.com/products/904
* Adafruit Library: http://learn.adafruit.com/adafruit-ina219-current-sensor-breakout/downloads

Tutorial can be found here: http://learn.adafruit.com/adafruit-ina219-current-sensor-breakout/overview

The sketch puts out shunt voltage, load voltage and current with a 10 seconds interval.

To read the output use

$ ruby serial-port-read.rb