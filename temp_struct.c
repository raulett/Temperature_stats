#include "temp_struct.h"
#include <stdlib.h>
#include <stdio.h>
#define DEBUG 1
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

void del_element(tmp_list **prev_t_list, tmp_list **current)
{
    tmp_list *temp_current_next;
    temp_current_next = (*current)->next;
    free(*current);
    *current = temp_current_next;
    if (*prev_t_list != NULL){
        (*prev_t_list)->next = *current;
    }

}


// void push_test(test_list **t_list, int digit)
// {
//     test_list *t_record;
//     t_record = malloc(sizeof(test_list));
//     if (DEBUG_TEST) printf("push_test t_list input addr %p\n", *t_list);
//     t_record->digit = digit;
//     t_record->next = *t_list;
//     *t_list = t_record;
//     if (DEBUG_TEST) printf("push_test t_list addr after %p\n", *t_list);
// }

// int pop_test(test_list **t_list)
// {
//     test_list *t_record = *t_list;
//     int t_data;
//     t_data = t_record->digit;
//     *t_list = t_record->next;
//     free(t_record);
//     return t_data;
// }

// _Bool test_is_list_empty(test_list *t_list)
// {
//     return t_list==NULL;
// }
