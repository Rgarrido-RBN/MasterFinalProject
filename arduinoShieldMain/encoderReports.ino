void timerInit()
{
  cli();
  TCCR3A = 0;
  TCCR3B = 0;
  TCNT3  = 0;
  OCR3A = 15624;
  TCCR3B |= (1 << WGM12);
  TCCR3B |= (1 << CS12) | (1 << CS10);  
  TIMSK3 |= (1 << OCIE1A);  
  sei();
}
ISR(TIMER3_COMPA_vect)
{
  long speed = encoderPulse/2400.00*60;
  Serial.println(direction*speed);
   encoderPulse = 0; 
}
void encoderISRChannelA()
{
  encoderPulse++;
  movementDirection = digitalRead(ENCODER_CHANNEL_A) == digitalRead(ENCODER_CHANNEL_B) ? -1 : 1;
}

void encoderISRChannelB()
{
  encoderPulse++;
  movementDirection = digitalRead(ENCODER_CHANNEL_A) != digitalRead(ENCODER_CHANNEL_B) ? -1 : 1;
}
