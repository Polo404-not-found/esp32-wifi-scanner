#include <arduino.h>
#include <WiFi.h>

void setup(){
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(2000);
  Serial.printf(" \
                                                                                 \n \
                                                                                \n \
                                                                                \n \
  ██████                                                     ████               \n \
  ██████     ██                                              ████               \n \
    ██       ██                                                ██               \n \
    ██     ███████    ▒█████░            ██░███▒    ░████░     ██       ░████░  \n \
    ██     ███████   ████████            ███████▒  ░██████░    ██      ░██████░ \n \
    ██       ██      ██▒  ░▒█            ███  ███  ███  ███    ██      ███  ███ \n \
    ██       ██      █████▓░             ██░  ░██  ██░  ░██    ██      ██░  ░██ \n \
    ██       ██      ░██████▒            ██    ██  ██    ██    ██      ██    ██ \n \
    ██       ██         ░▒▓██            ██░  ░██  ██░  ░██    ██      ██░  ░██ \n \
    ██       ██░     █▒░  ▒██            ███  ███  ███  ███    ██▒     ███  ███ \n \
  ██████     █████   ████████            ███████▒  ░██████░    █████   ░██████░ \n \
  ██████     ░████   ░▓████▓             ██░███▒    ░████░     ░████    ░████░  \n \
                                         ██                                     \n \
                                         ██                                     \n \
                                         ██                                     \n \
                              ██████████                                        \n  ");
}

void loop(){
  Serial.println();
  Serial.println("Scanning spectrum for WiFi networks...");
  int internet = WiFi.scanNetworks();
  
  if (internet == 0) {
    Serial.println("No networks found");
  } else {
    Serial.printf("Found %d networks: \n", internet);
    for (int i = 0; i < internet; ++i) {
      String ssid = WiFi.SSID(i);
      int32_t rssi = WiFi.RSSI(i);
      wifi_auth_mode_t encryption = WiFi.encryptionType(i);
      Serial.printf(" [%2d] SSID: %-25s | Signal: %3d dBm | Security: ", i + 1, ssid.c_str(), rssi);
      switch (encryption) {
        case WIFI_AUTH_OPEN:
          Serial.println("Open");
          break;
        case WIFI_AUTH_WEP:
          Serial.println("WEP");
          break;
        case WIFI_AUTH_WPA_PSK:
          Serial.println("WPA_PSK");
          break;
        case WIFI_AUTH_WPA2_PSK:
          Serial.println("WPA2_PSK");
          break;  
        case WIFI_AUTH_WPA_WPA2_PSK:
          Serial.println("WPA/WPA2_PSK");
          break;
        case WIFI_AUTH_WPA3_PSK:
          Serial.println("WPA3_PSK");
          break;
      }
    }
  }
}