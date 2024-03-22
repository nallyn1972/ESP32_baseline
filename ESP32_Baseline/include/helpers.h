
#ifndef HELPERS_H
#define HELPERS_H

// I2C for Temp/Humidity sensor
#include <Wire.h>

#include <SPI.h>

#define USE_OTA 1
#define USE_MQTT 1

#if USE_OTA
#include <WiFi.h>
#include <ESPmDNS.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>


void setup_wifi_ota();
#endif // USE_OTA

#if USE_MQTT
#include <PubSubClient.h>
#endif // USE_MQTT

#endif // HELPERS_H