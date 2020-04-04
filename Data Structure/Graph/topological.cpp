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
const int mx=1e4+5;
vector<int> v[mx],order;
vector<bool> visited(mx,false);
void topo(int n)
{
	if(visited[n]) return;
	visited[n]=true;
	for(auto j : v[n])
	{
		if(!visited[j])topo(j);
	}
	order.pb(n);
}
int main(void)
{
	FIO	
	int n,e,x,y;
	cin>>n>>e;
	for(int i=0;i<e;i++)
	{
		cin>>x>>y;
		v[x].pb(y);
	}
	for(int i=1;i<=n;i++)
	{
		topo(i);
	}
	cout<<"order "<<"\n";
	for(auto j : order) cout<<j<<" ";
	return 0;
}