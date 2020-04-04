#include<stdio.h>
int main(void) 
{ 
	int n; 
	scanf("%d",&n);
	int arr[n][n],i,j; 
	for(i=1;i<n;i++)
	{
		for(j=1;j<n;j++)
		{
			if(j==1) 
			{ 
				arr[i][j]=i;
			} 
			else if(i==1||j==n-1) 
			{ 
				arr[i][j]=1; 
			}
			else if(i<=n/2) 
			{ 
				arr[i][j]=(arr[i][j-1]*i)%n;
			}
			else
			{ 
				if(j%2==0)
					arr[i][j]=arr[n-i][j];
				else 
					arr[i][j]=n-arr[n-i][j];
			}
		} 
	}
	for(i=1;i<n;i++)
	{ 
	 	for(j=1;j<n;j++)
	 	{ 
	 	 	printf("%d ",arr[i][j]); 
	 	} 
	 	printf("\n");
	} 
	return 0; 
 }