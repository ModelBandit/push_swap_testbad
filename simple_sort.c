#include "my_std.h"

void bubble(List **list_a, List **list_b)
{
    int len;

    if(*list_b == NULL)
        print_with_push(list_b, list_a, "pb");
    
    while(*list_a != NULL)
    {
        // stack_print(*list_a, *list_b);
        len = count_node(*list_a);
        while(len > 0)
        {
            swap_other_node(list_a, list_b);
            --len;
            print_with_reverse_rotate(*list_a, "rra");
        }
        print_with_push(list_b, list_a, "pb");
    }
    while(*list_b != NULL)
        print_with_push(list_a, list_b, "pa");
}
