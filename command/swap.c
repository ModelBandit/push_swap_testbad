#include "print_command.h"


void print_with_swap(List *head, const char *str)
{
    ft_putendl_fd((char*)str, 1);
    swap(head);
    ++count;
}

void print_with_swapswap(List *list_a, List *list_b)
{
    ft_putendl_fd("ss", 1);
    swap(list_a);
    swap(list_b);
    ++count;
}
