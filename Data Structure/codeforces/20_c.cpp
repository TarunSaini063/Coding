#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007

int main(){
	ll n, m, u, v, w;
		cin >> n >> m;
		vector<pair<ll, ll>> adj[n + 1];
	for(int i=0;i<m;i++){
		ll a,b,w;
		cin>>a>>b>>w;
		adj[a].push_back(make_pair(b,w));
		adj[b].push_back(make_pair(a,w));
	}
	vector<ll>dist(n + 1, 1e12), par(n + 1,-1);
	set<pair<ll,ll>>s;
	int src = 1;
	dist[src]=0;
	s.insert(make_pair(dist[src],src));
	par[1]=-1;
	while(!s.empty()){
		pair<ll,ll> temp = *s.begin();
		s.erase(s.begin());
		for(pair<ll,ll> to : adj[temp.second]){
			int dis = dist[temp.second] + to.second;
			if(dis < dist[to.first]){
				s.erase(make_pair(dist[to.first],to.first));
				dist[to.first] = dis;
				s.insert(make_pair(dist[to.first],to.first));
				par[to.first] = temp.second;
			}
		}
	}
	if(dist[n]==1e12){
		cout<<"-1\n";
		return 0;
	}
		vector<ll>ans;
		for(ll i = par[n];i!=1;i=par[i])ans.push_back(i);
			ans.push_back(1);
		reverse(ans.begin(),ans.end());
		ans.push_back(n);
		for(ll i=0;i<ans.size();i++)cout<<ans[i]<<" ";
}