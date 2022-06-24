#include <ESP8266WiFi.h>
#include <espnow.h>

typedef void (*esp_rc_cb_t)();

esp_rc_cb_t on_callback;
esp_rc_cb_t off_callback;

void OnDataRecv(uint8_t * mac, uint8_t * data, uint8_t len) {
  #ifdef ESP_LOGD
        ESP_LOGD("nockanda", "received: %c\n", data[0]);
  #endif
  if(data[0] == '0'){
     off_callback();
  }else if(data[0] == '1'){
     on_callback();
  }
}

class {
public:
    void begin() {
        WiFi.mode(WIFI_STA);  
        if (esp_now_init() == 0) {
            esp_now_set_self_role(ESP_NOW_ROLE_COMBO);
            esp_now_register_recv_cb(OnDataRecv);
        }
    }
    void turn_on(esp_rc_cb_t callback) {
        on_callback = callback;
    }
    void turn_off(esp_rc_cb_t callback) {
        off_callback = callback;
    }
} NOCKANDA_ESPNOW;
