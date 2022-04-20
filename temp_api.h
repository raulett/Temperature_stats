#ifndef TEMP_API_H
#define TEMP_API_H

#include <stdint.h>
#include <inttypes.h>
#include "temp_struct.h"


int compare_datetime(const void *, const void *);
int8_t average_temp(tmp_list *);
int8_t min_temp(tmp_list *);
int8_t max_temp(tmp_list *);
uint32_t select_period(tmp_list *);

#endif