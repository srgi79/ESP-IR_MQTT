
// WiFi: Config
const char* WIFI_SSID = "XXXX";
const char* WIFI_PASSWORD = "XXXX";

// MQTT: Config
const PROGMEM char* MQTT_CLIENT_ID = "IR1";
const PROGMEM char* MQTT_SERVER_IP = "192.168.0.100";
const PROGMEM short unsigned int MQTT_SERVER_PORT = 1883;
const PROGMEM char* MQTT_USER = "XXXX";
const PROGMEM char* MQTT_PASSWORD = "XXXX";

// MQTT: Topics
const char* MQTT_OUT_TOPIC = "IR1/OUT";
const char* MQTT_IN_TOPIC = "IR1/IN";

// PIN: Definitions
const short unsigned int kIrLed = 5;
const short unsigned int kIrLed2 = 14;
const short unsigned int ledBuilt = 2;
const short unsigned int buttonPin = 4;
const short unsigned int ledGreen =  12;
const short unsigned int ledBlue =  13;
const short unsigned int ledRed =  15;

// PIN: Analog Treshold
unsigned int threshold = 512;
