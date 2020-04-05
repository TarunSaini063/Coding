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
bool onlyab(int n,int a,int b)
{
	while(n)
	{
		if(n%10==a||n%10==b) n/=10;
		else return false;
	}
	return true;
}
int main(void)
{
	FIO	
	ll a,b,n,sm,ans=0,z;
	ll fact[1000002];
	fact[0]=1;
	for(int i=1;i<=1000001;i++) fact[i]=(fact[i-1]*i)%mod;
	cin>>a>>b>>n;
	for(int i=0;i<=n;i++)
	{
		sm=a*i+(n-i)*b;
		if(onlyab(sm,a,b))
		{
			z=(fact[i]*fact[n-i])%mod;
			z=invmod(z);
			ans=(ans+fact[n]*z)%mod;
		}
	}
	cout<<ans<<endl;
	return 0;
}