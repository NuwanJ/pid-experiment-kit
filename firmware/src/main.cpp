
#include <Arduino.h>

#define PIN_A 18
#define PIN_B 19
#define PIN_EN 21
#define PIN_POT 13

// setting PWM properties
#define PWM_CHANNEL 0
#define PWM_FREQ 5000
#define PWM_RES 12

//PID constants
double kp = 15;
double ki = 0.01;
double kd = 0.05;

unsigned long currentTime, previousTime;
double elapsedTime;
double lastError;
double cumError, rateError;
int setPoint = 0;
int correction = 80;

void setup() {
    // Set software serial baud to 115200;

    Serial.begin(115200);

    pinMode(PIN_A, OUTPUT);
    pinMode(PIN_B, OUTPUT);
    pinMode(PIN_EN, OUTPUT);

    // Configure LED PWM functionalitites
    ledcSetup(PWM_CHANNEL, PWM_FREQ, PWM_RES);

    // Attach the channel to the GPIO to be controlled
    ledcAttachPin(PIN_EN, PWM_CHANNEL);
    ledcWrite(PWM_CHANNEL, 0);

    // Setup Digital Ports
    digitalWrite(PIN_A, HIGH);
    digitalWrite(PIN_B, LOW);

    setPoint = 0;
}

int computePID(int error){
    currentTime = millis();
    elapsedTime = (int)(currentTime - previousTime);

    cumError += error * elapsedTime;
    rateError = (error - lastError)/elapsedTime;

    int out = (int)(kp*error + ki*cumError + kd*rateError);

    lastError = error;
    previousTime = currentTime;

    return max(-4095, min(out, 4095));
}

void loop() {

    int potValue = analogRead(PIN_POT) - 2047 - correction;
    int error = -1*(setPoint - potValue)/4;
    int pid = computePID(error);
    int motorSpeed = abs(pid);
    Serial.printf("R: %d, SP: %d, E: %d, Out: %d (p=%f i=%f d=%f)\n", potValue, setPoint, error, motorSpeed, kp*error, ki*cumError, kd*rateError);

    if(pid > 0){
        digitalWrite(PIN_A, HIGH);
        digitalWrite(PIN_B, LOW);
    }else{
        digitalWrite(PIN_A, LOW);
        digitalWrite(PIN_B, HIGH);
    }

    ledcWrite(PWM_CHANNEL, motorSpeed );

    delay(50);
}
