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
bool lap(ll a,ll b,ll c,ll d)
{
	if(a>d||b<c) return false;
	return true;
}
int main(void)
{
	FIO	
	int t;
	cin>>t;
	while(t--)
	{
		ll n,a,b,c,d;
		cin>>n>>a>>b>>c>>d;
		if(lap(n*(a-b),n*(a+b),c-d,c+d)) cout<<"Yes"<<"\n";
		else cout<<"No"<<"\n";
	}
	return 0;
}