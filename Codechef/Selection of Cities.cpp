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
ll power(ll n)
{
	ll ans=1,ep=2;
	while(n)
	{
		if(n&1) ans=(ans*ep)%mod;
		ep=(ep*ep)%mod;
		n/=2;
	}
	return ans;
}
int main(void)
{
	FIO	
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		cout<<power(n)-1<<endl;
	}
	return 0;
}