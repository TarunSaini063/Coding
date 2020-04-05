#include <bits/stdc++.h>
using namespace std;
#define ld double
#define ll long long
#define pb emplace_back
#define mk make_pair
#define mod 1000000007
#define ff first
#define ss second
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(x) x.begin(),x.end()
ll power(ll a, ll b){ll res=1;a=a%mod; while(b){if(b&1)res=(res*a)%mod; a=(a*a)%mod;b/=2;}return res;}
ll invmod(ll a){return power(a,mod-2);}
// int lcs(char x[],char y[],int m,int n,string s)
// {
// 	if(m==0||n==0) {return 0;}
// 	if(x[m-1]==y[n-1]){s+=x[m-1]; return 1+lcs(x,y,m-1,n-1,s);}
// 	return max(lcs(x,y,m-1,n,s),lcs(x,y,m,n-1,s));
// }
int lcs(char x[],char y[],int m,int n)
{
	int dp[m+1][n+1];
	for(int i=0;i<=m;i++)
	{
		for(int j=0;j<=n;j++)
		{
			if(i==0||j==0) dp[i][j]=0;
			else if(x[i]==y[j]) dp[i][j]=1+dp[i-1][j-1];
			else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	}
	int i=m,j=n;
	string s="";
	while(i>0&&j>0)
	{
		if(dp[i][j]==dp[i][j-1]) j--;
		else if(dp[i-1][j]==dp[i][j]) i--;
		else s+=x[i-1],i--,j--;
	}
	reverse(all(s));
	cout<<s<<endl;
	return dp[m][n];
}
int main(void)
{
	FIO	
	char X[] = "AGGTAB";  
    char Y[] = "GXTXAYB";  
    int m = strlen(X);  
    int n = strlen(Y);
    cout<<lcs(X,Y,m,n)<<endl;
	return 0;
}