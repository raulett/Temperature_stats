#include <stdint.h>
#include <inttypes.h>
#include "temp_api.h"
#include "temp_struct.h"

int compare_datetime(const void * val1, const void * val2)
{
    struct temp a = *((struct temp*)val1);
    struct temp b = *((struct temp*)val1);

    if (a.year > b.year) return 1;
    else if (a.year < b.year) return -1;

    if (a.mon > b.mon) return 1;
    else if (a.mon < b.mon) return -1;

    if (a.day > b.day) return 1;
    else if (a.day < b.day) return -1;

    if (a.hour > b.hour) return 1;
    else if (a.hour < b.hour) return -1;

    if (a.min > b.min) return 1;
    else if (a.min < b.min) return -1;
    else return 0;
}

int8_t average_mon_temp(struct temp_arr t_arr, uint8_t mon, uint16_t year)
{
    
}

int8_t min_mon_temp(struct temp_arr t_arr, uint8_t mon, uint16_t year)
{
    
}

int8_t max_mon_temp(struct temp_arr t_arr, uint8_t mon, uint16_t year)
{
    
}

int8_t average_year_temp(struct temp_arr t_arr, uint16_t year)
{
    
}

int8_t min_year_temp(struct temp_arr t_arr, uint16_t year)
{
    
}

int8_t max_year_temp(struct temp_arr t_arr, uint16_t year)
{
    
}