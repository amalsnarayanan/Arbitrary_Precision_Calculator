#include<stdio.h>
#include"main.h"

void add_num(List1 **head, List1 **tail, List2 **head2, List2 **tail2, Res_List **head3, Res_List **tail3)

{
    List1 *temp1 = *head;
    List2 *temp2 = *head2;
    Res_List *temp3 = *tail3;
    int num_node1 = 0;
    int carry = 0;
    while (temp1 != NULL)
    {
	  num_node1++;
	  temp1 = temp1->next;
    }
    temp1 = *tail;
    int num_node2 = 0;
    while (temp2 != NULL)
    {
	   num_node2++;
	   temp2 = temp2 -> next;
    }
    temp2 = *tail2;
    *head3 = NULL;
    *tail3 = NULL;
    while (temp1 != NULL || temp2 != NULL || carry>0)
    {
	
	int sum = 0;
	if (temp1 != NULL)
	{
	    sum += temp1->num;
	    temp1 = temp1->prev;
	}

	if (temp2 != NULL)
	{
	    sum += temp2->num;
	    temp2 = temp2->prev;
	}

	sum = sum + carry;

	if (sum >= 10000)
	{
	    carry = 1;
	    sum = sum - 10000;
	}
	else
	{
	    carry = 0;
	}
	
	Res_List *new = malloc(sizeof(Res_List));
    
	if (*head3 == NULL)
	{
	    new -> num = sum;
	    new -> prev = NULL;
	    new -> next = NULL;
	    *head3 = new;
	    *tail3 = new;
	}
	else
	{
	    new -> num = sum;
	    new -> prev = NULL;
	    new -> next = *head3;
	    (*head3) -> prev = new;
	    *head3 = new;
	}
	
	sum = 0;

    }

    print_list3(*head3);

}