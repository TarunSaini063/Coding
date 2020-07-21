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
vector<vector<int>> adj;
vector<int> dp;
int dfs(int v) {
	int mx = -1;
	for (auto u : adj[v]) {
		if (dp[u] == -1) dfs(u);
		mx = max(mx, dp[u]);
	}
	return dp[v] = mx + 1;
}

int main(void)
{
	FIO
	int t = 1;
	// cin>>t;
	while (t--)
	{
		int n, m, u, v;
		cin >> n >> m;
		adj.assign(n + 1, vector<int>());
		dp.assign(n + 1, -1);
		for (int i = 0; i < m; i++) {
			cin >> u >> v;
			adj[u].pb(v);
		}
		for (int i = 1; i <= n; i++) {
			if (dp[i] == -1)dfs(i);
		}
		cout << *max_element(all(dp)) << "\n";

	}
	return 0;
}