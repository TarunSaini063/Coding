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
	vector<int>arr(n);
	map<int,int> mp;
	for(auto &j : arr) cin>>j;
	vector<vector<int>> dp(n,vector<int>(n,-1));
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			dp[i][j]=2;
			int nxt=2*arr[i]-arr[j];
			if(mp.find(nxt)!=mp.end())
			{
				dp[i][j]=max(dp[i][j],dp[mp[nxt]][i]+1);
			}
		}
		mp[arr[i]]=i;
	}
	int ans=0;
	for(auto j : dp)
	{
		for(auto i :j) ans=max(ans,j);
	}
	cout<<ans<<"\n";
	return 0;
}