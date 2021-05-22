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
const int mxn = 5e5;
vector<ll> adj[mxn];
ll tin[mxn], low[mxn], timer = 0, vis[mxn], bridge = 0;
void dfs(ll id, ll p) {
	tin[id] = low[id] = timer++;
	vis[id] = 1;
	for (ll i : adj[id]) {
		if (i == p) continue;
		if (vis[i] == 0) {
			dfs(i, id);
			if (tin[id] < low[i]) bridge++;// cout << id << " " << i << "\n";
			low[id] = min(low[id], low[i]);
		}
		else {
			low[id] = min(low[id], tin[i]);
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
		ll n, m, a, b;
		cin >> n >> m;
		for (ll i = 0; i < m; i++) {
			cin >> a >> b;
			adj[a].pb(b);
			adj[b].pb(a);
		}
		for (int i = 1; i <= n; i++)
			if (vis[i] == 0)
				dfs(i, 0);
		ll tot = n * (n - 1) / 2;
		ll bad = m - bridge;
		ld ans = 1.0 - 1.0 * bad / tot;
		cout << fixed << setprecision(5) << ans;
	}
	return 0;
}