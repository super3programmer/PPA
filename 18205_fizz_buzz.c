
#include<stdio.h>
#define max 100

int main()
{
	int a[max],i;
	char *str1="Fizz",*str2="Buzz";

	printf("\nNumbers from 1 to 100: \n");
	for(i=1;i<=max;i++)
	{
	 	if(i%3 == 0 && i%5 == 0)
			printf("\t%s  %s",str1,str2);
		else if(i%3 == 0)
			printf("\t%s",str1);
		else if(i%5 == 0)
			printf("\t%s",str2);
		else
			printf("\t%d",i);
		
	}
	return 0;
}
