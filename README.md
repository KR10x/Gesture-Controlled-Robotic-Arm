# 6-DOF Gesture-Controlled Robotic Arm

## 🚀 Project Overview
[cite_start]This project features an advanced 6-degree-of-freedom (6-DOF) robotic arm that utilizes a computer vision interface for intuitive, contactless gesture-based control[cite: 14, 15]. [cite_start]Developed as part of the TA212 course, the system tracks hand movements in real-time and mirrors them through the mechanical assembly[cite: 2, 1140]. 

## 🛠️ Hardware Specifications
[cite_start]The mechanical assembly consists of 21 distinct manufactured parts, optimized for lightweight operation[cite: 16, 77]. 

* [cite_start]**Structural Components:** Built using a robust foundation of ACP base plates, 3D printed PLA arms, and a high-density metal shaft for stability[cite: 16, 49, 1243].
* [cite_start]**Actuation:** Driven by 3x MG996R servo motors (for heavy base/shoulder movements) and 3x SG90 servo motors (for wrist/gripper movements)[cite: 49].
* [cite_start]**Control Electronics:** An Arduino Uno handles the logic, paired with a PCA9685 servo driver ensuring stable multi-servo PWM control at 50 Hz[cite: 72, 73].
* [cite_start]**Performance:** The maximum payload is limited by the shoulder joint to approximately 120-150 grams[cite: 70].

## 💻 Software & Control Pipeline
[cite_start]The software stack is split into two main components: a Python-based computer vision script and C++ Arduino firmware[cite: 959, 960, 1081].

1. [cite_start]**Hand Tracking (Python):** Uses OpenCV to capture webcam video and MediaPipe to detect 21 specific hand landmarks[cite: 1146, 1147].
2. [cite_start]**Kinematic Mapping:** Hand movements are translated into 6 distinct servo angles[cite: 1183]. For example:
   * [cite_start]Left/Right hand movement controls the **Base**[cite: 1186].
   * [cite_start]Up/Down wrist movement controls the **Shoulder**[cite: 1189].
   * [cite_start]Fist detection automatically closes the **Claw/Gripper**[cite: 1178, 1180].
3. [cite_start]**Serial Communication:** The calculated angles are sent as a comma-separated string to the Arduino via USB at a 115200 baud rate[cite: 968, 1204, 1206].
4. [cite_start]**Motion Smoothing:** To prevent jerky, sudden movements, a mathematical smoothing filter (`New Angle = 0.7 * Previous Angle + 0.3 * Current Angle`) is applied[cite: 1200, 1201, 1202].

## 🔌 Circuit & Wiring
* **PCA9685 to Arduino Uno:**
  * [cite_start]VCC → 5V [cite: 944]
  * [cite_start]GND → GND [cite: 945]
  * [cite_start]SDA → A4 [cite: 947]
  * [cite_start]SCL → A5 [cite: 948]
* **Servos to PCA9685:**
  * [cite_start]CH-0: Base [cite: 950]
  * [cite_start]CH-1: Shoulder [cite: 951, 952]
  * [cite_start]CH-2: Elbow [cite: 953]
  * [cite_start]CH-3: Wrist Pitch [cite: 954]
  * [cite_start]CH-4: Wrist Roll [cite: 955]
  * [cite_start]CH-5: Claw [cite: 956]

## ⚙️ How to Run

### 1. Prerequisites
Ensure you have Python installed, then install the required dependencies:
`pip install opencv-python mediapipe pyserial`

### 2. Flash the Firmware
1. Open the `Code/Arduino_Firmware/servo_driver.ino` file in the Arduino IDE.
2. [cite_start]Install the **Adafruit PWM Servo Driver Library** via the Library Manager[cite: 1085].
3. [cite_start]Connect your Arduino Uno and upload the code[cite: 1081].

### 3. Launch the Interface
1. [cite_start]Ensure your webcam is connected[cite: 1146].
2. [cite_start]Update the `SERIAL_PORT` variable in the Python script to match your Arduino's COM port[cite: 967].
3. Run the script:
`python Code/Computer_Vision/gesture_control.py`

## 📁 Repository Structure
* `/CAD_Models` - STL and source files for the 3D-printed components.
* `/Code` - Python vision scripts and Arduino C++ firmware.
* `/Docs` - Full project report, cost analysis, and orthographic drawings.
* `/Media` - Images, schematics, and demonstration videos.
