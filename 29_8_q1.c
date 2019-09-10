/*
Number is represented in linked list such that each digit corresponds to a node in linked list. Add 1
to it. For example 9999999 is represented as (9->9-> 9->9->9->9-> 9) and adding 1 to it should
change it to (1->0->0->0->0->0->0->0)
*/
#include<stdio.h>
#include<stdlib.h>

typedef struct ll
{
	int data;
	struct ll *next;

}SLL;

SLL *head;
int flag = 0;

SLL * create(SLL *head , int i_num)
{
	int digit;
	SLL *nn,*temp;

	if(flag == 1)
		i_num = i_num*(-1);

	//printf("\n%d- - \n",i_num);
	while(i_num > 0)
	{
		digit = i_num % 10;
		
		nn = (SLL *)malloc(sizeof(SLL));
		nn->next = NULL;
		nn->data = digit;

		i_num = i_num/10;

		if(head == NULL)
			head = nn;
		else
		{
			nn->next = head;
			head = nn;
		}

	}


return head;
}

SLL * rev_ll(SLL *head)
{
	SLL  *curr , *next_ptr , *prev;
	
	curr = head;
	prev = NULL;
	next_ptr = curr->next;

	while(curr!=NULL)
	{
		curr->next = prev;
		prev = curr;
		curr = next_ptr;
		
		if(curr != NULL)
			next_ptr = curr->next;

	}

return prev;
}


void display(SLL *head)
{
        SLL *temp;
        for(temp = head ; temp!=NULL ; temp=temp->next)
	{
		if(flag == 1 && temp == head)
                	printf("\t--> -%d",temp->data);
		else
			printf("\t--> %d",temp->data);
	}
printf("\n");

}

SLL * sum_two_num(SLL * head)
{
	int val;
	printf("\nEnter second number:\n");
	scanf("%d",&val);

	SLL *temp, *prev , *nn;

	temp = head ;
	while(temp!=NULL)
	{	
		int result=0 , digit;
		if(flag == 0)   
	        {
        	        result = temp->data + val;
                	if(result >=0 && result < 10)
	                {
			//	printf("\nResult %d",result);
                	        temp->data = result;
                        	break;                
	                }
        	        else
                	{
                        	digit = result % 10;
	                        temp->data = digit;
        	                result = result/10;
                	        val = result ;
	                }

        	}       //end of positive number

	        else
        	{
        //        	printf("\nNegative number:\n");
		
			if(temp->data >= val)
			{
				result = temp->data - val;
			//	printf("\n%d\n",temp->data);	
				temp->data = result;
        		       break;
			}
			else
			{
				val = temp->data + 10 - val;
				temp->data = val;
				val = 1;
			}	

		}		//end of negative number
		prev = temp;
		temp = temp->next ;

	}	//end of while


	if(temp == NULL)
	{
		nn = (SLL *)malloc(sizeof(SLL));
		nn->next = NULL;
		nn->data = val;
		prev->next = nn;
	}

head = rev_ll(head);
return head;
}


int main()
{

	SLL *head;
	head=NULL;
	int i_num , ch;

	printf("\nEnter the number:\n");
	scanf("%d",&i_num);

	if(i_num < 0)
		flag=1;
	printf("\n%d\n",i_num);
	do
	{
		printf("\nMenu\n1: Create linked list of number\n2:Display\n3: Sum of numbers\n4:Exit\n");
		scanf("%d",&ch);
		
		switch(ch)
		{
		case 1:
			head = create(head , i_num);
			break;
		case 2:
			display(head);
			break;
		case 3:
			head = rev_ll(head);
			head = sum_two_num(head);
			break;
		case 4:
			exit(0);
		default : 
			printf("\nWrong choice\n");
		}

	}while(ch!=4);
return 0;
}
