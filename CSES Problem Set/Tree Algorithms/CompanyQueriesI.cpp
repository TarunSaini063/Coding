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
int dp[20][mxn], par[mxn];
vector<int> adj[mxn];
void dfs(int id, int p) {
	dp[0][id] = p;
	for (int i : adj[id]) {
		if (i != p) {
			dfs(i, id);
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
		int n, q;
		cin >> n >> q;
		for (int i = 0; i < n - 1; i++) {
			int x;
			cin >> x;
			adj[x].pb(i + 2);
			adj[i + 2].pb(x);
		}
		memset(dp, -1, sizeof(dp));
		dfs(1, -1);
		for (int i = 1; i < 20; i++) {
			for (int j = 1; j <= n; j++) {
				int p = dp[i - 1][j];
				if (p != -1) {
					dp[i][j] = dp[i - 1][p];
				}
			}
		}
		while (q--) {
			int a, k;
			cin >> a >> k;
			while (true) {
				int id = 0;
				while ((1 << id) <= k) id++;
				id--;
				a = dp[id][a];
				k -= (1 << id);
				if (k == 0 || a == -1) break;
			}
			cout << a << "\n";
		}
	}
	return 0;
}