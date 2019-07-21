#ifndef __FAN_H__
#define __FAN_H__

#define FAN_PIN 7
#define TEMP_THRESHOLD 50
#define TEMPERATURE_FILE "/sys/class/thermal/thermal_zone0/temp"

void Switch(int);
float getcurrentTemp();
void autoRun();
#endif
