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

void print_count_init()
{
    ft_putstr_fd("commands: ", 1);
    ft_putnbr_fd(count, 1);
    ft_putchar_fd('\n', 1);
    count = 0;   
}