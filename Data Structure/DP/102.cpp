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
ll solve(ll n,ll k,ll arr[])
{
	ll ncr[n+1][n+1];
	for(ll i=0;i<=n;i++)
	{
		for(ll j=0;j<=i;j++)
		{
			if(j==i||j==0)
			{
				ncr[i][j]=1;
			}
			else ncr[i][j]=(ncr[i-1][j-1]+ncr[i-1][j])%mod;
		}
	}
	// for(int i=0;i<k;i++) cout<<arr[i]<<"\n";
	ll dp[k+1]={0};
	dp[0]=1;
	ll cnt=0;
	for(ll i=0;i<k;i++)
	{
		dp[i+1]=(dp[i]%mod*ncr[cnt+arr[i]-1][arr[i]-1])%mod;
		cnt+=arr[i];
	}
	return dp[k];
}
int main(void)
{
	FIO	
	ll n=0,k;
	cin>>k;
	ll arr[k];
	for(ll i=0;i<k;i++) cin>>arr[i],n+=arr[i];
	cout<<solve(n,k,arr)<<"\n";
	return 0;
}