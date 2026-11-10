#include "my_std.h"
#define NUM_ARR 5

int main()
{
    List *list_a = build_List(build_number_array(NUM_ARR), NUM_ARR);
    List *list_b = NULL;

    visual_print(list_a, list_b, 1);

    clear_list(&list_a);
    clear_list(&list_b);
    return 0;
}