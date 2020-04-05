#include <bits/stdc++.h>
using namespace std;
#define ld double
#define ll long long
#define pb emplace_back
#define mk make_pair
#define mod 1000003
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
	ll arr[mod];
	arr[0]=0;
	arr[1]=1;
	for(int i=2;i<mod;i++) arr[i]=((arr[i-1]%mod)*(i%mod))%mod;
	cin>>t;
	while(t--)
	{
		ll n,x;
		cin>>n>>x;
		if(n>=mod) cout<<0<<endl;
		else cout<<((x%mod)*(arr[n]%mod))%mod<<endl;
	}	
	return 0;
}