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
		if((n/2)%2!=0) cout<<"NO"<<"\n";
		else
		{
			vector<ll> odd,even;
			ll x=2;
			for(int i=1;i<=n/4;i++)
			{
				
				even.pb(x);odd.pb(x-1);x+=2;
				even.pb(x+2);odd.pb(x+1);x+=4;
			}
			cout<<"YES"<<"\n";
			for(auto j : even) cout<<j<<" ";
			for(auto j : odd) cout<<j<<" ";
			cout<<"\n";
		}
	}
	return 0;
}