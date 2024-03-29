#include <Arduino.h>
#include "helpers.h"

std::string bp_version = "0.0.1";

void setup()
{
  Serial.begin(115200); /* prepare for possible serial debug */

#if USE_OTA
  setup_wifi_ota();
#endif

  Serial.println("Setup done");
  Serial.printf("%d, %d, %d", (1 << 1), 1 << 2, 1 << 3);
  Serial.println();
}

/* Main execution loop */
void loop()
{
#if USE_OTA
  // OTA Handler --- cannot be blocked. No delay or long running code.
  ArduinoOTA.handle();
#endif
}

// #if USE_OTA
// void setup_wifi_ota()
// {

//   Serial.println("Booting");
//   WiFi.mode(WIFI_STA);
//   WiFi.begin(ssid, pass);
//   while (WiFi.waitForConnectResult() != WL_CONNECTED)
//   {
//     Serial.println("Connection Failed! Rebooting...");
//     delay(5000);
//     ESP.restart();
//   }

//   ArduinoOTA
//       .onStart([](){
//       String type;
//       if (ArduinoOTA.getCommand() == U_FLASH)
//         type = "sketch";
//       else // U_SPIFFS
//         type = "filesystem";

//       // NOTE: if updating SPIFFS this would be the place to unmount SPIFFS using SPIFFS.end()
//       Serial.println("Start updating " + type); })
//       .onEnd([]()
//              { Serial.println("\nEnd"); })
//       .onProgress([](unsigned int progress, unsigned int total)
//                   { Serial.printf("Progress: %u%%\r", (progress / (total / 100))); })
//       .onError([](ota_error_t error)
//                {
//       Serial.printf("Error[%u]: ", error);
//       if (error == OTA_AUTH_ERROR) Serial.println("Auth Failed");
//       else if (error == OTA_BEGIN_ERROR) Serial.println("Begin Failed");
//       else if (error == OTA_CONNECT_ERROR) Serial.println("Connect Failed");
//       else if (error == OTA_RECEIVE_ERROR) Serial.println("Receive Failed");
//       else if (error == OTA_END_ERROR) Serial.println("End Failed"); });

//   ArduinoOTA.begin();

//   Serial.println("Ready");
//   Serial.print("IP address: ");
//   myIp = WiFi.localIP();
//   Serial.println(myIp);
// }
// #endif