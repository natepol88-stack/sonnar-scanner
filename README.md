# Sonar Scanner- https://natepolishook.com/projects/sonar-scanner

A servo-mounted ultrasonic sensor sweeps 180 degrees and drives real-time RGB LED and buzzer feedback based on live distance readings.

## Overview

An HC-SR04 ultrasonic sensor is mounted on a servo that sweeps from 0 to 180 degrees and back in a continuous loop. At every degree step the sensor fires a trigger and echo cycle, and the measured distance sets the LED color and buzzer tone for that exact angle.

Solo build: circuit design and firmware.

## Features

- Continuous 0 to 180 degree servo sweep
- One ultrasonic distance read per degree step
- Three-tier proximity feedback through an RGB LED and buzzer
- Single-microcontroller loop handling sensing, actuation, and feedback

## Feedback Tiers

| Distance | RGB LED | Buzzer |
|----------|---------|--------|
| Over 40 cm | Green | Silent |
| 10 to 40 cm | Yellow | 100 Hz tone |
| Under 10 cm | Red | 500 Hz tone |

## Hardware

- Arduino Mega
- HC-SR04 ultrasonic sensor (mounted on the servo)
- Servo motor
- RGB LED with a 220 ohm resistor on each leg
- Buzzer
- Breadboard and jumper wires

All components share a common 5V line and ground.

## How It Works

1. The servo steps one degree at a time from 0 to 180, then back to 0.
2. At each step, the Arduino sends a trigger pulse and times the returning echo.
3. Distance is calculated from the pulse duration:

   ```
   distance_cm = pulse_duration_us * 0.017
   ```

   The factor is the speed of sound (about 0.034 cm/us) divided by two, since the pulse travels to the object and back.
4. The distance is compared against the tier thresholds, and the LED and buzzer are updated before the servo moves to the next angle.

## Design Challenge: Sensor and Servo Sync

The main challenge was keeping distance readings tied to the servo's actual position. The trigger and echo cycle has to finish inside each 10 ms step of the sweep, so the LED color and buzzer tone reflect what the sensor is pointing at now, not a stale reading from the previous angle.

## Build and Run

1. Wire the circuit with all components on a shared 5V line and ground.
2. Open the sketch in the Arduino IDE.
3. Select **Arduino Mega 2560** under Tools > Board.
4. Upload, then place objects in front of the sensor at different distances.

## Results

- Continuous 0 to 180 degree sweep with a distance read at every degree step
- Three-tier LED and buzzer feedback working as specified
- Each LED leg protected by a 220 ohm resistor

## Tech

Arduino Mega, Arduino IDE (C/C++), HC-SR04, servo motor
