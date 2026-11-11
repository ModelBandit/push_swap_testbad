#include "my_std.h"

/* 제출용 프로그램

*/
int main(int argc, char **argv)
{
    List *list_a;
    List *list_b;
    int i;

    i = 1;
    if(ft_strncmp(argv[1], "--", 3) == 0)
        i = 2;
    
    while(i < argc)
    {
        ft_putnbr_fd(i, 1);
        ft_putstr_fd(": ", 1);
        ft_putendl_fd(argv[i], 1);

        if(init_list(&list_a, argv[i]) == 1)
        {
            ft_putendl_fd("Error", 2);
            return 1;
        }

        ++i;
    }
    if(init_list(&list_b, NULL) == 1)
    {
        ft_putendl_fd("Error", 2);
        return 1;
    }



    return 0;
}
