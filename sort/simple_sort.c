#include "../my_std.h"

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

    // n개의 content가 정렬할때까지
    while(sorted_count < len)
    {
        // stack_print(*list_a, *list_a);
        i = 0;
        // 정렬안한 List 노드 수 만큼
        while(i < len - sorted_count)
        {
            // stack_print(*list_a, *list_a);
            // 현재 HEAD와 HEAD->next를 비교하여 큰값을 next로 보냄
            if(count_compare() && (*list_a)->num > (*list_a)->next->num)
            {
                print_with_swap(*list_a, "sa");
                // stack_print(*list_a, *list_a);
            }
            // 그렇게 HEAD와 HEAD->next 중 작은 놈은 TAIL로 가게됨
            print_with_rotate(list_a, "ra");
            ++i;
        }
        /*
        이쯤 왔다면 가장 큰 값이 현재 HEAD에 있음
        그래서 정렬된 수 만큼 뒤로 다시 넘겨버리는 작업을 진행함.
        */
        i = 0;
        ++sorted_count; // 점점 커지면서 정렬된 갯수가 늘어난 만큼 탐색을 덜 돌게되면서 그만큼 뒤로 넘겨줘야 함.
        // stack_print(*list_a, *list_a);
        while(i < sorted_count)
        {
            print_with_rotate(list_a, "ra");
            ++i;
        }
        // stack_print(*list_a, *list_a);
    }
}

void selection(List **list_a)
{
    // 대상 지정용 변수 2개
    int target_value;
    int target_index;

    int len = count_node(*list_a);
    int i;
    int sorted_count = 0;

    // 여전히 버블과 마찬가지로 같은 자료형 내에서 돌아감.
    while(sorted_count < len)
    {
        // stack_print(*list_a, *list_b);
        target_value = 0; // 지정된 값이 없으니 그냥 아무값이나
        target_index = -1; // 위치 특정 위한 변수. 일단은 불가능한 값으로
        i = 0;
        while(i < len - sorted_count)
        {
            // stack_print(*list_a, *list_b);
            // index가 -1 이거나 지정된 밸류값이 현재 HEAD보다 클 때
            if( (target_index == -1 || (count_compare() && target_value < (*list_a)->num)))
            {
                target_value = (*list_a)->num; // 이 대상을 target으로 지정함.
                target_index = i; // 나중에 rot로 따라가봐야하니 index도 저장함.
            }
            (*list_a) = (*list_a)->next;
            ++i;
        }
        // stack_print(*list_a, *list_a);
        // 한바퀴 돌면서 대상 선정했으니 해당 대상을 HEAD로 올림
        while((*list_a)->num != target_value) 
        {
            // 그냥 rot 명령어 적게써보려는 몸부림.
            if(target_index < len / 2)
                print_with_rotate(list_a, "ra");
            else
                print_with_reverse_rotate(list_a, "rra");
        }
        // stack_print(*list_a, *list_a);
        // target_index + sorted_count 와 len -1
        // 즉 정렬안된 노트 중 가장 큰 값을 가진 노드부터 TAIL까지
        while(len - 1 > target_index + sorted_count)
        {
            // swap rot를 반복하여 뒤로 쭉 빼냄
            print_with_swap(*list_a, "sa");
            print_with_rotate(list_a, "ra");
            ++target_index;
        }
        // 최종적으로 가장 큰 값은 정렬안된 노드 중 가장 끝(정렬노드의 최상단)에 위치하게됨
        i = 0;
        ++sorted_count;
        // stack_print(*list_a, *list_a);
        // 버블때와 마찬가지로 현재 HEAD는 정렬된 값이니 다시 뒤로 넘겨서 다음 비교를 준비함.
        while(i < sorted_count)
        {
            print_with_rotate(list_a, "ra");
            ++i;
        }
        // stack_print(*list_a, *list_a);
        // print_count();

        // 만약 타겟 머시기가 두개씩이나 필요한가 싶다면 니말이 맞음.
        // 해보겠다면 명령어(p○,s○, r○, rr○ 중) 하나를 개선하면 대상특정은 하나면 될거임.
        // 괴장히 과도하게 도는 명령어가 하나 있음 
    }
}

void insert(List **list_a, List **list_b)
{
    int rot_count;

    // 일단 빈칸 찾아서 옮기고 보는건데 처음에는 든게 없어서 하나 넣음
    // 컨셉에 따라서 b는 반드시 정렬된 List로 구성됨.
    print_with_push(list_b, list_a, "pb");
    while(*list_a != NULL)
    {
        // stack_print(*list_a, *list_b);
        // 최대 rot 횟수 제한
        rot_count = count_node(*list_b) - 1;
        while(rot_count >= 0)
        {
            // list_a 와 list_b의 각 HEAD를 비교하여 a의 값이 크면 반복문 종료
            if(count_compare() && (*list_a)->num > (*list_b)->num)
                break;
            // rot를 돌며 a의 HEAD가 B에 안맞는다면 B의 크기만큼 순회함.
            print_with_rotate(list_b, "rb");
            --rot_count;
        }
        // 싹 돌았다면(아니면 적당한 위치에서 break에 걸렸다면) b값 추가
        print_with_push(list_b, list_a, "pb");
        // 현 HEAD의 next, prev 전부 작은 값이다 == 현 HEAD가 가장 크다
        while((*list_b)->num < (*list_b)->next->num
           || (*list_b)->num < (*list_b)->prev->num)
            print_with_rotate(list_b, "rb");// 그런 HEAD가 될때까지 rot 반복

        // stack_print(*list_a, *list_b);
    }

    // B에 HEAD가 큰걸로 정렬했으니 A로 옮긴다. 구조 특성상 큰 순에서 작은 순으로 정렬됨
    while(*list_b != NULL)
        print_with_push(list_a, list_b, "pa");
}
