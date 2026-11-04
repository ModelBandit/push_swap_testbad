#include "my_std.h"
#define MY_RANDOM_RANGE 1000

// 받은 인자의 크기만큼 배열반환
int* build_number_array(size_t size)
{
    int *nums = malloc(sizeof(int) * size);

    srand(time(NULL));
    
    // 랜덤값 추가
    for(size_t i = 0; i < size; ++i)
    {
        // rand 반환값이 0 ~ 2147483647. modulo로 RANGE에 맞춰주고 0 기준으로 음수 표현도 가능하게 RANGE계산 추가
        nums[i] = (rand() % MY_RANDOM_RANGE) - (MY_RANDOM_RANGE*0.5);
    }

    // 중복검사
    for(size_t i = 0; i < size - 1; ++i)
    {
        for(size_t j = i + 1; j < size; ++j)
        {
            if(nums[i] == nums[j])
                nums[i] = (rand() % MY_RANDOM_RANGE) - ((MY_RANDOM_RANGE)*0.5); // 또 겹치면 뭐 안타까운거지
        }
    }

    return nums;
}

// int 배열을 받아서 list생성 후 int 배열을 해제
List *build_List(int *nums, size_t nums_size)
{
    List *list = NULL;
    for(size_t i = 0; i < nums_size; ++i)
    {
        push_back(&list, create_node(nums[i]));
    }

    free(nums);
    return list;
}

// 그냥 출력용으로 막찍은 함수
void visual_print(List *list_a, List *list_b, int fd)
{
    List *cur_a = list_a;
    List *cur_b = list_b;
    int i = 0;

    ft_putstr_fd("\e[43m", fd);
    while(cur_a != NULL && cur_a->next != list_a)
    {
        ft_putstr_fd("                                ", fd);
        cur_a = cur_a->next;
    }
    ft_putendl_fd("\e[0m", fd);
    cur_a = list_a;

    ft_putstr_fd("stack A:\t", fd);
    while(cur_a != NULL && cur_a->next != list_a)
    {
        ft_putchar_fd('(', fd);
        ft_putnbr_fd(i++, fd);
        ft_putchar_fd(')', fd);
        ft_putnbr_fd(cur_a->num, fd);
        ft_putstr_fd("\t│\t", fd);
        cur_a = cur_a->next;
    }
    if(cur_a != NULL)
    {
        ft_putchar_fd('(', fd);
        ft_putnbr_fd(i, fd);
        ft_putchar_fd(')', fd);
        ft_putnbr_fd(cur_a->num, fd);
    }
    ft_putchar_fd('\n', fd);

    i = 0;
    ft_putstr_fd("stack B:\t", fd);
    while(cur_b != NULL && cur_b->next != list_b)
    {
        ft_putchar_fd('(', fd);
        ft_putnbr_fd(i++, fd);
        ft_putchar_fd(')', fd);
        ft_putnbr_fd(cur_b->num, fd);
        ft_putstr_fd("\t│\t", fd);
        cur_b = cur_b->next;
    }
    if(cur_b != NULL)
    {
        ft_putchar_fd('(', fd);
        ft_putnbr_fd(i, fd);
        ft_putchar_fd(')', fd);
        ft_putnbr_fd(cur_b->num, fd);
    }
    ft_putchar_fd('\n', fd);

    cur_a = list_a;
    ft_putstr_fd("\e[43m", fd);
    while(cur_a != NULL && cur_a->next != list_a)
    {
        ft_putstr_fd("                                ", fd);
        cur_a = cur_a->next;
    }
    ft_putendl_fd("\e[0m", fd);
}

void clear_list(List **list)
{
    if(list == NULL || *list == NULL)
        return;
        
    List *cur= (*list);
    while(cur->next != (*list))
    {
        cur = cur->next;
        free(cur);
    }
    free(*list);
    *list = NULL;
}