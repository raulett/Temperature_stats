#include <stdio.h>
#include <stdlib.h>
#include "temp_api.h"
#include "parse_args.h"
#include "temp_struct.h"
#include "read_temperature_file.h"

#define PARSE_DEBUG 0
#define READ_DEBUG 0
#define DEBUG_TEST 0
#define SELECT_DEBUG 0
#define OUTPUT_DEBUG 0

int main(int argc, char **argv) {
    parsed_args args = get_arguments_parsed(argc, argv);
    if(PARSE_DEBUG) printf("args_parsed_flag = %d, in_file_flag = %d, in_file_name = %p, stat_parsed_flag = %d, stat_parsed_type = %d\n", args.args_parsed_flag, args.in_file_parsed_flag, args.in_file, args.stat_parsed_flag, args.stat_parsed_type);
    if(PARSE_DEBUG) printf("year_parsed_flag = %d, year_parsed = %d, month_parsed_flag = %d, month_parsed = %d\n", args.year_parsed_flag, args.year_parsed, args.month_parsed_flag, args.month_parsed);
    tmp_list *in_temp_list;
    //in_temp_list = malloc(sizeof(tmp_list));
    if (args.in_file_parsed_flag)
    {
        
        read_temperature_file(args.in_file, &in_temp_list);
    } 
    else
    {
        printf("No input file found");
        free(in_temp_list);
        return 1;
    }
    if (READ_DEBUG)
    {
        if (READ_DEBUG) printf("List after read!\n");
        int counter = 0;
        tmp_list *current_list; 
        current_list = in_temp_list;
        while(is_list_empty(current_list) != 1){
            //if (READ_DEBUG) printf("main look befofre call, current t_list is %p\n", current_list);
            //if (READ_DEBUG) printf("main call is_list_empty %d\n", is_list_empty(current_list));
            if (READ_DEBUG) printf("%d) main year " "%" PRIu16 ", mon " "%" PRIu8 ", day " "%" PRIu8 ", hour " "%" PRIu8 ", min " "%" PRIu8 ", temperature " "%" PRId8 "\n", counter, (current_list->data).year, (current_list->data).mon, (current_list->data).day, (current_list->data).hour, (current_list->data).min, (current_list->data).temperature);
            current_list = current_list->next;
            //if (READ_DEBUG) printf("main look after call current t_list is %p\n", current_list);
            counter++;
        }
    }
    uint8_t current_mon = args.month_parsed;
    if (args.month_parsed_flag == 0) current_mon = 0;
    select_period(&in_temp_list, args.year_parsed, current_mon);

    if (SELECT_DEBUG)
    {
        if (SELECT_DEBUG) printf("List after select!\n");
        int counter = 0;
        tmp_list *current_list; 
        current_list = in_temp_list;
        while(is_list_empty(current_list) != 1){
            //if (READ_DEBUG) printf("main look befofre call, current t_list is %p\n", current_list);
            //if (READ_DEBUG) printf("main call is_list_empty %d\n", is_list_empty(current_list));
            if (SELECT_DEBUG) printf("%d) main year " "%" PRIu16 ", mon " "%" PRIu8 ", day " "%" PRIu8 ", hour " "%" PRIu8 ", min " "%" PRIu8 ", temperature " "%" PRId8 "\n", counter, (current_list->data).year, (current_list->data).mon, (current_list->data).day, (current_list->data).hour, (current_list->data).min, (current_list->data).temperature);
            current_list = current_list->next;
            //if (READ_DEBUG) printf("main look after call current t_list is %p\n", current_list);
            counter++;
        }
    }

    if (OUTPUT_DEBUG) printf("current stat parsed flag: %d\n", args.stat_parsed_type);
    if (args.stat_parsed_flag)
    {
        if (args.stat_parsed_type == 1) printf("average_temp: %.2lf\n", average_temp(in_temp_list));
        if (args.stat_parsed_type == 2) printf("min_temp: %d\n", min_temp(in_temp_list));
        if (args.stat_parsed_type == 3) printf("max_temp: %d\n", max_temp(in_temp_list));
    }
    else
    {
        printf("Error statistic type. enter statistic -s.");
        return 0;
    }
    if (OUTPUT_DEBUG) printf("average_temp: %.2lf\n", average_temp(in_temp_list));
    if (OUTPUT_DEBUG) printf("min_temp: %d\n", min_temp(in_temp_list));
    if (OUTPUT_DEBUG) printf("max_temp: %d\n", max_temp(in_temp_list));
    return 0;
}
    

    // if (DEBUG_TEST) 
    // {
    //     int test_int[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    //     test_list *test_digits_list;
    //     test_digits_list = malloc(sizeof(test_list));
    //     test_digits_list->digit = test_int[0];
    //     test_digits_list->next = NULL;
    //     for (int i = 1; i < 10; i++)
    //     {
    //         if (DEBUG_TEST) printf("main t_list list addr 1 %p\n", test_digits_list);
    //         push_test(&test_digits_list, test_int[i]);
    //         if (DEBUG_TEST) printf("main t_list list addr 2 %p\n", test_digits_list);
    //     }
    //     while (test_is_list_empty(test_digits_list) != 1)
    //     {
    //         printf("current list addr %p\n", test_digits_list);
    //         printf("current list member %d\n", pop_test(&test_digits_list));
    //         printf("current list addr after pop %p\n", test_digits_list);
    //     }
    // }
    

