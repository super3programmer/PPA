/*
Given a Linked List of size N, where every node represents a linked list and contains two pointers
of its type:
(i) a next pointer to the next node,
(ii) a bottom pointer to a linked list where this node is head.
You have to flatten the linked list to a single linked list which is sorted.
5-> 10 -> 19 -> 28
|	|	|	  |
V	v	v	  v
7	20	22	  35
|		|	  |
V		v	  v
8		50	  40
|			  |
V			  v
30			  45

and after flattening it, the sorted linked list looks like:
5-> 7-> 8- > 10 -> 19-> 20-> 22-> 28-> 30-> 35-> 40-> 45-> 50

*/


#include<stdio.h>
#include<stdlib.h>

typedef struct ll
{
	int data;
	struct ll *next;
	struct ll *down;
}LL;


LL * create_list(LL *head_node)
{
        LL *temp_node,*new_node , *temp1;
 
        head_node = NULL;

        int i,i_no,j,i_down;

        printf("\nEnter how many numbers in main list:\n");
        scanf("%d",&i_no);

        for(i=0;i<i_no;i++)
        {
                new_node = (LL *)malloc(sizeof(LL));
                new_node->next = NULL;
                new_node->down = NULL;

                printf("\nEnter data for main linked list: --> \t");
                scanf("%d",&new_node->data);

                if(head_node == NULL)
                {
                        head_node = temp_node = new_node;
                }
                else
                {
                        temp_node->next = new_node;
                        temp_node = new_node;
			 }

	        printf("\nElements for node %d=>  ",temp_node->data);
                scanf("%d",&i_down);

                temp_node->down = NULL;
                
                for(j=0;j<i_down;j++)
                {


                        new_node = (LL *)malloc(sizeof(LL));
                        new_node->next = NULL;
				    new_node->down = NULL;
                        printf("\nEnter data for sub linnked list:\t");
                        scanf("%d",&new_node->data);

                        if(temp_node->down == NULL)
                        {
                                temp_node->down = new_node;
                                temp1 = new_node;
                                
                        }
                        else
                        {
                                temp1->down = new_node;
                                temp1 = new_node;
                        }
                
                }
        }

        return head_node;
}


LL * single_ll(LL *head_node)
{
	LL *temp,*temp1,*temp2,*s , *t;
	

	temp = head_node;
	s = NULL;

	while(temp!=NULL)
	{
		temp2 = temp->down;

		if(s == NULL)		
		{
			s = temp;
			temp1 = s;
		}
		else
		{
			temp1->down = temp;			
			temp1 = temp;		
		}

			while(temp2!=NULL)
			{
				temp1->down = temp2;
				temp1 = temp2;
				temp2 = temp2->down;
			}

		temp = temp->next;
	}


return s ;
}

LL * sort_sll(LL *sll)
{
	int i_data;	
	LL *temp ,*temp1,*temp2;
	
	temp = sll;	
	for(temp=sll;temp!=NULL;temp=temp->down)
	{
		for(temp1 =sll;temp1!=NULL;temp1 = temp1->down)	
		{
			if(temp->data < temp1->data)
			{
				i_data = temp->data;
				temp->data= temp1->data;
				temp1->data=i_data; 
			}

		}


	}

	return sll;
}

void display_sll(LL *sll)
{
	LL *temp;

	printf("\n*******************sll*********************\n");
	for(temp=sll; temp!=NULL;temp=temp->down)
	{
		printf("\t%d ",temp->data);
	}

}
void display(LL *head_node)
{
        LL *temp_node , *temp1;
       

        for(temp_node = head_node ; temp_node!= NULL ; temp_node = temp_node->next )
        {
                printf("\n%d-->\t",temp_node->data);
                temp1  = temp_node->down;
                while(temp1!=NULL)
                {
                        printf("\t%d",temp1->data);
                        temp1 = temp1->down;

                }
	}
}


int main()
{
	LL *head_node , *sll;
	sll = NULL;
	head_node = NULL;

	int ch;
	do
	{
		printf("\nMENU\n1 : Create list with sublist\n2: Display given list\n3: Sort list\n4:Display single list\n5:Exit\n");
		printf("\nEnter choice: ");
		scanf("%d",&ch);
		switch(ch)
		{	
			case 1:
				head_node = create_list(head_node);
				break;
			case 2:
				printf("\nGiven linked list: ");
				display(head_node);
				break;
			case 3:
				sll = single_ll(head_node);
				sll = sort_sll(sll);
				break;
			case 4:
				display_sll(sll);
				break;
			case 5:
				exit(0);
			default:
				printf("\nWrong choice\n");
		}
	}
	while(ch!=5);
	return 0;
}
