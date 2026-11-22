#include "../my_std.h"
#include <stdio.h>


void my_merge(List **list_a, List **list_b, int min, int max)
{
    List *left_p;
    List *right_p;
    //핵심 분할 정복
    printf("min/max: %d / %d\n", min, max);
    
    // 정렬 범위. min - max가 0이면 분할 종료
    if(min == max)
        return;
    
    /* 퀵이나 병합의 컨셉은 분할정복
    병합에서의 분할 과정은 아래와 같음
    일반적으로 그냥 정렬하면 n개의 정렬대상이 생김
    이걸 최소단위까지 두 부분으로 쪼개기를 반복함.
    처음에는 n/2 n/2 로 시작해서 그 크기가 n/n까지 작아짐.
    */
    // stack_print(*list_a, *list_a);
    my_merge(list_a, list_b, min, min+(max - min)/2);
    // stack_print(*list_a, *list_a);
    my_merge(list_a, list_b, (min+(max - min)/2)+1, max);
    
    /*
    쪼갠거까지는 좋은데 역시나 stack이라는 명령어 기반으로 움직여야하는 구조문제로 또 문제가 생김
    흔한 예시대로면 현재 범위 내에서 작은거부터 쌓아두면 됨.
    문제는 찾는거 까지는 그렇게한다쳐도 결국 rot pop/swap을 쓰는건 같음
    */

    left_p = *list_a;
    right_p = *list_a;
   // 시작지점 셋팅
    int merge_rot = 0;
    int i = 0;
    for(; i < min; ++i) // 분할된 것들의 좌측 그룹 시작점
    {
        left_p = left_p->next;
        print_with_rotate(list_a, "ra"); // 이런식으로 돌려두지않으면 나중에 중간껄 다시 넣고 정렬할 근거 자료가 없음
        ++merge_rot;
    }
    int j = 0;
    for(; j < min+(max - min)/2+1; ++j) // 분한된 것들의 우측 그룹 시작점
    {
        right_p = right_p->next;
    }
    /* 상황
    원하는 정렬 반대 형태(역정렬)로 B에서 넣으면 정리하고 다시 A로 빼기
    삽입정렬한거 벤치마크 때린거 맞음
    다만 이중반복시 표면상 시간복잡도가 O(n^2)이 되어버리니 한번에 치워야함
    test1
    */
    /* test 1: 그냥 넣으려하니 만약 8개의 노드에서 앞에 2개로만 정렬하려고하니 문제가 생김
        a1. 각 시작점인 min, min+(max - min)/2)+1 번째 노드를 가르키는 노드를 기반으로 비교
    */
    /* test 2: 변수를 더 쓰기로함. 상부에 List포인터 두개 -> 굳이 두개인 이유. 하나로는 내가 헷갈려서
        a2. 해당 지점 처리는 가능해짐. 다만 찾아서 비교해도 결국 넣으려면 루프를 돌아서 list_a가 해당 노드 위치로 가야함.
    */
    int rot_count = 0;
    for(; i <= min+(max - min)/2 && j <= max;)
    {
        stack_print(*list_a, *list_b);
        if(count_compare() && left_p->num < right_p->num)
        {
            while((*list_a)->num != left_p->num)
            {
                print_with_rotate(list_a, "ra");
                ++rot_count;
            }
            left_p = left_p->next;
            ++i;
        }
        else
        {
            while((*list_a)->num != right_p->num)
            {
                print_with_rotate(list_a, "ra");
                ++rot_count;
            }
            right_p = right_p->next;
            ++j;
        }
        // stack_print(*list_a, *list_b);
        print_with_push(list_b, list_a, "pb");
        // stack_print(*list_a, *list_b);
        while(rot_count > 0)
        {
            print_with_reverse_rotate(list_a, "rra");
            --rot_count;
        }
    }
    while(i <= min+(max - min)/2)
    {
        while((*list_a)->num != left_p->num)
            print_with_rotate(list_a, "ra");
        left_p = left_p->next;
        print_with_push(list_b, list_a, "pb");
        ++i;
    }
    while(j <= max)
    {
        while((*list_a)->num != right_p->num)
            print_with_rotate(list_a, "ra");
        right_p = right_p->next;
        print_with_push(list_b, list_a, "pb");
        ++j;
    }
    while(*list_b != NULL)
    {
        print_with_push(list_a, list_b, "pa");
    }
    // 새로 넣었으니 돌려두기
    while(merge_rot > 0)
    {
        print_with_reverse_rotate(list_a, "rra");
        --merge_rot;
    }

    // printf("s---min/max: %d / %d\n", min, max);
    // stack_print(*list_a, *list_a);
    // printf("e---min/max: %d / %d\n", min, max);
}
