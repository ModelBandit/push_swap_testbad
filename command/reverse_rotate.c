#include "print_command.h"


void print_with_reverse_rotate(List *head, const char *str)
{
    ft_putendl_fd((char*)str, 1);
    reverse_rotation(head);
    ++count;
}

// TAIL TO HEAD
void print_with_reverse_rotaterotate(List *list_a, List *list_b)
{
    ft_putendl_fd("rrr", 1);
    reverse_rotation(list_a);
    reverse_rotation(list_b);
    ++count;
}