
// Pin definitions
const int irSensorPin = 8;  // IR sensor pin connected to D8
const int motorPWM1 = 9;   // Motor PWM pin 1
const int motorPWM2 = 10;  // Motor PWM pin 2
const int motorPWM3 = 6;   // Motor PWM pin 3
const int motorPWM4 = 11;  // Motor PWM pin 4

void setup() {
  // Set up IR sensor pin as INPUT
  pinMode(irSensorPin, INPUT);

  // Set up motor driver pins as OUTPUT
  pinMode(motorPWM1, OUTPUT);
  pinMode(motorPWM2, OUTPUT);
  pinMode(motorPWM3, OUTPUT);
  pinMode(motorPWM4, OUTPUT);
}

void loop() {
  // Read IR sensor value
  int irSensorValue = digitalRead(irSensorPin);

  // If the robot is falling (IR sensor pin is LOW)
  if (irSensorValue == 0) {
    // Rotate motors clockwise
    analogWrite(motorPWM1, 120);  // PWM value for clockwise rotation
    analogWrite(motorPWM2, 120);
    analogWrite(motorPWM3, 0);    // PWM value for anti-clockwise rotation
    analogWrite(motorPWM4, 0);
  } else {
    // If the robot is not falling, rotate motors anti-clockwise
    analogWrite(motorPWM1, 0);
    analogWrite(motorPWM2, 0);
    analogWrite(motorPWM3, 120);  // PWM value for anti-clockwise rotation
    analogWrite(motorPWM4, 120);
  }
}
