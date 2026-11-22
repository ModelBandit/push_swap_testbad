#ifndef COMMON_HEADER
#define COMMON_HEADER
#include "../data_structure/my_list.h"
#include "../libft/libft.h"
#endif

extern int compare_count;

extern int push_count;
extern int swap_count;
extern int rot_rrot_count;

extern int command_count;

// sa, sb
void print_with_swap(List *head, const char *str);
// ss
void print_with_swapswap(List *list_a, List *list_b);

// pa, pb
void print_with_push(List **dst, List **src, const char *str);

/* ra rb
HEAD TO TAIL
*/
void print_with_rotate(List **head, const char *str);
/* rr
HEAD TO TAIL
*/
void print_with_rotaterotate(List **list_a, List **list_b);
/* rra rrb
TAIL TO HEAD
*/
void print_with_reverse_rotate(List **head, const char *str);
/* rrr
TAIL TO HEAD
*/
void print_with_reverse_rotaterotate(List **list_a, List **list_b);

void swap_other_node(List **node_a, List **node_b);

int count_compare();

void print_count();

void print_command_count();

void print_compare_count();

void print_push_count();
void print_swap_count();
void print_rot_count();