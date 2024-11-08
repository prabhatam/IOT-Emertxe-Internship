#include "ldr.h"
#include "Arduino.h"
#include "main.h"

void init_ldr(void)
{
   pinMode(GARDEN_LIGHT, OUTPUT);
   pinMode(LDR_SENSOR, INPUT);
   
}

void brightness_control(void)
{
  unsigned int ADC_value;
  // to read values from the LDR_SENSOR sensor
  ADC_value = analogRead(A1); // 0 to 5v -> 0 to 1023
  // scale it down to 0 to 255 and reverse it 255 to 0.
  ADC_value = 255-(ADC_value/4);
  // we can also implement the above logic using in-built function
  // map(o,1023,255,0);
  analogWrite(GARDEN_LIGHT, ADC_value);
  delay(100);
}
