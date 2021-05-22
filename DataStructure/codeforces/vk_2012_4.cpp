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
const int mxn = 5e4 + 1;
vector<int> adj[mxn];
ll dp[mxn][510], k, n, tp = 0;
void dfs(int v, int p)
{
	dp[v][0] = 1;
	for (int u : adj[v]) {
		if (u != p) {
			dfs(u, v);
			for (int x = 0; x <= k; x++) {
				tp += dp[v][x] * dp[u][k - x - 1];
			}
			for (int x = 0; x <= k; x++) {
				dp[v][x + 1] += dp[u][x];
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
		cin >> n >> k;
		for (int i = 0; i < n - 1; i++) {
			ll a, b;
			cin >> a >> b;
			adj[a].pb(b);
			adj[b].pb(a);
		}
		dfs(1, -1);
		cout << tp << "\n";
	}
	return 0;
}