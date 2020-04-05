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
ll gcd(ll a,ll b)
{
	while(b)
	{
		a%=b;
		swap(a,b);
	}
	return a;
}
int main(void)
{
	FIO	
	int t;
	cin>>t;
	while(t--)
	{
		ll a,b;
		cin>>a>>b;
		while(true)
		{
			if(b==1) {cout<<"Yes"<<endl;break;}
			a=gcd(a,b);
		    if(a==1) {cout<<"No"<<endl;break;}
		    b/=a;
		}
	}
	return 0;
}