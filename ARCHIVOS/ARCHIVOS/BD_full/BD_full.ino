#include <ESP8266WiFi.h>
#include <PubSubClient.h>
const char* ssid = "Colocar SSID";
const char* password = "Colocar Password";
const char* mqtt_server = "broker.hivemq.com";
const int mqtt_port = 1883;
const char* topic = "agregar tu topico";
WiFiClient espClient;
PubSubClient client(espClient);
void setup_wifi() {
 delay(10);
 WiFi.begin(ssid, password);
 while (WiFi.status() != WL_CONNECTED) {
 delay(500);
 }
}
void reconnect() {
 while (!client.connected()) {
 if (!client.connect("NodeMCU_Client")) {
 delay(5000);
 }
 }
}
void setup() {
 Serial.begin(115200);
 setup_wifi();
 client.setServer(mqtt_server, mqtt_port);
}
void loop() {
 if (!client.connected()) {
 reconnect();
 }
 client.loop();
 float temperatura = random(20, 30);
 String mensaje = "Temperatura: " + String(temperatura) + " °C";
 client.publish(topic, mensaje.c_str());
 delay(5000);
}