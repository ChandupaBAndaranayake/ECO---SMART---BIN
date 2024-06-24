# IoT Dustbin Project

This project integrates an IoT-enabled dustbin system using Arduino-compatible boards, sensors, and the Blynk platform for remote monitoring and control.

## Table of Contents
- [Overview](#overview)
- [Features](#features)
- [Hardware Requirements](#hardware-requirements)
- [Software Requirements](#software-requirements)
- [Setup Instructions](#setup-instructions)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)

## Overview
This project combines sensor data monitoring and servo motor control to create an IoT-based dustbin system. It includes features such as:
- Monitoring alcohol levels using an MQ2 sensor.
- Measuring distance using a sonar sensor.
- Automatically opening the dustbin lid based on proximity detected by an ultrasonic sensor.
- Integration with the Blynk IoT platform for remote monitoring and control.

## Features
- Real-time monitoring of alcohol levels and distance measurements.
- Automatic lid opening/closing based on the presence of objects within a specified range.
- Remote access and control through the Blynk mobile app or web dashboard.

## Hardware Requirements
- ESP8266 or Arduino board (e.g., NodeMCU, Arduino Uno).
- MQ2 gas sensor.
- Ultrasonic distance sensor (HC-SR04 or similar).
- Servo motor.
- Resistors and connecting wires.
- Power supply (USB or external power adapter).

## Software Requirements
- Arduino IDE ([Download](https://www.arduino.cc/en/software)).
- Blynk IoT platform account ([Sign up](https://blynk.io)).

## Setup Instructions
1. **Clone the Repository**:
   ```bash
   git clone https://github.com/YourUsername/YourRepository.git
