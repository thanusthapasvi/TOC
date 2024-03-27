#include <stdio.h>
#include <string.h>

//   start with 0 and end with 1
int main()
{
    char s[10];
	int i,k,c=0;
	printf("Use Only 0's or 1's\n");
	printf("Enter a string : ");
	scanf("%s",s);
	k=strlen(s);
	for(i = 0;i<k;i++)
    {
    	if(s[i] == '0' || s[i] == '1')
    		c = c+1;
	}
	if (c == k)
	{
		if(s[0]=='0' && s[k-1]=='1')
			printf("\nString Accepted");
		else
			printf("\nNot Accepted");
	}
	else
		printf("\nstring must be 0's and 1's");
}
