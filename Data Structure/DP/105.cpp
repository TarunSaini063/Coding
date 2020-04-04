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
	int n;
	cin>>n;
	int dp[12][n+2];
	memset(dp,0,sizeof(dp));
	for(int i=n;i>=1;i--)
	{
		for(int j=9;j>=1;j--)
		{
			if(i==n) dp[j][i]=1;
			else dp[j][i]=dp[j+1][i+1]+dp[j+1][i];
		}
		
	}
	int ans=0;
	for(int i=1;i<10;i++) ans+=dp[i][1];
	cout<<ans<<"\n";
	return 0;
}