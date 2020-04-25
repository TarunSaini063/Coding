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
		int n,r;
		cin>>n>>r;
		int dp[n+1][r+1];
		for(int i=0;i<=n;i++)
		{
			for(int j=0;j<=min(i,r);j++)
			{
				if(j==0||j==i) dp[i][j]=1;
				else dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])%mod;
			}
		}
		cout<<dp[n][r]<<"\n";
	}
	return 0;
}