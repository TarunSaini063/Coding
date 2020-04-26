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
		int v,n;
		cin>>v>>n;
		int arr[n],dp[v+1];dp[0]=0;
		for(auto &j:arr) cin>>j;
		for(int i=1;i<=v;i++)
		{
			dp[i]=INT_MAX;
			for(int j=0;j<n;j++)
			{
				if(arr[j]<=i&&dp[i-arr[j]]!=INT_MAX)
				{
					dp[i]=min(dp[i-arr[j]]+1,dp[i]);
				}
			}
		}
		if(dp[v]==INT_MAX) dp[v]=-1;
		cout<<dp[v]<<"\n";
	}
	return 0;
}