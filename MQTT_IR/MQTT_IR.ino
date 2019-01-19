
#if defined(ESP8266)
#include <ESP8266WiFi.h>        
#else
#include <WiFi.h>
#endif
#include <PubSubClient.h>
#include <IRremoteESP8266.h>
#include <IRsend.h>



#define MQTT_VERSION MQTT_VERSION_3_1_1

// Wifi: SSID and password
const char* WIFI_SSID = "ONDRONE";
const char* WIFI_PASSWORD = "gasalafibra";

// MQTT: ID, server IP, port, username and password
const PROGMEM char* MQTT_CLIENT_ID = "IR1";
const PROGMEM char* MQTT_SERVER_IP = "192.168.0.100";
const PROGMEM uint16_t MQTT_SERVER_PORT = 1883;
const PROGMEM char* MQTT_USER = "mqttuser";
const PROGMEM char* MQTT_PASSWORD = "mqttpwd";

// MQTT: topics
const char* MQTT_LIGHT_STATE_TOPIC = "IR1/OUT";
const char* MQTT_LIGHT_COMMAND_TOPIC = "IR1/IN";

// PIN: definitions
const int buttonPin = 4;// D2
const int ledGreen =  12;// D6 GREEN
const int ledBlue =  13;// D7 BLUE
const int ledRed =  15;// D8 RED
const int ledBuilt =  2;// D4
const int irPin =     5;// D1

WiFiClient wifiClient;
PubSubClient client(wifiClient);
IRsend irsend(irPin);


// function called when a MQTT message arrived
void callback(char* p_topic, byte* p_payload, unsigned int p_length) {
 // concat the payload into a string
 String payload;
 
 for (uint8_t i = 0; i < p_length; i++) {
   payload.concat((char)p_payload[i]);
 }
 Serial.print("Received: "); Serial.println(payload);
if (payload == "RED") {
  digitalWrite(ledRed,not digitalRead(ledRed));}
else if (payload == "GREEN") {
  digitalWrite(ledGreen,not digitalRead(ledGreen));}
else if (payload == "BLUE") {
  digitalWrite(ledBlue,not digitalRead(ledBlue));}
else if (payload == "BUILT") {
  digitalWrite(ledBuilt,not digitalRead(ledBuilt));}
else {
 // Convert from String HEX to LONG
 long hexCmd = strtol(&payload[0], NULL, 16);
 irsend.sendNEC(hexCmd, 32);
 Serial.print("LONG:"); Serial.println(hexCmd);
 }
}

void reconnect() {
 // Loop until we're reconnected
 while (!client.connected()) {
   Serial.print("INFO: Attempting MQTT connection...");
   // Attempt to connect
   if (client.connect(MQTT_CLIENT_ID, MQTT_USER, MQTT_PASSWORD)) {
     Serial.println("INFO: connected");
     // Once connected, publish an announcement...
     //publishLightState();
     // ... and resubscribe
     client.subscribe(MQTT_LIGHT_COMMAND_TOPIC);
   } else {
     Serial.print("ERROR: failed, rc=");
     Serial.print(client.state());
     Serial.println("DEBUG: try again in 5 seconds");
     // Wait 5 seconds before retrying
     delay(5000);
   }
 }
}

void setup() {
 Serial.begin(115200);
 pinMode(buttonPin,INPUT);
 pinMode(ledRed,OUTPUT);
 pinMode(ledGreen,OUTPUT);
 pinMode(ledBlue,OUTPUT);
 pinMode(ledBuilt,OUTPUT);
 digitalWrite(ledBuilt,true);
 irsend.begin();

 
 // init the WiFi connection
 Serial.println();
 Serial.println();
 Serial.print("INFO: Connecting to ");
 WiFi.mode(WIFI_STA);
 Serial.println(WIFI_SSID);
 WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

 while (WiFi.status() != WL_CONNECTED) {
   delay(500);
   Serial.print(".");
 }

 Serial.println("");
 Serial.println("INFO: WiFi connected");
 Serial.print("INFO: IP address: ");
 Serial.println(WiFi.localIP());

 // init the MQTT connection
 client.setServer(MQTT_SERVER_IP, MQTT_SERVER_PORT);
 client.setCallback(callback);
}

void loop() {
 if (!client.connected()) {
   reconnect();
 }
 client.loop();
}
