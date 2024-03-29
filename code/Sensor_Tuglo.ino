#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include "ACS712.h"

ACS712 sensor(ACS712_05B, A0);
const char* ssid = "Tunas Global Nasional School";
const char* password = "Tun9102022";
const char* mqtt_server = "broker.hivemq.com";
const char* mqtt_topic = "tuglo/sd/pascal/kk1";
const unsigned long interval = 10 * 60 * 1000;  // 15 menit dalam milidetik 
unsigned long lastSent = 0;

WiFiClient espClient;
PubSubClient client(espClient);

const int numReadings = 10;  // Jumlah pembacaan sensor untuk buffer
float sensorReadings[numReadings];
int readIndex = 0;
float total = 0;
float average = 0;

void setup() {
  delay(100);
  Serial.begin(9600);
  sensor.calibrate();
  while (!Serial);

  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  client.setServer(mqtt_server, 1883);
}

void loop() {
  // Baca sensor dan tambahkan ke buffer
  sensorReadings[readIndex] = I;
  total -= sensorReadings[readIndex - numReadings];
  total += I;
  average = total / numReadings;
  if (average < 5){
    average =0;
  }
  readIndex = (readIndex + 1) % numReadings;
  unsigned long currentMillis = millis();
  
  if (currentMillis - lastSent >= interval) {
    lastSent = currentMillis;

    if (!client.connected()) {
      reconnect();
    }

    String payload = "{\"I\": " + String(average, 2) + "}";

    client.publish(mqtt_topic, payload.c_str());
    Serial.println("Output:");
    Serial.println(payload);
  }

  delay(10);
  client.loop();
}

void reconnect() {
  while (!client.connected()) {
    Serial.println("Attempting MQTT connection...");
    String clientId = "ESP8266Client-";
    clientId += String(random(0xffff), HEX);

    if (client.connect(clientId.c_str())) {
      Serial.println("connected");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      delay(5000);
    }
  }
}