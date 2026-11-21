#include "print_command.h"


void print_with_push(List **dst, List **src, const char *str)
{
    ft_putendl_fd((char*)str, 1);
    push_back(dst, pop(src));
    ++command_count;
    ++push_count;
}

