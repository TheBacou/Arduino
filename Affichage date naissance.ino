struct PinLeds {
  int triggers[9];
};

PinLeds list[] = {
  { A0, A1, A3, 2, 3, 5 },        // 0
  { 3, 5 },                       // 1
  { A0, A3, 2, 5, 4 },            // 2
  { A0, 2, 3, 5, 4 },             // 3
  { 3, 4, A1, 5 },                // 4
  { A0, A1, 3, 4, 2 },            // 5
  { A0, 2, 4, 3, A1, A3 },        // 6
  { A0, 3, 5 },                   // 7
  { A0, A1, A3, 2, 3, 5, 4 },     // 8
  { A0, A1, 2, 3, 5, 4 }          // 9
};

const int ports[] = { A0, A1, A2, A3, 2, 3, 4, 5 };
const int date[] = { 0, 9, ".", 1, 0, ".", 2, 0, 0, 5 };

int time_delay = 1000;

void loadPin() {
  for (int P = 0; P < sizeof(ports); P++) {
    pinMode(ports[P], INPUT);
  }
}

void setup() {
  Serial.begin(9600);
  loadPin();
}

void loop() {
  for (int i = 0; i < 11; i++) {
    if (i == 10) {
      delay(1000);
      for (int i = 0; i <= 5; i++) {
        for (int e = 0; e <= sizeof(ports); e++) {
          pinMode(ports[e], OUTPUT);
          digitalWrite(ports[e], LOW);
        }
        delay(200);
        loadPin();
        delay(200);
      }
    }
    if (date[i] == ".") {
      pinMode(A2, OUTPUT);
      digitalWrite(A2, LOW);
    } else {
      for (int e = 0; e < sizeof(list[date[i]].triggers) / sizeof(list[date[i]].triggers[0]); e++) {
        if (i < 9 && i > 0 && date[i-1] == date[i]) {
          pinMode(A2, OUTPUT);
          digitalWrite(A2, LOW);
        }
        pinMode(list[date[i]].triggers[e], OUTPUT);
        digitalWrite(list[date[i]].triggers[e], LOW);
      }
    }
    delay(time_delay);
    loadPin();
  }
}
