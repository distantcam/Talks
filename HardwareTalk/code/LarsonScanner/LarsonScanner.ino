int latchPin = 5;
int clockPin = 6;
int dataPin = 4;

byte leds = 1;

void setup() 
{
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);  
  pinMode(clockPin, OUTPUT);
}

void loop() 
{
  for (int i = 0; i < 7; i++)
  {
    leds = leds << 1;
    updateShiftRegister(leds);
    delay(100);
  }
  for (int i = 0; i < 7; i++)
  {
    leds = leds >> 1;
    updateShiftRegister(leds);
    delay(100);
  }
}

void updateShiftRegister(byte value)
{
   digitalWrite(latchPin, LOW);
   shiftOut(dataPin, clockPin, LSBFIRST, value);
   digitalWrite(latchPin, HIGH);
}
