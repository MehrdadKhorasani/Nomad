#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "battery.h"

void battery_update(Battery *bat)
{
    FILE *fp = fopen("/sys/class/power_supply/BAT0/capacity", "r");

    if (!fp) {
        bat->percent = -1;
        bat->status[0] = '\0';
        return;
    }
    int percent = 0;
    bat->percent = percent;

    fscanf(fp, "%d", &bat->percent);
    fclose(fp);
}
