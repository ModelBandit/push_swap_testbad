#include "other_lib/my_list.h"
#include "libft/libft.h"

#define MY_RANDOM_RANGE 1000
#define RAND_VALUE (rand() % MY_RANDOM_RANGE) - (MY_RANDOM_RANGE*0.5)


int init_list(char **list, char *arg_str);
void parr_release(char **strs);
int my_notint(const char *str);

// visual
int* build_number_array(size_t size);
List *build_List(int *nums, size_t nums_size);
void stack_print(List *list_a, List *list_b);
void visual_print(List *list_a, List *list_b, int fd);
void clear_list(List **list);