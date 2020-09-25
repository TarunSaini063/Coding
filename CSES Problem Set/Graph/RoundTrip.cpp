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
const int mxn = 2e5 + 1;
vector<int> adj[mxn], par(mxn), vis(mxn);
int se = -1, ss = -1;
bool dfs(int v, int p) {
	vis[v] = 1;
	for (int u : adj[v]) {
		if (u == p) continue;
		if (vis[u] == 0) {
			par[u] = v;
			if (dfs(u, v))return true;
		}
		else if (vis[u] == 1) {
			se = v;
			ss = u;
			return true;
		}
	}
	vis[v] = 2;
	return false;
}
int main(void)
{
	FIO
	int t = 1;
	// cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		for (int i = 0; i < m; i++) {
			int a, b;
			cin >> a >> b;
			adj[a].pb(b);
			adj[b].pb(a);
		}
		for (int i = 1; i <= n; i++) {
			if (vis[i] == 0 && dfs(i, par[i])) {
				break;
			}
		}
		if (se == -1) cout << "IMPOSSIBLE\n";
		else {
			vector<int> ans;
			ans.pb(ss);
			for (int i = se; i != ss; i = par[i]) ans.pb(i);
			ans.pb(ss);
			cout << sz(ans) << "\n";
			for (int i = sz(ans) - 1; i >= 0; i--) cout << ans[i] << " ";
			cout << "\n";
		}
	}
	return 0;
}