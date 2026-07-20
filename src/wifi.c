#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "wifi.h"

void wifi_update(Wifi *wifi)
{
    FILE *fp = fopen("/proc/net/wireless", "r");

    if (fp == NULL) {
        wifi->connected = false;
        wifi->quality = 0;
        wifi->ssid[0] = '\0';
        return;
    }

    char line[256];

    fgets(line, sizeof(line), fp);
    fgets(line, sizeof(line), fp);

    if (fgets(line, sizeof(line), fp) == NULL) {
        wifi->connected = false;
        wifi->quality = 0;
        wifi->ssid[0] = '\0';
        fclose(fp);
        return;
    }

    int quality = 0;

    if (sscanf(line, " %*[^:]: %*d %d.", &quality) == 1) {
        wifi->connected = true;
        wifi->quality = quality;
        strcpy(wifi->ssid, "");
    }
    else {
        wifi->connected = false;
        wifi->quality = 0;
        wifi->ssid[0] = '\0';
    }

    fclose(fp);
}
