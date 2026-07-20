#include <time.h>
#include "clock.h"

void get_time_string(char *buffer, int size)
{
    time_t now = time(NULL);
    struct tm *local = localtime(&now);
    strftime(buffer, size, "%H:%M:%S", local);
}

void get_date_string(char *buffer, int size) 
{
    time_t now = time(NULL);
    struct tm *local = localtime(&now);
    strftime(buffer, size, "%a %d %b %Y", local);
}
