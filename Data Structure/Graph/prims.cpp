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
vector<pair<int,int>> graph[mx];
vector<bool> marked(mx,false);
int prims()
{
	pair<int,int> p;
	int ans=0,x;
	p=mk(0,1);
	priority_queue<pair<int,int>,vector<pair<int,int>> ,greater<pair<int,int>>> Q;
	Q.push(p);
	while(!Q.empty())
	{
		p=Q.top();
		Q.pop();
		x=p.ss;
		if(marked[x]) continue;
		marked[x]=true;
		ans+=p.ff;
		for(auto j : graph[x])
		{
			if(!marked[j.ss]) Q.push(j);
		}
	}
	return ans;
}
int main(void)
{
	FIO	
	int n,e,x,y,w;
	cin>>n>>e;
	for(int i=0;i<e;i++)
	{
		cin>>x>>y>>w;
		graph[x].pb(mk(w,y));
		graph[y].pb(mk(w,x));
	}
	int ans=prims();
	cout<<ans<<endl;
	return 0;
}