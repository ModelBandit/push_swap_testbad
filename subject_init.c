#include "my_std.h"

int init(List **list_a, List **list_b, int argc, char **argv)
{
    int i;

    i = 1;
    if(ft_strncmp(argv[1], "--", 3) == 0)
        i = 2;
    while(i < argc)
    {
        if(init_list(list_a, argv[i]) == 1)
        {
            ft_putendl_fd("Error", 2);
            return 1;
        }

        ++i;
    }
    if(init_list(list_b, NULL) == 1)
    {
        ft_putendl_fd("Error", 2);
        return 1;
    }
    return 0;
}

int init_list(List **list, char *arg_str)
{
    char **strs;
    int i;

    if(arg_str == NULL)
    {
        *list = NULL; 
        return 0;
    }
    strs = ft_split(arg_str, ' ');
    i = 0;
    while(strs[i] != NULL)
    {
        if(my_notint(strs[i]) == 1)
        {
            parr_release(strs);
            return 1;
        }
        push_back(list, create_node(ft_atoi(strs[i])));
        free(strs[i]);
        ++i;
    }
    free(strs);
    return 0;
}
void parr_release(char **strs)
{
    int i = 0;
    while(strs[i] != NULL)
    {
        free(strs[i]);
        ++i;
    }
    free(strs);
}

int my_notint(const char *str)
{
    int i;
    int len;

    i = 0;
    len = ft_strlen(str);

    if((str[0] == '-' && len > 11) || (str[0] != '-' && len > 10))
        return 1;
    if(str[i] == '-')
        i = 1;

    while(i < len)
    {
        if(ft_isdigit(str[i]) == 0)
            return 1;
        ++i;
    }
    if((str[0] == '-' && (progress_cmp(str, "-2147483648") == 1)) 
    || (str[0] != '-' && (progress_cmp(str, "2147483647") == 1))) 
        return 1;
    
    return 0;
}
int progress_cmp(const char *origin, const char *other)
{
    int i;
    int origin_len;
    int other_len;

    i = 0;
    while(*origin == '0')
        ++origin;
    while(*other == '0')
        ++other;
    origin_len = ft_strlen(origin);
    other_len = ft_strlen(other);
    if(origin_len < other_len)
        return 0;
    else if(origin_len > other_len)
        return 1;

    while(i < origin_len && origin[i] <= other[i])
    {
        if(origin[i] < other[i])
            return 0;
        ++i;
    }
    return 1;
}
