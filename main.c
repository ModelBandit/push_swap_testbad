#include "my_std.h"
#include <time.h>

int compare_count = 0;

int push_count = 0;
int swap_count = 0;
int rot_rrot_count = 0;

int command_count = 0;
/* 제출용 프로그램

*/
int main(int argc, char **argv)
{
    List *list_a;
    List *list_b;

    list_a = NULL;
    list_b = NULL;

    // 대충 그냥 컴파일 때렸다는 뜻
    if(argc == 1)
    {
        list_a = build_List(build_number_array(NUM_ARR), NUM_ARR);
    }
    else
    {
        if(init(&list_a, &list_b, argc, argv))
            return 1;
    }
    
    // 초기상태 체크용
    stack_print(list_a, list_b);

    // 대충 그냥 컴파일 때렸다는 뜻
    if(argc == 1)
    {
        // simple
        bubble(&list_a);
        // selection(&list_a);
        // insert(&list_a, &list_b);
        // my_merge(&list_a, &list_b, 0, count_node(list_a)-1);
    }
    else
    {
        if(ft_strncmp(argv[1], "--simple", ft_strlen(argv[1])) == 0)
            insert(&list_a, &list_b);
    }
    // 정렬상태 검사용
    stack_print(list_a, list_b);
    // 명령어 호출 횟수 카운터
    print_count();

    // 메모리 해제
    clear_list(&list_a);
    clear_list(&list_b);
}

