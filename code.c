/* 
 * Created by Linh Huynh
 * Created on April 2025
 * 
*/

# include <Servo.h>


const int TRIG_PIN = 8;  
const int ECHO_PIN = 9; 
const int DISTNACE_TO_START =  20;
const int CONVERSION_METRIC = 0.0343;

const float DISTANCE;
const float DURATION;

Servo servoNumber1;

void setup() {
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
    Serial.begin(9600);
    servoNumber1.attach(10);
    servoNumber1.write(0);
}

void loop() {
    servoNumber1.write(0);
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);

    DURATION = pulseIn(ECHO_PIN, HIGH);
    DISTANCE = (DURATION * CONVERSION_METRIC) / 2;
    Serial.print("Distance: ");
    Serial.println(DISTANCE);
    delay(100);
  
    if (DISTANCE < DISTANCE_TO_START) {
      servoNumber1.write(0);
      delay(1000);
      servoNumber1.write(90);
      delay(1000);
	    }
}
