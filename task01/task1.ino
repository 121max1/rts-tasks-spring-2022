struct Led
{
  int pin;
  int state;
  unsigned long previousMicros;
  unsigned long interval;
};

struct Led leds[] = {
  5, LOW, 0, 111000,
  6, LOW, 0, 11000,
  9, LOW, 0, 1110,
  10, LOW, 0,111,
  11, LOW, 0, 11
};

void setup() {
  for (int i = 0; i < 5; i++)
  {
    pinMode(leds[i].pin, OUTPUT);
  }
}

void loop()
{
  unsigned long currentMicros = micros();

  for (int i = 0; i < 5; i++)
  {
    if (currentMicros - leds[i].previousMicros  > leds[i].interval)
    {
      leds[i].previousMicros  = currentMicros ;

      if (leds[i].state == LOW)
        leds[i].state = HIGH;
      else
        leds[i].state = LOW;

      digitalWrite(leds[i].pin, leds[i].state);
    }
  }
}
