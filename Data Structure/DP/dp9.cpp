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
		int n,m;
		cin>>n>>m;
		string s1,s2;
		cin>>s1>>s2;
		int dp[n+1][m+1];
		int mx=0;
		for(int i=0;i<=n;i++)
		{
			for(int j=0;j<=m;j++)
			{
				if(i==0||j==0) dp[i][j]=0;
				else if(s1[i-1]==s2[j-1]) dp[i][j]=dp[i-1][j-1]+1,mx=max(mx,dp[i][j]);
				else dp[i][j]=0;
			}
		}
		cout<<mx<<"\n";
	}
	return 0;
}