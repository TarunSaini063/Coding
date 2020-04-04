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
	ll m,n;
	bool fl=true;
	while(t--)
	{
		fl=false;
		cin>>n>>m;
		ll x=(sqrt(1+8*m)-1)/2;
		ll y=x*(x+1)/2;
		y-=x;
		for(ll i=x;i<=n;i++)
		{
			y+=i;
			if(y>=m) cout<<i<<endl,fl=true;
		 	if(fl) break;
		}
		if(!fl) cout<<-1<<endl;
	}
	return 0;
}