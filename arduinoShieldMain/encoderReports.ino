void encoderReport()
{
  // wheelSpeed = (encoderPulse / COUNTS_PER_PULSE / PULSES_PER_LAP) * (PERIOD_MS / MILLISEC_TO_MIN); //ENCODER RPM
  wheelSpeed = (encoderPulse / COUNTS_PER_PULSE) * (PERIOD_MS); //PULSES PER MILLISEC
  if(prevWheelSpeed != wheelSpeed)
  {
    RPISerial.print("RPM of Right encoder: ");RPISerial.print(wheelSpeed * movementDirection);RPISerial.print("\n");
  }
  prevWheelSpeed = wheelSpeed;
  encoderPulse = 0; 
}
void encoderISRChannelA()
{
  encoderPulse++;
  movementDirection = digitalRead(ENCODER_CHANNEL_A) == digitalRead(ENCODER_CHANNEL_B) ? -1 : 1;
  digitalWrite(DEBUG_PIN, !digitalRead(DEBUG_PIN));
}

void encoderISRChannelB()
{
  encoderPulse++;
  movementDirection = digitalRead(ENCODER_CHANNEL_A) != digitalRead(ENCODER_CHANNEL_B) ? -1 : 1;
}
