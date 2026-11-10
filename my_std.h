#include "other_lib/my_list.h"
#include <stdio.h>
#include <time.h>
#define MY_RANDOM_RANGE 1000
#define RAND_VALUE (rand() % MY_RANDOM_RANGE) - (MY_RANDOM_RANGE*0.5)

int* build_number_array(size_t size);
List *build_List(int *nums, size_t nums_size);
void stack_print(List *list_a, List *list_b);
void visual_print(List *list_a, List *list_b, int fd);
void clear_list(List **list);