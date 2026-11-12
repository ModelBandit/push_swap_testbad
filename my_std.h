#include "command/print_command.h"

#ifndef COMMON_HEADER
#define COMMON_HEADER
#include "data_structure/my_list.h"
#include "libft/libft.h"
#endif

// 랜덤 배열 생성용
#define NUM_ARR 100
#define MY_RANDOM_RANGE 1000
#define RAND_VALUE (rand() % MY_RANDOM_RANGE) - (MY_RANDOM_RANGE*0.5)

// subject init
int init(List **list_A, List **list_B, int argc, char **argv);
int init_list(List **list, char *arg_str);
void parr_release(char **strs);
int my_notint(const char *str);
int check_intedge(const char *str);
int progress_cmp(const char *origin, const char *other);

// simple sort
void bubble(List **list_a, List **list_b);

// visual
int* build_number_array(size_t size);
List *build_List(int *nums, size_t nums_size);
void stack_print(List *list_a, List *list_b);
void visual_print(List *list_a, List *list_b, int fd);
void clear_list(List **list);