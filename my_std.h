#include "other_lib/my_list.h"
#include <time.h>

int* build_number_array(size_t size);
List *build_List(int *nums, size_t nums_size);
void visual_print(List *list_a, List *list_b, int fd);
void clear_list(List **list);