#include "print_command.h"


// HEAD TO TAIL
void print_with_rotate(List *head, const char *str)
{
    ft_putendl_fd((char*)str, 1);
    rotation(head);
    ++command_count;
    ++rot_rrot_count;
}

// HEAD TO TAIL
void print_with_rotaterotate(List *list_a, List *list_b)
{
    ft_putendl_fd("rr", 1);
    rotation(list_a);
    rotation(list_b);
    ++command_count;
    ++rot_rrot_count;
}