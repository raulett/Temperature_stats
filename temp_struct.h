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
} temperature;

typedef struct temperature_list
{
    temperature data;
    struct temperature_list *next;
} tmp_list;

void  push_temperature(tmp_list**, temperature);
_Bool is_list_empty(tmp_list*);
temperature pop(tmp_list**);




// typedef struct intlist
// {
//     int digit;
//     struct intlist *next;
// } test_list;

// void push_test(test_list **t_list, int digit);
// int pop_test(test_list **t_list);
// _Bool test_is_list_empty(test_list *t_list);

#endif