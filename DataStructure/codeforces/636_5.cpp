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
vector<vector<int>> adj;
void bfs(int a,vector<int> &arr)
{
	queue<int> q;
	arr[a]=0;
	q.push(a);
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		for(auto j : adj[x])
		{
			if(arr[j]==INT_MAX)
			{
				q.push(j);
				arr[j]=arr[x]+1;
			}
		}
	}
}
int main(void)
{
	FIO	
	int t;
	cin>>t;
	while(t--)
	{
		int m,n,a,b,c,u,v;
		cin>>n>>m>>a>>b>>c;
		adj=vector<vector<int>>(n);
		a--,b--,c--;
		vector<int> wt(m);
		vector<ll> pre(m+1,0);
		for(auto &i:wt) cin>>i;
		sort(all(wt));
		for(int i=0;i<m;i++) pre[i+1]+=wt[i]+pre[i];
		for(int i=0;i<m;i++)
		{
			cin>>u>>v;
			u--,v--;
			adj[u].pb(v);
			adj[v].pb(u);
			// cout<<u<<" "<<v<<" ";
		}
		vector<int> da(n,INT_MAX),db(n,INT_MAX),dc(n,INT_MAX);
		bfs(a,da);bfs(b,db);bfs(c,dc);
		ll ans=1e18;
		for(int i=0;i<n;i++)
		{
			ll sm=da[i]+db[i]+dc[i];
			if(sm>m) continue;
			ans=min(ans,pre[db[i]]+pre[da[i]+db[i]+dc[i]]);
		}
		cout<<ans<<"\n";
	}
	return 0;
}