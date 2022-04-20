#include <stdint.h>
#include <inttypes.h>
#include "temp_struct.h"
#include "temp_api.h"



int compare_datetime(const void * val1, const void * val2){
    temperature a = *((temperature*)val1);
    temperature b = *((temperature*)val1);

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

int8_t average_temp(tmp_list *t_list)
{
    return 0;
}

int8_t min_temp(tmp_list *t_list)
{
    return 0;
}

int8_t max_temp(tmp_list *t_list)
{
    return 0;
}

//return size of list and rewrite tmp_list with selected period
uint32_t select_period(tmp_list *t_list){
    return 0;
}