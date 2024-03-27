#include <stdio.h>
#include <string.h>
int main()
{
    char s[10];
    int k,i,c=0;
    printf("Use Only 0's or 1's\n");
    printf("Enter a string: ");
    scanf("%s", s);
    k = strlen(s);
    for(i = 0;i<k;i++)
    {
    	if(s[i] == '0' || s[i] == '1')
    		c = c+1;
	}
	if (c == k)
	{
		if (s[0] == s[k - 1] )
        	printf("\nAccepted\n");
    	else
        		printf("\nNot Accepted\n");	
	}
	else
		printf("\nstring must be 0's and 1's");
    return 0;
}

