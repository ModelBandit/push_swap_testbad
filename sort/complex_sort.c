#include "../my_std.h"
#include <stdio.h>

void my_merge(List **list_a, List **list_b, int min, int max)
{
    printf("min/max: %d / %d\n", min, max);
    if(min >= max)
        return;
    
    // stack_print(*list_a, *list_a);
    my_merge(list_a, list_b, min, min+(max - min)/2);
    // stack_print(*list_a, *list_a);
    my_merge(list_a, list_b, (min+(max - min)/2)+1, max);
    
    int i = 0;
    for(; i < min; ++i)
    {
        print_with_rotate(*list_a, "ra");
    }
    for(; i <= max; ++i)
    {
        print_with_push(list_b, list_a, "pb");
    }
    for(; i > min; --i)
    {
        print_with_reverse_rotate(*list_a, "rra");
    }

    printf("s---min/max: %d / %d\n", min, max);
    stack_print(*list_a, *list_a);
    printf("e---min/max: %d / %d\n", min, max);
}