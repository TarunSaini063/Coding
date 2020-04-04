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
		ll m,n,q,a,b,xa,ya;
		cin>>n>>m>>q;
		multiset<ll> x,y,mx,my;
		x.insert(0);x.insert(n);
		y.insert(0);y.insert(m);
		mx.insert(n);my.insert(m);
		while(q--)
		{
			cin>>a>>b;
			if(a==0)
			{
				if(x.find(b)!=x.end())
				{
					auto it=mx.end();
					it--;
					xa=*it;
				}
				else
				{
					auto it=x.upper_bound(b);
					auto it1=it;
					it--;
					ll x1=*it;
					ll x2=*it1;
					// cout<<"x1 x2 "<<x1<<" "<<x2<<endl;
					auto it3=mx.find(x2-x1);
					mx.erase(it3);
					mx.insert(b-x1);mx.insert(x2-b);
					it=mx.end();
					it--;
					xa=*it;
					// cout<<"xa "<<xa<<endl;
				}
				x.insert(b);
				auto it=my.end();
				it--;
				ya=*it;
			}
			else
			{
				if(y.find(b)!=y.end())
				{
					auto it=my.end();
					it--;
					ya=*it;
				}
				else
				{
					auto it=y.upper_bound(b);
					auto it1=it;
					it--;
					ll y1=*it;
					ll y2=*it1;
					auto it3=my.find(y2-y1);
					my.erase(it3);
					my.insert(b-y1);my.insert(y2-b);
					it=my.end();
					it--;
					ya=*it;
				}
				auto it=mx.end();
				y.insert(b);
				it--;
				xa=*it;
			}
			cout<<xa*ya<<endl;
		}
	}
	return 0;
}