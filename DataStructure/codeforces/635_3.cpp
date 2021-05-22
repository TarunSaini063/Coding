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
vector<int> v[200005];
vector<int> ht;
int dfs(int i,int p,int d)
{
	int sub=1;
	for(auto j : v[i])
	{
		if(j!=p) 
		{
			sub+=dfs(j,i,d+1);
		}
	}
	ht.pb(d-sub+1);
	return sub;
}
int main(void)
{
	FIO	
	int n,k,a,b;
	cin>>n>>k;
	for(int i=0;i<n-1;i++)
	{
		cin>>a>>b;
		v[a].pb(b);
		v[b].pb(a);
	}
	dfs(1,-1,0);
	sort(all(ht),greater<int>());
	int ans=0;
	for(int i=0;i<k;i++) ans+=ht[i];
	cout<<ans<<"\n";
	return 0;
}
    