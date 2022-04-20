#include "temp_struct.h"
#include <stdlib.h>
#include <stdio.h>
#define DEBUG 0
#define DEBUG_TEST 0

void  push_temperature(tmp_list **t_list, temperature t_data)
{
    if (DEBUG) printf("push t_list ptr before push: %p\n", *t_list);
    tmp_list *t_record;
    t_record = malloc(sizeof(tmp_list));
    t_record->data = t_data;
    t_record->next = *t_list;
    *t_list = t_record;  
    if (DEBUG) printf("push t_list ptr after push: %p\n", *t_list);
}

_Bool is_list_empty(tmp_list *t_list)
{
    return t_list==NULL;
}

temperature pop(tmp_list **t_list)
{
    tmp_list *t_record = *t_list;
    temperature t_data;
    t_data = t_record->data;
    *t_list = t_record->next;
    free(t_record);
    return t_data;
}

