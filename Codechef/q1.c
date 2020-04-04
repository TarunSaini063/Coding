#include<stdio.h>
int main(void)
{
	char a[100];
	scanf("%[^\n]",a);
	printf("%s",a);
	return 0;
}