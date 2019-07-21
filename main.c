#include "distance.h"
#include "fan.h"
#include <sys/io.h>
#include <stdio.h>
#include <string.h>


#include <wiringPi.h>



char *usage = "Usage: main -h\n"
              "       main Fan\n"
              "       main Distance\n"
              "       main Temp\n"
              "       main autoRun\n";

int main(int argc, char *argv[])
{
    if (-1 == wiringPiSetup())
    {
        fprintf(stderr, "setup failed.\n");
        return -1;
    }
    if (argc != 2)
    {
        printf("%s", usage);
        return 0;
    }
    if (strcmp(argv[1],"-h")==0){
        fprintf(stdout,usage);
        return 0;
    }
    if (strcmp(argv[1], "Fan") == 0)
    {
        Switch(FAN_PIN);
        return 0;
    }
    if (strcmp(argv[1],"autoRun")==0){
        autoRun();
        return 0;
    }
    if (strcmp(argv[1], "Distance") == 0)
    {
        if (distance() == -1)
        {
            fprintf(stderr,"error\n");
        }
        return 0;
    }
    if (strcmp(argv[1],"Temp")==0){
        float temp=0;
        if ((temp=getcurrentTemp())!=-1){
            fprintf(stdout,"T:%fC\n",temp);
        }else{
            fprintf(stderr,"Get temp failed\n");
        }
    }
    return 0;
}
