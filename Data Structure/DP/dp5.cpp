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
		int p,q;
		cin>>p>>q;
		string a,b;
		cin>>a>>b;
		int dp[p+1][q+1];
		for(int i=0;i<=p;i++)
		{
			for(int j=0;j<=q;j++)
			{
				if(i==0||j==0) dp[i][j]=max(i,j);
				else if(a[i-1]==b[j-1]) dp[i][j]=dp[i-1][j-1];
				else dp[i][j]=1+min({dp[i-1][j-1],dp[i-1][j],dp[i][j-1]});
			}
		}
		cout<<dp[p][q]<<"\n";
	}
	return 0;
}