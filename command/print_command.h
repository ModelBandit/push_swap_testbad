#ifndef COMMON_HEADER
#define COMMON_HEADER
#include "../data_structure/my_list.h"
#include "../libft/libft.h"
#endif

extern int count;

// sa, sb
void print_with_swap(List *head, const char *str);
// ss
void print_with_swapswap(List *list_a, List *list_b);

// pa, pb
void print_with_push(List **dst, List **src, const char *str);

/* ra rb
HEAD TO TAIL
*/
void print_with_rotate(List *head, const char *str);
/* rr
HEAD TO TAIL
*/
void print_with_rotaterotate(List *list_a, List *list_b);
/* rra rrb
TAIL TO HEAD
*/
void print_with_reverse_rotate(List *head, const char *str);
/* rrr
TAIL TO HEAD
*/
void print_with_reverse_rotaterotate(List *list_a, List *list_b);

void swap_other_node(List **node_a, List **node_b);
void print_count_init();