#include "../libft/libft.h"

/*
기존 libft의 list에 앞 노드를 보는 포인터가 추가된 버전
컨테이너 빌딩 코드를보면 순환형(Doubly Circular Linked List) 구성했지만 Double Linked List랑 구조는 같음
*/
typedef struct dc_list
{
    int num;
    struct dc_list *prev;
    struct dc_list *next;
} List;

// 노드 생성
List* create_node(int num);
// 가장 끝 노드 뒤에 넣기
void push_back(List **head, List *new_list);
// 가장 마지막 노드 빼면서 반환
List* pop(List *head);
// 모든 원소 한 칸씩 뒤로 (마지막 노드는 맨 앞으로)
void rotation(List *self);
// 모든 원소 한 칸씩 앞으로 (첫 노드는 마지막 노드로)
void reverse_rotation(List *self);