/**/
#if defined(ESP8266)
  #include <ESP8266WiFi.h>        
#else //def ESP32
  #include <WiFi.h>
#endif
#include <PubSubClient.h>
#include <IRremoteESP8266.h>
#include <IRsend.h>
#include "configuration.h"
#include "data.h"

WiFiClient wifiClient;
PubSubClient client(wifiClient);
IRsend irsend(kIrLed);

void setup() {
  Serial.begin(115200);
  pinMode(ledBuilt,OUTPUT);
  digitalWrite(ledBuilt,HIGH);
  irsend.begin();
    
  // init WiFi
  Serial.println();
  Serial.println();
  Serial.print("Connectant a ");
  WiFi.mode(WIFI_STA);
  Serial.println(WIFI_SSID);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  
  while (WiFi.status() != WL_CONNECTED) {
   delay(500);
   Serial.print("."); }
  
  Serial.println("");
  Serial.println("WiFi OK");
  Serial.print("IP: ");
  Serial.println(WiFi.localIP());
  
  // init MQTT
  client.setServer(MQTT_SERVER_IP, MQTT_SERVER_PORT);
  client.setCallback(callback);
}

void loop() {
  if (!client.connected()) { reconnect(); }
  client.loop();
}

void reconnect() {
  // Loop fins connexio
  while (!client.connected()) {
   Serial.print("Intentant MQTT...");
   if (client.connect(MQTT_CLIENT_ID, MQTT_USER, MQTT_PASSWORD)) {
     Serial.println("OK");
     client.subscribe(MQTT_IN_TOPIC); } 
   else {
     Serial.print("ERROR = ");
     Serial.print(client.state());
     Serial.println("Reintentant en 5s");
     delay(5000); }
  }
}

void callback(char* p_topic, byte* p_payload, unsigned int p_length) {
 // Byte to String
 String payload;
 for (uint8_t i = 0; i < p_length; i++) {
   payload.concat((char)p_payload[i]); }
  Serial.print("Rebut: "); Serial.println(payload);
  if (payload == "POWER") { irsend.sendNEC(0x20DF10EF, 32);}
  else if (payload == "VOLUP") { irsend.sendNEC(0x20DF40BF , 32);}
  else if (payload == "VOLDWN") { irsend.sendNEC(0x20DFC03F , 32);}
}
