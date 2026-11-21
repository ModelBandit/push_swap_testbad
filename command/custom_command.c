#include "print_command.h"
#include <stdio.h>

/* NOT using
최대/최솟값을 b로 옮겨두고 교환하는 스타일에서 쓰던 함수
명령어 호출량이 너무 많이 치솟음.
*/
void swap_other_node(List **node_a, List **node_b)
{
    if(*node_a == NULL || *node_b == NULL)
        return;
    if((*node_a)->num > (*node_b)->num)
    {
        print_with_push(node_a, node_b, "pa");
        print_with_swap(*node_a, "sa");
        print_with_push(node_b, node_a, "pb");
    }
}

int count_compare()
{
    ++compare_count;
    return 1;
}

void print_count()
{
    print_compare_count();

    print_push_count();
    print_swap_count();
    print_rot_count();

    print_command_count();
}

void print_command_count()
{
    ft_putstr_fd("commands: ", 1);
    ft_putnbr_fd(command_count, 1);
    ft_putchar_fd('\n', 1);
    command_count = 0;   
}

void print_compare_count()
{
    ft_putstr_fd("compare: ", 1);
    ft_putnbr_fd(compare_count, 1);
    ft_putchar_fd('\n', 1);
    compare_count = 0;   
}

void print_push_count()
{
    ft_putstr_fd("push: ", 1);
    ft_putnbr_fd(push_count, 1);
    ft_putchar_fd('\n', 1);
    push_count = 0;   
}
void print_swap_count()
{
    ft_putstr_fd("swap: ", 1);
    ft_putnbr_fd(swap_count, 1);
    ft_putchar_fd('\n', 1);
    swap_count = 0;   
}

void print_rot_count()
{
    ft_putstr_fd("rot_rrot: ", 1);
    ft_putnbr_fd(rot_rrot_count, 1);
    ft_putchar_fd('\n', 1);
    rot_rrot_count = 0;   
}
