# 6-DOF Gesture-Controlled Robotic Arm

## 🚀 Project Overview
This repository contains the hardware design, firmware, and software stack for a 6-degree-of-freedom (6-DOF) robotic arm. Developed as part of the TA212 course at IIT Kanpur, the system utilizes a computer vision interface to achieve intuitive, contactless, gesture-based control. The project demonstrates real-time kinematic mapping, translating human hand movements into precise mechanical actuation.

## ✨ Key Features
* **Real-Time Hand Tracking:** Utilizes MediaPipe and OpenCV to map 21 distinct hand landmarks in real-time.
* **Kinematic Translation:** Maps complex spatial hand gestures to specific servo constraints.
* **Motion Smoothing:** Implements a mathematical smoothing filter (`New Angle = 0.7 * Previous Angle + 0.3 * Current Angle`) to eliminate servo jitter and prevent jerky actuation.
* **Lightweight Architecture:** Custom 21-part mechanical assembly optimized for a high strength-to-weight ratio.

## 🛠️ Hardware Specifications
The mechanical assembly is designed for fluid motion and structural stability.

* **Structural Components:** Robust foundation utilizing ACP base plates, 3D-printed PLA arms, and a high-density metal shaft.
* **Actuation:** * 3x MG996R servos (Heavy base/shoulder movements)
  * 3x SG90 servos (Wrist/gripper manipulation)
* **Control Electronics:** Arduino Uno paired with a PCA9685 servo driver for stable, multi-channel PWM control at 50 Hz.
* **Performance:** Maximum payload capacity of 120-150 grams at the shoulder joint.

## 💻 Software Architecture
The control pipeline operates across a split Python/C++ stack:

1. **Vision & Logic (Python):** Captures webcam feeds and processes spatial data. 
2. **Gesture Mapping:** * **Base:** Left/Right hand translation.
   * **Shoulder:** Up/Down wrist translation.
   * **Elbow:** Depth scaling (distance between wrist and index finger).
   * **Claw/Gripper:** Automated clamping triggered by fist detection.
3. **Serial Communication:** Formats and transmits calculated angles to the microcontroller via USB at a 115200 baud rate.
4. **Hardware Execution (C++):** The Arduino firmware parses incoming serial packets, applies the smoothing algorithm, and drives the PCA9685.

## 🔌 Circuit & Wiring Reference

**PCA9685 to Arduino Uno:**
* `VCC` → `5V` | `GND` → `GND` | `SDA` → `A4` | `SCL` → `A5`

**Servos to PCA9685 Channels:**
* `CH-0`: Base | `CH-1`: Shoulder | `CH-2`: Elbow 
* `CH-3`: Wrist Pitch | `CH-4`: Wrist Roll | `CH-5`: Claw

## ⚙️ How to Run

### 1. Prerequisites
Ensure you have Python installed, then install the required dependencies:
`pip install opencv-python mediapipe pyserial`

### 2. Flash the Firmware
1. Open the `Code/Arduino_Firmware/servo_driver.ino` file in the Arduino IDE.
2. Install the **Adafruit PWM Servo Driver Library** via the Library Manager.
3. Connect your Arduino Uno and upload the code.

### 3. Launch the Interface
1. Ensure your webcam is connected.
2. Update the `SERIAL_PORT` variable in the Python script to match your Arduino's COM port.
3. Run the script:
`python Code/Computer_Vision/gesture_control.py`
