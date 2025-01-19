struct PinLeds {
  int triggers[9];
};

PinLeds list[] = {
  { A0, A1, A3, 2, 3, 5 },    // 0
  { 3, 5 },                    // 1
  { A0, A3, 2, 5, 4 },        // 2
  { A0, 2, 3, 5, 4 },        // 3
  { 3, 4, A1, 5 },            // 4
  { A0, A1, 3, 4, 2 },        // 5
  { A0, 2, 4, 3, A1, A3 },    // 6
  { A0, 3, 5 },                // 7
  { A0, A1, A3, 2, 3, 5, 4 },// 8
  { A0, A1, 2, 3, 5, 4 }     // 9
};

const int ports[] = { A0, A1, A2, A3, 2, 3, 4, 5, 6 };
int full = 0;

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
  for (int l = 0; l < sizeof(list) / sizeof(list[0]); l++) {
        
    if (full != 1) {
      for (int i = 0; i < sizeof(list[l].triggers) / sizeof(list[l].triggers[0]); i++) {
        pinMode(list[l].triggers[i], OUTPUT);
        digitalWrite(list[l].triggers[i], LOW);
      }

      if (l == 9) {
        full++;
      }

      delay(time_delay);
      loadPin();
    } else {
      for (int i = 0; i < sizeof(list[9].triggers) / sizeof(list[9].triggers[0]); i++) {
        pinMode(list[9].triggers[i], OUTPUT);
        digitalWrite(list[9].triggers[i], LOW);
      }
    }
  }
}
