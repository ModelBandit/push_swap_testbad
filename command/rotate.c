#include "print_command.h"


void print_with_rotate(List *head, const char *str)
{
    ft_putendl_fd((char*)str, 1);
    rotation(head);
    ++count;
}

void print_with_rotaterotate(List *list_a, List *list_b)
{
    ft_putendl_fd("rr", 1);
    rotation(list_a);
    rotation(list_b);
    ++count;
}