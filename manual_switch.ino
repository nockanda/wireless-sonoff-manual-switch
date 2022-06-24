#include <ESP8266WiFi.h>
#include <espnow.h>

byte board[] = {0x7C,0x87,0xCE,0xA1,0x2E,0xDF};

unsigned long t = 0;

int count = 0;

void setup() {
  // put your setup code here, to run once:

  Serial.begin(115200);
  WiFi.mode(WIFI_STA); //제일 처음 할일! 와이파이모드를 스테이션 모드로!

  //ESPNOW의 기능을 활성화한다!
  if (esp_now_init() != 0) {
    //ESP NOW 시작 실패!
    Serial.println("ESPNOW 실패!");
    return;
  }else{
     //ESP NOW 시작 성공!
     Serial.println("ESPNOW 성공!");
  }

  //지금 이보드의 역할은 주고 받는것을 다하겠다!
  esp_now_set_self_role(ESP_NOW_ROLE_COMBO);

  //나의 슬레이브를 등록해야겠다!
  esp_now_add_peer(board, ESP_NOW_ROLE_COMBO, 1, NULL, 0);//뒤에 2개는 ID, PW

  //송신완료 콜백함수 등록
  esp_now_register_send_cb(OnDataSent);

  //수신완료 콜백 함수 등록
  esp_now_register_recv_cb(OnDataRecv);

  //ESPNOW로 메시지 전송
  char c= '0';
  esp_now_send(board, (uint8_t *) &c, sizeof(c));
}

void loop() {
  // put your main code here, to run repeatedly:
  /*
  if(millis() - t > 2000){
    t = millis();
    //2초마다 한번씩 하겠다!
    esp_now_send(board11, (uint8_t *) &data, sizeof(data));
  }*/
}

//송신콜백함수 원형:
void OnDataSent(uint8_t *mac, uint8_t status) {
   //status가 0일때 송신 완료!
   if(status == 0){
      Serial.println("성공적으로 송신했음!");
      Serial.println("딥슬립하겠습니다!");
      ESP.deepSleep(0);
   }else{
      Serial.println("송신 실패!!");
      char c= '0';
      esp_now_send(board, (uint8_t *) &c, sizeof(c));
      count++;
      if(count >= 10){
        Serial.println("전송횟수를 초과해서 강제로 딥슬립하겠습니다!!");
        ESP.deepSleep(0);
      }
   }
}


//수신콜백함수 원형:
void OnDataRecv(uint8_t * mac, uint8_t * data, uint8_t len) {
  String text = "";
  for(int i = 0;i<len;i++){
    text += (char)data[i];
  }
  Serial.println(text);
}
