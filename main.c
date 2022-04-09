#include <stdio.h>
#include "temp_api.h"

#include "parse_args.h"

#define PARSE_DEBUG 0

int main(int argc, char **argv) {
    struct parsed_args args;
    args = get_arguments_parsed(argc, argv);
    if(PARSE_DEBUG) printf("args_parsed_flag = %d, in_file_flag = %d, in_file_name = %p, stat_parsed_flag = %d, stat_parsed_type = %d\n", args.args_parsed_flag, args.in_file_parsed_flag, args.in_file, args.stat_parsed_flag, args.stat_parsed_type);
    if(PARSE_DEBUG) printf("year_parsed_flag = %d, year_parsed = %d, month_parsed_flag = %d, month_parsed = %d\n", args.year_parsed_flag, args.year_parsed, args.month_parsed_flag, args.month_parsed);
    return 0;
}
