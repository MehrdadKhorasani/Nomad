#ifndef BATTERY_H
#define BATTERY_H

typedef struct {
    int percent;
    char status[4];
} Battery;

void battery_update(Battery *bat);

#endif
