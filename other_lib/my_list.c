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
    if(head->prev == head)
        return;

    List *cur_list = head->prev;
    int temp = cur_list->num;
    cur_list->num = cur_list->prev->num;
    cur_list->prev->num = temp;
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

    while(cur_node->next != *head)
        cur_node = cur_node->next;

    cur_node->next = new_list;
    new_list->prev = cur_node;
    new_list->next = *head;
    (*head)->prev =  new_list;
}

List* pop(List *head)
{
    List *cur_node = head;
    List *prev_node;

    while(cur_node->next != head)
        cur_node = cur_node->next;

    prev_node = cur_node->prev;
    prev_node->next = head;
    head->prev = prev_node;
    return cur_node;
}
void rotation(List *head)
{
    if(head == NULL)
        return;

    List *cur_node = head;
    List *next_node = cur_node->next;
    int temp = cur_node->num;

    while(cur_node->next != head)
    {
        // 앞에 노드의 num을 현재 노드에 저장
        cur_node->num = next_node->num;

        // 각 노드를 다음 노드로 변경
        cur_node = cur_node->next;
        next_node = next_node->next;
    }
    cur_node->num = temp;
}
void reverse_rotation(List *head)
{
    if(head == NULL)
        return;

    List *cur_node = head;
    List *prev_node = cur_node->prev;
    int temp = cur_node->num;

    while(cur_node->prev != head)
    {
        cur_node->num = prev_node->num;
        cur_node = cur_node->prev;
        prev_node = prev_node->prev;
    }
    cur_node->num = temp;
}
