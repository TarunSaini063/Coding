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
const int mxn = 1e5;
vector<int>adj[mxn], par(mxn), level(mxn);
vector<vector<int>>dp(mxn, vector<int>(20, -1));
int mx;
void dfs(int id, int p, int h) {
	dp[id][0] = p;
	par[id] = p;
	level[id] = h;
	for (int i : adj[id]) {
		if (i == p) continue;
		dfs(i, id, h + 1);
	}
}
int query(int a, int b) {
	if (level[a] > level[b]) swap(a, b);
	int d = level[b] - level[a];
	while (d > 0) {
		int nt = log2(d);
		b = dp[b][nt];
		d -= (1 << nt);
	}
	if (a == b) return a;
	for (int i = mx; i >= 0; i-- ) {
		if (dp[b][i] != -1 && dp[a][i] != dp[b][i]) {
			b = dp[b][i], a = dp[a][i];
		}
	}
	return par[a];
}
int main(void)
{
	FIO
	int t = 1;
	while (t--)
	{
		int n;
		cin >> n;
		int nt = log2(n) + 1;
		mx = nt;
		for (int i = 0; i < n - 1; i++) {
			int a, b;
			cin >> a >> b;
			adj[a].pb(b);
			adj[b].pb(a);
		}
		dfs(1, -1, 0);
		for (int i = 1; i <= nt; i++) {
			for (int j = 1; j <= n; j++) {
				int par = dp[j][i - 1];
				if (par != -1) {
					dp[j][i] = dp[par][i - 1];
				}
			}
		}
		for (int i = 1, j = 0; i <= n; i++, j = 0) {
			while (dp[i][j] != -1) cout << dp[i][j++] << " ";
			cout << '\n';
		}
		int q = 0;
		cin >> q;
		while (q--) {
			int a, b;
			cin >> a >> b;
			// cout << query(a, b) << '\n';
		}
	}
	return 0;
}