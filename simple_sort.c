#include "my_std.h"

/* 조건 v2
데이터 탐색은 next/prev로 가능
사유: 탐색까지 명령어로 한다쳐도 결국 변수를 하나 쓰거나 next/prev를 써야하니 채택

데이터 이동은 명령어를 기반으로 작업

문제: rot swap이나 pop push로 컨트롤해야되다보니 교환이 번거로움
*/

void bubble(List **list_a)
{
    int len = count_node(*list_a) - 1;
    int sorted_count = 0;
    int i;

    while(len - sorted_count > 0)
    {
        // stack_print(*list_a, *list_a);
        i = 0;
        while(i < len - sorted_count)
        {
            // stack_print(*list_a, *list_a);
            if((*list_a)->num > (*list_a)->next->num)
            {
                print_with_swap(*list_a, "sa");
                // stack_print(*list_a, *list_a);
            }
            print_with_rotate(*list_a, "ra");
            ++i;
        }
        i = 0;
        ++sorted_count;
        // stack_print(*list_a, *list_a);
        while(i < sorted_count)
        {
            print_with_rotate(*list_a, "ra");
            ++i;
        }
        // stack_print(*list_a, *list_a);
    }
}

void selection(List **list_a)
{
    int target_value;
    int target_index;
    int len = count_node(*list_a);
    int i;
    int sorted_count = 0;

    while(sorted_count < len)
    {
        // stack_print(*list_a, *list_b);
        target_value = 0;
        target_index = -1;
        i = 0;
        while(i < len - sorted_count)
        {
            // stack_print(*list_a, *list_b);
            if(target_index == -1 || target_value < (*list_a)->num)
            {
                target_value = (*list_a)->num;
                target_index = i;
            }
            (*list_a) = (*list_a)->next;
            ++i;
        }
        // stack_print(*list_a, *list_a);
        while((*list_a)->num != target_value) 
        {
            if(target_index < len / 2)
                print_with_rotate(*list_a, "ra");
            else
                print_with_reverse_rotate(*list_a, "rra");
        }
        // stack_print(*list_a, *list_a);
        while(len - 1 > target_index + sorted_count)
        {
            print_with_swap(*list_a, "sa");
            print_with_rotate(*list_a, "ra");
            ++target_index;
        }
        i = 0;
        ++sorted_count;
        // stack_print(*list_a, *list_a);
        while(i < sorted_count)
        {
            print_with_rotate(*list_a, "ra");
            ++i;
        }
        // stack_print(*list_a, *list_a);
    }
}

void insert(List **list_a, List **list_b)
{
    int rot_count;

    print_with_push(list_b, list_a, "pb");
    while(*list_a != NULL)
    {
        // stack_print(*list_a, *list_b);
        rot_count = count_node(*list_b) - 1;
        while(rot_count >= 0)
        {
            if((*list_a)->num > (*list_b)->num)
                break;
            print_with_rotate(*list_b, "rb");
            --rot_count;
        }
        print_with_push(list_b, list_a, "pb");
        while((*list_b)->num < (*list_b)->next->num
           || (*list_b)->num < (*list_b)->prev->num)
            print_with_rotate(*list_b, "rb");

        // stack_print(*list_a, *list_b);
    }

    while(*list_b != NULL)
        print_with_push(list_a, list_b, "pa");
}
