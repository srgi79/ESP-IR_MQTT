# ESP-IR_MQTT

#### Send IR commands via MQTT/Google Assistant

You can do it

### Hardware

* [ESP8266/ESP32](https://es.aliexpress.com/item/ESP8266-serial-WIFI-Witty-cloud-Development-Board-ESP-12F-module-MINI-nodemcu/32569199462.html) Used ESP8266 Witty
* [IR-LED](https://es.aliexpress.com/item/10pair-lot-5mm-Infrared-receiver-and-Infrared-emitting-transmit-diodes-IR-LED/32452151722.html) 5mm IR-LED
* [Resistor-Kit](https://es.aliexpress.com/item/230Pcs-12-ohm-180-Ohm-1-4w-Resistance-5-Metal-Film-Resistor-Resistance-Assortment-Kit-Set/32793409547.html) Resistor Kit
* [BC547](https://es.aliexpress.com/store/product/100pcs-bag-BC547-TO-92-45V-0-1A-NPN-transistor-low-power/1630603_32260347646.html) General use NPN BJT Transistor
* Some wires
* USB cable

### Software

* [Node-Red](https://nodered.org/) Used in Raspberry Pi 1B
* [Arduino-IDE](https://www.arduino.cc/) Used in Windows
* [GoogleAssistant](https://assistant.google.com/intl/es_es/) Used in Google Home / Android

#### Library dependencies

* [ESP8266](https://github.com/esp8266/Arduino) ESP8266
* [PubSubClient](https://github.com/knolleary/pubsubclient) MQTT
* [IRremoteESP8266](https://github.com/markszabo/IRremoteESP8266) IR

#### Node-Red dependencies

* [NORA](https://flows.nodered.org/node/node-red-contrib-nora) NORA


### Electronic circuit
#### Protoboard
<p align="center">
<img src="https://raw.githubusercontent.com/srgi79/ESP-IR_MQTT/master/Fritzing/Fritzing_bb.png" alt="Protoboard"/>
</p>



#### Schematic
<p align="center">
<img src="ESP-IR_MQTT/Fritzing/Fritzing_sch.png" alt="Schematic"/>
</p>

### Arduino configuration

* [BOARD] Witty/Adafruit HUZZAH ESP8266
* [UPLOAD-SPEED] 115200
* [FLASH-SIZE] 4M (1M SPIFFS)


TEST

*TEST*

```
TEST
```
