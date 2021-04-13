#include <CayenneMQTTESP8266.h>
#define CAYENNE_DEBUG
#define CAYENNE_PRINT Serial
char ssid[] = "MEKANUS.";
char password[]="robotica10";
char username[] = "8818a890-9c56-11eb-883c-638d8ce4c23d";
char mqtt_password[] = "f31767ef1fc320597a5f71f3d5feaeea2238f325";
char cliend_id[] = "2c582650-9c85-11eb-a2e4-b32ea624e442";

void setup() {
  Serial.begin(9600);
  Cayenne.begin(username, mqtt_password, cliend_id, ssid, password);
  pinMode(0, OUTPUT);
  digitalWrite(0, HIGH);
  pinMode(2, OUTPUT);
  digitalWrite(2, HIGH);
}

void loop() {
  Cayenne.loop();
}

CAYENNE_IN(0){
  digitalWrite(0, !getValue.asInt()); 
}
CAYENNE_IN(2){
  digitalWrite(2, !getValue.asInt()); 
}
