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
const int mxn = 2e5+10;
vector<pair<int,ll>> adj[mxn];
ll dp[mxn];
map<ll,vector<ll>> ct;
int n,m,k;

void dij(int src){
	set<pair<ll,int>> s;
	s.insert(mk(0,1));
	dp[1] = 0;
	while(!s.empty()){
		pair<ll,int> from = *s.begin();
		s.erase(s.begin());
		for(auto to : adj[from.ss] ){
			ll dis = dp[from.ss] + to.ss;
			if(dis < dp[to.ff]){
				s.erase(mk(dp[to.ff],to.ff));
				dp[to.ff] = dis;
				s.insert(mk(dp[to.ff],to.ff));
			}
		}
	}
}
int main(void)
{
	FIO	
	cin>>n>>m>>k;
		for(int i = 0; i<=n+1;i++) dp[i] = 1e17;
	
	for(int i = 0;i<m;i++){
		ll u,v,w;
		cin>>u>>v>>w;
		adj[u].pb(mk(v,w));
		adj[v].pb(mk(u,w));
	}
	
	int ans = 0;
	
	for(int i =0; i<k; i++){
		int city;
		ll dis;
		cin>>city>>dis;
		ct[city].pb(dis);
		dp[city]= dis;
		// if(dp[city]<=dis) ans++,cout<<dis<<"\n";
	}
	dij(1);
	for(int i =1; i<=n;i++) cout<<dp[i]<<" "; 
		cout<<'\n';
	for(auto i: ct){
		for(ll j: i.ss){
			if(dp[i.ff]<j) ans++;
		}
	}
	cout<<ans<<"\n";
	return 0;
}