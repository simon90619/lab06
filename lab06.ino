#define SI 493
#define LA 440
#define SO 392
#define DO 523
#define RE 600
#define WHOLE 1 //全分符
#define HALF 0.5 //半分符
#define QUARTER 0.25
#define EIGHTH 0.125
#define SIXTEENTH 0.0625


int length ;
void setup() {
pinMode(8, OUTPUT);
length = sizeof(tune) /
sizeof(tune[0]);
}
void loop() {
// 讀取 Keypad 的輸入
  char key = keypad.getKey();
  
  // NO_KEY 代表沒有按鍵被按下
  if (key != NO_KEY){      // 假如有按鍵被按下，就印出按鍵對應的字元
      switch (key) {
     case '1':    
       tone(4, SI, duration);
       break;
     case '2':    
       tone(4, LA, duration);
       break;
     case '3':    
       tone(4, SO, duration);
       break;
     case '4':    
       tone(4, DO, duration);
       break;
     case '5':    
       tone(4, RE, duration);
       break;
    
     }
    Serial.println(key);
  }
}
