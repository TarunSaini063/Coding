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
const int mxn = 2501;
ll dis[mxn], vis[mxn], n;
vector<int> grp[mxn];
struct edge {
	ll to, from, wt;
};
void dfs(int id) {
	vis[id] = 1;
	for (int i : grp[id]) {
		if (!vis[i]) dfs(i);
	}
}
int main(void)
{
	FIO
	int t = 1;
	// cin >> t;
	while (t--)
	{
		int  m;
		cin >> n >> m;
		edge adj[m];
		for (int i = 0; i < m; i++)
		{
			cin >> adj[i].from >> adj[i].to >> adj[i].wt;
			grp[adj[i].from].pb(adj[i].to);
			adj[i].wt = -adj[i].wt;
		}
		for (int i = 1; i <= n; i++) dis[i] = 1e15;
		dis[1] = 0;
		for (int i = 0; i < n - 1; i++) {
			int x = 0;
			for (edge e : adj) {
				if (dis[e.from] < 1e15) {
					if (dis[e.to] > dis[e.from] + e.wt) {
						dis[e.to] = e.wt + dis[e.from];
						x = 1;
					}
				}
			}
			if (!x) break;
		}
		int neg = -1;
		for (edge e : adj) {
			if (dis[e.from] < 1e15) {
				if (dis[e.to] > dis[e.from] + e.wt) {
					dis[e.to] = e.wt + dis[e.from];
					neg = e.to;
					if (e.to == n) {
						cout << "-1\n";
						return 0;
					}
				}
			}
		}
		if (neg != -1) {
			dfs(neg);
		}
		if (vis[n]) cout << "-1\n";
		else cout << -dis[n] << "\n";
	}
	return 0;
}