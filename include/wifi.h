#ifndef WIFI_H
#define WIFI_H

typedef struct 
{
    int quality;     //0..100
    bool connected;
    char ssid[33];
} Wifi;

void wifi_update(Wifi *wifi);

#endif
