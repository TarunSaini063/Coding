#include <bits/stdc++.h>
using namespace std;
#define ld double
#define ll long long
#define pb push_back
#define mk make_pair
#define mod 1000000007
#define ff first
#define ss second
#define sz(x) (int)x.size()
#define ar array
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(x) x.begin(),x.end()
ll power(ll a, ll b) {ll res = 1; a = a % mod; while (b) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b /= 2;} return res;}
ll invmod(ll a) {return power(a, mod - 2);}
const int mxn = 1e5 + 1;
ll n, vis[mxn], dis[mxn];
vector<ar<ll, 2>> adj[mxn];
vector<int> adj2[mxn];
void dfs(int id) {
	if (id == n) {
		dis[id] = 1;
		return;
	}
	vis[id] = 1;
	for (int i : adj2[id]) {
		if (vis[i] == 0) {
			dfs(i);
		}
		dis[id] = (dis[id] % mod + dis[i] % mod) % mod;
	}
	vis[id] = 2;
}
void dfs1(int id) {
	if (id == n) {
		dis[id] = 1;
		return;
	}
	else dis[id] = 1e9;
	vis[id] = 1;
	for (int i : adj2[id]) {
		if (vis[i] == 0) {
			dfs1(i);
		}
		dis[id] = min(dis[id], dis[i] + 1);
	}
	vis[id] = 2;
}
void dfs2(int id) {
	if (id == n) {
		dis[id] = 1;
		return;
	}
	else dis[id] = -1e9;
	vis[id] = 1;
	for (int i : adj2[id]) {
		if (vis[i] == 0) {
			dfs2(i);
		}
		dis[id] = max(dis[id], dis[i] + 1);
	}
	vis[id] = 2;
}
void dij(int id) {
	set<ar<ll, 2>> s;
	for (int i = 1; i <= n; i++) dis[i] = 1e15;
	dis[id] = 0;
	s.insert({dis[id], id});
	while (!s.empty()) {
		int u = (*s.begin())[1];
		s.erase(s.begin());
		for (ar < ll, 2> tmp : adj[u]) {
			int to = tmp[1];
			int len = tmp[0];
			if (dis[to] > dis[u] + len) {
				s.erase({dis[to], to});
				dis[to] = dis[u] + len;
				s.insert({dis[to], to});
			}
		}
	}
}
int main(void)
{
	FIO
	int t = 1;
	// cin >> t;
	while (t--)
	{
		int m;
		cin >> n >> m;
		for (int i = 0; i < m; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			adj[a].pb({c, b});
		}
		dij(1);
		ll mn_dis = dis[n];
		for (int i = 1; i <= n; i++) {
			for (ar<ll, 2> tmp : adj[i]) {
				if (dis[i] + tmp[0] == dis[tmp[1]]) {
					adj2[i].pb(tmp[1]);
				}
			}
		}
		for (int i = 1; i <= n; i++) dis[i] = 0;
		dfs(1);
		ll tot_path = dis[1];
		for (int i = 1; i <= n; i++) vis[i] = 0;
		dfs1(1);
		ll min_path_node = dis[1] - 1;
		for (int i = 1; i <= n; i++) vis[i] = 0;
		dfs2(1);
		ll max_path_node = dis[1] - 1;
		cout << mn_dis << " " << tot_path << " " << min_path_node << " " << max_path_node << '\n';
	}
	return 0;
}