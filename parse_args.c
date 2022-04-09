#include <inttypes.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "parse_args.h"
#include "show_help.h"


struct parsed_args get_arguments_parsed(int argc, char **argv)
{
    int arg_flag = 0;
    struct parsed_args result;
    //init result
    result.args_parsed_flag = 0;
    result.in_file_parsed_flag = 0;
    result.in_file = NULL;
    result.stat_parsed_flag = 0;
    result.stat_parsed_type = 0;
    result.year_parsed_flag = 0;
    result.year_parsed = 0;
    result.month_parsed_flag = 0;
    result.month_parsed = 0;
    
    while ( (arg_flag = getopt(argc,argv,"hf:s:y:m:")) != -1)
    {
        //printf("%s, %s", arg_flag, optarg);
        char filename[255];
        int year, mon;
        switch (arg_flag)
        {
        case 'h': 
            show_help(); 
            break;
        case 'f': 
            strcpy(filename, optarg);
            result.in_file = fopen(filename, "r");
            if (result.in_file != NULL) result.in_file_parsed_flag = 1;
            continue;
            //printf("found argument \"i = %s\".\n",optarg); continue;
        case 's': 
            if ((strcmp(optarg, "avg") == 0) || (parse_pos_int(optarg) == 1))
            {
                result.stat_parsed_flag = 1;
                result.stat_parsed_type = 1;
            }
            if ((strcmp(optarg, "min") == 0) || (parse_pos_int(optarg) == 2))
            {
                result.stat_parsed_flag = 1;
                result.stat_parsed_type = 2;
            }
            if ((strcmp(optarg, "max") == 0) || (parse_pos_int(optarg) == 3))
            {
                result.stat_parsed_flag = 1;
                result.stat_parsed_type = 3;
            }
            continue;
            //printf("found argument \"s = %s\".\n",optarg); continue;
        case 'y': 
            year = parse_pos_int(optarg);
            if ((year >= 1980) && (year <= 2100))
            {
                result.year_parsed_flag = 1;
                result.year_parsed = year;
            }
            //printf("found argument \"y = %s\".\n",optarg); 
            continue;
        case 'm':
            mon = parse_pos_int(optarg);
            if ((mon >= 1) && (mon <= 12))
            {
                result.month_parsed_flag = 1;
                result.month_parsed = mon;
            } 
            //printf("found argument \"m = %s\".\n",optarg); 
            continue;
        }

    }
    result.args_parsed_flag = result.in_file_parsed_flag*1000 + result.stat_parsed_flag*100 + result.year_parsed_flag*10 + result.month_parsed_flag;
    return result;
}

int parse_pos_int(char input_str[])
{
    int result = 0;
    int int_len = strlen(input_str);
    for (int i = 0; i < int_len; i++)
    {   
        if ((input_str[i] >= '0') && (input_str[i] <= '9'))
        {
            result = result*10 + (int)(input_str[i]-'0');
        }
    }
    return result;    
}