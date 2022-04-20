#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include "temp_struct.h"
#include "read_temperature_file.h"

#define READ_FILE_DEBUG 0
#define READLINE_DEBUG 0
#define READ_DEBUG 0
#define ADDR_DEBUG 0
#define ADDR_DEBUG_FINAL 0

uint32_t read_temperature_file(FILE *file, tmp_list **in_list)
{
    if (READ_FILE_DEBUG) printf("read_file_temperature function in\n");
    temperature *t_record_ptr;
    t_record_ptr = malloc(sizeof(temperature));
    int rline_res;
    uint32_t counter = 0;
    tmp_list *t_list;
    t_list = malloc(sizeof(tmp_list));
    while ((rline_res = readline(file, t_record_ptr)) > -1)
    {
        if (READ_FILE_DEBUG) printf("current readline result if %d\n", rline_res);
        if (rline_res == 0) continue;
        if (rline_res == 1)
        {
            if (READ_FILE_DEBUG) printf("after read: year " "%" PRIu16 ", mon " "%" PRIu8 ", day " "%" PRIu8 ", hour " "%" PRIu8 ", min " "%" PRIu8 ", temperature " "%" PRId8 "\n", t_record_ptr->year, t_record_ptr->mon, t_record_ptr->day, t_record_ptr->hour, t_record_ptr->min, t_record_ptr->temperature);
            if (counter == 0)
            {
                t_list->data = *t_record_ptr;
                t_list->next = NULL;
                if (ADDR_DEBUG) printf("current counter is: %d, current next is %p\n", counter, t_list->next);
                if (ADDR_DEBUG) printf("current counter is: %d, current t_list is %p\n", counter, t_list);
                if (ADDR_DEBUG) printf("counter 0, current t_list year " "%" PRIu16 ", mon " "%" PRIu8 ", day " "%" PRIu8 ", hour " "%" PRIu8 ", min " "%" PRIu8 ", temperature " "%" PRId8 "\n", t_list->data.year, t_list->data.mon, t_list->data.day, t_list->data.hour, t_list->data.min, t_list->data.temperature);
            }
            else
            {
                if (ADDR_DEBUG) printf("befofre push call current counter is: %d, current t_list is %p\n", counter, t_list);
                push_temperature(&t_list, *t_record_ptr);
                if (ADDR_DEBUG) printf("after push call current counter is: %d, current t_list is %p\n", counter, t_list);
                if (ADDR_DEBUG) printf("call is_list_empty %d\n", is_list_empty(t_list));
            }
            t_record_ptr = malloc(sizeof(temperature));
            counter++;
        }
    }
    if (rline_res == -2)
    {
        push_temperature(&t_list, *t_record_ptr);
        counter++;
    }
    // printf ("Read_temperature_file load %d records\n", counter);
    *in_list = t_list;


    if (ADDR_DEBUG_FINAL)
    {
        tmp_list *current_list; 
        current_list = *in_list;
        while(is_list_empty(current_list) != 1){
            if (ADDR_DEBUG_FINAL) printf("look befofre call current counter is: %d, current t_list is %p\n", counter, current_list);
            if (ADDR_DEBUG_FINAL) printf("call is_list_empty %d\n", is_list_empty(t_list));
            if (ADDR_DEBUG_FINAL) printf("year " "%" PRIu16 ", mon " "%" PRIu8 ", day " "%" PRIu8 ", hour " "%" PRIu8 ", min " "%" PRIu8 ", temperature " "%" PRId8 "\n", (current_list->data).year, (current_list->data).mon, (current_list->data).day, (current_list->data).hour, (current_list->data).min, (current_list->data).temperature);
            current_list = current_list->next;
            if (ADDR_DEBUG_FINAL) printf("look after call current counter is: %d, current t_list is %p\n", counter, current_list);
        }
    }


}

//возвращает -1 если EOF, 0, если строка некорректна, 1 если все ОК
int readline(FILE *f, temperature *t_record_ptr)
{
    char c;
    int current_col = 0;
    if (READLINE_DEBUG) printf("enter readline\n");
    uint16_t current_digit = 0;
    int sign = 1;
    while((c = fgetc(f)) != EOF)
    {
        if (READLINE_DEBUG) printf("current c %c\n", c);
        if (c == '-')
        {
            sign = -1;
        }
        else if (c == ';')
        {
            if (READLINE_DEBUG) printf("current digit: %d\n", current_digit);
            switch (current_col)
            {
            case 0:
                t_record_ptr->year = (uint16_t)current_digit;
                //if (READLINE_DEBUG) printf("t_record.year: %d\n", t_record_ptr->year);
            case 1:
                t_record_ptr->mon = (uint8_t)current_digit;
            case 2:
                t_record_ptr->day = (uint8_t)current_digit;
            case 3:
                t_record_ptr->hour = (uint8_t)current_digit;
            case 4:
                t_record_ptr->min = (uint8_t)current_digit;
            }
            sign = 1;
            current_col++;
            current_digit = 0;
            continue;
        }
        else if (c == '\n')
        {
            t_record_ptr->temperature = (int8_t)current_digit * sign;
            return 1;
        }
        else if ((c >= '0') && (c <= '9'))
        {
            current_digit = current_digit*10 + (c - '0');
        }
        else if (c == ' ')
        {
            continue;
        }
        else
        {
            if (READLINE_DEBUG) printf("%c\n", c);
            while((c = fgetc(f)) != '\n') 
            {
                if (READLINE_DEBUG) printf("%c\n", c);
            }
            return 0;
        }

    }
    if (current_col == 5)
    {
        t_record_ptr->temperature = current_digit * sign;
        return -2;
    }
    return -1;
}