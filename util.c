#include "my_std.h"

int init_list(char **list, char *arg_str)
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
    int str_values;

    i = 0;
    len = ft_strlen(str);
    str_values = 0;

    if(str[i] == '-')
        i = 1;

    while(i < len)
    {
        if(ft_isdigit(str[i]) == 0)
            return 1;
        str_values += (int)(str[i]);
    }
    if((str[0] == '-' && str_values > 572) || (str[0] != '-' && str_values > 526))
        return 1;
    
    return 0;
}
/*  각 문자들 전부 더한 값
    min = "-2147483648"; // 572
    max = "2147483647"; // 526
*/