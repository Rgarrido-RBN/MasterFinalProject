#include <SoftwareSerial.h>

#define ENCODER_CHANNEL_A 3
#define ENCODER_CHANNEL_B 5
#define BUFFERSIZE 20

SoftwareSerial RPISerial(1, 2); // RX, TX 

volatile unsigned long encoderPulse = 0;
volatile long direction = 1;

void setup() 
{
  Serial.begin(9600);
  RPISerial.begin(115200);

  pinMode(ENCODER_CHANNEL_A, INPUT_PULLUP);
  pinMode(ENCODER_CHANNEL_B, INPUT_PULLUP);

  attachInterrupt(0, encoderISRChannelA, CHANGE);
  attachInterrupt(1, encoderISRChannelB, CHANGE);
}

void loop()
{
  long speed = encoderPulse/2400.00*60;
  Serial.println(direction*speed);
  encoderPulse = 0; 
  delay(1000);

  Serial.println("Opening the communication");
  long setime = millis();
  RPISerial.write("message");

  char rfidData[BUFFERSIZE];  
  rfidData[0] = 0;
  char offset = 0;      

  while (RPISerial.available()) 
  {
    byte C = RPISerial.read();
    rfidData[offset] = C;
    offset++;
    Serial.print(C);
  }

  if(offset == 17)
  {
    Serial.println(" ");
    Serial.println(rfidData);
  }
}

void encoderISRChannelA()
{
  encoderPulse++;
  direction = digitalRead(ENCODER_CHANNEL_A) == digitalRead(ENCODER_CHANNEL_B) ? -1 : 1;
}

void encoderISRChannelB()
{
  encoderPulse++;
  direction = digitalRead(ENCODER_CHANNEL_A) != digitalRead(ENCODER_CHANNEL_B) ? -1 : 1;
}