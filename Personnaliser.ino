struct PinLeds {
  int portPin;
  int triggers[10];
  int numTriggers;
};

int time = 150;

PinLeds model[] = {
  { A0, { 1, 2, 3, 7 }, 4 },
  { A1, { 1, 2, 3, 6 }, 4 },
  { A2, { 1, 2, 3, 5 }, 4 },
  { A3, { 1, 2, 3, 4 }, 4 }
};

const int MaxQueue = 10;

void leds(PinLeds model[], int numPins);

void setup() {
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
  pinMode(A4, OUTPUT);
  pinMode(A5, OUTPUT);
}

void loop() {
  leds(model, sizeof(model) / sizeof(model[0]));
}

void leds(PinLeds pinLeds[], int numPins) {
  for (int trigger = 1; trigger <= MaxQueue; trigger++) {

    for (int i = 0; i < numPins; i++) {
      for (int j = 0; j < pinLeds[i].numTriggers; j++) {
        if (pinLeds[i].triggers[j] == trigger) {
          digitalWrite(pinLeds[i].portPin, HIGH);
        }
      }
    }

    delay(time);

    for (int i = 0; i < numPins; i++) {
      for (int j = 0; j < pinLeds[i].numTriggers; j++) {
        if (pinLeds[i].triggers[j] == trigger) {
          digitalWrite(pinLeds[i].portPin, LOW);
        }
      }
    }

    delay(time);
  }
}
