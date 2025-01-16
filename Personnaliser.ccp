struct PinLeds {
  int portPin;
  int triggers[10];
  int numTriggers;
};

int time = 150;

PinLeds pinLeds1[] = {
  { A0, { 1, 2, 3, 7 }, 4 },
  { A1, { 1, 2, 3, 6 }, 4 },
  { A2, { 1, 2, 3, 5 }, 4 },
  { A3, { 1, 2, 3, 4 }, 4 }
};

PinLeds pinLeds2[] = {
  { A0, { 1, 3, 6 }, 3 },
  { A1, { 2, 4, 5 }, 3 },
  { A2, { 1, 3, 5 }, 3 },
  { A3, { 2, 4, 6 }, 3 }
};

const int MaxQueue = 10;

void leds(PinLeds pinLeds[], int numPins);

void setup() {

  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);

  /*pinMode(A4, INPUT);
  pinMode(A5, INPUT);*/
}

void loop() {

  leds(pinLeds1, sizeof(pinLeds1) / sizeof(pinLeds1[0]));


  /*int stateA4 = digitalRead(A4);
  int stateA5 = digitalRead(A5);
  
  if (stateA5 == LOW && stateA4 == LOW) {
    digitalWrite(A0, HIGH);
    digitalWrite(A1, HIGH);
    digitalWrite(A2, HIGH);
    digitalWrite(A3, HIGH);
  }
  if (stateA4 == HIGH) {
    leds(pinLeds1, sizeof(pinLeds1) / sizeof(pinLeds1[0]));
  }*/
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
