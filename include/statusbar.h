#ifndef STATUSBAR_H
#define STATUSBAR_H

#include "wifi.h"
#include "battery.h"

void draw_statusbar(const char *time,
                    const char *date,
                    const Wifi *wifi,
                    const Battery *bat);

#endif

