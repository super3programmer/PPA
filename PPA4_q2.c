/*
Given two strings, check if they’re anagrams or not. Two strings are
anagrams if they are written using the same exact letters, ignoring
space, punctuation and capitalization. Each letter should have the same
count in both strings.
For example, ‘Eleven plus two’ and ‘Twelve plus one’ are meaningful
anagrams of each other.
*/

#include<stdio.h>
#include<string.h>


void check_anagrams(char s1[],char s2[],int cnt[])
{

	int i, flag=0;

	for(i=0;s1[i]!='\0';i++)
	{
		cnt[s1[i]]++;
	}

	for(i=0;s2[i]!='\0';i++)
	{
		cnt[s2[i]]--;
	}

	for(i=0;i<256;i++)
	{
		if(cnt[i]!=0)
		{
			flag=1;
			break;
		}
	}

if(flag == 0)
	printf("\nStrings are anagrams\n");
else
	printf("\nNot anagrams\n");
}


int main()
{
	char str_ip1[100],str_ip2[100];
	int i_cnt[256],i;

	printf("\nEnter first string:\t");
		gets(str_ip1);
	
	printf("\nEnter second string: ");
		gets(str_ip2);


	for(i=0 ; i < 256 ; i ++)
	{
		i_cnt[i]=0;
	}

	check_anagrams(str_ip1,str_ip2,i_cnt);



	return 0;
}
