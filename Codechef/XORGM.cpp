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
ll tp;
int main(void)
{
	FIO	
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<ll> a(n),c(n);
		ll xr=0;
		vector<int> ans(n);
		map<ll,ll> mp;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
			xr^=a[i];
		}	
		for(int i=0;i<n;i++)
		{
			cin>>c[i];
			mp[c[i]]++;
			xr^=c[i];
		}
		ll eq=xr;
		int fl=0;
		for(int i=0;i<n;i++)
		{
			tp=eq^a[i];
			if(mp.find(tp)==mp.end()||mp[tp]<=0)
			{
				fl=-1;
				break;
			}
			mp[tp]--;
			ans[i]=tp;
		}
		if(fl) cout<<fl<<endl;
		else
		{
			for(int i=0;i<n;i++) cout<<ans[i]<<" ";
				cout<<endl;
		}
	}
	return 0;
}