#include <stdio.h>
#include <stdlib.h>
#include "temp_api.h"
#include "parse_args.h"
#include "temp_struct.h"
#include "read_temperature_file.h"

#define PARSE_DEBUG 0
#define READ_DEBUG 0
#define DEBUG_TEST 1

int main(int argc, char **argv) {
    parsed_args args = get_arguments_parsed(argc, argv);
    if(PARSE_DEBUG) printf("args_parsed_flag = %d, in_file_flag = %d, in_file_name = %p, stat_parsed_flag = %d, stat_parsed_type = %d\n", args.args_parsed_flag, args.in_file_parsed_flag, args.in_file, args.stat_parsed_flag, args.stat_parsed_type);
    if(PARSE_DEBUG) printf("year_parsed_flag = %d, year_parsed = %d, month_parsed_flag = %d, month_parsed = %d\n", args.year_parsed_flag, args.year_parsed, args.month_parsed_flag, args.month_parsed);
    tmp_list *in_temp_list;
    in_temp_list = malloc(sizeof(tmp_list));
    if (args.in_file_parsed_flag)
    {
        
        read_temperature_file(args.in_file, in_temp_list);
    } 
    else
    {
        printf("No input file found");
        free(in_temp_list);
        return 1;
    }
    if (READ_DEBUG){
        for(int i = 0; i < 17; i++){
            temperature t_record = pop(&in_temp_list);
            if (READ_DEBUG) printf("year " "%" PRIu16 ", mon " "%" PRIu8 ", day " "%" PRIu8 ", hour " "%" PRIu8 ", min " "%" PRIu8 ", temperature " "%" PRId8 "\n", t_record.year, t_record.mon, t_record.day, t_record.hour, t_record.min, t_record.temperature);
        }
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
    return 0;
}
