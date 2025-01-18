int time = 150;
int queue = 0;

const int pinLeds[] = {A0, A1, A2, A3, A4, A5};


void setup() {
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
  pinMode(A4, INPUT);
  pinMode(A5, INPUT);
}

void loop() {
  if (queue == 0) {

    for (int i = 0; i < 6; i++) {
      digitalWrite(pinLeds[i], HIGH);
      delay(time);
      digitalWrite(pinLeds[i], LOW);
    }
    queue = 1;

  } else {

    for (int i = 5; i > 0; i--) {
      digitalWrite(pinLeds[i], HIGH);
      delay(time);
      digitalWrite(pinLeds[i], LOW);
    }
    queue = 0;

  }
}
