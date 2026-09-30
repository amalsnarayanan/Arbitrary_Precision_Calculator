#include<stdio.h>
#include"main.h"


void div_num(List1 **head1, List1 **tail1, List2 **head2, List2 **tail2, Res_List **head3, Res_List **tail3)
{
    List1 *temp1 = *head1;
    List2 *temp2 = *head2;
    Res_List *temp3 = *head3;
    int len1=0;
    int len2 = 0;

    while (temp1 != NULL)
    {
	    len1++;
	    temp1 = temp1 -> next;

    }
    temp1 = *tail1;

	
    while (temp2 != NULL)
    {
	    len2++;
	    temp2 = temp2 -> next;
    }
    temp2 = *tail2;
    
    
    if ((len1 < len2) || ( (*head1) -> num > (*head2) -> num ))
    {
	  printf("0\n");
	  return;
    }
    else if (len1 >= len2)
    {
	
	  List2 *node2 = *head2;
	  long int divider = 0;
	  while (node2) 
      {
	    divider = divider * 10000 + (long int )node2->num;
	    node2 = node2->next;
	  }

	
	List1 *node1 = *head1;
	long int running_value = 0;
	Res_List *dummy_head = (Res_List *)malloc(sizeof(Res_List));
	dummy_head->num = 0;
	dummy_head->next = NULL;
	dummy_head->prev = NULL;
	*head3 = dummy_head;
	*tail3 = dummy_head;

	int started = 0; 

	while (node1) 
    {
	    running_value = running_value * 10000 + (long int)node1->num;
	    long int digit = running_value / divider;
	    running_value = running_value % divider;

	    
	    if ( started != 0 || digit > 0 ) 
		{
		started = 1;
		Res_List *new_node = (Res_List *)malloc(sizeof(Res_List));
		new_node->num = digit;
		new_node->next = NULL;
		new_node->prev = *tail3;
		(*tail3)->next = new_node;
		*tail3 = new_node;
	    }

	    node1 = node1 ->next;
	}

    
	if ((*head3) -> num == 0)
	{
	    *head3 = (*head3) -> next;
	    free((*head3) -> prev);
	    (*head3) -> prev = NULL;
	}
	else if ("")

	if (*tail3 == dummy_head) 
	{
	    *head3 = dummy_head->next;
	    if (*head3)
	    {
		   (*head3)->prev = NULL;
	    }
	    free(dummy_head);
	}
    }
    
    print_list5(*head3);

}


void print_list5(Res_List *head) 
{
    if (!head) 
	{
	   printf("0\n");
	   return;
    }

    
    char buffer[1000];
    char *ptr = buffer;
    int first = 1;

    while (head) 
	{
	if (first) 
	{
	    
	    ptr += sprintf(ptr, "%d", head->num);
	    first = 0;
	} 
	else 
	{
	    
	    ptr += sprintf(ptr, "%04d", head->num);
	}
	head = head->next;
    }
    printf("%s\n", buffer);
}