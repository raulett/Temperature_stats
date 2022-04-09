#ifndef TEMP_API_H
#define TEMP_API_H

#include <stdint.h>
#include "temp_struct.h"


int compare_datetime(const void *, const void *);
int8_t average_mon_temp(struct temp_arr, uint8_t, uint16_t);
int8_t min_mon_temp(struct temp_arr, uint8_t, uint16_t);
int8_t max_mon_temp(struct temp_arr, uint8_t, uint16_t);
int8_t average_year_temp(struct temp_arr, uint16_t);
int8_t min_year_temp(struct temp_arr, uint16_t);
int8_t max_year_temp(struct temp_arr, uint16_t);

#endif