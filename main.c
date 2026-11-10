#include "my_std.h"
#define NUM_ARR 5

void customEnv();

int main()
{
    srand(time(NULL));
    List *list_a = build_List(build_number_array(NUM_ARR), NUM_ARR);
    List *list_b = build_List(build_number_array(NUM_ARR), NUM_ARR);
    char input[4] = "012";

    while(ft_strncmp(input, "ext", 4) != 0)
    {
        stack_print(list_a, list_b);
        printf("%s\n", input);
        scanf("%s", input);
        if(input[0] == 's')
        {
            if(input[1] == 'a' && list_a != NULL)
            {
                swap(list_a);
            }
            else if(input[1] == 'b' && list_b != NULL)
            {
                swap(list_b);
            }
            else if(input[1] == 's')
            {
                if(list_a != NULL)
                {
                    swap(list_a);
                }
                if(list_b != NULL)
                {
                    swap(list_b);
                }
            }
        }
        else if(input[0] == 'p')
        {
            if(input[1] == 'a' && list_b != NULL)
            {
                push_back(&list_a, pop(list_b));
            }
            else if(input[1] == 'b')
            {
                push_back(&list_b, pop(list_a));
            }
        }
        else if(ft_strlen(input) == 2 && input[0] == 'r')
        {
            if(input[1] == 'a' && list_a != NULL)
            {
                rotation(list_a);
            }
            else if(input[1] == 'b' && list_b != NULL)
            {
                rotation(list_b);
            }
            else if(input[1] == 'r')
            {
                if(list_a != NULL)
                    rotation(list_a);
                if(list_b != NULL)
                    rotation(list_b);
            }
        }
        else if(ft_strncmp(input, "rr", 2) != 0)
        {
            if(input[2] == 'a' && list_a != NULL)
            {
                reverse_rotation(list_a);
            }
            else if(input[2] == 'b' && list_b != NULL)
            {
                reverse_rotation(list_b);
            }
            else if(input[2] == 'r')
            {
                if(list_a != NULL)
                    reverse_rotation(list_a);
                if(list_b != NULL)
                    reverse_rotation(list_b);
            }
        }
        else
        {
            printf("error %s\n", input);
        }
    }
    return 0;
}

void customEnv()
{
    List *list_a = build_List(build_number_array(NUM_ARR), NUM_ARR);
    List *list_b = NULL;

    // while()
    visual_print(list_a, list_b, 1);

    clear_list(&list_a);
    clear_list(&list_b);
}