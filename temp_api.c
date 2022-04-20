#include <stdint.h>
#include <stdlib.h>
#include <inttypes.h>
#include <stdio.h>
#include <limits.h>
#include "temp_struct.h"
#include "temp_api.h"

#define SELECT_DEBUG 0
#define AVG_DEBUG 0



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

double average_temp(tmp_list *t_list)
{
    tmp_list *current_member;
    current_member = t_list;
    long counter = 0;
    long sum = 0;
    while(is_list_empty(current_member) != 1)
    {
        sum += (current_member->data).temperature;
        
        counter++;
        if (AVG_DEBUG) printf("AVG DEBUG, current sum %d, current counter %d\n", sum, counter);
        current_member = current_member->next;
    }
    double result = ((double)sum)/counter;

    return result;
}

int8_t min_temp(tmp_list *t_list)
{
    tmp_list *current_member;
    current_member = t_list;
    int8_t result = INT8_MAX;
    while(is_list_empty(current_member) != 1)
    {
        if ((current_member->data).temperature < result) result = (current_member->data).temperature;
        current_member = current_member->next;
    }
    return result;
}

int8_t max_temp(tmp_list *t_list)
{
    tmp_list *current_member;
    current_member = t_list;
    int8_t result = INT8_MIN;
    while(is_list_empty(current_member) != 1)
    {
        if ((current_member->data).temperature > result) result = (current_member->data).temperature;
        current_member = current_member->next;
    }
    return result;
}

//return size of list and rewrite tmp_list with selected period
uint32_t select_period(tmp_list **t_list, uint16_t year, uint8_t mon){
    if (SELECT_DEBUG) printf("Enter selec period func!\n");
    tmp_list *current_member;
    tmp_list *result_list;
    result_list = malloc(sizeof(tmp_list));
    current_member = *t_list;
    _Bool same_year_flag = 0;
    _Bool same_mon_flag = 0;
    int counter = 0;
    int count = 0;
    if (mon == 0) same_mon_flag = 1;
    if (SELECT_DEBUG) printf("%d) Current year %d, curr mon %d, same year flag: %d, same mon flag %d\n", counter, year, mon, same_year_flag, same_mon_flag);
    while(is_list_empty(current_member) != 1)
    {
        
        same_year_flag = 0;
        if (mon == 0) same_mon_flag = 1;
        else same_mon_flag = 0;
        uint16_t curr_year = current_member->data.year;
        uint8_t curr_mon = current_member->data.mon;
        if (curr_year == year) same_year_flag = 1;
        if (curr_mon == mon) same_mon_flag = 1;
        if (SELECT_DEBUG) printf("%d) WHILE main year " "%" PRIu16 ", mon " "%" PRIu8 ", day " "%" PRIu8 ", hour " "%" PRIu8 ", min " "%" PRIu8 ", temperature " "%" PRId8 "\n", counter, (current_member->data).year, (current_member->data).mon, (current_member->data).day, (current_member->data).hour, (current_member->data).min, (current_member->data).temperature);
        if (SELECT_DEBUG) printf("%d) WHILE Current year %d, curr mon %d, same year flag: %d, same mon flag %d\n", counter, year, mon, same_year_flag, same_mon_flag);
        if (same_year_flag && same_mon_flag)
        {
            if (count == 0)
            {
                result_list->data = current_member->data;
                result_list->next = NULL;
            }
            else
            {
                push_temperature(&result_list, current_member->data);
            }
            count++;          
        }
        current_member = current_member->next;
        counter++;
    }
    if (SELECT_DEBUG)
    {
        if (SELECT_DEBUG) printf("List after select!\n");
        int counter = 0;
        tmp_list *current_list; 
        current_list = result_list;
        while(is_list_empty(current_list) != 1){
            //if (READ_DEBUG) printf("main look befofre call, current t_list is %p\n", current_list);
            //if (READ_DEBUG) printf("main call is_list_empty %d\n", is_list_empty(current_list));
            if (SELECT_DEBUG) printf("%d) main year " "%" PRIu16 ", mon " "%" PRIu8 ", day " "%" PRIu8 ", hour " "%" PRIu8 ", min " "%" PRIu8 ", temperature " "%" PRId8 "\n", counter, (current_list->data).year, (current_list->data).mon, (current_list->data).day, (current_list->data).hour, (current_list->data).min, (current_list->data).temperature);
            current_list = current_list->next;
            //if (READ_DEBUG) printf("main look after call current t_list is %p\n", current_list);
            counter++;
        }
    }
    *t_list = result_list;
    return 0;
}