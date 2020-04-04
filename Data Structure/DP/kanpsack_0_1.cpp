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
// int kanpsack(int n,int val[],int wt[],int w)
// {
// 	if(w==0||n==0) return 0;
// 	if(wt[n-1]>w) kanpsack(n-1,val,wt,w);
// 	return max(val[n-1]+kanpsack(n-1,val,wt,w-wt[n-1]),kanpsack(n-1,val,wt,w));
// }
int kanpsack(int n,int val[],int wt[],int w)
{
	int dp[n+1][w+1];
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=w;j++)
		{
			if(j==0||i==0) dp[i][j]=0;
			else if(wt[i-1]>j) dp[i][j]=dp[i-1][j];
			else dp[i][j]=max(dp[i-1][j],val[i-1]+dp[i-1][j-wt[i-1]]);
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=w;j++) cout<<dp[i][j]<<" ";
			cout<<endl;
	}
	return dp[n][w];
}
int main(void)
{
	FIO	
	int w=50;
	int val[]={60,100,120};
	int wt[]={10,20,30};
	cout<<kanpsack(3,val,wt,w)<<endl;
	return 0;
}