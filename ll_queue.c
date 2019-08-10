#include<stdio.h>
#include<stdlib.h>

typedef struct ll
{
	int data;
	struct ll *next;

}LL;

LL *head,*first,*last;

LL *enQ(LL *head)
{
	int n,i,value;
	LL *temp,*nn;


	printf("\nEnter element to insert:\n");
	scanf("%d",&value);
	
	nn = (LL *)malloc(sizeof(LL));
	nn->next=NULL;
	nn->data = value;

	if(head == NULL)
	{
		head = temp = nn;
		first = temp;

	}
	else
	{
		first->next = nn;
		first=nn;
		temp=nn;

	}


return head;

}

LL *deQ(LL *head)
{
	LL *temp,*temp1;
	if(head == NULL)
	{
		printf("\nNULL\n");
		
		return head;
	}

	else 
	{
	if(head->next!=NULL)
	{
		for(temp=head;temp->next!=first;temp=temp->next);
		temp1 = first;
		first = temp;
		free(temp1);
		first->next=temp->next=NULL;
		return head;		
	}
	else 
	{
		free(head);
		head->next=NULL;
		head=NULL;
		return(head);
	}
	printf("\nElement successfully deleted\n");


	}
}

void peek(LL *head)
{
	if(head!=NULL)
		printf("\nCurrent element: %d\n",head->data);
	else
		printf("\t-->NULL\n");
}
void display_Q(LL *head)
{
	LL *temp;
	if(head!=NULL)
	{
		for(temp=head;temp!=NULL;temp=temp->next)
				printf("\t-->%d-->",temp->data);
		
	}
	else
		printf("\tNULL\n");
printf("\n");

}

int main()
{

	int ch,i=0;
	
	head=NULL;
	

	do
	{
	printf("\nMENU\n1:Enqueue\n2:Dequeue\n3:Peek\n4:Display\n5:exit");

	printf("\nEnter choice:\n");
	scanf("%d",&ch);
	
	switch(ch)
	{
		case 1:
			head=enQ(head);		
			break;
		case 2:
			head=deQ(head);
			break;
		case 3:
			peek(head);
			break;
		case 4:
			display_Q(head);
			break;
		case 5:
			exit(0);
		}
	}while(ch!=5);

return 0;
}
