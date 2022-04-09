#ifndef PARSE_ARGS_H
#define PARSE_ARGS_H

#include <inttypes.h>

typedef struct parsed_args{
    uint8_t args_parsed_flag:4;
    uint8_t in_file_parsed_flag:1;
    FILE *in_file;
    uint8_t stat_parsed_flag:1;
    uint8_t stat_parsed_type:2; //stat parsed type 0 - parse error, 1 - average, 2 - min, 3 - max
    uint8_t year_parsed_flag:1;
    uint16_t year_parsed;
    uint8_t month_parsed_flag:1;
    uint8_t month_parsed;
};

struct parsed_args get_arguments_parsed(int, char**);
int parse_pos_int(char*);

#endif
