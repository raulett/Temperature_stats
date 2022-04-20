#ifndef READ_TEMPERATURE_FILE_H
#define READ_TEMPERATURE_FILE_H
#include "temp_struct.h"
#include <stdio.h>


uint32_t read_temperature_file(FILE*, tmp_list**);
int readline(FILE*, temperature*);

#endif