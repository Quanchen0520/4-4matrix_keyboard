const byte rowPins[] = {22, 23, 24, 25}; // 設置行引腳位
const byte colPins[] = {26, 27, 28, 29}; // 設置列引腳位
const byte BuzzerPin = 30; // 設置蜂鳴器引腳位

char Keys[4][4] = {
  {'1', '4', '7', '*'},
  {'2', '5', '8', '0'},
  {'3', '6', '9', '#'},
  {'A', 'B', 'C', 'D'}
};

void setup() {
  // 腳位狀態設定
  for (int i = 0; i <= 3; i++) {
    pinMode(rowPins[i], OUTPUT);
    digitalWrite(rowPins[i], HIGH);
    pinMode(colPins[i], INPUT);
  }
  pinMode(BuzzerPin, OUTPUT);
  Serial.begin(9600); // 鮑率設定
}

void loop() {
  for (int r = 0; r <= 3; r++) {
    digitalWrite(rowPins[r], LOW);
    for (int c = 0; c <= 3; c++) {
      if (digitalRead(colPins[c]) == LOW) {
        delay(20);
        Serial.println(Keys[r][c]);
        analogWrite(BuzzerPin, 128); // 在此設置 PWM 佔空比（0 到 255）
        delay(50);
        analogWrite(BuzzerPin, 0); // 停止聲音
        while (digitalRead(colPins[c]) == LOW) delay(1);
        delay(20);
      }
    }
    digitalWrite(rowPins[r], HIGH);
  }
}
