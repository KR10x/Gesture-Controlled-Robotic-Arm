#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pca = Adafruit_PWMServoDriver();

//SERVO LIMITS
#define SERVOMIN  150   // pulse for 0°
#define SERVOMAX  600   // pulse for 180°

int angles[6] = {90, 90, 90, 90, 90, 60};   // current
int target[6] = {90, 90, 90, 90, 90, 60};   // incoming

String input = "";


int angleToPulse(int angle) {
  return map(angle, 0, 180, SERVOMIN, SERVOMAX);
}

void setup() {
  Serial.begin(115200);

  pca.begin();
  pca.setPWMFreq(50); 

  delay(500);


  for (int i = 0; i < 6; i++) {
    pca.setPWM(i, 0, angleToPulse(angles[i]));
  }
}

void loop() {

  
  if (Serial.available()) {
    input = Serial.readStringUntil('\n');

    int i = 0;
    char *token = strtok((char*)input.c_str(), ",");

    while (token != NULL && i < 6) {
      target[i++] = atoi(token);
      token = strtok(NULL, ",");
    }
  }

 
  for (int i = 0; i < 6; i++) {
    angles[i] = 0.7 * angles[i] + 0.3 * target[i];
  }

 
  for (int ch = 0; ch < 6; ch++) {
    int pulse = angleToPulse(angles[ch]);
    pca.setPWM(ch, 0, pulse);
  }

  delay(20);  
}
