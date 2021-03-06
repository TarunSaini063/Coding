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
const int mxn = 2e5 + 1;
int dp[20][mxn], par[mxn], level[mxn], ans[mxn], cnt[mxn];
vector<int> adj[mxn];
void dfs(int id, int p, int l) {
	dp[0][id] = p;
	level[id] = l;
	par[id] = p;
	for (int i : adj[id]) {
		if (i != p) {
			dfs(i, id, l + 1);
		}
	}
}
int lca(int a, int b) {
	if (level[a] > level[b]) swap(a, b);
	int d = level[b] - level[a];
	while (d) {
		int k = log2(d);
		b = dp[k][b];
		d -= (1 << k);
	}
	if (a == b) return a;
	for (int i = 19; i >= 0; i--) {
		if (dp[i][b] != -1 && dp[i][a] != dp[i][b]) {
			a = dp[i][a];
			b = dp[i][b];
		}
	}
	return par[b];
}
void dfs1(int id, int p) {
	for (int i : adj[id]) {
		if (i != p) {
			dfs1(i, id);
			cnt[id] += cnt[i];
		}
	}
	ans[id] = cnt[id];
}
int main(void)
{
	FIO
	int t = 1;
	// cin >> t;
	while (t--)
	{
		int n, q;
		cin >> n >> q;
		for (int i = 0; i < n - 1; i++) {
			int x, y;
			cin >> x >> y;
			adj[x].pb(y);
			adj[y].pb(x);
		}
		memset(dp, -1, sizeof(dp));
		dfs(1, -1, 0);
		for (int i = 1; i < 20; i++) {
			for (int j = 1; j <= n; j++) {
				int p = dp[i - 1][j];
				if (p != -1) {
					dp[i][j] = dp[i - 1][p];
				}
			}
		}
		while (q--) {
			int a, b;
			cin >> a >> b;
			cnt[a]++;
			cnt[b]++;
			int com = lca(a, b);
			cnt[com]--;
			if (dp[0][com] != -1) cnt[dp[0][com]]--;
		}
		dfs1(1, -1);
		for (int i = 1; i <= n; i++) cout << ans[i] << " ";
	}
	return 0;
}