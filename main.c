#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"


int neg1 = 0;
int neg2 = 0;
int both_neg = 0;

int main(int argc, char *argv[]) 
{
    char str1[100], str2[100];
    char operator;

    /* Expect: ./main num1 operator num2  (e.g. ./main 123 + 456) */
    if (argc != 4)
    {
	printf("Usage: %s <num1> <operator> <num2>\n", argv[0]);
	printf("Example: %s 123 + 456\n", argv[0]);
	return 1;
    }

    strncpy(str1, argv[1], sizeof(str1) - 1);
    str1[sizeof(str1) - 1] = '\0';

    operator = argv[2][0];

    strncpy(str2, argv[3], sizeof(str2) - 1);
    str2[sizeof(str2) - 1] = '\0';

    if (str1[0] == '-' && str2[0] == '-')
    {
	  both_neg = 1;
    }

    if (str1[0] == '-')
    {
	  neg1 = 1;
	  int i = 0;
	  while (str1[i] != '\0')
	  {
	      str1[i] = str1[i + 1];
	      i++;
	  }
    }

    if (str2[0] == '-')
    {
		neg2 = 1;
		int i = 0;
		while (str2[i] != '\0')
		{
	    	str2[i] = str2[i + 1];
	   	    i++;
	    }
    }

    List1 *head1 = NULL;
    List1 *tail1 = NULL;
    store_num1(&head1, &tail1, str1);

    List2 *head2 = NULL;
    List2 *tail2 = NULL;
    store_num2(&head2, &tail2, str2);

    Res_List *head3 = NULL;
    Res_List *tail3 = NULL;

    switch (operator)
    {
	case '+':
	    {
		if (head1 == NULL || head2 == NULL)
		{
			printf("Syntax error pass 2 operands\n");
			return 0;
		}
		printf("Result : ");

		if (both_neg == 1)
		{
			printf("-");
			add_num(&head1,&tail1,&head2,&tail2,&head3,&tail3);
		}
		else if (neg1)
		{
			sub_num(&head1,&tail1,&head2,&tail2,&head3,&tail3);
		}
		else if (neg2)
		{
			sub_num(&head1,&tail1,&head2,&tail2,&head3,&tail3);
		}
		else
		{
			add_num(&head1,&tail1,&head2,&tail2,&head3,&tail3);

		}
		break;
	    }
	case '-':
	    {
		if (head1 == NULL || head2 == NULL)
		{
			printf("Syntax error pass 2 operands\n");
			return 0;
		}
		printf("Result : ");

		if (neg1 == 1)
		{
			printf("-");
			add_num(&head1,&tail1,&head2,&tail2,&head3,&tail3);
		}
		else 
		{
			sub_num(&head1,&tail1,&head2,&tail2,&head3,&tail3);
		}
		break;
	    }
	case '*' :
	    {
		if (head1 == NULL || head2 == NULL)
		{
			printf("Syntax error pass 2 operands\n");
			return 0;
		}
		printf("Result : ");
		if (head2 == NULL)
		{
			return 0;
		}
		if( (neg1 == 1 && neg2 == 0) || (neg1 == 0 && neg2 == 1) )
		{
			printf("-");
			multi_num(&head1,&tail1,&head2,&tail2,&head3,&tail3);
		}
		else
		{
			multi_num(&head1,&tail1,&head2,&tail2,&head3,&tail3);
		}
		break;
	    }
	case '/' :
	    {
		if (head1 == NULL || head2 == NULL)
		{
			printf("Syntax error pass 2 operands\n");
			return 0;
		}
		printf("Result : ");
		if (head2 == NULL)
		{
			printf("num1\n");
			return 0;
		}
		if ((neg1 == 1 && neg2 == 0) || (neg1 == 0 && neg2 == 1))
		{
			printf("-");
			div_num(&head1,&tail1,&head2,&tail2,&head3,&tail3);
			neg1 = 0;
			neg2 = 0;
		}
		else
		{
			div_num(&head1,&tail1,&head2,&tail2,&head3,&tail3);
			both_neg = 0;
		}
		break;
	    }
	default:
	    {
		printf("Pass correct operator\n");
	    }
    }

    return 0;
}



