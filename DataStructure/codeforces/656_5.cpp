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
int n, fl;
vector<vector<int>> adj;
vector<bool> visited, stk;
vector<int> ans;

bool dfs(int v) {
	if (!visited[v]) {
		visited[v] = true;
		stk[v] = true;
		for (int u : adj[v]) {
			if (!visited[u] && dfs(u))
			{
				return true;
			}
			else if (stk[u]) {
				return true;
			}
		}
		ans.pb(v);
	}
	stk[v] = false;
	return false;
}
int main(void)
{
	FIO
	int t;
	cin >> t;
	while (t--)
	{
		int n, m, u, v, s;
		cin >> n >> m;
		fl = 0;
		adj.clear();
		adj.assign(n + 1, vector<int>());
		ans.clear();
		stk.assign(n + 1, false);
		visited.assign(n + 1, false);
		vector<pair<int, int>> undir, dir;
		for (int i = 0; i < m; i++) {
			cin >> s >> u >> v;
			if (s == 0) undir.pb(mk(u, v));
			else {
				adj[u].pb(v);
				dir.pb(mk(u, v));
			}
		}
		for (int i = 1; i <= n; ++i) {
			if (dfs(i)) {
				fl = 1;
				break;
			}
		}
		if (fl == 1) {
			cout << "NO\n";
			continue;
		}
		// reverse(ans.begin(), ans.end());
		// cout << "topo\n";
		// for (auto i : ans) cout << i << " ";
		// cout << "\n";
		int id[n + 1];
		for (int i = 0; i < sz(ans); i++) {
			id[ans[i]] = i;
		}
		cout << "YES\n";
		for (auto i : dir) cout << i.ff << " " << i.ss << "\n";
		for (auto i : undir) {
			u = i.ff;
			v = i.ss;
			if (id[u] > id[v])
				cout << u << " " << v << '\n';
			else cout << v << " " << u << "\n";
		}
	}
	return 0;
}