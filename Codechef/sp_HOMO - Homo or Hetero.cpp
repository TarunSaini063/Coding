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
	int n;
	int ho=0,ht=0;
	cin>>n;
	map<ll,int> mp;
	while(n--)
	{
		string s;
		ll x;
		cin>>s>>x;
		if(s=="insert")
		{
			mp[x]++;
			if(mp[x]>=2) ho++;
			else if(mp[x]==1) ht++;
		}
		else
		{
			if(mp[x]>0)
			{
				mp[x]--;
				if(mp[x]==1) ho--;
				else if(mp[x]==0) ht--;
			}
		}
		if(ho>=1&&ht>=2) cout<<"both"<<endl;
		else if(ho>=1) cout<<"homo"<<endl;
		else if(ht>=2) cout<<"hetero"<<endl;
		else cout<<"neither"<<endl;
	}
	return 0;
}