void store_num1(List1 **head1, List1 **tail1, char str1[])
{
    int len1 = strlen(str1);
    int j = strlen(str1) -1;
    char str3[5];
    
    while (j >= 0)
    {
	  int k;
	  for (k = 0; k < 4 && j >= 0; k++, j--)
	{
	    str3[3 - k] = str1[j];
	}
	while (k < 4) 
	{
	    str3[3 - k] = '0';
	    k++;
	}
	str3[4] = '\0';
	int num1 = atoi(str3);
	List1 *new = malloc(sizeof(List1));
	if (new == NULL)
	{
	    printf("Memory allocation failed.\n");
	    exit(1);
	}

	new->num = num1;
	new->prev = NULL;
	if (*head1 == NULL)
	{
	    *head1 = new;
	    *tail1 = new;
	} 
	else 
	{
	    new->next = *head1;
	    (*head1)->prev = new;
	    *head1 = new;
	}
    }

}



void store_num2(List2 **head2, List2 **tail2, char str2[])
{
    int len2 = strlen(str2);
    int j = strlen(str2) -1;
    char str3[5];
    
    while (j >= 0) 
	{
	   int k;
	for (k = 0; k < 4 && j >= 0; k++, j--)
	{
	    str3[3 - k] = str2[j];
	}
	while (k < 4) {
	    str3[3 - k] = '0';
	    k++;
	}
	str3[4] = '\0';
	int num2 = atoi(str3);
	List2 *new = malloc(sizeof(List1));
	if (new == NULL) 
	{
	    printf("Memory allocation failed.\n");
	    exit(1);
	}

	new->num = num2;
	new->prev = NULL;

	if (*head2 == NULL)
	{
	    *head2 = new;
	    *tail2 = new;
	}
	else
	{
	    new->next = *head2;
	    (*head2)->prev = new;
	    *head2 = new;
	}
    }

}


void print_list1(List1 *head1)
{
    /* Check the list is empty or not */
    if (head1 == NULL)
    {
	    printf("INFO : List is empty\n");
    }
    else
    {
	    printf("Head -> ");
	while (head1)		
	{
	    /* Print the list */
	    printf("%d <-", head1 -> num);

	    /* Travering in forward direction */
	    head1 = head1 -> next;
	    if (head1)
		printf("> ");
	}
	printf(" Tail\n");
    }
}


void print_list2(List2 *head1)
{
    /* Check the list is empty or not */
    if (head1 == NULL)
    {
	  printf("INFO : List is empty\n");
    }
    else
    {
	  printf("Head -> ");
	while (head1)		
	{
	    /* Print the list */
	    printf("%d <-", head1 -> num);

	    /* Travering in forward direction */
	    head1 = head1 -> next;
	    if (head1)
		printf("> ");
	}
	printf(" Tail\n");
    }
}

void print_list3(Res_List *head1)
{
    /* Check the list is empty or not */
    if (head1 == NULL)
    {
	  printf("INFO : List is empty\n");
    }
    else
    {
	
	while (head1)		
	{
	    if (head1->num == 0)
	    {
		printf("000");
	    }
	    /* Print the list */
	    printf("%d", head1 -> num);

	    /* Travering in forward direction */
	    head1 = head1 -> next;
	    
	}
	
    }
    printf("\n");
}


void print_list4(Res_List *head1)
{
    /* Check if the list is empty or not */
    if (head1 == NULL)
    {
	printf("INFO : List is empty\n");
    }
    else
    {
	printf("Head -> ");
	while (head1)		
	{
	    /* Print the list */
	    printf("%d <-", head1 -> num);

	    /* Traverse in forward direction */
	    head1 = head1 -> next;
	    if (head1)
		printf("> ");
	}
	printf(" Tail\n");
    }
}