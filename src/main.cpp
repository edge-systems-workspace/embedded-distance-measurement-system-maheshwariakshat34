/**
 * @file main.cpp
 * @brief Ultrasonic Distance Measurement System using HC-SR04 sensor
 *
 * This program interfaces with an HC-SR04 ultrasonic distance sensor to measure
 * the distance of objects in centimeters. The sensor uses a trigger pin to send
 * ultrasonic waves and an echo pin to receive the reflected signal. The distance
 * is calculated based on the time it takes for the signal to return.
 *
 * @author Akshat Maheshwari
 * @date February 28, 2026
 *
 * @details
 * The HC-SR04 sensor works by:
 * - Sending a 10 microsecond pulse on the trigger pin
 * - Measuring the duration of the high pulse on the echo pin
 * - Calculating distance using the formula: distance = (duration * 0.0343) / 2
 *   where 0.0343 cm/microsecond is the speed of sound in air
 */

#include <Arduino.h>

/** @brief Pin connected to the trigger pin of the HC-SR04 sensor */
int trigPin = 9;

/** @brief Pin connected to the echo pin of the HC-SR04 sensor */
int echoPin = 10;

/** @brief Duration of the echo pulse in microseconds */
long duration;

/** @brief Calculated distance to the object in centimeters */
long distance;


/**
 * @brief Initializes the ultrasonic sensor pins and serial communication
 *
 * Sets up the trigger pin as an output and the echo pin as an input.
 * Also initializes serial communication at 9600 baud rate for debugging and
 * distance output.
 *
 * @return void
 */
void setup() {
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    Serial.begin(9600);
}

/**
 * @brief Main program loop that continuously measures distance
 *
 * This function repeatedly triggers the HC-SR04 sensor, measures the echo pulse duration,
 * calculates the distance based on the pulse duration, and outputs the result via serial.
 *
 * @details
 * Process:
 * -# Sets trigger pin LOW for 2 microseconds to ensure a clean trigger
 * -# Sends a 10 microsecond pulse on the trigger pin to activate the sensor
 * -# Measures the duration of the HIGH pulse on the echo pin using pulseIn()
 * -# Calculates distance in centimeters: (duration * 0.0343) / 2
 * -# Prints the distance value to the serial monitor
 * -# Waits 500 milliseconds before the next measurement
 *
 * @note The speed of sound is approximately 0.0343 cm/microsecond (or 343 m/s).
 *       The distance is divided by 2 because the sound travels to the object
 *       and back to the sensor.
 *
 * @return void
 */
void loop() {

    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);

    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);

    digitalWrite(trigPin, LOW);

    duration = pulseIn(echoPin, HIGH);
    distance = (duration * 0.0343) / 2;

    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");

    delay(500);
}