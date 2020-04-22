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
int lcs(string a,string b)
{
	int n=a.size();
	int m=b.size();
	int dp[n+1][m+1];
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			if(i==0||j==0) dp[i][j]=0;
			else if(a[i-1]==b[j-1]) dp[i][j]=1+dp[i-1][j-1];
			else dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
		}
	}
	return dp[n][m];
}

int main(void)
{
	FIO	
	int t;
	cin>>t;
	while(t--)
	{
		string s,r;
		cin>>s;
		r=s;
		reverse(all(r));
		int tp=lcs(r,s);
		cout<<s.size()-tp<<"\n";
	}
	return 0;
}