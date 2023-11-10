/*
Código exemplo demonstrando o funcionamento do Sensor DHT11 enviando 
informações via serial no formato JSON para o servidor node-Red que recebe e transmite via protocolo MQTT 
*/

/////Json
#include <ArduinoJson.h>
const int TAMANHO = 50;

///// Sensor DHT
#include "DHT.h"
#define DHTPIN  7
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

///// Fotoressistor
const int LDR = A0;

#define led 13

void setup() 
{
  dht.begin();

  Serial.begin(9600);

  pinMode(led, OUTPUT);
  pinMode(LDR, INPUT);
}

void loop() 
{
  StaticJsonDocument<TAMANHO> json;

  float temp = dht.readTemperature();
  float umi = dht.readHumidity();
  float lumi = analogRead(LDR);

  json["temperatura"] = temp;
  json["umidade"] = umi;
  json["luminosidade"] = lumi;

  serializeJson(json, Serial);
  
  Serial.println();

  if (Serial.available() > 0) {
    StaticJsonDocument<TAMANHO> json;
    deserializeJson(json, Serial);
    if(json.containsKey("led")) {
      digitalWrite(led, HIGH);
      delay(500);
      digitalWrite(led, LOW);
    }
  }

  delay(500);
}