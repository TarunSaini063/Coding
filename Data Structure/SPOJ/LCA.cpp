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
const int mxn = 1001;
int dp[mxn][11];
vector<int> adj[mxn], level(mxn), par(mxn);
int mx;
void dfs(int id, int p , int h) {
	level[id] = h;
	dp[id][0] = p;
	for (int i : adj[id]) {
		if (i == p) continue;
		dfs(i, id, h + 1);
	}
}
int query(int a, int b) {
	if (a == b) return a;
	if (level[a] > level[b]) swap(a, b);
	int d = level[b] - level[a];
	while (d > 0) {
		int nt = log2(d);
		b = dp[b][nt];
		d -= (1 << nt);
	}
	if (a == b) return a;
	for (int i = mx; i >= 0; i--) {
		if (dp[a][i] != -1 && dp[a][i] != dp[b][i]) {
			a = dp[a][i];
			b = dp[b][i];
		}
	}
	return par[a];
}
int main(void)
{
	FIO
	int t, d = 0;
	scanf("%d", &t);
	while (t--)
	{
		d++;
		int q, a, b, n;
		scanf("%d", &n);
		int nt = log2(n) + 1;
		mx = nt;
		for (int i = 0; i <= n; i++) {
			adj[i].clear();
			for (int j = 0; j < 10; j++) dp[i][j] = -1;
		}
		for (int i = 1; i <= n; i++) {
			scanf("%d", &q);
			while (q--) {
				scanf("%d", &a);
				par[a] = i;
				adj[i].pb(a);
				// adj[a].pb(i);
			}
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
		scanf("%d", &q);
		printf("Case %d:\n", d);
		while (q--) {
			scanf("%d%d", &a, &b);
			printf("%d\n", query(a, b) );
		}
		// cout.flush();
	}
	return 0;
}