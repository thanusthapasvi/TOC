#include <stdio.h>
#include <string.h>
//   start with a and end with a
int main()
{
	char s[10];
	int i,k,c=0;
	printf("Use Only a's or b's\n");
	printf("Enter a string : ");
	scanf("%s",s);
	k=strlen(s);
	for(i = 0;i<k;i++)
    {
    	if(s[i] == 'a' || s[i] == 'b')
    		c = c+1;
	}
	if (c == k)
	{
		if(s[0]=='a' && s[k-1]=='a')
			printf("\nString Accepted");
		else
			printf("\nNot Accepted");
	}
	else
		printf("\nstring must be a's and b's");
}

