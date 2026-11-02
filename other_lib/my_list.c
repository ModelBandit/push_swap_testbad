#include "my_list.h"

List* create_node(int num)
{
    List *list = malloc(sizeof(List));

    list->num = num;
    list->prev = NULL;
    list->next = NULL;

    return list;
}

void push_back(List **head, List *new_list)
{
    List *cur_node = *head;
    if(cur_node == NULL)
    {
        *head = new_list;
        (*head)->prev = new_list;
        (*head)->next = new_list;
        return;
    }

    while(cur_node->next != *head)
        cur_node = cur_node->next;

    cur_node->next = new_list;
    new_list->prev = cur_node;
    new_list->next = *head;
}

List* pop(List *head)
{
    List *cur_node = head;

    while(cur_node->next != head)
        cur_node = cur_node->next;

    return cur_node;
}
void swap(List *list_a, List *list_b)
{
    int temp = list_a->num;
    list_b->num = list_a->num;
    list_a->num = temp;
}
void rotation(List *head)
{
    List *cur_node = head;
    List *next_node = cur_node->next;
    int temp = cur_node->num;

    while(cur_node->next != head)
    {
        cur_node->num = next_node->num;
        cur_node = cur_node->next;
        next_node = next_node->next;
    }
    next_node->num = temp;
}
void reverse_rotation(List *head)
{
    List *cur_node = head;
    List *prev_node = cur_node->prev;
    int temp = cur_node->num;

    while(cur_node->prev != head)
    {
        cur_node->num = prev_node->num;
        cur_node = cur_node->prev;
        prev_node = prev_node->prev;
    }
    prev_node->num = temp;
}