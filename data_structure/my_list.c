#include "my_list.h"

List* create_node(int num)
{
    List *list = malloc(sizeof(List));

    list->num = num;
    list->prev = NULL;
    list->next = NULL;

    return list;
}

void swap(List *head)
{
    if(head == NULL || head->next == head )
        return;

    List *next_list = head->next;
    int temp = next_list->num;
    next_list->num = head->num;
    head->num = temp;
}

void push_back(List **head, List *new_list)
{
    if(new_list == NULL)
        return;

    List *cur_node = *head;
    if(cur_node == NULL)
    {
        *head = new_list;
        (*head)->prev = new_list;
        (*head)->next = new_list;
        return;
    }

    new_list->next = cur_node;
    new_list->prev = cur_node->prev;
    cur_node->prev->next = new_list;
    cur_node->prev = new_list;

    *head = new_list;
}

List* pop(List **head)
{
    List *cur_node;

    if(*head == NULL)
        return NULL;
    cur_node = *head;
    if(cur_node->next == *head)
    {
        *head = NULL;
        return cur_node;
    }

    cur_node->prev->next = cur_node->next;
    cur_node->next->prev = cur_node->prev;
    (*head) = cur_node->next;

    cur_node->next = cur_node;
    cur_node->prev = cur_node;

    return cur_node;
}
// HEAD TO TAIL
void rotation(List **head)
{
    if(*head == NULL)
        return;

    *head = (*head)->next;
}

// TAIL TO HEAD
void reverse_rotation(List **head)
{
    if(*head == NULL)
        return;

    *head = (*head)->prev;
}

int count_node(List *head)
{
    List *cur_node;
    int i;

    if(head == NULL)
        return 0;
    else if(head == head->next)
        return 1;

    cur_node = head->next;
    i = 1;

    while(cur_node != head)
    {
        cur_node = cur_node->next;
        ++i;
    }

    return i;
}