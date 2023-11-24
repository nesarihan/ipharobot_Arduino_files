#include "Motor.h"
Motor motor1(12,12);
int Motor::counts_per_rev_ = 0;
long ticks = 0;

void setup() {
  Serial.begin(9600);
//  Motor::initEncoder(10);
}

void loop() {
  motor1.updateSpeed(ticks);
  Serial.println(motor1.current_rpm);
  ticks = ticks + 20;
  delay(1000);
  
}