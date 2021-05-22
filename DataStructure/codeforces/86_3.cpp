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
ll solve(ll r,ll lcm,ll b)
{
	ll ans=r/lcm*b;
	ans+=(min(r%lcm,b-1));
	return r-ans;
}
int main(void)
{
	FIO	
	int t;
	cin>>t;
	while(t--)
	{
		ll a,b,q;
		ll l,r;
		cin>>a>>b>>q;
		if(a>b) swap(a,b);
		while(q--)
		{
			cin>>l>>r;
			ll lcm=(a*b)/__gcd(a,b);
			cout<<solve(r,lcm,b)-solve(l-1,lcm,b)<<" ";
		}cout<<"\n";
	}
	return 0;
}