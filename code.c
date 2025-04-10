/* 
 * Created by Linh Huynh
 * Created on April 2025
 * 
*/

# include <Servo.h>


const int TRIG_PIN = 9;  
const int ECHO_PIN = 8;
const float SPEED_OF_LIGHT = 0.0343;
const int DISTANCE_TWIST = 50;

float duration;
float distance;

Servo servoNumber1;

void setup() {
    servoNumber1.attach(10);
    servoNumber1.write(0);
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
    Serial.begin(9600);

}

void loop() {
    servoNumber1.write(0);
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);

    duration = pulseIn(ECHO_PIN, HIGH);
    distance = (duration * SPEED_OF_LIGHT) / 2;
    Serial.print(distance);
    Serial.println(distance);
  
    if (distance < DISTANCE_TWIST) 
    {
      servoNumber1.write(90);
      delay(1000);
      servoNumber1.write(0);
      delay(1000);
    }
}
