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
		string s;
		cin>>s;
		int dp[n];
		int fl=0;
		if(s[0]=='0') {cout<<0<<"\n"; continue;}
		dp[0]=1;
		if(n>1)
		{
			int x=(s[0]-'0')*10+(s[1]-'0');dp[1]=0;
			if(x<=26&&x>0) dp[1]=1;
			if(s[1]!='0') dp[1]++;
			for(int i=2;i<n;i++)
			{
				x=(s[i-1]-'0')*10+(s[i]-'0');dp[i]=0;
				if(x==0)
				{
					fl=1;
					break;
				}
				if(s[i-1]!='0'&&x<=26&&x>0) dp[i]=dp[i-2];
				if(s[i]!='0') dp[i]+=dp[i-1];
			}
		}
		// for(auto j : dp)cout<<j<<" ";
		if(fl) cout<<0<<"\n";
		else cout<<dp[n-1]<<"\n";
	}
	return 0;
}