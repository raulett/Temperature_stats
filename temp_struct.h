#ifndef TEMP_STRUCT_H
#define TEMP_STRUCT_H
#include <stdint.h>

typedef struct temp
{
    int8_t temperature;
    uint16_t year;
    uint8_t mon;
    uint8_t day;
    uint8_t hour;
    uint8_t min;  
};

typedef struct temp_arr
{
    struct temp *temp_list;
    uint32_t temp_list_size;
};

#endif