#include <SoftwareSerial.h>

#define ENCODER_CHANNEL_A 20
#define ENCODER_CHANNEL_B 21
#define BUFFERSIZE 20

SoftwareSerial RPISerial(19, 18); // RX, TX 

volatile unsigned long encoderPulse = 0;
volatile long movementDirection = 1;

void setup() 
{
  timerInit();
  
  Serial.begin(9600);
  RPISerial.begin(115200);

  attachInterrupt(digitalPinToInterrupt(ENCODER_CHANNEL_A), encoderISRChannelA, CHANGE);
  attachInterrupt(digitalPinToInterrupt(ENCODER_CHANNEL_B), encoderISRChannelB, CHANGE);
}

void loop()
{
  RPISerial.print("Pulses: ");RPISerial.print(encoderPulse);RPISerial.print("\n");
  RPISerial.print("Direction: ");RPISerial.print(movementDirection);RPISerial.print("\n");
  
  Serial.print("Pulses: ");Serial.print(encoderPulse);Serial.print("\n");
  Serial.print("Direction: ");Serial.print(movementDirection);Serial.print("\n");

  delay(10);
}
