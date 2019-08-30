#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}NODE;

NODE *head,*head1;

NODE *create(NODE *head_node)
{
	NODE *nn,*temp ; 
	
	head_node =NULL;
	int n,i;

	printf("\nEnter how many nodes: ");
 	scanf("%d",&n);


	for(i=0;i<n;i++)
	{
		nn=(NODE *)malloc(sizeof(NODE));
		nn->next = NULL;
		printf("\nEnter data:\t");
		scanf("%d",&nn->data);

		if(head_node == NULL)
			head_node = temp = nn;
		else
		{
			temp->next = nn;
			temp = nn;
		}
	}


return head_node;

}


NODE * merge(NODE *head,NODE *head1)
{
	NODE * temp,* temp1, *temp3;

	temp=head;
	temp1 = head1;

	if(temp && temp1)
	{
		while(temp!=NULL && temp1!=NULL)
		{	
			temp3 = temp1->next;

			temp1->next = temp->next;
			temp->next = temp1;
		
			temp = temp1->next;
			temp1 = temp3;
		
		}
		if(temp3 == NULL)
		{
			printf("\nSecond list after merging : NULL \n");
		
		}
		else
		{
			printf("\nAfter merge second list elements:\n");
			for(temp = temp3;temp!=NULL ; temp=temp->next)
				printf("\t--> %d",temp->data);
		}
	}

	else
	{
		printf("\n No change\n");
	}

return head;
}


void display(NODE *head_node)
{
	NODE *temp;
	temp =head_node;

	if(head_node)
	{
		for(temp = head_node;temp!=NULL;temp=temp->next)
			printf("\t-->%d",temp->data);
	}
	else
		printf("\n----NULL-------\n");
printf("\n");

}

int main()
{
	int ch;
	NODE *head , *head1;

	head = NULL;
	head1= NULL;

	do
	{
		printf("\nMenu\n1:Create first linked list\n2:Create second list\n3: Merge with alternate position\n4:Display  list after merging\n5:Exit\n");
		printf("\nEnter the choice: \n");
		scanf("%d",&ch);
		
		switch(ch)
		{
		case 1:
			head = create(head);
			break;
		case 2:
			head1 = create(head1);
			break;
		case 3:
			head = merge(head,head1);
			break;
		case 4:
			display(head);
			break;
		case 5:
			exit(0);
		}

	}
	while(ch!=7);
	return 0;
}
