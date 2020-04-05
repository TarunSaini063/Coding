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
ll power(ll a,ll b)
{
	ll ans=1;
	a=a%mod;
	while(b)
	{
		if(b&1) ans=(ans*a)%mod;
		a=(a*a)%mod;
		b/=2;
	}
	return ans;
}
int main(void)
{
	FIO	
	ll a,b;
	cin>>a>>b;
	cout<<power(a,b)<<endl;
	return 0;
}