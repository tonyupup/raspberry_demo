#include <wiringPi.h>
#include <stdio.h>
#include <sys/time.h>
#include <signal.h>
#include "distance.h"



typedef void (*sigFunc)(int);

float one()
{
    struct timeval tv1, tv2;
    float start, stop, dis;
    digitalWrite(GPIO_TRIGE, HIGH);
    delayMicroseconds(10);
    digitalWrite(GPIO_TRIGE, LOW);

    while (digitalRead(GPIO_ECHO) == LOW)
        ;
    gettimeofday(&tv1, NULL);
    while (digitalRead(GPIO_ECHO) == HIGH)
        ;
    gettimeofday(&tv2, NULL);

    start = tv1.tv_sec * 1000000 + tv1.tv_usec;
    stop = tv2.tv_sec * 1000000 + tv2.tv_usec;

    
    return (float)(stop - start) / 1000000 * 34000 / 2;
}

int *cot;

void mySigfunc(int sig)
{
    *cot = 0;
    pinMode(GPIO_TRIGE, INPUT);
    pinMode(GPIO_ECHO, INPUT);
}
int distance()
{
    float dis;
    int flag = 1;
    cot = &flag;
    sigFunc s = &mySigfunc;
    pinMode(GPIO_TRIGE, OUTPUT);
    pinMode(GPIO_ECHO, INPUT);

    if (signal(SIGINT, s) == SIG_ERR)
    {
        return -1;
    }
    while (*cot)
    {
        dis = one();
        printf("[Dis],%fcm\n", dis);
        delay(500);
    }
}
