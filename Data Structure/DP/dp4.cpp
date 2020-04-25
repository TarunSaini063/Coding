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
int main(void)
{
	FIO	
	int t;
	cin>>t;
	while(t--)
	{
		int n,w;
		cin>>n>>w;
		int val[n],wt[n];
		for(auto &j : val) cin>>j;
		for(auto &j : wt) cin>>j;
		int dp[n+1][w+1];
		for(int i=0;i<=n;i++)
		{
			for(int j=0;j<=w;j++)
			{
				if(i==0||j==0) dp[i][j]=0;
				else if(wt[i-1]>j) dp[i][j]=dp[i-1][j];
				else dp[i][j]=max(dp[i-1][j],val[i-1]+dp[i-1][j-wt[i-1]]);
			}
		}
		cout<<dp[n][w]<<"\n";
	}
	return 0;
}