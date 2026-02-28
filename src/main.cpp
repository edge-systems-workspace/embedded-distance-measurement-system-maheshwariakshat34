#include <Arduino.h>

int trigPin = 9;
int echoPin = 10;


long duration;
long distance;

void setup() {
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    Serial.begin(9600);
}
