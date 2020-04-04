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
ll min(ll n,ll x)
{
	if(n<=x) return n;
	return x;
}
int main(void)
{
	FIO	
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		ll sm=0;
		if(n<=250000)cout<<n<<endl;
		else{
		 if(n>250000)sm+=(min(n,500000)-250000)*(0.05);
		 if(n>500000) sm+=(min(n,750000)-500000)*(0.1);
		 if(n>750000) sm+=(min(n,1000000)-750000)*(0.15);
		 if(n>1000000) sm+=(min(n,1250000)-1000000)*(0.2);
		 if(n>1250000) sm+=(min(n,1500000)-1250000)*(0.25);
		if(n>1500000) sm+=(n-1500000)*(0.3);
		cout<<n-sm<<endl;}
	}
	return 0;
}