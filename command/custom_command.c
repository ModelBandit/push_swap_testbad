#include "print_command.h"


void swap_other_node(List **node_a, List **node_b)
{
    List *temp1;
    List *temp2;
    if(*node_a == NULL || *node_b == NULL)
        return;

    temp1 = pop(node_a);
    temp2 = pop(node_b);
    if(temp1->num > temp2->num)
    {
        print_with_push(node_a, &temp2, "pa");
        print_with_push(node_b, &temp1, "pb");
    }
    else
    {
        print_with_push(node_a, &temp1, "pa");
        print_with_push(node_b, &temp2, "pb");
    }
}

void print_count_init()
{
    ft_putstr_fd("commands: ", 1);
    ft_putnbr_fd(count, 1);
    ft_putchar_fd('\n', 1);
    count = 0;   
}