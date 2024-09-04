#include <Servo.h>

Servo tap_servo;

int sensor_pin = 4;
int tap_servo_pin = 5;
int val;

const int buzzer = 9;

void setup() {
  pinMode(sensor_pin, INPUT);
  tap_servo.attach(tap_servo_pin);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  val = digitalRead(sensor_pin);

  if (val == 0) {
    tap_servo.write(0);
    tone(buzzer, 1000);
    delay(1000);
    noTone(buzzer);
    delay(10000);
  }
  
  if (val == 1) {
    tap_servo.write(180);
    delay(1000);
  }
}

