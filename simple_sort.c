#include "my_std.h"

// 하나 지정하고 남은 풀중에서 비교하면서 탐색함
void bubble(List **list_a, List **list_b)
{
    int len;

    // 비교를 위해 다른 변수에 빼두거나 탐색할게 아니라면 비교대상을 b에 빼두는식으로 채용
    print_with_push(list_b, list_a, "pb");
    
    while(*list_a != NULL)
    {
        // stack_print(*list_a, *list_b);
        // 순환 리스트라 끝을 따로 지정하지 않았으니 남은 풀의 갯수를 알아내기
        len = count_node(*list_a);
        while(len > 0)
        {
            // 조건검사 + 위치교환
            swap_other_node(list_a, list_b);
            --len;
            // 다음 노드로
            print_with_reverse_rotate(*list_a, "rra");
        }
        // 새로운 검사대상 지정
        print_with_push(list_b, list_a, "pb");
    }
    // 정렬된걸 다시 돌려넣음
    while(*list_b != NULL)
        print_with_push(list_a, list_b, "pa");
}

// 일단 넘긴 풀(list b)에서 자리잡는 스타일
void selection(List **list_a, List **list_b)
{
    int len;

    while(*list_a != NULL)
    {
        print_with_push(list_b, list_a, "pb");
        len = count_node(*list_b) - 1;
        while(len > 0)
        {
            if((*list_b)->num > (*list_b)->next->num)
            {
                print_with_swap(*list_b, "sb");
                // stack_print(*list_a, *list_b);
            }
            print_with_rotate(*list_b, "rb");
            // stack_print(*list_a, *list_b);
            --len;
        }
        print_with_rotate(*list_b, "rb");
    }

    while(*list_b != NULL)
        print_with_push(list_a, list_b, "pa");
}
// 넣기전에 가장 큰/작은애를 찾아서 넣는 스타일
void insert(List **list_a, List **list_b)
{
    int len;

    while(*list_a != NULL)
    {
        // stack_print(*list_a, *list_b);
        len = count_node(*list_a);
        while(len > 0)
        {
            if((*list_a)->num > (*list_a)->next->num)
            {
                // stack_print(*list_a, *list_b);
                print_with_swap(*list_a, "sa");
                // stack_print(*list_a, *list_b);
            }
            --len;
            print_with_rotate(*list_a, "ra");
        }
        print_with_push(list_b, list_a, "pb");
    }

    while(*list_b != NULL)
        print_with_push(list_a, list_b, "pa");
}
