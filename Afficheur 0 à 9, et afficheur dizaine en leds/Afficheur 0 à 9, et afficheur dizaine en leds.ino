struct PinLeds {
  int triggers[9];
};

PinLeds list[] = {
  { 53, 51, 47, 31, 33, 39 },    // 0
  { 33, 39 },                    // 1
  { 53, 47, 31, 39, 37 },        // 2
  { 53, 31, 33, 39, 37 },        // 3
  { 33, 37, 51, 39 },            // 4
  { 53, 51, 33, 37, 31 },        // 5
  { 53, 31, 37, 33, 51, 47 },    // 6
  { 53, 33, 39 },                // 7
  { 53, 51, 47, 31, 33, 39, 37 },// 8
  { 53, 51, 31, 33, 39, 37 }     // 9
};

const int port_dizaine[] = {52, 50, 48, 46, 30, 28, 26, 24, 22};
int dizaine = 0;

int time_delay = 250;

void loadPin() {
  for (int port = 22; port <= 53; port++) {
    pinMode(port, INPUT);
  }
}

void setup() {
  Serial.begin(9600);
  loadPin();
}

void loop() {
  for (int l = 0; l < sizeof(list) / sizeof(list[0]); l++) {
    if (dizaine > 0) {
      for (int e = 0; e < dizaine; e++) {
        pinMode(port_dizaine[e], OUTPUT);
        digitalWrite(port_dizaine[e], LOW);
      }
    }

    
    if (dizaine < 10) {
      for (int i = 0; i < sizeof(list[l].triggers) / sizeof(list[l].triggers[0]); i++) {
        pinMode(list[l].triggers[i], OUTPUT);
        digitalWrite(list[l].triggers[i], LOW);
      }

      if (l == 9) {
        dizaine++;
        if (dizaine == 10) {
          while (true);
        }
      }

      delay(time_delay);
      loadPin();
    }
  }
}
