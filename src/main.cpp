#include <Arduino.h>

/**
 * @file main.cpp
 * @brief Embedded RGB LED Control (Digital + PWM)
 * @author shre-coder638
 * @date 2026-02-17
 *
 * @details
 * Controls an RGB LED using digital ON/OFF and analog PWM brightness control.
 * Demonstrates simple digital blink and PWM color cycling on three pins.
 */

const uint8_t RED_pin = 9;
const uint8_t GREEN_pin = 10;
const uint8_t BLUE_pin = 11;

/**
 * @brief Initialize serial communication and configure LED pins.
 *
 * @details
 * Starts the hardware Serial at 9600 baud and sets the RGB pins as OUTPUT.
 * Prints an initialization message to the serial console.
 *
 * @return void
 */
void setup() {
    Serial.begin(9600);

    pinMode(RED_pin, OUTPUT);
    pinMode(GREEN_pin, OUTPUT);
    pinMode(BLUE_pin, OUTPUT);

    Serial.println("RGB LED Initialized!");
}

/**
 * @brief Run the LED demo loop: digital blink and PWM color cycle.
 *
 * @details
 * First toggles the red LED using digitalWrite with 1 second intervals.
 * Then cycles full-brightness red, green, and blue using analogWrite (PWM),
 * each shown for 1 second. A short pause separates cycles.
 *
 * @return void
 */
void loop() {
    // -------- DIGITAL MODE --------
    digitalWrite(RED_pin, HIGH);
    delay(1000);

    digitalWrite(RED_pin, LOW);
    delay(1000);

    // -------- ANALOG (PWM) MODE --------
    analogWrite(RED_pin, 255);   // Full brightness
    analogWrite(GREEN_pin, 0);
    analogWrite(BLUE_pin, 0);
    delay(1000);

    analogWrite(RED_pin, 0);
    analogWrite(GREEN_pin, 255);
    analogWrite(BLUE_pin, 0);
    delay(1000);

    analogWrite(RED_pin, 0);
    analogWrite(GREEN_pin, 0);
    analogWrite(BLUE_pin, 255);
    delay(1000);

    delay(500);
}
