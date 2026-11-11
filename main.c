#include "my_std.h"

int count = 0;
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
    
    stack_print(list_a, list_b);
    // if(ft_strncmp(argv[1], "--simple", ft_strlen(argv[1])) == 0)
        bubble(&list_a, &list_b);
    print_count_init();
    stack_print(list_a, list_b);

}

