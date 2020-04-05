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
		ll m,n,l,r,c,p,q,s,a,b;
		cin>>n>>m>>l>>r>>c>>p>>q>>s;
		ll cost[n+2]={0};
		for(int i=1;i<=m;i++)
		{
			cost[l]+=c;
			cost[r+1]-=c;
			a=(l*p+r)%n+1;
			b=(r*q+l)%n+1;
			l=min(a,b);
			r=max(a,b);
			c=(c*s)%1000000+1;
		}
		for(ll i=1;i<=n;i++) cost[i]+=cost[i-1];
		a=b=0;
		for(ll i=1;i<=n;i++)
		{
			if(cost[i]>a)
			{
				a=cost[i];
				b=i;
			}
		}
		cout<<b<<" "<<a<<endl;
	}
	return 0;
}