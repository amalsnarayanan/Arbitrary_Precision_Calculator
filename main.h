#include <stdio.h>
#include <stdlib.h>


#define SUCCESS 0
#define FAILURE -1


typedef struct node1
{
    int num;
    struct node1 *prev;
    struct node1 *next;
}List1;


typedef struct node2
{

    int num;
    struct node2 *prev;
    struct node2 *next;
}List2;


typedef struct node3
{
    int num;
    struct node3 *prev;
    struct node3 *next;
} Res_List;






void store_num1(List1 **head, List1 **tail, char str1[]);
void store_num2(List2 **head2, List2 **tail2, char str2[]);
void print_list1(List1 *head);
void print_list2(List2 *head2);
void print_list3(Res_List *head);
void print_list4(Res_List *head);
void print_list5(Res_List *head);

void add_num(List1 **head, List1 **tail, List2 **head2, List2 **tail2, Res_List **head3, Res_List **tail3);
void sub_num(List1 **head, List1 **tail, List2 **head2, List2 **tail2, Res_List **head3, Res_List **tail3);
void multi_num(List1 **head, List1 **tail, List2 **head2, List2 **tail2, Res_List **head3, Res_List **tail3);
void div_num(List1 **head, List1 **tail, List2 **head2, List2 **tail2, Res_List **head3, Res_List **tail3);