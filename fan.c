#include "fan.h"
#include <wiringPi.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

void Switch(int pin)
{
    pinMode(pin,OUTPUT);
    digitalWrite(pin, digitalRead(pin) == 1 ? 0 : 1);
}
void autoRun()
{
    while(1){ 
        if (getcurrentTemp()>=TEMP_THRESHOLD ){
            Switch(FAN_PIN);
        }else{
        delay(30000);
        }
    }
}

float getcurrentTemp()
{
    char buf[10];
    FILE *f = fopen(TEMPERATURE_FILE, "r");
    if (f == NULL)
    {
        return -1;
    }
    if (NULL == fgets(buf, 10, f))
    {
        fclose(f);
        return -1;
    }
    else
    {
        fclose(f);
        return (float)atof(buf)/1000;
    }
}
