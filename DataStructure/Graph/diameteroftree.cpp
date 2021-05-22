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
vector<int> height(mx,0),nd(mx,-1),out(mx,0);
vector<int> adj[mx];
void ht(int i,int p)
{
	height[i]=0;
	for(auto j : adj[i])
	{
		if(j==p) continue;
		ht(j,i);
		height[i]=max(height[i],1+height[j]);
	}
}
void dia(int node,int parent)
{
	int mx1,mx2;
	mx1=mx2=-1;
	for(auto j : adj[node])
	{
		if(j==parent)continue;
		if(height[j]>=mx1) mx2=mx1,mx1=height[j];
		else if(height[j]>mx2) mx2=height[j];
	}
	for(int j : adj[node])
	{
		if(j==parent)continue;
		int use=mx1;
		if(height[j]==mx1) use=mx2;
		out[j]=max(2+use,1+out[node]);
		dia(j,node);
	}
}
int main(void)
{
	FIO	
	int n,x,y;
	cin>>n;
	for(int i=0;i<n-1;i++)
	{
		cin>>x>>y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	ht(1,-1);
	dia(1,-1);
	for(int i=1;i<=n;i++) cout<<max(out[i],height[i])<<" ";
	cout<<"\n";
	return 0;
}
// 10
// 1 2
// 1 3
// 1 4
// 2 5
// 2 6
// 3 7
// 4 8
// 7 9
// 7 10