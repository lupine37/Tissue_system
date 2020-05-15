#include <Stepper.h>

int led = 13;
int sensor = 2;
int state = LOW;
int val = 0;
int step_num = 2048;

Stepper motor(step_num, 8, 10, 9, 11);

void setup() {
  pinMode(led, OUTPUT);
  pinMode(sensor, INPUT);
  motor.setSpeed(10);
  Serial.begin(9600);

}

void loop() {
  val = digitalRead(sensor);
  if (val == HIGH) {
    digitalWrite(led, HIGH);
    motor.step(step_num);
    if (state == LOW) {
      state = HIGH;
    }
  }
  else{
    digitalWrite(led, LOW);
    motor.step(0);
    if (state == HIGH){
      state = LOW;
    }
  }

}
