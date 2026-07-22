#include <stdbool.h>
#include <time.h>
#include <ncurses.h>
#include "statusbar.h"
#include "clock.h"
#include "battery.h"

int main(void) 
{
    initscr();

    noecho();
    cbreak();
    keypad(stdscr, TRUE);
    curs_set(0);

    halfdelay(2);

    bool running = true;

    time_t last_second = 0;

    char clock[16]; 
    char date[32];
    Wifi wifi = {0};
    Battery battery = {0};

    while(running)
    {
        time_t now = time(NULL);

        if (now != last_second)
        {
            last_second = now;
            get_time_string(clock, sizeof(clock));
            get_date_string(date, sizeof(date));
            wifi_update(&wifi);
            battery_update(&battery);
            draw_statusbar(date, clock, &wifi, &battery);
            refresh();
        }
        int ch = getch();

        if (ch == 'q')
            running = false;
    }

    endwin();
    
    return 0;
}
