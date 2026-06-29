#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <DabbleESP32.h>
#include <ESP32Servo.h>

#define IN1 25
#define IN4 26
#define SERVO_PIN 15

Servo steering;

void setup() {
  Serial.begin(115200);
  Dabble.begin("ROMY");

  steering.attach(SERVO_PIN);
  steering.write(90);

  pinMode(IN1, OUTPUT);
  pinMode(IN4, OUTPUT);

  berhenti();
}

void loop() {
  Dabble.processInput();

  if (GamePad.isCrossPressed()) {
    maju();
  } else if (GamePad.isTrianglePressed()) {
    mundur();
  } else {
    berhenti();
  }

  int steerAngle = 90;

  if (GamePad.isLeftPressed()) {
    steerAngle = 60;
  } else if (GamePad.isRightPressed()) {
    steerAngle = 115;
  }

  steering.write(steerAngle);
}

void maju() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN4, LOW);
}

void mundur() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN4, HIGH);
}

void berhenti() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN4, LOW);
}
