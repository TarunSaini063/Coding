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
		int n;
		cin>>n;
		vector<int> arr(n),id[201];
		vector<vector<int>> dp(201,vector<int>(n,0));
		for(int i=0;i<n;i++) cin>>arr[i];
		for(int i=1;i<=200;i++)
		{
			dp[i][0]=arr[0]==i?1:0;
			if(arr[0]==i) id[i].pb(0);
			for(int j=1;j<n;j++)
			{
				dp[i][j]=dp[i][j-1]+(arr[j]==i?1:0);
				if(arr[j]==i) id[i].pb(j);
			}
		}
		// for(int i=1;i<=1;i++,cout<<"\n")
		// 	for(auto j : dp[i]) cout<<j<<" ";
		int ans=0;
		for(int i=1;i<=200;i++)
		{
			ans=max(ans,dp[i][n-1]);
			for(int j=1;j<=200;j++)
			{
				int to,fo,md,tp=0;
				if(i!=j)
				{

					for(int k=1;k<=(int)id[i].size()/2;k++)
					{
						// cout<<i<<" "<<j<<" "<<k<<"   ";
						to=id[i][k-1];
						fo=id[i][id[i].size()-k];
						// cout<<to<<" "<<fo<s<"   ";
						if(to>fo) break;
						md=dp[j][fo]-dp[j][to];
						tp=max(tp,2*k+md);
					}
				}
				ans=max(ans,tp);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}