#include<stdio.h>
#include<stdlib.h>
#define max 20

void merge(int *a, int lb , int mid , int ub)
{
	int i , j , k ,size ,temp[max];
	 
	i = lb;
	j = mid;
	k=lb;
	
	while( i<= mid-1 && j <= ub)
	{
		if(a[i] <= a[j])
		{
			temp[k++] = a[i++];
		}
		else
		{
			temp[k++] = a[j++];			
		}
	}
	
	while(i<=mid-1)
	{
		temp[k++] = a[i++];
	}
	
	while(j<=ub)
	{
		temp[k++] = a[j++];
	}
	
	for(i=lb ; i<=ub; i++)
	{
		a[i] = temp[i];
		
	}
}

void ms(int *a,int lb,int ub)
{
	int mid;
	if(lb < ub)
	{
		mid = (lb+ub)/2;
		ms(a,lb,mid);
		ms(a,mid+1 , ub);
		merge(a , lb , mid+1 ,ub);
	}
}

void print_Snake(int a[],int  m[max][max], int i_R,int i_C)
{
	int i , j , n , k=0;

	n = i_R * i_C;

	for(i=0; i < i_R ; i++)
	{
		if((i%2)!=0)
		{
			for(j=i_C - 1 ; j>=0 ; j--)
			{
				m[i][j] = a[k];
				k++;
			}									//left to right
		
		}
		else
		{
			for(j=0;j<i_C;j++)
			{
				m[i][j] = a[k];
				k++;
			}
		}
		
		
	}

	for(i=0;i<i_R;i++)
	{
		for(j=0;j<i_C;j++)
		{
			printf("\t%d",m[i][j]);
		}
		printf("\n");
	}

}

int main()
{
	int m[max][max] , i_Row , i_Col , i , j , *array , n , k=0;

	printf("\nEnter the number of rows and columns:\t");
	scanf("%d%d",&i_Row,&i_Col);
	
	if(i_Row < 0 || i_Col < 0)
	{
		return 0;
	}

	n = i_Row * i_Col;

	printf("\nEnter elements of matrix: \n");
	for(i=0;i<i_Row;i++)
	{
		for(j=0;j<i_Col;j++)
		{
			scanf("%d",&m[i][j]);
		}
	}

	array = (int *)malloc(n*sizeof(int));

	for(i=0;i<i_Row;i++)
	{
		for(j=0;j<i_Col;j++)
		{
			array[k] = m[i][j];
			k++;
		}
	}

	ms(array , 0 , n-1);

	printf("\n\nsort\n");
	print_Snake(array , m ,i_Row , i_Col );
	return 0;
}
