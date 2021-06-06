#include <SoftwareSerial.h>
#include <TimerThree.h>

#define COUNTS_PER_PULSE 4
#define PULSES_PER_LAP 36
#define DEBUG_PIN 2
#define ENCODER_CHANNEL_A 20
#define ENCODER_CHANNEL_B 21
#define PERIOD_MS 500.0
#define MILLISEC_TO_MICROSEC 1000.0
#define MILLISEC_TO_SEC 1/1000
#define MILLISEC_TO_MIN 1/1000/60

SoftwareSerial RPISerial(19, 18); // RX, TX 

volatile unsigned long encoderPulse = 0;
volatile long movementDirection = 1;
float wheelSpeed = 0;
float prevWheelSpeed = 0;

void setup() 
{
  pinMode(DEBUG_PIN, OUTPUT);

  Timer3.initialize(PERIOD_MS * MILLISEC_TO_MICROSEC);
  Timer3.attachInterrupt(encoderReport);

  Serial.begin(9600);
  RPISerial.begin(115200);

  attachInterrupt(digitalPinToInterrupt(ENCODER_CHANNEL_A), encoderISRChannelA, CHANGE);
  attachInterrupt(digitalPinToInterrupt(ENCODER_CHANNEL_B), encoderISRChannelB, CHANGE);
}

void loop()
{
  delay(10);
}
