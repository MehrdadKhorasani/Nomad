#include <ncurses.h>

#include "statusbar.h"
#include "clock.h"
#include "wifi.h"
#include "battery.h"

void draw_statusbar(const char *date,
                    const char *time,
                    const Wifi *wifi,
                    const Battery *bat)
{
    move(0,0);
    clrtoeol();
    mvprintw(0, 2, "NOMAD");
    mvprintw(0, 12, "%s", date);
    if(wifi->connected)
        mvprintw(0, COLS - 22, "Wifi:%2d%%", wifi->quality);
    else
        mvprintw(0, COLS - 22, "Wifi:--");
    if(bat->percent)
        mvprintw(0,COLS - 33, "[%d%%]", bat->percent);
    mvprintw(0,COLS - 10, "%s", time);
    mvhline(1, 0, ACS_HLINE, COLS);
}
