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
	int n,m;
	cin>>n>>m;
	int dp[n+2][n+2];
	memset(dp,0,sizeof(dp));
	dp[0][n+1]=1;
	for(int i=n;i>=m;i--)
	{
		for(int j=0;j<=n;j++)
		{
			dp[j][i]=dp[j][i+1];
			if(i<=j) dp[j][i]+=dp[j-i][i];
			cout<<j<<" "<<i<<" ->"<<dp[j][i]<<"\n";
		}
	}
	cout<<dp[n][m]<<"\n";
	return 0;
}