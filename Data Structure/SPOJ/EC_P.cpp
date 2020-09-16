#include <bits/stdc++.h>
using namespace std;
#define ld double
#define ll long long
#define pb emplace_back
#define mk make_pair
#define mod 1000000007
#define ff first
#define ss second
#define sz(x) (int)x.size()
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define all(x) x.begin(),x.end()
ll power(ll a, ll b) {ll res = 1; a = a % mod; while (b) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b /= 2;} return res;}
ll invmod(ll a) {return power(a, mod - 2);}
const int mxn = 1e3;
vector<int> adj[mxn];
int vis[mxn], tin[mxn], low[mxn], timer = 0, bridge;
vector<pair<int, int>> ans;
void dfs(int id, int p) {
	tin[id] = low[id] = timer++;
	vis[id] = 1;
	for (int i : adj[id]) {
		if (i == p) continue;
		if (vis[i] == 0) {
			dfs(i, id);
			if (tin[id] < low[i]) {
				if (id < i)
					ans.pb(mk(id, i));
				else
					ans.pb(mk(i, id));
			}
			low[id] = min(low[i], low[id]);
		}
		else low[id] = min(low[id], tin[i]);
	}
}
int main(void)
{
	FIO
	int t, nc = 0;
	cin >> t;
	while (t--)
	{
		nc++;
		int n, m, a, b;
		cin >> n >> m;
		bridge = timer = 0;
		for (int i = 0; i <= n; i++) adj[i].clear(), tin[i] = 0, low[i] = 0, vis[i] = 0;
		for (int i = 0; i < m; i++) {
			cin >> a >> b;
			adj[a].pb(b);
			adj[b].pb(a);
		}
		cout << "Caso #" << nc << "\n";
		for (int i = 1; i <= n; i++)
			if (vis[i] == 0)dfs(i, 0);
		if (sz(ans) == 0) cout << "Sin bloqueos\n";
		else {
			sort(all(ans));
			cout << sz(ans) << "\n";
			for (auto i : ans) {
				cout << i.ff << " " << i.ss << "\n";
			}
			ans.clear();
		}
	}
	return 0;
}